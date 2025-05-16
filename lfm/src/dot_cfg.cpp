// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[dot_cfg]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(dot_cfg)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(dot_cfg)
#include "lfc/base/abi.h"
#include "lfc/llvm/dot_cfg.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/trace.h"
#include <map>
#include <set>
#include <vector>
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;
using namespace lfc;

#define DOT_SUCCESSOR_TRUE        "s0"
#define DOT_SUCCESSOR_FALSE       "s1"
#define DOT_SUCCESSOR_DEF         "def"
#define DOT_NODE_LABEL_TRUE       "T"
#define DOT_NODE_LABEL_FALSE      "F"
#define DOT_NODE_LABEL_DEF        "DEF"
#define DOT_NEW_LINE              "\\l "

static std::string get_switch_branch_name(int bidx){
  return "s" + std::to_string(bidx);
}

static std::string get_successor_label(std::vector<std::string> names, std::vector<std::string> values){
  std::string out = "|{";
  int size = names.size();
  for(int i = 0; i < size; ++i){
    if( i!=0 )
      out += "|";
    out += "<";
    out += names[i];
    out += ">";
    out += values[i];
  }
  out += "}";
  return out;
}

namespace lfc {

class CFGDotUtil{
public:
  std::string get_node_label(CFGNode* node, bool only_show_cfg);
  std::string get_dot_node_name(CFGNode* node);

