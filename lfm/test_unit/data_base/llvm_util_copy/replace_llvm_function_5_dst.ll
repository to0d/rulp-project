; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_5_tgt.ll'
source_filename = "data_base/llvm_util_copy/replace_llvm_function_5_tgt.ll"
%struct.xxx = type { i32 }
define dso_local i32 @foo() {
  %1 = alloca %struct.xxx*, align 8
  %2 = call %struct.xxx* @create_xx()
  store %struct.xxx* %2, %struct.xxx** %1, align 8
  %3 = load %struct.xxx*, %struct.xxx** %1, align 8
  call void @func1(%struct.xxx* %3)
  %4 = load %struct.xxx*, %struct.xxx** %1, align 8
  call void @des_xx(%struct.xxx* %4)
  %5 = load %struct.xxx*, %struct.xxx** %1, align 8
  %6 = getelementptr inbounds %struct.xxx, %struct.xxx* %5, i32 0, i32 0
  %7 = load i32, i32* %6, align 4
  ret i32 %7
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
declare %struct.xxx* @create_xx()
declare void @des_xx(%struct.xxx* noundef)
