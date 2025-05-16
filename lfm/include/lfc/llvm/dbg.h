// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_DBG_UTIL_H__
#define __LFC_DBG_UTIL_H__

#include "llvm/IR/Instructions.h"
#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "lfc/llvm/src_scope.h"
namespace lfc {

// Debug Declare Var
struct DbgDeclareVar {
  std::string var_name;
  std::string type_name;
  int         type_ptr_lvl;

  std::string declare_name;
  int         declare_loc;
};

std::vector<DbgDeclareVar> get_block_ddv(llvm::BasicBlock *B, bool ignore_opaque_ptr = true);

/************************************************************/
// Debug Info Helper
/************************************************************/
class DBGUtilImpl;
class DBGUtil{
public:
  DBGUtil();
  ~DBGUtil();

  void update_function(llvm::Function* F);
  DbgDeclareVar* find_ddv(llvm::Value* val);

private:
  class DBGUtilImpl* impl = NULL;
};

void remove_debug_info(llvm::Module* M);
int  get_llvm_inst_dbg_loc(llvm::Instruction* I);
bool get_llvm_block_scope(llvm::BasicBlock* BB, SrcScope& SS);
bool get_llvm_function_scope(llvm::Function* F, SrcScope& SS);


} // namespace lfc
LFC_TO_STRING_DEF(DbgDeclareVar);
TRACE_SUB_MODULE_DEF(dbg_util)
#endif // __LFC_DBG_UTIL_H__

