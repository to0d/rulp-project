// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_DOT_DFG_UTIL_H__
#define __LFC_DOT_DFG_UTIL_H__

#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "lfc/llvm/dfg.h"
#include "lfc/base/dot.h"

namespace lfc {

void build_dfg_dot_graph(const std::vector<DFGNode*>& nodes, DotUtil* DOT_Util);

}// namespace lfc

TRACE_SUB_MODULE_DEF(dot_dfg)

#endif // __LFC_DOT_DFG_UTIL_H__

