// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[func_call]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(func_call)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(func_call)
#include "lfc/base/abi.h"
#include "lfc/llvm/macro.h"
#include "lfc/llvm/func_call.h"
#include "lfc/llvm/dbg.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include "llvm/Pass.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Support/Casting.h"

using namespace llvm;

namespace lfc {

std::string _load_para_by_value(Value* value);
std::string _load_para_by_user(User* user);
std::string _load_para_by_instruction(Instruction* I);

std::vector<FuncCall> load_block_func_call_list(llvm::BasicBlock* B){
  if( !B )
    return {};

  std::vector<FuncCall> fc_list;

  for(Instruction& I : *B){

    if(!isa<CallInst>(&I)){
      continue;
    }

    CallInst* CI = dyn_cast<CallInst>(&I);
    FuncCall FC;

    // update Instruction
    FC.call_inst = CI;

    // update function name
    {
      auto mangled_name = get_llvm_call_name(CI);
      FC.func_name = demangle_func_name(mangled_name);
      LFC_TRACE4("func=", FC.func_name, ", mangled=", mangled_name);
    }

    // update return var
    if (!CI->getType()->isVoidTy()) {
      FC.ret_var = get_llvm_value_name(CI);
    }

    fc_list.push_back(FC);
  }

  return fc_list;
}

FuncCall::FuncCall(){
  src_loc = -1;
}

static void _copy(const FuncCall& A, FuncCall& B){
  B.func_name = A.func_name;
  B.call_inst = A.call_inst;
  B.para_list = A.para_list;
  B.ret_var   = A.ret_var;
  B.src_loc   = A.src_loc;
}

static void _move(FuncCall& A, FuncCall& B){
  B.func_name = std::move(A.func_name);
  B.call_inst = A.call_inst;
  B.para_list = std::move(A.para_list);
  B.ret_var   = A.ret_var;
  B.src_loc   = A.src_loc;
}

FuncCall::FuncCall(const FuncCall& FC){
  _copy(FC, *this);
}

FuncCall::FuncCall(FuncCall&& FC){
  _move(FC,*this);
}

FuncCall& FuncCall::operator=(const FuncCall &FC){
  _copy(FC, *this);
  return *this;
}

FuncCall& FuncCall::operator=(FuncCall &&FC){
  _move(FC,*this);
  return *this;
}

void FuncCall::update_para_list(){
  //LFC_TRACE2("update para, I=", *call_inst);
  para_list.clear();

  for(auto opd : get_llvm_call_operands(call_inst)){
    std::string para = _load_para_by_value(opd); 
    para_list.push_back(para);
  }
}

void FuncCall::update_debug_info(){
  //LFC_TRACE2("update debug info, I=", *call_inst);
  src_loc = get_llvm_inst_dbg_loc(call_inst);
}

std::string _load_para_by_value(Value* value){
  //LFC_TRACE2( "\t\t_load_para_by_value: ", *value);
  if(isa<User>(value)){
    return _load_para_by_user(dyn_cast<User>(value));
  }

  if(isa<Argument>(value)){ 
    return get_llvm_value_name(value);
  }

  errs() << " value=" << *value << "\n";
  llvm_unreachable("unprocess value!");
}

std::string _load_para_by_instruction(Instruction* I){
  //LFC_TRACE2( "\t\t_load_para_by_instruction: ", *I);

  unsigned int num_operands = I->getNumOperands();

  LoadInst* LI = dyn_cast<LoadInst>(I);
  if(LI){
    //LFC_TRACE1( "\t\t\tLoadInst: ");
    assert(num_operands == 1);  

    Value* val = LI->getPointerOperand();
    assert(val != NULL);
    
    Type* type = LI->getPointerOperandType();
    assert(type != NULL);
    
    //errs() <<", type=LoadInst, getPointerOperandType()=" << *type << "\n" ;    

    // errs() << "getPointerOperand(): ";
    return _load_para_by_value(val);
  }

  GetElementPtrInst * GI = dyn_cast<GetElementPtrInst>(I);
  if(GI){
    //LFC_TRACE2( "\t\t\tGetElementPtrInst: ", *GI);
    return _load_para_by_value(GI->getOperand(num_operands - 2));
  }

  // AllocaInst* AI = dyn_cast<AllocaInst>(I);
  // if(AI){
  //   return get_llvm_value_name(AI);
  // }

  // CallInst* CI = dyn_cast<CallInst>(I);
  // if(CI){
  //   return get_llvm_value_name(CI);
  // }

  // errs() << "Instruction(): " << *I << "\n";
  // llvm_unreachable("unprocess Instruction!");

  //LFC_TRACE1( "\t\t\tget_value_name: ");
  return get_llvm_value_name(I);
}

std::string _load_para_by_user(User* user){
  if(ConstantInt* C = dyn_cast<ConstantInt>(user); C){ 
    return std::to_string(C->getSExtValue());
  }

  if(ConstantFP* F = dyn_cast<ConstantFP>(user); F){ 
    return std::to_string(F->getValue().convertToDouble());
  }

  if(Instruction* I = dyn_cast<Instruction>(user); I){
    return _load_para_by_instruction(I);
  }
  
  if(GlobalVariable* GV = dyn_cast<GlobalVariable>(user); GV){
    return GV->getGlobalIdentifier();
  }

  if(ConstantPointerNull* C = dyn_cast<ConstantPointerNull>(user); C){
    return LLVM_NAME_NULL;
  }

  errs() << " user=" << *user << " typid=" << user->getType()->getTypeID() << "\n";
  llvm_unreachable("unprocess user!");
}

LFC_TO_STRING_IMPL(FuncCall, FC){
  if(!FC)
    return "FC(null)";

  std::string out = "FC(";

  out += "name=";
  out += FC->func_name;

  out += ", para=";
  out += lfc::to_string(FC->para_list);

  out += ", ret=";
  out += FC->ret_var;

  out += ", src_loc=";
  out += std::to_string(FC->src_loc);

  out += ")";

  return out;
}

} // namespace lfc 


