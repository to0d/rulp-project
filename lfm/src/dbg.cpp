// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/trace_macro.h"
#define LFC_TRACE_NAME   "[dbg_util]"
#define LFC_TRACE_NEED   TRACE_GET_TRACE(dbg_util)()
#define LFC_TRACE_STREAM llvm::errs()
TRACE_SUB_MODULE_IMPL(dbg_util)
#include "lfc/llvm/macro.h"
#include "lfc/llvm/dbg.h"
#include "lfc/llvm/llvm_util.h"
#include "lfc/base/trace.h"
#include "lfc/base/container.h"
#include <map>
#include <set>
#include <vector>
#include "llvm/IR/Constants.h"
#include "llvm/IR/DebugInfoMetadata.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>

using namespace llvm;

LLVM_DECLARE_MIN_VERSION_15

namespace lfc {

/************************************************************/
// Debug Declare Var
/************************************************************/

static std::pair<std::string, int> get_pointer_type_info(Type* type) {
  if( type == NULL )
    return std::pair<std::string, int>("", -1);

  switch (type->getTypeID()){
  case Type::DoubleTyID:
  case Type::IntegerTyID:
    return std::pair<std::string, int>(get_llvm_type_name(type), 0);
  default:
    break;
  }

  if( StructType* ST = dyn_cast<StructType>(type) ){
     return std::pair<std::string, int>(ST->getName(), 0);
  }

  if( PointerType* PT = dyn_cast<PointerType>(type) ){
    assert(!PT->isOpaque() && "not support opaque pointer yet");
    Type* ET = PT->getNonOpaquePointerElementType();
    assert(ET);

    auto rst = get_pointer_type_info(ET);
    return std::pair<std::string, int>(rst.first, rst.second+1);
  }

  // errs() << "type=" << *type << "\n";  
  // llvm_unreachable("unsupport type");
  return std::pair<std::string, int>("", -1);
}

std::vector<DbgDeclareVar> get_block_ddv(llvm::BasicBlock* B, bool ignore_opaque_ptr){
  if( !B )
    return {};

  std::vector<DbgDeclareVar> decVars; 

  // std::string blockName = get_llvm_block_name(B);      
  // errs() << "block: namne=" << blockName << "\n" ;        
  for(Instruction& I : *B){
    if(!isa<CallInst>(I)){
      continue;
    }
    
    CallInst* CI = dyn_cast<CallInst>(&I);
    std::string callFuncName = get_llvm_call_name(CI);

    if(callFuncName == LLVM_INTRINSICS_DBG_DECLARE || callFuncName == LLVM_INTRINSICS_DBG_VALUE){

      unsigned int num_operands = I.getNumOperands();
      assert(num_operands > 2);
      // errs() << "\t\tnum_operands:\t" << num_operands << "\n";
      
      Value* varOpd = CI->getArgOperand(0);       
      if( varOpd == NULL)
        continue;
      
      MetadataAsValue* varMAV = dyn_cast<MetadataAsValue>(varOpd);
       if( varMAV == NULL)
        continue;

      DbgDeclareVar DBV;

      ValueAsMetadata* varMD = dyn_cast<ValueAsMetadata>(varMAV->getMetadata());
      if( varMD == NULL)
        continue;

      Value* varVal =  varMD->getValue();
      Type* varType =  varMD->getType();

      DBV.var_name = get_llvm_value_name(varVal);

      bool is_opaque_ptr = false;
      if(PointerType* pt = dyn_cast<PointerType>(varType); pt){
         is_opaque_ptr = pt->isOpaque();
      }
      
      if(is_opaque_ptr && ignore_opaque_ptr){
        continue;
      }

      if(!is_opaque_ptr){
        auto vn = get_pointer_type_info(varType);
        if( vn.first == "" ){
          continue;
        }

        DBV.type_name = vn.first; 
        DBV.type_ptr_lvl = vn.second;
        assert(DBV.type_ptr_lvl >= -1);
      }

      MetadataAsValue* nameMAV = dyn_cast<MetadataAsValue>(CI->getArgOperand(1));
      if( nameMAV == NULL )
        continue;          

      DILocalVariable* nameMD = dyn_cast<DILocalVariable>(nameMAV->getMetadata());
      if( nameMD == NULL )
        continue;

      DBV.declare_name = nameMD->getName().str();
      DBV.declare_loc = get_llvm_inst_dbg_loc(&I);

      decVars.push_back(DBV);
    }
  }  
  
  return decVars;
}


class DBGUtilImpl{
  friend class DBGUtil;
public:
  DBGUtilImpl(): m_last_func(NULL), m_load_func_ddv(false){};
  void update_function(Function* F);
  void update_ddv(DbgDeclareVar* DDV);

