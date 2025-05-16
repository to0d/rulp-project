; ModuleID = 'input.c'
source_filename = "input.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.CoreExecutor_T = type { i32 }
%struct.DreExecutor_T = type { i32 }

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @foo() #0 {
  %1 = alloca double*, align 8
  %2 = alloca double*, align 8
  %3 = alloca double*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca %struct.CoreExecutor_T*, align 8
  %8 = alloca %struct.DreExecutor_T*, align 8
  %9 = call %struct.CoreExecutor_T* (...) @simd_gemm_executor_create()
  store %struct.CoreExecutor_T* %9, %struct.CoreExecutor_T** %7, align 8
  %10 = call %struct.DreExecutor_T* (...) @simd_dre_executor_create()
  store %struct.DreExecutor_T* %10, %struct.DreExecutor_T** %8, align 8
  %11 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %7, align 8
  %12 = load double*, double** %1, align 8
  %13 = load double*, double** %2, align 8
  %14 = load double*, double** %3, align 8
  %15 = load i32, i32* %4, align 4
  %16 = load i32, i32* %5, align 4
  %17 = load i32, i32* %6, align 4
  %18 = call i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T* noundef %11, double* noundef %12, double* noundef %13, double* noundef %14, i32 noundef %15, i32 noundef %16, i32 noundef %17, i32 noundef 0, i32 noundef 0, i32 noundef 0, double noundef 1.000000e+00, double noundef 1.000000e+00)
  %19 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %8, align 8
  %20 = load double*, double** %1, align 8
  %21 = load double*, double** %2, align 8
  %22 = call i32 @simd_dre_executor_reshape(%struct.DreExecutor_T* noundef %19, double* noundef %20, double* noundef %21, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0)
  %23 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %7, align 8
  %24 = load double*, double** %2, align 8
  %25 = load double*, double** %3, align 8
  %26 = load double*, double** %3, align 8
  %27 = load i32, i32* %4, align 4
  %28 = load i32, i32* %5, align 4
  %29 = load i32, i32* %6, align 4
  %30 = call i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T* noundef %23, double* noundef %24, double* noundef %25, double* noundef %26, i32 noundef %27, i32 noundef %28, i32 noundef %29, i32 noundef 0, i32 noundef 0, i32 noundef 0, double noundef 1.000000e+00, double noundef 1.000000e+00)
  %31 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %7, align 8
  call void @simd_gemm_executor_destroy(%struct.CoreExecutor_T* noundef %31)
  %32 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %8, align 8
  call void @simd_dre_executor_destroy(%struct.DreExecutor_T* noundef %32)
  ret void
}

declare %struct.CoreExecutor_T* @simd_gemm_executor_create(...) #1

declare %struct.DreExecutor_T* @simd_dre_executor_create(...) #1

declare i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T* noundef, double* noundef, double* noundef, double* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, double noundef, double noundef) #1

declare i32 @simd_dre_executor_reshape(%struct.DreExecutor_T* noundef, double* noundef, double* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) #1

declare void @simd_gemm_executor_destroy(%struct.CoreExecutor_T* noundef) #1

declare void @simd_dre_executor_destroy(%struct.DreExecutor_T* noundef) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
