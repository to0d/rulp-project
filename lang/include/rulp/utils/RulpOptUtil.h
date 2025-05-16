// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_LANG_RULPOPTUTIL_H__
#define __RULP_LANG_RULPOPTUTIL_H__
#include "lfc/base/trace_macro.h"
#include "rulp/object/IRObject.h"
#include "rulp/object/IRExpr.h"
#include "rulp/runtime/IRIterator.h"
namespace lfc {

class RulpOptUtil {
public:
  
  static boolean isConstNumber(IRObject* obj);

  static boolean isConstNumber(IRObject* obj, double value);

  static boolean isConstValue(IRObject* obj);

  static boolean isConstValue(IRIteratorPtr it);

  static boolean isNewFrameFactor(IRObject* obj);

  static void listReturnObject(IRExpr* expr, std::vector<IRObject*>& exprList);

  static void reset();
};

} // namespace lfc
TRACE_SUB_MODULE_DEF(opt_util)
#endif //__RULP_LANG_RULPOPTUTIL_H__