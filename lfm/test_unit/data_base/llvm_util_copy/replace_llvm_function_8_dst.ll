; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_8_tgt.ll'
source_filename = "data_base/llvm_util_copy/replace_llvm_function_8_tgt.ll"
@__const.func1.values = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
define dso_local i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @func1(i32 %3)
  ret i32 %4
}
define dso_local i32 @func1(i32 noundef %0) {
  %2 = alloca i32, align 4
  %3 = alloca [7 x i32], align 16
  store i32 %0, i32* %2, align 4
  %4 = bitcast [7 x i32]* %3 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %4, i8* bitcast ([7 x i32]* @__const.func1.values to i8*), i64 28, i1 false)
  %5 = load i32, i32* %2, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds [7 x i32], [7 x i32]* %3, i64 0, i64 %6
  %8 = load i32, i32* %7, align 4
  ret i32 %8
}
; Function Attrs: argmemonly nocallback nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #0
attributes #0 = { argmemonly nocallback nofree nounwind willreturn }
