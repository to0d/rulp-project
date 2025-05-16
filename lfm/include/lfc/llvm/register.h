// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_LLVM_REGISTER_H__
#define __LFC_LLVM_REGISTER_H__


#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "lfc/base/function.h"
#include "lfc/base/graph/graph_simple.h"
#include "lfc/llvm/cfg.h"
#include <vector>
#include <map>
namespace lfc {

typedef function<std::vector<std::string>(llvm::Instruction*)> check_var_func_t;

bool register_allocation_cfg(CFGGraph* graph, check_var_func_t func, int max_register_count, std::vector<std::vector<std::string>>& register_vec);

bool register_allocation_by_fill_graph_coloring(
    const std::vector<std::vector<std::string>>& def_vars
  , const std::vector<std::vector<std::string>>& use_vars
  , const std::vector<std::vector<int>>& graph
  , int pp_count  // program point count 
  , int in_idx
  , int out_idx
  , int max_register_count
  , std::vector<std::vector<std::string>>& register_vec
  );

simple_graph make_register_interference_graph(const std::vector<std::vector<std::string>>& in_vars, std::vector<std::string>& all_vars);

} // namespace lfc
TRACE_SUB_MODULE_DEF(register)

#endif // __LFC_LLVM_REGISTER_H__