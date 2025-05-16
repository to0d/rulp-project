// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "rulp/lang.h"
#include "rulp/utils/AttrUtil.h"
#include "rulp/utils/StmtCountUtil.h"
#include "lfc/base/container.h"

using namespace lfc;
using namespace lfc;
namespace lfc {

static int _getStmtCount(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame);

static int _getFactorStmtCount(IRFactor* factor, IRInterpreter* interpreter, IRFrame* frame) {
  auto attrValue = AttrUtil::getAttributeValue(factor, A_STMT_COUNT);
  if (attrValue != null) {
    return AS_INT(attrValue)->asInteger();
  }

  return 1;
}

static int _getFuncStmtCount(IRFunction* func, IRInterpreter* interpreter, IRFrame* frame) {

  auto attrValue = AttrUtil::getAttributeValue(func, A_STMT_COUNT);
  if (attrValue != null) {
    return AS_INT(attrValue)->asInteger();
  }

  int count = 0;

  if (AttrUtil::isRecursive(func)) {
    count = -1;

  } 
  else {

    if (func->isList()) {
      auto funcList = AS_FUNC_LIST(func);
      for (auto childFunc : funcList->getAllFuncList()) {
        int childCount = _getFuncStmtCount(childFunc, interpreter, frame);
        if (count < childCount) {
          count = childCount;
        }
      }
    }
     else {
      count = _getStmtCount(func->getFunBody(), interpreter, frame);
    }
  }

  AttrUtil::setAttribute(func, A_STMT_COUNT, RulpFactory::createInteger(count));
  return count;
}

static int _getMacroStmtCount(IRMacro* macro, IRInterpreter* interpreter, IRFrame* frame) {

  auto attrValue = AttrUtil::getAttributeValue(macro, A_STMT_COUNT);
  if (attrValue != null) {
    return AS_INT(attrValue)->asInteger();
  }

  int count = _getStmtCount(macro->getMacroBody(), interpreter, frame);
  AttrUtil::setAttribute(macro, A_STMT_COUNT, RulpFactory::createInteger(count));
  return count;
}

static int _getExprStmtCount(IRExpr* expr, IRInterpreter* interpreter, IRFrame* frame) {

  if (expr->isEmpty()) {
    return 1;
  }

  auto e0 = RulpUtil::lookup(expr->get(0), interpreter, frame);
  int count = 1 + _getStmtCount(e0, interpreter, frame);

  auto it = expr->listIterator(1);
  while (it->hasNext()) {
    count += _getStmtCount(it->next(), interpreter, frame);
  }

  return count;
}

static int _getListStmtCount(IRList* list, IRInterpreter* interpreter, IRFrame* frame) {

  int count = 0;

  auto it = list->iterator();
  while (it->hasNext()) {
    count += _getStmtCount(it->next(), interpreter, frame);
  }

  return count;
}

static int _getStmtCount(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame) {

//		if (level++ > 100) {
//			System.out.println();
//		}

  switch (TYPE_INDEX_OF(obj)) {

  case E_FACTOR:
    return _getFactorStmtCount(AS_FACTOR(obj), interpreter, frame);

  case E_FUNC:
    return _getFuncStmtCount(AS_FUNC(obj), interpreter, frame);

  case E_MACRO:
    return _getMacroStmtCount(AS_MACRO(obj), interpreter, frame);

  case E_TEMPLATE:
    return 1;

  case E_EXPR:
    return _getExprStmtCount(AS_EXPR(obj), interpreter, frame);

  case E_LIST:
    return _getListStmtCount(AS_LIST(obj), interpreter, frame);

  case E_ATOM: {

    auto atomName = AS_ATOM(obj)->getName();
    auto entry = RuntimeUtil::lookupFrameEntry(frame, atomName);
    // is pure atom
    if (entry == null) {
      return 0;
    }

    auto entryValue = entry->getObject();
    if (entryValue == null || TYPE_INDEX_OF(entryValue) == E_ATOM) {
      return 0;
    }

    return _getStmtCount(entryValue, interpreter, frame);
  }
  default:
    return 0;
  }
}

int StmtCountUtil::getStmtCount(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame){
  return _getStmtCount(obj, interpreter, frame);
}

} // namespace lfc