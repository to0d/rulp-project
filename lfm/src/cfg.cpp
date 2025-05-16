// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[cfg_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(cfg_util)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(cfg_util)
#include "lfc/base/abi.h"
#include "lfc/llvm/cfg.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include "lfc/base/graph/graph_visit.h"
#include "lfc/base/graph/graph_utils.h"
#include "lfc/base/container.h"
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"
#include <iostream>

using namespace llvm;

namespace lfc {

static void _copy(const CFGNode& A, CFGNode& B){
  B.index             = A.index;
  B.type              = A.type;
  B.inst              = A.inst;
  B.block             = A.block;
  B.block_name        = A.block_name;
  B.block_end_inst    = A.block_end_inst;
  std::copy(A.jump_from_nodes.begin(), A.jump_from_nodes.end(), std::back_inserter(B.jump_from_nodes));
  std::copy(A.jump_to_nodes.begin(), A.jump_to_nodes.end(), std::back_inserter(B.jump_to_nodes));
  std::copy(A.switch_values.begin(), A.switch_values.end(), std::back_inserter(B.switch_values));
}

static void _move(CFGNode& A, CFGNode& B){
  B.index             = A.index;
  B.type              = A.type;
  B.inst              = A.inst;
  B.block             = A.block;
  B.block_name        = A.block_name;
  B.block_end_inst    = A.block_end_inst;
  std::move(A.jump_from_nodes.begin(), A.jump_from_nodes.end(), std::back_inserter(B.jump_from_nodes));
  std::move(A.jump_to_nodes.begin(), A.jump_to_nodes.end(), std::back_inserter(B.jump_to_nodes));
  std::move(A.switch_values.begin(), A.switch_values.end(), std::back_inserter(B.switch_values));
}

CFGNode::CFGNode(const CFGNode& N){
  _copy(N, *this);
}

CFGNode::CFGNode(CFGNode && N){
  _move(N, *this);
}

CFGNode& CFGNode::operator=(const CFGNode& N){
  _copy(N, *this);
  return *this;
}

CFGNode& CFGNode::operator=(CFGNode&& N){
  _move(N, *this);
  return *this;
}

class CFGGraphImpl : public CFGGraph{
public:
  CFGGraphImpl() = default;
  CFGGraphImpl(const CFGGraphImpl& N);
  CFGGraphImpl(CFGGraphImpl&& N);

  CFGGraphImpl& operator=(const CFGGraphImpl &G);
  CFGGraphImpl& operator=(CFGGraphImpl &&G);

