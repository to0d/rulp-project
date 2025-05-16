// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_LLVM_LOOP_H__
#define __LFC_LLVM_LOOP_H__


#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "lfc/base/function.h"
#include "lfc/llvm/cfg.h"
#include <vector>
#include <map>

namespace lfc {

bool llvm_unroll_loop_in_cfg_graph(llvm::Function* F, CFGGraph* graph);

} // namespace lfc
TRACE_SUB_MODULE_DEF(llvm_loop)
#endif // __LFC_LLVM_LOOP_H__