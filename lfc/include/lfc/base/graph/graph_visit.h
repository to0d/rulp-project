#ifndef __LFC_GRAPH_VISIT_H__
#define __LFC_GRAPH_VISIT_H__


#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
namespace lfc {

template <typename _TNode, typename _F_visit, typename _F_next>
int visit_graph_bfs(const std::vector<_TNode>& input_nodes, _F_visit _visit, _F_next _next, bool visit_input_node = false){

  std::set<_TNode> input_nodes_set;
  std::queue<_TNode> visiting_queue;
  std::for_each(input_nodes.begin(), input_nodes.end(), 
    [&](auto node){ 
      visiting_queue.push(node);
      if(!visit_input_node){
        input_nodes_set.insert(node); 
      }      
    }
  );

  int visit_count = 0;

  std::set<_TNode> visited_nodes;
  while(!visiting_queue.empty()){
    _TNode node = visiting_queue.front(); 
    visiting_queue.pop();

    if(visited_nodes.find(node) != visited_nodes.end()){
      continue;
    }     

    visited_nodes.insert(node);

    if(visit_input_node || input_nodes_set.find(node) == input_nodes_set.end()){
      ++visit_count;
      if(_visit(node)){
        break;
      }
    }    

    for(_TNode NN : _next(node)){
      visiting_queue.push(NN);
    }
  }

  return visit_count;
}

template <typename _TNode, typename _F_visit, typename _F_next>
bool _visit_graph_dfs(_TNode node, _F_visit _visit, _F_next _next, std::set<_TNode>& visited_nodes, int& visit_count){

  for(_TNode NN : _next(node)){

    if(visited_nodes.find(NN) != visited_nodes.end()){
      continue;
    }

    visited_nodes.insert(NN);
    ++visit_count;
    if(_visit(NN)){
      return true;
    }

    _visit_graph_dfs(NN, _visit, _next, visited_nodes, visit_count);
  }

  return false;
}

template <typename _TNode, typename _F_visit, typename _F_next>
int visit_graph_dfs(const std::vector<_TNode>& input_nodes, _F_visit _visit, _F_next _next, bool visit_input_node = false){

  std::set<_TNode> input_nodes_set;
  std::for_each(input_nodes.begin(), input_nodes.end(), [&](auto e){input_nodes_set.insert(e);});

  int visit_count = 0;
  std::set<_TNode> visited_nodes;

  for(auto& input_node : input_nodes){
    
    if(visited_nodes.find(input_node) != visited_nodes.end()){
      continue;
    }

    visited_nodes.insert(input_node);
    if(visit_input_node){
      ++visit_count;
      if(_visit(input_node)){
        break;
      }
    }

    if(_visit_graph_dfs(input_node, _visit, _next, visited_nodes, visit_count)){
      break;
    }
  
  }

  return visit_count;
}

template <typename _TNode, typename _F_visit, typename _F_next>
int visit_graph_by_topological_sorting(const std::vector<_TNode>& all_nodes, _F_visit _visit, _F_next _next){

  int size = all_nodes.size();
  std::map<_TNode, int> input_count_map;
  std::queue<_TNode> working_queue;

  int visit_count = 0;

  for(int i = 0; i < size; ++i){
    _TNode node = all_nodes[i];
    for(_TNode next : _next(node)){
      input_count_map[next]++;
    }
  }

  for(int i = 0; i < size; ++i){
    _TNode node = all_nodes[i];
    if(input_count_map[node] == 0){
      working_queue.push(node);      
    }
  }

  while(!working_queue.empty()){
    _TNode& node = working_queue.front();
    working_queue.pop();

    ++visit_count;
    if(_visit(node)){
      break;
    }

    for(_TNode next : _next(node)){
      if(--input_count_map[next] == 0){
        working_queue.push(next);
      }
    }    
  }

  return visit_count;
}

} // namespace lfc

#endif // __LFC_GRAPH_H__

