// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include <assert.h>
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[rulp_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(rulp_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
#include "rulp/lang/RConstant.h"
#include "rulp/lang/RGlobal.h"
#include "rulp/lang/RException.h"
#include "rulp/utils/RulpUtil.h"
#include "rulp/utils/RulpFactory.h"
#include "rulp/utils/RuntimeUtil.h"

#include "lfc/base/to_string.h"
#include "lfc/base/trace.h"
using namespace lfc;
using namespace lfc;
namespace lfc {


boolean RulpUtil::isIf1(IRList* args) {

  // (if condition true-expr)
  return args->size() == 3;
}

boolean RulpUtil::isIf2(IRList* args) {

  // (if condition true-expr false-expr)
  return args->size() == 4 && !RulpUtil::isAtom(args->get(2), A_DO);
}

boolean RulpUtil::isIf3(IRList* args) {

  // (if condition do expr1 expr2 expr3 ...)
  return args->size() >= 4 && RulpUtil::isAtom(args->get(2), A_DO);
}

boolean RulpUtil::isLoop1(IRList* args) {
  // (loop for x in '(1 2 3) do ...)
  return args->size() >= 7 
      && RulpUtil::isAtom(args->get(1), F_FOR)
      && RulpUtil::isAtom(args->get(2))
      && RulpUtil::isAtom(args->get(3), F_IN) 
      && RulpUtil::isAtom(args->get(5), A_DO);
}

boolean RulpUtil::isLoop2(IRList* args) {
  // (loop for x from 1 to 3 do ...)
  return args->size() >= 9 
      && RulpUtil::isAtom(args->get(1), F_FOR) 
      && RulpUtil::isAtom(args->get(2))
      && RulpUtil::isAtom(args->get(3), A_FROM) 
      && RulpUtil::isAtom(args->get(5), F_TO)
      && RulpUtil::isAtom(args->get(7), A_DO);
}

boolean RulpUtil::isLoop3(IRList* args) {
  return args->size() == 1 || TYPE_INDEX_OF(args->get(1)) == E_EXPR;
}

boolean RulpUtil::isLoop4(IRList* args) {
  // (loop for x from 1 to 3 by 1 do ...) A_By
  return args->size() >= 9 
      && RulpUtil::isAtom(args->get(1), F_FOR) 
      && RulpUtil::isAtom(args->get(2))
      && RulpUtil::isAtom(args->get(3), A_FROM) 
      && RulpUtil::isAtom(args->get(5), F_TO)
      && RulpUtil::isAtom(args->get(7), A_By) 
      && RulpUtil::isAtom(args->get(9), A_DO);
}

IRObject* RulpUtil::handle_error(IRError* err, IRInterpreter* interpreter, IRFrame* frame) {

  std::string errId = err->getId()->getName();

  std::string handleName = C_HANDLE + errId;
  std::string valueName = errId;

  auto handlEntry = frame->getEntry(handleName);
  if (handlEntry == null) {

    handlEntry = frame->getEntry(C_HANDLE_ANY);
    if (handlEntry == null) {
      return null;
    }

    valueName = AS_ATOM(frame->getEntry(C_ERROR_DEFAULT)->getObject())->getName();
  }

  auto catchExpr = AS_EXPR(handlEntry->getObject());
  frame->setEntry(valueName, err);

  IRObject* rst = null;
  auto iter = catchExpr->listIterator(2);
  while (iter->hasNext()) {
    rst = RuntimeUtil::compute(iter->next(), interpreter, frame);
  }

  return rst;
}

IRObject* RulpUtil::throw_error(IRInterpreter* interpreter, IRFrame* frame, IRAtom* errId, IRObject* errValue, IRObject* fromObject) {
  auto err = RulpFactory::createError(interpreter, errId, errValue);
  auto rst = handle_error(err, interpreter, frame);
  if (rst == null) {
    throw RExceptionError(fromObject, frame, err);
  }

  return rst;
}

} // namespace lfc