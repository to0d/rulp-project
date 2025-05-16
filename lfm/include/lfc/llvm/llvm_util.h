// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_LLVM_UTIL_H__
#define __LFC_LLVM_UTIL_H__


#include "lfc/base/trace_macro.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Module.h"
#include <map>
#include <vector>
namespace lfc {

typedef llvm::Instruction*                InstPtr;
typedef llvm::Module*                     ModulePtr;
typedef llvm::Function*                   FuncPtr;
typedef llvm::BasicBlock*                 BlockPtr;
typedef std::vector<std::string>          StrList;
typedef std::vector<llvm::Instruction*>   InstList;
typedef std::vector<llvm::Function*>      FuncList;
typedef std::vector<llvm::BasicBlock*>    BlockList;
typedef std::vector<llvm::Value*>         ValueList;
typedef std::map<std::string, InstPtr>    value_inst_map;
typedef std::map<std::string, FuncPtr>    name_func_map;

/*****************************************************************/
// Info Utils
/*****************************************************************/
std::string get_llvm_argument_name(llvm::Argument* A);
std::string get_llvm_block_name(BlockPtr BB);
std::string get_llvm_func_name(FuncPtr);
std::string get_llvm_inst_string(InstPtr);
std::string get_llvm_value_name(llvm::Value* val);
std::string get_llvm_type_name(llvm::Type* type);
std::string get_llvm_call_name(llvm::CallInst* CI);
std::string get_llvm_global_var_name(llvm::GlobalVariable* G);
std::string to_string(InstPtr);
std::string get_llvm_inst_info(InstPtr);

int  get_llvm_var_index(const std::string& name);
bool has_llvm_common_var(const StrList& a, const StrList& b);
bool has_llvm_inst_return_var(InstPtr);
bool is_llvm_ir_var(const std::string& name);
bool is_llvm_intrinsic(const std::string& name);
bool is_llvm_empty_function(FuncPtr F);
bool is_llvm_constant_value(llvm::Value* val);
bool is_llvm_pointer_type(llvm::Type* T);
bool is_llvm_null_ptr(llvm::Value* val);
bool is_llvm_same_type(llvm::Type* a, llvm::Type* b);
bool is_llvm_same_function_type(llvm::FunctionType* a, llvm::FunctionType* b, bool report = false);
bool is_cxx_class_func(const std::string& func_name);

FuncPtr     get_llvm_func (ModulePtr M, const std::string& func_name);
FuncList    get_all_llvm_function(ModulePtr M, bool ignore_empty_function = false);
InstList    get_all_llvm_instructions(FuncPtr F, unsigned opcode);
InstList    get_all_llvm_instructions(InstPtr begin, InstPtr end);
BlockPtr    get_llvm_block  (FuncPtr F, const std::string& block_name);
BlockList   get_llvm_blocks (FuncPtr F, const StrList& block_names);
FuncPtr     get_llvm_called_function(llvm::CallInst* CI);
ValueList   get_llvm_call_operands(llvm::CallInst* CI);

value_inst_map  get_llvm_value_inst_map(FuncPtr F);

/*****************************************************************/
// Opt Utils
/*****************************************************************/
bool        is_all_in_dom_path(const BlockList& blocks);
BlockPtr    get_ignored_block(llvm::BranchInst* BI);

/*****************************************************************/
// Read/Write Utils
/*****************************************************************/
std::unique_ptr<llvm::Module>   
            load_llvm_module(std::string path, llvm::LLVMContext& context);
StrList     dump_llvm_module(ModulePtr M);

/*****************************************************************/
// Modify Utils
/*****************************************************************/
bool        swap_llvm_call_inst   (FuncPtr F, int a, int b);
FuncPtr     replace_llvm_function (ModulePtr SM, ModulePtr DM, std::string func_name);
FuncList    replace_llvm_function (std::string ir, ModulePtr DM, const StrList& func_list);
FuncPtr     copy_llvm_function    (ModulePtr SM, ModulePtr DM, std::string func_name);
FuncList    copy_llvm_function    (const std::string& ir, ModulePtr DM, const StrList& func_list);
bool        verify_module          (ModulePtr M, std::string* err_msg = nullptr);
bool        erase_llvm_module_flag(ModulePtr M, const std::string& name);
bool        update_llvm_inst_const(InstPtr I, int idx, int inc);

/*****************************************************************/
// Other Utils
/*****************************************************************/
StrList         to_llvm_block_names(BlockList blocks);
StrList         to_llvm_func_names(FuncList funcs);
name_func_map   to_llvm_func_map(FuncList funcs);

} // namespace lfc
TRACE_SUB_MODULE_DEF(llvm_util);
#endif // __LFC_LLVM_UTIL_H__

