target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

declare i32 @simd_convert_to_relative_addr(i64 noundef) #0
declare i32 @Gemm( i32 noundef) #0

define i32 @foo(double* noundef %0) {
    %2 = alloca double*, align 8    
    %3 = alloca i32, align 4
    %4 = alloca double*, align 8
    store double* %0, double** %4, align 8
    %5 = load double*, double** %4, align 8
    store double* %5, double** %2, align 8
    %6 = load double*, double** %2, align 8
    %7 = bitcast double* %6 to i8*
    %8 = ptrtoint i8* %7 to i64
    %9 = call i32 @simd_convert_to_relative_addr(i64 noundef %8)
    store i32 %9, i32* %3, align 4
    %10 = load i32, i32* %3, align 4
    %11 = call i32 @Gemm(i32 noundef %10)
    ret i32 %11
}

attributes #0 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

