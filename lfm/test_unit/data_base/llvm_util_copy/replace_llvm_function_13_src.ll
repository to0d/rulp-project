; int func1(int x){
;   int values[7] = {0, 1, 2, 3, 4, 5, 6};
;   return values[x];
; }

@__const.func1.values = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16

define dso_local i32 @func1(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca [7 x i32], align 16
  store i32 %0, ptr %2, align 4
  call void @llvm.memcpy.p0.p0.i64(ptr align 16 %3, ptr align 16 @__const.func1.values, i64 28, i1 false)
  %4 = load i32, ptr %2, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds [7 x i32], ptr %3, i64 0, i64 %5
  %7 = load i32, ptr %6, align 4
  ret i32 %7
}

declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) 

