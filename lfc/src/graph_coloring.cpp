// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/graph/graph_coloring.h"
#include <set>

namespace lfc {

static bool _is_neighbor(const std::vector<std::set<int>>& ugraph, int x, int y){
  if(x == y)
    return false;
  return ugraph[x].count(y) != 0;
}

static std::vector<int> _get_neighbors(const std::vector<std::set<int>>& ugraph, int pos, int size){
  std::vector<int> neighbor;

  for(int i = 0; i < size; ++i){
    if(_is_neighbor(ugraph, i, pos)){
      neighbor.push_back(i);
    }
  }
  
  return std::move(neighbor);
}

bool _fill_graph_coloring(const std::vector<std::set<int>>& ugraph, int color_num, std::vector<int>& colors, int size, int pos) {

  if(pos >= size){
    return true;
  }

  std::vector<int> neighbors = _get_neighbors(ugraph, pos, size);
  
  for(int color = 0; color < color_num; ++color){

    bool find_duplicated = false;
    for(int neighbor : neighbors){
      if(colors[neighbor] == color){
        find_duplicated = true;
        break;
      }
    }

    if(find_duplicated){
      continue;
    }

    colors[pos] = color;

    bool succ = true;
    for(int neighbor : neighbors){
      if(colors[neighbor] != -1){
        continue;
      }

      if(!_fill_graph_coloring(ugraph, color_num, colors, size, neighbor)){
        succ = false;
        break;
      }
    }

    if(succ){
      return true;
    }

    colors[pos] = -1;
  }

  return false;
}

bool fill_graph_coloring(const std::vector<std::vector<int>>& graph, int color_num, std::vector<int>& colors){
  
  int size = graph.size();
  std::vector<std::set<int>> SSG = make_simple_set_graph(graph, false);
  colors = std::vector<int>(size, -1);

  return _fill_graph_coloring(SSG, color_num, colors, size, 0);
}

} // namespace lfc