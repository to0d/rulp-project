// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/task_dot.h"

namespace lfc {
 
static std::string _get_dep_dot_node_name(int index){
  return "n" + std::to_string(index);
}

void build_dep_dot_graph(const std::vector<std::vector<int>>& dep_arr,  DotUtil* DOT_Util){
 
  int size = dep_arr.size();

  // output nodes
  for(int i = 0; i < size; ++i){
    std::string node_name = _get_dep_dot_node_name(i);
    DotNode* dot_node = DOT_Util->add_node(node_name, node_name);
    DOT_Util->set_node_attribute(dot_node, DotAttr::ELLIPSE);
  }

  // output edges
  int cur_index = 0;
  for(const std::vector<int>& pre : dep_arr){
    std::string cur_name = _get_dep_dot_node_name(cur_index++);
    for(int pre_index : pre){
      std::string pre_name = _get_dep_dot_node_name(pre_index);
      DOT_Util->add_edge(pre_name, cur_name);
    }
  }

  // output CFG: call node edges 
  {
    std::string last_name = ""; 
    for(int i = 0; i < size; ++i){
      std::string call_name = _get_dep_dot_node_name(i);
      if(!last_name.empty()){
        DotEdge* dot_edge = DOT_Util->add_edge(last_name, call_name);
        DOT_Util->set_edge_attribute(dot_edge, DotAttr::RED);
        DOT_Util->set_edge_weight(dot_edge, DOT_EDGE_WEIGHT_HIGH);
      }
      last_name = call_name;
    }
  }
  
}


} // namespace lfc 


