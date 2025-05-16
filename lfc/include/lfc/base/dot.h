// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_DOT_UTIL_H__
#define __LFC_DOT_UTIL_H__

#include <string>
#include <vector>

#define DOT_EDGE_WEIGHT_DEF       -1
#define DOT_EDGE_WEIGHT_HIGH      100

namespace lfc {

enum class DotAttr{
  NIL = 0, 
  ELLIPSE, RECORD,      // Shape
  LINE,                 // Splines
  RED, GREY, WHITE,     // Color
  TB, BT, LR, RL,       // RandDir
  DASHED,               // Style
  SAME,                 // Rank
  NONE,                 // DIR
  LEFT, RIGHT, CENTER,  // ALIGN
  FILL_COLOR_1,         // FILL_COLOR #f3c7b170
  FILL_COLOR_2,         // FILL_COLOR #dc5d4a70
  FILL_COLOR_YELLOW,    // FILL_COLOR yellow
  DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST,                       // DIR
  DIR_NORTH_EAST, DIR_SOUTH_EAST, DIR_SOUTH_WEST, DIR_NORTH_WEST, // DIR
  DIR_CENTER, DIR_ANY,                                            // DIR
  EDGE, FROM_NODE, TO_NODE,                                       // CHOOSE
};


std::string to_string(DotAttr attr);

std::string dot_format_label(const std::string& line, DotAttr attr);
std::string dot_format_label(const std::vector<std::string>& lines);

struct DotEdge;
struct DotNode;
struct DotGraph;

class DotUtilImpl;
class DotUtil{
public:
  DotUtil(std::string root_graph_name);
  ~DotUtil();
  
  DotNode* add_node(std::string name, std::string label, DotGraph* graph = NULL);
  DotNode* add_empty_node(std::string name, DotGraph* graph = NULL);
  DotEdge* add_edge(std::string from_name, std::string to_name, DotGraph* graph = NULL);
  DotGraph* add_graph(std::string name = "", DotGraph* parent = NULL);

  void set_graph_attribute(DotAttr attr, DotGraph* graph = NULL);
  void set_graph_name(std::string name, DotGraph* graph = NULL);

  void set_node_attribute(DotNode* node, DotAttr attr);
  void set_node_label(DotNode* node,  std::string label);

  void set_edge_attribute(DotEdge* edge, DotAttr attr, DotAttr choose = DotAttr::EDGE);
  void set_edge_label(DotEdge* edge,  std::string label);
  void set_edge_weight(DotEdge* edge, int weight);

  std::vector<std::string> output_dot_graph();

  DotNode* get_node(std::string name, DotGraph* graph = NULL);

  std::vector<std::string> dump();

public:
  static std::string get_node_name(DotNode* node);
  static std::string get_node_label(DotNode* node);

private:
  class DotUtilImpl* impl;
};

std::string to_string(const DotNode*);

}// namespace lfc

#endif // __LFC_DOT_UTIL_H__

