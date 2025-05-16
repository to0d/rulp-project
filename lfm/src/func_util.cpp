// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[func_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(func_util)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(func_util)
#include "lfc/llvm/llvm_util.h"
#include "lfc/llvm/func_util.h"
#include "lfc/base/dot.h"
#include "lfc/base/task.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include <queue>
#include <map>

using namespace llvm;

#define DOT_NODE_NAME_START "start"
#define DOT_NODE_NAME_END   "end"

namespace lfc {

class FuncUtilImpl {
  friend class FuncUtil;

public:
  void add_func_def_list(const std::vector<FuncDef>& fd_list);
  void add_dfg_func_list(const std::vector<dfg_select_func>& func_list);
  bool has_func_def(const std::string& func);
  std::vector<int> get_func_params(const std::string& func);
  std::vector<int> get_simd_func_out_params(const std::string& func);
  std::vector<std::string> build_ordered_var_list(std::vector<int> &param_index_list, FuncCall* FC);
  std::vector<std::string> build_dfg_var_list(std::vector<int> &param_index_list, FuncCall* FC);
  void update_function(Function* F);
  std::vector<DFGNode*> get_last_dfg_nodes();

private:
  std::map<std::string, FuncDef> func_dep_map;
  std::map<std::string, std::vector<int>> func_params_map;
  
