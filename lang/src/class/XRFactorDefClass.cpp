// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/runtime/IRFactorImpl.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/SubjectUtil.h"

namespace lfc {
XRFACTOR_IMPL_BEGIN(XRFactorDefClass)

  int argSize = args->size();

  /*****************************************************/
  // class name
  /*****************************************************/
  auto className = AS_ATOM(args->get(1))->getName();

  /*****************************************************/
  // find super expression
  /*****************************************************/
  IRClass* superClass = null;
  int superExprIndex = -1;
  for (int i = 2; i < argSize; ++i) {

    auto extendsExpr = AS_EXPR(args->get(i));

    if (!extendsExpr->isEmpty() && extendsExpr->get(0)->asString() == F_EXTENDS) {

      if (extendsExpr->size() != 2) {
        throw RException("Invalid super expression: " + extendsExpr->asString());
      }

      superExprIndex = i;
      superClass = AS_CLASS(interpreter->compute(frame, extendsExpr->get(1)));
      if (superClass->isFinal()) {
        throw RException("Can't inherit final class: " + superClass->asString());
      }
      break;
    }
  }

  auto defClass = RulpFactory::createClassDefClass(className, frame, superClass);
  if (superClass != null) {
    RulpUtil::setMember(defClass, F_EXTENDS, superClass);
  }

  /*****************************************************/
  // Update Entry
  /*****************************************************/
  RuntimeUtil::addFrameObject(frame, defClass);

  /*****************************************************/
  // members
  /*****************************************************/
  for (int i = 2; i < argSize; ++i) {

    auto mbrExpr = AS_EXPR(args->get(i));

    int mbrExprSize = mbrExpr->size();
    if (mbrExprSize < 2) {
      throw RException("Invalid member expression: " + mbrExpr->asString());
    }

    auto e0 = mbrExpr->get(0);
    if (TYPE_INDEX_OF(e0) != E_ATOM) {
      throw RException("Invalid member expression: " + mbrExpr->asString());
    }

    auto e0Name = AS_ATOM(e0)->getName();
    if( e0Name == F_DEFVAR ){
      SubjectUtil::defineMemberVar(defClass, mbrExpr, interpreter, frame);
    }
    else if(e0Name == F_DEFUN){
      SubjectUtil::defineMemberFun(defClass, AS_ATOM(mbrExpr->get(1))->getName(), mbrExpr, interpreter, frame);
    }
    else if(e0Name == F_EXTENDS){
      if (superExprIndex != i) {
        throw RException("duplicated super expression: " + mbrExpr->asString());
      }
    }
    else {
      throw RException("Invalid member obj: " + mbrExpr->asString());
    }    
  }

  if (AttrUtil::hasAttributeList(args)) {
    for (auto attr : AttrUtil::getAttributeKeyList(args)) {
      if(attr == A_FINAL){
        defClass->setFinal(true);
      }
      AttrUtil::addAttribute(defClass, attr);
    }
  }

  return defClass;

XRFACTOR_IMPL_ARG(2, -1)
XRFACTOR_IMPL_END
STATIC_FACTOR_REGISTER(XRFactorDefClass, F_DEFCLASS);

} // namespace lfc
