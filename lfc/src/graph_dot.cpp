#include "lfc/base/graph/graph_dot.h"
#include "lfc/base/to_string.h"
#include "lfc/base/container.h"
#include <assert.h>

namespace lfc {

static std::string _get_sg_node_name(int idx){
  return "N"+lfc::to_string(idx);
}

static std::string _get_sg_node_label(int idx, const std::vector<std::string>& names){
  if(!names.empty())
    return names[idx];

  return lfc::to_string(idx);
}

void build_simple_graph_dot_graph(const simple_graph& graph, DotUtil* DOT_Util, bool is_directed, const std::vector<std::string>& names){

  int size = graph.size();
  assert(names.empty() || names.size() == size);

  std::vector<std::set<int>> SSG = make_simple_set_graph(graph, is_directed);

  for(int i = 0; i < size; ++i){
    DotNode* node = DOT_Util->add_node(_get_sg_node_name(i), _get_sg_node_label(i, names));
    DOT_Util->set_node_attribute(node, DotAttr::ELLIPSE);
  }

  for(int i = 0; i < size; ++i){
    for(int j : to_vector(SSG[i])){
      if(!is_directed && i > j)
        continue;

      DotEdge* edge = DOT_Util->add_edge(_get_sg_node_name(j), _get_sg_node_name(i));
      if(!is_directed){
        DOT_Util->set_edge_attribute(edge, DotAttr::NONE);
      }
    }  
  }

}

} // namespace lfc