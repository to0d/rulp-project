// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[cfg_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(cfg_util)()
#define LFC_TRACE_STREAM llvm::errs()
#include "lfc/base/abi.h"
#include "lfc/llvm/cfg.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include "lfc/base/graph/graph_visit.h"
#include "lfc/base/container.h"
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include <iostream>

using namespace llvm;

namespace lfc {



class CFGSimplifier{
public:

  CFGSimplifier(CFGUtil* CFG_UTIL, std::vector<CFGNode*> new_nodes, std::set<CFGNode*> keep_nodes){
    this->CFG_UTIL = CFG_UTIL;
    this->new_nodes = new_nodes;
    this->keep_nodes = keep_nodes;
  };

  CFGGraph* update(){
    LFC_TRACE1("simplify graph: old=");
    if(LFC_TRACE_ENABLE){
      for(auto node : new_nodes){
        LFC_TRACE_STREAM << lfc::to_string(node) << "\n";
      }
    }

    while(new_nodes.size() > 1){
      if( _simplify_middle_node() 
      || _break_self_loop_node()
      // || _remove_head_node()
      || _remove_multi_branch_node()
      ){
        continue;
      }
      break;
    }

    LFC_TRACE1("simplify graph: new=");
    if(LFC_TRACE_ENABLE){
      for(auto node : new_nodes){
        LFC_TRACE_STREAM << lfc::to_string(node) << "\n";
      }
    }

    return CFG_UTIL->create_cfg_sub_graph(new_nodes);
  }

private:
  bool _is_keep_node(CFGNode* node) { return keep_nodes.count(node) != 0; };
  bool _simplify_middle_node();
  bool _break_self_loop_node();
  bool _remove_head_node();
  bool _remove_multi_branch_node();

private:
  std::set<CFGNode*> keep_nodes;
  std::vector<CFGNode*> new_nodes;
  CFGUtil* CFG_UTIL;
};

static CFGNode* _get_only_jump_from_node(CFGNode* node){
  if(node->jump_from_nodes.size() != 1)
    return NULL;
  return node->jump_from_nodes[0];
}

static CFGNode* _get_only_jump_to_node(CFGNode* node){
  assert(node);
  return node->jump_to_nodes.size() == 1 ? node->jump_to_nodes[0] : NULL;
}

static void _replace_jump_from_node(CFGNode* node, CFGNode* old_node, CFGNode* new_node){

  int update = 0;  
  for(int i = 0; i < node->jump_from_nodes.size(); ++i){
    if(node->jump_from_nodes[i] == old_node){
      node->jump_from_nodes[i] = new_node;
      ++update;
    }
  }

  assert(update > 0 && "old from node not found");
}

static void _replace_jump_to_node(CFGNode* node, CFGNode* old_node, CFGNode* new_node){

  int update = 0;

  for(int i = 0; i < node->jump_to_nodes.size(); ++i){
    if(node->jump_to_nodes[i] == old_node){
      node->jump_to_nodes[i] = new_node;
      ++update;
    }
  }

  assert(update > 0 && "old to node not found");
}

bool CFGSimplifier::_remove_head_node(){
  int update_count = 0;
  auto it = new_nodes.begin();
  while(it != new_nodes.end()){
    CFGNode* node = *it;
    bool update = false;
    if(node->jump_from_nodes.size() == 0){
      CFGNode* jump_to_node = _get_only_jump_to_node(node);
      if(jump_to_node != NULL){
        // std::cout << "node: " << lfc::to_string(node) << "\n";
        // std::cout << "jump_to_node: " << lfc::to_string(jump_to_node) << "\n";
        int pos = erase_first_of(jump_to_node->jump_from_nodes, node);
        assert(pos >= 0);
        update = true;
        //  std::cout << "update: " << lfc::to_string(jump_to_node) << "\n";
      }
    }

    if(update){
      it = new_nodes.erase(it);
      ++update_count;
    }
    else{
      it++;
    }
  }
  return update_count > 0;
}

static bool _remove_child(CFGNode* node, CFGNode* child){
  assert(child);

  int size = node->jump_to_nodes.size();
  for(int i = 0; i < size; ++i){
    if(node->jump_to_nodes[i] == child){
      node->jump_to_nodes.erase(node->jump_to_nodes.begin()+i);
      int pos = erase_first_of(child->jump_from_nodes, node);
      assert(pos >= 0);
      return true;
    }
  }

  return false;
}

bool CFGSimplifier::_remove_multi_branch_node(){

  int update_count = 0;
  for(auto node : new_nodes){

    int size = node->jump_to_nodes.size();
    if(size == 0)
      continue;

    std::set<CFGNode*> node_set;
    bool removed = false;

    auto it = node->jump_to_nodes.begin();
    while(it != node->jump_to_nodes.end()){
      auto* child = *it;
      assert(child);
      if(node_set.count(child) != 0){
        int pos = erase_first_of(child->jump_from_nodes, node);
        assert(pos >= 0);
        it = node->jump_to_nodes.erase(it);
        removed = true;
      }
      else{
        node_set.insert(child);
        ++it;
      }
    }

    if(removed){
      if(node->type == CFGType::BLOCK2){
        node->type = CFGType::BLOCK1;
      }
      ++update_count;
    }
  }

  return update_count > 0;
}


bool CFGSimplifier::_break_self_loop_node(){

  int update_count = 0;
  for(CFGNode* node : new_nodes){

    auto it = node->jump_to_nodes.begin();
    while(it != node->jump_to_nodes.end()){
      auto* child = *it;
      assert(child);
      if(child == node){
        int pos = erase_first_of(node->jump_from_nodes, node);
        assert(pos >= 0);
        it = node->jump_to_nodes.erase(it);
        ++update_count;
      }
      else{
        ++it;
      }
    }

  }
  return update_count > 0;
}

bool CFGSimplifier::_simplify_middle_node(){

  // std::cout << "_simplify_middle_node: \n";
  int update_count = 0;
 
  auto it = new_nodes.begin();
  while(it != new_nodes.end()){
    CFGNode* node = *it;
    bool update = false;
    if(!_is_keep_node(node)){
      // std::cout << "node: " << lfc::to_string(node) << "\n";

      CFGNode* jump_from_node = _get_only_jump_from_node(node);
      CFGNode* jump_to_node   = _get_only_jump_to_node(node);
      if(jump_from_node != NULL && jump_to_node != NULL){        
        _replace_jump_from_node(jump_to_node, node, jump_from_node);
        _replace_jump_to_node(jump_from_node, node, jump_to_node);
        update = true;
      }
    }

    if(update){
      it = new_nodes.erase(it);
      ++update_count;
    }
    else{
      it++;
    }
  }

  return update_count > 0;
}



static int _remove_dead_nodes(std::vector<CFGNode*>& nodes, CFGNode* begin_node){
  LFC_TRACE2("_remove_dead_nodes: begin=", lfc::to_string(begin_node));
  assert(begin_node);

  int update_count = 0;

  std::map<BasicBlock*, CFGNode*> node_block_map;
  for(auto node : nodes){
    node_block_map[node->block] = node;
  }

  std::queue<CFGNode*> checking_queue;

  for(auto node : nodes){
    if(node->type == CFGType::BLOCK2 && node->block_end_inst){
      LFC_TRACE2("check node: ", lfc::to_string(node));
      
      if(auto ignore_block = get_ignored_block(dyn_cast<BranchInst>(node->block_end_inst))){
        CFGNode* dst_node = node_block_map[ignore_block];
        std::string dst_node_idx = dst_node == NULL ? "null" : lfc::to_string(dst_node->index); 
        LFC_TRACE6("ignore: src=", node->index, ", dst_block=", get_llvm_block_name(ignore_block), ", dst_node=", dst_node_idx);
        if(dst_node != NULL){         
          bool rc = _remove_child(node, dst_node);
          assert(rc);
          node->type = CFGType::BLOCK1;
          ++update_count;
          checking_queue.push(dst_node);
        }
      }
    }
  }

  // errs() << "checking_queue: size=" << checking_queue.size() << "\n";

  while(!checking_queue.empty()){
    CFGNode* node = checking_queue.front(); 
    checking_queue.pop();
    if(node == NULL || node == begin_node)
      continue;

    LFC_TRACE2("check node: ", lfc::to_string(node));
     
    if(node->jump_from_nodes.empty()){

      auto child_nodes = node->jump_to_nodes;
      for(auto* child : child_nodes){
        checking_queue.push(child);
        bool rc = _remove_child(node, child);
        assert(rc);
      }      
    }
  }

  // errs() << "remove dead nodes: \n";

  if(update_count > 0){
    auto it = nodes.begin();
    while(it != nodes.end()){
      CFGNode* node = *it;
      if(node != begin_node && node->jump_from_nodes.empty()){
        LFC_TRACE2("remove dead node:", lfc::to_string(node));
        it = nodes.erase(it);
        ++update_count;
      }
      else{
        it++;
      }
    }
  }

  return update_count;
}


CFGGraph* simplify_cfg_graph(CFGGraph* graph, function<bool(CFGNode*)> func, bool remove_dead_block){
  LFC_TRACE1("simplify_cfg_graph:");
  
  CFGUtil* CFG_UTIL = graph->get_cfg_util();

  auto new_nodes = CFG_UTIL->clone_cfg_nodes(graph->get_all_nodes());
  LFC_TRACE_LIST("new_nodes", new_nodes);

  if(remove_dead_block && new_nodes.size() >= 2){
    CFGNode* begin_node = NULL;
    for(auto node : new_nodes){
      if(node->block == graph->get_begin_node()->block){
        begin_node = node;
        break;
      }
    }

    _remove_dead_nodes(new_nodes, begin_node);
  }

  std::set<CFGNode*> keep_nodes;
  if( func != NULL ){
    for(auto node : new_nodes){
      if(func(node)){
        keep_nodes.insert(node);
      }      
    }
  }
  else{
    keep_nodes = to_set(new_nodes);
  }

  return CFGSimplifier(CFG_UTIL, new_nodes, keep_nodes).update();
}



}// namespace lfc 