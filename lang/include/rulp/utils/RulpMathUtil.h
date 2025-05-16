// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RULPMATHUTIL_H__
#define __RULP_LANG_RULPMATHUTIL_H__
#include "lfc/base/trace_macro.h"
#include "rulp/lang/RArithmeticOperator.h"
#include "rulp/lang/RRelationalOperator.h"
#include "rulp/object/IRObject.h"
namespace lfc {

class RulpMathUtil {
public:

  static RTypeIndex getTypeConvert(RTypeIndex a, RTypeIndex b);
  
  static IRObject* computeArithmeticExpression(RArithmeticOperator op, IRObject* a, IRObject* b);

  static boolean computeRelationalExpression(RRelationalOperator op, IRObject* a, IRObject* b);

};

} // namespace lfc
TRACE_SUB_MODULE_DEF(math_util)
#endif //__RULP_LANG_RULPMATHUTIL_H__