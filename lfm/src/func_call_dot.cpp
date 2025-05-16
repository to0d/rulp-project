// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/llvm/func_call_dot.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/llvm/dbg.h"

using namespace llvm;

namespace lfc {

#define DOT_NODE_NAME_START "start"
#define DOT_NODE_NAME_END   "end"

std::string _get_node_label(const FuncCall* FC, bool show_param, bool show_loc, bool show_rc){

  std::string dot_line = "";
  {
    std::string line = "";
    if(show_loc){
      int loc = get_llvm_inst_dbg_loc(FC->call_inst);
      if(loc != -1){
        line += std::to_string(loc) + ": ";
      }
    }

    line += FC->func_name ;
    if(show_param){
      line += "(";
      unsigned int num_operands = FC->para_list.size();
      for(unsigned int r = 0; r < num_operands; r++){
        if(r != 0)
          line += ",";
        line += FC->para_list[r];
      }
      line += ")";
    }

    dot_line += dot_format_label(line, DotAttr::CENTER);
  }

  if (show_rc && FC->ret_var != "") {
    std::string line = "(" + FC->ret_var + ")";
    dot_line += dot_format_label(line, DotAttr::CENTER);
  }

  return dot_line;
}

static void _add_dfg_end_node(DotUtil* DOT_Util, std::string name){
  DotNode* node = DOT_Util->add_node(name, name);
  DOT_Util->set_node_attribute(node, DotAttr::ELLIPSE);
  DOT_Util->set_node_attribute(node, DotAttr::RED);
}

void build_dep_fc_dot_graph( const std::vector<std::vector<int>>& dep_arr
                           , const std::vector<FuncCall>& fc_list
                           , DotUtil* DOT_Util
                           , bool show_param 
                           , bool show_loc
                           , bool show_rc
                           ){
  int size = dep_arr.size();

  // DOT_Util->set_graph_attribute(DotAttr::LR);

  _add_dfg_end_node(DOT_Util, DOT_NODE_NAME_START);
  _add_dfg_end_node(DOT_Util, DOT_NODE_NAME_END);

  // output nodes
  for(int i = 0; i < size; ++i){
    std::string node_name = "n" + std::to_string(i);
    DotNode* dot_node = DOT_Util->add_node(node_name, _get_node_label(&(fc_list[i]), show_param, show_loc, show_rc));
    DOT_Util->set_node_attribute(dot_node, DotAttr::ELLIPSE);
  }

  // output deps edges
  int cur_index = 0;
  for(const std::vector<int>& pre : dep_arr){
    std::string cur_name = "n" + std::to_string(cur_index++);
    for(int pre_index : pre){
      std::string pre_name = "n" + std::to_string(pre_index);
      DotEdge* dot_edge = DOT_Util->add_edge(pre_name, cur_name);
      DOT_Util->set_edge_attribute(dot_edge, DotAttr::RED);
      DOT_Util->set_edge_attribute(dot_edge, DotAttr::DIR_EAST, DotAttr::FROM_NODE);
      DOT_Util->set_edge_attribute(dot_edge, DotAttr::DIR_EAST, DotAttr::TO_NODE);
    }
  }

  // output call edges 
  {
    std::string last_name = DOT_NODE_NAME_START; 

    for(int i = 0; i < size; ++i){
      std::string call_name = "n" + std::to_string(i);
      DotEdge* dot_edge = DOT_Util->add_edge(call_name, last_name);
      DOT_Util->set_edge_weight(dot_edge, DOT_EDGE_WEIGHT_HIGH);
      last_name = call_name;
    }

    DotEdge* dot_edge = DOT_Util->add_edge(DOT_NODE_NAME_END, last_name);
    DOT_Util->set_edge_weight(dot_edge, DOT_EDGE_WEIGHT_HIGH);
  }

}


} // namespace lfc 


