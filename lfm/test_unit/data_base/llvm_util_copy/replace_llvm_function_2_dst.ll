; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_2_tgt.ll'
source_filename = "data_base/llvm_util_copy/replace_llvm_function_2_tgt.ll"
%struct.xxx = type { i32 }
define dso_local i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  %3 = alloca %struct.xxx, align 8
  store i32 %0, i32* %2, align 4
  call void @func1(%struct.xxx* %3)
  %4 = getelementptr inbounds %struct.xxx, %struct.xxx* %3, i32 0, i32 0
  %5 = load i32, i32* %4, align 4
  ret i32 %5
}
define dso_local void @func1(%struct.xxx* noundef %0) {
  %2 = alloca %struct.xxx*, align 8
  store %struct.xxx* %0, %struct.xxx** %2, align 8
  %3 = load %struct.xxx*, %struct.xxx** %2, align 8
  %4 = getelementptr inbounds %struct.xxx, %struct.xxx* %3, i32 0, i32 0
  %5 = load i32, i32* %4, align 4
  %6 = add nsw i32 %5, 1
  store i32 %6, i32* %4, align 4
  ret void
}
