// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[llvm_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(llvm_util)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(llvm_util)
#include "lfc/llvm/macro.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/abi.h"
#include "lfc/base/container.h"
#include "lfc/base/collection.h"
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

std::string get_llvm_argument_name(Argument* A){
  return get_llvm_value_name(A);
}

std::string get_llvm_block_name(llvm::BasicBlock* BB){
  if( BB == nullptr )
      return "";
  
  if (!BB->getName().empty())
      return BB->getName().str();
  
  std::string Str;
  raw_string_ostream OS(Str);

  BB->printAsOperand(OS, false);
  return OS.str();
}


std::string get_llvm_func_name(llvm::Function* F){
  std::string func_name = F->getName().str();
  func_name = demangle_func_name(func_name);
  return func_name;
}


std::string get_llvm_inst_string(llvm::Instruction* inst){
  std::string str;
  raw_string_ostream OS(str);
  inst->print(OS,false);
  return lfc::str_trim(OS.str());
}

std::string get_llvm_global_var_name(llvm::GlobalVariable* G){
  std::string str;
  raw_string_ostream OS(str);
  G->printAsOperand(OS,false);
  return OS.str();
}

std::string get_llvm_value_name(llvm::Value* val) {
  std::string str;
  raw_string_ostream OS(str);
  val->printAsOperand(OS,false);
  return OS.str();
}

std::string get_llvm_type_name(llvm::Type* type){
  std::string str;
  raw_string_ostream OS(str);
  type->print(OS,false);  
  return OS.str();
}

int get_llvm_var_index(const std::string& name){
  std::string::size_type idx = name.find("%");
  if( idx == std::string::npos)
    return -1;

  std::string index_str = name.substr(idx+1, name.length());
  int num = std::stoi(index_str);
  return num;  
}

std::vector<llvm::Value*> get_llvm_call_operands(llvm::CallInst* CI){
  if(!CI){
    return {};
  }

  unsigned int num_operands = CI->getNumOperands() - 1;
  std::vector<llvm::Value*> opds;

  for(unsigned int r = 0; r < num_operands; r++){
    opds.push_back(CI->getOperand(r));
  }

  return std::move(opds);
}

bool has_llvm_common_var(const std::vector<std::string>& a, const std::vector<std::string>& b){
  if( a.empty() || b.empty() )
    return false;

  std::vector<int> aa, bb;
  for(auto& v : a){
    int index = get_llvm_var_index(v);
    assert(index !=-1 && "invalid var name");
    aa.push_back(index);
  }

  for(auto& v : b){
    int index = get_llvm_var_index(v);
    assert(index !=-1 && "invalid var name");
    bb.push_back(index);
  }

  // The var list should has descending order: example %3 %2 %1...
  std::sort(aa.begin(), aa.end(), std::less<int>());
  std::sort(bb.begin(), bb.end(), std::less<int>());

  return has_common_index(aa.begin(), aa.end(), bb.begin(), bb.end(), [](int v){return v;});
}


bool is_llvm_ir_var(const std::string& name){
  return get_llvm_var_index(name) != -1;
}

bool is_llvm_intrinsic(const std::string& name){
  static const std::string llvm_instrinsics_prefix= "llvm.";
  return name.length() > llvm_instrinsics_prefix.length() 
      && name.substr(0, llvm_instrinsics_prefix.length()).compare(llvm_instrinsics_prefix) == 0;
}

bool is_llvm_empty_function(Function* F){
  if(!F)
    return true;
  
  for(BasicBlock& B : *F){  
    for(Instruction& I : B){
      return false;
    }
  }
  return true;
}

bool is_cxx_class_func(const std::string& func_name){
  return func_name.find("::") != std::string::npos;
}

Function* get_llvm_func(Module* M, const std::string& func_name){
  if( !M )
    return NULL;
  
  for(Function& F : *M){
    if(func_name == get_llvm_func_name(&F))
      return &F;
  }

  return NULL;
}

bool has_llvm_inst_return_var(llvm::Instruction* I){
  if( !I)
    return false;

  switch (I->getOpcode()){
  case Instruction::Store         :
  case Instruction::Ret           :
  case Instruction::Br            : 
    return false;
  
  case Instruction::Call          : 
    {
      CallInst* CI = dyn_cast<CallInst>(I);
      return !CI->getType()->isVoidTy();
    }
  
  default: 
    break;
  }

  return true;
}