  std::vector<dfg_select_func> dfg_func_list;
  std::vector<DFGNode*> last_dfg_nodes;
  DFGUtil   last_dfg_Util;
  Function* last_F = NULL;
  bool      last_dfg_update = false;
};

void FuncUtilImpl::add_func_def_list(const std::vector<FuncDef>& fd_list){
  for(auto& FD : fd_list){
    func_dep_map[FD.func_name] = FD;
  }
}

void FuncUtilImpl::add_dfg_func_list(const std::vector<dfg_select_func>& func_list){
  for(auto& F : func_list){
    dfg_func_list.push_back(F);
  }
}

bool FuncUtilImpl::has_func_def(const std::string& func) {
  return func_dep_map.find(func) != func_dep_map.end();
}

std::vector<int> FuncUtilImpl::get_func_params(const std::string& func){
  if( !has_func_def(func))
    return {};
  
  if(auto it = func_params_map.find(func); it != func_params_map.end()){
    return it->second;
  }

  FuncDef& AD = func_dep_map[func];
  std::vector<int> params  = AD.input_para_indexs;
  std::vector<int> out_params = AD.output_para_indexs;
  params.insert( params.end(), out_params.begin(), out_params.end());
  std::sort(params.begin(), params.end(), std::less<int>());
  func_params_map[func] = params;
  
  return params;
}

std::vector<int> FuncUtil::get_func_params(const std::string& func){
  return impl->get_func_params(func);
}

std::vector<int> FuncUtilImpl::get_simd_func_out_params(const std::string& func){
  if( !has_func_def(func))
    return {};
  return func_dep_map[func].output_para_indexs;
}

std::vector<std::string> FuncUtilImpl::build_ordered_var_list(std::vector<int> &param_index_list, FuncCall* FC){
  std::vector<std::string> var_name_list;

  for(int para_index : param_index_list){
    std::string para = FC->para_list[para_index];
    if( is_llvm_ir_var(para)){ 
      var_name_list.push_back(para);
    }
  }
  
  std::sort(var_name_list.begin(), var_name_list.end(), [](std::string a, std::string b){
    return get_llvm_var_index(a) > get_llvm_var_index(b);
  });

  return var_name_list;
}

std::vector<DFGNode*> FuncUtilImpl::get_last_dfg_nodes(){
  if(!last_dfg_update && last_F != NULL){

    LFC_TRACE2("update dfg nodes: Func=", lfc::to_string(get_llvm_func_name(last_F)));

    last_dfg_Util.init(last_F);

    std::vector<DFGNode*> dfg_nodes = last_dfg_Util.get_all_dfg_nodes();
    for(auto F : dfg_func_list){
      dfg_nodes = F(dfg_nodes, last_dfg_Util);
    }

    last_dfg_update = true;
    last_dfg_nodes  = dfg_nodes;
  }

  return last_dfg_nodes;
}

void FuncUtilImpl::update_function(Function* F){
  LFC_TRACE2("update_function: F=", lfc::to_string(get_llvm_func_name(F)));
  if(last_F != F){
    last_F = F;
    last_dfg_update = false;
  }
}

std::vector<std::string> FuncUtilImpl::build_dfg_var_list(std::vector<int> &param_index_list, FuncCall* FC){
  LFC_TRACE4("build_dfg_var_list: ", lfc::to_string(FC), ", paras=", lfc::to_string(param_index_list));  

  DFGNode* call_node = NULL;
  for(DFGNode* node : get_last_dfg_nodes()){
    if(node->get_inst() == FC->call_inst){
      call_node = node;
      break;
    }
  }
  assert(call_node && "call_node not found");

  std::vector<DFGNode*> para_node_list;
  LFC_TRACE2("call_node: ", lfc::to_string(call_node));

  for(int para_index : param_index_list){
    DFGNode* para_node = call_node->get_call_operand_node(para_index);
    if(para_node != NULL){
      para_node_list.push_back(para_node);
      LFC_TRACE2("para_node: ", lfc::to_string(para_node));  
    }
  }

  LFC_TRACE2("para_node_list : ", lfc::to_string(para_node_list));
  auto depend_on_nodes  = DFGNode::get_all_depend_on_nodes(para_node_list);
  
  LFC_TRACE2("depend_on_nodes: ", lfc::to_string(depend_on_nodes));
  std::copy(depend_on_nodes.begin(), depend_on_nodes.end(), std::back_inserter(para_node_list));
  DFGNode::sort_dfg_nodes(para_node_list);

  return last_dfg_Util.get_all_dfg_src_vars(para_node_list);
}

FuncUtil::FuncUtil(){
  impl = new FuncUtilImpl();
}

FuncUtil::FuncUtil(const std::vector<FuncDef>& fd_list){
  impl = new FuncUtilImpl();
  impl->add_func_def_list(fd_list);
}

FuncUtil::FuncUtil(const std::vector<FuncDef>& fd_list, const std::vector<dfg_select_func>& func_list){
  impl = new FuncUtilImpl();
  impl->add_func_def_list(fd_list);
  impl->add_dfg_func_list(func_list);
}

FuncUtil::~FuncUtil(){
  delete impl;
}

void FuncUtil::add_func_def_list(const std::vector<FuncDef>& fd_list){
  impl->add_func_def_list(fd_list);
}

void FuncUtil::add_dfg_func_list(const std::vector<dfg_select_func>& func_list){
  impl->add_dfg_func_list(func_list);
}

std::vector<FuncCall> FuncUtil::load_func_call_list(llvm::BasicBlock* B){
  if( !B ){
    return {};
  }

  std::vector<FuncCall> fc_list;
  for(auto FC : lfc::load_block_func_call_list(B)){
    if( impl->has_func_def(FC.func_name) ){     
      // update function call info
      FC.update_para_list();
      FC.update_debug_info();
      LFC_TRACE2("found FC: ", lfc::to_string(FC));
      fc_list.push_back(FC);
    }
  }

  return fc_list;
}

std::vector<FuncCall> FuncUtil::load_func_call_list(llvm::Function* F){
  if( !F ){
    return {};
  }

  std::vector<lfc::FuncCall> fc_list;
  for(llvm::BasicBlock& B : *F){
    for(auto FC : load_func_call_list(&B)){
      fc_list.push_back(FC);
    }
  }

  return fc_list;
}

std::vector<std::vector<int>> FuncUtil::build_dep_array(const std::vector<FuncCall>& fc_list){
  const int task_count = fc_list.size();
  std::vector<std::vector<int>> dp_array(task_count);

  for(int current_index = 0; current_index < task_count; ++current_index){    
    auto current_FC = fc_list[current_index];
    auto in_out_param_index_list = impl->get_func_params(current_FC.func_name);
    auto in_out_var_list = impl->build_ordered_var_list(in_out_param_index_list, &current_FC);
    
    if(in_out_var_list.empty())
      continue;

    // check previous functions
    for(int previous_index = current_index-1; previous_index >= 0; --previous_index){
      auto previous_FC = fc_list[previous_index];
      auto previous_out_param_index_list = impl->get_simd_func_out_params(previous_FC.func_name);
      auto previous_out_var_list = impl->build_ordered_var_list(previous_out_param_index_list, &previous_FC);     
      if(has_llvm_common_var(in_out_var_list, previous_out_var_list)){
        dp_array[current_index].push_back(previous_index);
      }      
    }
  }

  return dp_array;
}

std::vector<std::vector<int>> FuncUtil::build_dep_array2(const std::vector<FuncCall>& fc_list){
  LFC_TRACE1("build_dep_array2:");

  const int task_count = fc_list.size();
  std::vector<std::vector<int>> dp_array(task_count);

  for(int current_index = 0; current_index < task_count; ++current_index){    
    
    auto current_FC = fc_list[current_index];

    std::string call_var_name = get_llvm_value_name(current_FC.call_inst);
    LFC_TRACE6("Check current: index=", current_index, ", FC=", lfc::to_string(current_FC), ", var_name=", call_var_name);

    auto in_out_param_index_list = impl->get_func_params(current_FC.func_name);
    auto in_out_var_list         = impl->build_dfg_var_list(in_out_param_index_list, &current_FC);
    LFC_TRACE2("in_out_var_list: ", lfc::to_string(in_out_var_list));
    if(current_FC.ret_var != ""){
      LFC_TRACE2("ret_var: ", lfc::to_string(current_FC.ret_var));
      in_out_var_list.push_back(current_FC.ret_var);
      LFC_TRACE2("in_out_var_list: ", lfc::to_string(in_out_var_list));
    }

    if(in_out_var_list.empty())
      continue;

    // check previous functions
    for(int previous_index = current_index-1; previous_index >= 0; --previous_index){
      auto previous_FC = fc_list[previous_index];

      std::string previous_var_name = get_llvm_value_name(previous_FC.call_inst);      
      LFC_TRACE6("Check previous: index=", previous_index, ", FC=", lfc::to_string(previous_FC), ", var_name=", previous_var_name);
      
      auto previous_out_param_index_list = impl->get_simd_func_out_params(previous_FC.func_name);
      auto previous_out_var_list         = impl->build_dfg_var_list(previous_out_param_index_list, &previous_FC);     
      LFC_TRACE2("out_var_list: ", lfc::to_string(previous_out_var_list));

      if(previous_FC.ret_var != ""){
        LFC_TRACE2("ret_var: ", lfc::to_string(previous_FC.ret_var));
        previous_out_var_list.push_back(previous_FC.ret_var);
        LFC_TRACE2("out_var_list: ", lfc::to_string(previous_out_var_list));
      }

      if(has_llvm_common_var(in_out_var_list, previous_out_var_list)){
        LFC_TRACE4("found dep: pre=", previous_index, ", cur=", current_index);
        dp_array[current_index].push_back(previous_index);
      }
    }
  }

  return dp_array;
}

std::vector<DFGNode*> FuncUtil::get_func_dfg_nodes(){
  return impl->get_last_dfg_nodes();
}

void FuncUtil::update_function(Function* F){
  impl->update_function(F);
}



} // namespace lfc 


