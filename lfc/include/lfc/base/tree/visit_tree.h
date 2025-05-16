#ifndef __LFC_VISIT_TREE_H__
#define __LFC_VISIT_TREE_H__

#include <queue>

namespace lfc {

template <typename _TNode, typename _F_visit, typename _F_next>
int visit_tree_bfs(_TNode tree, _F_visit _visit, _F_next _next){

  std::queue<_TNode>  visiting_queue;
  std::queue<int>     visiting_level;

  visiting_queue.push(tree);
  visiting_level.push(0);
  int visit_count = 0;

  while(!visiting_queue.empty()){

    _TNode node = visiting_queue.front(); 
    int level   = visiting_level.front(); 

    visiting_queue.pop();
    visiting_level.pop();

    ++visit_count;
    if(_visit(node, level)){
      break;
    }

    for(_TNode NN : _next(node)){
      visiting_queue.push(NN);
      visiting_level.push(level + 1);
    }
  }

  return visit_count;
}

template <typename _TNode, typename _F_visit, typename _F_next>
bool _visit_tree_dfs_postorder(int level, int& count, _TNode node, _F_visit _visit, _F_next _next){
  for(_TNode NN : _next(node)){
    if(_visit_tree_dfs_postorder(level+1, count, NN, _visit, _next)){
      return true;
    }
  }

  ++count;
  _visit(node, level);
  return false;
}

template <typename _TNode, typename _F_visit, typename _F_next>
int visit_tree_dfs_postorder(_TNode root, _F_visit _visit, _F_next _next){
  int visit_count = 0;
  _visit_tree_dfs_postorder(0, visit_count, root, _visit, _next);
  return visit_count;
}

template <typename _TNode, typename _F_visit, typename _F_next>
bool _visit_tree_dfs_preorder(int level, int& count, _TNode node, _F_visit _visit, _F_next _next){
  _visit(node, level);
  for(_TNode NN : _next(node)){
    if(_visit_tree_dfs_postorder(level+1, count, NN, _visit, _next)){
      return true;
    }
  }
  return false;
}


template <typename _TNode, typename _F_visit, typename _F_next>
int visit_tree_dfs_preorder(_TNode root, _F_visit _visit, _F_next _next){
  int visit_count = 0;
  _visit_tree_dfs_preorder(0, visit_count, root, _visit, _next);
  return visit_count;
}

template <typename _TNode, typename _F_visit, typename _F_next>
void _dump_tree(std::vector<bool>& leaf_vec, _TNode node, _F_visit _visit, _F_next _next, std::vector<std::string>& lines){

  std::string out = "";
  int level = leaf_vec.size();
  for(int i = 1; i <= level; ++i){
    if( i == level ){
      out += leaf_vec[i-1] ? "`-" : "|-" ;
    }
    else{
      out += leaf_vec[i-1] ? "  " : "| " ;
    }
  }

  out +=_visit(node);

  lines.push_back(out);

  auto childs = _next(node);  
  int child_size = childs.size();  
  int i = 0;
  for(_TNode NN : childs){
    leaf_vec.push_back(i == (child_size-1));
    _dump_tree(leaf_vec, NN, _visit, _next, lines);
    leaf_vec.pop_back();
    ++i;
  }
}

template <typename _TNode, typename _F_visit, typename _F_next>
std::vector<std::string> dump_tree(_TNode root, _F_visit _visit, _F_next _next){
  std::vector<std::string> lines;
  std::vector<bool> leaf_vec;
  _dump_tree(leaf_vec, root, _visit, _next, lines);
  return lines;
}


} // namespace lfc

#endif // __LFC_VISIT_TREE_H__

