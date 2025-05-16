// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[dot_dfg]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(dot_dfg)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(dot_dfg)
#include "lfc/llvm/dot_dfg.h"
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

#define DOT_NODE_NAME_START "start"
#define DOT_NODE_NAME_END   "end"
#define is_nolink_node(n)  ((n)->has_no_depend_on_node() && (n)->has_no_depend_by_node())

namespace lfc {

class DFGDotUtil{
public:
  std::string get_node_label(DFGNode* node);
  std::string get_dot_node_name(DFGNode* node);

  void clear(){
    m_node_dot_name_map.clear();
  }

private:
  std::map<DFGNode*, std::string> m_node_dot_name_map;
};

std::string DFGDotUtil::get_node_label(DFGNode* node){
  switch (node->get_type()){
  case DFGType::ARG    : return node->get_var_name() +": arg";
  case DFGType::ALLOCA : return node->get_var_name() + ": " + node->get_inst_name();
  case DFGType::STORE  : return "store(" + node->get_operand(0)
                           +"," + node->get_operand(1) +")";
  
  case DFGType::CALL   :  {
    std::string line = "call " + node->get_call_name() + "(";

    unsigned int num_operands = node->get_operand_count() - 1;
    for(unsigned int r = 0; r < num_operands; r++){
      if(r != 0)
        line += ",";
      line += node->get_operand(r);
    }
    line += ")";

    if(node->get_var_name() != ""){
      line = node->get_var_name() + ": " + line;
    }
    return line;
  }  

  case DFGType::LOAD: 
  case DFGType::CAST:
  case DFGType::MOP:
  case DFGType::RET:
    {
      std::string line = node->get_inst_name() + "(";
      unsigned int num_operands = node->get_operand_count();
      for(unsigned int r = 0; r < num_operands; r++){
        if(r != 0)
          line += ",";
        line += node->get_operand(r);
      }
      line += ")";

      if(node->get_var_name() != ""){
        line = node->get_var_name() + ": " + line;
      }

      return line;
    }

  // case OTHER  : 
  default: break;
  }

  return get_llvm_inst_string(node->get_inst());
}

std::string DFGDotUtil::get_dot_node_name(DFGNode* node){
  if(auto it = m_node_dot_name_map.find(node); it != m_node_dot_name_map.end() )
    return it->second;

  char tmp[20] = {0};
  sprintf(tmp, "node_%04d", node->get_index());
  std::string node_name = std::string(tmp);
  m_node_dot_name_map[node] = node_name;
  return node_name;
}


static void _add_dfg_end_node(DotUtil* DOT_Util, std::string name){
  DotNode* node = DOT_Util->add_node(name, name);
  DOT_Util->set_node_attribute(node, DotAttr::ELLIPSE);
  DOT_Util->set_node_attribute(node, DotAttr::RED);
}

void build_dfg_dot_graph(const std::vector<DFGNode*>& nodes, DotUtil* DOT_Util){
  
  DFGDotUtil DDU;

  _add_dfg_end_node(DOT_Util, DOT_NODE_NAME_START);
  _add_dfg_end_node(DOT_Util, DOT_NODE_NAME_END);

  std::set<DFGNode*> node_set;
  std::for_each(nodes.begin(), nodes.end(), [&node_set](auto it){node_set.insert(it);});

  std::vector<DFGNode*> call_nodes;
  std::vector<DFGNode*> arg_nodes;
  std::vector<DFGNode*> ret_nodes;

  // add nodes
  LFC_TRACE2("add all nodes: count=" , nodes.size());
  for(DFGNode* node : nodes){
    if(is_nolink_node(node) && node->get_type() != DFGType::CALL){
      LFC_TRACE2("ignore no-link node: ", lfc::to_string(node));
      continue;
    }

    std::string node_name   = DDU.get_dot_node_name(node);
    std::string node_label  = DDU.get_node_label(node);
    DotAttr     node_color  = DotAttr::NIL;
    DotAttr     node_shape  = DotAttr::RECORD;

    switch (node->get_type()){
    case DFGType::CALL:
      call_nodes.push_back(node);
      node_shape = DotAttr::RECORD;
      node_color = DotAttr::RED;
      break;
    
    case DFGType::ARG:       
      arg_nodes.push_back(node);
      node_shape = DotAttr::ELLIPSE;
      break;
    
    case DFGType::RET:
      ret_nodes.push_back(node);
      node_shape = DotAttr::ELLIPSE;
      break;
    default:
      break;
    }

    DotNode* dot_node = DOT_Util->add_node(node_name, node_label);
    DOT_Util->set_node_attribute(dot_node, node_color);
    DOT_Util->set_node_attribute(dot_node, node_shape);
  }

  // output edges
  LFC_TRACE1("add edges:");
  for(DFGNode* node  : nodes){
    auto this_name = DDU.get_dot_node_name(node);
    for(DFGNode* dep_node :  node->get_depend_on_nodes()){
      if(node_set.count(dep_node) == 0)
        continue;
      auto dep_name = DDU.get_dot_node_name(dep_node);
      DotEdge* dot_edge = DOT_Util->add_edge(dep_name, this_name);    
    }
  }

  // output CFG: args->start edges
  LFC_TRACE2("add args edges: count=" , arg_nodes.size());
  {
    std::string this_name = DOT_NODE_NAME_START; 
    for(DFGNode* arg_node : arg_nodes){
      auto arg_name = DDU.get_dot_node_name(arg_node);
      DotEdge* dot_edge = DOT_Util->add_edge(this_name, arg_name);
      DOT_Util->set_edge_attribute(dot_edge, DotAttr::RED);
      DOT_Util->set_edge_weight(dot_edge, DOT_EDGE_WEIGHT_HIGH);
    }
  }

  // output CFG: call node edges 
  LFC_TRACE2("add call edges: count=" , call_nodes.size());
  {
    std::string last_name = DOT_NODE_NAME_START; 
    for(DFGNode* call_node : call_nodes){
      auto call_name = DDU.get_dot_node_name(call_node);
      DotEdge* dot_edge = DOT_Util->add_edge(last_name, call_name);
      DOT_Util->set_edge_attribute(dot_edge, DotAttr::RED);
      DOT_Util->set_edge_weight(dot_edge, DOT_EDGE_WEIGHT_HIGH);
      last_name = call_name;
    }
    DotEdge* dot_edge = DOT_Util->add_edge(last_name, DOT_NODE_NAME_END);
    DOT_Util->set_edge_attribute(dot_edge, DotAttr::RED);
    DOT_Util->set_edge_weight(dot_edge, DOT_EDGE_WEIGHT_HIGH);
  }

  // output CFG: ret->end edges
  LFC_TRACE2("add rets edges: count=" , ret_nodes.size());
  {
    for(DFGNode* ret_node : ret_nodes){
      DotEdge* dot_edge = DOT_Util->add_edge(DDU.get_dot_node_name(ret_node), DOT_NODE_NAME_END);
      DOT_Util->set_edge_attribute(dot_edge, DotAttr::RED);
      DOT_Util->set_edge_weight(dot_edge, DOT_EDGE_WEIGHT_HIGH);
    }
  }

}


} // namespace lfc 