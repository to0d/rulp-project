// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[lva]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(lva)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(lva)
#include "lfc/llvm/lva.h"
#include "lfc/base/graph/graph_visit.h"
#include "lfc/base/trace.h"
#include "lfc/base/container.h"
#include "lfc/base/collection.h"
#include "lfc/base/to_string.h"
#include "lfc/base/equal.h"
#include "llvm/IR/Instructions.h"
#include <assert.h>

using namespace llvm;
using namespace lfc;

namespace lfc {

void live_variables_analysis (
    const std::vector<std::vector<std::string>>& input_def_vars
  , const std::vector<std::vector<std::string>>& input_use_vars
  , const std::vector<std::vector<int>>& input_graph
  , int node_count
  , int in_node_idx
  , int out_node_idx
  , std::vector<std::vector<std::string>>& in_vars
  , std::vector<std::vector<std::string>>& out_vars
  )
{
  LFC_TRACE1("live_variables_analysis: ");
  LFC_TRACE2("  def_vars: ", lfc::to_string(input_def_vars));
  LFC_TRACE2("  use_vars: ", lfc::to_string(input_use_vars));
  LFC_TRACE2("  graph   : ", lfc::to_string(input_graph));
  LFC_TRACE2("  count   : ", lfc::to_string(node_count));
  LFC_TRACE2("  in_idx  : ", lfc::to_string(in_node_idx));
  LFC_TRACE2("  out_idx : ", lfc::to_string(out_node_idx));    
  
  assert(input_def_vars.size() <= node_count);
  assert(input_use_vars.size() <= node_count);
  assert(input_graph.size() <= node_count);

  auto def_vars = resize_to(input_def_vars, node_count);
  auto use_vars = resize_to(input_use_vars, node_count);
  auto graph    = resize_to(input_graph, node_count);

  std::vector<int> visit_orders = [&]()-> std::vector<int>{
    
    std::vector<int> input = {in_node_idx};
    std::vector<int> output;

    int count = visit_graph_dfs(input
      , [&](int n){
        output.push_back(n);
        return false;
      }
      , [=](int n){
        return graph[n];
      }
      ,
      true
    );

    assert(count == node_count && "dead block found");

    return output;
  }();

  std::reverse(visit_orders.begin(), visit_orders.end());
  LFC_TRACE2("orders: ", lfc::to_string(visit_orders));

  std::vector<std::set<std::string>> in_var_sets(node_count);
  std::vector<std::set<std::string>> out_var_sets(node_count);  
  int in_update = 1;

  while(in_update > 0){
    in_update = 0;
    for(int idx : visit_orders){

      LFC_TRACE2("  update: index=", lfc::to_string(idx));

      auto& nxts = graph[idx];
      LFC_TRACE2("    nxts=", lfc::to_string(nxts));

      std::set<std::string> outs;
      
      for(int next : nxts){
        add_all(outs, in_var_sets[next]);
      }

      auto& olds = out_var_sets[idx];
      LFC_TRACE2("    olds=", lfc::to_string(olds));

      if(!lfc::equal(outs, olds)){
        out_var_sets[idx] = outs;
        LFC_TRACE2("    upds=", lfc::to_string(in_update));
        ++in_update;
      }

      LFC_TRACE2("    outs=", lfc::to_string(outs));

      auto& defs = def_vars[idx];
      auto& uses = use_vars[idx];

      LFC_TRACE2("    defs=", lfc::to_string(defs));
      LFC_TRACE2("    uses=", lfc::to_string(uses));

      // IN(B) = Use[B] U (OUT[B] - def[B])  

      std::set<std::string> ins, tmp; 
      complement_of(outs.begin(), outs.end(), defs.begin(), defs.end(), std::inserter(tmp, tmp.begin()));
      union_of(tmp.begin(), tmp.end(), uses.begin(), uses.end(), std::inserter(ins, ins.begin()));

      LFC_TRACE2("    ins =", lfc::to_string(ins));

      in_var_sets[idx] = ins;
      out_var_sets[idx] = outs;     
    }
  
  }

  in_vars.clear();
  out_vars.clear();
  
  for(int i = 0 ; i < node_count; ++i){
    auto ins  = to_vector(in_var_sets[i]);
    std::sort(ins.begin(), ins.end());
    in_vars.push_back(ins);

    auto outs = to_vector(out_var_sets[i]);
    std::sort(outs.begin(), outs.end());
    out_vars.push_back(outs);
  }
}

} // namespace lfc