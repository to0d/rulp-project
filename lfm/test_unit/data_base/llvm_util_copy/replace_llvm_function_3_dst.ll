; ModuleID = 'data_base/llvm_util_copy/replace_llvm_function_3_tgt.ll'
source_filename = "input.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"
%struct.CoreExecutor_T.0 = type { i32 }
%struct.DreExecutor_T = type { i32 }
@__const.simd_dre_executor_reshape.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_reshape.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @foo() #0 {
  %1 = alloca double*, align 8
  %2 = alloca double*, align 8
  %3 = alloca double*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca %struct.CoreExecutor_T.0*, align 8
  %8 = alloca %struct.DreExecutor_T*, align 8
  %9 = call %struct.CoreExecutor_T.0* (...) @simd_gemm_executor_create()
  store %struct.CoreExecutor_T.0* %9, %struct.CoreExecutor_T.0** %7, align 8
  %10 = call %struct.DreExecutor_T* @simd_dre_executor_create()
  store %struct.DreExecutor_T* %10, %struct.DreExecutor_T** %8, align 8
  %11 = load %struct.CoreExecutor_T.0*, %struct.CoreExecutor_T.0** %7, align 8
  %12 = load double*, double** %1, align 8
  %13 = load double*, double** %2, align 8
  %14 = load double*, double** %3, align 8
  %15 = load i32, i32* %4, align 4
  %16 = load i32, i32* %5, align 4
  %17 = load i32, i32* %6, align 4
  %18 = call i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T.0* noundef %11, double* noundef %12, double* noundef %13, double* noundef %14, i32 noundef %15, i32 noundef %16, i32 noundef %17, i32 noundef 0, i32 noundef 0, i32 noundef 0, double noundef 1.000000e+00, double noundef 1.000000e+00)
  %19 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %8, align 8
  %20 = load double*, double** %1, align 8
  %21 = load double*, double** %2, align 8
  %22 = call i32 @simd_dre_executor_reshape(%struct.DreExecutor_T* %19, double* %20, double* %21, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0, i32 0)
  %23 = load %struct.CoreExecutor_T.0*, %struct.CoreExecutor_T.0** %7, align 8
  %24 = load double*, double** %2, align 8
  %25 = load double*, double** %3, align 8
  %26 = load double*, double** %3, align 8
  %27 = load i32, i32* %4, align 4
  %28 = load i32, i32* %5, align 4
  %29 = load i32, i32* %6, align 4
  %30 = call i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T.0* noundef %23, double* noundef %24, double* noundef %25, double* noundef %26, i32 noundef %27, i32 noundef %28, i32 noundef %29, i32 noundef 0, i32 noundef 0, i32 noundef 0, double noundef 1.000000e+00, double noundef 1.000000e+00)
  %31 = load %struct.CoreExecutor_T.0*, %struct.CoreExecutor_T.0** %7, align 8
  call void @simd_gemm_executor_destroy(%struct.CoreExecutor_T.0* noundef %31)
  %32 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %8, align 8
  call void @simd_dre_executor_destroy(%struct.DreExecutor_T* %32)
  ret void
}
declare %struct.CoreExecutor_T.0* @simd_gemm_executor_create(...) #1
declare i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T.0* noundef, double* noundef, double* noundef, double* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, double noundef, double noundef) #1
declare void @simd_gemm_executor_destroy(%struct.CoreExecutor_T.0* noundef) #1
; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_reshape.1(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, i32 noundef %11, i32 noundef %12, i32 noundef %13, i32 noundef %14, i32 noundef %15, i32 noundef %16, i32 noundef %17, i32 noundef %18) #2 {
  %20 = alloca %struct.DreExecutor_T*, align 8
  %21 = alloca double*, align 8
  %22 = alloca double*, align 8
  %23 = alloca i32, align 4
  %24 = alloca i32, align 4
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i32, align 4
  %31 = alloca i32, align 4
  %32 = alloca i32, align 4
  %33 = alloca i32, align 4
  %34 = alloca i32, align 4
  %35 = alloca i32, align 4
  %36 = alloca i32, align 4
  %37 = alloca i32, align 4
  %38 = alloca i32, align 4
  %39 = alloca i32, align 4
  %40 = alloca i32, align 4
  %41 = alloca i32, align 4
  %42 = alloca i32, align 4
  %43 = alloca i32, align 4
  %44 = alloca i8, align 1
  %45 = alloca i8, align 1
  %46 = alloca i8, align 1
  %47 = alloca i16, align 2
  %48 = alloca i32, align 4
  %49 = alloca i8, align 1
  %50 = alloca i8, align 1
  %51 = alloca i8, align 1
  %52 = alloca i8, align 1
  %53 = alloca i8, align 1
  %54 = alloca i8, align 1
  %55 = alloca [7 x i32], align 16
  %56 = alloca [7 x i32], align 16
  %57 = alloca i128, align 16
  %58 = alloca i128, align 16
  %59 = alloca [7 x i32], align 16
  %60 = alloca [7 x i32], align 16
  %61 = alloca i128, align 16
  %62 = alloca i128, align 16
  %63 = alloca i128, align 16
  %64 = alloca i128, align 16
  store %struct.DreExecutor_T* %0, %struct.DreExecutor_T** %20, align 8
  store double* %1, double** %21, align 8
  store double* %2, double** %22, align 8
  store i32 %3, i32* %23, align 4
  store i32 %4, i32* %24, align 4
  store i32 %5, i32* %25, align 4
  store i32 %6, i32* %26, align 4
  store i32 %7, i32* %27, align 4
  store i32 %8, i32* %28, align 4
  store i32 %9, i32* %29, align 4
  store i32 %10, i32* %30, align 4
  store i32 %11, i32* %31, align 4
  store i32 %12, i32* %32, align 4
  store i32 %13, i32* %33, align 4
  store i32 %14, i32* %34, align 4
  store i32 %15, i32* %35, align 4
  store i32 %16, i32* %36, align 4
  store i32 %17, i32* %37, align 4
  store i32 %18, i32* %38, align 4
  %65 = load double*, double** %21, align 8
  %66 = ptrtoint double* %65 to i64
  %67 = call i32 @convertToRelativeAddr(i64 %66)
  store i32 %67, i32* %39, align 4
  store i32 0, i32* %40, align 4
  store i32 0, i32* %41, align 4
  %68 = load double*, double** %22, align 8
  %69 = ptrtoint double* %68 to i64
  %70 = call i32 @convertToRelativeAddr(i64 %69)
  store i32 %70, i32* %42, align 4
  store i32 0, i32* %43, align 4
  store i8 0, i8* %44, align 1
  store i8 2, i8* %45, align 1
  store i8 0, i8* %46, align 1
  store i16 -1, i16* %47, align 2
  store i32 0, i32* %48, align 4
  store i8 0, i8* %49, align 1
  store i8 1, i8* %50, align 1
  store i8 2, i8* %51, align 1
  store i8 3, i8* %52, align 1
  store i8 4, i8* %53, align 1
  %71 = load i32, i32* %38, align 4
  %72 = icmp eq i32 %71, 0
  br i1 %72, label %73, label %74
