// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/graph/graph_simple.h"
#include "lfc/base/container.h"
#include <algorithm>

using namespace std;
using namespace lfc;

namespace lfc {

simple_set_graph make_simple_set_graph(const simple_graph& graph, bool is_directed){

  int size = graph.size();
  simple_set_graph SSG(size);

  for(int i = 0 ; i < size; i++){
    for(int j : graph[i]){
      SSG[i].insert(j);
      if(!is_directed){
        SSG[j].insert(i);
      }
    }
  }

  return std::move(SSG);
}

simple_graph make_simple_graph_undirected(const simple_set_graph& graph){

  int size = graph.size();
  simple_graph SG(size);

  for(int i = 0 ; i < size; i++){
    for(int j : graph[i]){
      if( i <=j ){
        SG[i].push_back(j);
      }
      std::sort(SG[i].begin(), SG[i].end(), std::less<>());
    }

  } 

  return std::move(SG);
}


static void _dfs_visit( const vector<vector<int>>& graph
                      , vector<int>& visited
                      , vector<int>& path
                      , vector<vector<int>>& rst
                      , int start
                      , int target)
{   
  int cur_node = path.back();
  if( cur_node == target){
    
    if(start != target || path.size() != 1){
      rst.push_back(path);
      return;
    }

    auto& vec = graph[start];

    // start == target && path.size() == 1 && start has self-link
    if(std::find(vec.begin(), vec.end(), target) != vec.end()){
      rst.push_back(path);
    }

  }

  if(visited[cur_node] > 0 ){
    return;
  }

  visited[cur_node]++;

  for(int next : graph[cur_node]){
    if(next == cur_node)
      continue;

    path.push_back(next);
    _dfs_visit(graph, visited, path, rst, start, target);
    path.pop_back();
  }

  visited[cur_node]--;
}


std::vector<std::vector<int>> getAllPathsSourceTarget(const vector<vector<int>>& graph, int start, int target){
  if(target == -1){
    target = graph.size()-1;
  }

  vector<int> path = {start};
  vector<vector<int>> rst;
  vector<int> visited(graph.size(), 0);  

  _dfs_visit(graph, visited, path, rst, start, target);

  return std::move(rst);
}



} // namespace lfc