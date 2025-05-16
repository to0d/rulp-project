// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[llvm_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(llvm_util)()
#define LFC_TRACE_STREAM llvm::errs()
#include "lfc/llvm/macro.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/abi.h"
#include "lfc/base/container.h"
#include "lfc/base/string/util.h"
#include "lfc/base/file.h"
#include "lfc/base/trace.h"
#include "lfc/base/to_string.h"
#include "llvm/Pass.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/SourceMgr.h"

#include <map>
#include <set>
#include <vector>
#include <iostream>

using namespace llvm;

LLVM_DECLARE_MIN_VERSION_15

namespace lfc {

#define STRUCT_HEAD     "struct."
#define STRUCT_HEADLEN  7

class ModelCopyHelper{

public:
  ModelCopyHelper(Module* m):M(m), MC(&m->getContext()), builder(*MC) {};

  ~ModelCopyHelper(){_finish_update();}

public:
  Function* _get_copy_func(Function* F, int lvl);
  void      _update_st_inst(Function* F, int lvl);
  void      _check_call_inst(Function* F, int lvl);
  void      _replace_llvm_function(Function* old_func, Function* new_func, int lvl);
  void      _replace_call_inst(Function* F, Function* DF, Function* new_DF, int lvl);
  void      _finish_update();

private:

  Type*           _get_copy_type(Type* type);
  Value*          _get_copy_value(Value* value);
  GlobalVariable* _get_copy_global_var(GlobalVariable* GV);
  Instruction*    _get_copy_inst(Instruction* I);
  Function*       _get_copy_empty_func(Function* SF);
  Function*       _get_copy_full_func(Function* F, int lvl);

  std::map<std::string, StructType*>& _get_struct_type_map();

  void _add_removed_func(Function* F, int lvl){
    LFC_TRACE3(lvl, ": _add_removed_func: F=", get_llvm_func_name(F));
    removed_func_list.insert(F);
  };

  bool _is_removed(Function* F) { return lfc::find(removed_func_list, F); }

  bool _has_copy_func(Function* F) {return copy_func_map.find(F) != copy_func_map.end(); }

private:

  std::map<Function*, Function*> copy_func_map;

  std::map<std::string, StructType*> struct_type_map;
  bool struct_type_map_init = false;

  std::map<Type*, Type*> copy_type_map;
  std::map<std::string, GlobalVariable*> copy_global_var_map;

  std::set<Function*> removed_func_list;
  std::vector<std::pair<Function*, std::string>> new_func_name_list;
  
