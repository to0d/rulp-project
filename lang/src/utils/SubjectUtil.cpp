// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/SubjectUtil.h"
#include "lfc/base/string/format.h"

using namespace lfc;
using namespace lfc;
namespace lfc {

static IRMember* _processMemberAttribute(IRMember* mbr, StrConstRef attr, boolean fun){
  if(attr == A_PUBLIC){
    mbr->setAccessType(RAccessType::PUBLIC);
  }
  else if(attr == A_PRIVATE){
    mbr->setAccessType(RAccessType::PRIVATE);
  }
  else if(attr == A_DEFAULT){
    mbr->setAccessType(RAccessType::DEFAULT);
  }
  else if(attr == A_FINAL){
    RulpUtil::setPropertyFinal(mbr, true);
  }
  else if(attr == A_STATIC){
    
    RulpUtil::setPropertyStatic(mbr, true);

    /****************************************************/
    // set subject frame for static function
    /****************************************************/
    if (fun) {

      auto old_mbr = mbr;

      mbr = RulpFactory::createMember(
                mbr->getSubject()
              , mbr->getName()
              , RulpFactory::createFunctionLambda (
                    RulpUtil::asFunction(mbr->getValue())
                  , RulpUtil::asSubject(mbr->getSubject())->getSubjectFrame()
                  )
                );

      RULP_FREE(old_mbr);
    }

  }

  AttrUtil::addAttribute(mbr, attr);
  return mbr;
}


IRMember* SubjectUtil::defineMemberFun(IRSubject* sub, StrConstRef mbrName, IRList* mbrExpr, IRInterpreter* interpreter, IRFrame* frame){
  
  int mbrExprSize = mbrExpr->size();
  if (mbrExprSize < 4) {
    throw RException("Invalid member parameters:" + mbrExpr->asString());
  }

  if (sub->isFinal()) {
    throw RException("can't define member<" + mbrName + "> for final subject: " + sub->asString());
  }

  // std::cout << "setMember: " << sub->asString() << ", name=" << mbrName << ", mbr=" << mbrExpr->asString() << "\n";

  IRMember* mbr = null;

  /*****************************************************/
  // Function parameter list
  /*****************************************************/
  auto paraAttrs = AttrUtil::buildAttrList(mbrExpr->get(2), interpreter, frame);
  AUTO_INC_DEC(paraAttrs);

  // Check duplicate parameters
  if (paraAttrs.size() > 1) {
    std::set<std::string> paraNames;
    for (auto pa : paraAttrs) {
      if (paraNames.count(pa->getParaName()) != 0) {
        throw RException("duplicate parameter: " + pa->getParaName());
      }
      paraNames.insert(pa->getParaName());
    }
  }

  /*****************************************************/
  // Function body
  /*****************************************************/
  IRExpr* funBody = null;
  if (mbrExprSize == 4) {
    funBody = AS_EXPR(mbrExpr->get(3));

  } 
  else {
    funBody = RulpUtil::toDoExpr(mbrExpr->listIterator(3));
  }

  /*****************************************************/
  // Check old Member
  /*****************************************************/
  auto oldMbr = sub->getMember(mbrName);
  boolean inherit = false;
  if (oldMbr != null) {

    if (TYPE_INDEX_OF(oldMbr->getValue()) != E_FUNC) {
      throw RException("can't redefine member<" + oldMbr->asString() + "> to fun");
    }

    if (RulpUtil::isPropertyStatic(oldMbr)) {
      throw RException("can't redefine static member: " + oldMbr->asString());
    }

  } 
  else {

    auto parentMbr = SubjectUtil::lookUpMember(sub->getParent(), mbrName);
    if (parentMbr != null && TYPE_INDEX_OF(parentMbr->getValue()) == E_FUNC
        && !RulpUtil::isPropertyStatic(parentMbr)) {
      oldMbr = parentMbr;
      inherit = true;
    }
  }

  auto newFunc = RulpFactory::createFunction(frame, mbrName, std::move(paraAttrs), funBody);
  AUTO_INC_DEC(newFunc);

  if (oldMbr != null) {

    auto oldFunc =  RulpUtil::asFunction(oldMbr->getValue());
    if (!IS_FUNC_LIST(oldFunc)) {

      /*****************************************************/
      // Override
      /*****************************************************/
      if (oldFunc->getSignature() == newFunc->getSignature()) {

        if (RulpUtil::isPropertyFinal(oldMbr)) {
          throw RException("can't redefine final member: " + oldMbr->asString());
        }

        if (!inherit) {
          RulpUtil::tryOverride(oldFunc, newFunc);
        }
      }
      /*****************************************************/
      // Create Function List
      /*****************************************************/
      else {

        auto funList = RulpFactory::createFunctionList(mbrName);
        funList->addFunc(oldFunc);
        funList->addFunc(newFunc);
        newFunc = funList;
      }

    } 
    else {

      auto oldFunList = RulpUtil::asFunctionList(oldFunc);
      auto newFunList = RulpFactory::createFunctionList(oldFunList->getName());

      for (auto f : oldFunList->getAllFuncList()) {
        if (f->getSignature() != newFunc->getSignature()) {
          newFunList->addFunc(f);
        }
      }

      newFunList->addFunc(newFunc);
      newFunc = newFunList;
    }
  }

  mbr = RulpFactory::createMember(sub, mbrName, newFunc);

  /*****************************************************/
  // Process attribute
  /*****************************************************/
  if (AttrUtil::hasAttributeList(mbrExpr)) {
    for (auto attr : AttrUtil::getAttributeKeyList(mbrExpr)) {
      mbr = _processMemberAttribute(mbr, attr, true);
    }
  }

  sub->setMember(mbrName, mbr);
  return mbr;
}

static IRMember* _createMemberVar(IRSubject* sub, StrConstRef mbrName, IRObject* varValue) {

  /*****************************************************/
  // Check the variable whether be defined
  /*****************************************************/
  auto oldMbr = sub->getMember(mbrName);
  if (oldMbr != null) {

    if (TYPE_INDEX_OF(oldMbr->getValue()) != E_VAR) {
      throw RException( LFC_STR_FORMAT_BGN 
                            "can't redefine member<%s> type from %s to %s"
                          , oldMbr->asString().c_str()
                          , oldMbr->getValue()->getType()->getName().c_str()
                          , T_VAR->getName().c_str()
                        LFC_STR_FORMAT_END);
    }

    if (RulpUtil::isPropertyFinal(oldMbr)) {
      throw RException("can't redefine final member variable: " + oldMbr->asString());
    }

    if (!RulpUtil::isPropertyInherit(oldMbr)) {
      throw RException("duplicate member variable: " + oldMbr->asString());
    }
  }

  if (sub->isFinal()) {
    throw RException("can't define member variable<" + mbrName + "> for final subject: " + sub->asString());
  }

  auto var = RulpFactory::createVar(mbrName);
  if (varValue != null) {
    var->setValue(varValue);
  }

  return RulpFactory::createMember(sub, mbrName, var);
}

IRVar* SubjectUtil::defineMemberVar(IRMember* mbrObj, IRObject* val, IRInterpreter* interpreter, IRFrame* frame){
  auto subObj   = interpreter->compute(frame, mbrObj->getSubject());
  auto sub      = RulpUtil::asSubject(subObj);
  auto varName  = mbrObj->getName();

  if (val != null) {
    val = interpreter->compute(frame, val);
  }

  auto mbr = _createMemberVar(sub, varName, val);
  sub->setMember(varName, mbr);

  return RulpUtil::asVar(mbr->getValue());
}

void SubjectUtil::defineMemberVar(IRSubject* sub, IRList* mbrExpr, IRInterpreter* interpreter, IRFrame* frame) {
  if (mbrExpr->size() != 2 && mbrExpr->size() != 3) {
    throw RException("Invalid member parameters: " + mbrExpr->asString());
  }

  /*****************************************************/
  // name
  /*****************************************************/
  auto mbrName = AS_ATOM(mbrExpr->get(1))->getName();

  /*****************************************************/
  // value
  /*****************************************************/
  IRObject* varValue = null;
  int mbrExprSize = mbrExpr->size();
  if (mbrExprSize >= 3) {
    varValue = mbrExpr->get(2);

    if (TYPE_INDEX_OF(varValue) == E_EXPR) {
      varValue = RulpFactory::createExpression({
                  RulpFactory::createFunctionLambda(
                      RulpFactory::createFunction(
                          frame
                        , F_LAMBDA
                        , {}
                        , RulpFactory::createExpression({O_RETURN, varValue})
                        )
                    , frame)
                  });
      AttrUtil::addAttribute(varValue, A_OPT_LCO);
    } 
    else {
      varValue = interpreter->compute(frame, varValue);
    }

  }

  /*****************************************************/
  // member
  /*****************************************************/
  auto mbr = _createMemberVar(sub, mbrName, varValue);

  /*****************************************************/
  // Process attribute
  /*****************************************************/
  if (AttrUtil::hasAttributeList(mbrExpr)) {
    for (auto attr : AttrUtil::getAttributeKeyList(mbrExpr)) {
      mbr = _processMemberAttribute(mbr, attr, false);
    }
  }

  sub->setMember(mbrName, mbr);
}

IRClass* SubjectUtil::findMatchClass(IRInstance* instance, IRAtom* classAtom){
  IRClass* rClass = instance->getRClass();
  while (rClass != null && !RulpUtil::equal(rClass->getClassTypeAtom(), classAtom)) {
    rClass = rClass->getSuperClass();
  }

  return rClass;
}

IRMember* SubjectUtil::getClassMember(IRInstance* instance, IRClass* rClass, StrConstRef name) {
  if (name.empty()) {
    return null;
  }

  // if(name == F_UNINIT){
  //    std::cout << "getClassMember:" << rClass->getClassName() << "\n";
  // }

  auto classMbr = rClass->getMember(name);
  if (classMbr == null) {
    classMbr = SubjectUtil::lookUpMember(rClass->getSuperClass(), name);
  }

  if (classMbr == null) {
    return null;
  }

  IRObject* classMbrVal = classMbr->getValue();
  IRObject* insMbrVal = null;

  // for static member, use it directly
  if (RulpUtil::isPropertyStatic(classMbr)) {

    switch (TYPE_INDEX_OF(classMbrVal)) {
    case E_FUNC:

      if (IS_FUNC_LIST(classMbrVal)) {

        auto oldFunList = AS_FUNC_LIST(classMbrVal);
        auto newFunList = RulpFactory::createFunctionList(oldFunList->getName());

        for (auto f : oldFunList->getAllFuncList()) {
          newFunList->addFunc(f);
        }
        insMbrVal = newFunList;

      } 
      else {
        insMbrVal = classMbrVal;
      }

      break;

    case E_VAR:
      insMbrVal = classMbrVal;
      break;

    default:
      throw RException("Invalid member obj: " + classMbrVal->asString());
    }

  } 
  else {

    switch (TYPE_INDEX_OF(classMbrVal)) {
    case E_FUNC:

      if (IS_FUNC_LIST(classMbrVal)) {

        auto oldFunList = RulpUtil::asFunctionList(classMbrVal);
        auto newFunList = RulpFactory::createFunctionList(oldFunList->getName());

        for (auto f : oldFunList->getAllFuncList()) {
          newFunList->addFunc(RulpFactory::createFunctionLambda(f, instance->getSubjectFrame()));
        }

        insMbrVal = newFunList;

      } 
      else {
        insMbrVal = RulpFactory::createFunctionLambda(AS_FUNC(classMbrVal), instance->getSubjectFrame());
      }

      break;

    case E_VAR: {

      auto var    = RulpFactory::createVar(name);
      auto value = AS_VAR(classMbrVal)->getValue();

      if (TYPE_INDEX_OF(value) == E_EXPR && AttrUtil::containAttribute(value, A_OPT_LCO)) {
        AttrUtil::addAttribute(var, A_OPT_LCO);
      } 
      else {
        value = RulpUtil::clone(value);
      }

      var->setValue(value);
      insMbrVal = var;
      break;
    }

    default:
      throw RException("Invalid member obj: " + classMbrVal->asString());
    }
  }

  auto objMbr = RulpFactory::createMember(instance, name, insMbrVal);
  objMbr->setAccessType(classMbr->getAccessType());
  objMbr->setProperty(classMbr->getProperty());
  RulpUtil::setPropertyInherit(objMbr, true);

  return objMbr;
}

IRMember* SubjectUtil::lookUpMember(IRSubject* subject, StrConstRef name){
  IRMember* mbr = null;
  while (mbr == null && subject != null) {
    mbr = subject->getMember(name);
    subject = subject->getParent();
  }

  return mbr;
}

} // namespace lfc