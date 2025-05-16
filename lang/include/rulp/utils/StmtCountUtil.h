// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_UTILS_STMTCOUNT_UTIL_H__
#define __RULP_UTILS_STMTCOUNT_UTIL_H__

#include "rulp/runtime/IRFrame.h"
#include "rulp/runtime/IRInterpreter.h"
namespace lfc {

class StmtCountUtil {
public:

  static int getStmtCount(IRObject* obj, IRInterpreter* interpreter, IRFrame* frame);

}; 

} // namespace lfc
#endif //__RULP_UTILS_STMTCOUNT_UTIL_H__