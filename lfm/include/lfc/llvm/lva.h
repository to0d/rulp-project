// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_LLVM_LVA_H__
#define __LFC_LLVM_LVA_H__


#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include <vector>
#include <map>

namespace lfc {


void live_variables_analysis(
    const std::vector<std::vector<std::string>>& def_vars
  , const std::vector<std::vector<std::string>>& use_vars
  , const std::vector<std::vector<int>>& graph
  , int node_count
  , int in_node_idx
  , int out_node_idx
  , std::vector<std::vector<std::string>>& in_var
  , std::vector<std::vector<std::string>>& out_var
  );



} // namespace lfc

TRACE_SUB_MODULE_DEF(lva)

#endif // __LFC_LLVM_LVA_H__