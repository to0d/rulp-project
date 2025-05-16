; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_14_tgt.ll'
source_filename = "data_base/llvm_util_copy/replace_llvm_function_14_tgt.ll"
@values = internal constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
define dso_local i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 @func1(i32 %3)
  ret i32 %4
}
define dso_local i32 @func1(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = sext i32 %3 to i64
  %5 = getelementptr inbounds [7 x i32], ptr @values, i64 0, i64 %4
  %6 = load i32, ptr %5, align 4
  ret i32 %6
}
