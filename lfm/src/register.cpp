// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[register]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(register)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(register)
#include "lfc/llvm/register.h"
#include "lfc/llvm/lva.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include "lfc/base/container.h"
#include "lfc/base/graph/graph_simple.h"
#include "lfc/base/graph/graph_coloring.h"

namespace lfc {

simple_graph make_register_interference_graph(const std::vector<std::vector<std::string>>& in_vars, std::vector<std::string>& all_vars){
  LFC_TRACE1("make_register_interference_graph: ");
  LFC_TRACE2("in_vars : ", lfc::to_string(in_vars)); 

  all_vars = [&]()->std::vector<std::string>{
    std::set<std::string> var_set;
    for(auto vars : in_vars){
      add_all(var_set, to_set(vars));
    }

    auto v = to_vector(var_set);
    std::sort(v.begin(), v.end());

    return v;
  }();
  
  LFC_TRACE2("all_vars: ", lfc::to_string(all_vars));
  
  std::map<std::string, int> var_idx_map;
  for(auto var : all_vars){
    var_idx_map[var] = var_idx_map.size();
  }

  int size = all_vars.size();

  simple_set_graph SSG(size);

  for(auto& vars : in_vars){
    int var_size = vars.size();
    for(int i = 0; i < var_size; ++i){
      auto& a = var_idx_map[vars[i]];
      for(int j = i+1; j < var_size; ++j){
        auto& b = var_idx_map[vars[j]];
        SSG[a].insert(b);
      }
    }
  }

  return make_simple_graph_undirected(SSG);
}

bool register_allocation_cfg(CFGGraph* graph, check_var_func_t func, int max_register_count, std::vector<std::vector<std::string>>& register_vec){
  
  
  
  return true;
}



bool register_allocation_by_fill_graph_coloring(
    const std::vector<std::vector<std::string>>& def_vars
  , const std::vector<std::vector<std::string>>& use_vars
  , const std::vector<std::vector<int>>& graph
  , int pp_count  // program point count 
  , int in_idx
  , int out_idx
  , int max_register_count
  , std::vector<std::vector<std::string>>& register_vec
  )
{
  LFC_TRACE1("register_allocation_by_fill_graph_coloring: ");
  LFC_TRACE2("  def_vars: ", lfc::to_string(def_vars));
  LFC_TRACE2("  use_vars: ", lfc::to_string(use_vars));
  LFC_TRACE2("  graph   : ", lfc::to_string(graph));
  LFC_TRACE2("  count   : ", lfc::to_string(pp_count));
  LFC_TRACE2("  in_idx  : ", lfc::to_string(in_idx));
  LFC_TRACE2("  out_idx : ", lfc::to_string(out_idx)); 

  std::vector<std::vector<std::string>> in_vars, out_vars;
  live_variables_analysis(def_vars, use_vars, graph, pp_count, in_idx, out_idx, in_vars, out_vars);

  LFC_TRACE2("in_vars : ", lfc::to_string(in_vars)); 
  LFC_TRACE2("out_vars: ", lfc::to_string(out_vars));

  std::vector<std::string> all_vars;
  simple_graph RIG = make_register_interference_graph(in_vars, all_vars);

  std::vector<int> colors;
  if(!fill_graph_coloring(RIG, max_register_count, colors)){
    LFC_TRACE1("fail to fill_graph_coloring");
    return false;
  }

  LFC_TRACE2("colors : ", lfc::to_string(colors));
  int max_color = *std::max_element(colors.begin(), colors.end()) + 1;

  std::vector<std::vector<std::string>> registers(max_color);
  int idx = 0;
  for(int color : colors){
    registers[color].push_back(all_vars[idx++]);
  }

  register_vec = registers;

  return true;
}

} // namespace lfc
