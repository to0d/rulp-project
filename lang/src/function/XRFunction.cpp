// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "XRFunction.h" 
#include "rulp/lang/RException.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/RuntimeUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/ReturnTypeUtil.h"
#include "rulp/utils/LCOUtil.h"
#include "lfc/base/to_string.h"
#include "lfc/base/string/format.h"
#include "lfc/base/auto/auto_do.h"
#include <sstream>
#include <iostream>

using namespace lfc;

namespace lfc {

XRFunction::XRFunction(IRFrame* defineFrame, StrConstRef name, std::vector<IRParaAttr*>&& paraAttrList, IRExpr* funBody)
  : defineFrame(defineFrame)
  , name(name)
  , paraAttrList(paraAttrList)
  , paraCount(paraAttrList.size())
  , funBody(funBody)
{
  // std::cout << "funBody=" << funBody->asString() << "\n";
  // std::cout << "create func: name=" << name << ", addr=" << this << "\n";
  RULP_INC_REF(paraAttrList);
  RULP_INC_REF(funBody);
}

XRFunction::~XRFunction() {
  // std::cout << "delete func: name=" << name << ", addr=" << this << "\n";
}

void XRFunction::_delete(){

  RULP_DEC_REF(funBody);
  RULP_DEC_REF(paraAttrList);

  AbsFunctionAdapter::_delete();
}

const std::string& XRFunction::asString() const {
  return name;
}

void XRFunction::_matchTypeList(IRList* args, IRFrame* frame){
  if ((paraCount + 1) != args->size()) {
    throw RExceptionUnmatchPara(this, frame, "Invalid parameter count: " + TO_STR(paraCount));
  }

  for(int argIndex = 0; argIndex < paraCount; ++argIndex){
    auto& attr = paraAttrList[argIndex];
    auto  typeAtom = attr->getParaType();
    IRObject* value = args->get(argIndex+1);

    // Match any type
    if (typeAtom == O_Nil || value == null|| value == O_Nil) {
      continue;
    }

    if (!RuntimeUtil::matchParaType(value, typeAtom)) {

      if (TYPE_INDEX_OF(value) == E_EXPR && AttrUtil::containAttribute(attr, A_OPT_LCO)) {
        IRAtom* exprTypeAtom = ReturnTypeUtil::returnTypeOf(value, frame);
        if (exprTypeAtom != O_Nil && RulpUtil::equal(exprTypeAtom, typeAtom)) {
          continue;
        }
      }

      throw RExceptionRuntime( this
                             , frame
                             , LFC_STR_FORMAT_BGN 
                                   "the %d argument<%s> not match type <%s>"
                                  , argIndex
                                  , value->asString().c_str()
                                  , typeAtom->asString().c_str()
                               LFC_STR_FORMAT_END
                               );
    }
  }
}

IRObject* XRFunction::compute(IRList* args, IRInterpreter* interpreter, IRFrame* frame) {
  _matchTypeList(args, frame);

  auto funFrame = RulpFactory::createFrame(frame, A_FUN_PRE + name);
  RULP_AUTO_DEC_REF(funFrame);

  try {
    RULP_INC_REF(funFrame);

    for(int argIndex = 0; argIndex < paraCount; ++argIndex){
      auto& attr = paraAttrList[argIndex];
      auto paraName = attr->getParaName();
      IRObject* arg = args->get(argIndex+1);
      if (arg == null) {
        arg = O_Nil;
      } 
      else if (TYPE_INDEX_OF(arg) != E_VAR) {
        boolean lazyLoad = false;

        // Lazy compute
        if (TYPE_INDEX_OF(arg) == E_EXPR && AttrUtil::containAttribute(attr, A_OPT_LCO)) {
          arg = RulpFactory::createExpression({
                  RulpFactory::createFunctionLambda(
                    RulpFactory::createFunction( frame
                                                , F_LAMBDA
                                                , {}
                                                , RulpFactory::createExpression({O_RETURN, arg}))
                    , frame)
                  });
          LCOUtil::incPassCount();
          lazyLoad = true;
        }

        arg = RulpFactory::createVar(paraName, arg);
        if (lazyLoad) {
          AttrUtil::addAttribute(arg, A_OPT_LCO);
        }
      }

      funFrame->setEntry(paraName, arg);
    }

    // std::cout << "funBody=" << funBody->asString() << "\n";
    interpreter->compute(funFrame, funBody);
    return O_Nil;

  } 
  catch (RExceptionReturn& r) {
    return r.returnValue(frame);
  } 
  

  return O_Nil;
}


RType XRFunction::getType() const {
  return T_FUNC;
}

StrConstRef XRFunction::getSignature() const {
  if (signature.empty()) {

    std::stringstream ss;

    ss << '(';
    ss << name;

    for (auto attr : getParaAttrs()) {
      ss << ' ';
      ss << attr->getParaType()->asString();
    }

    ss << ')';

    signature = ss.str();
  }

  return signature;
}

} // namespace lfc