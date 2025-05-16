// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[dfg_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(dfg_util)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(dfg_util)
#include "lfc/base/abi.h"
#include "lfc/base/graph/graph_visit.h"
#include "lfc/llvm/dfg.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
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

using namespace llvm;

namespace lfc {

static int DFG_INST_DEF[10][5] = {
  {0, -1, -1, 0, 0}, // OTHER
  {0, -1, -1, 0, 0}, // ARG
  {0,  0, -1, 0, 0}, // LOAD
  {1,  0,  1, 0, 0}, // STORE
  {0, -1, -1, 0, 0}, // CALL
  {1,  0, -1, 0, 0}, // RET
  {0, -1, -1, 1, 0}, // ALLOCA
  {0,  0, -1, 0, 0}, // CAST
  {0, -2,  0, 0, 0}, // MOP
  {0,  0,  0, 0, 0}, // IGNORE
};

#define type_index_of(n)    (int)(*(n)).get_type()

#define is_void_return(n)  (DFG_INST_DEF[type_index_of(n)][0] == 1)
#define get_src1_index(n)  (DFG_INST_DEF[type_index_of(n)][1])
#define has_multi_input(n) (DFG_INST_DEF[type_index_of(n)][1] == -2)
#define get_dst1_index(n)  (DFG_INST_DEF[type_index_of(n)][2])
#define is_ignore_type(n)  (DFG_INST_DEF[type_index_of(n)][3] == 1)

static DFGType get_inst_type(Instruction* I){
  assert(I);
  switch (I->getOpcode()){
  case Instruction::Store         : return DFGType::STORE; 
  case Instruction::Call          : return DFGType::CALL;  
  case Instruction::Load          : return DFGType::LOAD;
  case Instruction::Ret           : return DFGType::RET;
  case Instruction::Alloca        : return DFGType::ALLOCA;
  case Instruction::BitCast       :
  case Instruction::SExt          :
  case Instruction::IntToPtr      :
  case Instruction::PtrToInt      : return DFGType::CAST;
  case Instruction::Add           :
  case Instruction::SDiv          :
  case Instruction::Mul           :
  case Instruction::ExtractValue  :
  case Instruction::GetElementPtr : return DFGType::MOP;
  case Instruction::Br            : return DFGType::IGNORE;
  default: break;
  }
  return DFGType::OTHER;
}

void DFGNode::_copy_dfg_node(const DFGNode& A, DFGNode& B){
    B.index       = A.index;
    B.inst        = A.inst;
    B.block       = A.block;
    B.var_name    = A.var_name;
    B.inst_name   = A.inst_name;
    B.call_name   = A.call_name;
    B.type        = A.type;  
    B.depend_on_nodes.clear();
    B.depend_by_nodes.clear();
    std::copy(A.depend_on_nodes.begin(), A.depend_on_nodes.end(), std::back_inserter(B.depend_on_nodes));
    std::copy(A.depend_by_nodes.begin(), A.depend_by_nodes.end(), std::back_inserter(B.depend_by_nodes));
    std::copy(A.operand_list.begin(), A.operand_list.end(), std::back_inserter(B.operand_list));
    std::copy(A.call_opd_nodes.begin(), A.call_opd_nodes.end(), std::back_inserter(B.call_opd_nodes));
}

void DFGNode::_move_dfg_node(DFGNode& A, DFGNode& B){
    B.index       = A.index;
    B.inst        = A.inst;
    B.block       = A.block;
    B.var_name    = A.var_name;
    B.inst_name   = A.inst_name;
    B.call_name   = A.call_name;
    B.type        = A.type;
    B.depend_on_nodes = std::move(A.depend_on_nodes);
    B.depend_by_nodes = std::move(A.depend_by_nodes);
    B.operand_list    = std::move(A.operand_list);
    B.call_opd_nodes  = std::move(A.call_opd_nodes);
}

DFGNode::DFGNode(){
  index     = -1;
  inst      = NULL;
  block     = NULL;
  type      = DFGType::OTHER;
}

DFGNode::DFGNode(DFGType type){
  index       = -1;
  inst        = NULL;
  block       = NULL;
  this->type  = type;
}

DFGNode::DFGNode(const DFGNode& N){
  _copy_dfg_node(N, *this);
}

DFGNode::DFGNode(DFGNode && N){
  _move_dfg_node(N, *this);
}

DFGNode& DFGNode::operator=(const DFGNode& N){
  _copy_dfg_node(N, *this);
  return *this;
}

DFGNode& DFGNode::operator=(DFGNode&& N){
  _move_dfg_node(N, *this);
  return *this;
}

static int _index_of(const std::vector<DFGNode*>& node_list, DFGNode* node){
  int index = node_list.size() - 1;
  while( index>= 0 && node_list[index] != node )
    --index;
  return index;
}

void DFGNode::add_depend_on_node(DFGNode* node){
  assert(node != NULL);
  LFC_TRACE4("add_depend_on_node: this=", this->index, ", target=", node->index);
  int index = _index_of(depend_on_nodes, node);
  if(index >= 0){
    LFC_TRACE2("already in depend_on_list: ", lfc::to_string(node));
    return;
  }
  depend_on_nodes.push_back(node);
  node->depend_by_nodes.push_back(this);
}

void DFGNode::remove_depend_on_node(DFGNode* node){
  assert(node != NULL);
  LFC_TRACE4("remove_depend_on_node: this=", this->index, ", target=", node->index);
  int dpdon_index = _index_of(depend_on_nodes, node);
  if(dpdon_index < 0){
    LFC_TRACE2("not in depend_on_list: ", lfc::to_string(node));
    return;
  }

  int dpdby_index = _index_of(node->depend_by_nodes, this);
  if(dpdby_index < 0){
    LFC_TRACE2("dpdby info incorrect: ", lfc::to_string(node));
    assert(dpdby_index >= 0 && "dpdby info incorrect"); 
  }

  depend_on_nodes.erase(depend_on_nodes.begin() + dpdon_index);
  node->depend_by_nodes.erase(node->depend_by_nodes.begin() + dpdby_index);
}

bool DFGNode::has_depend_on_node(DFGNode* node) const{
  return _index_of(depend_on_nodes, node) >= 0;
}

bool DFGNode::has_no_depend_on_node() const{
  return depend_on_nodes.empty();
}

bool DFGNode::has_no_depend_by_node() const{
  return depend_by_nodes.empty();
}

std::vector<DFGNode*> DFGNode::get_depend_on_nodes() const{
  return depend_on_nodes;
}

std::vector<DFGNode*> DFGNode::get_depend_by_nodes() const {
  return depend_by_nodes;
}

int DFGNode::get_operand_count() const {
  return operand_list.size();
}

std::string DFGNode::get_operand(int index) const {
  return operand_list[index];
}

DFGNode* DFGNode::get_call_operand_node(int index) const {
  return call_opd_nodes[index];
}

bool DFGNode::is_removed() const {
  return index < 0;
}

void DFGNode::remove_node(){
  LFC_TRACE2("remove_node: ", lfc::to_string(this));
  assert(depend_on_nodes.empty());
  // if(!depend_by_nodes.empty()){
  //   errs() << lfc::to_string(this) << "\n";
  // }
  assert(depend_by_nodes.empty());

  index = -1;
}

std::vector<DFGNode*> DFGNode::get_all_depend_on_nodes(const std::vector<DFGNode*>& nodes){
  LFC_TRACE1("get_all_depend_on_nodes:");

  std::set<DFGNode*> input_nodes;
  std::for_each(nodes.begin(), nodes.end(), [&](auto node){input_nodes.insert(node);});

  std::vector<DFGNode*> find_nodes;
  visit_graph_bfs(nodes, 
    [&](DFGNode* node){
      find_nodes.push_back(node);
      return false;
    }, 
    [](DFGNode* node){
      return node->depend_on_nodes;
    }
  );

  sort_dfg_nodes(find_nodes);
  return find_nodes;
}

std::vector<DFGNode*> DFGNode::get_all_depend_by_nodes(const std::vector<DFGNode*>& nodes){
  LFC_TRACE1("get_all_depend_by_nodes:");

  std::set<DFGNode*> input_nodes;
  std::for_each(nodes.begin(), nodes.end(), [&](auto node){input_nodes.insert(node);});

  std::vector<DFGNode*> find_nodes;
  visit_graph_bfs(nodes, 
    [&](DFGNode* node){
      find_nodes.push_back(node);
      return false;
    },
    [](DFGNode* node){
      return node->depend_by_nodes;
    }
  );

  sort_dfg_nodes(find_nodes);
  return find_nodes;
}

std::vector<DFGNode*> DFGNode::get_dfg_nodes(const std::vector<DFGNode*>& nodes, DFGType type){
  std::vector<DFGNode*> new_nodes;
  std::for_each(nodes.begin(), nodes.end(), [&new_nodes, &type](auto node){
    if(node->get_type() == type)
      new_nodes.push_back(node);
  });
  return new_nodes;
}

void DFGNode::remove_unused_dfg_nodes(std::vector<DFGNode*>& nodes){
  LFC_TRACE1("remove_unused_dfg_nodes: ");
  
  for(DFGNode* node : nodes){
    LFC_TRACE1(lfc::to_string(node));
  }

  std::queue<DFGNode*> check_queue;

  for(DFGNode* node : nodes){
    if(node->depend_by_nodes.size() == 0){
      check_queue.push(node);
    }
  }

  int update = 0;

  while(!check_queue.empty()){
    DFGNode* node = check_queue.front();
    check_queue.pop();
    if(node == NULL || node->is_removed())
      continue;
    
    if(node->get_type() != DFGType::LOAD && node->get_type() != DFGType::STORE)
      continue;

    LFC_TRACE2("Remove node: ", lfc::to_string(node));
    for(DFGNode* dpdon_node : node->get_depend_on_nodes()){
      if(dpdon_node != NULL){
        node->remove_depend_on_node(dpdon_node);
        if( dpdon_node->depend_by_nodes.size() == 0){
          check_queue.push(dpdon_node);
        }
      }
    }

    node->remove_node();
    ++update;
  }

  if(update == 0)
    return;

  auto it = nodes.begin();
  while( it != nodes.end()){
    if( (*it)->is_removed() )
      it = nodes.erase(it);
    else
      ++it;
  }
}

void DFGNode::sort_dfg_nodes(std::vector<DFGNode*>& nodes){
  std::sort(nodes.begin(), nodes.end(), 
    [](DFGNode* a, DFGNode* b){return a->index < b->index;});
}

std::string to_string(DFGType type){
  switch (type)
  {
  case DFGType::OTHER  : return "OTHER";
  case DFGType::ARG    : return "ARG";
  case DFGType::LOAD   : return "LOAD";
  case DFGType::STORE  : return "STORE";
  case DFGType::CALL   : return "CALL";     
  case DFGType::RET    : return "RET";
  case DFGType::ALLOCA : return "ALLOCA";
  case DFGType::CAST   : return "CAST";
  case DFGType::MOP    : return "MOP";
  default:      return "BAD";
  }
}

LFC_TO_STRING_IMPL(DFGNode, N){
  if( !N )
    return "DFGNode(null)";

  std::string out = "DFGNode(";

  out += "index=";
  out += lfc::to_string(N->index);

  out += ", type=";
  out += lfc::to_string(N->type);

  out += ", var_name=";
  out += N->var_name;

  out += ", inst_name=";
  out += N->inst_name;

  out += ", operand=";
  out += lfc::to_string(N->operand_list);

  out += ", dpdon={";
  {
    int idx = 0;
    for(DFGNode* DN : N->depend_on_nodes){
      if(idx ++ != 0)
        out +=",";
      if(DN == NULL)
        out += "null";
      else{
        out += std::to_string(DN->index);
      }
    }
    out +="}";
  }

  out += ", dpdby={";
  {
    int idx = 0;
    for(DFGNode* DN : N->depend_by_nodes){
      if(idx ++ != 0)
        out +=",";
      if(DN == NULL)
        out += "null";
      else{
        out += std::to_string(DN->index);
      }
    }
    out +="}";
  }

  if(N->type == DFGType::CALL){
    out += ", call_name=";
    out += N->call_name;
    int idx = 0;
     out += ", opd={";
    for(DFGNode* OPN : N->call_opd_nodes){
      if(idx ++ != 0)
        out +=",";
      if( OPN == NULL ) 
        out +="-1";
      else
        out += std::to_string(OPN->index);
    }
    out +="}";
  }


  out += ")";

  return out;
}

class DFGUtilImpl{
  friend class DFGUtil;

public:
  ~DFGUtilImpl();
  DFGNode* alloc_new_node(DFGType type);
  void scan_inst();
  void build_arg_nodes();
  void build_inst_nodes();
  void build_depend_indexs();
  std::vector<std::string> get_all_vars();
  std::vector<DFGNode*> _clone_dfg_graph(const std::vector<DFGNode*>& nodes);


private:
  std::vector<DFGNode*>            node_pool;
  std::vector<DFGNode*>            all_nodes;
  std::map<std::string, DFGNode*>  var_node_map;
  std::map<Instruction*, DFGNode*> inst_node_map;
  int node_next_index = 0;
  Function* F;
};

DFGUtilImpl::~DFGUtilImpl(){
  for(DFGNode* node : node_pool){
    if(node)
      delete node;
  }
}

DFGNode* DFGUtilImpl::alloc_new_node(DFGType type){
  DFGNode* new_node = new DFGNode(type);
  new_node->set_index(node_next_index++);
  node_pool.push_back(new_node);
  return new_node;
}

void DFGUtilImpl::build_arg_nodes(){
  LFC_TRACE1("Build argument nodes:");
  int arg_size = F->arg_size();
  for(int i = 0; i < arg_size; ++i){
    Argument* arg = F->getArg(i);
    DFGNode* node = alloc_new_node(DFGType::ARG);
    node->set_var_name(get_llvm_value_name(arg));
    node->set_inst_name("argument");
    LFC_TRACE2("New arg node: ", lfc::to_string(node));
    all_nodes.push_back(node);
  }
}

void DFGUtilImpl::build_inst_nodes(){
  LFC_TRACE1("Build instruction nodes:");
  for(BasicBlock& B : *F){  
    for(Instruction& I : B){
      LFC_TRACE2("input inst : ", I);
      DFGType type = get_inst_type(&I);
      if(type == DFGType::IGNORE)
        continue;

      CallInst* CI = NULL; 
      std::string callName = "";
      if(isa<CallInst>(I)){
        CI = dyn_cast<CallInst>(&I);
        callName = get_llvm_call_name(CI);
        if(is_llvm_intrinsic(callName)){
          continue;
        }        
      }

      DFGNode *node = alloc_new_node(type);
      node->set_inst(&I);
      node->set_block(&B);
      node->set_inst_name(I.getOpcodeName());
      node->set_call_name(demangle_func_name(callName));

      if (is_void_return(node) || (CI != NULL && CI->getType()->isVoidTy()) ) {
        node->set_var_name("");
      }
      else{
        node->set_var_name(get_llvm_value_name(&I));
      }

      LFC_TRACE2("output node: ", lfc::to_string(node));
      all_nodes.push_back(node);
    }
  }
}

void DFGUtilImpl::build_depend_indexs(){
  LFC_TRACE1("Build depend_indexs:");
 
  std::map<std::string, DFGNode*> latest_node_map;
  BasicBlock* last_block = NULL;

#define LATEST_NODE(var) \
  (latest_node_map.count((var)) == 0 ? \
      NULL : latest_node_map[(var)])

#define LINK_NODE(from_node, to_node)\
  if( (from_node) != NULL && (to_node != NULL)) {\
    (to_node)->add_depend_on_node(from_node); \
  }

  for(DFGNode* node : all_nodes){
    LFC_TRACE2("Scan node: ",lfc::to_string(node));
    // #TODO how about if/loop?
    // if(last_block != node.block){
    //   LFC_TRACE1("New Block:");
    //   latest_index_map.clear();
    // }
    // last_block = node.block;

    llvm::Instruction* inst = node->get_inst();
    unsigned int num_operands = inst == NULL ? 0 : inst->getNumOperands();
    if(node->get_type() == DFGType::RET && num_operands == 0){
      continue;
    }

    for(unsigned int r = 0; r < num_operands; r++){
      Value* opd = inst->getOperand(r);
      std::string opd_var = get_llvm_value_name(opd);
      node->operand_list.push_back(opd_var);
    }

    // call inst
    if(node->type == DFGType::CALL){
      CallInst* CI = dyn_cast<CallInst>(node->inst);
      assert(CI);

      num_operands--;
      node->call_opd_nodes.resize(num_operands);

      for(unsigned int r = 0; r < num_operands; r++){
        std::string opd_var = node->operand_list[r];
        if(is_llvm_ir_var(opd_var)){
          DFGNode* src_node = LATEST_NODE(opd_var);
          LINK_NODE(src_node, node);
          if( src_node != NULL ){
            node->call_opd_nodes[r] = src_node;
          }
        }
      }

      // have return value
      if(!CI->getType()->isVoidTy()){
        std::string dst_var = node->var_name;
        LFC_TRACE4("Update latest_index_map: var=", dst_var, ", index=", node->index);
        latest_node_map[dst_var] = node;
      }
    }
    // other inst
    else{
      if( !is_void_return(node)){
        LFC_TRACE4("Update latest_index_map: var=\"", node->var_name, "\", index=", node->index);
        latest_node_map[node->var_name] = node;
      }

      if(has_multi_input(node)){
        for(unsigned int r = 0; r < num_operands; r++){
          Value* opd = node->inst->getOperand(r);
          std::string opd_var = get_llvm_value_name(opd);
          if(is_llvm_ir_var(opd_var)){
            DFGNode* src_node = LATEST_NODE(opd_var);
            LINK_NODE(src_node, node);
          }
        }
      }
      else {
        int src1_index = get_src1_index(node);
        LFC_TRACE2("src1_index=", src1_index);
        if(src1_index  >=0 && src1_index < num_operands){
          Value* src_val = node->inst->getOperand(src1_index);
          std::string src_var = get_llvm_value_name(src_val);
          // LFC_TRACE3("src_var=\"", src_var,"\"");
          if(is_llvm_ir_var(src_var)){
            DFGNode* src_node = LATEST_NODE(src_var);
            // if(src_node != NULL)
            // {
            //   LFC_TRACE2("src_node=", src_node->index);
            // }
            // else
            //   {
            //     errs() << "not found\n";
            //     for(auto& it : latest_index_map)
            //        errs() << it.first << " " << it.second << "\n";
            //   }
            LINK_NODE(src_node, node);
          }
        }
      }   

      int dst1_index = get_dst1_index(node);
      LFC_TRACE2("dst1_index=", dst1_index);
      if(dst1_index != -1 && dst1_index < num_operands){
        Value* dst_val = node->inst->getOperand(dst1_index);
        std::string dst_var = get_llvm_value_name(dst_val);
        LFC_TRACE4("Update latest_index_map: var=", dst_var, ", index=", node->index);
        latest_node_map[dst_var] = node;
      }
    } 
  }
}

void DFGUtilImpl::scan_inst(){
  LFC_TRACE3("************** scan inst: ", F->getName().str() , "**************");
  build_arg_nodes();
  build_inst_nodes();
  for(DFGNode* N : all_nodes){
    if(!N->var_name.empty())
      var_node_map[N->var_name] = N;
    if( N->inst != NULL ){
      inst_node_map[N->inst] = N;
    }
  }
  
  build_depend_indexs();

  LFC_TRACE1("Print all nodes:");
  for(DFGNode* node : all_nodes){
    LFC_TRACE1(lfc::to_string(node));
  }
}

std::vector<std::string> DFGUtilImpl::get_all_vars(){
  std::vector<std::string> vars;
  std::for_each(var_node_map.begin(), var_node_map.end(), [&vars](auto it){vars.push_back(it.first);});
  std::sort(vars.begin(), vars.end());
  return vars;
}

void DFGUtil::init(Function* F){
  if(impl != NULL)
    delete impl;
  impl = new DFGUtilImpl();
  impl->F = F;
  impl->scan_inst();
}

DFGUtil::~DFGUtil(){
  if(impl != NULL)
    delete impl;
}

std::vector<std::string> DFGUtil::get_all_vars(){
  return impl->get_all_vars();
}

std::vector<DFGNode*> DFGUtil::get_all_dfg_nodes(){
  return impl->all_nodes;
}

DFGNode* DFGUtil::get_node_by_var(const std::string& var_name){
  auto it = impl->var_node_map.find(var_name);
  if(it == impl->var_node_map.end()){
    return NULL;
  }
  return it->second;
}

DFGNode* DFGUtil::get_node_by_inst(llvm::Instruction* I){
  auto it = impl->inst_node_map.find(I);
  if(it == impl->inst_node_map.end()){
    return NULL;
  }
  return it->second;
}

std::vector<std::string> DFGUtil::get_all_dfg_src_vars(const std::vector<DFGNode*>& nodes){
  LFC_TRACE2("get_all_dfg_src_vars: size=", nodes.size());

  std::vector<std::string> src_vars;
  for(DFGNode* node : nodes){
    if(node == NULL || !node->depend_on_nodes.empty())
      continue;

    if(node->type == DFGType::ARG || node->type == DFGType::ALLOCA){
      src_vars.push_back(node->var_name);
      continue;
    }

    if(node->type == DFGType::CALL && node->var_name != ""){
      src_vars.push_back(node->var_name);
      continue;  
    }

    if(node->type == DFGType::STORE){
      src_vars.push_back(node->operand_list[1]);
      continue;
    }

    if(has_multi_input(node)){
      int src_opd_count = 0;
      for(auto& src_var : node->operand_list){
        if(is_llvm_ir_var(src_var)){
          ++src_opd_count;
          src_vars.push_back(src_var);
        }
      }

      if(src_opd_count == 0){
        src_vars.push_back(node->var_name);
      }
        
    }
    else {
      int src1_index = get_src1_index(node);
      if(src1_index >=0 && src1_index < node->operand_list.size()){
        if(std::string src_var = node->operand_list[src1_index]; is_llvm_ir_var(src_var))
          src_vars.push_back(src_var);
      }
    }
  }

  std::sort(src_vars.begin(), src_vars.end());
  return src_vars;
}

std::vector<DFGNode*> DFGUtilImpl::_clone_dfg_graph(const std::vector<DFGNode*>& old_nodes){
  std::map<DFGNode*, DFGNode*> old_new_map;
  std::map<DFGNode*, DFGNode*> new_old_map;
  
  std::vector<DFGNode*> new_node_list;
  for(DFGNode* old_node : old_nodes){
    assert(old_node->index != -1 && "Can't clone invalid node!");
    DFGNode* new_node = alloc_new_node(old_node->type);
    int new_index = new_node->index;
    DFGNode::_copy_dfg_node(*old_node, *new_node);
    new_node->index = new_index;
    new_node->depend_on_nodes.clear();
    new_node->depend_by_nodes.clear();
    new_node_list.push_back(new_node);
    old_new_map[old_node] = new_node;
    new_old_map[new_node] = old_node;
  }

  for(DFGNode* new_node : new_node_list){     
    //errs() << "clone: before" << lfc::to_string(new_node) << "\n";
    DFGNode* old_node  = new_old_map[new_node];

    for(DFGNode* old_dp_node : old_node->depend_on_nodes){
      auto it = old_new_map.find(old_dp_node);
      if(it != old_new_map.end()){
        new_node->add_depend_on_node(it->second);
      }
    }
    
    int k = 0;
    for(DFGNode* old_call_node : old_node->call_opd_nodes){
      if(old_call_node == NULL){
        new_node->call_opd_nodes[k] = NULL;
      }
      else{
        if(auto it = old_new_map.find(old_call_node); it == old_new_map.end()){        
          new_node->call_opd_nodes[k] = NULL;
        }
        else{
          DFGNode* new_call_node = it->second;
          new_node->call_opd_nodes[k] = new_call_node;
        }
      }
      k++;
    }
    //errs() << "clone: after" << lfc::to_string(new_node) << "\n";
  }

  return new_node_list;
}



std::vector<DFGNode*> DFGUtil::simplify_link_node(const std::vector<DFGNode*>& nodes){
  LFC_TRACE1("simplify_link_node: ");

  std::vector<DFGNode*> clone_node_list = impl->_clone_dfg_graph(nodes);

  while(true){
  
    for(DFGNode* node : clone_node_list){
      int call_dep_update = 0;

      std::vector<DFGNode*> simple_node_list;
      for(DFGNode* dp_node : node->depend_on_nodes){
        if(dp_node->depend_by_nodes.size() == 1 && dp_node->depend_on_nodes.size() == 1){
          LFC_TRACE2("find simple node: ", lfc::to_string(dp_node));
          simple_node_list.push_back(dp_node);
        }
      }
      
      for(DFGNode* simple_node : simple_node_list){
        LFC_TRACE2("remove node: ", lfc::to_string(simple_node));
        DFGNode* previous_dpdon_node = simple_node->depend_on_nodes[0];

        node->remove_depend_on_node(simple_node);
        simple_node->remove_depend_on_node(previous_dpdon_node);
        node->add_depend_on_node(previous_dpdon_node);

        if(simple_node->has_no_depend_by_node()){
          simple_node->remove_node();
        }
   
        if(node->type == DFGType::CALL){

          ++call_dep_update;

          int r = 0;
          for(DFGNode* &  call_dp_node : node->call_opd_nodes){
            if(call_dp_node == simple_node){
              std::string opd = previous_dpdon_node->var_name;
              if( previous_dpdon_node->type == DFGType::STORE){
                opd = previous_dpdon_node->operand_list[1];
              }
              call_dp_node = previous_dpdon_node;
              node->operand_list[r] = opd;
            }
            ++r;       
          }
        }
      }
      
    }

    break;

  }

  std::vector<DFGNode*> new_node_list ;
  for(DFGNode* node : clone_node_list){
    if(node->index !=-1)
      new_node_list.push_back(node);
  }

  return new_node_list; 
}

std::vector<DFGNode*> DFGUtil::clone_dfg_graph(const std::vector<DFGNode*>& nodes){
  return impl->_clone_dfg_graph(nodes);
}

std::vector<DFGNode*> DFGUtil::simplify_const_in_call(const std::vector<DFGNode*>& nodes){
  LFC_TRACE1("simplify_const_in_call: ");

  std::vector<DFGNode*> clone_node_list = impl->_clone_dfg_graph(nodes);
  std::map<DFGNode*, std::string> node_const_val_map;

  for(DFGNode* node : clone_node_list){
    if(!node->depend_on_nodes.empty() )
      continue;
    
    if(node->type == DFGType::STORE && !is_llvm_ir_var(node->operand_list[0])){
      LFC_TRACE2("find store-const node: ", lfc::to_string(node));
      node_const_val_map[node] = node->operand_list[0];
    }
  }

  std::set<DFGNode*> node_call_const_set;
  for(DFGNode* node : clone_node_list){
    if(node->type == DFGType::CALL){
      int const_dep_count = 0;
  
      for(DFGNode* dp_node : node->get_depend_on_nodes()){
        if(node_const_val_map.find(dp_node) != node_const_val_map.end()){          
          node->remove_depend_on_node(dp_node);
          node_call_const_set.insert(dp_node);
          if(dp_node->has_no_depend_by_node()){
            dp_node->remove_node();
          }
          const_dep_count++;
        }
      }

      if(const_dep_count > 0){
        LFC_TRACE2("find call const node: ", lfc::to_string(node));
        unsigned int num_operands = node->operand_list.size() - 1;
        for(unsigned int r = 0; r < num_operands; r++){ 
          DFGNode* call_node = node->call_opd_nodes[r];
          if(call_node != NULL && node_const_val_map.find(call_node) != node_const_val_map.end()){
            node->operand_list[r] = node_const_val_map[call_node];
            node->call_opd_nodes[r] = NULL;
          }
        }
      }
    }
  }

  std::vector<DFGNode*> new_node_list ;
  for(DFGNode* node : clone_node_list){
    if(node->index !=-1)
      new_node_list.push_back(node);
  }

  return new_node_list; 
}


} // namespace lfc