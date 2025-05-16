// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <sstream>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rt_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rt_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
TRACE_SUB_MODULE_IMPL(rt_util)
#include "rulp/lang.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/LCOUtil.h"
#include "rulp/utils/RulpMathUtil.h"
#include "rulp/utils/ReturnTypeUtil.h"
#include "rulp/utils/SubjectUtil.h"
#include "rulp/utils/RListHandler.h"
#include "rulp/utils/RFrameHandler.h"
#include "rulp/utils/RObjectHandler.h"
#include "lfc/base/to_string.h"
#include "lfc/base/trace.h"
#include "lfc/base/string/format.h"
#include "lfc/base/auto/auto_do.h"
#include "lfc/base/auto/auto_free.h"
#include "lfc/base/container.h"
#include "lfc/base/static/static_holder.h"
using namespace lfc;
using namespace lfc;
namespace lfc {

static int callStatsId = 0;

static int exprComputeFactorCount = 0;

static int exprComputeFuncCount = 0;

static int exprComputeMacroCount = 0;

static int exprComputeMemberCount = 0;

static int exprComputeTemplateCount = 0;

static int frameMaxLevel = 0;

static void _checkFrame(IRFrame* frame) {

  if(frame == NULL)
  {
    assert(frame);
  }

  assert(frame);

  /***************************************************/
  // Check frame ref
  /***************************************************/
  if (frame->getRef() < 0) {
    LFC_TRACE4("ref=", frame->getRef(), ", frame=", TO_STR(frame));
    assert(false && "invalid frame ref");
  }

  /***************************************************/
  // Check Async Completed
  /***************************************************/
  {
    auto atext = frame->getThreadContext();
    if (atext != null && atext->isCompleted()) {
      throw RException(frame, "thread is already completed");
    }
  }

  /***************************************************/
  // Update max level
  /***************************************************/
  {
    int lvl = frame->getLevel();
    if (lvl > frameMaxLevel) {
      frameMaxLevel = lvl;
    }
  }

}

static void _checkObject(IRObject* obj) {

  assert(obj);

  /***************************************************/
  // Check object ref
  /***************************************************/
  if (obj->getRef() < 0) {
    LFC_TRACE4("ref=", obj->getRef(), ", obj=", TO_STR(obj));
    assert(false && "invalid obj ref");
  }

}

static IRObject* _lookupNonSubjectObject(StrConstRef name, IRFrame* frame) {

  auto nonSubFrame = frame->getParentFrame();
  while (nonSubFrame != null && RuntimeUtil::isSubjectFrame(nonSubFrame)) {
    nonSubFrame = nonSubFrame->getParentFrame();
  }

  if (nonSubFrame == null) {
    return null;
  }

  auto entry = RuntimeUtil::lookupFrameEntry(nonSubFrame, name);
  if (entry == null) {
    return null;
  }

  auto obj = entry->getObject();
  if (obj == null) {
    return null;
  }

  return obj;
}


IRVar* RuntimeUtil::addVar(IRFrame* frame, StrConstRef name) {
  IRVar* var = RulpFactory::createVar(name);
  frame->setEntry(name, var);
  return var;
}

void RuntimeUtil::addFactor(IRFrame* frame, StrConstRef factorName, factor_func factorBody, boolean threadSafe) {
  frame->setEntry(factorName, RulpFactory::createFactor(factorName, factorBody, threadSafe));
}

IRTemplate* RuntimeUtil::addTemplate(IRFrame* frame, StrConstRef templateName, const TemplateParaEntry& paraEntry) {
  IRTemplate* templateObj = null;  

  // Create template
  auto entry = frame->getEntry(templateName);
  if (entry == null) {
    
    templateObj = RulpFactory::createTemplate(templateName, frame);
    frame->setEntry(templateName, templateObj);
 
  } 
  else if (TYPE_INDEX_OF(entry->getValue()) != E_TEMPLATE) {
    auto obj = entry->getValue();
    if (entry->getFrame() != frame) {

      templateObj = RulpFactory::createTemplate(templateName, frame);
      frame->setEntry(templateName, templateObj);

    } 
    else {

      throw RException( LFC_STR_FORMAT_BGN
                            "Can't redifine <%s:%s> as a template"
                          , obj->asString().c_str()
                          , obj->getType()->getName().c_str()
                        LFC_STR_FORMAT_END);
    }

  } 
  else {

    templateObj = AS_TEMPLATE(entry->getValue());

    // Copy template
    if (templateObj->getDefineFrame() != frame) {

      auto oldTpEntrys = templateObj->getTemplateParaEntryList();
      templateObj = RulpFactory::createTemplate(templateName, frame);
      for (auto& tpEntry : oldTpEntrys) {
        templateObj->addEntry(tpEntry);
      }

      frame->setEntry(templateName, templateObj);
    }
  }

  templateObj->addEntry(paraEntry);

  return templateObj;
}

IRTemplate* RuntimeUtil::addTemplate(IRFrame* frame, StrConstRef templateName, IRCallable* templateBody, int totalParaCount, const std::vector<std::string>& fixedParaNames) {

  // Add entry
  TemplateParaEntry paraEntry;
  paraEntry.body = templateBody;
  paraEntry.isVary = totalParaCount > (fixedParaNames.size() + 1);

  for (auto& fixedParaName :fixedParaNames) {

    TemplatePara tp;
    tp.isVar = false;

    auto fixParaEntry = RuntimeUtil::lookupFrameEntry(frame, fixedParaName);
    if (fixParaEntry != null) {
      auto fixParaObj = fixParaEntry->getObject();
      tp.paraType   = RulpUtil::getObjectType(fixParaObj);
      tp.paraValue  = fixParaObj;
    } 
    else {
      tp.paraType   = T_Atom;
      tp.paraValue  = RulpFactory::createAtom(fixedParaName);
    }

    paraEntry.fixedParas.push_back(tp);
  }

  return addTemplate(frame, templateName, paraEntry);
}

static IRObject* computeExpr(IRObject* e0, IRList* expr, IRInterpreter* interpreter, IRFrame* frame){

  // IRDebugger debugger = interpreter.getActiveDebugger();
  // if (debugger != null) {
  //   debugger.pushStack(expr, frame);

  //   if (debugger.canBreak(e0)) {
  //     debugger.run(interpreter, frame);
  //   }
  // }

  // try {

    switch (TYPE_INDEX_OF(e0)) {
      case E_FACTOR: {
        ++exprComputeFactorCount;

        IRFactor* factor = RulpUtil::asFactor(e0);
        IRObject* rst = RuntimeUtil::computeCallable(factor, expr, interpreter, frame);

        /**************************************************/
        // Compute Afters annotation
        /**************************************************/
        if (factor->hasAfterAnnotation() && AttrUtil::hasAttributeList(rst)) {
          for (auto attr : AttrUtil::getAttributeKeyList(rst)) {
            auto anno = factor->getAfterAnnotation(attr);
            if (anno != null) {
              rst = anno->build(rst, interpreter, frame);
            }
          }
        }

        return rst;
      }

    case E_MACRO:
      exprComputeMacroCount++;      
      return RuntimeUtil::computeCallable(RulpUtil::asCallable(e0), expr, interpreter, frame);

    case E_FUNC: {

      IRFunction* func = RulpUtil::asFunction(e0);
      AUTO_INC_DEC(func);

      try {

        exprComputeFuncCount++;
        auto rst = RuntimeUtil::computeFun(func, expr, interpreter, frame);
        if (rst == null) {
          return O_Nil;
        }

        /**************************************************/
        // Compute Afters annotation
        /**************************************************/
        if (func->hasAfterAnnotation() && AttrUtil::hasAttributeList(rst)) {
          for (auto attr : AttrUtil::getAttributeKeyList(rst)) {
            auto anno = func->getAfterAnnotation(attr);
            if (anno != null) {
              rst = anno->build(rst, interpreter, frame);
            }
          }
        }

        return rst;

      } 
      catch (RExceptionUnmatchPara& e) {

        if (!RuntimeUtil::isSubjectFrame(func->getDefineFrame())) {
          e.setHandle(true);
          throw e;
        }

        auto o2 = _lookupNonSubjectObject(func->getName(), frame);
        if (o2 == null) {
          e.setHandle(true);
          throw e;
        }

        return computeExpr(o2, expr, interpreter, frame);
      }
    }

    case E_TEMPLATE: {
      
      exprComputeTemplateCount++;
      return RuntimeUtil::computeCallable(AS_CALL(e0), expr, interpreter, frame);
    
    }

    case E_MEMBER: {

      exprComputeMemberCount++;
      
      auto e1m = RulpUtil::asMember(e0)->getValue();
      if (TYPE_INDEX_OF(e1m) != E_FUNC) {
        throw RException("factor not found: " + expr->asString());
      }

      return RuntimeUtil::computeFun(RulpUtil::asFunction(e1m), expr, interpreter, frame);
    }

    default:
      // std::cout << TO_STR(expr) << "\n";
      // assert(false && "factor not found");
      throw RException("factor not found: " + expr->asString());
    }

  // } finally {

  //   if (debugger != null) {
  //     debugger.popStack(frame);
  //   }
  // }

  return NULL;
}

boolean RuntimeUtil::isSubjectFrame(IRFrame* frame){
  return frame != null && frame->getSubject() != frame;
}

IRObject* RuntimeUtil::computeFun(IRFunction* fun, IRList* expr, IRInterpreter* interpreter, IRFrame* frame){

  _checkFrame(frame);
  _checkObject(fun);

  //  std::cout << "computeFun: " << fun->asString() << "\n";
  AUTO_INC_DEC(fun);

  // For Function List, the argCount is -1
  int argCount = fun->getArgCount();
  if (argCount != -1 && expr->size() != (argCount + 1)) {
    throw RExceptionUnmatchPara
            ( fun
            , frame
            , LFC_STR_FORMAT_BGN 
                  "Unexpect argument number in fun<%s>: expect=%d, actual=%d"
                , fun->getName().c_str()
                , argCount
                , expr->size() - 1 
              LFC_STR_FORMAT_END);
  }

  auto newExpr = rebuildFuncExpr(fun, expr, interpreter, frame);
  AUTO_INC_DEC(newExpr);

  return RuntimeUtil::computeCallable(fun, newExpr, interpreter, frame);
}

IRObject* RuntimeUtil::computeFun2(IRFunction* fun, IRInterpreter* interpreter, IRFrame* frame, std::vector<IRObject*>&& objs) {
  std::vector<IRObject*> args;
  args.push_back(fun);

  for (auto obj : objs) {
    args.push_back(obj);
  }

  auto list = RulpFactory::createList(std::move(args));
  AUTO_INC_DEC(list);

  return RuntimeUtil::computeFun(fun, list, interpreter, frame);
}

static boolean _needRebuildPara(IRFunction* fun, int index, IRParaAttr* attr, IRObject* value, IRFrame* frame) {

		// pass by default
		if (attr == null) {
			return true;
		}

		// pass by expression
		if (attr->getParaType() == T_Expr) {
			return false;
		}

		// Lazy compute
		if (TYPE_INDEX_OF(value) == E_EXPR && AttrUtil::containAttribute(attr, A_OPT_LCO)) {

			auto typeAtom = attr->getParaType();

			// Match any type
			if (typeAtom == O_Nil) {
				return false;
			}

			auto exprTypeAtom = ReturnTypeUtil::returnTypeOf(value, frame);
			if (exprTypeAtom != O_Nil) {
				if (RulpUtil::equal(exprTypeAtom, typeAtom)) {
					return false;
				} 
        else {
					throw RExceptionUnmatchPara
                      ( fun
                      , frame
                      , LFC_STR_FORMAT_BGN 
                            "the %d argument<%s> not match type <%s>"
                          , index
                          , value->asString().c_str()
                          , typeAtom->asString().c_str()
                        LFC_STR_FORMAT_END);
				}
			}
		}

		// other, pass by value
		return true;
	}


IRList* RuntimeUtil::rebuildFuncExpr(IRFunction* fun, IRList* expr, IRInterpreter* interpreter, IRFrame* frame){
  std::vector<IRObject*>* argList = null;
  LFC_AUTO_FREE(argList);

  int size = expr->size();

  bool hasPara = !fun->getParaAttrs().empty();

  for (int i = 1; i < size; ++i) {// Skip factor head element

    auto value = expr->get(i);
    IRParaAttr* para = hasPara ? fun->getParaAttrs()[i-1] : null;
    boolean rebuild = false;

    // Check parameter attribute whether there is any pass-value parameter
    if (_needRebuildPara(fun, i - 1, para, value, frame)) {
      value = compute(value, interpreter, frame);
      rebuild = true;
    }

    // rebuild argument value list
    if (rebuild && argList == null) {
      argList = new std::vector<IRObject*>();
      for (int j = 0; j < i; ++j) {
        argList->push_back(expr->get(j));
      }
    }

    if (argList != null) {
      argList->push_back(value);
    }
  }

  if (argList == null) {
    return expr;
  }

  return RulpFactory::createExpression(std::move(*argList));
}

IRObject* RuntimeUtil::computeCallable(IRCallable* callObject, IRList* args, IRInterpreter* interpreter, IRFrame* frame){
  _checkFrame(frame);
  _checkObject(callObject);

  ROH new_arg_holder;
  bool needClone = false;

  // std::cout << "computeCallable: callObject=" << callObject->asString() << ", args=" << args->asString() << ", frame=" << frame->asString() << "\n";

  /**************************************************/
  // Check early expression
  /**************************************************/
  {
    int size = args->size();
    int firstEarlyIndex = -1;

    for (int i = 1; i < size; ++i) {
      IRObject* arg = args->get(i);      
      if (arg != null && arg->getType() == T_EXPR && AS_EXPR(arg)->isEarly()) {
        firstEarlyIndex = i;
        break;
      }
    }

    if (firstEarlyIndex != -1) {
  
      std::vector<IRObject*> newArgList;
      for (int i = 0; i < firstEarlyIndex; ++i) {
        newArgList.push_back(args->get(i));
      }

      for (int i = firstEarlyIndex; i < size; ++i) {
        IRObject* arg = args->get(i);
        if (arg != null && arg->getType() == T_EXPR && AS_EXPR(arg)->isEarly()) {
          arg = RuntimeUtil::compute(arg, interpreter, frame);
        }

        newArgList.push_back(arg);
      }

      auto new_arg = args->getType() == T_EXPR ? RulpFactory::createExpression(std::move(newArgList))
          : RulpFactory::createList(std::move(newArgList));

      // std::cout << "new_arg=" << new_arg->asString() << ", ptr=" <<new_arg << "\n";
      new_arg_holder.set(new_arg);
      needClone = true;

      args = new_arg;
    }
  }

  callObject->incCallCount(getCallStatsId(), interpreter->getCallId());

  /**************************************************/
  // Compute before annotation
  /**************************************************/
  if (callObject->hasBeforeAnnotation() && AttrUtil::hasAttributeList(args)) {

    auto lastAttrList = AttrUtil::getAttributeKeyList(args);
    std::vector<std::string> attrList = lastAttrList;
    for (int i = 0; i < attrList.size(); ++i) {

      auto attr = attrList[i];
      auto anno = callObject->getBeforeAnnotation(attr);
      if (anno == null) {
        continue;
      }

      args = anno->build(args, interpreter, frame);
      auto newAttrList = AttrUtil::getAttributeKeyList(args);
      if (newAttrList != lastAttrList) {
        for (auto newAttr : newAttrList) {
          if(!lfc::find(attrList, newAttr)){
            attrList.push_back(newAttr);
          }
        }
      }
    }
  }

  IRObject* rst = NULL;

  /**************************************************/
  // Compute
  /**************************************************/
  // if (AttrUtil.isThreadSafe(callObject, frame)) {

  // check argument count
  if(TYPE_INDEX_OF(callObject) == E_FACTOR) {
    auto factor = AS_FACTOR(callObject);
    
    if(factor->getMinArgCount() != -1 && args->size() < factor->getMinArgCount()) {
      throw RException("Too few parameters: " + args->asString() 
                     + ", min arg count: " + TO_STR(factor->getMinArgCount()));
    }

    if(factor->getMaxArgCount() != -1 && args->size() > factor->getMaxArgCount()) {
      throw RException("Too many parameters: " + args->asString() 
                     + ", max arg count: " + TO_STR(factor->getMaxArgCount()));
    }
  }

  rst = callObject->compute(args, interpreter, frame);

  if(needClone && rst->getRef() > 0){

    switch (TYPE_INDEX_OF(rst))
    {
    case E_FRAME:
      break;
    
    default:
      rst = RulpUtil::clone(rst);
      break;
    }


    // std::cout << "rst " << rst->asString() << ", ref=" << rst->getRef() << ", addr=" << rst << "\n";
 
    // std::cout << "rst " << rst->asString() << ", ref=" << rst->getRef() << ", addr=" << rst << "\n";
  }

  // } else {
  //   synchronized (callObject) {
  //     rst = callObject.compute(args, interpreter, frame);
  //   }
  // }

  return rst;
}

IRObject* RuntimeUtil::compute(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame){

  if (!obj) {
    return O_Nil;
  }

  // std::cout << "compute: obj=" << obj->asString() << ", type=" << obj->getType()->getIndex() << ", ref=" << obj->getRef() << ", ptr=" << obj << "\n";

  _checkFrame(frame);
  _checkObject(obj);

  try {

    switch (TYPE_INDEX_OF(obj)) {
      case E_INT:
      case E_LONG:
      case E_FLOAT:
      case E_DOUBLE:
      case E_BOOL:
      case E_STRING:
      case E_INSTANCE:
      case E_NATIVE:
      case E_FACTOR:
      case E_TEMPLATE:
      case E_FUNC:
      case E_FRAME:
      case E_ARRAY:
      case E_ITERATOR:
        return obj;

      case E_VAR: {

        auto var = AS_VAR(obj);
        if (var->getValue() != null) {
          return var->getValue();
        }

        auto entry = frame->getEntry(var->getName());
        if (entry != null) {
          return AS_VAR(entry->getObject());
        }

        throw RException("var entry not found: " + var->asString());
      }

      case E_CONSTANT:
        return AS_CONST(obj)->getValue();\

      case E_ATOM: {

        auto entry = lookupFrameEntry(frame, AS_ATOM(obj)->getName());
        if (entry == null) {
          return obj;
        }
     
        auto rst = entry->getObject();

        switch (TYPE_INDEX_OF(rst)) {
        case E_VAR: {
            
            auto value =  AS_VAR(rst)->getValue();
            if (value != null && TYPE_INDEX_OF(value) == E_EXPR && AttrUtil::containAttribute(rst, A_OPT_LCO)) {
              LCOUtil::incHitCount();
              RFH lcoFrame = RulpFactory::createFrame(frame, A_OPT_LCO);
              value = interpreter->compute(lcoFrame, value);
              AS_VAR(rst)->setValue(value);
            }

            rst = value;
          }
          break;

        case E_CONSTANT:
          rst = AS_CONST(rst)->getValue();
          break;

        default:
          break;
        }

        return rst;
      }

      case E_NIL:
        return O_Nil;

      case E_EXPR: {
        auto expr = AS_EXPR(obj);
        if (expr->size() == 0) {
          return obj;
        }

        IRObject* e0 = compute(expr->get(0), interpreter, frame);
        return computeExpr(e0, expr, interpreter, frame);
      }

      case E_LIST:

        if (!RuntimeUtil::isComputable(frame, obj)) {
          return obj;
        }

        {
          auto oldList = AS_LIST(obj);

          std::vector<IRObject*> rstList;
          auto it = oldList->iterator();
          while (it->hasNext()) {
            rstList.push_back(compute(it->next(), interpreter, frame));
          }

          return RulpUtil::toList(oldList->getNamedName(), std::move(rstList));
        }      


      case E_MEMBER: {

        auto mbr = RuntimeUtil::getActualMember(AS_MEMBER(obj), interpreter, frame);
        if (!RuntimeUtil::canAccess(mbr, interpreter, frame)) {
          throw RException("Can't access member<" + mbr->asString() + "> in frame<" + frame->asString() + ">");
        }

        return mbr->getValue();
      }

      default:
        LFC_TRACE4("type=", TO_STR(obj->getType()), ", obj=", TO_STR(obj));
        assert(false && "invalid type");
    }

  } 
  catch (RExceptionReturn& e) {
    throw e;
  }
  catch (RExceptionBreak& e) {
    throw e;
  }
  catch (RExceptionContinue& e) {
    throw e;
  }
  catch (RException& e) {

    std::string atExprStr = obj->asString();
    if (atExprStr.length() > 80) {
      atExprStr = atExprStr.substr(0, 77) + "...";
    }

    e.addAdditionalMessage( LFC_STR_FORMAT_BGN 
                                "at %s ; %s-%d"
                              , atExprStr.c_str()
                              , frame->getFrameName().c_str()
                              , frame->getFrameId() 
                            LFC_STR_FORMAT_END);
    throw e;
  }

  return NULL;
}

boolean RuntimeUtil::isInstanceOf(IRSubject* child, IRSubject* parent){
  auto childParent = child->getParent();
  while (childParent != null) {
    if (childParent == parent) {
      return true;
    }
    childParent = childParent->getParent();
  }

  return false;
}

boolean RuntimeUtil::canAccess(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame){
  if (obj == null) {
    return true;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_MEMBER: {
    
      auto mbr = RulpUtil::asMember(obj);

      // Check access authority
      switch (mbr->getAccessType()) {
        case RAccessType::PRIVATE: {

          auto* mbrSub   = mbr->getSubject();
          auto frameSub = frame->getSubject();
          if (mbrSub == frameSub) {
            return true;
          }

          if(mbrSub->isSubject()){
            return RuntimeUtil::isInstanceOf(frameSub, AS_SUBJECT(mbrSub));
          }

          return false;
        }

      case RAccessType::DEFAULT:
      case RAccessType::PUBLIC:
        return true;

      default:
        throw RException("invalid accessType: " + TO_STR(mbr->getAccessType()));
      }
    }

  default:
    return true;
  }
}


RListHandler RuntimeUtil::compute(IRInterpreter* interpreter, StrConstRef input){
  RListHandler resultList;

  interpreter->compute(input, [&](auto rst) {
    resultList.addResult(rst);
  });

  return resultList;
}

static bool isForceLocalEntryName(StrConstRef name) {
  if(name == A_LOCAL){
    return true;
  }

  if(name == A_PARENT){
    return true;
  }

  return false;
}

IRMember* RuntimeUtil::getActualMember(IRMember* mbr, IRInterpreter* interpreter, IRFrame* frame){
  if (mbr->getValue() != null) {
    return mbr;
  }

  auto subObj = RuntimeUtil::compute(mbr->getSubject(), interpreter, frame);
  if (subObj == null) {
    throw RException("subject<" + mbr->getSubject()->asString() + "> not found");
  }

  auto sub = RulpUtil::asSubject(subObj);

  // Get root object
  auto actMbr = sub->getMember(mbr->getName());
  if (actMbr == null) {
    throw RException("member<" + mbr->asString() + "> not found in " + sub->asString());
  }

  return actMbr;
}

IRFrameEntry* RuntimeUtil::lookupFrameEntry(IRFrame* frame, StrConstRef name){

  if (isForceLocalEntryName(name)) {
    return frame->getEntry(name);
  }

  auto searchFrameList = frame->getSearchFrameList();
  if (searchFrameList == null) {
    return frame->getEntry(name);
  }

  // Searching the using name space if it was specified
  for (auto searchFrame : *searchFrameList) {
    auto entry = searchFrame->getEntry(name);
    if (entry != null) {
      return entry;
    }
  }

  return NULL;
}

// void RuntimeUtil::init(IRFrame* frame) {
//   RulpUtil::setLocalVar(frame, A_TRACE, O_False);
// }

boolean RuntimeUtil::isComputable(IRFrame* curFrame, IRObject* obj){
  
  if (obj == null) {
    return false;
  }

  switch (obj->getType()->getIndex()) {
    case E_INT:
    case E_LONG:
    case E_FLOAT:
    case E_BOOL:
    case E_STRING:
    case E_NIL:
    case E_FACTOR:
    case E_TEMPLATE:
    case E_FUNC:
    case E_ARRAY:
      return false;

    case E_ATOM:
      return curFrame->getEntry(RulpUtil::asAtom(obj)->getName()) != null;

    case E_VAR:
    case E_EXPR:
    case E_MEMBER:
      return true;

    case E_LIST:

      {
        auto iter = RulpUtil::asList(obj)->iterator();;
        while (iter->hasNext()) {
          if (isComputable(curFrame, iter->next())) {
            return true;
          }
        }
      }

      return false;

    default:
      return true;
  }
}

void RuntimeUtil::addFrameObject(IRFrame* frame, IRObject* obj) {
  switch (TYPE_INDEX_OF(obj)) {
  case E_NIL:
  case E_ATOM:
    frame->setEntry(AS_ATOM(obj)->getName(), obj);
    break;

  case E_BOOL:
    frame->setEntry(AS_BOOL(obj)->asString(), obj);
    break;

  case E_FACTOR:
    frame->setEntry(AS_FACTOR(obj)->getName(), obj);
    break;

  case E_TEMPLATE:
    frame->setEntry(AS_TEMPLATE(obj)->getName(), obj);
    break;

  case E_INSTANCE:
    frame->setEntry(AS_INSTANCE(obj)->getInstanceName(), obj);
    break;

  case E_VAR:
    frame->setEntry(AS_VAR(obj)->getName(), obj);
    break;

  case E_CLASS: 
    frame->setEntry(AS_CLASS(obj)->getClassName(), obj);
    addFrameObject(frame, AS_CLASS(obj)->getClassTypeAtom());
    break;
  default:
    throw RException("Invalid object: " + obj->asString());
  }
}

boolean RuntimeUtil::matchParaType(IRObject* paraValue, IRAtom* paraTypeAtom){

  RType valueType = paraValue->getType();
  if (valueType->getIndex() == E_INSTANCE) {
    return SubjectUtil::findMatchClass(RulpUtil::asInstance(paraValue), paraTypeAtom) != null;
  }

  RType expectType = RRType::toType(paraTypeAtom->asString());
  if (valueType == expectType) {
    return true;
  }

  if (expectType == null) {
    return false;
  }

  return RulpMathUtil::getTypeConvert(valueType->getIndex(), expectType->getIndex()) == expectType->getIndex();
}



IRObject* RuntimeUtil::rebuild(IRObject* obj, const std::map<std::string, IRObject*>& replaceMap){
  if (obj == null) {
    return null;
  }

  switch (TYPE_INDEX_OF(obj)) {
  case E_ATOM: {
    auto atom = RulpUtil::asAtom(obj);
    auto var = find(replaceMap, atom->getName());
    return var == null ? obj : var;
  }

  case E_EXPR:
  case E_LIST: {

    std::vector<IRObject*> newList;
    auto it = RulpUtil::asList(obj)->iterator();
    while (it->hasNext()) {

      auto newElement = rebuild(it->next(), replaceMap);
      if (TYPE_INDEX_OF(newElement) == E_ITERATOR) {

        auto newIterator = AS_ITERATOR(newElement);
        while (newIterator->hasNext()) {
          newList.push_back(newIterator->next());
        }

      } else {
        newList.push_back(newElement);
      }
    }

    if (TYPE_INDEX_OF(obj) == E_LIST) {

      auto name = RulpUtil::asList(obj)->getNamedName();
      if (!name.empty()) {

        auto replaceObj = find(replaceMap, name);
        if (replaceObj != null) {
          switch (TYPE_INDEX_OF(replaceObj)) {
          case E_ATOM:
            name = RulpUtil::asAtom(replaceObj)->getName();
            break;

          default:
            throw RException("Can't replace list name: " + obj->asString());
          }
        }
      }

      return RulpUtil::toList(name, std::move(newList));
    }

    auto expr = AS_EXPR(obj);
    return expr->isEarly()
            ? RulpFactory::createExpressionEarly(std::move(newList)) 
            : RulpFactory::createExpression(std::move(newList));
  }
  case E_MEMBER: {

    auto mbr = RulpUtil::asMember(obj);
    if (mbr->getValue() == null) {

      boolean update = false;

      auto sub      = mbr->getSubject();
      auto mbrName  = mbr->getName();

      if (TYPE_INDEX_OF(sub) == E_ATOM) {
        auto var =  find(replaceMap, RulpUtil::asAtom(sub)->getName());
        if (var != null) {
          sub     = var;
          update  = true;
        }
      }

      if (update) {
        return RulpFactory::createMember(sub, mbrName, null);
      }
    }

    return obj;
  }

  default:
    return obj;
  }
}

IRVar* RuntimeUtil::getActualVar(IRVar* var, IRInterpreter* interpreter, IRFrame* frame){
  if (var->getValue() != null) {
    return var;
  }

  auto entry = frame->getEntry(var->getName());
  if (entry == null) {
    throw RException("var not found: " + var->asString());
  }

  return AS_VAR(entry->getObject());
}

IRVar* RuntimeUtil::setVar(IRObject* obj, IRObject* val, IRInterpreter* interpreter, IRFrame* frame){
  IRVar* var = null;

  switch (TYPE_INDEX_OF(obj)) {
  case E_ATOM: {
    auto varName = RulpUtil::asAtom(obj)->getName();
    auto entry = frame->getEntry(varName);
    if (entry == null) {
      throw RException("var not found: " + varName);
    }
    var = AS_VAR(entry->getObject());
    break;
  }

  case E_VAR:    
    var = RuntimeUtil::getActualVar(AS_VAR(obj), interpreter, frame);
    break;

  case E_EXPR:
    return setVar(interpreter->compute(frame, obj), val, interpreter, frame);

  case E_MEMBER: {

    auto mbr = RuntimeUtil::getActualMember(RulpUtil::asMember(obj), interpreter, frame);
    if (!RuntimeUtil::canAccess(mbr, interpreter, frame)) {
      throw RException("Can't access member<" + mbr->asString() + "> in frame<" + frame->asString() + ">");
    }

    if (RulpUtil::isPropertyFinal(mbr)) {
      throw RException("Can't update final member: " + mbr->asString());
    }

    return setVar(mbr->getValue(), val, interpreter, frame);
  }
  default:
    throw RException("Invalid var: " + obj->asString());
  }

  var->setValue(interpreter->compute(frame, val));
  return var;
}

int RuntimeUtil::getCallStatsId(){
  return callStatsId;
}

int RuntimeUtil::getFrameMaxLevel() {
  return frameMaxLevel;
}

std::map<IRObject*, DeCounter*> RuntimeUtil::getObjecCallCount(IRFrame* frame) {

  std::map<IRObject*, DeCounter*> cm;

  for (auto entry : frame->listEntries()) {

    auto obj = entry->getObject();
    if (obj == null) {
      continue;
    }

    if(IS_CALLABLE(obj)){
      auto call = AS_CALL(obj);
      auto counter = call->getCallCount(RuntimeUtil::getCallStatsId());
      if (counter->getTotalCount() > 0) {
        cm[call] = counter;
      }

      continue;
    }

    if(IS_SUBJECT(obj)){

      if(auto sub = AS_SUBJECT(obj); sub) {

        if (TYPE_INDEX_OF(obj) == E_FRAME) {
          continue;
        }

        // std::cout << "print subject: " << obj->asString() << "\n";

        int member_count = sub->getMemberCount();
      // std::cout << "member_count: " << member_count << "\n";
        for (int i = 0; i < member_count; ++i) {
          auto mbr = sub->getMember(i);
          if(!mbr){
            continue;
          }

          // std::cout << ", ptr=" << mbr  << "\n";
          // std::cout << "mbr: " << mbr->asString() << ", ptr=" << mbr << "\n";

          auto mbrObj = mbr->getValue();
          if (!mbrObj) {
            continue;
          }

          if(mbrObj->isCallable()){
            auto call = AS_CALL(mbrObj);
            auto counter = call->getCallCount(RuntimeUtil::getCallStatsId());
            if (counter->getTotalCount() > 0) {
              cm[call] = counter;
            }

            continue;
          }      
        }    
      }
    }
  }

  return std::move(cm);
}

int RuntimeUtil::getExprComputeCount(RTypeIndex type) {

  switch (type) {
  case E_FACTOR:
    return exprComputeFactorCount;

  case E_FUNC:
    return exprComputeFuncCount;

  case E_TEMPLATE:
    return exprComputeTemplateCount;

  case E_MACRO:
    return exprComputeMacroCount;

  case E_MEMBER:
    return exprComputeMemberCount;

  default:
    return 0;
  }

}

IRClass* RuntimeUtil::getNoClass(IRInterpreter* interpreter) {
  return AS_CLASS(interpreter->getObject(A_NOCLASS));
}

void RuntimeUtil::reset(){

  exprComputeFactorCount = 0;
  exprComputeMacroCount = 0;
  exprComputeFuncCount = 0;
  exprComputeTemplateCount = 0;
  exprComputeMemberCount = 0;

  frameMaxLevel = 0;
  callStatsId++;

}

struct FactorHolder {
  std::string name;
  IRFactor*   factor;

