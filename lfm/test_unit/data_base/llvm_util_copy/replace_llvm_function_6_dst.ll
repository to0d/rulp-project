; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_6_tgt.ll'
source_filename = "data_base/llvm_util_copy/replace_llvm_function_6_tgt.ll"
define dso_local void @foo() {
  call void @func1()
  ret void
}
define dso_local void @func1() {
  call void @func2()
  ret void
}
declare void @func2()