BasicBlock* get_llvm_block(Function* F, const std::string& block_name){
  if( !F )
    return NULL;

  for(BasicBlock& B : *F){
    if(block_name == get_llvm_block_name(&B))
      return &B;
  }

  return NULL;
}

std::vector<BasicBlock*> get_llvm_blocks(llvm::Function* F, const std::vector<std::string>& block_names){
  if( !F )
    return {};

  std::vector<BasicBlock*> blocks;
  std::set<std::string> name_set = to_set(block_names);

  for(BasicBlock& B : *F){
    std::string block_name = get_llvm_block_name(&B);
    if(name_set.count(block_name) != 0)
      blocks.push_back(&B);
  }

  return blocks;
}

llvm::Function* get_llvm_called_function(CallInst* CI){
  auto called_F = CI->getCalledFunction();
  if(called_F != NULL){
    return called_F;
  }

  Value* calledValue = CI->getCalledOperand();
  if(Function* calledFunction = dyn_cast<Function>(calledValue); calledFunction) {
    return calledFunction;
  }

  // call ptr @func()
  assert(false);
  return NULL;
}

std::vector<std::string> to_llvm_block_names(std::vector<BasicBlock*> blocks){
  std::vector<std::string> block_names;
  std::for_each(blocks.begin(), blocks.end(), [&block_names](auto& b){
    block_names.push_back(get_llvm_block_name(b));
  });
  return block_names;
}

std::string get_llvm_call_name(llvm::CallInst* CI){
  std::string callName;
  Function* callfunc = CI->getCalledFunction();
  if(callfunc == NULL){
    auto callopd = CI->getOperand(0);
    // errs() << "callopd: " << *callopd << "\n";
    callName = get_llvm_value_name(callopd);
    if(callName.length() > 0 && callName[0] == '@'){
      callName = callName.substr(1);
    }
  }
  else{
    // errs() << "callfunc: " << *callfunc << "\n";
    callName = callfunc->getName().str();
  }
  return callName;
}

std::unique_ptr<Module> load_llvm_module(std::string path, llvm::LLVMContext& context){
  SMDiagnostic error;
  return std::move(parseIRFile(path, error, context));
}

std::vector<std::string> dump_llvm_module(llvm::Module* M){
  std::string str;
  llvm::raw_string_ostream OS(str);
  M->print(OS, nullptr);  

  return STR_SPLIT_BY_CHAR(OS.str(), '\n');
}


bool verify_module(llvm::Module* M, std::string* err_msg){
  std::string errorStr;
  raw_string_ostream errorStream(errorStr);
  if (!verifyModule(*M, &errorStream)) {
    return true;
  }

  std::string err = errorStream.str();
  LFC_TRACE1("Module verification failed:");
  if( LFC_TRACE_ENABLE ){
    LFC_TRACE_STREAM << err << "\n";
  }

  if(err_msg != nullptr){
    *err_msg = err;
  }

  return false;
}

std::string to_string(llvm::Instruction* I){
  if(!I)
    return "I(null)";

  std::string out = "I(";
  out += get_llvm_inst_string(I);
  out += ")";
  return out;
}

std::string get_llvm_inst_info(llvm::Instruction* I){
  if(!I)
    return "null";

  if(BranchInst* brInst = dyn_cast<BranchInst>(I); brInst){

    if(brInst->isConditional()){
      Instruction* condInst   = dyn_cast<Instruction>(brInst->getCondition());
      return "br[" + get_llvm_value_name(condInst) +":"+
                get_llvm_block_name(brInst->getSuccessor(0))+","+
                get_llvm_block_name(brInst->getSuccessor(1))+"]";
    }
    else{
      return "br[" + get_llvm_block_name(brInst->getSuccessor(0))+"]";
    }    
  }

  if(SwitchInst* sw_inst = dyn_cast<SwitchInst>(I); sw_inst){
    std::vector<std::string> case_info;
    for(auto caseIt : sw_inst->cases()){
      ConstantInt* caseValue = caseIt.getCaseValue();
      std::string out = lfc::to_string(caseValue->getSExtValue());
      out += ":"+ get_llvm_block_name(caseIt.getCaseSuccessor());
      case_info.push_back(out);
    }

    std::string out = "d:" + get_llvm_block_name(sw_inst->getDefaultDest());
    case_info.push_back(out);
    
    return "sw:" + to_string(case_info);
  }

  if(ReturnInst* rtInst = dyn_cast<ReturnInst>(I); rtInst){
    return "ret";
  }

  return get_llvm_inst_info(I);
}