  void clear(){
    m_node_dot_name_map.clear();
  }

public:
  std::map<CFGNode*, std::string> m_node_dot_name_map;
  function<bool(llvm::Instruction*)> imp_func;
};

static bool is_important_inst(Instruction* I){
  assert(I);
  switch (I->getOpcode()){
  case Instruction::Br    : return true;
  default: break;
  }
  return false;
}

static std::string _format_inst(Instruction* I){
  std::string line;
  if(I->getOpcode() == Instruction::Call){
    CallInst* CI = dyn_cast<CallInst>(I);
    assert(CI);
    std::string callName = get_llvm_call_name(CI);
    line = "call " + demangle_func_name(callName);
    if(!CI->getType()->isVoidTy()){
      line = get_llvm_value_name(I) + " = " + line;
    }
  }
  else {
    line = get_llvm_inst_string(I);
  }

  return dot_format_label(line, DotAttr::LEFT);
}

std::string CFGDotUtil::get_node_label(CFGNode* node, bool only_show_cfg){
  
  std::vector<std::string> lines;
  lines.push_back(dot_format_label(get_llvm_block_name(node->block) + ":", DotAttr::LEFT));

  if(only_show_cfg){

    if(imp_func != NULL){
      for(Instruction& I : *node->block){
        if(imp_func(&I)){
          lines.push_back(" "+_format_inst(&I));
        }
      }
    }

  }
  else{
    int inst_index = 0;
    bool print_all = node->block->size() <= 6;
    for(Instruction& I : *node->block){
      if( print_all 
      || inst_index < 3 
      || (inst_index+3) > node->block->size() 
      || is_important_inst(&I)
      || (imp_func != NULL && imp_func(&I))){
        lines.push_back(" "+_format_inst(&I));
      }
      if(!print_all && inst_index == 3){
        lines.push_back(dot_format_label(" ...", DotAttr::LEFT));
      }
      inst_index++;
    }
  }

  if(node->type == CFGType::BLOCK2){
    lines.push_back(get_successor_label(
        {DOT_SUCCESSOR_TRUE, DOT_SUCCESSOR_FALSE}
      , {DOT_NODE_LABEL_TRUE, DOT_NODE_LABEL_FALSE}));
  }
  else if(node->type == CFGType::BLOCK3){
    std::vector<std::string> names, values;

    int size = node->jump_to_nodes.size();
    for(int i = 0; i < size-1; ++i){
      names.push_back(get_switch_branch_name(i));
      values.push_back(std::to_string(node->switch_values[i]));
    }

    names.push_back(DOT_SUCCESSOR_DEF);
    values.push_back(DOT_NODE_LABEL_DEF);

    lines.push_back(get_successor_label(names, values));
  }

  return dot_format_label(lines);
}

static std::string _get_dot_node_name(CFGNode* node){
  char tmp[20] = {0};
  sprintf(tmp, "node_%04d", node->index);
  std::string node_name = std::string(tmp);
  return node_name;
}

std::string CFGDotUtil::get_dot_node_name(CFGNode* node){
  if(auto it = m_node_dot_name_map.find(node); it != m_node_dot_name_map.end() )
    return it->second;

  std::string node_name = _get_dot_node_name(node);
  m_node_dot_name_map[node] = node_name;
  return node_name;
}

static bool is_important_block(CFGNode* node, function<bool(llvm::Instruction*)> imp_func){
  for(Instruction& I : *node->block){
    if(imp_func(&I))
      return true;
  }
  return false;
}

#define DOT_NODE_NAME_START "start"
#define DOT_NODE_NAME_END   "end"

static DotNode* _add_cfg_end_node(DotUtil* DOT_Util, std::string name){
  DotNode* node = DOT_Util->add_node(name, name);
  DOT_Util->set_node_attribute(node, DotAttr::ELLIPSE);
  DOT_Util->set_node_attribute(node, DotAttr::RED);
  return node;
}


void build_cfg_dot_graph(CFGGraph* graph, DotUtil* DOT_Util, function<bool(llvm::Instruction*)> func, bool only_show_cfg){
  build_cfg_dot_graph(graph->get_all_nodes(), DOT_Util, func, only_show_cfg);

  if(graph->get_begin_node() != NULL){
    _add_cfg_end_node(DOT_Util, DOT_NODE_NAME_START);
    std::string node_name = _get_dot_node_name(graph->get_begin_node());
    DOT_Util->add_edge(node_name, DOT_NODE_NAME_START);
  }

  for(auto end_node : graph->get_end_nodes()){
    _add_cfg_end_node(DOT_Util, DOT_NODE_NAME_END);
    std::string node_name = _get_dot_node_name(end_node);
    DOT_Util->add_edge(DOT_NODE_NAME_END, node_name);
  }

}


void build_cfg_dot_graph(const std::vector<CFGNode*>& nodes, DotUtil* DOT_Util, function<bool(llvm::Instruction*)> func, bool only_show_cfg){
  
  CFGDotUtil CDU;

  CDU.imp_func = func;

  // add nodes
  LFC_TRACE2("add all nodes: count=" , nodes.size());
  for(CFGNode* node : nodes){
    std::string node_name   = CDU.get_dot_node_name(node);
    std::string node_label  = CDU.get_node_label(node, only_show_cfg);
    DotAttr     node_color  = DotAttr::NIL;
    DotAttr     node_shape  = DotAttr::RECORD;

    switch (node->type){    
    case CFGType::BLOCK0:
    case CFGType::BLOCK1:
    case CFGType::BLOCK2:
      node_shape = DotAttr::RECORD;
      break;

    default:
      break;
    }

    DotNode* dot_node = DOT_Util->add_node(node_name, node_label);
    DOT_Util->set_node_attribute(dot_node, node_color);
    DOT_Util->set_node_attribute(dot_node, node_shape);
  
    if(func != NULL && is_important_block(node, func)){
      DOT_Util->set_node_attribute(dot_node, DotAttr::FILL_COLOR_1);
    }
  } 

  // output edges
  LFC_TRACE1("add edges:");
  for(CFGNode* node : nodes){
    auto this_name = CDU.get_dot_node_name(node);
 
    switch (node->type){    
    case CFGType::BLOCK1:
      {
        auto jump_name = CDU.get_dot_node_name(get_cfg_child_at(node, 0));
        DotEdge* dot_edge = DOT_Util->add_edge(jump_name, this_name);  
      }

      break;
    case CFGType::BLOCK2:
      {
        auto jump_true_name = CDU.get_dot_node_name(get_cfg_child_at(node, 0));
        DOT_Util->add_edge(jump_true_name, this_name + ":" + DOT_SUCCESSOR_TRUE);  
      
        auto jump_false_name = CDU.get_dot_node_name(get_cfg_child_at(node, 1));
        DOT_Util->add_edge(jump_false_name, this_name + ":" + DOT_SUCCESSOR_FALSE);  
        
      }
      break;

    case CFGType::BLOCK3:
      {
        int size = node->jump_to_nodes.size();
        for(int i = 0; i < size-1; ++i){
          auto jump_true_name = CDU.get_dot_node_name(get_cfg_child_at(node, i));
          DOT_Util->add_edge(jump_true_name, this_name + ":" + get_switch_branch_name(i));
        }

        auto jump_true_name = CDU.get_dot_node_name(get_cfg_child_at(node, size-1));
        DOT_Util->add_edge(jump_true_name, this_name + ":" + DOT_SUCCESSOR_DEF);
      }
      break;

    default:
      break;
    }
  }

}




} // namespace lfc 