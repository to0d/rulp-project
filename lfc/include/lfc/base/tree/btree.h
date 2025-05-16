// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BTREE_H__
#define __LFC_BTREE_H__

#include "lfc/base/tree/visit_tree.h"
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

namespace lfc {

template <typename Tx>
struct BTreeNode {
  Tx val;
  BTreeNode *left;
  BTreeNode *right;
  BTreeNode(Tx x) : val(x), left(nullptr), right(nullptr) {}
  BTreeNode(Tx x, BTreeNode *left, BTreeNode *right) : val(x), left(left), right(right) {}
};

template <typename Tx, typename _F_visit>
int visit_tree_bfs(BTreeNode<Tx>* tree, _F_visit _visit){  
  typedef BTreeNode<Tx> _TNode;
  if (tree == nullptr) {
    return 0;
  }

  std::queue<_TNode*> visiting_queue;
  std::queue<int>     visiting_level;

  BTreeNode<Tx>* root = tree;
  visiting_queue.push(root);
  visiting_level.push(0);

  int visit_count = 0;

  while(!visiting_queue.empty()){
    _TNode* node  = visiting_queue.front();
    int level     = visiting_level.front();
    visiting_queue.pop();
    visiting_level.pop();

    ++visit_count;
    if(_visit(node, level)){
      break;
    }

    if( node->left != nullptr ){
      visiting_queue.push(node->left);
      visiting_level.push(level + 1);
    }

    if( node->right != nullptr ){
      visiting_queue.push(node->right);
      visiting_level.push(level + 1);
    }
  }

  return visit_count;
}

template <typename Tx, typename _F_visit>
int visit_tree_dfs_inorder(BTreeNode<Tx>* tree, _F_visit _visit){
  typedef BTreeNode<Tx> _TNode;
  if (tree == nullptr) {
    return 0;
  }

  _TNode *node = tree;
  int level = 0;
  int visit_count = 0;

  std::stack<_TNode*> node_stack;
  std::stack<int>     level_stack;

  while (node != NULL || !node_stack.empty() ){  
    for(; node != NULL ; node = node->left){
      node_stack.push(node);
      level_stack.push(level++);
    }

    node = node_stack.top(); node_stack.pop();
    level = level_stack.top(); level_stack.pop();

    ++visit_count;
    if(_visit(node, level)){
      break;
    }

    node = node->right;
    level++;
  }

  return visit_count;
}

template <typename Tx, typename _F_visit>
int visit_tree_dfs_postorder(BTreeNode<Tx>* tree, _F_visit _visit){
  typedef BTreeNode<Tx> _TNode;
  if (tree == nullptr) {
    return 0;
  }

  std::stack<_TNode*> node_stack;
  std::stack<int>     level_stack;

  _TNode *node = tree, *previsited= NULL;
  int level = 0;
  int visit_count = 0;

  while (node != NULL || !node_stack.empty() ){   
    for(; node != NULL ; node = node->left){
      node_stack.push(node);
      level_stack.push(level++);
    }      

    node = node_stack.top();
    level = level_stack.top();

    if( node->right == NULL || previsited == node->right ){

      ++visit_count;
      if(_visit(node, level)){
        break;
      }

      node_stack.pop();
      level_stack.pop();
      previsited = node;
      node  = NULL;
      level = -1;
    }
    else{
      node = node->right;
      level++;
    }
  }

  return visit_count;
}

template <typename Tx, typename _F_visit>
int visit_tree_dfs_preorder(BTreeNode<Tx>* tree, _F_visit _visit){
  typedef BTreeNode<Tx> _TNode;
  if (tree == nullptr) {
    return 0;
  }

  BTreeNode<Tx>* root = tree;
  std::stack<_TNode*> node_stack;
  std::stack<int>     level_stack;

  int visit_count = 0;

  node_stack.push(root);
  level_stack.push(0);

  while (!node_stack.empty()) {
    _TNode* node = node_stack.top();
    node_stack.pop();

    int level = level_stack.top();
    level_stack.pop();

    ++visit_count;
    if(_visit(node, level)){
      break;
    }

    if (node->right) {
      node_stack.push(node->right);
      level_stack.push(level+1);
    }
    if (node->left) {
      node_stack.push(node->left);
      level_stack.push(level+1);
    }
  }

  return visit_count;
}


template <typename Tx>
std::string to_string(BTreeNode<Tx>* tree){
  std::vector<BTreeNode<Tx>*> nodeList;
  std::queue<BTreeNode<Tx>*>  nodeQueue;
  nodeQueue.push(tree);
  while(!nodeQueue.empty()){
    BTreeNode<Tx>* node = nodeQueue.front();
    nodeQueue.pop();
    nodeList.push_back(node);
    
    if( node != nullptr ){   
      nodeQueue.push(node->left); 
      nodeQueue.push(node->right); 
    }
  }
  
  int size = nodeList.size();
  while( size > 0 && nodeList[size-1] == nullptr ){   
    --size;
  }

  std::string out = "[";
  
  for(int i=0; i<size; ++i){
    if( i != 0 )
      out += ",";

    BTreeNode<Tx>* node = nodeList[i];
    if( node == nullptr ){  
      out += "null";
    }
    else{
      out += lfc::to_string(node->val);
    }        
  }
  out += "]";

  return out;
}


template <typename Tx>
void free_btree(BTreeNode<Tx>* tree){
  if( tree == nullptr)
    return;

  if(tree->left != nullptr){
    free_btree(tree->left);
    tree->left = nullptr;
  }
  
  if(tree->right != nullptr){
    free_btree(tree->right);
    tree->right = nullptr;
  }

  delete tree;
}

inline 
BTreeNode<int>* make_btree(std::string s){
  // "{1,2,3,#,#,4,#,#,5}"

  int begin = 0, end = s.size();

  while( begin < end && s[begin] != '{' )
    ++begin;
  
  while( begin < end && s[end-1] != '}' )
    --end;
  
  if( begin == end )
      return nullptr;
  
  ++begin, --end; //skip {}
  
  std::vector<BTreeNode<int>*> nodeList;
  
  while( begin < end ){
    int pos = begin;
    while (pos < end && s[pos] != ',')
        ++pos;

    if( pos == (begin+1) && s[begin] == '#' ){  
      nodeList.push_back(nullptr);
    }
    else if( pos == (begin+4) && s.substr(begin, 4) == "null" ){  
      nodeList.push_back(nullptr);
    }
    else{
      std::string str = s.substr(begin, pos-begin);
      int val = std::stoi(s.substr(begin, pos-begin));
      nodeList.push_back(new BTreeNode<int>(val));
    }

    begin = pos+1;
  }
  
  BTreeNode<int>* root = nullptr;
  BTreeNode<int>* cur  = nullptr;
  bool      left = true;
  
  std::queue<BTreeNode<int>*> nodeQueue;

  for(BTreeNode<int>* node: nodeList){
    if( cur == nullptr ){ 
      if( !nodeQueue.empty() ){   
        cur = nodeQueue.front();
        nodeQueue.pop();
        left = true;
      }
    }

    if( node == nullptr ){
      if( cur != nullptr ){
        if( left )
          left = false;
        else
          cur = nullptr;
      }
    }
    else if( root == nullptr ){
      root = node;
      cur  = node;
    }
    else{

      if( left ){
        left = false;
        cur->left = node;
      }
      else{
        cur->right = node;
        cur = nullptr;
      }

      nodeQueue.push(node);
    }
  }

  return root;
}

template <typename Tx>
BTreeNode<Tx>* find_btree_node(BTreeNode<Tx>* tree, Tx val){
  if( tree == NULL || tree->val == val )
    return tree;
  
  BTreeNode<Tx>* node = find_btree_node(tree->left, val);
  if( node != NULL )
    return node;
  
  return find_btree_node(tree->right, val);
}

} // namespace lfc


#endif // __LFC_BTREE_H__

