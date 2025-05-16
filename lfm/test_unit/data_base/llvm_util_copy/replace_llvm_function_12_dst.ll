; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_12_tgt.ll'
source_filename = "data_base/llvm_util_copy/replace_llvm_function_12_tgt.ll"
define dso_local i32 @foo(i32 %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @func1(i32 %3)
  ret i32 %4
}
define dso_local i32 @func1(i32 %0) {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  store i32 0, i32* %3, align 4
  %4 = load i32, i32* %2, align 4
  switch i32 %4, label %8 [
    i32 0, label %5
    i32 1, label %6
    i32 2, label %7
  ]
5:                                                ; preds = %1
  store i32 1, i32* %3, align 4
  br label %9
6:                                                ; preds = %1
  store i32 10, i32* %3, align 4
  br label %9
7:                                                ; preds = %1
  store i32 100, i32* %3, align 4
  br label %9
8:                                                ; preds = %1
  br label %9
9:                                                ; preds = %8, %7, %6, %5
  %10 = load i32, i32* %3, align 4
  ret i32 %10
}