  FactorHolder() = default;
  FactorHolder(const FactorHolder& FH){
    this->factor  = FH.factor;
    this->name    = FH.name;
  }
};

struct ObjectHolder {
  std::string name;
  IRObject*   object;

  ObjectHolder() = default;
  ObjectHolder(const ObjectHolder& FH){
    this->object  = FH.object;
    this->name    = FH.name;
  }
};

struct LoadertHolder {
  std::string name;
  IRLoader* object ;

  LoadertHolder() = default;
  LoadertHolder(const LoadertHolder& FH){
    this->object  = FH.object;
    this->name    = FH.name;
  }
};

static StaticHolder<std::map<std::string, FactorHolder>> _G_FactorRegistry;
static StaticHolder<std::map<std::string, ObjectHolder>> _G_ObjectRegistry;
static StaticHolder<std::map<std::string, LoadertHolder>> _G_LoaderRegistry;

static bool _has_registry_factor(std::string name){
  return _G_FactorRegistry->find(name) != _G_FactorRegistry->end();
}

static bool _has_registry_object(std::string name){
  return _G_ObjectRegistry->find(name) != _G_ObjectRegistry->end();
}

static bool _has_registry_loader(std::string name){
  return _G_LoaderRegistry->find(name) != _G_LoaderRegistry->end();
}

void RuntimeUtil::registryFactor(IRFactor* factor){

  assert(factor && "null object");

  auto name = factor->getName();

  assert(!name.empty() && "invalid factor name");
  assert(!_has_registry_factor(name) && "duplicated factor found");

  FactorHolder FH;
  FH.factor   = factor;
  FH.name     = name;

  _G_FactorRegistry->try_emplace(name, FH);
}

void RuntimeUtil::registryObject(IRObject* object, StrConstRef name){

  assert(object && "null object");
  assert(!name.empty() && "invalid factor name");
  assert(!_has_registry_object(name) && "duplicated factor found");

  ObjectHolder PH;
  PH.object   = object;
  PH.name     = name;

  _G_ObjectRegistry->try_emplace(name, PH);
}

void RuntimeUtil::registryLoader(IRLoader* loader, StrConstRef name) {
  
  assert(loader && "null loader");
  assert(!name.empty() && "invalid loader name");
  assert(!_has_registry_loader(name) && "duplicated loader found");

  LoadertHolder PH;
  PH.object   = loader;
  PH.name     = name;

  _G_LoaderRegistry->try_emplace(name, PH);

}

void RuntimeUtil::loadAllRegisterObject(IRInterpreter* interpreter, IRFrame* frame){
  
  for(auto it = _G_FactorRegistry->begin(); it != _G_FactorRegistry->end(); ++it){
    auto FH = it->second;
    RuntimeUtil::addFrameObject(frame, FH.factor);

    // auto obj = RulpUtil::lookup(FH.factor, interpreter, frame);
    // auto factor = AS_FACTOR(obj);

    if(FH.factor->getMinArgCount() != -1) {
      AttrUtil::setAttribute(FH.factor, ATTR_ARG_MIN_COUNT, RulpFactory::createInteger(FH.factor->getMinArgCount()));
    }

    if(FH.factor->getMaxArgCount() != -1) {
      AttrUtil::setAttribute(FH.factor, ATTR_ARG_MAX_COUNT, RulpFactory::createInteger(FH.factor->getMaxArgCount()));
    }

  }

  for(auto it = _G_ObjectRegistry->begin(); it != _G_ObjectRegistry->end(); ++it){
    auto OH = it->second;
    RuntimeUtil::addFrameObject(frame, OH.object);
  }

}


IRLoader* RuntimeUtil::findLoader(StrConstRef name) {

  auto it = _G_LoaderRegistry->find(name);
  if(it == _G_LoaderRegistry->end()) {
    return null;
  }

  return it->second.object;
}

IRLoader* RuntimeUtil::removeLoader(StrConstRef name) {

  auto it = _G_LoaderRegistry->find(name);
  if(it == _G_LoaderRegistry->end()) {
    return null;
  }

  auto loader = it->second.object;
  _G_LoaderRegistry->erase(it);

  return it->second.object;
}


} // namespace lfc