  Module* M;
  LLVMContext* MC;
  IRBuilder<> builder;
};

std::map<std::string, StructType*>& ModelCopyHelper::_get_struct_type_map(){
  if(!struct_type_map_init){
    for(auto st : M->getIdentifiedStructTypes()){
      auto st_name = st->getName().str();
      struct_type_map[st_name] = st;
    }
    struct_type_map_init = true;
  }

  return struct_type_map;
}

Function* ModelCopyHelper::_get_copy_empty_func(Function* F){

  // create function type
  auto FT = F->getFunctionType();
  {        
    std::vector<Type*> paras;
    for(auto pos = FT->param_begin(); pos != FT->param_end(); ++pos){
      Type* src_pt = *pos;
      Type* dst_pt = _get_copy_type(src_pt);    
      paras.push_back(dst_pt);
    }

    auto RT = _get_copy_type(F->getReturnType());
    FT = FunctionType::get(RT, paras, false);
  }

  auto FL = F->getLinkage();
  auto FA = F->getAddressSpace();
  auto FN = F->getName();  // in case demangle_func_name

  // create new function
  Function* new_F = Function::Create(FT, FL, FA, FN, M);
  assert(new_F && "fail to create new function");

  return new_F;
}

Value* ModelCopyHelper::_get_copy_value(Value* value){

  if(ConstantExpr* CE = dyn_cast<ConstantExpr>(value); CE){
    int opcode = CE->getOpcode();
    switch(opcode){
      case Instruction::BitCast:
        assert(CE->getNumOperands() == 1);
        if(GlobalVariable *GV = dyn_cast<GlobalVariable>(CE->getOperand(0)); GV) {
          GlobalVariable* new_var = _get_copy_global_var(GV);
          value = ConstantExpr::getBitCast(new_var, CE->getType());
        }
        break;

      default:
        break;
    }
  }
  else if(GlobalVariable* GV = dyn_cast<GlobalVariable>(value); GV){
    GlobalVariable* new_var = _get_copy_global_var(GV);
    value = new_var;
  }

  return value;
}


Instruction* ModelCopyHelper::_get_copy_inst(Instruction* I){
  if(CallInst* CI = dyn_cast<CallInst>(I); CI){

    int num_of_arg = CI->getNumOperands() - 1;
    auto DF = CI->getCalledFunction();    
    std::vector<Value*> values;
    int update = 0;

    for(int i = 0; i < num_of_arg; ++i){
      Value* old_value = CI->getArgOperand(i);
      Value* new_value = _get_copy_value(old_value);
      if(new_value != old_value){
        ++update;        
      }

      values.push_back(new_value);        
    }

    if(update > 0){
      return builder.CreateCall(DF, values);
    }   
  }
  else if(AllocaInst* AI = dyn_cast<AllocaInst>(I); AI){
    auto old_type = AI->getAllocatedType();
    auto new_type = _get_copy_type(AI->getAllocatedType());
    assert(new_type);

    if(old_type != new_type){
      // return builder.CreateAlloca(new_type, AI->getAddressSpace(), AI->getArraySize(), AI->getName()); // #TODO why crash
      return new AllocaInst(new_type, AI->getAddressSpace(), AI->getName(), AI);
    }
  }
  else if(LoadInst* LI = dyn_cast<LoadInst>(I); LI){
    auto old_type = LI->getType();
    auto new_type = _get_copy_type(old_type);

    if(old_type != new_type){
      return new LoadInst(new_type, LI->getPointerOperand(), LI->getName(), LI);
    }    
  }
  else if(GetElementPtrInst* GI = dyn_cast<GetElementPtrInst>(I); GI){
    auto old_type = GI->getSourceElementType();
    auto new_type = _get_copy_type(old_type);

    // auto dd= GI->getSou/rceElementType();
    // errs() << "dd: " << *dd << "\n";

    if(PointerType* pt = dyn_cast<PointerType>(new_type); pt){
      if(!pt->isOpaque()){
        new_type = _get_copy_type(pt->getNonOpaquePointerElementType());
      }
    }

    int update = 0;
    std::vector<Value*> values;

    if(old_type != new_type){
      ++update;
    }

    // errs() << "old_type: " << *old_type << "\n";
    // errs() << "new_type: " << *new_type << "\n";

    // errs() << "GI=" << *GI << "\n";

    for(auto it = GI->idx_begin(); it != GI->idx_end(); ++it){
      Value* old_value = it->get();
      Value* new_value = _get_copy_value(old_value);
      if(new_value != old_value){
        ++update;        
      }
      values.push_back(new_value);

      // errs() << "new_value: " << *new_value << "\n";
    }

    auto* old_ptr = GI->getPointerOperand();
    auto* new_ptr = _get_copy_value(old_ptr);
    if(new_ptr != old_ptr){
      ++update;        
    }

    // errs() << "update=" << update << "\n";
    // errs() << "old_ptr: " << *old_ptr << "\n";
    // errs() << "new_ptr: " << *new_ptr << "\n";

    if(update > 0){

      // errs() << "ElTy: " << "\n";
    //  auto* ElTy = GetElementPtrInst::getIndexedType(old_type, values);
    //  errs() << "ElTy: " << *ElTy << "\n";
    //  assert(ElTy);

      // errs() << "new_ptr: " << *GI->getOperand(1) << "\n";
      

      auto* new_GI = GetElementPtrInst::CreateInBounds(new_type, new_ptr, values, GI->getName(), GI);
      // errs() << "new_GI=" << *new_GI << "\n";

      return new_GI;
    }
  }

  // else if(GetElementPtrInst* GI = dyn_cast<GetElementPtrInst>(I); GI){
    
  // }

  return I;
}

GlobalVariable* ModelCopyHelper::_get_copy_global_var(GlobalVariable* GV){

  auto global_name = get_llvm_global_var_name(GV);
  GlobalVariable* new_var = copy_global_var_map[global_name];

   if(new_var == NULL){
    // 创建一个新的 GlobalVariable 对象
    new_var = new GlobalVariable(
        *M, // 新模块
        _get_copy_type(GV->getValueType()), 
        GV->isConstant(),
        GV->getLinkage(),
        GV->getInitializer(), 
        GV->getName(), 
        nullptr, 
        GV->getThreadLocalMode(), 
        GV->getType()->getAddressSpace() 
    );

    // // 复制 GlobalVariable 的属性
    new_var->copyAttributesFrom(GV);

    copy_global_var_map[global_name] = new_var;
  }

  return new_var;
}


Type* ModelCopyHelper::_get_copy_type(Type* type){
  assert(type && "invalid type");

  Type* copy_type = copy_type_map[type];
  if(copy_type != NULL){
    return copy_type;
  }

  switch (type->getTypeID()) {
  case Type::PointerTyID:
    {
      PointerType* PT = dyn_cast<PointerType>(type);
      assert(PT);
      if(!PT->isOpaque()){
        Type* new_ET = _get_copy_type(PT->getNonOpaquePointerElementType());
        copy_type = PointerType::get(new_ET, PT->getAddressSpace());
      }
      break;
    }
    break;
  case Type::StructTyID:
    {
      StructType* ST = dyn_cast<StructType>(type);
      auto st_name = ST->getName().str();

      // match struct.xxxx
      if(!str_start_With(st_name, STRUCT_HEAD)){
        break;
      }

      // match struct.xxxx.1
      int pos = STR_INDEX_OF_FROM(st_name, '.', STRUCT_HEADLEN);
      if(pos == -1){
        break;
      }

      // match xxxx.1
      auto st_name3 = st_name.substr(pos+1);
      if(!STR_IS_INT(st_name3)){
        break;
      }

      std::string tgt_name = st_name.substr(0, pos);

      auto& _st_map = _get_struct_type_map();
      auto pos2 = _st_map.find(tgt_name);
      if(pos2 == _st_map.end()){
        break;
      }

      copy_type = pos2->second;
      break;
    }
    break;
  case Type::ArrayTyID:
    {
      ArrayType* at = dyn_cast<ArrayType>(type);
      copy_type = ArrayType::get(_get_copy_type(at->getArrayElementType()), at->getArrayNumElements());
    }

    break;

  default:
    break;
  }

  if(copy_type == NULL){
    copy_type = type;
  }

  copy_type_map[type] = copy_type;
  return copy_type;
}


void ModelCopyHelper::_finish_update(){
  LFC_TRACE1("_finish_update:");

  for(auto F: removed_func_list){
    assert(F);    
    LFC_TRACE2("erase: func=", get_llvm_func_name(F));
    F->eraseFromParent();
  }

  for(auto p : new_func_name_list){
    assert(p.first);
    LFC_TRACE4("rename: func=", get_llvm_func_name(p.first), ", name=", p.second);
    p.first->setName(p.second);
    // errs() << "done1\n";
  }

  // errs() << "done\n";
}


Function* copy_llvm_function(llvm::Module* SM, llvm::Module* DM, std::string func_name){
  LFC_TRACE2("copy_llvm_function: func=", func_name);

  Function* SF = get_llvm_func(SM, func_name);
  if(SF == NULL){
    LFC_TRACE2("func not found in SM, func=", func_name);
    return NULL;
  }

  Function* DF = get_llvm_func(DM, func_name);
  if(DF != NULL){
    LFC_TRACE2("func alrady exist in DM, func=", func_name);
    return DF;
  }

  auto& DC = DM->getContext();
  auto& SC = SM->getContext();
  assert(&DC == &SC && "Can't copy function to diff context");

  ModelCopyHelper MC(DM);

  return MC._get_copy_func(SF, 0);
}

std::vector<llvm::Function*> 
copy_llvm_function(const std::string& ir, llvm::Module* DM, const std::vector<std::string>& func_list){
  LFC_TRACE2("copy_llvm_function: ir=", FS_FILE_NAME(ir));
  LFC_TRACE_LIST("func_list", func_list);

  std::map<std::string, Function*> name_func_map = to_llvm_func_map(get_all_llvm_function(DM));
  std::vector<std::string> need_copy_func_list;

  for(auto required_func_name : func_list){
    if(name_func_map.find(required_func_name) != name_func_map.end()){
      LFC_TRACE2("ignore exist function: ", required_func_name);
    }
    else {
      need_copy_func_list.push_back(required_func_name);
    }
  }

  LFC_TRACE2("need_copy_func_list: ", lfc::to_string(need_copy_func_list));
  if(need_copy_func_list.empty())
    return {};

  auto SM = load_llvm_module(ir, DM->getContext());;
  assert(SM && "fail to load example module");

  ModelCopyHelper MC(DM);
  std::vector<llvm::Function*> copied_func_vec;

  for(auto copy_func_name : need_copy_func_list){
    Function* SF = get_llvm_func(SM.get(), copy_func_name);
    if(SF == NULL){
      LFC_TRACE2("func not found in SM, func=", copy_func_name);
      continue;
    }

    auto F = MC._get_copy_func(SF, 0);
    assert(F && "fail to copy function");
    copied_func_vec.push_back(F);
  }
 
  return copied_func_vec;
}

void ModelCopyHelper::_replace_call_inst(Function* F, Function* DF, Function* new_DF, int lvl){
  LFC_TRACE7(lvl, ": _replace_call_inst: F=", get_llvm_func_name(F), ", DF=", get_llvm_func_name(DF), ", new_DF=", get_llvm_func_name(new_DF));

  std::vector<CallInst*> ci_list;
  for(auto& BB : *F){
    for(auto& I : BB){
      CallInst* CI = dyn_cast<CallInst>(&I);
      if(CI && CI->getCalledFunction() == DF){
        ci_list.push_back(CI);
      }
    }
  }

  LFC_TRACE2("   ci_list: size=", ci_list.size());

  for(CallInst* CI : ci_list){
    std::vector<Value*> values;
    int num_of_arg = CI->getNumOperands() - 1;

    for(int i = 0; i < num_of_arg; ++i){
      Value* value = CI->getArgOperand(i);
      values.push_back(value);
    }

    CallInst * new_CI = builder.CreateCall(new_DF, values);
    new_CI->insertBefore(CI);
    CI->replaceAllUsesWith(new_CI);
    CI->eraseFromParent();
  }
}

void ModelCopyHelper::_check_call_inst(Function* F, int lvl){
  LFC_TRACE3(lvl, ": _check_call_inst: F=", get_llvm_func_name(F));

  std::vector<Function*> updating_func_list;

  for(auto& BB : *F){
    for(auto& I : BB){
      if(CallInst* CI = dyn_cast<CallInst>(&I); CI){
        auto called_F = get_llvm_called_function(CI);
        assert(called_F);
        // errs() << *called_F << "\n";

        if(lfc::find(updating_func_list, called_F)){
          continue;
        }

        if(called_F->getInstructionCount() != 0){
          continue;
        }

        auto old_st = called_F->getReturnType();
        auto new_st = _get_copy_type(old_st);
        if(old_st != new_st){
          updating_func_list.push_back(called_F);
          continue;
        }

        bool find = false;

        auto FT = called_F->getFunctionType();
        for(auto pos = FT->param_begin(); pos != FT->param_end(); ++pos){
          Type* src_pt = *pos;
          Type* dst_pt = _get_copy_type(src_pt);    
          if(src_pt != dst_pt){
            find = true;
            break;
          }
        }

        if(find){
          updating_func_list.push_back(called_F);
          // errs() << *called_F;
          continue;
        }
      }
    }
  }

  LFC_TRACE2("   updating_func_list: size=", updating_func_list.size());

  for(auto old_func: updating_func_list){
    if(_is_removed(old_func))
      continue;
    _get_copy_func(old_func, lvl);
  }
}

void ModelCopyHelper::_update_st_inst(Function* F, int lvl){
  LFC_TRACE3(lvl, ": _update_st_inst: func=", get_llvm_func_name(F));

  std::vector<Instruction*> updating_inst;

  for(auto& BB : *F){
    for(auto& I : BB){
      if(AllocaInst* AI = dyn_cast<AllocaInst>(&I); AI){
        auto old_st = AI->getType();
        auto new_st = _get_copy_type(old_st);
        if(old_st != new_st){          
          updating_inst.push_back(&I);
          continue;
        }
      }
      else if(LoadInst* LI = dyn_cast<LoadInst>(&I); LI){
        auto old_st = LI->getType();
        auto new_st = _get_copy_type(old_st);
        if(old_st != new_st){   
          updating_inst.push_back(&I);
          continue;
        }
      }
      else if(GetElementPtrInst* GI = dyn_cast<GetElementPtrInst>(&I); GI){
        auto old_st = GI->getPointerOperandType();
        auto new_st = _get_copy_type(old_st);
        if(old_st != new_st){   
          updating_inst.push_back(&I);
          continue;
        }
      }
    }
  }

  LFC_TRACE2("   updating_inst: size=", updating_inst.size());
  for(auto old_inst : updating_inst){
    // LFC_TRACE2("old ii: ", *I);

    auto *new_inst = _get_copy_inst(old_inst);
    assert(new_inst != NULL && new_inst != old_inst);  
    if(new_inst != old_inst){
      old_inst->replaceAllUsesWith(new_inst);
      old_inst->eraseFromParent();
    }

  }
}

void ModelCopyHelper::_replace_llvm_function(Function* old_func, Function* new_func, int lvl){

  LFC_TRACE5(lvl, ": _replace_llvm_function: old=", get_llvm_func_name(old_func), ", new=", get_llvm_func_name(new_func));
  assert(old_func != new_func);

  for(auto F : get_all_llvm_function(M, true)){
    if(F == old_func || F == new_func)
      continue;

    // update call inst
    _replace_call_inst(F, old_func, new_func, lvl+1);

    // update struct type
    _update_st_inst(F, lvl+1);

    // update func type
    _check_call_inst(F,lvl+1);
  }
}

Function* ModelCopyHelper::_get_copy_full_func(Function* F, int lvl){
  LFC_TRACE3(lvl, ": _get_copy_full_func: F=", get_llvm_func_name(F));

  Module* SM = F->getParent();
  Module* DM = this->M; 
  // assert(SM != DM);

  LLVMContext& MC = *this->MC;

  // create new function
  Function* new_F = _get_copy_empty_func(F);
  assert(new_F && "fail to create new function");

  // copy function attribue
  new_F->copyAttributesFrom(F);
 
  /*******************************************************************/
  // copy block & instrctions
  /*******************************************************************/
  std::map<Instruction*, std::pair<int, int>> old_inst_map;
  std::vector<std::vector<Instruction*>> new_inst_arr;
  int bb_index = 0;
  for (auto &BB : *F) {
    BasicBlock *newBB = BasicBlock::Create(new_F->getContext(), "", new_F);
    int inst_indx = 0;
    std::vector<Instruction*> inst_vec;
    for (auto &I : BB) {
      Instruction *new_inst = I.clone();
      newBB->getInstList().push_back(new_inst);
      old_inst_map[&I] = {bb_index, inst_indx};
      inst_vec.push_back(new_inst);
      ++inst_indx;
    }
    new_inst_arr.push_back(inst_vec);
    ++bb_index;
  }

  /*******************************************************************/
  // Update inst use
  /*******************************************************************/
  for (auto &BB : *new_F) {
    for (auto &I : BB) {
      for (Use &U : I.operands()){
        Value *old_value = U.get();
        if (Instruction *old_inst = dyn_cast<Instruction>(old_value)) {
          auto it = old_inst_map.find(old_inst);
          if(it != old_inst_map.end()){
            int bb_index    = it->second.first;
            int inst_index  = it->second.second;
            Instruction *new_inst = new_inst_arr[bb_index][inst_index];
            U.set(new_inst);
          }
        }
      }
    }
  }

  /*******************************************************************/
  // Update argument
  /*******************************************************************/
  std::map<std::string, Argument*> arg_map;
  for (Argument &arg : new_F->args()) {
    arg_map[get_llvm_argument_name(&arg)] = &arg;
  }

  for (auto &BB : *new_F) {
    for (auto &I : BB) {  
      for (Use &U : I.operands()){
        Value *old_value = U.get();
        if (Argument *old_arg = dyn_cast<Argument>(old_value)) {
          auto arg_name = get_llvm_argument_name(old_arg);
          auto it = arg_map.find(arg_name);
          if(it != arg_map.end()){
            Argument* new_arg = it->second;
            U.set(new_arg);
          }
        }
      }
    }
  }

  /*******************************************************************/
  // Update block reference
  /*******************************************************************/
  std::map<std::string, BasicBlock*> block_map;
  for (auto &BB : *new_F) {
    block_map[get_llvm_block_name(&BB)] = &BB;
  }

  for (auto &BB : *new_F) {
    for (auto &I : BB) {  
      if (BranchInst *BI = dyn_cast<BranchInst>(&I)){

        {
          BasicBlock* old_true_bb = BI->getSuccessor(0);
          auto true_bb_name = get_llvm_block_name(old_true_bb);
          auto true_it = block_map.find(true_bb_name);
          if(true_it != block_map.end()){
            BasicBlock* new_bb = true_it->second;
            BI->setSuccessor(0, new_bb);
          }
        }

        if (BI->isConditional()) {
          BasicBlock* new_true_bb = BI->getSuccessor(1);
          auto false_bb_name = get_llvm_block_name(new_true_bb);
          auto false_it = block_map.find(false_bb_name);
          if(false_it != block_map.end()){
            BasicBlock* new_bb = false_it->second;
            BI->setSuccessor(1, new_bb);
          }
        }

      }
    }
  }

  /*******************************************************************/
  // Update swtich block reference
  /*******************************************************************/
  for (auto &BB : *new_F) {
    for (auto &I : BB) {  
      if (SwitchInst *SI = dyn_cast<SwitchInst>(&I)){

        for(auto caseIt : SI->cases()){    
          BasicBlock* old_case_block = caseIt.getCaseSuccessor();
          auto true_bb_name = get_llvm_block_name(old_case_block);
          auto true_it = block_map.find(true_bb_name);
          if(true_it != block_map.end()){
            BasicBlock* new_bb = true_it->second;
            caseIt.setSuccessor(new_bb);
          }
        }

        {
          BasicBlock* old_case_block  = SI->getDefaultDest();
          auto true_bb_name = get_llvm_block_name(old_case_block);
          auto true_it = block_map.find(true_bb_name);
          if(true_it != block_map.end()){
            BasicBlock* new_bb = true_it->second;
            SI->setDefaultDest(new_bb);          
          }
        }
      }
    }
  }

  /*******************************************************************/
  // Update phi block reference
  /*******************************************************************/
  for (auto &BB : *new_F) {
    for (auto &I : BB) {
      if(PHINode* PI = dyn_cast<PHINode>(&I); PI){
        for (unsigned i = 0; i < PI->getNumIncomingValues(); ++i){
          BasicBlock *old_bb = PI->getIncomingBlock(i);
          auto old_bb_name = get_llvm_block_name(old_bb);
          auto old_it = block_map.find(old_bb_name);
          if(old_it != block_map.end()){
            BasicBlock* new_bb = old_it->second;
            PI->setIncomingBlock(i, new_bb);            
          }
        }
      }
    }
  }


  /*******************************************************************/
  // Copy global var
  /*******************************************************************/
  {
    std::vector<Instruction*> global_inst_list;
    for (auto &BB : *new_F) {
      for (auto &I : BB) {
        bool find = false;
        // errs() << I << "\n";
        for (Use &U : I.operands()){
          Value *value = U.get();
          // errs() << "  :" << *value << ":" << *value->getType() <<  "\n";
          if(ConstantExpr* CE = dyn_cast<ConstantExpr>(value); CE){
            for (unsigned int i = 0; i < CE->getNumOperands(); ++i) {         
              if (GlobalVariable *GV = dyn_cast<GlobalVariable>(CE->getOperand(i)); GV) {    
                find = true;
                break;
              }
            }
          }
          else if(GlobalVariable* GV = dyn_cast<GlobalVariable>(value); GV){
            // errs() << *GV << "\n";
            find = true;
            break;
          }
        } 
      
        if(find){
          global_inst_list.push_back(&I);
        }
      }
    }

    LFC_TRACE2("   update insts for global var: size=", global_inst_list.size());
    for(auto old_inst : global_inst_list){
      Instruction* new_inst = _get_copy_inst(old_inst);
      if(new_inst != NULL && new_inst == old_inst){
        errs() << *new_inst << "\n";
      }
      assert(new_inst != NULL && new_inst != old_inst); 
      new_inst->insertBefore(old_inst);
      old_inst->replaceAllUsesWith(new_inst);
      old_inst->eraseFromParent();
    }
  }

  /*******************************************************************/
  // Update call inst
  /*******************************************************************/
  std::vector<Function*> need_update_func_list;

  for (auto &BB : *new_F) {
    for (auto &I : BB) {
      if(CallInst* CI = dyn_cast<CallInst>(&I); CI){
        auto called_func = get_llvm_called_function(CI);
        assert(called_func);
        if(called_func->getParent() == this->M){
          continue;
        }

        if(lfc::find(need_update_func_list, called_func))
          continue;

        need_update_func_list.push_back(called_func);
      }
    }
  }

  for(auto func : need_update_func_list){
    bool has_copied = _has_copy_func(func);
    auto new_func = _get_copy_func(func, lvl+1);
    if(has_copied){
      _replace_call_inst(new_F, func, new_func, lvl+1);
    }
  } 

  return new_F;
}

Function* ModelCopyHelper::_get_copy_func(Function* F, int lvl){
  LFC_TRACE3(lvl, ": _get_copy_func: F=", get_llvm_func_name(F));

  // assert(F->getParent() != this->M);

  auto it = this->copy_func_map.find(F);
  if(it != this->copy_func_map.end()){
    return it->second;
  }

  std::string old_func_name = get_llvm_func_name(F);
  Function* dup_F = get_llvm_func(this->M, old_func_name);

  Function* new_F = _get_copy_full_func(F, lvl+1);
  assert(new_F && "fail to copy function");

  if(dup_F != NULL){
    if(!_is_removed(dup_F)){
      _add_removed_func(dup_F,lvl+1);
      new_func_name_list.push_back({new_F, old_func_name});
      _replace_llvm_function(dup_F, new_F, lvl+1);
    }
  }
  else{
    _replace_llvm_function(F, new_F, lvl+1);
  }
  
  this->copy_func_map[F] = new_F;
  return new_F;  
}


llvm::Function* replace_llvm_function(Module* SM, Module* DM, std::string func_name){
  LFC_TRACE2("replace_llvm_function: func=", func_name);

  Function* SF = get_llvm_func(SM, func_name);
  if(SF == NULL){
    LFC_TRACE2("func not found in SM, func=", func_name);
    return NULL;
  }

  Function* DF = get_llvm_func(DM, func_name);
  if(DF == NULL){
    LFC_TRACE2("func not found in DM, func=", func_name);
    return NULL;
  }
  
  auto& DC = DM->getContext();
  auto& SC = SM->getContext();
  assert(&DC == &SC && "Can't copy function to diff context");

  ModelCopyHelper MC(DM);

  Function* new_DF = MC._get_copy_func(SF, 0);
  assert(new_DF && "fail to copy function");

  return new_DF;
}


std::vector<llvm::Function*> 
replace_llvm_function(std::string ir, llvm::Module* DM, const std::vector<std::string>& func_list){
  LFC_TRACE2("replace_llvm_function: ir=", ir);
  LFC_TRACE_LIST("func_list", func_list);

  auto SM = load_llvm_module(ir, DM->getContext());;
  assert(SM && "fail to load example module");

  auto& DC = DM->getContext();
  auto& SC = SM->getContext();
  assert(&DC == &SC && "Can't copy function to diff context");

  ModelCopyHelper MC(DM);
  std::vector<llvm::Function*> copied_func_vec;
  for(auto func_name : func_list){
    
    Function* SF = get_llvm_func(SM.get(), func_name);
    if(SF == NULL){
      LFC_TRACE2("func not found in SM, func=", func_name);
      continue;
    }

    Function* DF = get_llvm_func(DM, func_name);
    if(DF == NULL){
      LFC_TRACE2("func not found in DM, func=", func_name);
      continue;
    }
    
    Function* new_DF = MC._get_copy_func(SF, 0);
    assert(new_DF && "fail to copy function");
    copied_func_vec.push_back(new_DF);
  }

  return copied_func_vec;
}


} // namespace lfc 