std::vector<Instruction*> get_all_llvm_instructions(Function* F, unsigned opcode){
  if(!F)
    return {};

  std::vector<Instruction*> inst_list;

  for(auto& BB : *F){
    for(auto& I : BB){
      if(I.getOpcode() == opcode){
        inst_list.push_back(&I);
      }

    }
  }

  return inst_list;
}


static Value* _get_const_value_before(Value* val, Instruction* I){

  auto BB = I->getParent();
  auto pos = BB->rbegin();
  auto end = BB->rend();
  for (; pos != end; ++pos) {
    if (&*pos == I) {
      ++pos;
      break;
    }
  }

  std::set<Value*> value_set;
  value_set.insert(val);

  Type* expect_type = val->getType();
  
  for (; pos != end; ++pos) {
    Instruction* inst = &*pos;
    // errs() << "I:" << get_llvm_inst_string(inst) << ", getNumOperands:" << inst->getNumOperands() << "\n";
    switch (inst->getOpcode()){
      case Instruction::Load:
      {        
        LoadInst* LI = dyn_cast<LoadInst>(inst);
        assert(LI);
        
        Value* src_val = LI->getOperand(0);
        if(value_set.count(src_val) == 0 && value_set.count(LI) != 0){
          assert(!is_llvm_constant_value(src_val));
          Type* src_pointer_type = src_val->getType();
          assert(is_llvm_pointer_type(src_pointer_type));

          PointerType* pt = dyn_cast<PointerType>(src_pointer_type);
          if(pt && !pt->isOpaque()){
            Type* src_type = pt->getNonOpaquePointerElementType();
            assert(expect_type == src_type);
          }
          
          // if(expect_type != src_type){
          //   errs() << "expect_type:" << get_llvm_type_name(expect_type) << "\n";
          //   errs() << "src_type:" << get_llvm_type_name(src_type) << "\n";
          // }
          
          value_set.insert(src_val);          
        }    

        break;
      }
      case Instruction::Store:
      {
        StoreInst* SI = dyn_cast<StoreInst>(inst);
        assert(SI);

        Value* src_val = SI->getOperand(0);
        Value* dst_val = SI->getOperand(1);

        if(value_set.count(src_val) == 0 && value_set.count(dst_val) != 0){
          assert(expect_type == src_val->getType());
          if(is_llvm_constant_value(src_val)){
            return src_val;
          }
          else{
            value_set.insert(src_val); 
          }        
        }

        break;
      }
    default:
      break;
    }

  }

  return NULL;
}

static bool _compute_ne_int(void* p0, void* p1){
  int v0 = *(int*)p0;
  int v1 = *(int*)p1;
  return v0 != v1;
}

static bool _compute_eq_int(void* p0, void* p1){
  int v0 = *(int*)p0;
  int v1 = *(int*)p1;
  return v0 == v1;
}

static bool _compute(CmpInst::Predicate P, Constant* c0, Constant* c1, bool& result){

  // errs() << "_computet: P=" << P << ", c0=" << get_llvm_value_name(c0) << ", c1=" << get_llvm_value_name(c1) << "\n";

  assert(c0->getType() == c1->getType());
  //assert();

  Type::TypeID cmp_type = c0->getType()->getTypeID();

  typedef bool (*cmp_func)(void*, void*);
  static cmp_func cmp_arr [CmpInst::LAST_ICMP_PREDICATE][100] = {0};
  static int cmp_init = 0;
  if(cmp_init == 0){
    cmp_arr[CmpInst::ICMP_EQ][Type::TypeID::IntegerTyID] = _compute_eq_int;
    cmp_arr[CmpInst::ICMP_NE][Type::TypeID::IntegerTyID] = _compute_ne_int;
    cmp_init = 1;
  }

  cmp_func _func = cmp_arr[P][cmp_type];
  if(_func == 0){
    // errs() << "not support: P=" << P << ", cmp_type=" << cmp_type << "\n";
    return false;
  }

  switch(cmp_type){
    case Type::TypeID::IntegerTyID:{
      int v0, v1;
      if(ConstantInt* C = dyn_cast<ConstantInt>(c0)){
        v0 = C->getSExtValue();
      }
      else{
        // errs() << "v0 not constant\n";
        return false;
      }

      if(ConstantInt* C = dyn_cast<ConstantInt>(c1)){
        v1 = C->getSExtValue();
      }
      else{
        // errs() << "v1 not constant\n";
        return false;
      }

      // errs() << "v0=" << v0 << ", v1=" << v1 << "\n";
      result = _func(&v0, &v1);
      return true;
    }
    default:
      // errs() << "not support: cmp_type=" << cmp_type << "\n";
      return false;
  }

  return false;
}

