// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/dot.h"
#include "lfc/base/string/util.h"
#include "lfc/base/to_string.h"
#include "lfc/base/container.h"
#include "lfc/base/trace.h"
#include <cassert>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define DOT_ALIGN_LEFT              "\\l"
#define DOT_ALIGN_RIGH              "\\r"
#define DOT_ALIGN_CENTER            "\\n"

namespace lfc {

enum class DotAttrType{
  NONE = 0, COLOR, DIR, RANDIR, RANK, SHAPE, SPLINES, STYLE, ALIGN, FILL_COLOR, CHOOSE, UNKNOWN
};

static DotAttrType type_of(DotAttr attr){
  switch (attr){
    case DotAttr::NIL               : return DotAttrType::NONE;
    case DotAttr::LINE              : return DotAttrType::SPLINES;
    case DotAttr::ELLIPSE           :
    case DotAttr::RECORD            : return DotAttrType::SHAPE;
    case DotAttr::RED               :
    case DotAttr::GREY              : 
    case DotAttr::WHITE             : return DotAttrType::COLOR;
    case DotAttr::TB                : 
    case DotAttr::BT                :
    case DotAttr::LR                : 
    case DotAttr::RL                : return DotAttrType::RANDIR;
    case DotAttr::DASHED            : return DotAttrType::STYLE;
    case DotAttr::SAME              : return DotAttrType::RANK;
    case DotAttr::NONE              : return DotAttrType::DIR;
    case DotAttr::LEFT              :
    case DotAttr::RIGHT             :
    case DotAttr::CENTER            : return DotAttrType::ALIGN;
    case DotAttr::FILL_COLOR_1      :
    case DotAttr::FILL_COLOR_2      :
    case DotAttr::FILL_COLOR_YELLOW : return DotAttrType::FILL_COLOR;
    case DotAttr::DIR_NORTH         :
    case DotAttr::DIR_EAST          :
    case DotAttr::DIR_SOUTH         :
    case DotAttr::DIR_WEST          :
    case DotAttr::DIR_NORTH_EAST    :
    case DotAttr::DIR_SOUTH_EAST    :
    case DotAttr::DIR_SOUTH_WEST    :
    case DotAttr::DIR_NORTH_WEST    :
    case DotAttr::DIR_CENTER        :
    case DotAttr::DIR_ANY           : return DotAttrType::DIR;
    case DotAttr::EDGE              :
    case DotAttr::FROM_NODE         :
    case DotAttr::TO_NODE           : return DotAttrType::CHOOSE;
    default:
      break;
  }
  return DotAttrType::UNKNOWN;
}

std::string to_string(DotAttr attr){
  switch (attr){
    case DotAttr::BT                : return "BT";
    case DotAttr::DASHED            : return "dashed";
    case DotAttr::DIR_NORTH         : return "n";
    case DotAttr::DIR_EAST          : return "e";
    case DotAttr::DIR_SOUTH         : return "s";
    case DotAttr::DIR_WEST          : return "w";
    case DotAttr::DIR_NORTH_EAST    : return "ne";
    case DotAttr::DIR_SOUTH_EAST    : return "se";
    case DotAttr::DIR_SOUTH_WEST    : return "sw";
    case DotAttr::DIR_NORTH_WEST    : return "nw";
    case DotAttr::DIR_CENTER        : return "c";
    case DotAttr::DIR_ANY           : return "_";
    case DotAttr::ELLIPSE           : return "ellipse";
    case DotAttr::EDGE              : return "edge";
    case DotAttr::FROM_NODE         : return "from";
    case DotAttr::GREY              : return "grey";
    case DotAttr::LINE              : return "line";
    case DotAttr::LR                : return "LR";
    case DotAttr::NONE              : return "none";
    case DotAttr::RECORD            : return "record";
    case DotAttr::RED               : return "red";
    case DotAttr::RL                : return "RL";
    case DotAttr::SAME              : return "same";
    case DotAttr::TB                : return "TB";
    case DotAttr::TO_NODE           : return "to";
    case DotAttr::LEFT              : return "LEFT";
    case DotAttr::RIGHT             : return "RIGHT";
    case DotAttr::CENTER            : return "CENTER";
    case DotAttr::FILL_COLOR_1      : return "\"#f3c7b170\"";
    case DotAttr::FILL_COLOR_2      : return "\"#dc5d4a70\"";
    case DotAttr::FILL_COLOR_YELLOW : return "\"yellow\"";
    case DotAttr::WHITE             : return "white";

    default:  break;
  }
  return "";
}

std::string to_string(DotAttrType type){
  switch (type){
    case DotAttrType::COLOR       : return "color";
    case DotAttrType::DIR         : return "dir";
    case DotAttrType::RANDIR      : return "rankdir";
    case DotAttrType::RANK        : return "rank";
    case DotAttrType::SHAPE       : return "shape";
    case DotAttrType::SPLINES     : return "splines";
    case DotAttrType::STYLE       : return "style";
    case DotAttrType::ALIGN       : return "align";
    case DotAttrType::FILL_COLOR  : return "fillcolor";
    case DotAttrType::CHOOSE      : return "choose";
    default:
      break;
  }
  return "";
}



std::string dot_format_label(const std::string& line, DotAttr attr){
  switch(attr){
    case DotAttr::LEFT    : return line + DOT_ALIGN_LEFT;
    case DotAttr::RIGHT   : return line + DOT_ALIGN_RIGH;
    case DotAttr::CENTER  : return line + DOT_ALIGN_CENTER;
    default               : return line;
  }
}

std::string dot_format_label(const std::vector<std::string>& lines){
  if(lines.size() == 1)
    return lines[0];

  std::string out = "{";
  for(std::string line : lines){
    out += line;
  }
  out += "}";
  return out;
}


static std::string _output_attr(DotAttr attr){
  if(attr == DotAttr::NIL)
    return "";

  DotAttrType attr_type = type_of(attr);
  std::string key = lfc::to_string(attr_type);
  assert(key != "" && "bad attr");

  std::string value = lfc::to_string(attr);

  switch(attr_type){
    // style=filled, fillcolor="#88abfd70"
    case DotAttrType::FILL_COLOR:
    {
      std::string out = "style=filled, ";
      return out + key +"=" + value;
    }
  default:
    break;
  }

  return key +"=" + value;
}

static std::string _out_attr_list(const std::vector<std::string>& vec){
  if(vec.empty())
    return "";

  std::string out = "";
  int i = 0, size = vec.size();;
  for(const std::string& val : vec){
    if(val == "")
      continue;
    if(i++ != 0)
      out += ", ";
    else
      out += "[";
    out += val;
  }

  if(i > 0)
    out += "]";
  
  return out;
}

static std::string _output_node_label(std::string label){
  return "label=\"" + label +"\"";
}

static std::string _output_edge_label(std::string label){
  if(label == "")
    return "";
  return "label=\"" + label +"\"";
}


static std::string _name_of_label(std::string name, std::string label, DotAttr from_attr){
  std::string out = name;
  if(label != ""){
    out += ":"+ label;
  }

  if(from_attr != DotAttr::NIL){
    out += ":"+ lfc::to_string(from_attr);
  }

  return out;
}

struct DotEdge{
  int         index;
  DotAttr     attr_color;
  DotAttr     attr_style;
  DotAttr     attr_dir;
  DotAttr     from_dir;
  DotAttr     to_dir;
  int         from_index;
  int         to_index;
  int         weight;
  std::string from_label;
  std::string to_label;
  std::string edge_label;
  DotEdge() = default;
  DotEdge(const DotEdge& E){
    this->index      = E.index; 
    this->attr_color = E.attr_color; 
    this->attr_style = E.attr_style; 
    this->attr_dir   = E.attr_dir;
    this->from_dir   = E.from_dir;
    this->to_dir     = E.to_dir;
    this->from_index = E.from_index; 
    this->to_index   = E.to_index; 
    this->weight     = E.weight; 
    this->from_label = E.from_label; 
    this->to_label   = E.to_label; 
    this->edge_label = E.edge_label; 
  }
};

struct DotNode{
  int               index;
  std::string       name;
  std::string       label;
  DotAttr           attr_shape;
  DotAttr           attr_color;
  DotAttr           attr_style;
  DotAttr           attr_fillcolor;
  bool              empty;
  int               graph_index;
  std::vector<int>  input_edge_list;
  std::vector<int>  output_edge_list;
  DotNode() = default;
  DotNode(const DotNode& N){
    this->index             = N.index;
    this->name              = N.name;
    this->label             = N.label; 
    this->attr_shape        = N.attr_shape; 
    this->attr_color        = N.attr_color;
    this->attr_style        = N.attr_style;
    this->attr_fillcolor    = N.attr_fillcolor;
    this->empty             = N.empty;
    this->graph_index       = N.graph_index;
    this->input_edge_list   = N.input_edge_list;
    this->output_edge_list  = N.output_edge_list;
  }
};

struct DotGraph{
  int               index = 0;
  int               parent_index;
  std::string       name;
  bool              anonymous;
  DotAttr           attr_rankdir;
  DotAttr           attr_rank;  
  std::vector<int>  child_graph_list;
  std::vector<int>  node_list;
  std::vector<int>  edge_list;