  DbgDeclareVar* get_ddv(const std::string& var);


private:
  std::map<std::string, DbgDeclareVar> m_ddv_var_name_map;
  Function* m_last_func;
  bool m_load_func_ddv;
};

DbgDeclareVar* DBGUtilImpl::get_ddv(const std::string& var){

  if(!m_load_func_ddv && m_last_func != NULL){
    LFC_TRACE2("Build DDV Name Map: F=", get_llvm_func_name(m_last_func));

    for(BasicBlock& BB : *m_last_func){
      
      std::vector<DbgDeclareVar> dbgDecVars = get_block_ddv(&BB);
      LFC_TRACE4("Block: name=", get_llvm_block_name(&BB), "declare vars=", dbgDecVars.size());

      // Build Global Declare Var Map     
      for(DbgDeclareVar& DDV : dbgDecVars){
        update_ddv(&DDV);
      }
    }

    m_load_func_ddv = true;
  }

  auto it = m_ddv_var_name_map.find(var);
  if( it == m_ddv_var_name_map.end())
    return NULL;

  DbgDeclareVar* DBV = &(it->second);
  LFC_TRACE2( "update DBV: ",lfc::to_string(DBV));
  return DBV;
}

void DBGUtilImpl::update_function(Function* F){
  if(m_last_func == F)
    return;

  m_last_func = F;
  m_load_func_ddv = false;
  m_ddv_var_name_map.clear();
}

void DBGUtilImpl::update_ddv(DbgDeclareVar* DDV){
  LFC_TRACE2( "update DDV: ", lfc::to_string(DDV));
  if( !DDV )
    return;
  m_ddv_var_name_map[DDV->var_name] = *DDV;
}

DBGUtil::DBGUtil(){
  impl = new DBGUtilImpl();
}

DBGUtil::~DBGUtil(){
  delete impl;
}


DbgDeclareVar* DBGUtil::find_ddv(llvm::Value* val){
  if(LoadInst* LI = dyn_cast<LoadInst>(val)){
    return find_ddv(LI->getOperand(0));
  }

  if(AllocaInst* AI = dyn_cast<AllocaInst>(val)){
    std::string varName = get_llvm_value_name(val);
    DbgDeclareVar* DBV = impl->get_ddv(varName);
    if( DBV == NULL ){
      LFC_TRACE2("DBV not found: var=", varName);
      return DBV;
    }
    return DBV;
  }

  return NULL;
}

void DBGUtil::update_function(Function* F){
  if(impl->m_last_func == F)
    return;
  
  impl->m_last_func = F;
}

LFC_TO_STRING_IMPL(DbgDeclareVar, DDV){
  if( !DDV )
    return "DDV(null)";

  std::string out = "DDV(";

  out += "var_name=";
  out += DDV->var_name;

  out += ", type_name=";
  out += DDV->type_name;

  out += ", type_ptr_lvl=";
  out += std::to_string(DDV->type_ptr_lvl);

  out += ", declare_name=";
  out += DDV->declare_name;

  out += ", declare_loc=";
  out += std::to_string(DDV->declare_loc);
  
  out += ")";

  return out;
}

int get_llvm_inst_dbg_loc(Instruction* I){
  if(!I){
    return -1;
  }

  int line_number = -1;
  DILocation* LOC = I->getDebugLoc().get();
  if(!LOC){
    return -1;
  }

  return LOC->getLine();
}

void remove_debug_info(llvm::Module* M){
  if(!M){
    return;
  }

  // remove DILocation
  {
    for(auto& F : *M){
      for(auto& BB : F){
        for(auto& I : BB){
          if(DILocation* LOC = I.getDebugLoc(); LOC){
            I.setDebugLoc(DebugLoc());
          }
        }
      }
    }
  }

  // remove inst: call void @llvm.dbg.declare
  {
    std::set<std::string> dbg_func_name_set = {LLVM_INTRINSICS_DBG_DECLARE};
    std::vector<Instruction*> dbg_inst_vec;
    std::vector<Function*>    dbg_func_vec;
    for(auto& F : *M){
      for(auto& BB : F){
        for(auto& I : BB){
          if(CallInst* CI = dyn_cast<CallInst>(&I); CI){
            if(std::string func_name = get_llvm_call_name(CI); dbg_func_name_set.count(func_name) != 0){
              dbg_inst_vec.push_back(CI);
              auto CF = CI->getCalledFunction();
              if(!lfc::find(dbg_func_vec, CF)){
                dbg_func_vec.push_back(CF);
              }
            }
          }
        }
      }
    }

    for(auto I : dbg_inst_vec){
      I->eraseFromParent();
    }

    for(auto F : dbg_func_vec){
      F->eraseFromParent();
    }
  }

  // remove DISubprogram
  {
    for(auto& F : *M){
      if(F.getSubprogram() != NULL){
        F.setSubprogram(nullptr);
      }       
    }
  }

  // remove DICompileUnit: "llvm.dbg.cu"
  if(NamedMDNode* MD = M->getNamedMetadata(LLVM_META_DBG_CU); MD){
    MD->eraseFromParent();
  }

  // remove module flag: "Dwarf Version"
  erase_llvm_module_flag(M, LLVM_FLAG_DWARF_VERSION);

  // remove module flag: "Debug Info Version"
  erase_llvm_module_flag(M, LLVM_FLAG_DEBUG_INFO_VER);

  
}

bool get_llvm_block_scope(llvm::BasicBlock* BB, SrcScope& SS){
  if(!BB){
    return false;
  }

  int start_line = -1;
  int end_line = -1;
  Instruction* first_inst = NULL;

  for(auto &I : *BB){
    int loc = get_llvm_inst_dbg_loc(&I);
    if(loc == -1)
      continue;
    
    if(first_inst == NULL)
      first_inst = &I;

    if(start_line == -1){
      start_line = loc;
      end_line   = loc;
    }
    else {
      assert(loc >= end_line && "invalid inst loc");
      end_line = loc;
    }
  }

  if(start_line == -1)
    return false; 

  assert(first_inst);
  if(first_inst != NULL){

    // llvm::errs() << "first_inst found: " << *first_inst  << "\n";

    DILocation* LOC = first_inst->getDebugLoc().get();
    assert(LOC);
    if(LOC){
      // std::cout << "LOC found" << "\n";
      auto scope = LOC->getScope();
      assert(scope);
      if (auto *LexicalBlock = llvm::dyn_cast<llvm::DILexicalBlock>(scope); LexicalBlock) {
        // std::cout << "LexicalBlock found" << "\n";
        unsigned line = LexicalBlock->getLine();
        unsigned Column = LexicalBlock->getColumn();
        // std::cout << "Line: " << line << ", Column: " << Column << "\n";
        if(start_line > line){
          start_line = line;
        }
      }
      
    }
  }

  // assert(false);

  SrcScope scope;
  scope.start_line  = start_line;
  scope.end_line    = end_line;

  SS = scope;

  return true;
}

bool get_llvm_function_scope(llvm::Function* F, SrcScope& SS){
  if(!F){
    return false;
  }

  if(F->isDeclaration()) {
    // ignore declare function
    return false;
  }

  DISubprogram* DISP = F->getSubprogram();
  if(!DISP){
    return false;
  }

  SrcScope FSS;

  FSS.file_name   = DISP->getFile()->getFilename();
  FSS.start_line  = DISP->getLine();
  int end_line = -1;

  for(auto& BB : *F){
    SrcScope BSS;
    if(get_llvm_block_scope(&BB, BSS)){
      end_line = std::max(end_line, BSS.end_line); 
    }
  }

  FSS.end_line = end_line;

  SS = FSS;
  return true;  
}



} // namespace lfc 