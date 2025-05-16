// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[opt_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(opt_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
TRACE_SUB_MODULE_IMPL(opt_util)
#include "rulp/utils/RulpOptUtil.h"
#include "rulp/utils/RulpUtil.h"
#include "lfc/base/container.h"

using namespace lfc;
using namespace lfc;
namespace lfc {

static int OptFactorCount = 0;

boolean RulpOptUtil::isConstNumber(IRObject* obj){
  switch (TYPE_INDEX_OF(obj)) {
  case E_INT:
  case E_FLOAT:
  case E_DOUBLE:
  case E_LONG:
    return true;

  case E_CONSTANT:
    return isConstNumber(AS_CONST(obj)->getValue());

  default:
    return false;
  }
}

boolean RulpOptUtil::isConstNumber(IRObject* obj, double value){
  switch (TYPE_INDEX_OF(obj)) {
  case E_INT:
    return AS_INT(obj)->asInteger() == value;

  case E_FLOAT:
    return AS_FLOAT(obj)->asFloat() == value;

  case E_DOUBLE: 
    return AS_DOUBLE(obj)->asDouble() == value;

  case E_LONG: 
    return AS_LONG(obj)->asLong() == value;

  case E_CONSTANT:
    return isConstNumber(AS_CONST(obj)->getValue(), value);

  default:
    return false;
  }
}

boolean RulpOptUtil::isConstValue(IRObject* obj){
  switch (TYPE_INDEX_OF(obj)) {
  case E_BOOL:
  case E_INT:
  case E_FLOAT:
  case E_DOUBLE:
  case E_CONSTANT:
  case E_LONG:
  case E_NIL:
  case E_STRING:
    return true;

  case E_LIST:
    return isConstValue(RulpUtil::asList(obj)->iterator());

  default:
    return false;
  }
}

boolean RulpOptUtil::isConstValue(IRIteratorPtr it){
  while (it->hasNext()) {
    if (!isConstValue(it->next())) {
      return false;
    }
  }

  return true;
}

static std::set<std::string> newFrameFactorNameSet;

boolean RulpOptUtil::isNewFrameFactor(IRObject* obj){
 
  if (auto type = TYPE_INDEX_OF(obj); type != E_ATOM && type != E_FACTOR) {
    return false;
  }

  if(newFrameFactorNameSet.empty()){
    newFrameFactorNameSet.insert(F_FOREACH);
    newFrameFactorNameSet.insert(F_TRY);
    newFrameFactorNameSet.insert(A_DO);
    newFrameFactorNameSet.insert(F_LET);
    newFrameFactorNameSet.insert(F_LOOP);
    newFrameFactorNameSet.insert(F_OPT);
  }

  return lfc::find(newFrameFactorNameSet, obj->asString());
}

void RulpOptUtil::listReturnObject(IRExpr* expr, std::vector<IRObject*>& exprList){
  auto e0 = expr->get(0);   
  if (TYPE_INDEX_OF(e0) != E_ATOM && TYPE_INDEX_OF(e0) != E_FACTOR) {
    return;
  }

  auto op = e0->asString();
  if(op == A_DO){
    auto it = expr->listIterator(1);
    while (it->hasNext()) {
      auto e = it->next();
      if (TYPE_INDEX_OF(e) == E_EXPR) {        
        listReturnObject(AS_EXPR(e), exprList);
      }
    }
  }
  else if(op == F_IF){
    auto it = expr->listIterator(2);
    while (it->hasNext()) {
      auto e = it->next();
      if (TYPE_INDEX_OF(e) == E_EXPR) {        
        listReturnObject(AS_EXPR(e), exprList);
      }
    }
  }
  else if(op == F_RETURN || op == F_RETURN ){
    if (expr->size() > 1) {
      exprList.push_back(expr->get(1));
    }
  }
 
}

void RulpOptUtil::reset(){
  OptFactorCount = 0;
}

} // namespace lfc