  std::map<std::string, int> node_index_map;

  DotGraph() = default;
  DotGraph(const DotGraph& G){
    this->index             = G.index;
    this->parent_index      = G.parent_index;
    this->name              = G.name;
    this->anonymous         = G.anonymous;
    this->attr_rankdir      = G.attr_rankdir;
    this->attr_rank         = G.attr_rank;
    this->node_list         = G.node_list;
    this->child_graph_list  = G.child_graph_list;
    this->node_index_map    = G.node_index_map;
  }
};

class DotUtilImpl{
  friend class DotUtil;

public:

  DotUtilImpl(std::string root_graph_name);
  DotNode* add_node(DotGraph* graph, DotNode& node);
  DotNode* get_node(std::string name, DotGraph* graph);
  void output_graph(std::vector<std::string>& lines, DotGraph& graph, int level);

private:
  DotGraph                   m_root_graph;
  std::vector<DotGraph>      m_dot_graph_list;
  std::vector<DotNode>       m_dot_node_list;
  std::vector<DotEdge>       m_dot_edge_list;
};


DotUtilImpl::DotUtilImpl(std::string root_graph_name){
  m_root_graph.index        = 0;
  m_root_graph.parent_index = -1;
  m_root_graph.name         = "\""+root_graph_name+"\"";
  m_root_graph.anonymous    = false;
  m_root_graph.attr_rankdir = DotAttr::NIL;
  m_root_graph.attr_rank    = DotAttr::NIL;

  m_dot_graph_list.push_back(m_root_graph);
}


static std::string _output_node(DotNode& node){
  return node.name + _out_attr_list(to_vector({
     _output_attr(node.attr_shape)
    , _output_attr(node.attr_fillcolor)
    , node.empty ? "" : _output_node_label(node.label)
    , _output_attr(node.attr_color)
    , _output_attr(node.attr_style)
    }));
}

static std::string _output_edge_weight(int weight){
  if(weight == DOT_EDGE_WEIGHT_DEF)
    return "";
  return "weight="+lfc::to_string(weight);
}

static std::string _output_edge(const std::string& from_name, const std::string& to_name, DotEdge& edge){
  return  _name_of_label(to_name, edge.to_label, edge.to_dir) + " -> " 
    + _name_of_label(from_name, edge.from_label, edge.from_dir) + " " 
    + _out_attr_list(to_vector({
        _output_attr(edge.attr_color)
      , _output_edge_weight(edge.weight)
      , _output_attr(edge.attr_style)
      , _output_attr(edge.attr_dir)
      , _output_edge_label(edge.edge_label)
      }));
}


static void _add_line(std::vector<std::string>& lines, std::string line, int level){
  static std::vector<std::string> level_lines = {"", "\t", "\t\t", "\t\t\t", "\t\t\t\t", "\t\t\t\t\t"};
  lines.push_back(level_lines[level] + line);
}

void DotUtilImpl::output_graph(std::vector<std::string>& lines, DotGraph& graph, int level){
  
  // output digraph begin
  {
    std::string head_line;

    if(!graph.anonymous){
      head_line += level == 0 ? "digraph " : "subgraph ";
      head_line += graph.name +" ";    
    }

    head_line += "{"; 
    _add_line(lines, head_line, level);
  }

  // output rankdir
  if(graph.attr_rankdir != DotAttr::NIL){
    _add_line(lines, _output_attr(graph.attr_rankdir), level+1);
  }

  // output rank
  if(graph.attr_rank != DotAttr::NIL){
    _add_line(lines, _output_attr(graph.attr_rank), level+1);
  }

  // output nodes
  for(int node_index : graph.node_list){
    DotNode& node = m_dot_node_list[node_index];
    _add_line(lines, _output_node(node), level+1);
  }

  // output edges
  for(int edge_index: graph.edge_list){
    DotEdge& edge      = m_dot_edge_list[edge_index];
    DotNode& from_node = m_dot_node_list[edge.from_index];
    DotNode& to_node   = m_dot_node_list[edge.to_index];
    _add_line(lines, _output_edge(from_node.name, to_node.name, edge), level+1);
  }

  // output child graph
  for(int child_graph_index: graph.child_graph_list){
    auto& child_graph = m_dot_graph_list[child_graph_index];
    output_graph(lines, child_graph, level+1);
  }

  // output digraph end
  _add_line(lines, "}", level);
}

DotNode* DotUtilImpl::add_node(DotGraph* graph, DotNode& node){
  node.graph_index = graph->index;
  graph->node_list.push_back(node.index);
  graph->node_index_map[node.name] = node.index;
  m_dot_node_list.push_back(node);
  return &m_dot_node_list.back();
}

DotNode* DotUtilImpl::get_node(std::string name, DotGraph* graph){
  assert(graph);

  auto it = graph->node_index_map.find(name);
  if(it == graph->node_index_map.end())
    return NULL;
  
  int index = it->second;
  return &(m_dot_node_list[index]);
}

DotUtil::DotUtil(std::string root_graph_name){
  impl = new DotUtilImpl(root_graph_name);
}

DotUtil::~DotUtil(){
  delete impl;
}

std::vector<std::string> DotUtil::output_dot_graph(){
  std::vector<std::string> lines;
  impl->output_graph(lines, impl->m_root_graph, 0);
  return lines;
}

DotGraph* DotUtil::add_graph(std::string name, DotGraph* parent){
  if(parent == NULL){
    parent = &impl->m_root_graph;
  }

  int graph_index = impl->m_dot_graph_list.size();
  bool anonymous = false;

  if(name == ""){
    name = "G" + lfc::to_string(graph_index);
    anonymous = true;
  }

  DotGraph graph;
  graph.index         = graph_index;
  graph.name          = name;
  graph.anonymous     = anonymous;
  graph.attr_rankdir  = DotAttr::NIL;
  graph.attr_rank     = DotAttr::NIL;

  graph.parent_index = parent->index;
  parent->child_graph_list.push_back(graph_index);
  impl->m_dot_graph_list.push_back(graph);

  return &impl->m_dot_graph_list.back();
}

DotNode* DotUtil::add_node(std::string name, std::string label, DotGraph* graph){
  if(graph == NULL){
    graph = &impl->m_root_graph;
  }

  int node_index = impl->m_dot_node_list.size();
  
  DotNode node;
  node.index  = node_index;
  node.name   = name;
  node.label  = label;
  node.empty  = false;
  node.attr_shape     = DotAttr::RECORD;
  node.attr_color     = DotAttr::NIL;
  node.attr_style     = DotAttr::NIL;
  node.attr_fillcolor = DotAttr::NIL;

  return impl->add_node(graph, node);
}

DotNode* DotUtil::add_empty_node(std::string name, DotGraph* graph){
  if(graph == NULL){
    graph = &impl->m_root_graph;
  }

  int node_index = impl->m_dot_node_list.size();
  
  DotNode node;
  node.index  = node_index;
  node.name   = name;
  node.label  = "";
  node.empty  = true;
  node.attr_shape     = DotAttr::NIL;
  node.attr_color     = DotAttr::NIL;
  node.attr_style     = DotAttr::NIL;
  node.attr_fillcolor = DotAttr::NIL;

  return impl->add_node(graph, node);
}

DotEdge* DotUtil::add_edge(std::string from_name, std::string to_name, DotGraph* graph){
  if(graph == NULL){
    graph = &impl->m_root_graph;
  }

  std::string from_label = "", to_label = "";
  {
    const char* from_label_pos = ch_memrchr(from_name.c_str(), ':', from_name.length());
    if(from_label_pos != NULL){
      from_label = std::string(from_label_pos+1);
      from_name  = std::string(from_name.c_str(), from_label_pos - from_name.c_str());
    }
  }

  {
    const char* to_label_pos = ch_memrchr(to_name.c_str(), ':', to_name.length());
    if(to_label_pos != NULL){
      to_label = std::string(to_label_pos+1);
      to_name  = std::string(to_name.c_str(), to_label_pos - to_name.c_str());
    }
  }

  DotNode* from_node = impl->get_node(from_name, graph);
  assert(from_node && "from-node not found");

  DotNode* to_node = impl->get_node(to_name, graph);
  assert(to_node && "to-node not found");

  int edge_index = impl->m_dot_edge_list.size();

  DotEdge edge;
  edge.index      = edge_index;
  edge.from_index = from_node->index;
  edge.to_index   = to_node->index;
  edge.attr_color = DotAttr::NIL;
  edge.attr_style = DotAttr::NIL;
  edge.attr_dir   = DotAttr::NIL;
  edge.from_dir   = DotAttr::NIL;
  edge.to_dir     = DotAttr::NIL;
  edge.weight     = DOT_EDGE_WEIGHT_DEF;
  edge.from_label = from_label;
  edge.to_label   = to_label;

  impl->m_dot_edge_list.push_back(edge);

  from_node->output_edge_list.push_back(edge_index);
  to_node->input_edge_list.push_back(edge_index);

  graph->edge_list.push_back(edge_index);

  return &impl->m_dot_edge_list.back();
}

void DotUtil::set_graph_attribute(DotAttr attr, DotGraph* graph){
  if(graph == NULL){
    graph = &impl->m_root_graph;
  }

  switch (type_of(attr)){
    case DotAttrType::RANDIR:
      graph->attr_rankdir = attr;
      break;
    case DotAttrType::RANK:
      graph->attr_rank = attr;
    default:
      break;
  }
}

void DotUtil::set_graph_name(std::string name, DotGraph* graph){
  if(graph == NULL){
    graph = &impl->m_root_graph;
  }

  graph->name = name;
}

void DotUtil::set_node_attribute(DotNode* node, DotAttr attr){
  if(attr == DotAttr::NIL)
    return;

  switch (type_of(attr)){
    case DotAttrType::SHAPE       : node->attr_shape = attr;      break;
    case DotAttrType::COLOR       : node->attr_color = attr;      break;
    case DotAttrType::STYLE       : node->attr_style = attr;      break;
    case DotAttrType::FILL_COLOR  : node->attr_fillcolor = attr;  break;
    default:
      std::cout << "atrr: attr=" << lfc::to_string(attr)  << "(" << (int)attr 
                << "), type=" << lfc::to_string(type_of(attr)) << "(" << (int)type_of(attr) 
                << ")" << std::endl;
      assert(0 && "not support node attribute");
      break;
  }
}

void DotUtil::set_node_label(DotNode* node,  std::string label){
  node->label = label;
}

#define OUTPUT_ATTR(namme, attr) \
std::cout << namme <<  ": " << lfc::to_string(attr)  << "(" << (int)attr << ")" \
          << ", type=" << lfc::to_string(type_of(attr)) << "(" << (int)type_of(attr) << ")" \
          << std::endl;

void DotUtil::set_edge_attribute(DotEdge* edge, DotAttr attr, DotAttr choose){
  if(attr == DotAttr::NIL)
    return;
  
  if(type_of(choose) != DotAttrType::CHOOSE){
    OUTPUT_ATTR("attr", attr);
    OUTPUT_ATTR("choose", choose);
    assert(0 && "not support edge choose attribute");
  }

  switch (choose){
    case DotAttr::EDGE:
      switch (type_of(attr)){
        case DotAttrType::COLOR: edge->attr_color = attr; break;
        case DotAttrType::STYLE: edge->attr_style = attr; break;
        case DotAttrType::DIR  : edge->attr_dir   = attr; break;
        default:
          OUTPUT_ATTR("attr", attr);
          OUTPUT_ATTR("choose", choose);
          assert(0 && "not support edge attribute - attr");
          break;
      }
      break;
    case DotAttr::FROM_NODE:
    case DotAttr::TO_NODE:
      if( type_of(attr) != DotAttrType::DIR){
        OUTPUT_ATTR("attr", attr);
        OUTPUT_ATTR("choose", choose);
        assert(0 && "not support edge attribute - attr");
      }

      if(choose == DotAttr::FROM_NODE){
        edge->from_dir = attr;
      }
      else {
        edge->to_dir = attr;
      }     

      break;
    
    default:
      break;
  }
}

void DotUtil::set_edge_weight(DotEdge* edge, int weight){
  edge->weight = weight;
}

void DotUtil::set_edge_label(DotEdge* edge, std::string label){
  edge->edge_label = label;
}

DotNode* DotUtil::get_node(std::string name, DotGraph* graph){
  if(graph == NULL){
    graph = &impl->m_root_graph;
  }

  return impl->get_node(name, graph);
}

std::string DotUtil::get_node_name(DotNode* node){
  return node->name;
}

std::string DotUtil::get_node_label(DotNode* node){
  return node->label;
}

std::vector<std::string> DotUtil::dump(){
  std::vector<std::string> lines;
  lines.push_back("nodes:");
  for(auto& node : impl->m_dot_node_list){
    lines.push_back(lfc::to_string(&node));
  }
  return lines;  
}

std::string to_string(const DotNode* DN){
  if( !DN )
    return "DN(null)";

  std::string out = "DN(";

  out += "index=";
  out += std::to_string(DN->index);

  out += ", name=";
  out += DN->name;

  out += ", label=";
  out += DN->label;

  out += ", shape=";
  out += lfc::to_string(DN->attr_shape);

  out += ", color=";
  out += lfc::to_string(DN->attr_color);

  out += ", style=";
  out += lfc::to_string(DN->attr_style);

  out += ", fill=";
  out += lfc::to_string(DN->attr_fillcolor);

  out += ", empty=";
  out += lfc::to_string(DN->empty);

  out += ", graph=";
  out += lfc::to_string(DN->graph_index);

  out += ", input=";
  out += lfc::to_string(DN->input_edge_list);

  out += ", output=";
  out += lfc::to_string(DN->output_edge_list);

  out += ")";

  return out;
}

}// namespace lfc 
