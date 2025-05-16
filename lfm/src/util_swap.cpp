// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[llvm_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(llvm_util)()
#define LFC_TRACE_STREAM llvm::errs()
#include "lfc/llvm/dfg.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/collection.h"
#include "lfc/base/string/util.h"
#include "llvm/Pass.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

#include <map>
#include <set>
#include <vector>
#include <iostream>

using namespace llvm;

namespace lfc {

bool swap_llvm_call_inst(Function* F, int a, int b){
  
  assert(F != NULL);
  assert(a >= 0 && a < b);

  DFGUtil DFG_UTIL;
  DFG_UTIL.init(F);

  auto all_nodes  = DFG_UTIL.get_all_dfg_nodes();
  auto call_nodes = DFGNode::get_dfg_nodes(all_nodes, DFGType::CALL);
  assert(b < call_nodes.size());

  DFGNode* a_node = call_nodes[a];
  DFGNode* b_node = call_nodes[b];
  if( a_node->get_block() != b_node->get_block() ){
    llvm_unreachable("unsupport multi blocks");
  }

  auto a_dpdby_nodes = DFGNode::get_all_depend_by_nodes({a_node});
  if(std::find(a_dpdby_nodes.begin(), a_dpdby_nodes.end(), b_node) != a_dpdby_nodes.end()){
    return false;
  }

  auto b_dpdon_nodes = DFGNode::get_all_depend_on_nodes({b_node});
  if(std::find(b_dpdon_nodes.begin(), b_dpdon_nodes.end(), a_node) != b_dpdon_nodes.end()){
    return false;
  }

  bool a_has_comm_mid = has_common_index ( a_dpdby_nodes.begin(), a_dpdby_nodes.end()
                                         , b_dpdon_nodes.begin(), b_dpdon_nodes.end()
                                         , [](DFGNode* node){return node->get_index();});
  assert(!a_has_comm_mid);

  for(auto dpdon : b_dpdon_nodes){
    if(dpdon->get_index() < a_node->get_index())
      continue;
    Instruction* new_inst = dpdon->get_inst()->clone(); 
    new_inst->insertBefore(a_node->get_inst());
    dpdon->get_inst()->replaceAllUsesWith(new_inst);
  }

  Instruction* new_b_inst = b_node->get_inst()->clone();
  new_b_inst->insertBefore(a_node->get_inst());
  b_node->get_inst()->replaceAllUsesWith(new_b_inst);
  
  for(auto dpdon : b_dpdon_nodes){
    if(dpdon->get_index() < a_node->get_index())
      continue;
    dpdon->get_inst()->eraseFromParent();
  }

  b_node->get_inst()->eraseFromParent();
  return true;
}

} // namespace lfc 