BasicBlock* get_ignored_block(llvm::BranchInst* BI){
  if(!BI || BI->isUnconditional())
    return NULL; 

  assert(BI->isConditional());

  Instruction* condInst = dyn_cast<Instruction>(BI->getCondition());
  assert(condInst);

  if(ICmpInst* CI = dyn_cast<ICmpInst>(condInst); CI){

    Value* v0 = CI->getOperand(0);
    Value* v1 = CI->getOperand(1);

    // errs() << "v0: " << get_llvm_value_name(v0) << "\n";
    // errs() << "v1: " << get_llvm_value_name(v1) << "\n";

    if(!is_llvm_constant_value(v0)){
      Value* C = _get_const_value_before(v0, CI);
      if(C){
        // errs() << "C0: " << get_llvm_value_name(C) << "\n";
        v0 = C;
      }
      else{
        return NULL;
      }
    }

    if(!is_llvm_constant_value(v1)){
      Value* C = _get_const_value_before(v1, CI);
      if(C){
        // errs() << "C1: " << get_llvm_value_name(C) << "\n";
        v1 = C;
      }
      else{
        return NULL;
      }
    }

    bool rc;
    if(!_compute(CI->getPredicate(), dyn_cast<Constant>(v0), dyn_cast<Constant>(v1), rc)){
      return NULL;
    }
 
    // errs() << "compute: rc=" << rc << "\n";
    // errs() << "BI->getSuccessor(0): " << get_llvm_block_name(BI->getSuccessor(0)) << "\n";
    // errs() << "BI->getSuccessor(1): " << get_llvm_block_name(BI->getSuccessor(1)) << "\n";
    return rc ? BI->getSuccessor(1) : BI->getSuccessor(0);
  }

  return NULL;
}

bool is_llvm_constant_value(Value* val){
  return val && isa<Constant>(val);
}

bool is_llvm_null_ptr(llvm::Value* val){
  if(!val)
    return false;
  
  if(ConstantData* CD = dyn_cast<ConstantData>(val); CD){
    return CD->isNullValue();
  }

  return false;  
}

bool is_llvm_same_type(llvm::Type* a, llvm::Type* b){
  assert(a);
  assert(b);

  auto id = a->getTypeID();
  if(id != b->getTypeID()){
    return false;
  }

  // #TODO: check more detail, for example: int8 int16 .etc
  return true;
}

bool is_llvm_same_function_type(llvm::FunctionType* a, llvm::FunctionType* b, bool report){
  assert(a);
  assert(b);

  // check para num
  if(a->getNumParams() != b->getNumParams()){
    if(report){
      LFC_TRACE4("unmatch para num: a=", a->getNumParams(), ", b=", b->getNumParams());
    }
    return false;
  }

  // check para type
  for(int i = 0; i < a->getNumParams(); ++i){
    Type* at = a->getParamType(i);
    Type* bt = b->getParamType(i);

    if(!is_llvm_same_type(at, bt)){
      if(report){
        LFC_TRACE6("unmatch para type: idx=", i, ", a=", *at, ", b=", *bt);
      }
      return false;
    }
  }
 
  // check return type
  {
    auto at = a->getReturnType();
    auto bt = b->getReturnType();

    if(!is_llvm_same_type(at, bt)){
      if(report){
        LFC_TRACE4("unmatch return type: a=", *at, ", b=", *bt);
      }
      return false;
    }
  }

  return true;
}

