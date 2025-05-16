; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_10_tgt.ll'
source_filename = "data_base/llvm_util_copy/replace_llvm_function_10_tgt.ll"
define dso_local i32 @foo(i32 %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @func1(i32 %3)
  %5 = add nsw i32 %4, 1
  ret i32 %5
}
define dso_local i32 @func1(i32 %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @func2(i32 %3)
  %5 = add nsw i32 %4, 1
  ret i32 %5
}
define internal i32 @func2(i32 %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = add nsw i32 %3, 1
  ret i32 %4
}