  virtual const std::vector<CFGNode*>& get_all_nodes() const {return all_nodes;}
  virtual CFGNode* get_begin_node() const {return begin_node;}
  virtual const std::vector<CFGNode*>& get_end_nodes() const {return end_nodes;}
  virtual CFGUtil* get_cfg_util() const {return util;}

public:
  CFGUtil*  util        = NULL;
  CFGNode*  begin_node  = NULL;
  std::vector<CFGNode*> end_nodes;
  std::vector<CFGNode*> all_nodes;
};

void _copy_graph(const CFGGraphImpl& A, CFGGraphImpl& B){
  B.util  = A.util;
  B.begin_node = A.begin_node;
  std::copy(A.end_nodes.begin(), A.end_nodes.end(), std::back_inserter(B.end_nodes));
  std::copy(A.all_nodes.begin(), A.all_nodes.end(), std::back_inserter(B.all_nodes));
}

void _move_graph(const CFGGraphImpl& A, CFGGraphImpl& B){
  B.util        = A.util;
  B.begin_node  = A.begin_node;
  std::copy(A.end_nodes.begin(), A.end_nodes.end(), std::back_inserter(B.end_nodes));
  std::move(A.all_nodes.begin(), A.all_nodes.end(), std::back_inserter(B.all_nodes));
}

CFGGraphImpl::CFGGraphImpl(const CFGGraphImpl& G){
  _copy_graph(G, *this);
}

CFGGraphImpl::CFGGraphImpl(CFGGraphImpl && G){
  _move_graph(G, *this);
}

CFGGraphImpl& CFGGraphImpl::operator=(const CFGGraphImpl& G){
  _copy_graph(G, *this);
  return *this;
}

CFGGraphImpl& CFGGraphImpl::operator=(CFGGraphImpl&& G){
  _move_graph(G, *this);
  return *this;
}

class CFGUtilImpl{
  friend class CFGUtil;

public:
  CFGUtilImpl();
  ~CFGUtilImpl();
  CFGNode* alloc_new_node(CFGType type);
  void scan_func();
  void build_func_nodes();
  void build_block_nodes();
  void build_node_links();  
  std::vector<CFGNode*> _clone_cfg_nodes(const std::vector<CFGNode*>& nodes);


private:
  std::vector<CFGNode*>           node_pool;
  std::vector<CFGGraphImpl>       graph_list;
  CFGGraphImpl*                   root_graph;
  std::map<BasicBlock*, CFGNode*> block_block_map;
  std::map<std::string, CFGNode*> block_name_map;
  int node_next_index = 0;
  Function* F;
};

CFGUtilImpl::CFGUtilImpl(){
  graph_list.push_back(CFGGraphImpl());
  root_graph = &graph_list[0];
}

CFGUtilImpl::~CFGUtilImpl(){
  for(CFGNode* node : node_pool){
    if(node)
      delete node;
  }
}

std::vector<CFGNode*> CFGUtilImpl::_clone_cfg_nodes(const std::vector<CFGNode*>& old_nodes){
  std::map<CFGNode*, CFGNode*> old_new_map;
  std::map<CFGNode*, CFGNode*> new_old_map;
  
  std::vector<CFGNode*> new_node_list;
  for(CFGNode* old_node : old_nodes){
    assert(old_node->index != -1 && "Can't clone invalid node!");
    CFGNode* new_node = alloc_new_node(old_node->type);
    int new_index = new_node->index;

    _copy(*old_node, *new_node);
    new_node->index = new_index;
    new_node->jump_from_nodes.clear();
    new_node->jump_to_nodes.clear();
 
    new_node_list.push_back(new_node);
    old_new_map[old_node] = new_node;
    new_old_map[new_node] = old_node;
  }

  for(CFGNode* new_node : new_node_list){     
    //errs() << "clone: before" << lfc::to_string(new_node) << "\n";
    CFGNode* old_node  = new_old_map[new_node];

    for(auto old_from_node : old_node->jump_from_nodes){
      if(auto it = old_new_map.find(old_from_node); it != old_new_map.end()){
        CFGNode* new_from_node = it->second;
        new_node->jump_from_nodes.push_back(new_from_node);
      }
    }

    for(auto old_to_node : old_node->jump_to_nodes){
      if(auto it = old_new_map.find(old_to_node); it != old_new_map.end()){
        CFGNode* new_to_node = it->second;
        new_node->jump_to_nodes.push_back(new_to_node);
      }
    }
  }

  return new_node_list;
}

CFGNode* CFGUtilImpl::alloc_new_node(CFGType type){
  CFGNode* new_node = new CFGNode();
  new_node->index = node_next_index++;
  new_node->type   = type;
  node_pool.push_back(new_node);
  return new_node;
}


void CFGUtilImpl::build_block_nodes(){
  LFC_TRACE1("build_block_nodes:");
  for(BasicBlock& B : *F){

    CFGNode* node = alloc_new_node(CFGType::BLOCK0);
    assert(node);
    
    node->block = &B;
    node->block_name  = lfc::get_llvm_block_name(&B);
    
    LFC_TRACE2("New block node: ", lfc::to_string(node));

    for(Instruction& I : B){
      // %323 = icmp eq i32 %322, 0
      // br i1 %323, label %324, label %325    
      if(BranchInst* brInst = dyn_cast<BranchInst>(&I); brInst){
        if(brInst->isConditional()){
          // Instruction* condInst   = dyn_cast<Instruction>(brInst->getCondition());
          node->type = CFGType::BLOCK2;
          node->block_end_inst       = brInst;
          // node->jump_cmp_inst     = dyn_cast<ICmpInst>(condInst);
          // assert(node->jump_cmp_inst);
          break;
        } 
        else if(brInst->isUnconditional()){
          node->type = CFGType::BLOCK1;
          node->block_end_inst      = brInst;
          break;
        }

      }
      else if(SwitchInst* swInst = dyn_cast<SwitchInst>(&I); swInst){
        node->type = CFGType::BLOCK3;
        node->block_end_inst = swInst;
        break;
      }
      else if(ReturnInst* rtInst = dyn_cast<ReturnInst>(&I); rtInst){
        node->type = CFGType::BLOCK0;
        node->block_end_inst = rtInst;
        break;
      }
    }
    
    root_graph->all_nodes.push_back(node);
    block_block_map[&B] = node;
    block_name_map[node->block_name] = node;
  }
}

void CFGUtilImpl::build_node_links(){
  LFC_TRACE1("build_node_links:");

  for(auto& node : root_graph->all_nodes){
    switch (node->type)
    {
    case CFGType::BLOCK1:     
      {
        BranchInst* b1_br = dyn_cast<BranchInst>(node->block_end_inst);
        assert(b1_br);
        link_cfg_node(node, block_block_map[b1_br->getSuccessor(0)]);
      }
      break;

    case CFGType::BLOCK2:
      {
        BranchInst* b2_br = dyn_cast<BranchInst>(node->block_end_inst);
        assert(b2_br);
        link_cfg_node(node, block_block_map[b2_br->getSuccessor(0)]);  // true
        link_cfg_node(node, block_block_map[b2_br->getSuccessor(1)]);  // false
      }
      break;

    case CFGType::BLOCK3:
      {
        SwitchInst* b3_sw = dyn_cast<SwitchInst>(node->block_end_inst);
        assert(b3_sw);

        for(auto caseIt : b3_sw->cases()){
          // errs() << caseIt.getCaseIndex() << "\n";
          // errs() << *caseIt.getCaseValue() << "\n";
          // errs() << get_llvm_block_name(caseIt.getCaseSuccessor()) << "\n";

          link_cfg_node(node, block_block_map[caseIt.getCaseSuccessor()]);
          ConstantInt* caseValue = caseIt.getCaseValue();
          node->switch_values.push_back(caseValue->getSExtValue());
        }

        // errs() << get_llvm_block_name(node->switch_inst->getDefaultDest())  << "\n";
        link_cfg_node(node, block_block_map[b3_sw->getDefaultDest()]);
      }
      break;

    default:
      break;
    }
  }
}

void link_cfg_node(CFGNode* from, CFGNode* to){
  assert(from);
  assert(to);
  from->jump_to_nodes.push_back(to);
  to->jump_from_nodes.push_back(from);
}

void CFGUtilImpl::scan_func(){
  LFC_TRACE3("************** scan func: ", F->getName().str() , "**************");
  
  build_block_nodes();
  build_node_links();
}


void CFGUtil::init(Function* F){
  if(impl != NULL)
    delete impl;
  impl = new CFGUtilImpl();
  impl->root_graph->util = this;
  impl->F = F;
  impl->scan_func();
  
  bool rc = verify_cfg_graph( impl->root_graph->all_nodes
                            , &impl->root_graph->begin_node
                            , &impl->root_graph->end_nodes
                            );
  
  if(!rc && LFC_TRACE_ENABLE){
    LFC_TRACE1("invalid cfg graph:");
    for(auto node : impl->root_graph->all_nodes){
      LFC_TRACE_STREAM << lfc::to_string(node) << "\n";
    }
  }

  assert(rc && "invalid cfg graph");
}

CFGUtil::~CFGUtil(){
  if(impl != NULL)
    delete impl;
}

CFGGraph* CFGUtil::get_cfg_root_graph(){
  return impl->root_graph;
}

std::string to_string(CFGType type){
  switch (type)
  {
  case CFGType::BLOCK0   : return "B0";
  case CFGType::BLOCK1   : return "B1";
  case CFGType::BLOCK2   : return "B2";
  case CFGType::BLOCK3   : return "B3";
  default:                 return "BX";
  }
}

CFGNode* CFGUtil::find_cfg_node(std::string block_name){
  auto it = impl->block_name_map.find(block_name);
  if(it == impl->block_name_map.end())
    return NULL;

  return it->second;
}

std::vector<CFGNode*> CFGUtil::clone_cfg_nodes(const std::vector<CFGNode*>& nodes){
  return impl->_clone_cfg_nodes(nodes);
}


std::vector<CFGNode*> CFGUtil::get_cfg_sub_nodes(CFGNode* begin, CFGNode* end){
  std::string end_name = end == NULL ? "" : end->block_name;
  LFC_TRACE4("get_cfg_sub_nodes: begin=", begin->block_name, ", end=", end_name);

  std::vector<CFGNode*> all_block_nodes;

  visit_cfg_graph(begin, end, [&](auto node){
    all_block_nodes.push_back(node);
    return false;
  });
 
  std::sort(all_block_nodes.begin(), all_block_nodes.end(), 
    [](CFGNode* a, CFGNode* b){return a->index < b->index;});

  return all_block_nodes;
}

std::vector<CFGNode*> CFGUtil::get_cfg_continuous_nodes(CFGNode* begin, CFGNode* end){
  return {};
}

bool has_call_in_cfg_node(const CFGNode* node){
  for(auto& I : *node->block){
    if(I.getOpcode() == Instruction::Call){
      return true;
    }
  }
  
  return false;
}

CFGGraph* CFGUtil::create_cfg_sub_graph(const std::vector<CFGNode*>& nodes){

  CFGNode *begin_node = NULL;
  std::vector<CFGNode*> end_nodes;

  bool rc = verify_cfg_graph(nodes, &begin_node, &end_nodes);
  if(!rc && LFC_TRACE_ENABLE){
    LFC_TRACE1("invalid cfg graph:");
    for(auto node : nodes){
      LFC_TRACE_STREAM << lfc::to_string(node) << "\n";
    }
  }

  assert(rc && "invalid cfg graph");

  impl->graph_list.push_back(CFGGraphImpl());
  CFGGraphImpl* new_graph = &impl->graph_list.back();

  new_graph->begin_node = begin_node;
  new_graph->end_nodes  = end_nodes;
  new_graph->all_nodes  = nodes;
  new_graph->util       = this;

  return new_graph;
}

static std::string _to_string(CFGNode* node){
  if(node == NULL){
    return "null";
  }

  std::string out = std::to_string(node->index);
  out += ":";
  out += lfc::get_llvm_block_name(node->block);

  return out;
}

static std::string _to_string(const std::vector<CFGNode*>& nodes){
  std::vector<std::string> node_lines;
  for(auto node : nodes){
    node_lines.push_back(_to_string(node));
  }
  return lfc::to_string(node_lines);
}

CFGNode* get_cfg_child_at(CFGNode* node, int idx){
  assert(node);
  assert(idx >= 0);
  assert(idx != 0 || node->type == CFGType::BLOCK1 || node->type == CFGType::BLOCK2 || node->type == CFGType::BLOCK3);
  assert(idx != 1 || node->type == CFGType::BLOCK2 || node->type == CFGType::BLOCK3);
  assert(idx <= 1 || node->type == CFGType::BLOCK3);
  assert(node->jump_to_nodes.size() > idx);
  auto* child = node->jump_to_nodes[idx];
  assert(child);
  return child;
}

bool CFGUtil::verify_cfg_graph(const std::vector<CFGNode*>& nodes, CFGNode** begin, std::vector<CFGNode*>* end){

  // empty graph
  if(nodes.empty()){
    if(begin != NULL){
      *begin = NULL;
    }
    if(end != NULL){
      end->clear();
    }
    return true;
  }

  std::set<CFGNode*> node_set = to_set(nodes);
  if(node_set.size() != nodes.size()){
    LFC_TRACE4("duplicated node found: total=", nodes.size(), ", actual=", node_set.size());
    return false;
  }

  CFGNode* begin_node = NULL;
  std::vector<CFGNode*> end_nodes;
  int begin_count = 0;
  
  /*********************************************************/
  // Check every node
  /*********************************************************/
  for(auto node : nodes){

    if(node == NULL){
      LFC_TRACE1("null node found");
      return false;
    }

    /*********************************************************/
    // Check begin node
    /*********************************************************/
    if(node->jump_from_nodes.empty()){
      if(begin_count++ > 0){
        LFC_TRACE1("multi begin cfg-node found");
        return false;
      }
      begin_node = node;
    }   

    /*********************************************************/
    // Check end node
    /*********************************************************/
    if(node->jump_to_nodes.empty()){
      // #TODO check ret inst?
      end_nodes.push_back(node); 
    }

    /*********************************************************/
    // Check jump_from_node exist
    /*********************************************************/
    for(auto from : node->jump_from_nodes){
      if(from == NULL){
        LFC_TRACE1("null jump_from_node found");
        return false;
      }
      if(node_set.count(from) == 0){
        LFC_TRACE2("jump_from_node not found: ", lfc::to_string(from));
        return false;
      }
    }

    /*********************************************************/
    // Check jump_to_node exist
    /*********************************************************/
    for(auto to : node->jump_to_nodes){
      if(to == NULL){
        LFC_TRACE1("null jump_to_node found");
        return false;
      }
      if(node_set.count(to) == 0){
        LFC_TRACE2("jump_to_node not found: ", lfc::to_string(to));
        return false;
      }
    }

  }

  /*********************************************************/
  // There should 1 root and 1 end node
  /*********************************************************/
  if(begin_node == NULL){
    LFC_TRACE1("begin node not found");
    return false;
  }

  // if(end_node == NULL){
  //   LFC_TRACE1("end node not found");
  //   return false;
  // }

  int visit_count = visit_cfg_graph(begin_node, NULL, [](auto node){
    return false;
  });

  if(visit_count != nodes.size()){
    LFC_TRACE4("incompleted graph: total=", nodes.size(), ", visit=", visit_count);
    return false;
  }

  if(begin != NULL){
    *begin = begin_node;
  }

  if(end != NULL){
    *end = end_nodes;
  }
  
  return true;
}

int visit_cfg_graph(CFGNode* begin, CFGNode* end, function<bool(CFGNode*)> func){

  std::vector<CFGNode*> input_nodes = {begin};

  return visit_graph_bfs(input_nodes
    , [&](CFGNode* node){
        if(node == end)
          return false;
        return func(node);
      }
    , [&](CFGNode* node)->std::vector<CFGNode*>{
        if(node == end)
          return {};
        return node->jump_to_nodes;
      }
    , true
  );

}

int visit_cfg_graph(CFGGraph* graph, function<bool(CFGNode*)> func){
  return visit_cfg_graph(graph->get_begin_node(), NULL, func);
}


bool has_loop_in_cfg_graph(CFGGraph* graph){ 
  return has_loop_in_graph(graph->get_all_nodes(), [](CFGNode* node){
    return node->jump_to_nodes;
  });
}

bool has_multi_branch_in_cfg_graph(CFGGraph* graph){
  for(auto node : graph->get_all_nodes()){
    if(node->jump_to_nodes.size() > 1){
      return true;
    }
  }
  return false;
}


simple_graph make_link_simple_graph(CFGGraph* graph, std::map<CFGNode*, int>* index_map){
  int size = graph->get_all_nodes().size();

  simple_graph SG(size);
  std::map<CFGNode*, int> _map;

  int index = 0;
  for(auto N : graph->get_all_nodes()){
    _map[N] = index++;
  }

  index = 0;
  for(auto& N : graph->get_all_nodes()){
    auto& vec = SG[index];
    for(auto& M : N->jump_to_nodes){
      vec.push_back(_map[M]);
    }
    std::sort(vec.begin(), vec.end(), std::less<>());
    index++;  
  }

  if(index_map != NULL){
    *index_map = std::move(_map);
  }

  return std::move(SG);
}


LFC_TO_STRING_IMPL(CFGNode, N){
  if( !N )
    return "CN(null)";

  std::string out = "CN(";

  out += "index=";
  out += lfc::to_string(N->index);

  out += ", type=";
  out += lfc::to_string(N->type);

  if( N->inst != NULL){
    out += ", inst=";
    out += lfc::get_llvm_inst_info(N->inst);
  }    

  out += ", block=";
  out += N->block_name;
  if( N->block == NULL)
    out += ":null";

  out += ", end=";
  if(N->block_end_inst == NULL)
    out += "null";
  else
    out += lfc::get_llvm_inst_info(N->block_end_inst);

  // out += ", switch=";
  // if(N->switch_inst == NULL)
  //   out += "null";
  // else
  //   out += lfc::get_llvm_value_name(N->switch_inst);

  out += ", from=";
  out += _to_string(N->jump_from_nodes);

  out += ", to=";
  out += _to_string(N->jump_to_nodes);

  out += ", switch=";
  out += lfc::to_string(N->switch_values);

  out += ")";

  return out;
}

LFC_TO_STRING_IMPL(CFGGraph, G){
  if( !G )
    return "CG(null)";

  std::string out = "CG(";

  out += "begin=";
  out += _to_string(G->get_begin_node());

  out += ", end=";
  out += _to_string(G->get_end_nodes());

  out += ", nodes=";
  out += _to_string(G->get_all_nodes());

  out += ")";

  return out;
}

std::vector<llvm::BasicBlock*> to_llvm_blocks(std::vector<CFGNode*> nodes){
  std::vector<llvm::BasicBlock*> blocks;
  std::for_each(nodes.begin(), nodes.end(), [&blocks](auto& node){
    blocks.push_back(node->block);
  });
  return blocks;
}


}// namespace lfc 