73:                                               ; preds = %19
  br label %85
74:                                               ; preds = %19
  %75 = load i32, i32* %38, align 4
  %76 = icmp eq i32 %75, 1
  br i1 %76, label %77, label %78
77:                                               ; preds = %74
  br label %83
78:                                               ; preds = %74
  %79 = load i32, i32* %38, align 4
  %80 = icmp eq i32 %79, 2
  %81 = zext i1 %80 to i64
  %82 = select i1 %80, i32 6, i32 16
  br label %83
83:                                               ; preds = %78, %77
  %84 = phi i32 [ 5, %77 ], [ %82, %78 ]
  br label %85
85:                                               ; preds = %83, %73
  %86 = phi i32 [ 4, %73 ], [ %84, %83 ]
  %87 = trunc i32 %86 to i8
  store i8 %87, i8* %54, align 1
  %88 = bitcast [7 x i32]* %55 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %88, i8* bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false)
  %89 = getelementptr inbounds [7 x i32], [7 x i32]* %56, i64 0, i64 0
  %90 = load i32, i32* %23, align 4
  %91 = sub nsw i32 %90, 1
  store i32 %91, i32* %89, align 4
  %92 = getelementptr inbounds i32, i32* %89, i64 1
  %93 = load i32, i32* %25, align 4
  %94 = sub nsw i32 %93, 1
  store i32 %94, i32* %92, align 4
  %95 = getelementptr inbounds i32, i32* %92, i64 1
  %96 = load i32, i32* %24, align 4
  %97 = sub nsw i32 %96, 1
  store i32 %97, i32* %95, align 4
  %98 = getelementptr inbounds i32, i32* %95, i64 1
  store i32 0, i32* %98, align 4
  %99 = getelementptr inbounds i32, i32* %98, i64 1
  store i32 0, i32* %99, align 4
  %100 = getelementptr inbounds i32, i32* %99, i64 1
  %101 = load i32, i32* %23, align 4
  %102 = sub nsw i32 %101, 1
  store i32 %102, i32* %100, align 4
  %103 = getelementptr inbounds i32, i32* %100, i64 1
  %104 = load i32, i32* %24, align 4
  %105 = sub nsw i32 %104, 1
  store i32 %105, i32* %103, align 4
  %106 = getelementptr inbounds [7 x i32], [7 x i32]* %55, i64 0, i64 0
  %107 = getelementptr inbounds [7 x i32], [7 x i32]* %56, i64 0, i64 0
  %108 = call { i64, i64 } @setUpdateData(i32* %106, i32* %107, i32 7)
  %109 = bitcast i128* %58 to { i64, i64 }*
  %110 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %109, i32 0, i32 0
  %111 = extractvalue { i64, i64 } %108, 0
  store i64 %111, i64* %110, align 16
  %112 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %109, i32 0, i32 1
  %113 = extractvalue { i64, i64 } %108, 1
  store i64 %113, i64* %112, align 8
  %114 = load i128, i128* %58, align 16
  store i128 %114, i128* %57, align 16
  %115 = bitcast [7 x i32]* %59 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %115, i8* bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false)
  %116 = getelementptr inbounds [7 x i32], [7 x i32]* %60, i64 0, i64 0
  %117 = load i32, i32* %26, align 4
  %118 = sub nsw i32 %117, 1
  store i32 %118, i32* %116, align 4
  %119 = getelementptr inbounds i32, i32* %116, i64 1
  %120 = load i32, i32* %28, align 4
  %121 = sub nsw i32 %120, 1
  store i32 %121, i32* %119, align 4
  %122 = getelementptr inbounds i32, i32* %119, i64 1
  %123 = load i32, i32* %27, align 4
  %124 = sub nsw i32 %123, 1
  store i32 %124, i32* %122, align 4
  %125 = getelementptr inbounds i32, i32* %122, i64 1
  store i32 0, i32* %125, align 4
  %126 = getelementptr inbounds i32, i32* %125, i64 1
  store i32 0, i32* %126, align 4
  %127 = getelementptr inbounds i32, i32* %126, i64 1
  %128 = load i32, i32* %26, align 4
  %129 = sub nsw i32 %128, 1
  store i32 %129, i32* %127, align 4
  %130 = getelementptr inbounds i32, i32* %127, i64 1
  %131 = load i32, i32* %27, align 4
  %132 = sub nsw i32 %131, 1
  store i32 %132, i32* %130, align 4
  %133 = getelementptr inbounds [7 x i32], [7 x i32]* %59, i64 0, i64 0
  %134 = getelementptr inbounds [7 x i32], [7 x i32]* %60, i64 0, i64 0
  %135 = call { i64, i64 } @setUpdateData(i32* %133, i32* %134, i32 7)
  %136 = bitcast i128* %62 to { i64, i64 }*
  %137 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %136, i32 0, i32 0
  %138 = extractvalue { i64, i64 } %135, 0
  store i64 %138, i64* %137, align 16
  %139 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %136, i32 0, i32 1
  %140 = extractvalue { i64, i64 } %135, 1
  store i64 %140, i64* %139, align 8
  %141 = load i128, i128* %62, align 16
  store i128 %141, i128* %61, align 16
  %142 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %20, align 8
  %143 = load i16, i16* %47, align 2
  %144 = load i32, i32* %48, align 4
  %145 = load i128, i128* %57, align 16
  %146 = load i8, i8* %44, align 1
  store i128 %145, i128* %63, align 16
  %147 = bitcast i128* %63 to { i64, i64 }*
  %148 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 0
  %149 = load i64, i64* %148, align 16
  %150 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 1
  %151 = load i64, i64* %150, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* %142, i16 %143, i32 %144, i64 %149, i64 %151, i8 %146, i8 0, i8 0, i8 9)
  %152 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %20, align 8
  %153 = load i16, i16* %47, align 2
  %154 = load i32, i32* %48, align 4
  %155 = add i32 %154, 3
  %156 = load i128, i128* %61, align 16
  %157 = load i8, i8* %44, align 1
  store i128 %156, i128* %64, align 16
  %158 = bitcast i128* %64 to { i64, i64 }*
  %159 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %158, i32 0, i32 0
  %160 = load i64, i64* %159, align 16
  %161 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %158, i32 0, i32 1
  %162 = load i64, i64* %161, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* %152, i16 %153, i32 %155, i64 %160, i64 %162, i8 %157, i8 0, i8 0, i8 9)
  %163 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %20, align 8
  %164 = load i32, i32* %39, align 4
  %165 = load i32, i32* %40, align 4
  %166 = load i32, i32* %41, align 4
  %167 = load i32, i32* %42, align 4
  %168 = load i32, i32* %43, align 4
  %169 = load i8, i8* %44, align 1
  %170 = load i8, i8* %45, align 1
  %171 = load i8, i8* %46, align 1
  %172 = load i8, i8* %49, align 1
  %173 = load i8, i8* %50, align 1
  %174 = load i8, i8* %51, align 1
  %175 = load i8, i8* %52, align 1
  %176 = load i8, i8* %53, align 1
  %177 = load i8, i8* %54, align 1
  %178 = call i32 @Dre(%struct.DreExecutor_T* %163, i32 %164, i32 %165, i32 %166, i32 %167, i32 %168, i8 %169, i8 %170, i8 %171, i8 %172, i8 %173, i8 %174, i8 %175, i8 %176, i8 %177, i8 8)
  ret i32 %178
}
declare i32 @convertToRelativeAddr(i64 noundef) #1
declare %struct.DreExecutor_T* @simd_dre_executor_create() #1
declare i32 @simd_dre_executor_reshape(%struct.DreExecutor_T* noundef, double* noundef, double* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) #1
declare void @simd_dre_executor_destroy(%struct.DreExecutor_T* noundef) #1
; Function Attrs: argmemonly nocallback nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #3
declare { i64, i64 } @setUpdateData(i32* noundef, i32* noundef, i32 noundef) #1
declare void @simd_dre_init(%struct.DreExecutor_T* noundef, i16 noundef zeroext, i32 noundef, i64 noundef, i64 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1
declare i32 @Dre(%struct.DreExecutor_T* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1
attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { alwaysinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { argmemonly nocallback nofree nounwind willreturn }
!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}
!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
