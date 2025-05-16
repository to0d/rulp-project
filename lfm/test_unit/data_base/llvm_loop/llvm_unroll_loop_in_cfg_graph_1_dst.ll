; ModuleID = 'data_base/llvm_loop/llvm_unroll_loop_in_cfg_graph_1.ll'
source_filename = "input.c"
target datalayout = "e-m:e-p:64:64-i64:64-i128:128-n32:64-S128"
target triple = "riscv64-unknown-unknown-elf"
; Function Attrs: noinline nounwind optnone
define dso_local void @foo(ptr noundef %0, ptr noundef %1, ptr noundef %2) #0 {
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  store ptr %0, ptr %4, align 8
  store ptr %1, ptr %5, align 8
  store ptr %2, ptr %6, align 8
  store i32 100, ptr %7, align 4
  store i32 100, ptr %8, align 4
  store i32 100, ptr %9, align 4
  store i32 10, ptr %10, align 4
  call void @__sdc_scb_begin__(i32 1, i32 1)
  store i32 0, ptr %11, align 4
  br label %12
12:                                               ; preds = %40, %3
  %13 = load i32, ptr %11, align 4
  %14 = load i32, ptr %8, align 4
  %15 = load i32, ptr %10, align 4
  %16 = sdiv i32 %14, %15
  %17 = icmp slt i32 %13, %16
  br i1 %17, label %18, label %43
18:                                               ; preds = %12
  %19 = load ptr, ptr %4, align 8
  %20 = load i32, ptr %7, align 4
  %21 = load i32, ptr %10, align 4
  %22 = mul nsw i32 %20, %21
  %23 = load i32, ptr %11, align 4
  %24 = mul nsw i32 %22, %23
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds double, ptr %19, i64 %25
  %27 = load ptr, ptr %5, align 8
  %28 = load i32, ptr %9, align 4
  %29 = load i32, ptr %10, align 4
  %30 = mul nsw i32 %28, %29
  %31 = load i32, ptr %11, align 4
  %32 = mul nsw i32 %30, %31
  %33 = sext i32 %32 to i64
  %34 = getelementptr inbounds double, ptr %27, i64 %33
  %35 = load ptr, ptr %6, align 8
  %36 = load i32, ptr %7, align 4
  %37 = load i32, ptr %10, align 4
  %38 = load i32, ptr %9, align 4
  %39 = call zeroext i16 @_simd_gemm_AB(ptr noundef %26, ptr noundef %34, ptr noundef %35, i32 noundef signext %36, i32 noundef signext %37, i32 noundef signext %38, i32 noundef signext 0)
  br label %40
40:                                               ; preds = %18
  %41 = load i32, ptr %11, align 4
  %42 = add nsw i32 %41, 1
  store i32 %42, ptr %11, align 4
  br label %12, !llvm.loop !6
43:                                               ; preds = %12
  call void @__sdc_scb_end__(i32 1)
  ret void
}
declare dso_local zeroext i16 @_simd_gemm_AB(ptr noundef, ptr noundef, ptr noundef, i32 noundef signext, i32 noundef signext, i32 noundef signext, i32 noundef signext) #1
declare void @__sdc_scb_begin__(i32 noundef, i32 noundef) #2
declare void @__sdc_scb_end__(i32 noundef) #2
attributes #0 = { noinline nounwind optnone "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="c906fd" "target-features"="+64bit,+a,+c,+d,+f,+m,+relax,+xtheadc,+zfh,-save-restore" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="c906fd" "target-features"="+64bit,+a,+c,+d,+f,+m,+relax,+xtheadc,+zfh,-save-restore" }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
!llvm.ident = !{!0}
!llvm.module.flags = !{!1, !2, !3, !4, !5}
!0 = !{!"clang version 15.0.0 (Xuantie-900 elf newlib llvm Toolchain V1.0.0-beta B-20231116 059772e76040e9fe7ca5c0a7d1a27330360050b3)"}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 1, !"target-abi", !"lp64d"}
!3 = !{i32 1, !"Code Model", i32 3}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{i32 1, !"SmallDataLimit", i32 8}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
