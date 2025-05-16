// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[llvm_loop]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(llvm_loop)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(llvm_loop)
#include "lfc/llvm/llvm_loop.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/graph/graph_visit.h"
#include "lfc/base/trace.h"
#include "lfc/base/container.h"
#include "lfc/base/collection.h"
#include "lfc/base/to_string.h"
#include "lfc/base/equal.h"
#include "llvm/IR/Instructions.h"
#include <assert.h>
namespace lfc {

using namespace llvm;
using namespace lfc;



struct LoopUnrollBuilder{

  LoopUnrollBuilder(Function* F, CFGGraph* graph)
    : F(F)
    , graph(graph)
  {}

  bool try_unroll_loop();
  bool unroll_loop_style_1(CFGNode* node);

  CFGGraph* graph;
  Function* F;
  
  std::map<CFGNode*, int> index_map;
  simple_graph SG;
};

bool LoopUnrollBuilder::try_unroll_loop(){
  LFC_TRACE4("try_unroll_loop: F", get_llvm_func_name(F), ", CFG=", lfc::to_string(graph));
  
  SG = make_link_simple_graph(graph, &index_map);
  LFC_TRACE2("SG: ", lfc::to_string(SG));

  if(graph->get_end_nodes().empty()){
    LFC_TRACE1("no end node found");
    return false;
  }

  for(auto N : graph->get_all_nodes()){
    switch (N->type){
    case CFGType::BLOCK2:
      if(unroll_loop_style_1(N)){
        return true;
      }

      break;
    
    default:
      break;
    }  
 
  }

  return false;
}


bool LoopUnrollBuilder::unroll_loop_style_1(CFGNode* node){
  LFC_TRACE2("unroll_loop_style_1: ", lfc::to_string(node));
 
  /******************************************/
  // check loop path
  /******************************************/
  int N_index = index_map[node];
  auto loop_paths = getAllPathsSourceTarget(SG, N_index, N_index);
  LFC_TRACE2("check loop_paths=", lfc::to_string(loop_paths));

  if(loop_paths.size() != 1 || loop_paths[0].size() <= 2){
    LFC_TRACE1("loop path not match");
    return false;
  }
  
  auto loop_path = loop_paths[0];
  assert(loop_path[0] == N_index);
  assert(loop_path[loop_path.size() - 1] == N_index);

  /******************************************/
  // check path to end
  /******************************************/
  bool has_path_to_end = false;

  for(auto E_N : graph->get_end_nodes()){
    auto end_paths = getAllPathsSourceTarget(SG, N_index, N_index);
    LFC_TRACE4("check end-path: end=", lfc::to_string(E_N), ", loop_paths=", lfc::to_string(end_paths));
  
    if(!end_paths.empty()){
      has_path_to_end = true;
      break;
    }
  }

  if(!has_path_to_end){
    LFC_TRACE1("no path to end found");
    return false;
  }

  /******************************************/
  // check loop condition
  /******************************************/
  BranchInst* BI = NULL;
  
  for(auto& I : *(node->block)){
    if(BranchInst* brInst = dyn_cast<BranchInst>(&I); brInst){
      assert(brInst->isConditional());
      BI = brInst;
      break;
    }
  }

  if(!has_path_to_end){
    LFC_TRACE1("no path to end found");
    return false;
  }

  Instruction* condInst = dyn_cast<Instruction>(BI->getCondition());
  assert(condInst);

  if(ICmpInst* CI = dyn_cast<ICmpInst>(condInst); CI){

    Value* v0 = CI->getOperand(0);
    Value* v1 = CI->getOperand(1);
  
  }

  return false;
}


bool llvm_unroll_loop_in_cfg_graph(Function* F, CFGGraph* graph){
  LFC_TRACE4("llvm_unroll_loop_in_cfg_graph: F", get_llvm_func_name(F), ", CFG=", lfc::to_string(graph));
  return LoopUnrollBuilder(F, graph).try_unroll_loop();
}




} // namespace lfc