#ifndef UNITEST_LLVM_H
#define UNITEST_LLVM_H

#include "lfc/llvm.h"
#include "lfc/base/string/util.h"
#include "gtest/gtest.h"

#define LOAD_LLVM_FUNCTION(path, func) \
LLVMContext context; \
std::unique_ptr<Module> M = load_llvm_module(path, context); \
EXPECT_TRUE(M != NULL); \
Function* F = get_llvm_func(M.get(), func); \
EXPECT_TRUE(F != NULL);

#endif // UNITEST_LLVM_H

