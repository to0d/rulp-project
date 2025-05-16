// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_DOT_CFG_UTIL_H__
#define __LFC_DOT_CFG_UTIL_H__

#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "lfc/llvm/cfg.h"
#include "lfc/base/dot.h"

namespace lfc {

void build_cfg_dot_graph(const std::vector<CFGNode*>& nodes, DotUtil* DOT_Util, function<bool(llvm::Instruction*)> func = nullptr, bool only_show_cfg = false);
void build_cfg_dot_graph(CFGGraph* graph, DotUtil* DOT_Util, function<bool(llvm::Instruction*)> func = nullptr, bool only_show_cfg = false);

}// namespace lfc

TRACE_SUB_MODULE_DEF(dot_cfg)

#endif // __LFC_DOT_CFG_UTIL_H__