std::map<std::string, llvm::Instruction*> get_llvm_value_inst_map(llvm::Function* F){

  std::map<std::string, Instruction*> value_map;
  if (F){
    for(auto& BB : *F){
      for(auto &I : BB){
        if(I.getType()->getTypeID() != Type::TypeID::VoidTyID){
          auto var_name = get_llvm_value_name(&I);
          value_map[var_name] = &I;
        }
      }
    }
  }
  
  return std::move(value_map);
}

InstList get_all_llvm_instructions(InstPtr begin_inst, InstPtr end_inst){
  assert(begin_inst);
  assert(end_inst);
  assert(begin_inst->getParent() == end_inst->getParent() && "not in single block");

  auto BB = begin_inst->getParent();

  std::vector<Instruction*> need_removed_insts;

  bool find_begin = false, find_end = false;
  for(auto& I : *BB){
    
    if(!find_begin){
      if(&I == begin_inst){
        find_begin = true;
      }
    }
    else if (!find_end){
      if(&I == end_inst){
        find_end = true;
        break;
      }
      else {
        need_removed_insts.push_back(&I);
      }
    }
  }

  assert(find_begin && "begin_inst not found");
  assert(find_end && "end_inst not tound");

  return std::move(need_removed_insts);
}

bool is_llvm_pointer_type(llvm::Type* T){
  return T && isa<PointerType>(T);
}

std::vector<llvm::Function*> get_all_llvm_function(llvm::Module* M, bool ignore_empty_function){
  if(!M)
    return {};

  std::vector<llvm::Function*> func_vec;
  for(Function& F : M->getFunctionList()){
    if(ignore_empty_function && F.getInstructionCount() == 0){
      continue;
    }
    func_vec.push_back(&F);
  }

  return func_vec;
}

std::vector<std::string> 
to_llvm_func_names(std::vector<llvm::Function*> funcs){
  std::vector<std::string> names;
  std::for_each(funcs.begin(), funcs.end(), [&names](auto& F){
    names.push_back(get_llvm_func_name(F));
  });
  return names;
}


std::map<std::string, Function*> 
to_llvm_func_map(std::vector<llvm::Function*> funcs){
  std::map<std::string, Function*> func_map;
  std::for_each(funcs.begin(), funcs.end(), [&func_map](auto& F){
    func_map[get_llvm_func_name(F)] = F;
  });
  return func_map;
}

bool erase_llvm_module_flag(llvm::Module* M, const std::string& name){
  if(!M){
    return false;
  }

  NamedMDNode* MD = M->getNamedMetadata(LLVM_META_MODULE_FLAGS);
  if(!MD){
    return false;
  }

  bool found = false;
  SmallVector<Module::ModuleFlagEntry> old_flags;
  M->getModuleFlagsMetadata(old_flags);
  for(auto& MF : old_flags){
    if(MF.Key->getString() == name){
      found = true;
    }
  }

  if(!found){
    return false;
  }

  MD->eraseFromParent();
  for(auto& MF : old_flags){
    if(MF.Key->getString() != name){
      M->addModuleFlag(MF.Behavior,MF.Key->getString(),MF.Val);
    }
  }

  return true;
}

bool update_llvm_inst_const(Instruction* I, int idx, int inc){
  LFC_TRACE4("update_llvm_inst_const: idx=", idx, ", ",lfc::get_llvm_inst_string(I));

  auto& MC = I->getParent()->getParent()->getContext();

  Value* old_val = I->getOperand(idx);
  Value* new_val = NULL;

  if(ConstantInt* C = dyn_cast<ConstantInt>(old_val); C){
    int64_t num = C->getSExtValue();
    new_val = ConstantInt::get(Type::getInt64Ty(MC), num + inc);
  } 
  else if(ConstantExpr* CE = dyn_cast<ConstantExpr>(old_val); CE){
    int opcode = CE->getOpcode();
    if(opcode == Instruction::IntToPtr){
      auto* val = CE->getOperand(0);
      if(ConstantInt* C = dyn_cast<ConstantInt>(val); C){
        int64_t num = C->getSExtValue();
        ConstantInt* new_C = ConstantInt::get(Type::getInt64Ty(MC), num + inc);
        new_val = ConstantExpr::getIntToPtr(new_C, CE->getType());
      }
    }
  }

  if(new_val != NULL){
    I->setOperand(idx, new_val);
    LFC_TRACE2("update inst : ", lfc::get_llvm_inst_string(I));
    return true;
  }

  return false;
}

} // namespace lfc

