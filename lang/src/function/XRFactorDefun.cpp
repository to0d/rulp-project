// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/object/IRParaAttr.h"
#include "lfc/base/to_string.h"
#include "lfc/base/string/format.h"
#include "lfc/base/container.h"
#include <iostream>
using namespace lfc;

namespace lfc {
struct OPT {
  std::vector<std::string> attrList;
  IRFrame* frame;
  IRExpr* funBody;
  std::string funName;
  IRInterpreter* interpreter;
  std::vector<IRParaAttr*> paraAttrs;
};

static boolean _optLCO(OPT& opt){
  return LCOUtil::rebuild(opt.paraAttrs);
}

static IRObject* defFun(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {

  /*****************************************************/
  // Function name
  /*****************************************************/
  auto funName = RulpUtil::asAtom(args->get(1))->getName();

  /*****************************************************/
  // Function parameter list
  /*****************************************************/
  auto paraAttrs = AttrUtil::buildAttrList(args->get(2), interpreter, frame);
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
  if (args->size() == 4) {
    funBody = AS_EXPR(args->get(3));

  } 
  else if (args->size() > 4) {
    funBody = RulpUtil::toDoExpr(args->listIterator(3));
  } 
  else {
    throw RException("Invalid args size: " + TO_STR(args->size()));
  }

  std::vector<std::string> attrList;

  /*****************************************************/
  // Process function attribute
  /*****************************************************/
  if (AttrUtil::hasAttributeList(args)) {

    int optIndex = 0;
    OPT opt;

    opt.interpreter = interpreter;
    opt.frame = frame;
    opt.funBody = funBody;
    opt.funName = funName;
    opt.paraAttrs = paraAttrs;

    int optCount = 0;

    for (auto attr : AttrUtil::getAttributeKeyList(args)) {

      boolean update = false;
      if(attr == A_OPT_LCO){
        update = _optLCO(opt);
      }
      else {
        update = true;
      }

      if (update) {
        if (!lfc::find(opt.attrList, attr)) {
          opt.attrList.push_back(attr);
        }
        optCount++;
      }
    }

    if (optCount > 0) {
      funBody = opt.funBody;
    }

    attrList = opt.attrList;
  }

  // std::cout << "funBody=" << funBody->asString() << "\n";
  auto newFun = RulpFactory::createFunction(frame, funName, std::move(paraAttrs), funBody);
  // AUTO_INC_DEC(newFun);
  /*****************************************************/
  // Update attribute list
  /*****************************************************/
  for (auto attr : attrList) {
    AttrUtil::addAttribute(newFun, attr);
  }

  /*****************************************************/
  // Function
  /*****************************************************/
  auto entry = frame->getEntry(funName);
  if (entry == null) {
    frame->setEntry(funName, newFun);
    return newFun;
  }

  auto entryObj = entry->getObject();
  if (TYPE_INDEX_OF(entryObj) != E_FUNC) {
    RULP_AUTO_FREE(newFun);
    throw RException( LFC_STR_FORMAT_BGN 
                          "Can't overide object: obj=%s, type=%s"
                        , entryObj->asString().c_str()
                        , entryObj->getType()->getName().c_str()
                      LFC_STR_FORMAT_END);
  }

  auto oldFunc = RulpUtil::asFunction(entryObj);

  /*****************************************************/
  // Copy function
  /*****************************************************/
  if (entry->getFrame() != frame) {

    // Copy function list
    if (IS_FUNC_LIST(oldFunc)) {

      auto oldFunList = RulpUtil::asFunctionList(oldFunc);
      auto newFunList = RulpFactory::createFunctionList(oldFunList->getName());

      for (auto f : oldFunList->getAllFuncList()) {
        newFunList->addFunc(f);
      }

      frame->setEntry(funName, newFunList);
      oldFunc = newFunList;

    }
    // Copy function
    else {
      frame->setEntry(funName, oldFunc);
    }
  }

  if (!IS_FUNC_LIST(oldFunc)) {

    /*****************************************************/
    // Override
    /*****************************************************/
    if (oldFunc->getSignature() == newFun->getSignature()) {
      RulpUtil::tryOverride(oldFunc, newFun);
      frame->setEntry(funName, newFun);

      return newFun;
    }
    /*****************************************************/
    // Create Function List
    /*****************************************************/
    else {

      auto funList = RulpFactory::createFunctionList(funName);
      funList->addFunc(oldFunc);
      funList->addFunc(newFun);

      frame->setEntry(funName, funList);
      return funList;
    }

  }

  /*****************************************************/
  // Function List (overload)
  /*****************************************************/
  auto funList = RulpUtil::asFunctionList(oldFunc);
  funList->addFunc(newFun);

  return funList;
}

static IRObject* defMemberFun(IRList* args, IRInterpreter* interpreter, IRFrame* frame){
  /*****************************************************/
  // Function name
  /*****************************************************/
  auto funMbr = RulpUtil::asMember(args->get(1));
  auto sub    = RulpUtil::asSubject(interpreter->compute(frame, funMbr->getSubject()));

  return SubjectUtil::defineMemberFun(sub, funMbr->getName(), args, interpreter, frame);

}

XRFACTOR_IMPL_BEGIN(XRFactorDefun)

  auto nameObj = args->get(1);

  if (TYPE_INDEX_OF(nameObj) == E_ATOM) {
    return defFun(args, interpreter, frame);
  }

  if (TYPE_INDEX_OF(nameObj) == E_MEMBER) {
    return defMemberFun(args, interpreter, frame);
  }

  throw RException("Invalid parameters: " + args->asString());

XRFACTOR_IMPL_ARG(4, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDefun, F_DEFUN);

} // namespace lfc