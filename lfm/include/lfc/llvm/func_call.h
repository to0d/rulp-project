// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNC_CALL_H__
#define __LFC_FUNC_CALL_H__

#include "lfc/base/trace_macro.h"
#include "lfc/base/to_string_macro.h"
#include "llvm/IR/Instructions.h"

namespace lfc {

struct FuncCall {
  std::string               func_name;
  llvm::CallInst*           call_inst;

  // parameter info
  std::vector<std::string>  para_list;

  // return var
  std::string               ret_var;

  // debug info
  int                       src_loc;

  FuncCall();
  FuncCall(const FuncCall& FC);
  FuncCall(FuncCall&& FC);

  FuncCall& operator=(const FuncCall &FC);
  FuncCall& operator=(FuncCall &&FC);

  void update_para_list();
  void update_debug_info();
};

std::vector<FuncCall> load_block_func_call_list(llvm::BasicBlock* B);

}// namespace lfc

LFC_TO_STRING_DEF(FuncCall);
TRACE_SUB_MODULE_DEF(func_call);

#endif // __LFC_FUNC_CALL_H__

