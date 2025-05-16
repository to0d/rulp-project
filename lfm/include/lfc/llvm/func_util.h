// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_FUNC_UTIL_H__
#define __LFC_FUNC_UTIL_H__

#include "lfc/llvm/func_call.h"
#include "lfc/llvm/dfg.h"
#include "lfc/llvm/func_def.h"
#include "lfc/base/dot.h"
#include "lfc/base/function.h"
#include "lfc/base/trace_macro.h"
#include "llvm/IR/Instructions.h"

namespace lfc {

typedef function<std::vector<DFGNode*>(const std::vector<DFGNode*>&, DFGUtil&)> dfg_select_func;

class FuncUtilImpl;
class FuncUtil{
public:
public:
    FuncUtil();
    FuncUtil(const std::vector<FuncDef>& fd_list);
    FuncUtil(const std::vector<FuncDef>& fd_list, const std::vector<dfg_select_func>& func_list);
    ~FuncUtil();

    void add_func_def_list(const std::vector<FuncDef>& fd_list);
    void add_dfg_func_list(const std::vector<dfg_select_func>& func_list);

    void update_function(llvm::Function* F);

    std::vector<FuncCall>         load_func_call_list(llvm::BasicBlock* B);
    std::vector<FuncCall>         load_func_call_list(llvm::Function* F);
    std::vector<std::vector<int>> build_dep_array(const std::vector<FuncCall>& fc_list);
    std::vector<std::vector<int>> build_dep_array2(const std::vector<FuncCall>& fc_list);

    std::vector<int>              get_func_params(const std::string& func);
    std::vector<DFGNode*>         get_func_dfg_nodes();

private:
    class FuncUtilImpl* impl;
};


}// namespace lfc

TRACE_SUB_MODULE_DEF(func_util)

#endif // __LFC_FUNC_UTIL_H__

