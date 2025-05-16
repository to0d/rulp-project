; ModuleID = 'data_base/llvm_util_swap/swap_llvm_call_inst_1_input.ll'
source_filename = "input.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"
define dso_local void @_Z3fooi(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  call void @fun2(i32 noundef 2)
  call void @fun1(i32 noundef 1)
  %3 = load i32, i32* %2, align 4
  ret void
}
declare void @fun1(i32 noundef)
declare void @fun2(i32 noundef)
