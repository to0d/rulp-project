// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[math_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(math_util)()
#include <iostream>
#define LFC_TRACE_STREAM std::cout
TRACE_SUB_MODULE_IMPL(math_util)
#include "rulp/lang.h"
#include "rulp/lang/RArithmeticOperator.h"
#include "rulp/utils/RulpMathUtil.h"
#include "rulp/utils/RulpOptUtil.h"
#include "lfc/base/string/format.h"
#include "lfc/base/to_string.h"
#include <cmath>

using namespace lfc;
using namespace lfc;
namespace lfc {

static int result2Type[TYPE_NUM][TYPE_NUM] = {
// NIL ATOM BOOL INT LONG FLOAT DOUBLE STRING BLOB LIST EXPR ARR VAR CONS FACTOR FUNC TEMPLATE MACRO INSTANCE CLASS NATIVE MEMBER FRAME ITER
  {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // NIL
, {  0,  1,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // ATOM
, {  0,  0,   2,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // BOOL
, {  0,  0,   0,   3,   4,    5,     6,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // INT
, {  0,  0,   0,   4,   4,    5,     6,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // LONG
, {  0,  0,   0,   5,   5,    5,     6,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // FLOAT
, {  0,  0,   0,   6,   6,    6,     6,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // DOUBLE
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // STRING
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // BLOB
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // LIST
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,  10,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // EXPR
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // ARRAY
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // VAR
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // CONSTANT
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // FACTOR
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // FUNC
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // TEMPLATE
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // MACRO
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // INSTANCE
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // CLASS
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // NATIVE
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // MEMBER
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // FRAME
, {  0,  0,   0,   0,   0,    0,     0,     0,   0,   0,   0,  0,  0,   0,     0,   0,       0,    0,       0,    0,     0,     0,    0,   0} // ITERATOR
};

RTypeIndex RulpMathUtil::getTypeConvert(RTypeIndex a, RTypeIndex b){
  return (RTypeIndex) result2Type[a][b];
}

IRObject* RulpMathUtil::computeArithmeticExpression(RArithmeticOperator op, IRObject* a, IRObject* b){

  auto at = TYPE_INDEX_OF(a);
  auto bt = TYPE_INDEX_OF(b);

  auto rt = RulpMathUtil::getTypeConvert(at, bt);
  if(rt == E_NIL) {
    throw RException(LFC_STR_FORMAT_BGN "Invalid op types: %s %s"
                                        , a->asString().c_str()
                                        , b->asString().c_str()
                                        LFC_STR_FORMAT_END
                                        );
  }

  if(op == RArithmeticOperator::DIV && RulpOptUtil::isConstNumber(b, 0)) {
    throw RException(LFC_STR_FORMAT_BGN "divide zero(%s %s %s)"
                                        , to_op_string(op).c_str()
                                        , a->asString().c_str()
                                        , b->asString().c_str()
                                        LFC_STR_FORMAT_END
                                        );
  }

  switch (rt) {
  case E_FLOAT: {

    float av = RulpUtil::toFloat(a);
    float bv = RulpUtil::toFloat(b);

    switch (op) {
    case RArithmeticOperator::ADD:
      av += bv;
      break;

    case RArithmeticOperator::BY:
      av *= bv;
      break;

    case RArithmeticOperator::SUB:
      av -= bv;
      break;

    case RArithmeticOperator::DIV:
      av /= bv;
      break;

    // case RArithmeticOperator::MOD:
    //   av %= bv;
    //   break;

    case RArithmeticOperator::POWER:
      av = (float) pow(av, bv);
      break;

    default:
      throw RException(LFC_STR_FORMAT_BGN "Not support op: %s", to_op_string(op).c_str() LFC_STR_FORMAT_END);
    }

    return RulpFactory::createFloat(av);
  }

  case E_DOUBLE: {

    double av = RulpUtil::toDouble(a);
    double bv = RulpUtil::toDouble(b);

    switch (op) {
    case RArithmeticOperator::ADD:
      av += bv;
      break;

    case RArithmeticOperator::BY:
      av *= bv;
      break;

    case RArithmeticOperator::SUB:
      av -= bv;
      break;

    case RArithmeticOperator::DIV:
      av /= bv;
      break;

    // case RArithmeticOperator::MOD:
    //   av %= bv;
    //   break;

    case RArithmeticOperator::POWER:
      av = (double) pow(av, bv);
      break;

    default:
      throw RException(LFC_STR_FORMAT_BGN "Not support op: %s", to_op_string(op).c_str() LFC_STR_FORMAT_END);
    }

    return RulpFactory::createDouble(av);
  }

  case E_INT: {

    int av = RulpUtil::toInt(a);
    int bv = RulpUtil::toInt(b);

    switch (op) {
    case RArithmeticOperator::ADD:
      av += bv;
      break;

    case RArithmeticOperator::BY:
      av *= bv;
      break;

    case RArithmeticOperator::SUB:
      av -= bv;
      break;

    case RArithmeticOperator::DIV:
      av /= bv;
      break;

    case RArithmeticOperator::MOD:
      av %= bv;
      break;

    case RArithmeticOperator::POWER:
      av = pow(av, bv);
      break;

    case RArithmeticOperator::AND:
      av = av & bv;
      break;

    case RArithmeticOperator::OR:
      av = av | bv;
      break;

    case RArithmeticOperator::XOR:
      av = av ^ bv;
      break;

    default:
      throw RException(LFC_STR_FORMAT_BGN "Not support op: %s", to_op_string(op).c_str() LFC_STR_FORMAT_END);
    }

    return RulpFactory::createInteger(av);
  }

  case E_LONG: {

    long av = RulpUtil::toLong(a);
    long bv = RulpUtil::toLong(b);

    switch (op) {
    case RArithmeticOperator::ADD:
      av += bv;
      break;

    case RArithmeticOperator::BY:
      av *= bv;
      break;

    case RArithmeticOperator::SUB:
      av -= bv;
      break;

    case RArithmeticOperator::DIV:
      av /= bv;
      break;

    case RArithmeticOperator::MOD:
      av %= bv;
      break;

    case RArithmeticOperator::POWER:
      av = (long) pow(av, bv);
      break;

    case RArithmeticOperator::AND:
      av = av & bv;
      break;

    case RArithmeticOperator::OR:
      av = av | bv;
      break;

    case RArithmeticOperator::XOR:
      av = av ^ bv;
      break;

    default:
      throw RException(LFC_STR_FORMAT_BGN "Not support op: %s", to_op_string(op).c_str() LFC_STR_FORMAT_END);
    }

    return RulpFactory::createLong(av);
  }

  default:

    throw RException(LFC_STR_FORMAT_BGN "Invalid arithmetic expression: (%s %s %s)"
                                        , to_op_string(op).c_str()
                                        , a->asString().c_str()
                                        , b->asString().c_str()
                                        LFC_STR_FORMAT_END
                                        );
  }

}

static boolean isNumber(IRObject* obj) {

  switch (TYPE_INDEX_OF(obj)) {
  case E_DOUBLE:
  case E_FLOAT:
  case E_INT:
  case E_LONG:
    return true;

  default:
    return false;

  }
}

boolean RulpMathUtil::computeRelationalExpression(RRelationalOperator op, IRObject* a, IRObject* b){
  if (isNumber(a)) {
    if (!isNumber(b)) {
      throw RException( LFC_STR_FORMAT_BGN 
                          "Invalid rational expression: (%s %s %s)"
                        , to_op_string(op).c_str()
                        , a->asString().c_str()
                        , b->asString().c_str() 
                        LFC_STR_FORMAT_END);
    }
  }
  else {
    switch (op) {
    case RRelationalOperator::EQ: return RulpUtil::equal(a, b);
    case RRelationalOperator::NE: return !RulpUtil::equal(a, b);
    default:
      break;
    }
  }

  auto at = TYPE_INDEX_OF(a);
  auto bt = TYPE_INDEX_OF(b);

  auto rt = RulpMathUtil::getTypeConvert(at, bt);
  if (rt == E_NIL) {
    throw RException( LFC_STR_FORMAT_BGN 
                          "Invalid op types: %s %s %s"
                        , to_op_string(op).c_str()
                        , a->asString().c_str()
                        , b->asString().c_str() 
                      LFC_STR_FORMAT_END);
  }

  switch (rt) {

  case E_FLOAT: {

    float av = RulpUtil::toFloat(a);
    float bv = RulpUtil::toFloat(b);

    switch (op) {

    case RRelationalOperator::GT: // Greater than
      return av > bv;

    case RRelationalOperator::GE: // Greater than or equal
      return av >= bv;

    case RRelationalOperator::LT: // Less than
      return av < bv;

    case RRelationalOperator::LE: // Less than or equal
      return av <= bv;

    case RRelationalOperator::EQ: // Equal
      return av == bv;

    case RRelationalOperator::NE: // not equal
      return av != bv;

    default:
      break;
    }

    break;
  }

  case E_DOUBLE: {

    double av = RulpUtil::toDouble(a);
    double bv = RulpUtil::toDouble(b);

    switch (op) {

    case RRelationalOperator::GT: // Greater than
      return av > bv;

    case RRelationalOperator::GE: // Greater than or equal
      return av >= bv;

    case RRelationalOperator::LT: // Less than
      return av < bv;

    case RRelationalOperator::LE: // Less than or equal
      return av <= bv;

    case RRelationalOperator::EQ: // Equal
      return av == bv;

    case RRelationalOperator::NE: // not equal
      return av != bv;

    default:
      break;
    }

    break;
  }

  case E_INT: {
    int av = RulpUtil::toInt(a);
    int bv = RulpUtil::toInt(b);

    switch (op) {

    case RRelationalOperator::GT: // Greater than
      return av > bv;

    case RRelationalOperator::GE: // Greater than or equal
      return av >= bv;

    case RRelationalOperator::LT: // Less than
      return av < bv;

    case RRelationalOperator::LE: // Less than or equal
      return av <= bv;

    case RRelationalOperator::EQ: // Equal
      return av == bv;

    case RRelationalOperator::NE: // not equal
      return av != bv;

    default:
      break;
    }
    break;
  }

  case E_LONG: {

    auto av = RulpUtil::toLong(a);
    auto bv = RulpUtil::toLong(b);

    switch (op) {

    case RRelationalOperator::GT: // Greater than
      return av > bv;

    case RRelationalOperator::GE: // Greater than or equal
      return av >= bv;

    case RRelationalOperator::LT: // Less than
      return av < bv;

    case RRelationalOperator::LE: // Less than or equal
      return av <= bv;

    case RRelationalOperator::EQ: // Equal
      return av == bv;

    case RRelationalOperator::NE: // not equal
      return av != bv;

    default:
      break;
    }

    break;
  }

  default:
    break;
  }

  throw RException( LFC_STR_FORMAT_BGN 
                        "Invalid rational expression: %s %s %s"
                      , to_op_string(op).c_str()
                      , a->asString().c_str()
                      , b->asString().c_str() 
                    LFC_STR_FORMAT_END);
}

} // namespace lfc