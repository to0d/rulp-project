; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_9_tgt.ll'
source_filename = "data_base/llvm_util_copy/replace_llvm_function_9_tgt.ll"
%struct.xxx.0 = type { i32 }
%struct.xxx = type { i32 }
define dso_local i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  %3 = alloca %struct.xxx.0, align 4
  store i32 %0, ptr %2, align 4
  call void @func1(ptr %3)
  %4 = getelementptr inbounds %struct.xxx.0, ptr %3, i32 0, i32 0
  %5 = load i32, ptr %4, align 4
  ret i32 %5
}
define dso_local void @func1(ptr noundef %0) {
  %2 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  %3 = load ptr, ptr %2, align 8
  %4 = getelementptr inbounds %struct.xxx, ptr %3, i32 0, i32 0
  %5 = load i32, ptr %4, align 4
  %6 = add nsw i32 %5, 1
  store i32 %6, ptr %4, align 4
  ret void
}
