; ModuleID = 'util/simd_example.c'
source_filename = "util/simd_example.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.CoreExecutor_T = type { i32 }
%struct.OutputShape = type { i32, i32 }
%struct.DreExecutor_T = type { i32 }

@__const.simd_gemm_executor_AB.positions_src0 = private unnamed_addr constant [3 x i32] [i32 0, i32 2, i32 3], align 4
@__const.simd_gemm_executor_AB.positions_src1 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_AB.positions_dst0 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_AB.positions_func = private unnamed_addr constant [2 x i32] [i32 2, i32 3], align 4
@__const.simd_gemm_executor_Conv1d.positions_src0 = private unnamed_addr constant [3 x i32] [i32 0, i32 2, i32 3], align 4
@__const.simd_gemm_executor_Conv1d.positions_src1 = private unnamed_addr constant [3 x i32] [i32 0, i32 2, i32 3], align 4
@__const.simd_gemm_executor_Conv1d.positions_dst0 = private unnamed_addr constant [3 x i32] [i32 0, i32 2, i32 3], align 4
@__const.simd_gemm_executor_Conv1d.positions_func = private unnamed_addr constant [8 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7], align 16
@__const.simd_gemm_executor_Conv2d.positions_src0 = private unnamed_addr constant [4 x i32] [i32 0, i32 1, i32 2, i32 3], align 16
@__const.simd_gemm_executor_Conv2d.positions_src1 = private unnamed_addr constant [4 x i32] [i32 0, i32 1, i32 2, i32 3], align 16
@__const.simd_gemm_executor_Conv2d.positions_dst0 = private unnamed_addr constant [4 x i32] [i32 0, i32 1, i32 2, i32 3], align 16
@__const.simd_gemm_executor_Conv2d.positions_func = private unnamed_addr constant [8 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7], align 16
@__const.simd_gemm_executor_Ax.positions_src0 = private unnamed_addr constant [3 x i32] [i32 0, i32 2, i32 3], align 4
@__const.simd_gemm_executor_Ax.positions_dst0 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_Ax.positions_func = private unnamed_addr constant [1 x i32] [i32 3], align 4
@__const.simd_dre_executor_reshape.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_reshape.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_swap.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_swap.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_reduce_argmax.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_reduce_argmax.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_reduce_argmax.values_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 0, i32 1, i32 0, i32 0, i32 0, i32 1], align 16
@__const.simd_dre_executor_eltw_multi.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_eltw_multi.positions_src1 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_eltw_multi.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_eltw_sum.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_eltw_sum.positions_src1 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_eltw_sum.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_Apb.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_Apb.positions_src1 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_Apb.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_Ab.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_Ab.positions_src1 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_Ab.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_outer.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_outer.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16

; Function Attrs: alwaysinline nounwind uwtable
define dso_local void @simd_synchronize(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = icmp eq i32 %3, 0
  br i1 %4, label %5, label %6

5:                                                ; preds = %1
  call void @simd_major_finish(i8 noundef zeroext 0, i8 noundef zeroext 0)
  br label %6

6:                                                ; preds = %5, %1
  ret void
}

declare void @simd_major_finish(i8 noundef zeroext, i8 noundef zeroext) #1

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, double noundef %10, double noundef %11) #0 {
  %13 = alloca %struct.CoreExecutor_T*, align 8
  %14 = alloca double*, align 8
  %15 = alloca double*, align 8
  %16 = alloca double*, align 8
  %17 = alloca i32, align 4
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca double, align 8
  %24 = alloca double, align 8
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i8, align 1
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca i16, align 2
  %34 = alloca i32, align 4
  %35 = alloca i8, align 1
  %36 = alloca i8, align 1
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca i8, align 1
  %40 = alloca i8, align 1
  %41 = alloca [3 x i32], align 4
  %42 = alloca [3 x i32], align 4
  %43 = alloca i128, align 16
  %44 = alloca i128, align 16
  %45 = alloca [2 x i32], align 4
  %46 = alloca [2 x i32], align 4
  %47 = alloca i128, align 16
  %48 = alloca i128, align 16
  %49 = alloca [2 x i32], align 4
  %50 = alloca [2 x i32], align 4
  %51 = alloca i128, align 16
  %52 = alloca i128, align 16
  %53 = alloca [2 x i32], align 4
  %54 = alloca [2 x i32], align 4
  %55 = alloca i128, align 16
  %56 = alloca i128, align 16
  %57 = alloca i128, align 16
  %58 = alloca i128, align 16
  %59 = alloca i128, align 16
  %60 = alloca i128, align 16
  store %struct.CoreExecutor_T* %0, %struct.CoreExecutor_T** %13, align 8
  store double* %1, double** %14, align 8
  store double* %2, double** %15, align 8
  store double* %3, double** %16, align 8
  store i32 %4, i32* %17, align 4
  store i32 %5, i32* %18, align 4
  store i32 %6, i32* %19, align 4
  store i32 %7, i32* %20, align 4
  store i32 %8, i32* %21, align 4
  store i32 %9, i32* %22, align 4
  store double %10, double* %23, align 8
  store double %11, double* %24, align 8
  %61 = load double*, double** %14, align 8
  %62 = ptrtoint double* %61 to i64
  %63 = call i32 @convertToRelativeAddr(i64 noundef %62)
  store i32 %63, i32* %25, align 4
  %64 = load double*, double** %15, align 8
  %65 = ptrtoint double* %64 to i64
  %66 = call i32 @convertToRelativeAddr(i64 noundef %65)
  store i32 %66, i32* %26, align 4
  store i32 0, i32* %27, align 4
  %67 = load double*, double** %16, align 8
  %68 = ptrtoint double* %67 to i64
  %69 = call i32 @convertToRelativeAddr(i64 noundef %68)
  store i32 %69, i32* %28, align 4
  store i32 0, i32* %29, align 4
  store i8 0, i8* %30, align 1
  store i8 2, i8* %31, align 1
  store i8 0, i8* %32, align 1
  store i16 4369, i16* %33, align 2
  store i32 1, i32* %34, align 4
  store i8 1, i8* %35, align 1
  store i8 2, i8* %36, align 1
  store i8 0, i8* %37, align 1
  store i8 3, i8* %38, align 1
  store i8 4, i8* %39, align 1
  store i8 0, i8* %40, align 1
  %70 = bitcast [3 x i32]* %41 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %70, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %71 = getelementptr inbounds [3 x i32], [3 x i32]* %42, i64 0, i64 0
  %72 = load i32, i32* %18, align 4
  store i32 %72, i32* %71, align 4
  %73 = getelementptr inbounds i32, i32* %71, i64 1
  %74 = load i32, i32* %17, align 4
  store i32 %74, i32* %73, align 4
  %75 = getelementptr inbounds i32, i32* %73, i64 1
  %76 = load i32, i32* %18, align 4
  %77 = add nsw i32 %76, 16
  %78 = sdiv i32 %77, 16
  %79 = sub nsw i32 %78, 1
  store i32 %79, i32* %75, align 4
  %80 = getelementptr inbounds [3 x i32], [3 x i32]* %41, i64 0, i64 0
  %81 = getelementptr inbounds [3 x i32], [3 x i32]* %42, i64 0, i64 0
  %82 = call { i64, i64 } @setUpdateData(i32* noundef %80, i32* noundef %81, i32 noundef 3)
  %83 = bitcast i128* %44 to { i64, i64 }*
  %84 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %83, i32 0, i32 0
  %85 = extractvalue { i64, i64 } %82, 0
  store i64 %85, i64* %84, align 16
  %86 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %83, i32 0, i32 1
  %87 = extractvalue { i64, i64 } %82, 1
  store i64 %87, i64* %86, align 8
  %88 = load i128, i128* %44, align 16
  store i128 %88, i128* %43, align 16
  %89 = bitcast [2 x i32]* %45 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %89, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %90 = getelementptr inbounds [2 x i32], [2 x i32]* %46, i64 0, i64 0
  %91 = load i32, i32* %18, align 4
  store i32 %91, i32* %90, align 4
  %92 = getelementptr inbounds i32, i32* %90, i64 1
  %93 = load i32, i32* %19, align 4
  store i32 %93, i32* %92, align 4
  %94 = getelementptr inbounds [2 x i32], [2 x i32]* %45, i64 0, i64 0
  %95 = getelementptr inbounds [2 x i32], [2 x i32]* %46, i64 0, i64 0
  %96 = call { i64, i64 } @setUpdateData(i32* noundef %94, i32* noundef %95, i32 noundef 2)
  %97 = bitcast i128* %48 to { i64, i64 }*
  %98 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %97, i32 0, i32 0
  %99 = extractvalue { i64, i64 } %96, 0
  store i64 %99, i64* %98, align 16
  %100 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %97, i32 0, i32 1
  %101 = extractvalue { i64, i64 } %96, 1
  store i64 %101, i64* %100, align 8
  %102 = load i128, i128* %48, align 16
  store i128 %102, i128* %47, align 16
  %103 = bitcast [2 x i32]* %49 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %103, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %104 = getelementptr inbounds [2 x i32], [2 x i32]* %50, i64 0, i64 0
  %105 = load i32, i32* %17, align 4
  store i32 %105, i32* %104, align 4
  %106 = getelementptr inbounds i32, i32* %104, i64 1
  %107 = load i32, i32* %19, align 4
  store i32 %107, i32* %106, align 4
  %108 = getelementptr inbounds [2 x i32], [2 x i32]* %49, i64 0, i64 0
  %109 = getelementptr inbounds [2 x i32], [2 x i32]* %50, i64 0, i64 0
  %110 = call { i64, i64 } @setUpdateData(i32* noundef %108, i32* noundef %109, i32 noundef 2)
  %111 = bitcast i128* %52 to { i64, i64 }*
  %112 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %111, i32 0, i32 0
  %113 = extractvalue { i64, i64 } %110, 0
  store i64 %113, i64* %112, align 16
  %114 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %111, i32 0, i32 1
  %115 = extractvalue { i64, i64 } %110, 1
  store i64 %115, i64* %114, align 8
  %116 = load i128, i128* %52, align 16
  store i128 %116, i128* %51, align 16
  %117 = bitcast [2 x i32]* %53 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %117, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %118 = getelementptr inbounds [2 x i32], [2 x i32]* %54, i64 0, i64 0
  %119 = load i32, i32* %18, align 4
  %120 = load i32, i32* %17, align 4
  %121 = mul nsw i32 %119, %120
  %122 = sdiv i32 %121, 128
  store i32 %122, i32* %118, align 4
  %123 = getelementptr inbounds i32, i32* %118, i64 1
  %124 = load i32, i32* %18, align 4
  %125 = load i32, i32* %19, align 4
  %126 = mul nsw i32 %124, %125
  %127 = sdiv i32 %126, 128
  store i32 %127, i32* %123, align 4
  %128 = getelementptr inbounds [2 x i32], [2 x i32]* %53, i64 0, i64 0
  %129 = getelementptr inbounds [2 x i32], [2 x i32]* %54, i64 0, i64 0
  %130 = call { i64, i64 } @setUpdateData(i32* noundef %128, i32* noundef %129, i32 noundef 2)
  %131 = bitcast i128* %56 to { i64, i64 }*
  %132 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %131, i32 0, i32 0
  %133 = extractvalue { i64, i64 } %130, 0
  store i64 %133, i64* %132, align 16
  %134 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %131, i32 0, i32 1
  %135 = extractvalue { i64, i64 } %130, 1
  store i64 %135, i64* %134, align 8
  %136 = load i128, i128* %56, align 16
  store i128 %136, i128* %55, align 16
  %137 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %138 = load i16, i16* %33, align 2
  %139 = load i32, i32* %34, align 4
  %140 = load i128, i128* %43, align 16
  %141 = load i8, i8* %30, align 1
  %142 = load i8, i8* %31, align 1
  %143 = load i8, i8* %32, align 1
  store i128 %140, i128* %57, align 16
  %144 = bitcast i128* %57 to { i64, i64 }*
  %145 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %144, i32 0, i32 0
  %146 = load i64, i64* %145, align 16
  %147 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %144, i32 0, i32 1
  %148 = load i64, i64* %147, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %137, i16 noundef zeroext %138, i32 noundef %139, i64 noundef %146, i64 noundef %148, i8 noundef zeroext %141, i8 noundef zeroext %142, i8 noundef zeroext %143, i8 noundef zeroext 5)
  %149 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %150 = load i16, i16* %33, align 2
  %151 = load i32, i32* %34, align 4
  %152 = add i32 %151, 1
  %153 = load i128, i128* %47, align 16
  %154 = load i8, i8* %30, align 1
  %155 = load i8, i8* %31, align 1
  %156 = load i8, i8* %32, align 1
  store i128 %153, i128* %58, align 16
  %157 = bitcast i128* %58 to { i64, i64 }*
  %158 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %157, i32 0, i32 0
  %159 = load i64, i64* %158, align 16
  %160 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %157, i32 0, i32 1
  %161 = load i64, i64* %160, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %149, i16 noundef zeroext %150, i32 noundef %152, i64 noundef %159, i64 noundef %161, i8 noundef zeroext %154, i8 noundef zeroext %155, i8 noundef zeroext %156, i8 noundef zeroext 5)
  %162 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %163 = load i16, i16* %33, align 2
  %164 = load i32, i32* %34, align 4
  %165 = add i32 %164, 2
  %166 = load i128, i128* %51, align 16
  %167 = load i8, i8* %30, align 1
  %168 = load i8, i8* %31, align 1
  %169 = load i8, i8* %32, align 1
  store i128 %166, i128* %59, align 16
  %170 = bitcast i128* %59 to { i64, i64 }*
  %171 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %170, i32 0, i32 0
  %172 = load i64, i64* %171, align 16
  %173 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %170, i32 0, i32 1
  %174 = load i64, i64* %173, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %162, i16 noundef zeroext %163, i32 noundef %165, i64 noundef %172, i64 noundef %174, i8 noundef zeroext %167, i8 noundef zeroext %168, i8 noundef zeroext %169, i8 noundef zeroext 5)
  %175 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %176 = load i16, i16* %33, align 2
  %177 = load i32, i32* %34, align 4
  %178 = add i32 %177, 3
  %179 = load i128, i128* %55, align 16
  %180 = load i8, i8* %30, align 1
  %181 = load i8, i8* %31, align 1
  %182 = load i8, i8* %32, align 1
  store i128 %179, i128* %60, align 16
  %183 = bitcast i128* %60 to { i64, i64 }*
  %184 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %183, i32 0, i32 0
  %185 = load i64, i64* %184, align 16
  %186 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %183, i32 0, i32 1
  %187 = load i64, i64* %186, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %175, i16 noundef zeroext %176, i32 noundef %178, i64 noundef %185, i64 noundef %187, i8 noundef zeroext %180, i8 noundef zeroext %181, i8 noundef zeroext %182, i8 noundef zeroext 5)
  %188 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %189 = load i32, i32* %25, align 4
  %190 = load i32, i32* %26, align 4
  %191 = load i32, i32* %27, align 4
  %192 = load i32, i32* %28, align 4
  %193 = load i32, i32* %29, align 4
  %194 = load i8, i8* %30, align 1
  %195 = load i8, i8* %31, align 1
  %196 = load i8, i8* %32, align 1
  %197 = load i8, i8* %35, align 1
  %198 = load i8, i8* %36, align 1
  %199 = load i8, i8* %37, align 1
  %200 = load i8, i8* %38, align 1
  %201 = load i8, i8* %39, align 1
  %202 = load i8, i8* %40, align 1
  %203 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %188, i32 noundef %189, i32 noundef %190, i32 noundef %191, i32 noundef %192, i32 noundef %193, i8 noundef zeroext %194, i8 noundef zeroext %195, i8 noundef zeroext %196, i8 noundef zeroext %197, i8 noundef zeroext %198, i8 noundef zeroext %199, i8 noundef zeroext %200, i8 noundef zeroext %201, i8 noundef zeroext %202, i8 noundef zeroext 4)
  ret i32 %203
}

declare i32 @convertToRelativeAddr(i64 noundef) #1

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #2

declare { i64, i64 } @setUpdateData(i32* noundef, i32* noundef, i32 noundef) #1

declare void @simd_gemm_init(%struct.CoreExecutor_T* noundef, i16 noundef zeroext, i32 noundef, i64 noundef, i64 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

declare i32 @Gemm(%struct.CoreExecutor_T* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_gemm_executor_ABpC(%struct.CoreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, double* noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, double noundef %11, double noundef %12) #0 {
  %14 = alloca %struct.CoreExecutor_T*, align 8
  %15 = alloca double*, align 8
  %16 = alloca double*, align 8
  %17 = alloca double*, align 8
  %18 = alloca double*, align 8
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca i32, align 4
  %24 = alloca i32, align 4
  %25 = alloca double, align 8
  %26 = alloca double, align 8
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i32, align 4
  %31 = alloca i32, align 4
  %32 = alloca i8, align 1
  %33 = alloca i8, align 1
  %34 = alloca i8, align 1
  %35 = alloca i16, align 2
  %36 = alloca i32, align 4
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca i8, align 1
  %40 = alloca i8, align 1
  %41 = alloca i8, align 1
  %42 = alloca i8, align 1
  store %struct.CoreExecutor_T* %0, %struct.CoreExecutor_T** %14, align 8
  store double* %1, double** %15, align 8
  store double* %2, double** %16, align 8
  store double* %3, double** %17, align 8
  store double* %4, double** %18, align 8
  store i32 %5, i32* %19, align 4
  store i32 %6, i32* %20, align 4
  store i32 %7, i32* %21, align 4
  store i32 %8, i32* %22, align 4
  store i32 %9, i32* %23, align 4
  store i32 %10, i32* %24, align 4
  store double %11, double* %25, align 8
  store double %12, double* %26, align 8
  %43 = load double*, double** %15, align 8
  %44 = ptrtoint double* %43 to i64
  %45 = call i32 @convertToRelativeAddr(i64 noundef %44)
  store i32 %45, i32* %27, align 4
  %46 = load double*, double** %16, align 8
  %47 = ptrtoint double* %46 to i64
  %48 = call i32 @convertToRelativeAddr(i64 noundef %47)
  store i32 %48, i32* %28, align 4
  %49 = load double*, double** %17, align 8
  %50 = ptrtoint double* %49 to i64
  %51 = call i32 @convertToRelativeAddr(i64 noundef %50)
  store i32 %51, i32* %29, align 4
  %52 = load double*, double** %18, align 8
  %53 = ptrtoint double* %52 to i64
  %54 = call i32 @convertToRelativeAddr(i64 noundef %53)
  store i32 %54, i32* %30, align 4
  store i32 0, i32* %31, align 4
  store i8 1, i8* %32, align 1
  store i8 2, i8* %33, align 1
  store i8 0, i8* %34, align 1
  store i16 4369, i16* %35, align 2
  store i32 1, i32* %36, align 4
  store i8 1, i8* %37, align 1
  store i8 2, i8* %38, align 1
  store i8 3, i8* %39, align 1
  store i8 0, i8* %40, align 1
  store i8 4, i8* %41, align 1
  store i8 5, i8* %42, align 1
  %55 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %14, align 8
  %56 = load i32, i32* %27, align 4
  %57 = load i32, i32* %28, align 4
  %58 = load i32, i32* %29, align 4
  %59 = load i32, i32* %30, align 4
  %60 = load i32, i32* %31, align 4
  %61 = load i8, i8* %32, align 1
  %62 = load i8, i8* %33, align 1
  %63 = load i8, i8* %34, align 1
  %64 = load i8, i8* %37, align 1
  %65 = load i8, i8* %38, align 1
  %66 = load i8, i8* %39, align 1
  %67 = load i8, i8* %40, align 1
  %68 = load i8, i8* %41, align 1
  %69 = load i8, i8* %42, align 1
  %70 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %55, i32 noundef %56, i32 noundef %57, i32 noundef %58, i32 noundef %59, i32 noundef %60, i8 noundef zeroext %61, i8 noundef zeroext %62, i8 noundef zeroext %63, i8 noundef zeroext %64, i8 noundef zeroext %65, i8 noundef zeroext %66, i8 noundef zeroext %67, i8 noundef zeroext %68, i8 noundef zeroext %69, i8 noundef zeroext 4)
  ret i32 %70
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_gemm_executor_Conv1d(%struct.CoreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, double* noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, i32 noundef %11, i32 noundef %12) #0 {
  %14 = alloca %struct.CoreExecutor_T*, align 8
  %15 = alloca double*, align 8
  %16 = alloca double*, align 8
  %17 = alloca double*, align 8
  %18 = alloca double*, align 8
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca i32, align 4
  %24 = alloca i32, align 4
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i32, align 4
  %31 = alloca i32, align 4
  %32 = alloca i8, align 1
  %33 = alloca i8, align 1
  %34 = alloca i8, align 1
  %35 = alloca i16, align 2
  %36 = alloca i32, align 4
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca i8, align 1
  %40 = alloca i8, align 1
  %41 = alloca i8, align 1
  %42 = alloca i8, align 1
  %43 = alloca [3 x i32], align 4
  %44 = alloca [3 x i32], align 4
  %45 = alloca i128, align 16
  %46 = alloca i128, align 16
  %47 = alloca [3 x i32], align 4
  %48 = alloca [3 x i32], align 4
  %49 = alloca i128, align 16
  %50 = alloca i128, align 16
  %51 = alloca [1 x i32], align 4
  %52 = alloca [1 x i32], align 4
  %53 = alloca i128, align 16
  %54 = alloca i128, align 16
  %55 = alloca %struct.OutputShape, align 4
  %56 = alloca [3 x i32], align 4
  %57 = alloca [3 x i32], align 4
  %58 = alloca i128, align 16
  %59 = alloca i128, align 16
  %60 = alloca [8 x i32], align 16
  %61 = alloca [8 x i32], align 16
  %62 = alloca i128, align 16
  %63 = alloca i128, align 16
  %64 = alloca i128, align 16
  %65 = alloca i128, align 16
  %66 = alloca i128, align 16
  %67 = alloca i128, align 16
  %68 = alloca i128, align 16
  store %struct.CoreExecutor_T* %0, %struct.CoreExecutor_T** %14, align 8
  store double* %1, double** %15, align 8
  store double* %2, double** %16, align 8
  store double* %3, double** %17, align 8
  store double* %4, double** %18, align 8
  store i32 %5, i32* %19, align 4
  store i32 %6, i32* %20, align 4
  store i32 %7, i32* %21, align 4
  store i32 %8, i32* %22, align 4
  store i32 %9, i32* %23, align 4
  store i32 %10, i32* %24, align 4
  store i32 %11, i32* %25, align 4
  store i32 %12, i32* %26, align 4
  %69 = load double*, double** %15, align 8
  %70 = ptrtoint double* %69 to i64
  %71 = call i32 @convertToRelativeAddr(i64 noundef %70)
  store i32 %71, i32* %27, align 4
  %72 = load double*, double** %16, align 8
  %73 = ptrtoint double* %72 to i64
  %74 = call i32 @convertToRelativeAddr(i64 noundef %73)
  store i32 %74, i32* %28, align 4
  %75 = load double*, double** %17, align 8
  %76 = ptrtoint double* %75 to i64
  %77 = call i32 @convertToRelativeAddr(i64 noundef %76)
  store i32 %77, i32* %29, align 4
  %78 = load double*, double** %18, align 8
  %79 = ptrtoint double* %78 to i64
  %80 = call i32 @convertToRelativeAddr(i64 noundef %79)
  store i32 %80, i32* %30, align 4
  store i32 0, i32* %31, align 4
  store i8 2, i8* %32, align 1
  store i8 2, i8* %33, align 1
  store i8 0, i8* %34, align 1
  store i16 4369, i16* %35, align 2
  store i32 1, i32* %36, align 4
  store i8 1, i8* %37, align 1
  store i8 2, i8* %38, align 1
  store i8 3, i8* %39, align 1
  store i8 4, i8* %40, align 1
  store i8 0, i8* %41, align 1
  store i8 5, i8* %42, align 1
  %81 = bitcast [3 x i32]* %43 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %81, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_Conv1d.positions_src0 to i8*), i64 12, i1 false)
  %82 = getelementptr inbounds [3 x i32], [3 x i32]* %44, i64 0, i64 0
  %83 = load i32, i32* %19, align 4
  store i32 %83, i32* %82, align 4
  %84 = getelementptr inbounds i32, i32* %82, i64 1
  %85 = load i32, i32* %20, align 4
  store i32 %85, i32* %84, align 4
  %86 = getelementptr inbounds i32, i32* %84, i64 1
  %87 = load i32, i32* %19, align 4
  %88 = add nsw i32 %87, 16
  %89 = sdiv i32 %88, 16
  %90 = sub nsw i32 %89, 1
  store i32 %90, i32* %86, align 4
  %91 = getelementptr inbounds [3 x i32], [3 x i32]* %43, i64 0, i64 0
  %92 = getelementptr inbounds [3 x i32], [3 x i32]* %44, i64 0, i64 0
  %93 = call { i64, i64 } @setUpdateData(i32* noundef %91, i32* noundef %92, i32 noundef 3)
  %94 = bitcast i128* %46 to { i64, i64 }*
  %95 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %94, i32 0, i32 0
  %96 = extractvalue { i64, i64 } %93, 0
  store i64 %96, i64* %95, align 16
  %97 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %94, i32 0, i32 1
  %98 = extractvalue { i64, i64 } %93, 1
  store i64 %98, i64* %97, align 8
  %99 = load i128, i128* %46, align 16
  store i128 %99, i128* %45, align 16
  %100 = bitcast [3 x i32]* %47 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %100, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_Conv1d.positions_src1 to i8*), i64 12, i1 false)
  %101 = getelementptr inbounds [3 x i32], [3 x i32]* %48, i64 0, i64 0
  %102 = load i32, i32* %21, align 4
  store i32 %102, i32* %101, align 4
  %103 = getelementptr inbounds i32, i32* %101, i64 1
  %104 = load i32, i32* %22, align 4
  store i32 %104, i32* %103, align 4
  %105 = getelementptr inbounds i32, i32* %103, i64 1
  %106 = load i32, i32* %26, align 4
  store i32 %106, i32* %105, align 4
  %107 = getelementptr inbounds [3 x i32], [3 x i32]* %47, i64 0, i64 0
  %108 = getelementptr inbounds [3 x i32], [3 x i32]* %48, i64 0, i64 0
  %109 = call { i64, i64 } @setUpdateData(i32* noundef %107, i32* noundef %108, i32 noundef 3)
  %110 = bitcast i128* %50 to { i64, i64 }*
  %111 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %110, i32 0, i32 0
  %112 = extractvalue { i64, i64 } %109, 0
  store i64 %112, i64* %111, align 16
  %113 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %110, i32 0, i32 1
  %114 = extractvalue { i64, i64 } %109, 1
  store i64 %114, i64* %113, align 8
  %115 = load i128, i128* %50, align 16
  store i128 %115, i128* %49, align 16
  %116 = bitcast [1 x i32]* %51 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 4 %116, i8 0, i64 4, i1 false)
  %117 = getelementptr inbounds [1 x i32], [1 x i32]* %52, i64 0, i64 0
  %118 = load i32, i32* %26, align 4
  store i32 %118, i32* %117, align 4
  %119 = getelementptr inbounds [1 x i32], [1 x i32]* %51, i64 0, i64 0
  %120 = getelementptr inbounds [1 x i32], [1 x i32]* %52, i64 0, i64 0
  %121 = call { i64, i64 } @setUpdateData(i32* noundef %119, i32* noundef %120, i32 noundef 1)
  %122 = bitcast i128* %54 to { i64, i64 }*
  %123 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %122, i32 0, i32 0
  %124 = extractvalue { i64, i64 } %121, 0
  store i64 %124, i64* %123, align 16
  %125 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %122, i32 0, i32 1
  %126 = extractvalue { i64, i64 } %121, 1
  store i64 %126, i64* %125, align 8
  %127 = load i128, i128* %54, align 16
  store i128 %127, i128* %53, align 16
  %128 = load i32, i32* %19, align 4
  %129 = load i32, i32* %20, align 4
  %130 = load i32, i32* %21, align 4
  %131 = load i32, i32* %22, align 4
  %132 = load i32, i32* %23, align 4
  %133 = load i32, i32* %24, align 4
  %134 = call i64 @calculateConvOutputShape(i32 noundef %128, i32 noundef %129, i32 noundef %130, i32 noundef %131, i32 noundef %132, i32 noundef %133, i32 noundef 0, i32 noundef 0)
  %135 = bitcast %struct.OutputShape* %55 to i64*
  store i64 %134, i64* %135, align 4
  %136 = bitcast [3 x i32]* %56 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %136, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_Conv1d.positions_dst0 to i8*), i64 12, i1 false)
  %137 = getelementptr inbounds [3 x i32], [3 x i32]* %57, i64 0, i64 0
  %138 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %55, i32 0, i32 0
  %139 = load i32, i32* %138, align 4
  store i32 %139, i32* %137, align 4
  %140 = getelementptr inbounds i32, i32* %137, i64 1
  %141 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %55, i32 0, i32 1
  %142 = load i32, i32* %141, align 4
  store i32 %142, i32* %140, align 4
  %143 = getelementptr inbounds i32, i32* %140, i64 1
  %144 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %55, i32 0, i32 1
  %145 = load i32, i32* %144, align 4
  %146 = sdiv i32 %145, 128
  store i32 %146, i32* %143, align 4
  %147 = getelementptr inbounds [3 x i32], [3 x i32]* %56, i64 0, i64 0
  %148 = getelementptr inbounds [3 x i32], [3 x i32]* %57, i64 0, i64 0
  %149 = call { i64, i64 } @setUpdateData(i32* noundef %147, i32* noundef %148, i32 noundef 3)
  %150 = bitcast i128* %59 to { i64, i64 }*
  %151 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %150, i32 0, i32 0
  %152 = extractvalue { i64, i64 } %149, 0
  store i64 %152, i64* %151, align 16
  %153 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %150, i32 0, i32 1
  %154 = extractvalue { i64, i64 } %149, 1
  store i64 %154, i64* %153, align 8
  %155 = load i128, i128* %59, align 16
  store i128 %155, i128* %58, align 16
  %156 = bitcast [8 x i32]* %60 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %156, i8* align 16 bitcast ([8 x i32]* @__const.simd_gemm_executor_Conv1d.positions_func to i8*), i64 32, i1 false)
  %157 = getelementptr inbounds [8 x i32], [8 x i32]* %61, i64 0, i64 0
  %158 = load i32, i32* %23, align 4
  store i32 %158, i32* %157, align 4
  %159 = getelementptr inbounds i32, i32* %157, i64 1
  %160 = load i32, i32* %25, align 4
  store i32 %160, i32* %159, align 4
  %161 = getelementptr inbounds i32, i32* %159, i64 1
  %162 = load i32, i32* %24, align 4
  store i32 %162, i32* %161, align 4
  %163 = getelementptr inbounds i32, i32* %161, i64 1
  %164 = load i32, i32* %19, align 4
  %165 = load i32, i32* %20, align 4
  %166 = mul nsw i32 %164, %165
  %167 = sdiv i32 %166, 128
  store i32 %167, i32* %163, align 4
  %168 = getelementptr inbounds i32, i32* %163, i64 1
  %169 = load i32, i32* %19, align 4
  %170 = load i32, i32* %20, align 4
  %171 = mul nsw i32 %169, %170
  %172 = load i32, i32* %24, align 4
  %173 = mul nsw i32 %171, %172
  %174 = sdiv i32 %173, 128
  store i32 %174, i32* %168, align 4
  %175 = getelementptr inbounds i32, i32* %168, i64 1
  %176 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %55, i32 0, i32 0
  %177 = load i32, i32* %176, align 4
  %178 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %55, i32 0, i32 1
  %179 = load i32, i32* %178, align 4
  %180 = mul nsw i32 %177, %179
  %181 = load i32, i32* %24, align 4
  %182 = mul nsw i32 %180, %181
  %183 = sdiv i32 %182, 128
  store i32 %183, i32* %175, align 4
  %184 = getelementptr inbounds i32, i32* %175, i64 1
  %185 = load i32, i32* %19, align 4
  %186 = load i32, i32* %23, align 4
  %187 = mul nsw i32 %185, %186
  store i32 %187, i32* %184, align 4
  %188 = getelementptr inbounds i32, i32* %184, i64 1
  %189 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %55, i32 0, i32 0
  %190 = load i32, i32* %189, align 4
  %191 = load i32, i32* %25, align 4
  %192 = mul nsw i32 %190, %191
  store i32 %192, i32* %188, align 4
  %193 = getelementptr inbounds [8 x i32], [8 x i32]* %60, i64 0, i64 0
  %194 = getelementptr inbounds [8 x i32], [8 x i32]* %61, i64 0, i64 0
  %195 = call { i64, i64 } @setUpdateData(i32* noundef %193, i32* noundef %194, i32 noundef 8)
  %196 = bitcast i128* %63 to { i64, i64 }*
  %197 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %196, i32 0, i32 0
  %198 = extractvalue { i64, i64 } %195, 0
  store i64 %198, i64* %197, align 16
  %199 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %196, i32 0, i32 1
  %200 = extractvalue { i64, i64 } %195, 1
  store i64 %200, i64* %199, align 8
  %201 = load i128, i128* %63, align 16
  store i128 %201, i128* %62, align 16
  %202 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %14, align 8
  %203 = load i16, i16* %35, align 2
  %204 = load i32, i32* %36, align 4
  %205 = load i128, i128* %45, align 16
  %206 = load i8, i8* %32, align 1
  %207 = load i8, i8* %33, align 1
  %208 = load i8, i8* %34, align 1
  store i128 %205, i128* %64, align 16
  %209 = bitcast i128* %64 to { i64, i64 }*
  %210 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %209, i32 0, i32 0
  %211 = load i64, i64* %210, align 16
  %212 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %209, i32 0, i32 1
  %213 = load i64, i64* %212, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %202, i16 noundef zeroext %203, i32 noundef %204, i64 noundef %211, i64 noundef %213, i8 noundef zeroext %206, i8 noundef zeroext %207, i8 noundef zeroext %208, i8 noundef zeroext 5)
  %214 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %14, align 8
  %215 = load i16, i16* %35, align 2
  %216 = load i32, i32* %36, align 4
  %217 = add i32 %216, 1
  %218 = load i128, i128* %49, align 16
  %219 = load i8, i8* %32, align 1
  %220 = load i8, i8* %33, align 1
  %221 = load i8, i8* %34, align 1
  store i128 %218, i128* %65, align 16
  %222 = bitcast i128* %65 to { i64, i64 }*
  %223 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %222, i32 0, i32 0
  %224 = load i64, i64* %223, align 16
  %225 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %222, i32 0, i32 1
  %226 = load i64, i64* %225, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %214, i16 noundef zeroext %215, i32 noundef %217, i64 noundef %224, i64 noundef %226, i8 noundef zeroext %219, i8 noundef zeroext %220, i8 noundef zeroext %221, i8 noundef zeroext 5)
  %227 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %14, align 8
  %228 = load i16, i16* %35, align 2
  %229 = load i32, i32* %36, align 4
  %230 = add i32 %229, 2
  %231 = load i128, i128* %53, align 16
  %232 = load i8, i8* %32, align 1
  %233 = load i8, i8* %33, align 1
  %234 = load i8, i8* %34, align 1
  store i128 %231, i128* %66, align 16
  %235 = bitcast i128* %66 to { i64, i64 }*
  %236 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %235, i32 0, i32 0
  %237 = load i64, i64* %236, align 16
  %238 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %235, i32 0, i32 1
  %239 = load i64, i64* %238, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %227, i16 noundef zeroext %228, i32 noundef %230, i64 noundef %237, i64 noundef %239, i8 noundef zeroext %232, i8 noundef zeroext %233, i8 noundef zeroext %234, i8 noundef zeroext 5)
  %240 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %14, align 8
  %241 = load i16, i16* %35, align 2
  %242 = load i32, i32* %36, align 4
  %243 = add i32 %242, 3
  %244 = load i128, i128* %58, align 16
  %245 = load i8, i8* %32, align 1
  %246 = load i8, i8* %33, align 1
  %247 = load i8, i8* %34, align 1
  store i128 %244, i128* %67, align 16
  %248 = bitcast i128* %67 to { i64, i64 }*
  %249 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %248, i32 0, i32 0
  %250 = load i64, i64* %249, align 16
  %251 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %248, i32 0, i32 1
  %252 = load i64, i64* %251, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %240, i16 noundef zeroext %241, i32 noundef %243, i64 noundef %250, i64 noundef %252, i8 noundef zeroext %245, i8 noundef zeroext %246, i8 noundef zeroext %247, i8 noundef zeroext 5)
  %253 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %14, align 8
  %254 = load i16, i16* %35, align 2
  %255 = load i32, i32* %36, align 4
  %256 = add i32 %255, 4
  %257 = load i128, i128* %62, align 16
  %258 = load i8, i8* %32, align 1
  %259 = load i8, i8* %33, align 1
  %260 = load i8, i8* %34, align 1
  store i128 %257, i128* %68, align 16
  %261 = bitcast i128* %68 to { i64, i64 }*
  %262 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %261, i32 0, i32 0
  %263 = load i64, i64* %262, align 16
  %264 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %261, i32 0, i32 1
  %265 = load i64, i64* %264, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %253, i16 noundef zeroext %254, i32 noundef %256, i64 noundef %263, i64 noundef %265, i8 noundef zeroext %258, i8 noundef zeroext %259, i8 noundef zeroext %260, i8 noundef zeroext 5)
  %266 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %14, align 8
  %267 = load i32, i32* %27, align 4
  %268 = load i32, i32* %28, align 4
  %269 = load i32, i32* %29, align 4
  %270 = load i32, i32* %30, align 4
  %271 = load i32, i32* %31, align 4
  %272 = load i8, i8* %32, align 1
  %273 = load i8, i8* %33, align 1
  %274 = load i8, i8* %34, align 1
  %275 = load i8, i8* %37, align 1
  %276 = load i8, i8* %38, align 1
  %277 = load i8, i8* %39, align 1
  %278 = load i8, i8* %40, align 1
  %279 = load i8, i8* %41, align 1
  %280 = load i8, i8* %42, align 1
  %281 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %266, i32 noundef %267, i32 noundef %268, i32 noundef %269, i32 noundef %270, i32 noundef %271, i8 noundef zeroext %272, i8 noundef zeroext %273, i8 noundef zeroext %274, i8 noundef zeroext %275, i8 noundef zeroext %276, i8 noundef zeroext %277, i8 noundef zeroext %278, i8 noundef zeroext %279, i8 noundef zeroext %280, i8 noundef zeroext 4)
  ret i32 %281
}

; Function Attrs: argmemonly nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #3

declare i64 @calculateConvOutputShape(i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) #1

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_gemm_executor_Conv2d(%struct.CoreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, double* noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, i32 noundef %11, i32 noundef %12, i32 noundef %13, i32 noundef %14, i32 noundef %15, i32 noundef %16, i32 noundef %17) #0 {
  %19 = alloca %struct.CoreExecutor_T*, align 8
  %20 = alloca double*, align 8
  %21 = alloca double*, align 8
  %22 = alloca double*, align 8
  %23 = alloca double*, align 8
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
  %42 = alloca i8, align 1
  %43 = alloca i8, align 1
  %44 = alloca i8, align 1
  %45 = alloca i16, align 2
  %46 = alloca i32, align 4
  %47 = alloca i8, align 1
  %48 = alloca i8, align 1
  %49 = alloca i8, align 1
  %50 = alloca i8, align 1
  %51 = alloca i8, align 1
  %52 = alloca i8, align 1
  %53 = alloca [4 x i32], align 16
  %54 = alloca [4 x i32], align 16
  %55 = alloca i128, align 16
  %56 = alloca i128, align 16
  %57 = alloca [4 x i32], align 16
  %58 = alloca [4 x i32], align 16
  %59 = alloca i128, align 16
  %60 = alloca i128, align 16
  %61 = alloca [1 x i32], align 4
  %62 = alloca [1 x i32], align 4
  %63 = alloca i128, align 16
  %64 = alloca i128, align 16
  %65 = alloca %struct.OutputShape, align 4
  %66 = alloca [4 x i32], align 16
  %67 = alloca [4 x i32], align 16
  %68 = alloca i128, align 16
  %69 = alloca i128, align 16
  %70 = alloca [8 x i32], align 16
  %71 = alloca [8 x i32], align 16
  %72 = alloca i128, align 16
  %73 = alloca i128, align 16
  %74 = alloca i128, align 16
  %75 = alloca i128, align 16
  %76 = alloca i128, align 16
  %77 = alloca i128, align 16
  %78 = alloca i128, align 16
  store %struct.CoreExecutor_T* %0, %struct.CoreExecutor_T** %19, align 8
  store double* %1, double** %20, align 8
  store double* %2, double** %21, align 8
  store double* %3, double** %22, align 8
  store double* %4, double** %23, align 8
  store i32 %5, i32* %24, align 4
  store i32 %6, i32* %25, align 4
  store i32 %7, i32* %26, align 4
  store i32 %8, i32* %27, align 4
  store i32 %9, i32* %28, align 4
  store i32 %10, i32* %29, align 4
  store i32 %11, i32* %30, align 4
  store i32 %12, i32* %31, align 4
  store i32 %13, i32* %32, align 4
  store i32 %14, i32* %33, align 4
  store i32 %15, i32* %34, align 4
  store i32 %16, i32* %35, align 4
  store i32 %17, i32* %36, align 4
  %79 = load double*, double** %20, align 8
  %80 = ptrtoint double* %79 to i64
  %81 = call i32 @convertToRelativeAddr(i64 noundef %80)
  store i32 %81, i32* %37, align 4
  %82 = load double*, double** %21, align 8
  %83 = ptrtoint double* %82 to i64
  %84 = call i32 @convertToRelativeAddr(i64 noundef %83)
  store i32 %84, i32* %38, align 4
  %85 = load double*, double** %22, align 8
  %86 = ptrtoint double* %85 to i64
  %87 = call i32 @convertToRelativeAddr(i64 noundef %86)
  store i32 %87, i32* %39, align 4
  %88 = load double*, double** %23, align 8
  %89 = ptrtoint double* %88 to i64
  %90 = call i32 @convertToRelativeAddr(i64 noundef %89)
  store i32 %90, i32* %40, align 4
  store i32 0, i32* %41, align 4
  store i8 3, i8* %42, align 1
  store i8 2, i8* %43, align 1
  store i8 0, i8* %44, align 1
  store i16 4369, i16* %45, align 2
  store i32 1, i32* %46, align 4
  store i8 1, i8* %47, align 1
  store i8 2, i8* %48, align 1
  store i8 3, i8* %49, align 1
  store i8 4, i8* %50, align 1
  store i8 0, i8* %51, align 1
  store i8 5, i8* %52, align 1
  %91 = bitcast [4 x i32]* %53 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %91, i8* align 16 bitcast ([4 x i32]* @__const.simd_gemm_executor_Conv2d.positions_src0 to i8*), i64 16, i1 false)
  %92 = getelementptr inbounds [4 x i32], [4 x i32]* %54, i64 0, i64 0
  %93 = load i32, i32* %24, align 4
  store i32 %93, i32* %92, align 4
  %94 = getelementptr inbounds i32, i32* %92, i64 1
  %95 = load i32, i32* %26, align 4
  store i32 %95, i32* %94, align 4
  %96 = getelementptr inbounds i32, i32* %94, i64 1
  %97 = load i32, i32* %25, align 4
  store i32 %97, i32* %96, align 4
  %98 = getelementptr inbounds i32, i32* %96, i64 1
  %99 = load i32, i32* %24, align 4
  %100 = add nsw i32 %99, 16
  %101 = sdiv i32 %100, 16
  %102 = sub nsw i32 %101, 1
  store i32 %102, i32* %98, align 4
  %103 = getelementptr inbounds [4 x i32], [4 x i32]* %53, i64 0, i64 0
  %104 = getelementptr inbounds [4 x i32], [4 x i32]* %54, i64 0, i64 0
  %105 = call { i64, i64 } @setUpdateData(i32* noundef %103, i32* noundef %104, i32 noundef 4)
  %106 = bitcast i128* %56 to { i64, i64 }*
  %107 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %106, i32 0, i32 0
  %108 = extractvalue { i64, i64 } %105, 0
  store i64 %108, i64* %107, align 16
  %109 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %106, i32 0, i32 1
  %110 = extractvalue { i64, i64 } %105, 1
  store i64 %110, i64* %109, align 8
  %111 = load i128, i128* %56, align 16
  store i128 %111, i128* %55, align 16
  %112 = bitcast [4 x i32]* %57 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %112, i8* align 16 bitcast ([4 x i32]* @__const.simd_gemm_executor_Conv2d.positions_src1 to i8*), i64 16, i1 false)
  %113 = getelementptr inbounds [4 x i32], [4 x i32]* %58, i64 0, i64 0
  %114 = load i32, i32* %27, align 4
  store i32 %114, i32* %113, align 4
  %115 = getelementptr inbounds i32, i32* %113, i64 1
  %116 = load i32, i32* %29, align 4
  store i32 %116, i32* %115, align 4
  %117 = getelementptr inbounds i32, i32* %115, i64 1
  %118 = load i32, i32* %28, align 4
  store i32 %118, i32* %117, align 4
  %119 = getelementptr inbounds i32, i32* %117, i64 1
  %120 = load i32, i32* %34, align 4
  store i32 %120, i32* %119, align 4
  %121 = getelementptr inbounds [4 x i32], [4 x i32]* %57, i64 0, i64 0
  %122 = getelementptr inbounds [4 x i32], [4 x i32]* %58, i64 0, i64 0
  %123 = call { i64, i64 } @setUpdateData(i32* noundef %121, i32* noundef %122, i32 noundef 4)
  %124 = bitcast i128* %60 to { i64, i64 }*
  %125 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %124, i32 0, i32 0
  %126 = extractvalue { i64, i64 } %123, 0
  store i64 %126, i64* %125, align 16
  %127 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %124, i32 0, i32 1
  %128 = extractvalue { i64, i64 } %123, 1
  store i64 %128, i64* %127, align 8
  %129 = load i128, i128* %60, align 16
  store i128 %129, i128* %59, align 16
  %130 = bitcast [1 x i32]* %61 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 4 %130, i8 0, i64 4, i1 false)
  %131 = getelementptr inbounds [1 x i32], [1 x i32]* %62, i64 0, i64 0
  %132 = load i32, i32* %30, align 4
  store i32 %132, i32* %131, align 4
  %133 = getelementptr inbounds [1 x i32], [1 x i32]* %61, i64 0, i64 0
  %134 = getelementptr inbounds [1 x i32], [1 x i32]* %62, i64 0, i64 0
  %135 = call { i64, i64 } @setUpdateData(i32* noundef %133, i32* noundef %134, i32 noundef 1)
  %136 = bitcast i128* %64 to { i64, i64 }*
  %137 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %136, i32 0, i32 0
  %138 = extractvalue { i64, i64 } %135, 0
  store i64 %138, i64* %137, align 16
  %139 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %136, i32 0, i32 1
  %140 = extractvalue { i64, i64 } %135, 1
  store i64 %140, i64* %139, align 8
  %141 = load i128, i128* %64, align 16
  store i128 %141, i128* %63, align 16
  %142 = load i32, i32* %24, align 4
  %143 = load i32, i32* %25, align 4
  %144 = load i32, i32* %27, align 4
  %145 = load i32, i32* %28, align 4
  %146 = load i32, i32* %31, align 4
  %147 = load i32, i32* %32, align 4
  %148 = call i64 @calculateConvOutputShape(i32 noundef %142, i32 noundef %143, i32 noundef %144, i32 noundef %145, i32 noundef %146, i32 noundef %147, i32 noundef 0, i32 noundef 0)
  %149 = bitcast %struct.OutputShape* %65 to i64*
  store i64 %148, i64* %149, align 4
  %150 = bitcast [4 x i32]* %66 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %150, i8* align 16 bitcast ([4 x i32]* @__const.simd_gemm_executor_Conv2d.positions_dst0 to i8*), i64 16, i1 false)
  %151 = getelementptr inbounds [4 x i32], [4 x i32]* %67, i64 0, i64 0
  %152 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %65, i32 0, i32 0
  %153 = load i32, i32* %152, align 4
  store i32 %153, i32* %151, align 4
  %154 = getelementptr inbounds i32, i32* %151, i64 1
  %155 = load i32, i32* %34, align 4
  store i32 %155, i32* %154, align 4
  %156 = getelementptr inbounds i32, i32* %154, i64 1
  %157 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %65, i32 0, i32 1
  %158 = load i32, i32* %157, align 4
  store i32 %158, i32* %156, align 4
  %159 = getelementptr inbounds i32, i32* %156, i64 1
  %160 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %65, i32 0, i32 1
  %161 = load i32, i32* %160, align 4
  %162 = sdiv i32 %161, 128
  store i32 %162, i32* %159, align 4
  %163 = getelementptr inbounds [4 x i32], [4 x i32]* %66, i64 0, i64 0
  %164 = getelementptr inbounds [4 x i32], [4 x i32]* %67, i64 0, i64 0
  %165 = call { i64, i64 } @setUpdateData(i32* noundef %163, i32* noundef %164, i32 noundef 4)
  %166 = bitcast i128* %69 to { i64, i64 }*
  %167 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %166, i32 0, i32 0
  %168 = extractvalue { i64, i64 } %165, 0
  store i64 %168, i64* %167, align 16
  %169 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %166, i32 0, i32 1
  %170 = extractvalue { i64, i64 } %165, 1
  store i64 %170, i64* %169, align 8
  %171 = load i128, i128* %69, align 16
  store i128 %171, i128* %68, align 16
  %172 = bitcast [8 x i32]* %70 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %172, i8* align 16 bitcast ([8 x i32]* @__const.simd_gemm_executor_Conv2d.positions_func to i8*), i64 32, i1 false)
  %173 = getelementptr inbounds [8 x i32], [8 x i32]* %71, i64 0, i64 0
  %174 = load i32, i32* %31, align 4
  store i32 %174, i32* %173, align 4
  %175 = getelementptr inbounds i32, i32* %173, i64 1
  %176 = load i32, i32* %33, align 4
  store i32 %176, i32* %175, align 4
  %177 = getelementptr inbounds i32, i32* %175, i64 1
  %178 = load i32, i32* %32, align 4
  store i32 %178, i32* %177, align 4
  %179 = getelementptr inbounds i32, i32* %177, i64 1
  %180 = load i32, i32* %24, align 4
  %181 = load i32, i32* %25, align 4
  %182 = mul nsw i32 %180, %181
  %183 = sdiv i32 %182, 128
  store i32 %183, i32* %179, align 4
  %184 = getelementptr inbounds i32, i32* %179, i64 1
  %185 = load i32, i32* %24, align 4
  %186 = load i32, i32* %25, align 4
  %187 = mul nsw i32 %185, %186
  %188 = load i32, i32* %32, align 4
  %189 = mul nsw i32 %187, %188
  %190 = sdiv i32 %189, 128
  store i32 %190, i32* %184, align 4
  %191 = getelementptr inbounds i32, i32* %184, i64 1
  %192 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %65, i32 0, i32 0
  %193 = load i32, i32* %192, align 4
  %194 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %65, i32 0, i32 1
  %195 = load i32, i32* %194, align 4
  %196 = mul nsw i32 %193, %195
  %197 = load i32, i32* %32, align 4
  %198 = mul nsw i32 %196, %197
  %199 = sdiv i32 %198, 128
  store i32 %199, i32* %191, align 4
  %200 = getelementptr inbounds i32, i32* %191, i64 1
  %201 = load i32, i32* %24, align 4
  %202 = load i32, i32* %31, align 4
  %203 = mul nsw i32 %201, %202
  store i32 %203, i32* %200, align 4
  %204 = getelementptr inbounds i32, i32* %200, i64 1
  %205 = getelementptr inbounds %struct.OutputShape, %struct.OutputShape* %65, i32 0, i32 0
  %206 = load i32, i32* %205, align 4
  %207 = load i32, i32* %33, align 4
  %208 = mul nsw i32 %206, %207
  store i32 %208, i32* %204, align 4
  %209 = getelementptr inbounds [8 x i32], [8 x i32]* %70, i64 0, i64 0
  %210 = getelementptr inbounds [8 x i32], [8 x i32]* %71, i64 0, i64 0
  %211 = call { i64, i64 } @setUpdateData(i32* noundef %209, i32* noundef %210, i32 noundef 8)
  %212 = bitcast i128* %73 to { i64, i64 }*
  %213 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %212, i32 0, i32 0
  %214 = extractvalue { i64, i64 } %211, 0
  store i64 %214, i64* %213, align 16
  %215 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %212, i32 0, i32 1
  %216 = extractvalue { i64, i64 } %211, 1
  store i64 %216, i64* %215, align 8
  %217 = load i128, i128* %73, align 16
  store i128 %217, i128* %72, align 16
  %218 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %19, align 8
  %219 = load i16, i16* %45, align 2
  %220 = load i32, i32* %46, align 4
  %221 = load i128, i128* %55, align 16
  %222 = load i8, i8* %42, align 1
  %223 = load i8, i8* %43, align 1
  %224 = load i8, i8* %44, align 1
  store i128 %221, i128* %74, align 16
  %225 = bitcast i128* %74 to { i64, i64 }*
  %226 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %225, i32 0, i32 0
  %227 = load i64, i64* %226, align 16
  %228 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %225, i32 0, i32 1
  %229 = load i64, i64* %228, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %218, i16 noundef zeroext %219, i32 noundef %220, i64 noundef %227, i64 noundef %229, i8 noundef zeroext %222, i8 noundef zeroext %223, i8 noundef zeroext %224, i8 noundef zeroext 5)
  %230 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %19, align 8
  %231 = load i16, i16* %45, align 2
  %232 = load i32, i32* %46, align 4
  %233 = add i32 %232, 1
  %234 = load i128, i128* %59, align 16
  %235 = load i8, i8* %42, align 1
  %236 = load i8, i8* %43, align 1
  %237 = load i8, i8* %44, align 1
  store i128 %234, i128* %75, align 16
  %238 = bitcast i128* %75 to { i64, i64 }*
  %239 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %238, i32 0, i32 0
  %240 = load i64, i64* %239, align 16
  %241 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %238, i32 0, i32 1
  %242 = load i64, i64* %241, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %230, i16 noundef zeroext %231, i32 noundef %233, i64 noundef %240, i64 noundef %242, i8 noundef zeroext %235, i8 noundef zeroext %236, i8 noundef zeroext %237, i8 noundef zeroext 5)
  %243 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %19, align 8
  %244 = load i16, i16* %45, align 2
  %245 = load i32, i32* %46, align 4
  %246 = add i32 %245, 2
  %247 = load i128, i128* %63, align 16
  %248 = load i8, i8* %42, align 1
  %249 = load i8, i8* %43, align 1
  %250 = load i8, i8* %44, align 1
  store i128 %247, i128* %76, align 16
  %251 = bitcast i128* %76 to { i64, i64 }*
  %252 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %251, i32 0, i32 0
  %253 = load i64, i64* %252, align 16
  %254 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %251, i32 0, i32 1
  %255 = load i64, i64* %254, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %243, i16 noundef zeroext %244, i32 noundef %246, i64 noundef %253, i64 noundef %255, i8 noundef zeroext %248, i8 noundef zeroext %249, i8 noundef zeroext %250, i8 noundef zeroext 5)
  %256 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %19, align 8
  %257 = load i16, i16* %45, align 2
  %258 = load i32, i32* %46, align 4
  %259 = add i32 %258, 3
  %260 = load i128, i128* %68, align 16
  %261 = load i8, i8* %42, align 1
  %262 = load i8, i8* %43, align 1
  %263 = load i8, i8* %44, align 1
  store i128 %260, i128* %77, align 16
  %264 = bitcast i128* %77 to { i64, i64 }*
  %265 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %264, i32 0, i32 0
  %266 = load i64, i64* %265, align 16
  %267 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %264, i32 0, i32 1
  %268 = load i64, i64* %267, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %256, i16 noundef zeroext %257, i32 noundef %259, i64 noundef %266, i64 noundef %268, i8 noundef zeroext %261, i8 noundef zeroext %262, i8 noundef zeroext %263, i8 noundef zeroext 5)
  %269 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %19, align 8
  %270 = load i16, i16* %45, align 2
  %271 = load i32, i32* %46, align 4
  %272 = add i32 %271, 4
  %273 = load i128, i128* %72, align 16
  %274 = load i8, i8* %42, align 1
  %275 = load i8, i8* %43, align 1
  %276 = load i8, i8* %44, align 1
  store i128 %273, i128* %78, align 16
  %277 = bitcast i128* %78 to { i64, i64 }*
  %278 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %277, i32 0, i32 0
  %279 = load i64, i64* %278, align 16
  %280 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %277, i32 0, i32 1
  %281 = load i64, i64* %280, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %269, i16 noundef zeroext %270, i32 noundef %272, i64 noundef %279, i64 noundef %281, i8 noundef zeroext %274, i8 noundef zeroext %275, i8 noundef zeroext %276, i8 noundef zeroext 5)
  %282 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %19, align 8
  %283 = load i32, i32* %37, align 4
  %284 = load i32, i32* %38, align 4
  %285 = load i32, i32* %39, align 4
  %286 = load i32, i32* %40, align 4
  %287 = load i32, i32* %41, align 4
  %288 = load i8, i8* %42, align 1
  %289 = load i8, i8* %43, align 1
  %290 = load i8, i8* %44, align 1
  %291 = load i8, i8* %47, align 1
  %292 = load i8, i8* %48, align 1
  %293 = load i8, i8* %49, align 1
  %294 = load i8, i8* %50, align 1
  %295 = load i8, i8* %51, align 1
  %296 = load i8, i8* %52, align 1
  %297 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %282, i32 noundef %283, i32 noundef %284, i32 noundef %285, i32 noundef %286, i32 noundef %287, i8 noundef zeroext %288, i8 noundef zeroext %289, i8 noundef zeroext %290, i8 noundef zeroext %291, i8 noundef zeroext %292, i8 noundef zeroext %293, i8 noundef zeroext %294, i8 noundef zeroext %295, i8 noundef zeroext %296, i8 noundef zeroext 4)
  ret i32 %297
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_gemm_executor_Ax(%struct.CoreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, double noundef %9, double noundef %10) #0 {
  %12 = alloca %struct.CoreExecutor_T*, align 8
  %13 = alloca double*, align 8
  %14 = alloca double*, align 8
  %15 = alloca double*, align 8
  %16 = alloca i32, align 4
  %17 = alloca i32, align 4
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca double, align 8
  %22 = alloca double, align 8
  %23 = alloca i32, align 4
  %24 = alloca i32, align 4
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i8, align 1
  %29 = alloca i8, align 1
  %30 = alloca i8, align 1
  %31 = alloca i16, align 2
  %32 = alloca i32, align 4
  %33 = alloca i8, align 1
  %34 = alloca i8, align 1
  %35 = alloca i8, align 1
  %36 = alloca i8, align 1
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca [3 x i32], align 4
  %40 = alloca [3 x i32], align 4
  %41 = alloca i128, align 16
  %42 = alloca i128, align 16
  %43 = alloca [1 x i32], align 4
  %44 = alloca [1 x i32], align 4
  %45 = alloca i128, align 16
  %46 = alloca i128, align 16
  %47 = alloca [2 x i32], align 4
  %48 = alloca [2 x i32], align 4
  %49 = alloca i128, align 16
  %50 = alloca i128, align 16
  %51 = alloca [1 x i32], align 4
  %52 = alloca [1 x i32], align 4
  %53 = alloca i128, align 16
  %54 = alloca i128, align 16
  %55 = alloca i128, align 16
  %56 = alloca i128, align 16
  %57 = alloca i128, align 16
  %58 = alloca i128, align 16
  store %struct.CoreExecutor_T* %0, %struct.CoreExecutor_T** %12, align 8
  store double* %1, double** %13, align 8
  store double* %2, double** %14, align 8
  store double* %3, double** %15, align 8
  store i32 %4, i32* %16, align 4
  store i32 %5, i32* %17, align 4
  store i32 %6, i32* %18, align 4
  store i32 %7, i32* %19, align 4
  store i32 %8, i32* %20, align 4
  store double %9, double* %21, align 8
  store double %10, double* %22, align 8
  %59 = load double*, double** %13, align 8
  %60 = ptrtoint double* %59 to i64
  %61 = call i32 @convertToRelativeAddr(i64 noundef %60)
  store i32 %61, i32* %23, align 4
  %62 = load double*, double** %14, align 8
  %63 = ptrtoint double* %62 to i64
  %64 = call i32 @convertToRelativeAddr(i64 noundef %63)
  store i32 %64, i32* %24, align 4
  store i32 0, i32* %25, align 4
  %65 = load double*, double** %15, align 8
  %66 = ptrtoint double* %65 to i64
  %67 = call i32 @convertToRelativeAddr(i64 noundef %66)
  store i32 %67, i32* %26, align 4
  store i32 0, i32* %27, align 4
  store i8 4, i8* %28, align 1
  store i8 2, i8* %29, align 1
  store i8 0, i8* %30, align 1
  store i16 4369, i16* %31, align 2
  store i32 1, i32* %32, align 4
  store i8 1, i8* %33, align 1
  store i8 2, i8* %34, align 1
  store i8 0, i8* %35, align 1
  store i8 3, i8* %36, align 1
  store i8 0, i8* %37, align 1
  store i8 4, i8* %38, align 1
  %68 = bitcast [3 x i32]* %39 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %68, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_Ax.positions_src0 to i8*), i64 12, i1 false)
  %69 = getelementptr inbounds [3 x i32], [3 x i32]* %40, i64 0, i64 0
  %70 = load i32, i32* %17, align 4
  store i32 %70, i32* %69, align 4
  %71 = getelementptr inbounds i32, i32* %69, i64 1
  %72 = load i32, i32* %16, align 4
  store i32 %72, i32* %71, align 4
  %73 = getelementptr inbounds i32, i32* %71, i64 1
  %74 = load i32, i32* %17, align 4
  %75 = add nsw i32 %74, 16
  %76 = sdiv i32 %75, 16
  %77 = sub nsw i32 %76, 1
  store i32 %77, i32* %73, align 4
  %78 = getelementptr inbounds [3 x i32], [3 x i32]* %39, i64 0, i64 0
  %79 = getelementptr inbounds [3 x i32], [3 x i32]* %40, i64 0, i64 0
  %80 = call { i64, i64 } @setUpdateData(i32* noundef %78, i32* noundef %79, i32 noundef 3)
  %81 = bitcast i128* %42 to { i64, i64 }*
  %82 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %81, i32 0, i32 0
  %83 = extractvalue { i64, i64 } %80, 0
  store i64 %83, i64* %82, align 16
  %84 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %81, i32 0, i32 1
  %85 = extractvalue { i64, i64 } %80, 1
  store i64 %85, i64* %84, align 8
  %86 = load i128, i128* %42, align 16
  store i128 %86, i128* %41, align 16
  %87 = bitcast [1 x i32]* %43 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 4 %87, i8 0, i64 4, i1 false)
  %88 = getelementptr inbounds [1 x i32], [1 x i32]* %44, i64 0, i64 0
  %89 = load i32, i32* %17, align 4
  store i32 %89, i32* %88, align 4
  %90 = getelementptr inbounds [1 x i32], [1 x i32]* %43, i64 0, i64 0
  %91 = getelementptr inbounds [1 x i32], [1 x i32]* %44, i64 0, i64 0
  %92 = call { i64, i64 } @setUpdateData(i32* noundef %90, i32* noundef %91, i32 noundef 1)
  %93 = bitcast i128* %46 to { i64, i64 }*
  %94 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %93, i32 0, i32 0
  %95 = extractvalue { i64, i64 } %92, 0
  store i64 %95, i64* %94, align 16
  %96 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %93, i32 0, i32 1
  %97 = extractvalue { i64, i64 } %92, 1
  store i64 %97, i64* %96, align 8
  %98 = load i128, i128* %46, align 16
  store i128 %98, i128* %45, align 16
  %99 = bitcast [2 x i32]* %47 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %99, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_Ax.positions_dst0 to i8*), i64 8, i1 false)
  %100 = getelementptr inbounds [2 x i32], [2 x i32]* %48, i64 0, i64 0
  %101 = load i32, i32* %16, align 4
  store i32 %101, i32* %100, align 4
  %102 = getelementptr inbounds i32, i32* %100, i64 1
  store i32 1, i32* %102, align 4
  %103 = getelementptr inbounds [2 x i32], [2 x i32]* %47, i64 0, i64 0
  %104 = getelementptr inbounds [2 x i32], [2 x i32]* %48, i64 0, i64 0
  %105 = call { i64, i64 } @setUpdateData(i32* noundef %103, i32* noundef %104, i32 noundef 2)
  %106 = bitcast i128* %50 to { i64, i64 }*
  %107 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %106, i32 0, i32 0
  %108 = extractvalue { i64, i64 } %105, 0
  store i64 %108, i64* %107, align 16
  %109 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %106, i32 0, i32 1
  %110 = extractvalue { i64, i64 } %105, 1
  store i64 %110, i64* %109, align 8
  %111 = load i128, i128* %50, align 16
  store i128 %111, i128* %49, align 16
  %112 = bitcast [1 x i32]* %51 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %112, i8* align 4 bitcast ([1 x i32]* @__const.simd_gemm_executor_Ax.positions_func to i8*), i64 4, i1 false)
  %113 = getelementptr inbounds [1 x i32], [1 x i32]* %52, i64 0, i64 0
  %114 = load i32, i32* %17, align 4
  %115 = load i32, i32* %16, align 4
  %116 = mul nsw i32 %114, %115
  %117 = sdiv i32 %116, 128
  store i32 %117, i32* %113, align 4
  %118 = getelementptr inbounds [1 x i32], [1 x i32]* %51, i64 0, i64 0
  %119 = getelementptr inbounds [1 x i32], [1 x i32]* %52, i64 0, i64 0
  %120 = call { i64, i64 } @setUpdateData(i32* noundef %118, i32* noundef %119, i32 noundef 1)
  %121 = bitcast i128* %54 to { i64, i64 }*
  %122 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %121, i32 0, i32 0
  %123 = extractvalue { i64, i64 } %120, 0
  store i64 %123, i64* %122, align 16
  %124 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %121, i32 0, i32 1
  %125 = extractvalue { i64, i64 } %120, 1
  store i64 %125, i64* %124, align 8
  %126 = load i128, i128* %54, align 16
  store i128 %126, i128* %53, align 16
  %127 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %12, align 8
  %128 = load i16, i16* %31, align 2
  %129 = load i32, i32* %32, align 4
  %130 = load i128, i128* %41, align 16
  %131 = load i8, i8* %28, align 1
  %132 = load i8, i8* %29, align 1
  %133 = load i8, i8* %30, align 1
  store i128 %130, i128* %55, align 16
  %134 = bitcast i128* %55 to { i64, i64 }*
  %135 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %134, i32 0, i32 0
  %136 = load i64, i64* %135, align 16
  %137 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %134, i32 0, i32 1
  %138 = load i64, i64* %137, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %127, i16 noundef zeroext %128, i32 noundef %129, i64 noundef %136, i64 noundef %138, i8 noundef zeroext %131, i8 noundef zeroext %132, i8 noundef zeroext %133, i8 noundef zeroext 5)
  %139 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %12, align 8
  %140 = load i16, i16* %31, align 2
  %141 = load i32, i32* %32, align 4
  %142 = add i32 %141, 1
  %143 = load i128, i128* %45, align 16
  %144 = load i8, i8* %28, align 1
  %145 = load i8, i8* %29, align 1
  %146 = load i8, i8* %30, align 1
  store i128 %143, i128* %56, align 16
  %147 = bitcast i128* %56 to { i64, i64 }*
  %148 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 0
  %149 = load i64, i64* %148, align 16
  %150 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 1
  %151 = load i64, i64* %150, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %139, i16 noundef zeroext %140, i32 noundef %142, i64 noundef %149, i64 noundef %151, i8 noundef zeroext %144, i8 noundef zeroext %145, i8 noundef zeroext %146, i8 noundef zeroext 5)
  %152 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %12, align 8
  %153 = load i16, i16* %31, align 2
  %154 = load i32, i32* %32, align 4
  %155 = add i32 %154, 2
  %156 = load i128, i128* %49, align 16
  %157 = load i8, i8* %28, align 1
  %158 = load i8, i8* %29, align 1
  %159 = load i8, i8* %30, align 1
  store i128 %156, i128* %57, align 16
  %160 = bitcast i128* %57 to { i64, i64 }*
  %161 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %160, i32 0, i32 0
  %162 = load i64, i64* %161, align 16
  %163 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %160, i32 0, i32 1
  %164 = load i64, i64* %163, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %152, i16 noundef zeroext %153, i32 noundef %155, i64 noundef %162, i64 noundef %164, i8 noundef zeroext %157, i8 noundef zeroext %158, i8 noundef zeroext %159, i8 noundef zeroext 5)
  %165 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %12, align 8
  %166 = load i16, i16* %31, align 2
  %167 = load i32, i32* %32, align 4
  %168 = add i32 %167, 3
  %169 = load i128, i128* %53, align 16
  %170 = load i8, i8* %28, align 1
  %171 = load i8, i8* %29, align 1
  %172 = load i8, i8* %30, align 1
  store i128 %169, i128* %58, align 16
  %173 = bitcast i128* %58 to { i64, i64 }*
  %174 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %173, i32 0, i32 0
  %175 = load i64, i64* %174, align 16
  %176 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %173, i32 0, i32 1
  %177 = load i64, i64* %176, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %165, i16 noundef zeroext %166, i32 noundef %168, i64 noundef %175, i64 noundef %177, i8 noundef zeroext %170, i8 noundef zeroext %171, i8 noundef zeroext %172, i8 noundef zeroext 5)
  %178 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %12, align 8
  %179 = load i32, i32* %23, align 4
  %180 = load i32, i32* %24, align 4
  %181 = load i32, i32* %25, align 4
  %182 = load i32, i32* %26, align 4
  %183 = load i32, i32* %27, align 4
  %184 = load i8, i8* %28, align 1
  %185 = load i8, i8* %29, align 1
  %186 = load i8, i8* %30, align 1
  %187 = load i8, i8* %33, align 1
  %188 = load i8, i8* %34, align 1
  %189 = load i8, i8* %35, align 1
  %190 = load i8, i8* %36, align 1
  %191 = load i8, i8* %37, align 1
  %192 = load i8, i8* %38, align 1
  %193 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %178, i32 noundef %179, i32 noundef %180, i32 noundef %181, i32 noundef %182, i32 noundef %183, i8 noundef zeroext %184, i8 noundef zeroext %185, i8 noundef zeroext %186, i8 noundef zeroext %187, i8 noundef zeroext %188, i8 noundef zeroext %189, i8 noundef zeroext %190, i8 noundef zeroext %191, i8 noundef zeroext %192, i8 noundef zeroext 4)
  ret i32 %193
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_reshape(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, i32 noundef %11, i32 noundef %12, i32 noundef %13, i32 noundef %14, i32 noundef %15, i32 noundef %16, i32 noundef %17, i32 noundef %18) #0 {
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
  %67 = call i32 @convertToRelativeAddr(i64 noundef %66)
  store i32 %67, i32* %39, align 4
  store i32 0, i32* %40, align 4
  store i32 0, i32* %41, align 4
  %68 = load double*, double** %22, align 8
  %69 = ptrtoint double* %68 to i64
  %70 = call i32 @convertToRelativeAddr(i64 noundef %69)
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
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %88, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false)
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
  %108 = call { i64, i64 } @setUpdateData(i32* noundef %106, i32* noundef %107, i32 noundef 7)
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
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %115, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false)
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
  %135 = call { i64, i64 } @setUpdateData(i32* noundef %133, i32* noundef %134, i32 noundef 7)
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
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %142, i16 noundef zeroext %143, i32 noundef %144, i64 noundef %149, i64 noundef %151, i8 noundef zeroext %146, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9)
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
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %152, i16 noundef zeroext %153, i32 noundef %155, i64 noundef %160, i64 noundef %162, i8 noundef zeroext %157, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9)
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
  %178 = call i32 @Dre(%struct.DreExecutor_T* noundef %163, i32 noundef %164, i32 noundef %165, i32 noundef %166, i32 noundef %167, i32 noundef %168, i8 noundef zeroext %169, i8 noundef zeroext %170, i8 noundef zeroext %171, i8 noundef zeroext %172, i8 noundef zeroext %173, i8 noundef zeroext %174, i8 noundef zeroext %175, i8 noundef zeroext %176, i8 noundef zeroext %177, i8 noundef zeroext 8)
  ret i32 %178
}

declare void @simd_dre_init(%struct.DreExecutor_T* noundef, i16 noundef zeroext, i32 noundef, i64 noundef, i64 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

declare i32 @Dre(%struct.DreExecutor_T* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_swap(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7) #0 {
  %9 = alloca %struct.DreExecutor_T*, align 8
  %10 = alloca double*, align 8
  %11 = alloca double*, align 8
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = alloca i32, align 4
  %17 = alloca i32, align 4
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i8, align 1
  %23 = alloca i8, align 1
  %24 = alloca i8, align 1
  %25 = alloca i16, align 2
  %26 = alloca i32, align 4
  %27 = alloca i8, align 1
  %28 = alloca i8, align 1
  %29 = alloca i8, align 1
  %30 = alloca i8, align 1
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca [7 x i32], align 16
  %34 = alloca [7 x i32], align 16
  %35 = alloca i128, align 16
  %36 = alloca i128, align 16
  %37 = alloca [7 x i32], align 16
  %38 = alloca [7 x i32], align 16
  %39 = alloca i128, align 16
  %40 = alloca i128, align 16
  %41 = alloca i128, align 16
  %42 = alloca i128, align 16
  store %struct.DreExecutor_T* %0, %struct.DreExecutor_T** %9, align 8
  store double* %1, double** %10, align 8
  store double* %2, double** %11, align 8
  store i32 %3, i32* %12, align 4
  store i32 %4, i32* %13, align 4
  store i32 %5, i32* %14, align 4
  store i32 %6, i32* %15, align 4
  store i32 %7, i32* %16, align 4
  %43 = load double*, double** %10, align 8
  %44 = ptrtoint double* %43 to i64
  %45 = call i32 @convertToRelativeAddr(i64 noundef %44)
  store i32 %45, i32* %17, align 4
  store i32 0, i32* %18, align 4
  store i32 0, i32* %19, align 4
  %46 = load double*, double** %11, align 8
  %47 = ptrtoint double* %46 to i64
  %48 = call i32 @convertToRelativeAddr(i64 noundef %47)
  store i32 %48, i32* %20, align 4
  store i32 0, i32* %21, align 4
  store i8 1, i8* %22, align 1
  store i8 2, i8* %23, align 1
  store i8 0, i8* %24, align 1
  store i16 -1, i16* %25, align 2
  store i32 1, i32* %26, align 4
  store i8 0, i8* %27, align 1
  store i8 1, i8* %28, align 1
  store i8 2, i8* %29, align 1
  store i8 3, i8* %30, align 1
  store i8 4, i8* %31, align 1
  store i8 0, i8* %32, align 1
  %49 = bitcast [7 x i32]* %33 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %49, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_swap.positions_src0 to i8*), i64 28, i1 false)
  %50 = getelementptr inbounds [7 x i32], [7 x i32]* %34, i64 0, i64 0
  %51 = load i32, i32* %12, align 4
  %52 = sub nsw i32 %51, 1
  store i32 %52, i32* %50, align 4
  %53 = getelementptr inbounds i32, i32* %50, i64 1
  %54 = load i32, i32* %14, align 4
  %55 = sub nsw i32 %54, 1
  store i32 %55, i32* %53, align 4
  %56 = getelementptr inbounds i32, i32* %53, i64 1
  %57 = load i32, i32* %13, align 4
  %58 = sub nsw i32 %57, 1
  store i32 %58, i32* %56, align 4
  %59 = getelementptr inbounds i32, i32* %56, i64 1
  %60 = load i32, i32* %15, align 4
  store i32 %60, i32* %59, align 4
  %61 = getelementptr inbounds i32, i32* %59, i64 1
  store i32 0, i32* %61, align 4
  %62 = getelementptr inbounds i32, i32* %61, i64 1
  store i32 0, i32* %62, align 4
  %63 = getelementptr inbounds i32, i32* %62, i64 1
  %64 = load i32, i32* %13, align 4
  %65 = sub nsw i32 %64, 1
  store i32 %65, i32* %63, align 4
  %66 = getelementptr inbounds [7 x i32], [7 x i32]* %33, i64 0, i64 0
  %67 = getelementptr inbounds [7 x i32], [7 x i32]* %34, i64 0, i64 0
  %68 = call { i64, i64 } @setUpdateData(i32* noundef %66, i32* noundef %67, i32 noundef 7)
  %69 = bitcast i128* %36 to { i64, i64 }*
  %70 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %69, i32 0, i32 0
  %71 = extractvalue { i64, i64 } %68, 0
  store i64 %71, i64* %70, align 16
  %72 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %69, i32 0, i32 1
  %73 = extractvalue { i64, i64 } %68, 1
  store i64 %73, i64* %72, align 8
  %74 = load i128, i128* %36, align 16
  store i128 %74, i128* %35, align 16
  %75 = bitcast [7 x i32]* %37 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %75, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_swap.positions_dst0 to i8*), i64 28, i1 false)
  %76 = getelementptr inbounds [7 x i32], [7 x i32]* %38, i64 0, i64 0
  %77 = load i32, i32* %12, align 4
  %78 = sub nsw i32 %77, 1
  store i32 %78, i32* %76, align 4
  %79 = getelementptr inbounds i32, i32* %76, i64 1
  %80 = load i32, i32* %14, align 4
  %81 = sub nsw i32 %80, 1
  store i32 %81, i32* %79, align 4
  %82 = getelementptr inbounds i32, i32* %79, i64 1
  %83 = load i32, i32* %13, align 4
  %84 = sub nsw i32 %83, 1
  store i32 %84, i32* %82, align 4
  %85 = getelementptr inbounds i32, i32* %82, i64 1
  %86 = load i32, i32* %16, align 4
  store i32 %86, i32* %85, align 4
  %87 = getelementptr inbounds i32, i32* %85, i64 1
  store i32 0, i32* %87, align 4
  %88 = getelementptr inbounds i32, i32* %87, i64 1
  store i32 0, i32* %88, align 4
  %89 = getelementptr inbounds i32, i32* %88, i64 1
  %90 = load i32, i32* %13, align 4
  %91 = sub nsw i32 %90, 1
  store i32 %91, i32* %89, align 4
  %92 = getelementptr inbounds [7 x i32], [7 x i32]* %37, i64 0, i64 0
  %93 = getelementptr inbounds [7 x i32], [7 x i32]* %38, i64 0, i64 0
  %94 = call { i64, i64 } @setUpdateData(i32* noundef %92, i32* noundef %93, i32 noundef 7)
  %95 = bitcast i128* %40 to { i64, i64 }*
  %96 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %95, i32 0, i32 0
  %97 = extractvalue { i64, i64 } %94, 0
  store i64 %97, i64* %96, align 16
  %98 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %95, i32 0, i32 1
  %99 = extractvalue { i64, i64 } %94, 1
  store i64 %99, i64* %98, align 8
  %100 = load i128, i128* %40, align 16
  store i128 %100, i128* %39, align 16
  %101 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %9, align 8
  %102 = load i16, i16* %25, align 2
  %103 = load i8, i8* %27, align 1
  %104 = zext i8 %103 to i32
  %105 = load i128, i128* %35, align 16
  %106 = load i8, i8* %22, align 1
  %107 = load i8, i8* %23, align 1
  %108 = load i8, i8* %24, align 1
  store i128 %105, i128* %41, align 16
  %109 = bitcast i128* %41 to { i64, i64 }*
  %110 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %109, i32 0, i32 0
  %111 = load i64, i64* %110, align 16
  %112 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %109, i32 0, i32 1
  %113 = load i64, i64* %112, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %101, i16 noundef zeroext %102, i32 noundef %104, i64 noundef %111, i64 noundef %113, i8 noundef zeroext %106, i8 noundef zeroext %107, i8 noundef zeroext %108, i8 noundef zeroext 9)
  %114 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %9, align 8
  %115 = load i16, i16* %25, align 2
  %116 = load i8, i8* %30, align 1
  %117 = zext i8 %116 to i32
  %118 = load i128, i128* %39, align 16
  %119 = load i8, i8* %22, align 1
  %120 = load i8, i8* %23, align 1
  %121 = load i8, i8* %24, align 1
  store i128 %118, i128* %42, align 16
  %122 = bitcast i128* %42 to { i64, i64 }*
  %123 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %122, i32 0, i32 0
  %124 = load i64, i64* %123, align 16
  %125 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %122, i32 0, i32 1
  %126 = load i64, i64* %125, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %114, i16 noundef zeroext %115, i32 noundef %117, i64 noundef %124, i64 noundef %126, i8 noundef zeroext %119, i8 noundef zeroext %120, i8 noundef zeroext %121, i8 noundef zeroext 9)
  %127 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %9, align 8
  %128 = load i32, i32* %17, align 4
  %129 = load i32, i32* %18, align 4
  %130 = load i32, i32* %19, align 4
  %131 = load i32, i32* %20, align 4
  %132 = load i32, i32* %21, align 4
  %133 = load i8, i8* %22, align 1
  %134 = load i8, i8* %23, align 1
  %135 = load i8, i8* %24, align 1
  %136 = load i8, i8* %27, align 1
  %137 = load i8, i8* %28, align 1
  %138 = load i8, i8* %29, align 1
  %139 = load i8, i8* %30, align 1
  %140 = load i8, i8* %31, align 1
  %141 = load i8, i8* %32, align 1
  %142 = call i32 @Dre(%struct.DreExecutor_T* noundef %127, i32 noundef %128, i32 noundef %129, i32 noundef %130, i32 noundef %131, i32 noundef %132, i8 noundef zeroext %133, i8 noundef zeroext %134, i8 noundef zeroext %135, i8 noundef zeroext %136, i8 noundef zeroext %137, i8 noundef zeroext %138, i8 noundef zeroext %139, i8 noundef zeroext %140, i8 noundef zeroext %141, i8 noundef zeroext 8)
  ret i32 %142
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_reduce_argmax(%struct.DreExecutor_T* noundef %0, double* noundef %1, i128* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8) #0 {
  %10 = alloca %struct.DreExecutor_T*, align 8
  %11 = alloca double*, align 8
  %12 = alloca i128*, align 8
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = alloca i32, align 4
  %17 = alloca i32, align 4
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca i32, align 4
  %24 = alloca i8, align 1
  %25 = alloca i8, align 1
  %26 = alloca i8, align 1
  %27 = alloca i16, align 2
  %28 = alloca i32, align 4
  %29 = alloca i8, align 1
  %30 = alloca i8, align 1
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca i8, align 1
  %34 = alloca i8, align 1
  %35 = alloca [7 x i32], align 16
  %36 = alloca [7 x i32], align 16
  %37 = alloca i128, align 16
  %38 = alloca i128, align 16
  %39 = alloca [7 x i32], align 16
  %40 = alloca [7 x i32], align 16
  %41 = alloca i128, align 16
  %42 = alloca i128, align 16
  %43 = alloca i128, align 16
  %44 = alloca i128, align 16
  store %struct.DreExecutor_T* %0, %struct.DreExecutor_T** %10, align 8
  store double* %1, double** %11, align 8
  store i128* %2, i128** %12, align 8
  store i32 %3, i32* %13, align 4
  store i32 %4, i32* %14, align 4
  store i32 %5, i32* %15, align 4
  store i32 %6, i32* %16, align 4
  store i32 %7, i32* %17, align 4
  store i32 %8, i32* %18, align 4
  %45 = load double*, double** %11, align 8
  %46 = ptrtoint double* %45 to i64
  %47 = call i32 @convertToRelativeAddr(i64 noundef %46)
  store i32 %47, i32* %19, align 4
  store i32 0, i32* %20, align 4
  store i32 0, i32* %21, align 4
  %48 = load i128*, i128** %12, align 8
  %49 = ptrtoint i128* %48 to i64
  %50 = call i32 @convertToRelativeAddr(i64 noundef %49)
  store i32 %50, i32* %22, align 4
  store i32 0, i32* %23, align 4
  store i8 8, i8* %24, align 1
  store i8 2, i8* %25, align 1
  store i8 0, i8* %26, align 1
  store i16 -1, i16* %27, align 2
  store i32 0, i32* %28, align 4
  store i8 0, i8* %29, align 1
  store i8 1, i8* %30, align 1
  store i8 2, i8* %31, align 1
  store i8 3, i8* %32, align 1
  store i8 4, i8* %33, align 1
  %51 = load i32, i32* %18, align 4
  %52 = icmp ne i32 %51, 0
  %53 = zext i1 %52 to i64
  %54 = select i1 %52, i32 1, i32 0
  %55 = trunc i32 %54 to i8
  store i8 %55, i8* %34, align 1
  %56 = bitcast [7 x i32]* %35 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %56, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reduce_argmax.positions_src0 to i8*), i64 28, i1 false)
  %57 = getelementptr inbounds [7 x i32], [7 x i32]* %36, i64 0, i64 0
  %58 = load i32, i32* %13, align 4
  %59 = sub nsw i32 %58, 1
  store i32 %59, i32* %57, align 4
  %60 = getelementptr inbounds i32, i32* %57, i64 1
  %61 = load i32, i32* %15, align 4
  %62 = sub nsw i32 %61, 1
  store i32 %62, i32* %60, align 4
  %63 = getelementptr inbounds i32, i32* %60, i64 1
  %64 = load i32, i32* %14, align 4
  %65 = sub nsw i32 %64, 1
  store i32 %65, i32* %63, align 4
  %66 = getelementptr inbounds i32, i32* %63, i64 1
  %67 = load i32, i32* %16, align 4
  store i32 %67, i32* %66, align 4
  %68 = getelementptr inbounds i32, i32* %66, i64 1
  %69 = load i32, i32* %17, align 4
  store i32 %69, i32* %68, align 4
  %70 = getelementptr inbounds i32, i32* %68, i64 1
  %71 = load i32, i32* %13, align 4
  %72 = sub nsw i32 %71, 1
  store i32 %72, i32* %70, align 4
  %73 = getelementptr inbounds i32, i32* %70, i64 1
  %74 = load i32, i32* %14, align 4
  %75 = sub nsw i32 %74, 1
  store i32 %75, i32* %73, align 4
  %76 = getelementptr inbounds [7 x i32], [7 x i32]* %35, i64 0, i64 0
  %77 = getelementptr inbounds [7 x i32], [7 x i32]* %36, i64 0, i64 0
  %78 = call { i64, i64 } @setUpdateData(i32* noundef %76, i32* noundef %77, i32 noundef 7)
  %79 = bitcast i128* %38 to { i64, i64 }*
  %80 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %79, i32 0, i32 0
  %81 = extractvalue { i64, i64 } %78, 0
  store i64 %81, i64* %80, align 16
  %82 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %79, i32 0, i32 1
  %83 = extractvalue { i64, i64 } %78, 1
  store i64 %83, i64* %82, align 8
  %84 = load i128, i128* %38, align 16
  store i128 %84, i128* %37, align 16
  %85 = bitcast [7 x i32]* %39 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %85, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reduce_argmax.positions_dst0 to i8*), i64 28, i1 false)
  %86 = bitcast [7 x i32]* %40 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %86, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reduce_argmax.values_dst0 to i8*), i64 28, i1 false)
  %87 = getelementptr inbounds [7 x i32], [7 x i32]* %39, i64 0, i64 0
  %88 = getelementptr inbounds [7 x i32], [7 x i32]* %40, i64 0, i64 0
  %89 = call { i64, i64 } @setUpdateData(i32* noundef %87, i32* noundef %88, i32 noundef 7)
  %90 = bitcast i128* %42 to { i64, i64 }*
  %91 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %90, i32 0, i32 0
  %92 = extractvalue { i64, i64 } %89, 0
  store i64 %92, i64* %91, align 16
  %93 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %90, i32 0, i32 1
  %94 = extractvalue { i64, i64 } %89, 1
  store i64 %94, i64* %93, align 8
  %95 = load i128, i128* %42, align 16
  store i128 %95, i128* %41, align 16
  %96 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %10, align 8
  %97 = load i16, i16* %27, align 2
  %98 = load i8, i8* %29, align 1
  %99 = zext i8 %98 to i32
  %100 = load i128, i128* %37, align 16
  %101 = load i8, i8* %24, align 1
  %102 = load i8, i8* %25, align 1
  %103 = load i8, i8* %26, align 1
  store i128 %100, i128* %43, align 16
  %104 = bitcast i128* %43 to { i64, i64 }*
  %105 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %104, i32 0, i32 0
  %106 = load i64, i64* %105, align 16
  %107 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %104, i32 0, i32 1
  %108 = load i64, i64* %107, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %96, i16 noundef zeroext %97, i32 noundef %99, i64 noundef %106, i64 noundef %108, i8 noundef zeroext %101, i8 noundef zeroext %102, i8 noundef zeroext %103, i8 noundef zeroext 9)
  %109 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %10, align 8
  %110 = load i16, i16* %27, align 2
  %111 = load i8, i8* %32, align 1
  %112 = zext i8 %111 to i32
  %113 = load i128, i128* %41, align 16
  %114 = load i8, i8* %24, align 1
  %115 = load i8, i8* %25, align 1
  %116 = load i8, i8* %26, align 1
  store i128 %113, i128* %44, align 16
  %117 = bitcast i128* %44 to { i64, i64 }*
  %118 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %117, i32 0, i32 0
  %119 = load i64, i64* %118, align 16
  %120 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %117, i32 0, i32 1
  %121 = load i64, i64* %120, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %109, i16 noundef zeroext %110, i32 noundef %112, i64 noundef %119, i64 noundef %121, i8 noundef zeroext %114, i8 noundef zeroext %115, i8 noundef zeroext %116, i8 noundef zeroext 9)
  %122 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %10, align 8
  %123 = load i32, i32* %19, align 4
  %124 = load i32, i32* %20, align 4
  %125 = load i32, i32* %21, align 4
  %126 = load i32, i32* %22, align 4
  %127 = load i32, i32* %23, align 4
  %128 = load i8, i8* %24, align 1
  %129 = load i8, i8* %25, align 1
  %130 = load i8, i8* %26, align 1
  %131 = load i8, i8* %29, align 1
  %132 = load i8, i8* %30, align 1
  %133 = load i8, i8* %31, align 1
  %134 = load i8, i8* %32, align 1
  %135 = load i8, i8* %33, align 1
  %136 = load i8, i8* %34, align 1
  %137 = call i32 @Dre(%struct.DreExecutor_T* noundef %122, i32 noundef %123, i32 noundef %124, i32 noundef %125, i32 noundef %126, i32 noundef %127, i8 noundef zeroext %128, i8 noundef zeroext %129, i8 noundef zeroext %130, i8 noundef zeroext %131, i8 noundef zeroext %132, i8 noundef zeroext %133, i8 noundef zeroext %134, i8 noundef zeroext %135, i8 noundef zeroext %136, i8 noundef zeroext 8)
  ret i32 %137
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_eltw_multi(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, i32 noundef %11, i32 noundef %12, i32 noundef %13, i32 noundef %14, i32 noundef %15, i32 noundef %16, i32 noundef %17, i32 noundef %18, i32 noundef %19, i32 noundef %20, i32 noundef %21, i32 noundef %22, i32 noundef %23, i32 noundef %24, i32 noundef %25, i32 noundef %26, i32 noundef %27, double noundef %28, double noundef %29) #0 {
  %31 = alloca %struct.DreExecutor_T*, align 8
  %32 = alloca double*, align 8
  %33 = alloca double*, align 8
  %34 = alloca double*, align 8
  %35 = alloca i32, align 4
  %36 = alloca i32, align 4
  %37 = alloca i32, align 4
  %38 = alloca i32, align 4
  %39 = alloca i32, align 4
  %40 = alloca i32, align 4
  %41 = alloca i32, align 4
  %42 = alloca i32, align 4
  %43 = alloca i32, align 4
  %44 = alloca i32, align 4
  %45 = alloca i32, align 4
  %46 = alloca i32, align 4
  %47 = alloca i32, align 4
  %48 = alloca i32, align 4
  %49 = alloca i32, align 4
  %50 = alloca i32, align 4
  %51 = alloca i32, align 4
  %52 = alloca i32, align 4
  %53 = alloca i32, align 4
  %54 = alloca i32, align 4
  %55 = alloca i32, align 4
  %56 = alloca i32, align 4
  %57 = alloca i32, align 4
  %58 = alloca i32, align 4
  %59 = alloca double, align 8
  %60 = alloca double, align 8
  %61 = alloca i32, align 4
  %62 = alloca i32, align 4
  %63 = alloca i32, align 4
  %64 = alloca i32, align 4
  %65 = alloca i32, align 4
  %66 = alloca i8, align 1
  %67 = alloca i8, align 1
  %68 = alloca i8, align 1
  %69 = alloca i16, align 2
  %70 = alloca i32, align 4
  %71 = alloca i8, align 1
  %72 = alloca i8, align 1
  %73 = alloca i8, align 1
  %74 = alloca i8, align 1
  %75 = alloca i8, align 1
  %76 = alloca i8, align 1
  %77 = alloca [7 x i32], align 16
  %78 = alloca [7 x i32], align 16
  %79 = alloca i128, align 16
  %80 = alloca i128, align 16
  %81 = alloca [7 x i32], align 16
  %82 = alloca [7 x i32], align 16
  %83 = alloca i128, align 16
  %84 = alloca i128, align 16
  %85 = alloca [7 x i32], align 16
  %86 = alloca [7 x i32], align 16
  %87 = alloca i128, align 16
  %88 = alloca i128, align 16
  %89 = alloca i128, align 16
  %90 = alloca i128, align 16
  %91 = alloca i128, align 16
  store %struct.DreExecutor_T* %0, %struct.DreExecutor_T** %31, align 8
  store double* %1, double** %32, align 8
  store double* %2, double** %33, align 8
  store double* %3, double** %34, align 8
  store i32 %4, i32* %35, align 4
  store i32 %5, i32* %36, align 4
  store i32 %6, i32* %37, align 4
  store i32 %7, i32* %38, align 4
  store i32 %8, i32* %39, align 4
  store i32 %9, i32* %40, align 4
  store i32 %10, i32* %41, align 4
  store i32 %11, i32* %42, align 4
  store i32 %12, i32* %43, align 4
  store i32 %13, i32* %44, align 4
  store i32 %14, i32* %45, align 4
  store i32 %15, i32* %46, align 4
  store i32 %16, i32* %47, align 4
  store i32 %17, i32* %48, align 4
  store i32 %18, i32* %49, align 4
  store i32 %19, i32* %50, align 4
  store i32 %20, i32* %51, align 4
  store i32 %21, i32* %52, align 4
  store i32 %22, i32* %53, align 4
  store i32 %23, i32* %54, align 4
  store i32 %24, i32* %55, align 4
  store i32 %25, i32* %56, align 4
  store i32 %26, i32* %57, align 4
  store i32 %27, i32* %58, align 4
  store double %28, double* %59, align 8
  store double %29, double* %60, align 8
  %92 = load double*, double** %32, align 8
  %93 = ptrtoint double* %92 to i64
  %94 = call i32 @convertToRelativeAddr(i64 noundef %93)
  store i32 %94, i32* %61, align 4
  %95 = load double*, double** %33, align 8
  %96 = ptrtoint double* %95 to i64
  %97 = call i32 @convertToRelativeAddr(i64 noundef %96)
  store i32 %97, i32* %62, align 4
  store i32 0, i32* %63, align 4
  %98 = load double*, double** %34, align 8
  %99 = ptrtoint double* %98 to i64
  %100 = call i32 @convertToRelativeAddr(i64 noundef %99)
  store i32 %100, i32* %64, align 4
  store i32 0, i32* %65, align 4
  store i8 13, i8* %66, align 1
  store i8 2, i8* %67, align 1
  store i8 0, i8* %68, align 1
  store i16 -1, i16* %69, align 2
  store i32 0, i32* %70, align 4
  store i8 0, i8* %71, align 1
  store i8 1, i8* %72, align 1
  store i8 2, i8* %73, align 1
  store i8 3, i8* %74, align 1
  store i8 4, i8* %75, align 1
  store i8 0, i8* %76, align 1
  %101 = bitcast [7 x i32]* %77 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %101, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_eltw_multi.positions_src0 to i8*), i64 28, i1 false)
  %102 = getelementptr inbounds [7 x i32], [7 x i32]* %78, i64 0, i64 0
  %103 = load i32, i32* %35, align 4
  %104 = sub nsw i32 %103, 1
  store i32 %104, i32* %102, align 4
  %105 = getelementptr inbounds i32, i32* %102, i64 1
  store i32 0, i32* %105, align 4
  %106 = getelementptr inbounds i32, i32* %105, i64 1
  %107 = load i32, i32* %36, align 4
  %108 = sub nsw i32 %107, 1
  store i32 %108, i32* %106, align 4
  %109 = getelementptr inbounds i32, i32* %106, i64 1
  %110 = load i32, i32* %38, align 4
  store i32 %110, i32* %109, align 4
  %111 = getelementptr inbounds i32, i32* %109, i64 1
  %112 = load i32, i32* %39, align 4
  store i32 %112, i32* %111, align 4
  %113 = getelementptr inbounds i32, i32* %111, i64 1
  %114 = load i32, i32* %40, align 4
  %115 = sub nsw i32 %114, 1
  store i32 %115, i32* %113, align 4
  %116 = getelementptr inbounds i32, i32* %113, i64 1
  %117 = load i32, i32* %41, align 4
  %118 = sub nsw i32 %117, 1
  store i32 %118, i32* %116, align 4
  %119 = getelementptr inbounds [7 x i32], [7 x i32]* %77, i64 0, i64 0
  %120 = getelementptr inbounds [7 x i32], [7 x i32]* %78, i64 0, i64 0
  %121 = call { i64, i64 } @setUpdateData(i32* noundef %119, i32* noundef %120, i32 noundef 7)
  %122 = bitcast i128* %80 to { i64, i64 }*
  %123 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %122, i32 0, i32 0
  %124 = extractvalue { i64, i64 } %121, 0
  store i64 %124, i64* %123, align 16
  %125 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %122, i32 0, i32 1
  %126 = extractvalue { i64, i64 } %121, 1
  store i64 %126, i64* %125, align 8
  %127 = load i128, i128* %80, align 16
  store i128 %127, i128* %79, align 16
  %128 = bitcast [7 x i32]* %81 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %128, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_eltw_multi.positions_src1 to i8*), i64 28, i1 false)
  %129 = getelementptr inbounds [7 x i32], [7 x i32]* %82, i64 0, i64 0
  %130 = load i32, i32* %42, align 4
  %131 = sub nsw i32 %130, 1
  store i32 %131, i32* %129, align 4
  %132 = getelementptr inbounds i32, i32* %129, i64 1
  store i32 0, i32* %132, align 4
  %133 = getelementptr inbounds i32, i32* %132, i64 1
  %134 = load i32, i32* %43, align 4
  %135 = sub nsw i32 %134, 1
  store i32 %135, i32* %133, align 4
  %136 = getelementptr inbounds i32, i32* %133, i64 1
  %137 = load i32, i32* %45, align 4
  store i32 %137, i32* %136, align 4
  %138 = getelementptr inbounds i32, i32* %136, i64 1
  %139 = load i32, i32* %46, align 4
  store i32 %139, i32* %138, align 4
  %140 = getelementptr inbounds i32, i32* %138, i64 1
  %141 = load i32, i32* %47, align 4
  %142 = sub nsw i32 %141, 1
  store i32 %142, i32* %140, align 4
  %143 = getelementptr inbounds i32, i32* %140, i64 1
  %144 = load i32, i32* %48, align 4
  %145 = sub nsw i32 %144, 1
  store i32 %145, i32* %143, align 4
  %146 = getelementptr inbounds [7 x i32], [7 x i32]* %81, i64 0, i64 0
  %147 = getelementptr inbounds [7 x i32], [7 x i32]* %82, i64 0, i64 0
  %148 = call { i64, i64 } @setUpdateData(i32* noundef %146, i32* noundef %147, i32 noundef 7)
  %149 = bitcast i128* %84 to { i64, i64 }*
  %150 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %149, i32 0, i32 0
  %151 = extractvalue { i64, i64 } %148, 0
  store i64 %151, i64* %150, align 16
  %152 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %149, i32 0, i32 1
  %153 = extractvalue { i64, i64 } %148, 1
  store i64 %153, i64* %152, align 8
  %154 = load i128, i128* %84, align 16
  store i128 %154, i128* %83, align 16
  %155 = bitcast [7 x i32]* %85 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %155, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_eltw_multi.positions_dst0 to i8*), i64 28, i1 false)
  %156 = getelementptr inbounds [7 x i32], [7 x i32]* %86, i64 0, i64 0
  %157 = load i32, i32* %49, align 4
  %158 = sub nsw i32 %157, 1
  store i32 %158, i32* %156, align 4
  %159 = getelementptr inbounds i32, i32* %156, i64 1
  store i32 0, i32* %159, align 4
  %160 = getelementptr inbounds i32, i32* %159, i64 1
  %161 = load i32, i32* %50, align 4
  %162 = sub nsw i32 %161, 1
  store i32 %162, i32* %160, align 4
  %163 = getelementptr inbounds i32, i32* %160, i64 1
  %164 = load i32, i32* %52, align 4
  store i32 %164, i32* %163, align 4
  %165 = getelementptr inbounds i32, i32* %163, i64 1
  %166 = load i32, i32* %53, align 4
  store i32 %166, i32* %165, align 4
  %167 = getelementptr inbounds i32, i32* %165, i64 1
  %168 = load i32, i32* %54, align 4
  %169 = sub nsw i32 %168, 1
  store i32 %169, i32* %167, align 4
  %170 = getelementptr inbounds i32, i32* %167, i64 1
  %171 = load i32, i32* %55, align 4
  %172 = sub nsw i32 %171, 1
  store i32 %172, i32* %170, align 4
  %173 = getelementptr inbounds [7 x i32], [7 x i32]* %85, i64 0, i64 0
  %174 = getelementptr inbounds [7 x i32], [7 x i32]* %86, i64 0, i64 0
  %175 = call { i64, i64 } @setUpdateData(i32* noundef %173, i32* noundef %174, i32 noundef 7)
  %176 = bitcast i128* %88 to { i64, i64 }*
  %177 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %176, i32 0, i32 0
  %178 = extractvalue { i64, i64 } %175, 0
  store i64 %178, i64* %177, align 16
  %179 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %176, i32 0, i32 1
  %180 = extractvalue { i64, i64 } %175, 1
  store i64 %180, i64* %179, align 8
  %181 = load i128, i128* %88, align 16
  store i128 %181, i128* %87, align 16
  %182 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %31, align 8
  %183 = load i16, i16* %69, align 2
  %184 = load i8, i8* %71, align 1
  %185 = zext i8 %184 to i32
  %186 = load i128, i128* %79, align 16
  %187 = load i8, i8* %66, align 1
  %188 = load i8, i8* %67, align 1
  %189 = load i8, i8* %68, align 1
  store i128 %186, i128* %89, align 16
  %190 = bitcast i128* %89 to { i64, i64 }*
  %191 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %190, i32 0, i32 0
  %192 = load i64, i64* %191, align 16
  %193 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %190, i32 0, i32 1
  %194 = load i64, i64* %193, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %182, i16 noundef zeroext %183, i32 noundef %185, i64 noundef %192, i64 noundef %194, i8 noundef zeroext %187, i8 noundef zeroext %188, i8 noundef zeroext %189, i8 noundef zeroext 9)
  %195 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %31, align 8
  %196 = load i16, i16* %69, align 2
  %197 = load i8, i8* %72, align 1
  %198 = zext i8 %197 to i32
  %199 = load i128, i128* %83, align 16
  %200 = load i8, i8* %66, align 1
  %201 = load i8, i8* %67, align 1
  %202 = load i8, i8* %68, align 1
  store i128 %199, i128* %90, align 16
  %203 = bitcast i128* %90 to { i64, i64 }*
  %204 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %203, i32 0, i32 0
  %205 = load i64, i64* %204, align 16
  %206 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %203, i32 0, i32 1
  %207 = load i64, i64* %206, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %195, i16 noundef zeroext %196, i32 noundef %198, i64 noundef %205, i64 noundef %207, i8 noundef zeroext %200, i8 noundef zeroext %201, i8 noundef zeroext %202, i8 noundef zeroext 9)
  %208 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %31, align 8
  %209 = load i16, i16* %69, align 2
  %210 = load i8, i8* %74, align 1
  %211 = zext i8 %210 to i32
  %212 = load i128, i128* %87, align 16
  %213 = load i8, i8* %66, align 1
  %214 = load i8, i8* %67, align 1
  %215 = load i8, i8* %68, align 1
  store i128 %212, i128* %91, align 16
  %216 = bitcast i128* %91 to { i64, i64 }*
  %217 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %216, i32 0, i32 0
  %218 = load i64, i64* %217, align 16
  %219 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %216, i32 0, i32 1
  %220 = load i64, i64* %219, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %208, i16 noundef zeroext %209, i32 noundef %211, i64 noundef %218, i64 noundef %220, i8 noundef zeroext %213, i8 noundef zeroext %214, i8 noundef zeroext %215, i8 noundef zeroext 9)
  %221 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %31, align 8
  %222 = load i32, i32* %61, align 4
  %223 = load i32, i32* %62, align 4
  %224 = load i32, i32* %63, align 4
  %225 = load i32, i32* %64, align 4
  %226 = load i32, i32* %65, align 4
  %227 = load i8, i8* %66, align 1
  %228 = load i8, i8* %67, align 1
  %229 = load i8, i8* %68, align 1
  %230 = load i8, i8* %71, align 1
  %231 = load i8, i8* %72, align 1
  %232 = load i8, i8* %73, align 1
  %233 = load i8, i8* %74, align 1
  %234 = load i8, i8* %75, align 1
  %235 = load i8, i8* %76, align 1
  %236 = call i32 @Dre(%struct.DreExecutor_T* noundef %221, i32 noundef %222, i32 noundef %223, i32 noundef %224, i32 noundef %225, i32 noundef %226, i8 noundef zeroext %227, i8 noundef zeroext %228, i8 noundef zeroext %229, i8 noundef zeroext %230, i8 noundef zeroext %231, i8 noundef zeroext %232, i8 noundef zeroext %233, i8 noundef zeroext %234, i8 noundef zeroext %235, i8 noundef zeroext 8)
  ret i32 %236
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_eltw_sum(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, i32 noundef %11, i32 noundef %12, i32 noundef %13, i32 noundef %14, i32 noundef %15, i32 noundef %16, i32 noundef %17, i32 noundef %18, i32 noundef %19, i32 noundef %20, i32 noundef %21, i32 noundef %22, i32 noundef %23, i32 noundef %24, i32 noundef %25, i32 noundef %26, i32 noundef %27, i32 noundef %28, double noundef %29, double noundef %30) #0 {
  %32 = alloca %struct.DreExecutor_T*, align 8
  %33 = alloca double*, align 8
  %34 = alloca double*, align 8
  %35 = alloca double*, align 8
  %36 = alloca i32, align 4
  %37 = alloca i32, align 4
  %38 = alloca i32, align 4
  %39 = alloca i32, align 4
  %40 = alloca i32, align 4
  %41 = alloca i32, align 4
  %42 = alloca i32, align 4
  %43 = alloca i32, align 4
  %44 = alloca i32, align 4
  %45 = alloca i32, align 4
  %46 = alloca i32, align 4
  %47 = alloca i32, align 4
  %48 = alloca i32, align 4
  %49 = alloca i32, align 4
  %50 = alloca i32, align 4
  %51 = alloca i32, align 4
  %52 = alloca i32, align 4
  %53 = alloca i32, align 4
  %54 = alloca i32, align 4
  %55 = alloca i32, align 4
  %56 = alloca i32, align 4
  %57 = alloca i32, align 4
  %58 = alloca i32, align 4
  %59 = alloca i32, align 4
  %60 = alloca i32, align 4
  %61 = alloca double, align 8
  %62 = alloca double, align 8
  %63 = alloca i32, align 4
  %64 = alloca i32, align 4
  %65 = alloca i32, align 4
  %66 = alloca i32, align 4
  %67 = alloca i32, align 4
  %68 = alloca i8, align 1
  %69 = alloca i8, align 1
  %70 = alloca i8, align 1
  %71 = alloca i16, align 2
  %72 = alloca i32, align 4
  %73 = alloca i8, align 1
  %74 = alloca i8, align 1
  %75 = alloca i8, align 1
  %76 = alloca i8, align 1
  %77 = alloca i8, align 1
  %78 = alloca i8, align 1
  %79 = alloca [7 x i32], align 16
  %80 = alloca [7 x i32], align 16
  %81 = alloca i128, align 16
  %82 = alloca i128, align 16
  %83 = alloca [7 x i32], align 16
  %84 = alloca [7 x i32], align 16
  %85 = alloca i128, align 16
  %86 = alloca i128, align 16
  %87 = alloca [7 x i32], align 16
  %88 = alloca [7 x i32], align 16
  %89 = alloca i128, align 16
  %90 = alloca i128, align 16
  %91 = alloca i128, align 16
  %92 = alloca i128, align 16
  %93 = alloca i128, align 16
  store %struct.DreExecutor_T* %0, %struct.DreExecutor_T** %32, align 8
  store double* %1, double** %33, align 8
  store double* %2, double** %34, align 8
  store double* %3, double** %35, align 8
  store i32 %4, i32* %36, align 4
  store i32 %5, i32* %37, align 4
  store i32 %6, i32* %38, align 4
  store i32 %7, i32* %39, align 4
  store i32 %8, i32* %40, align 4
  store i32 %9, i32* %41, align 4
  store i32 %10, i32* %42, align 4
  store i32 %11, i32* %43, align 4
  store i32 %12, i32* %44, align 4
  store i32 %13, i32* %45, align 4
  store i32 %14, i32* %46, align 4
  store i32 %15, i32* %47, align 4
  store i32 %16, i32* %48, align 4
  store i32 %17, i32* %49, align 4
  store i32 %18, i32* %50, align 4
  store i32 %19, i32* %51, align 4
  store i32 %20, i32* %52, align 4
  store i32 %21, i32* %53, align 4
  store i32 %22, i32* %54, align 4
  store i32 %23, i32* %55, align 4
  store i32 %24, i32* %56, align 4
  store i32 %25, i32* %57, align 4
  store i32 %26, i32* %58, align 4
  store i32 %27, i32* %59, align 4
  store i32 %28, i32* %60, align 4
  store double %29, double* %61, align 8
  store double %30, double* %62, align 8
  %94 = load double*, double** %33, align 8
  %95 = ptrtoint double* %94 to i64
  %96 = call i32 @convertToRelativeAddr(i64 noundef %95)
  store i32 %96, i32* %63, align 4
  %97 = load double*, double** %34, align 8
  %98 = ptrtoint double* %97 to i64
  %99 = call i32 @convertToRelativeAddr(i64 noundef %98)
  store i32 %99, i32* %64, align 4
  store i32 0, i32* %65, align 4
  %100 = load double*, double** %35, align 8
  %101 = ptrtoint double* %100 to i64
  %102 = call i32 @convertToRelativeAddr(i64 noundef %101)
  store i32 %102, i32* %66, align 4
  store i32 0, i32* %67, align 4
  store i8 14, i8* %68, align 1
  store i8 2, i8* %69, align 1
  store i8 0, i8* %70, align 1
  store i16 -1, i16* %71, align 2
  store i32 0, i32* %72, align 4
  store i8 0, i8* %73, align 1
  store i8 1, i8* %74, align 1
  store i8 2, i8* %75, align 1
  store i8 3, i8* %76, align 1
  store i8 4, i8* %77, align 1
  %103 = load i32, i32* %57, align 4
  %104 = icmp ne i32 %103, 0
  %105 = zext i1 %104 to i64
  %106 = select i1 %104, i32 1, i32 0
  %107 = trunc i32 %106 to i8
  store i8 %107, i8* %78, align 1
  %108 = bitcast [7 x i32]* %79 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %108, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_eltw_sum.positions_src0 to i8*), i64 28, i1 false)
  %109 = getelementptr inbounds [7 x i32], [7 x i32]* %80, i64 0, i64 0
  %110 = load i32, i32* %36, align 4
  %111 = sub nsw i32 %110, 1
  store i32 %111, i32* %109, align 4
  %112 = getelementptr inbounds i32, i32* %109, i64 1
  store i32 0, i32* %112, align 4
  %113 = getelementptr inbounds i32, i32* %112, i64 1
  %114 = load i32, i32* %37, align 4
  %115 = sub nsw i32 %114, 1
  store i32 %115, i32* %113, align 4
  %116 = getelementptr inbounds i32, i32* %113, i64 1
  %117 = load i32, i32* %39, align 4
  store i32 %117, i32* %116, align 4
  %118 = getelementptr inbounds i32, i32* %116, i64 1
  %119 = load i32, i32* %40, align 4
  store i32 %119, i32* %118, align 4
  %120 = getelementptr inbounds i32, i32* %118, i64 1
  %121 = load i32, i32* %41, align 4
  %122 = sub nsw i32 %121, 1
  store i32 %122, i32* %120, align 4
  %123 = getelementptr inbounds i32, i32* %120, i64 1
  %124 = load i32, i32* %42, align 4
  %125 = sub nsw i32 %124, 1
  store i32 %125, i32* %123, align 4
  %126 = getelementptr inbounds [7 x i32], [7 x i32]* %79, i64 0, i64 0
  %127 = getelementptr inbounds [7 x i32], [7 x i32]* %80, i64 0, i64 0
  %128 = call { i64, i64 } @setUpdateData(i32* noundef %126, i32* noundef %127, i32 noundef 7)
  %129 = bitcast i128* %82 to { i64, i64 }*
  %130 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %129, i32 0, i32 0
  %131 = extractvalue { i64, i64 } %128, 0
  store i64 %131, i64* %130, align 16
  %132 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %129, i32 0, i32 1
  %133 = extractvalue { i64, i64 } %128, 1
  store i64 %133, i64* %132, align 8
  %134 = load i128, i128* %82, align 16
  store i128 %134, i128* %81, align 16
  %135 = bitcast [7 x i32]* %83 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %135, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_eltw_sum.positions_src1 to i8*), i64 28, i1 false)
  %136 = getelementptr inbounds [7 x i32], [7 x i32]* %84, i64 0, i64 0
  %137 = load i32, i32* %43, align 4
  %138 = sub nsw i32 %137, 1
  store i32 %138, i32* %136, align 4
  %139 = getelementptr inbounds i32, i32* %136, i64 1
  store i32 0, i32* %139, align 4
  %140 = getelementptr inbounds i32, i32* %139, i64 1
  %141 = load i32, i32* %44, align 4
  %142 = sub nsw i32 %141, 1
  store i32 %142, i32* %140, align 4
  %143 = getelementptr inbounds i32, i32* %140, i64 1
  %144 = load i32, i32* %46, align 4
  store i32 %144, i32* %143, align 4
  %145 = getelementptr inbounds i32, i32* %143, i64 1
  %146 = load i32, i32* %47, align 4
  store i32 %146, i32* %145, align 4
  %147 = getelementptr inbounds i32, i32* %145, i64 1
  %148 = load i32, i32* %48, align 4
  %149 = sub nsw i32 %148, 1
  store i32 %149, i32* %147, align 4
  %150 = getelementptr inbounds i32, i32* %147, i64 1
  %151 = load i32, i32* %49, align 4
  %152 = sub nsw i32 %151, 1
  store i32 %152, i32* %150, align 4
  %153 = getelementptr inbounds [7 x i32], [7 x i32]* %83, i64 0, i64 0
  %154 = getelementptr inbounds [7 x i32], [7 x i32]* %84, i64 0, i64 0
  %155 = call { i64, i64 } @setUpdateData(i32* noundef %153, i32* noundef %154, i32 noundef 7)
  %156 = bitcast i128* %86 to { i64, i64 }*
  %157 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %156, i32 0, i32 0
  %158 = extractvalue { i64, i64 } %155, 0
  store i64 %158, i64* %157, align 16
  %159 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %156, i32 0, i32 1
  %160 = extractvalue { i64, i64 } %155, 1
  store i64 %160, i64* %159, align 8
  %161 = load i128, i128* %86, align 16
  store i128 %161, i128* %85, align 16
  %162 = bitcast [7 x i32]* %87 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %162, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_eltw_sum.positions_dst0 to i8*), i64 28, i1 false)
  %163 = getelementptr inbounds [7 x i32], [7 x i32]* %88, i64 0, i64 0
  %164 = load i32, i32* %50, align 4
  %165 = sub nsw i32 %164, 1
  store i32 %165, i32* %163, align 4
  %166 = getelementptr inbounds i32, i32* %163, i64 1
  store i32 0, i32* %166, align 4
  %167 = getelementptr inbounds i32, i32* %166, i64 1
  %168 = load i32, i32* %51, align 4
  %169 = sub nsw i32 %168, 1
  store i32 %169, i32* %167, align 4
  %170 = getelementptr inbounds i32, i32* %167, i64 1
  %171 = load i32, i32* %53, align 4
  store i32 %171, i32* %170, align 4
  %172 = getelementptr inbounds i32, i32* %170, i64 1
  %173 = load i32, i32* %54, align 4
  store i32 %173, i32* %172, align 4
  %174 = getelementptr inbounds i32, i32* %172, i64 1
  %175 = load i32, i32* %55, align 4
  %176 = sub nsw i32 %175, 1
  store i32 %176, i32* %174, align 4
  %177 = getelementptr inbounds i32, i32* %174, i64 1
  %178 = load i32, i32* %56, align 4
  %179 = sub nsw i32 %178, 1
  store i32 %179, i32* %177, align 4
  %180 = getelementptr inbounds [7 x i32], [7 x i32]* %87, i64 0, i64 0
  %181 = getelementptr inbounds [7 x i32], [7 x i32]* %88, i64 0, i64 0
  %182 = call { i64, i64 } @setUpdateData(i32* noundef %180, i32* noundef %181, i32 noundef 7)
  %183 = bitcast i128* %90 to { i64, i64 }*
  %184 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %183, i32 0, i32 0
  %185 = extractvalue { i64, i64 } %182, 0
  store i64 %185, i64* %184, align 16
  %186 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %183, i32 0, i32 1
  %187 = extractvalue { i64, i64 } %182, 1
  store i64 %187, i64* %186, align 8
  %188 = load i128, i128* %90, align 16
  store i128 %188, i128* %89, align 16
  %189 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %32, align 8
  %190 = load i16, i16* %71, align 2
  %191 = load i8, i8* %73, align 1
  %192 = zext i8 %191 to i32
  %193 = load i128, i128* %81, align 16
  %194 = load i8, i8* %68, align 1
  %195 = load i8, i8* %69, align 1
  %196 = load i8, i8* %70, align 1
  store i128 %193, i128* %91, align 16
  %197 = bitcast i128* %91 to { i64, i64 }*
  %198 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %197, i32 0, i32 0
  %199 = load i64, i64* %198, align 16
  %200 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %197, i32 0, i32 1
  %201 = load i64, i64* %200, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %189, i16 noundef zeroext %190, i32 noundef %192, i64 noundef %199, i64 noundef %201, i8 noundef zeroext %194, i8 noundef zeroext %195, i8 noundef zeroext %196, i8 noundef zeroext 9)
  %202 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %32, align 8
  %203 = load i16, i16* %71, align 2
  %204 = load i8, i8* %74, align 1
  %205 = zext i8 %204 to i32
  %206 = load i128, i128* %85, align 16
  %207 = load i8, i8* %68, align 1
  %208 = load i8, i8* %69, align 1
  %209 = load i8, i8* %70, align 1
  store i128 %206, i128* %92, align 16
  %210 = bitcast i128* %92 to { i64, i64 }*
  %211 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %210, i32 0, i32 0
  %212 = load i64, i64* %211, align 16
  %213 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %210, i32 0, i32 1
  %214 = load i64, i64* %213, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %202, i16 noundef zeroext %203, i32 noundef %205, i64 noundef %212, i64 noundef %214, i8 noundef zeroext %207, i8 noundef zeroext %208, i8 noundef zeroext %209, i8 noundef zeroext 9)
  %215 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %32, align 8
  %216 = load i16, i16* %71, align 2
  %217 = load i8, i8* %76, align 1
  %218 = zext i8 %217 to i32
  %219 = load i128, i128* %89, align 16
  %220 = load i8, i8* %68, align 1
  %221 = load i8, i8* %69, align 1
  %222 = load i8, i8* %70, align 1
  store i128 %219, i128* %93, align 16
  %223 = bitcast i128* %93 to { i64, i64 }*
  %224 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %223, i32 0, i32 0
  %225 = load i64, i64* %224, align 16
  %226 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %223, i32 0, i32 1
  %227 = load i64, i64* %226, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %215, i16 noundef zeroext %216, i32 noundef %218, i64 noundef %225, i64 noundef %227, i8 noundef zeroext %220, i8 noundef zeroext %221, i8 noundef zeroext %222, i8 noundef zeroext 9)
  %228 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %32, align 8
  %229 = load i32, i32* %63, align 4
  %230 = load i32, i32* %64, align 4
  %231 = load i32, i32* %65, align 4
  %232 = load i32, i32* %66, align 4
  %233 = load i32, i32* %67, align 4
  %234 = load i8, i8* %68, align 1
  %235 = load i8, i8* %69, align 1
  %236 = load i8, i8* %70, align 1
  %237 = load i8, i8* %73, align 1
  %238 = load i8, i8* %74, align 1
  %239 = load i8, i8* %75, align 1
  %240 = load i8, i8* %76, align 1
  %241 = load i8, i8* %77, align 1
  %242 = load i8, i8* %78, align 1
  %243 = call i32 @Dre(%struct.DreExecutor_T* noundef %228, i32 noundef %229, i32 noundef %230, i32 noundef %231, i32 noundef %232, i32 noundef %233, i8 noundef zeroext %234, i8 noundef zeroext %235, i8 noundef zeroext %236, i8 noundef zeroext %237, i8 noundef zeroext %238, i8 noundef zeroext %239, i8 noundef zeroext %240, i8 noundef zeroext %241, i8 noundef zeroext %242, i8 noundef zeroext 8)
  ret i32 %243
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_Apb(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, double noundef %11, i32 noundef %12) #0 {
  %14 = alloca %struct.DreExecutor_T*, align 8
  %15 = alloca double*, align 8
  %16 = alloca double*, align 8
  %17 = alloca double*, align 8
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca i32, align 4
  %24 = alloca i32, align 4
  %25 = alloca double, align 8
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i32, align 4
  %31 = alloca i32, align 4
  %32 = alloca i8, align 1
  %33 = alloca i8, align 1
  %34 = alloca i8, align 1
  %35 = alloca i16, align 2
  %36 = alloca i32, align 4
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca i8, align 1
  %40 = alloca i8, align 1
  %41 = alloca i8, align 1
  %42 = alloca i8, align 1
  %43 = alloca [7 x i32], align 16
  %44 = alloca [7 x i32], align 16
  %45 = alloca i128, align 16
  %46 = alloca i128, align 16
  %47 = alloca [7 x i32], align 16
  %48 = alloca [7 x i32], align 16
  %49 = alloca i128, align 16
  %50 = alloca i128, align 16
  %51 = alloca [7 x i32], align 16
  %52 = alloca [7 x i32], align 16
  %53 = alloca i128, align 16
  %54 = alloca i128, align 16
  %55 = alloca i128, align 16
  %56 = alloca i128, align 16
  %57 = alloca i128, align 16
  store %struct.DreExecutor_T* %0, %struct.DreExecutor_T** %14, align 8
  store double* %1, double** %15, align 8
  store double* %2, double** %16, align 8
  store double* %3, double** %17, align 8
  store i32 %4, i32* %18, align 4
  store i32 %5, i32* %19, align 4
  store i32 %6, i32* %20, align 4
  store i32 %7, i32* %21, align 4
  store i32 %8, i32* %22, align 4
  store i32 %9, i32* %23, align 4
  store i32 %10, i32* %24, align 4
  store double %11, double* %25, align 8
  store i32 %12, i32* %26, align 4
  %58 = load double, double* %25, align 8
  %59 = load double*, double** %16, align 8
  store double %58, double* %59, align 8
  %60 = load double*, double** %15, align 8
  %61 = ptrtoint double* %60 to i64
  %62 = call i32 @convertToRelativeAddr(i64 noundef %61)
  store i32 %62, i32* %27, align 4
  %63 = load double*, double** %16, align 8
  %64 = ptrtoint double* %63 to i64
  %65 = call i32 @convertToRelativeAddr(i64 noundef %64)
  store i32 %65, i32* %28, align 4
  store i32 0, i32* %29, align 4
  %66 = load double*, double** %17, align 8
  %67 = ptrtoint double* %66 to i64
  %68 = call i32 @convertToRelativeAddr(i64 noundef %67)
  store i32 %68, i32* %30, align 4
  store i32 0, i32* %31, align 4
  store i8 15, i8* %32, align 1
  store i8 2, i8* %33, align 1
  store i8 0, i8* %34, align 1
  store i16 -1, i16* %35, align 2
  store i32 0, i32* %36, align 4
  store i8 0, i8* %37, align 1
  store i8 1, i8* %38, align 1
  store i8 2, i8* %39, align 1
  store i8 3, i8* %40, align 1
  store i8 4, i8* %41, align 1
  %69 = load i32, i32* %26, align 4
  %70 = icmp ne i32 %69, 0
  %71 = zext i1 %70 to i64
  %72 = select i1 %70, i32 1, i32 0
  %73 = trunc i32 %72 to i8
  store i8 %73, i8* %42, align 1
  %74 = bitcast [7 x i32]* %43 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %74, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_Apb.positions_src0 to i8*), i64 28, i1 false)
  %75 = getelementptr inbounds [7 x i32], [7 x i32]* %44, i64 0, i64 0
  %76 = load i32, i32* %18, align 4
  %77 = sub nsw i32 %76, 1
  store i32 %77, i32* %75, align 4
  %78 = getelementptr inbounds i32, i32* %75, i64 1
  store i32 0, i32* %78, align 4
  %79 = getelementptr inbounds i32, i32* %78, i64 1
  %80 = load i32, i32* %19, align 4
  %81 = sub nsw i32 %80, 1
  store i32 %81, i32* %79, align 4
  %82 = getelementptr inbounds i32, i32* %79, i64 1
  %83 = load i32, i32* %21, align 4
  store i32 %83, i32* %82, align 4
  %84 = getelementptr inbounds i32, i32* %82, i64 1
  %85 = load i32, i32* %22, align 4
  store i32 %85, i32* %84, align 4
  %86 = getelementptr inbounds i32, i32* %84, i64 1
  %87 = load i32, i32* %23, align 4
  %88 = sub nsw i32 %87, 1
  store i32 %88, i32* %86, align 4
  %89 = getelementptr inbounds i32, i32* %86, i64 1
  %90 = load i32, i32* %24, align 4
  %91 = sub nsw i32 %90, 1
  store i32 %91, i32* %89, align 4
  %92 = getelementptr inbounds [7 x i32], [7 x i32]* %43, i64 0, i64 0
  %93 = getelementptr inbounds [7 x i32], [7 x i32]* %44, i64 0, i64 0
  %94 = call { i64, i64 } @setUpdateData(i32* noundef %92, i32* noundef %93, i32 noundef 7)
  %95 = bitcast i128* %46 to { i64, i64 }*
  %96 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %95, i32 0, i32 0
  %97 = extractvalue { i64, i64 } %94, 0
  store i64 %97, i64* %96, align 16
  %98 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %95, i32 0, i32 1
  %99 = extractvalue { i64, i64 } %94, 1
  store i64 %99, i64* %98, align 8
  %100 = load i128, i128* %46, align 16
  store i128 %100, i128* %45, align 16
  %101 = bitcast [7 x i32]* %47 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %101, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_Apb.positions_src1 to i8*), i64 28, i1 false)
  %102 = bitcast [7 x i32]* %48 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %102, i8 0, i64 28, i1 false)
  %103 = getelementptr inbounds [7 x i32], [7 x i32]* %43, i64 0, i64 0
  %104 = getelementptr inbounds [7 x i32], [7 x i32]* %44, i64 0, i64 0
  %105 = call { i64, i64 } @setUpdateData(i32* noundef %103, i32* noundef %104, i32 noundef 7)
  %106 = bitcast i128* %50 to { i64, i64 }*
  %107 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %106, i32 0, i32 0
  %108 = extractvalue { i64, i64 } %105, 0
  store i64 %108, i64* %107, align 16
  %109 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %106, i32 0, i32 1
  %110 = extractvalue { i64, i64 } %105, 1
  store i64 %110, i64* %109, align 8
  %111 = load i128, i128* %50, align 16
  store i128 %111, i128* %49, align 16
  %112 = bitcast [7 x i32]* %51 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %112, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_Apb.positions_dst0 to i8*), i64 28, i1 false)
  %113 = getelementptr inbounds [7 x i32], [7 x i32]* %52, i64 0, i64 0
  %114 = load i32, i32* %18, align 4
  %115 = sub nsw i32 %114, 1
  store i32 %115, i32* %113, align 4
  %116 = getelementptr inbounds i32, i32* %113, i64 1
  store i32 0, i32* %116, align 4
  %117 = getelementptr inbounds i32, i32* %116, i64 1
  %118 = load i32, i32* %19, align 4
  %119 = sub nsw i32 %118, 1
  store i32 %119, i32* %117, align 4
  %120 = getelementptr inbounds i32, i32* %117, i64 1
  %121 = load i32, i32* %21, align 4
  store i32 %121, i32* %120, align 4
  %122 = getelementptr inbounds i32, i32* %120, i64 1
  %123 = load i32, i32* %22, align 4
  store i32 %123, i32* %122, align 4
  %124 = getelementptr inbounds i32, i32* %122, i64 1
  %125 = load i32, i32* %23, align 4
  %126 = sub nsw i32 %125, 1
  store i32 %126, i32* %124, align 4
  %127 = getelementptr inbounds i32, i32* %124, i64 1
  %128 = load i32, i32* %24, align 4
  %129 = sub nsw i32 %128, 1
  store i32 %129, i32* %127, align 4
  %130 = getelementptr inbounds [7 x i32], [7 x i32]* %51, i64 0, i64 0
  %131 = getelementptr inbounds [7 x i32], [7 x i32]* %52, i64 0, i64 0
  %132 = call { i64, i64 } @setUpdateData(i32* noundef %130, i32* noundef %131, i32 noundef 7)
  %133 = bitcast i128* %54 to { i64, i64 }*
  %134 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %133, i32 0, i32 0
  %135 = extractvalue { i64, i64 } %132, 0
  store i64 %135, i64* %134, align 16
  %136 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %133, i32 0, i32 1
  %137 = extractvalue { i64, i64 } %132, 1
  store i64 %137, i64* %136, align 8
  %138 = load i128, i128* %54, align 16
  store i128 %138, i128* %53, align 16
  %139 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %14, align 8
  %140 = load i16, i16* %35, align 2
  %141 = load i8, i8* %37, align 1
  %142 = zext i8 %141 to i32
  %143 = load i128, i128* %45, align 16
  %144 = load i8, i8* %32, align 1
  %145 = load i8, i8* %33, align 1
  %146 = load i8, i8* %34, align 1
  store i128 %143, i128* %55, align 16
  %147 = bitcast i128* %55 to { i64, i64 }*
  %148 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 0
  %149 = load i64, i64* %148, align 16
  %150 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 1
  %151 = load i64, i64* %150, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %139, i16 noundef zeroext %140, i32 noundef %142, i64 noundef %149, i64 noundef %151, i8 noundef zeroext %144, i8 noundef zeroext %145, i8 noundef zeroext %146, i8 noundef zeroext 9)
  %152 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %14, align 8
  %153 = load i16, i16* %35, align 2
  %154 = load i8, i8* %38, align 1
  %155 = zext i8 %154 to i32
  %156 = load i128, i128* %49, align 16
  %157 = load i8, i8* %32, align 1
  %158 = load i8, i8* %33, align 1
  %159 = load i8, i8* %34, align 1
  store i128 %156, i128* %56, align 16
  %160 = bitcast i128* %56 to { i64, i64 }*
  %161 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %160, i32 0, i32 0
  %162 = load i64, i64* %161, align 16
  %163 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %160, i32 0, i32 1
  %164 = load i64, i64* %163, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %152, i16 noundef zeroext %153, i32 noundef %155, i64 noundef %162, i64 noundef %164, i8 noundef zeroext %157, i8 noundef zeroext %158, i8 noundef zeroext %159, i8 noundef zeroext 9)
  %165 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %14, align 8
  %166 = load i16, i16* %35, align 2
  %167 = load i8, i8* %40, align 1
  %168 = zext i8 %167 to i32
  %169 = load i128, i128* %53, align 16
  %170 = load i8, i8* %32, align 1
  %171 = load i8, i8* %33, align 1
  %172 = load i8, i8* %34, align 1
  store i128 %169, i128* %57, align 16
  %173 = bitcast i128* %57 to { i64, i64 }*
  %174 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %173, i32 0, i32 0
  %175 = load i64, i64* %174, align 16
  %176 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %173, i32 0, i32 1
  %177 = load i64, i64* %176, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %165, i16 noundef zeroext %166, i32 noundef %168, i64 noundef %175, i64 noundef %177, i8 noundef zeroext %170, i8 noundef zeroext %171, i8 noundef zeroext %172, i8 noundef zeroext 9)
  %178 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %14, align 8
  %179 = load i32, i32* %27, align 4
  %180 = load i32, i32* %28, align 4
  %181 = load i32, i32* %29, align 4
  %182 = load i32, i32* %30, align 4
  %183 = load i32, i32* %31, align 4
  %184 = load i8, i8* %32, align 1
  %185 = load i8, i8* %33, align 1
  %186 = load i8, i8* %34, align 1
  %187 = load i8, i8* %37, align 1
  %188 = load i8, i8* %38, align 1
  %189 = load i8, i8* %39, align 1
  %190 = load i8, i8* %40, align 1
  %191 = load i8, i8* %41, align 1
  %192 = load i8, i8* %42, align 1
  %193 = call i32 @Dre(%struct.DreExecutor_T* noundef %178, i32 noundef %179, i32 noundef %180, i32 noundef %181, i32 noundef %182, i32 noundef %183, i8 noundef zeroext %184, i8 noundef zeroext %185, i8 noundef zeroext %186, i8 noundef zeroext %187, i8 noundef zeroext %188, i8 noundef zeroext %189, i8 noundef zeroext %190, i8 noundef zeroext %191, i8 noundef zeroext %192, i8 noundef zeroext 8)
  ret i32 %193
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_Ab(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, double noundef %11) #0 {
  %13 = alloca %struct.DreExecutor_T*, align 8
  %14 = alloca double*, align 8
  %15 = alloca double*, align 8
  %16 = alloca double*, align 8
  %17 = alloca i32, align 4
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca i32, align 4
  %24 = alloca double, align 8
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i8, align 1
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca i16, align 2
  %34 = alloca i32, align 4
  %35 = alloca i8, align 1
  %36 = alloca i8, align 1
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca i8, align 1
  %40 = alloca i8, align 1
  %41 = alloca [7 x i32], align 16
  %42 = alloca [7 x i32], align 16
  %43 = alloca i128, align 16
  %44 = alloca i128, align 16
  %45 = alloca [7 x i32], align 16
  %46 = alloca [7 x i32], align 16
  %47 = alloca i128, align 16
  %48 = alloca i128, align 16
  %49 = alloca [7 x i32], align 16
  %50 = alloca [7 x i32], align 16
  %51 = alloca i128, align 16
  %52 = alloca i128, align 16
  %53 = alloca i128, align 16
  %54 = alloca i128, align 16
  %55 = alloca i128, align 16
  store %struct.DreExecutor_T* %0, %struct.DreExecutor_T** %13, align 8
  store double* %1, double** %14, align 8
  store double* %2, double** %15, align 8
  store double* %3, double** %16, align 8
  store i32 %4, i32* %17, align 4
  store i32 %5, i32* %18, align 4
  store i32 %6, i32* %19, align 4
  store i32 %7, i32* %20, align 4
  store i32 %8, i32* %21, align 4
  store i32 %9, i32* %22, align 4
  store i32 %10, i32* %23, align 4
  store double %11, double* %24, align 8
  %56 = load double, double* %24, align 8
  %57 = load double*, double** %15, align 8
  store double %56, double* %57, align 8
  %58 = load double*, double** %14, align 8
  %59 = ptrtoint double* %58 to i64
  %60 = call i32 @convertToRelativeAddr(i64 noundef %59)
  store i32 %60, i32* %25, align 4
  %61 = load double*, double** %15, align 8
  %62 = ptrtoint double* %61 to i64
  %63 = call i32 @convertToRelativeAddr(i64 noundef %62)
  store i32 %63, i32* %26, align 4
  store i32 0, i32* %27, align 4
  %64 = load double*, double** %16, align 8
  %65 = ptrtoint double* %64 to i64
  %66 = call i32 @convertToRelativeAddr(i64 noundef %65)
  store i32 %66, i32* %28, align 4
  store i32 0, i32* %29, align 4
  store i8 16, i8* %30, align 1
  store i8 2, i8* %31, align 1
  store i8 0, i8* %32, align 1
  store i16 -1, i16* %33, align 2
  store i32 0, i32* %34, align 4
  store i8 0, i8* %35, align 1
  store i8 1, i8* %36, align 1
  store i8 2, i8* %37, align 1
  store i8 3, i8* %38, align 1
  store i8 4, i8* %39, align 1
  store i8 0, i8* %40, align 1
  %67 = bitcast [7 x i32]* %41 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %67, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_Ab.positions_src0 to i8*), i64 28, i1 false)
  %68 = getelementptr inbounds [7 x i32], [7 x i32]* %42, i64 0, i64 0
  %69 = load i32, i32* %17, align 4
  %70 = sub nsw i32 %69, 1
  store i32 %70, i32* %68, align 4
  %71 = getelementptr inbounds i32, i32* %68, i64 1
  store i32 0, i32* %71, align 4
  %72 = getelementptr inbounds i32, i32* %71, i64 1
  %73 = load i32, i32* %18, align 4
  %74 = sub nsw i32 %73, 1
  store i32 %74, i32* %72, align 4
  %75 = getelementptr inbounds i32, i32* %72, i64 1
  %76 = load i32, i32* %20, align 4
  store i32 %76, i32* %75, align 4
  %77 = getelementptr inbounds i32, i32* %75, i64 1
  %78 = load i32, i32* %21, align 4
  store i32 %78, i32* %77, align 4
  %79 = getelementptr inbounds i32, i32* %77, i64 1
  %80 = load i32, i32* %22, align 4
  %81 = sub nsw i32 %80, 1
  store i32 %81, i32* %79, align 4
  %82 = getelementptr inbounds i32, i32* %79, i64 1
  %83 = load i32, i32* %23, align 4
  %84 = sub nsw i32 %83, 1
  store i32 %84, i32* %82, align 4
  %85 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %86 = getelementptr inbounds [7 x i32], [7 x i32]* %42, i64 0, i64 0
  %87 = call { i64, i64 } @setUpdateData(i32* noundef %85, i32* noundef %86, i32 noundef 7)
  %88 = bitcast i128* %44 to { i64, i64 }*
  %89 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %88, i32 0, i32 0
  %90 = extractvalue { i64, i64 } %87, 0
  store i64 %90, i64* %89, align 16
  %91 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %88, i32 0, i32 1
  %92 = extractvalue { i64, i64 } %87, 1
  store i64 %92, i64* %91, align 8
  %93 = load i128, i128* %44, align 16
  store i128 %93, i128* %43, align 16
  %94 = bitcast [7 x i32]* %45 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %94, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_Ab.positions_src1 to i8*), i64 28, i1 false)
  %95 = bitcast [7 x i32]* %46 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %95, i8 0, i64 28, i1 false)
  %96 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %97 = getelementptr inbounds [7 x i32], [7 x i32]* %42, i64 0, i64 0
  %98 = call { i64, i64 } @setUpdateData(i32* noundef %96, i32* noundef %97, i32 noundef 7)
  %99 = bitcast i128* %48 to { i64, i64 }*
  %100 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %99, i32 0, i32 0
  %101 = extractvalue { i64, i64 } %98, 0
  store i64 %101, i64* %100, align 16
  %102 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %99, i32 0, i32 1
  %103 = extractvalue { i64, i64 } %98, 1
  store i64 %103, i64* %102, align 8
  %104 = load i128, i128* %48, align 16
  store i128 %104, i128* %47, align 16
  %105 = bitcast [7 x i32]* %49 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %105, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_Ab.positions_dst0 to i8*), i64 28, i1 false)
  %106 = getelementptr inbounds [7 x i32], [7 x i32]* %50, i64 0, i64 0
  %107 = load i32, i32* %17, align 4
  %108 = sub nsw i32 %107, 1
  store i32 %108, i32* %106, align 4
  %109 = getelementptr inbounds i32, i32* %106, i64 1
  store i32 0, i32* %109, align 4
  %110 = getelementptr inbounds i32, i32* %109, i64 1
  %111 = load i32, i32* %18, align 4
  %112 = sub nsw i32 %111, 1
  store i32 %112, i32* %110, align 4
  %113 = getelementptr inbounds i32, i32* %110, i64 1
  %114 = load i32, i32* %20, align 4
  store i32 %114, i32* %113, align 4
  %115 = getelementptr inbounds i32, i32* %113, i64 1
  %116 = load i32, i32* %21, align 4
  store i32 %116, i32* %115, align 4
  %117 = getelementptr inbounds i32, i32* %115, i64 1
  %118 = load i32, i32* %22, align 4
  %119 = sub nsw i32 %118, 1
  store i32 %119, i32* %117, align 4
  %120 = getelementptr inbounds i32, i32* %117, i64 1
  %121 = load i32, i32* %23, align 4
  %122 = sub nsw i32 %121, 1
  store i32 %122, i32* %120, align 4
  %123 = getelementptr inbounds [7 x i32], [7 x i32]* %49, i64 0, i64 0
  %124 = getelementptr inbounds [7 x i32], [7 x i32]* %50, i64 0, i64 0
  %125 = call { i64, i64 } @setUpdateData(i32* noundef %123, i32* noundef %124, i32 noundef 7)
  %126 = bitcast i128* %52 to { i64, i64 }*
  %127 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %126, i32 0, i32 0
  %128 = extractvalue { i64, i64 } %125, 0
  store i64 %128, i64* %127, align 16
  %129 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %126, i32 0, i32 1
  %130 = extractvalue { i64, i64 } %125, 1
  store i64 %130, i64* %129, align 8
  %131 = load i128, i128* %52, align 16
  store i128 %131, i128* %51, align 16
  %132 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %13, align 8
  %133 = load i16, i16* %33, align 2
  %134 = load i8, i8* %35, align 1
  %135 = zext i8 %134 to i32
  %136 = load i128, i128* %43, align 16
  %137 = load i8, i8* %30, align 1
  %138 = load i8, i8* %31, align 1
  %139 = load i8, i8* %32, align 1
  store i128 %136, i128* %53, align 16
  %140 = bitcast i128* %53 to { i64, i64 }*
  %141 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %140, i32 0, i32 0
  %142 = load i64, i64* %141, align 16
  %143 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %140, i32 0, i32 1
  %144 = load i64, i64* %143, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %132, i16 noundef zeroext %133, i32 noundef %135, i64 noundef %142, i64 noundef %144, i8 noundef zeroext %137, i8 noundef zeroext %138, i8 noundef zeroext %139, i8 noundef zeroext 9)
  %145 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %13, align 8
  %146 = load i16, i16* %33, align 2
  %147 = load i8, i8* %36, align 1
  %148 = zext i8 %147 to i32
  %149 = load i128, i128* %47, align 16
  %150 = load i8, i8* %30, align 1
  %151 = load i8, i8* %31, align 1
  %152 = load i8, i8* %32, align 1
  store i128 %149, i128* %54, align 16
  %153 = bitcast i128* %54 to { i64, i64 }*
  %154 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %153, i32 0, i32 0
  %155 = load i64, i64* %154, align 16
  %156 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %153, i32 0, i32 1
  %157 = load i64, i64* %156, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %145, i16 noundef zeroext %146, i32 noundef %148, i64 noundef %155, i64 noundef %157, i8 noundef zeroext %150, i8 noundef zeroext %151, i8 noundef zeroext %152, i8 noundef zeroext 9)
  %158 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %13, align 8
  %159 = load i16, i16* %33, align 2
  %160 = load i8, i8* %38, align 1
  %161 = zext i8 %160 to i32
  %162 = load i128, i128* %51, align 16
  %163 = load i8, i8* %30, align 1
  %164 = load i8, i8* %31, align 1
  %165 = load i8, i8* %32, align 1
  store i128 %162, i128* %55, align 16
  %166 = bitcast i128* %55 to { i64, i64 }*
  %167 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %166, i32 0, i32 0
  %168 = load i64, i64* %167, align 16
  %169 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %166, i32 0, i32 1
  %170 = load i64, i64* %169, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %158, i16 noundef zeroext %159, i32 noundef %161, i64 noundef %168, i64 noundef %170, i8 noundef zeroext %163, i8 noundef zeroext %164, i8 noundef zeroext %165, i8 noundef zeroext 9)
  %171 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %13, align 8
  %172 = load i32, i32* %25, align 4
  %173 = load i32, i32* %26, align 4
  %174 = load i32, i32* %27, align 4
  %175 = load i32, i32* %28, align 4
  %176 = load i32, i32* %29, align 4
  %177 = load i8, i8* %30, align 1
  %178 = load i8, i8* %31, align 1
  %179 = load i8, i8* %32, align 1
  %180 = load i8, i8* %35, align 1
  %181 = load i8, i8* %36, align 1
  %182 = load i8, i8* %37, align 1
  %183 = load i8, i8* %38, align 1
  %184 = load i8, i8* %39, align 1
  %185 = load i8, i8* %40, align 1
  %186 = call i32 @Dre(%struct.DreExecutor_T* noundef %171, i32 noundef %172, i32 noundef %173, i32 noundef %174, i32 noundef %175, i32 noundef %176, i8 noundef zeroext %177, i8 noundef zeroext %178, i8 noundef zeroext %179, i8 noundef zeroext %180, i8 noundef zeroext %181, i8 noundef zeroext %182, i8 noundef zeroext %183, i8 noundef zeroext %184, i8 noundef zeroext %185, i8 noundef zeroext 8)
  ret i32 %186
}

; Function Attrs: alwaysinline nounwind uwtable
define dso_local i32 @simd_dre_executor_outer(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, i32 noundef %11) #0 {
  %13 = alloca %struct.DreExecutor_T*, align 8
  %14 = alloca double*, align 8
  %15 = alloca double*, align 8
  %16 = alloca i32, align 4
  %17 = alloca i32, align 4
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca i32, align 4
  %24 = alloca i32, align 4
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i8, align 1
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca i16, align 2
  %34 = alloca i32, align 4
  %35 = alloca i8, align 1
  %36 = alloca i8, align 1
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca i8, align 1
  %40 = alloca i8, align 1
  %41 = alloca [7 x i32], align 16
  %42 = alloca [7 x i32], align 16
  %43 = alloca i128, align 16
  %44 = alloca i128, align 16
  %45 = alloca [7 x i32], align 16
  %46 = alloca [7 x i32], align 16
  %47 = alloca i128, align 16
  %48 = alloca i128, align 16
  %49 = alloca i128, align 16
  %50 = alloca i128, align 16
  store %struct.DreExecutor_T* %0, %struct.DreExecutor_T** %13, align 8
  store double* %1, double** %14, align 8
  store double* %2, double** %15, align 8
  store i32 %3, i32* %16, align 4
  store i32 %4, i32* %17, align 4
  store i32 %5, i32* %18, align 4
  store i32 %6, i32* %19, align 4
  store i32 %7, i32* %20, align 4
  store i32 %8, i32* %21, align 4
  store i32 %9, i32* %22, align 4
  store i32 %10, i32* %23, align 4
  store i32 %11, i32* %24, align 4
  %51 = load double*, double** %14, align 8
  %52 = ptrtoint double* %51 to i64
  %53 = call i32 @convertToRelativeAddr(i64 noundef %52)
  store i32 %53, i32* %25, align 4
  store i32 0, i32* %26, align 4
  store i32 0, i32* %27, align 4
  %54 = load double*, double** %15, align 8
  %55 = ptrtoint double* %54 to i64
  %56 = call i32 @convertToRelativeAddr(i64 noundef %55)
  store i32 %56, i32* %28, align 4
  store i32 0, i32* %29, align 4
  store i8 17, i8* %30, align 1
  store i8 2, i8* %31, align 1
  store i8 0, i8* %32, align 1
  store i16 -1, i16* %33, align 2
  store i32 0, i32* %34, align 4
  store i8 0, i8* %35, align 1
  store i8 1, i8* %36, align 1
  store i8 2, i8* %37, align 1
  store i8 3, i8* %38, align 1
  store i8 4, i8* %39, align 1
  store i8 0, i8* %40, align 1
  %57 = bitcast [7 x i32]* %41 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %57, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_outer.positions_src0 to i8*), i64 28, i1 false)
  %58 = getelementptr inbounds [7 x i32], [7 x i32]* %42, i64 0, i64 0
  %59 = load i32, i32* %16, align 4
  %60 = sub nsw i32 %59, 1
  store i32 %60, i32* %58, align 4
  %61 = getelementptr inbounds i32, i32* %58, i64 1
  store i32 0, i32* %61, align 4
  %62 = getelementptr inbounds i32, i32* %61, i64 1
  %63 = load i32, i32* %17, align 4
  %64 = sub nsw i32 %63, 1
  store i32 %64, i32* %62, align 4
  %65 = getelementptr inbounds i32, i32* %62, i64 1
  %66 = load i32, i32* %19, align 4
  store i32 %66, i32* %65, align 4
  %67 = getelementptr inbounds i32, i32* %65, i64 1
  %68 = load i32, i32* %20, align 4
  store i32 %68, i32* %67, align 4
  %69 = getelementptr inbounds i32, i32* %67, i64 1
  %70 = load i32, i32* %23, align 4
  %71 = sub nsw i32 %70, 1
  store i32 %71, i32* %69, align 4
  %72 = getelementptr inbounds i32, i32* %69, i64 1
  %73 = load i32, i32* %24, align 4
  %74 = sub nsw i32 %73, 1
  store i32 %74, i32* %72, align 4
  %75 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %76 = getelementptr inbounds [7 x i32], [7 x i32]* %42, i64 0, i64 0
  %77 = call { i64, i64 } @setUpdateData(i32* noundef %75, i32* noundef %76, i32 noundef 7)
  %78 = bitcast i128* %44 to { i64, i64 }*
  %79 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %78, i32 0, i32 0
  %80 = extractvalue { i64, i64 } %77, 0
  store i64 %80, i64* %79, align 16
  %81 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %78, i32 0, i32 1
  %82 = extractvalue { i64, i64 } %77, 1
  store i64 %82, i64* %81, align 8
  %83 = load i128, i128* %44, align 16
  store i128 %83, i128* %43, align 16
  %84 = bitcast [7 x i32]* %45 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %84, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_outer.positions_dst0 to i8*), i64 28, i1 false)
  %85 = getelementptr inbounds [7 x i32], [7 x i32]* %46, i64 0, i64 0
  %86 = load i32, i32* %16, align 4
  %87 = sub nsw i32 %86, 1
  store i32 %87, i32* %85, align 4
  %88 = getelementptr inbounds i32, i32* %85, i64 1
  store i32 0, i32* %88, align 4
  %89 = getelementptr inbounds i32, i32* %88, i64 1
  %90 = load i32, i32* %17, align 4
  %91 = sub nsw i32 %90, 1
  store i32 %91, i32* %89, align 4
  %92 = getelementptr inbounds i32, i32* %89, i64 1
  %93 = load i32, i32* %21, align 4
  store i32 %93, i32* %92, align 4
  %94 = getelementptr inbounds i32, i32* %92, i64 1
  %95 = load i32, i32* %22, align 4
  store i32 %95, i32* %94, align 4
  %96 = getelementptr inbounds i32, i32* %94, i64 1
  %97 = load i32, i32* %23, align 4
  %98 = sub nsw i32 %97, 1
  store i32 %98, i32* %96, align 4
  %99 = getelementptr inbounds i32, i32* %96, i64 1
  %100 = load i32, i32* %24, align 4
  %101 = sub nsw i32 %100, 1
  store i32 %101, i32* %99, align 4
  %102 = getelementptr inbounds [7 x i32], [7 x i32]* %45, i64 0, i64 0
  %103 = getelementptr inbounds [7 x i32], [7 x i32]* %46, i64 0, i64 0
  %104 = call { i64, i64 } @setUpdateData(i32* noundef %102, i32* noundef %103, i32 noundef 7)
  %105 = bitcast i128* %48 to { i64, i64 }*
  %106 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %105, i32 0, i32 0
  %107 = extractvalue { i64, i64 } %104, 0
  store i64 %107, i64* %106, align 16
  %108 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %105, i32 0, i32 1
  %109 = extractvalue { i64, i64 } %104, 1
  store i64 %109, i64* %108, align 8
  %110 = load i128, i128* %48, align 16
  store i128 %110, i128* %47, align 16
  %111 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %13, align 8
  %112 = load i16, i16* %33, align 2
  %113 = load i8, i8* %35, align 1
  %114 = zext i8 %113 to i32
  %115 = load i128, i128* %43, align 16
  %116 = load i8, i8* %30, align 1
  %117 = load i8, i8* %31, align 1
  %118 = load i8, i8* %32, align 1
  store i128 %115, i128* %49, align 16
  %119 = bitcast i128* %49 to { i64, i64 }*
  %120 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %119, i32 0, i32 0
  %121 = load i64, i64* %120, align 16
  %122 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %119, i32 0, i32 1
  %123 = load i64, i64* %122, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %111, i16 noundef zeroext %112, i32 noundef %114, i64 noundef %121, i64 noundef %123, i8 noundef zeroext %116, i8 noundef zeroext %117, i8 noundef zeroext %118, i8 noundef zeroext 9)
  %124 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %13, align 8
  %125 = load i16, i16* %33, align 2
  %126 = load i8, i8* %38, align 1
  %127 = zext i8 %126 to i32
  %128 = load i128, i128* %47, align 16
  %129 = load i8, i8* %30, align 1
  %130 = load i8, i8* %31, align 1
  %131 = load i8, i8* %32, align 1
  store i128 %128, i128* %50, align 16
  %132 = bitcast i128* %50 to { i64, i64 }*
  %133 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %132, i32 0, i32 0
  %134 = load i64, i64* %133, align 16
  %135 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %132, i32 0, i32 1
  %136 = load i64, i64* %135, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %124, i16 noundef zeroext %125, i32 noundef %127, i64 noundef %134, i64 noundef %136, i8 noundef zeroext %129, i8 noundef zeroext %130, i8 noundef zeroext %131, i8 noundef zeroext 9)
  %137 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %13, align 8
  %138 = load i32, i32* %25, align 4
  %139 = load i32, i32* %26, align 4
  %140 = load i32, i32* %27, align 4
  %141 = load i32, i32* %28, align 4
  %142 = load i32, i32* %29, align 4
  %143 = load i8, i8* %30, align 1
  %144 = load i8, i8* %31, align 1
  %145 = load i8, i8* %32, align 1
  %146 = load i8, i8* %35, align 1
  %147 = load i8, i8* %36, align 1
  %148 = load i8, i8* %37, align 1
  %149 = load i8, i8* %38, align 1
  %150 = load i8, i8* %39, align 1
  %151 = load i8, i8* %40, align 1
  %152 = call i32 @Dre(%struct.DreExecutor_T* noundef %137, i32 noundef %138, i32 noundef %139, i32 noundef %140, i32 noundef %141, i32 noundef %142, i8 noundef zeroext %143, i8 noundef zeroext %144, i8 noundef zeroext %145, i8 noundef zeroext %146, i8 noundef zeroext %147, i8 noundef zeroext %148, i8 noundef zeroext %149, i8 noundef zeroext %150, i8 noundef zeroext %151, i8 noundef zeroext 8)
  ret i32 %152
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @foo() #4 {
  %1 = alloca %struct.DreExecutor_T*, align 8
  %2 = alloca double*, align 8
  %3 = alloca double*, align 8
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = alloca i32, align 4
  %17 = alloca i32, align 4
  %18 = alloca i32, align 4
  %19 = alloca i32, align 4
  %20 = alloca i32, align 4
  %21 = alloca i32, align 4
  %22 = alloca i32, align 4
  %23 = alloca i32, align 4
  %24 = alloca i32, align 4
  %25 = alloca i8, align 1
  %26 = alloca i8, align 1
  %27 = alloca i8, align 1
  %28 = alloca i16, align 2
  %29 = alloca i32, align 4
  %30 = alloca i8, align 1
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca i8, align 1
  %34 = alloca i8, align 1
  %35 = alloca i8, align 1
  %36 = alloca [7 x i32], align 16
  %37 = alloca [7 x i32], align 16
  %38 = alloca i128, align 16
  %39 = alloca i128, align 16
  %40 = alloca [7 x i32], align 16
  %41 = alloca [7 x i32], align 16
  %42 = alloca i128, align 16
  %43 = alloca i128, align 16
  %44 = alloca i128, align 16
  %45 = alloca i128, align 16
  %46 = alloca %struct.CoreExecutor_T*, align 8
  %47 = alloca double*, align 8
  %48 = alloca double*, align 8
  %49 = alloca double*, align 8
  %50 = alloca i32, align 4
  %51 = alloca i32, align 4
  %52 = alloca i32, align 4
  %53 = alloca i32, align 4
  %54 = alloca i32, align 4
  %55 = alloca i32, align 4
  %56 = alloca double, align 8
  %57 = alloca double, align 8
  %58 = alloca i32, align 4
  %59 = alloca i32, align 4
  %60 = alloca i32, align 4
  %61 = alloca i32, align 4
  %62 = alloca i32, align 4
  %63 = alloca i8, align 1
  %64 = alloca i8, align 1
  %65 = alloca i8, align 1
  %66 = alloca i16, align 2
  %67 = alloca i32, align 4
  %68 = alloca i8, align 1
  %69 = alloca i8, align 1
  %70 = alloca i8, align 1
  %71 = alloca i8, align 1
  %72 = alloca i8, align 1
  %73 = alloca i8, align 1
  %74 = alloca [3 x i32], align 4
  %75 = alloca [3 x i32], align 4
  %76 = alloca i128, align 16
  %77 = alloca i128, align 16
  %78 = alloca [2 x i32], align 4
  %79 = alloca [2 x i32], align 4
  %80 = alloca i128, align 16
  %81 = alloca i128, align 16
  %82 = alloca [2 x i32], align 4
  %83 = alloca [2 x i32], align 4
  %84 = alloca i128, align 16
  %85 = alloca i128, align 16
  %86 = alloca [2 x i32], align 4
  %87 = alloca [2 x i32], align 4
  %88 = alloca i128, align 16
  %89 = alloca i128, align 16
  %90 = alloca i128, align 16
  %91 = alloca i128, align 16
  %92 = alloca i128, align 16
  %93 = alloca i128, align 16
  %94 = alloca i32, align 4
  %95 = alloca i32, align 4
  %96 = alloca double*, align 8
  %97 = alloca double*, align 8
  %98 = alloca double*, align 8
  %99 = alloca i32, align 4
  %100 = alloca i32, align 4
  %101 = alloca i32, align 4
  %102 = alloca %struct.CoreExecutor_T*, align 8
  %103 = alloca %struct.DreExecutor_T*, align 8
  %104 = call %struct.CoreExecutor_T* (...) @simd_gemm_executor_create()
  store %struct.CoreExecutor_T* %104, %struct.CoreExecutor_T** %102, align 8
  %105 = call %struct.DreExecutor_T* (...) @simd_dre_executor_create()
  store %struct.DreExecutor_T* %105, %struct.DreExecutor_T** %103, align 8
  %106 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %102, align 8
  call void @simd_gemm_executor_initialize(%struct.CoreExecutor_T* noundef %106)
  %107 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %103, align 8
  call void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef %107)
  call void @reg2sch_start_set(i8 noundef zeroext 0)
  %108 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %102, align 8
  %109 = load double*, double** %96, align 8
  %110 = load double*, double** %97, align 8
  %111 = load double*, double** %98, align 8
  %112 = load i32, i32* %99, align 4
  %113 = load i32, i32* %100, align 4
  %114 = load i32, i32* %101, align 4
  store %struct.CoreExecutor_T* %108, %struct.CoreExecutor_T** %46, align 8
  store double* %109, double** %47, align 8
  store double* %110, double** %48, align 8
  store double* %111, double** %49, align 8
  store i32 %112, i32* %50, align 4
  store i32 %113, i32* %51, align 4
  store i32 %114, i32* %52, align 4
  store i32 0, i32* %53, align 4
  store i32 0, i32* %54, align 4
  store i32 0, i32* %55, align 4
  store double 1.000000e+00, double* %56, align 8
  store double 1.000000e+00, double* %57, align 8
  %115 = load double*, double** %47, align 8
  %116 = ptrtoint double* %115 to i64
  %117 = call i32 @convertToRelativeAddr(i64 noundef %116) #5
  store i32 %117, i32* %58, align 4
  %118 = load double*, double** %48, align 8
  %119 = ptrtoint double* %118 to i64
  %120 = call i32 @convertToRelativeAddr(i64 noundef %119) #5
  store i32 %120, i32* %59, align 4
  store i32 0, i32* %60, align 4
  %121 = load double*, double** %49, align 8
  %122 = ptrtoint double* %121 to i64
  %123 = call i32 @convertToRelativeAddr(i64 noundef %122) #5
  store i32 %123, i32* %61, align 4
  store i32 0, i32* %62, align 4
  store i8 0, i8* %63, align 1
  store i8 2, i8* %64, align 1
  store i8 0, i8* %65, align 1
  store i16 4369, i16* %66, align 2
  store i32 1, i32* %67, align 4
  store i8 1, i8* %68, align 1
  store i8 2, i8* %69, align 1
  store i8 0, i8* %70, align 1
  store i8 3, i8* %71, align 1
  store i8 4, i8* %72, align 1
  store i8 0, i8* %73, align 1
  %124 = bitcast [3 x i32]* %74 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %124, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false) #5
  %125 = getelementptr inbounds [3 x i32], [3 x i32]* %75, i64 0, i64 0
  %126 = load i32, i32* %51, align 4
  store i32 %126, i32* %125, align 4
  %127 = getelementptr inbounds i32, i32* %125, i64 1
  %128 = load i32, i32* %50, align 4
  store i32 %128, i32* %127, align 4
  %129 = getelementptr inbounds i32, i32* %127, i64 1
  %130 = load i32, i32* %51, align 4
  %131 = add nsw i32 %130, 16
  %132 = sdiv i32 %131, 16
  %133 = sub nsw i32 %132, 1
  store i32 %133, i32* %129, align 4
  %134 = getelementptr inbounds [3 x i32], [3 x i32]* %74, i64 0, i64 0
  %135 = getelementptr inbounds [3 x i32], [3 x i32]* %75, i64 0, i64 0
  %136 = call { i64, i64 } @setUpdateData(i32* noundef %134, i32* noundef %135, i32 noundef 3) #5
  %137 = bitcast i128* %77 to { i64, i64 }*
  %138 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %137, i32 0, i32 0
  %139 = extractvalue { i64, i64 } %136, 0
  store i64 %139, i64* %138, align 16
  %140 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %137, i32 0, i32 1
  %141 = extractvalue { i64, i64 } %136, 1
  store i64 %141, i64* %140, align 8
  %142 = load i128, i128* %77, align 16
  store i128 %142, i128* %76, align 16
  %143 = bitcast [2 x i32]* %78 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %143, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false) #5
  %144 = getelementptr inbounds [2 x i32], [2 x i32]* %79, i64 0, i64 0
  %145 = load i32, i32* %51, align 4
  store i32 %145, i32* %144, align 4
  %146 = getelementptr inbounds i32, i32* %144, i64 1
  %147 = load i32, i32* %52, align 4
  store i32 %147, i32* %146, align 4
  %148 = getelementptr inbounds [2 x i32], [2 x i32]* %78, i64 0, i64 0
  %149 = getelementptr inbounds [2 x i32], [2 x i32]* %79, i64 0, i64 0
  %150 = call { i64, i64 } @setUpdateData(i32* noundef %148, i32* noundef %149, i32 noundef 2) #5
  %151 = bitcast i128* %81 to { i64, i64 }*
  %152 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %151, i32 0, i32 0
  %153 = extractvalue { i64, i64 } %150, 0
  store i64 %153, i64* %152, align 16
  %154 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %151, i32 0, i32 1
  %155 = extractvalue { i64, i64 } %150, 1
  store i64 %155, i64* %154, align 8
  %156 = load i128, i128* %81, align 16
  store i128 %156, i128* %80, align 16
  %157 = bitcast [2 x i32]* %82 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %157, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false) #5
  %158 = getelementptr inbounds [2 x i32], [2 x i32]* %83, i64 0, i64 0
  %159 = load i32, i32* %50, align 4
  store i32 %159, i32* %158, align 4
  %160 = getelementptr inbounds i32, i32* %158, i64 1
  %161 = load i32, i32* %52, align 4
  store i32 %161, i32* %160, align 4
  %162 = getelementptr inbounds [2 x i32], [2 x i32]* %82, i64 0, i64 0
  %163 = getelementptr inbounds [2 x i32], [2 x i32]* %83, i64 0, i64 0
  %164 = call { i64, i64 } @setUpdateData(i32* noundef %162, i32* noundef %163, i32 noundef 2) #5
  %165 = bitcast i128* %85 to { i64, i64 }*
  %166 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %165, i32 0, i32 0
  %167 = extractvalue { i64, i64 } %164, 0
  store i64 %167, i64* %166, align 16
  %168 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %165, i32 0, i32 1
  %169 = extractvalue { i64, i64 } %164, 1
  store i64 %169, i64* %168, align 8
  %170 = load i128, i128* %85, align 16
  store i128 %170, i128* %84, align 16
  %171 = bitcast [2 x i32]* %86 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %171, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false) #5
  %172 = getelementptr inbounds [2 x i32], [2 x i32]* %87, i64 0, i64 0
  %173 = load i32, i32* %51, align 4
  %174 = load i32, i32* %50, align 4
  %175 = mul nsw i32 %173, %174
  %176 = sdiv i32 %175, 128
  store i32 %176, i32* %172, align 4
  %177 = getelementptr inbounds i32, i32* %172, i64 1
  %178 = load i32, i32* %51, align 4
  %179 = load i32, i32* %52, align 4
  %180 = mul nsw i32 %178, %179
  %181 = sdiv i32 %180, 128
  store i32 %181, i32* %177, align 4
  %182 = getelementptr inbounds [2 x i32], [2 x i32]* %86, i64 0, i64 0
  %183 = getelementptr inbounds [2 x i32], [2 x i32]* %87, i64 0, i64 0
  %184 = call { i64, i64 } @setUpdateData(i32* noundef %182, i32* noundef %183, i32 noundef 2) #5
  %185 = bitcast i128* %89 to { i64, i64 }*
  %186 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %185, i32 0, i32 0
  %187 = extractvalue { i64, i64 } %184, 0
  store i64 %187, i64* %186, align 16
  %188 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %185, i32 0, i32 1
  %189 = extractvalue { i64, i64 } %184, 1
  store i64 %189, i64* %188, align 8
  %190 = load i128, i128* %89, align 16
  store i128 %190, i128* %88, align 16
  %191 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %192 = load i16, i16* %66, align 2
  %193 = load i32, i32* %67, align 4
  %194 = load i128, i128* %76, align 16
  %195 = load i8, i8* %63, align 1
  %196 = load i8, i8* %64, align 1
  %197 = load i8, i8* %65, align 1
  store i128 %194, i128* %90, align 16
  %198 = bitcast i128* %90 to { i64, i64 }*
  %199 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %198, i32 0, i32 0
  %200 = load i64, i64* %199, align 16
  %201 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %198, i32 0, i32 1
  %202 = load i64, i64* %201, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %191, i16 noundef zeroext %192, i32 noundef %193, i64 noundef %200, i64 noundef %202, i8 noundef zeroext %195, i8 noundef zeroext %196, i8 noundef zeroext %197, i8 noundef zeroext 5) #5
  %203 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %204 = load i16, i16* %66, align 2
  %205 = load i32, i32* %67, align 4
  %206 = add i32 %205, 1
  %207 = load i128, i128* %80, align 16
  %208 = load i8, i8* %63, align 1
  %209 = load i8, i8* %64, align 1
  %210 = load i8, i8* %65, align 1
  store i128 %207, i128* %91, align 16
  %211 = bitcast i128* %91 to { i64, i64 }*
  %212 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %211, i32 0, i32 0
  %213 = load i64, i64* %212, align 16
  %214 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %211, i32 0, i32 1
  %215 = load i64, i64* %214, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %203, i16 noundef zeroext %204, i32 noundef %206, i64 noundef %213, i64 noundef %215, i8 noundef zeroext %208, i8 noundef zeroext %209, i8 noundef zeroext %210, i8 noundef zeroext 5) #5
  %216 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %217 = load i16, i16* %66, align 2
  %218 = load i32, i32* %67, align 4
  %219 = add i32 %218, 2
  %220 = load i128, i128* %84, align 16
  %221 = load i8, i8* %63, align 1
  %222 = load i8, i8* %64, align 1
  %223 = load i8, i8* %65, align 1
  store i128 %220, i128* %92, align 16
  %224 = bitcast i128* %92 to { i64, i64 }*
  %225 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %224, i32 0, i32 0
  %226 = load i64, i64* %225, align 16
  %227 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %224, i32 0, i32 1
  %228 = load i64, i64* %227, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %216, i16 noundef zeroext %217, i32 noundef %219, i64 noundef %226, i64 noundef %228, i8 noundef zeroext %221, i8 noundef zeroext %222, i8 noundef zeroext %223, i8 noundef zeroext 5) #5
  %229 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %230 = load i16, i16* %66, align 2
  %231 = load i32, i32* %67, align 4
  %232 = add i32 %231, 3
  %233 = load i128, i128* %88, align 16
  %234 = load i8, i8* %63, align 1
  %235 = load i8, i8* %64, align 1
  %236 = load i8, i8* %65, align 1
  store i128 %233, i128* %93, align 16
  %237 = bitcast i128* %93 to { i64, i64 }*
  %238 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %237, i32 0, i32 0
  %239 = load i64, i64* %238, align 16
  %240 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %237, i32 0, i32 1
  %241 = load i64, i64* %240, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %229, i16 noundef zeroext %230, i32 noundef %232, i64 noundef %239, i64 noundef %241, i8 noundef zeroext %234, i8 noundef zeroext %235, i8 noundef zeroext %236, i8 noundef zeroext 5) #5
  %242 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %243 = load i32, i32* %58, align 4
  %244 = load i32, i32* %59, align 4
  %245 = load i32, i32* %60, align 4
  %246 = load i32, i32* %61, align 4
  %247 = load i32, i32* %62, align 4
  %248 = load i8, i8* %63, align 1
  %249 = load i8, i8* %64, align 1
  %250 = load i8, i8* %65, align 1
  %251 = load i8, i8* %68, align 1
  %252 = load i8, i8* %69, align 1
  %253 = load i8, i8* %70, align 1
  %254 = load i8, i8* %71, align 1
  %255 = load i8, i8* %72, align 1
  %256 = load i8, i8* %73, align 1
  %257 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %242, i32 noundef %243, i32 noundef %244, i32 noundef %245, i32 noundef %246, i32 noundef %247, i8 noundef zeroext %248, i8 noundef zeroext %249, i8 noundef zeroext %250, i8 noundef zeroext %251, i8 noundef zeroext %252, i8 noundef zeroext %253, i8 noundef zeroext %254, i8 noundef zeroext %255, i8 noundef zeroext %256, i8 noundef zeroext 4) #5
  store i32 0, i32* %94, align 4
  %258 = load i32, i32* %94, align 4
  %259 = icmp eq i32 %258, 0
  br i1 %259, label %260, label %261

260:                                              ; preds = %0
  call void @simd_major_finish(i8 noundef zeroext 0, i8 noundef zeroext 0) #5
  br label %261

261:                                              ; preds = %0, %260
  call void @reg2sch_start_set(i8 noundef zeroext 0)
  %262 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %103, align 8
  %263 = load double*, double** %96, align 8
  %264 = load double*, double** %97, align 8
  store %struct.DreExecutor_T* %262, %struct.DreExecutor_T** %1, align 8
  store double* %263, double** %2, align 8
  store double* %264, double** %3, align 8
  store i32 0, i32* %4, align 4
  store i32 0, i32* %5, align 4
  store i32 0, i32* %6, align 4
  store i32 0, i32* %7, align 4
  store i32 0, i32* %8, align 4
  store i32 0, i32* %9, align 4
  store i32 0, i32* %10, align 4
  store i32 0, i32* %11, align 4
  store i32 0, i32* %12, align 4
  store i32 0, i32* %13, align 4
  store i32 0, i32* %14, align 4
  store i32 0, i32* %15, align 4
  store i32 0, i32* %16, align 4
  store i32 0, i32* %17, align 4
  store i32 0, i32* %18, align 4
  store i32 0, i32* %19, align 4
  %265 = load double*, double** %2, align 8
  %266 = ptrtoint double* %265 to i64
  %267 = call i32 @convertToRelativeAddr(i64 noundef %266) #5
  store i32 %267, i32* %20, align 4
  store i32 0, i32* %21, align 4
  store i32 0, i32* %22, align 4
  %268 = load double*, double** %3, align 8
  %269 = ptrtoint double* %268 to i64
  %270 = call i32 @convertToRelativeAddr(i64 noundef %269) #5
  store i32 %270, i32* %23, align 4
  store i32 0, i32* %24, align 4
  store i8 0, i8* %25, align 1
  store i8 2, i8* %26, align 1
  store i8 0, i8* %27, align 1
  store i16 -1, i16* %28, align 2
  store i32 0, i32* %29, align 4
  store i8 0, i8* %30, align 1
  store i8 1, i8* %31, align 1
  store i8 2, i8* %32, align 1
  store i8 3, i8* %33, align 1
  store i8 4, i8* %34, align 1
  %271 = load i32, i32* %19, align 4
  %272 = icmp eq i32 %271, 0
  br i1 %272, label %273, label %274

273:                                              ; preds = %261
  br label %285

274:                                              ; preds = %261
  %275 = load i32, i32* %19, align 4
  %276 = icmp eq i32 %275, 1
  br i1 %276, label %277, label %278

277:                                              ; preds = %274
  br label %283

278:                                              ; preds = %274
  %279 = load i32, i32* %19, align 4
  %280 = icmp eq i32 %279, 2
  %281 = zext i1 %280 to i64
  %282 = select i1 %280, i32 6, i32 16
  br label %283

283:                                              ; preds = %278, %277
  %284 = phi i32 [ 5, %277 ], [ %282, %278 ]
  br label %285

285:                                              ; preds = %273, %283
  %286 = phi i32 [ 4, %273 ], [ %284, %283 ]
  %287 = trunc i32 %286 to i8
  store i8 %287, i8* %35, align 1
  %288 = bitcast [7 x i32]* %36 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %288, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false) #5
  %289 = getelementptr inbounds [7 x i32], [7 x i32]* %37, i64 0, i64 0
  %290 = load i32, i32* %4, align 4
  %291 = sub nsw i32 %290, 1
  store i32 %291, i32* %289, align 4
  %292 = getelementptr inbounds i32, i32* %289, i64 1
  %293 = load i32, i32* %6, align 4
  %294 = sub nsw i32 %293, 1
  store i32 %294, i32* %292, align 4
  %295 = getelementptr inbounds i32, i32* %292, i64 1
  %296 = load i32, i32* %5, align 4
  %297 = sub nsw i32 %296, 1
  store i32 %297, i32* %295, align 4
  %298 = getelementptr inbounds i32, i32* %295, i64 1
  store i32 0, i32* %298, align 4
  %299 = getelementptr inbounds i32, i32* %298, i64 1
  store i32 0, i32* %299, align 4
  %300 = getelementptr inbounds i32, i32* %299, i64 1
  %301 = load i32, i32* %4, align 4
  %302 = sub nsw i32 %301, 1
  store i32 %302, i32* %300, align 4
  %303 = getelementptr inbounds i32, i32* %300, i64 1
  %304 = load i32, i32* %5, align 4
  %305 = sub nsw i32 %304, 1
  store i32 %305, i32* %303, align 4
  %306 = getelementptr inbounds [7 x i32], [7 x i32]* %36, i64 0, i64 0
  %307 = getelementptr inbounds [7 x i32], [7 x i32]* %37, i64 0, i64 0
  %308 = call { i64, i64 } @setUpdateData(i32* noundef %306, i32* noundef %307, i32 noundef 7) #5
  %309 = bitcast i128* %39 to { i64, i64 }*
  %310 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %309, i32 0, i32 0
  %311 = extractvalue { i64, i64 } %308, 0
  store i64 %311, i64* %310, align 16
  %312 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %309, i32 0, i32 1
  %313 = extractvalue { i64, i64 } %308, 1
  store i64 %313, i64* %312, align 8
  %314 = load i128, i128* %39, align 16
  store i128 %314, i128* %38, align 16
  %315 = bitcast [7 x i32]* %40 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %315, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false) #5
  %316 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %317 = load i32, i32* %7, align 4
  %318 = sub nsw i32 %317, 1
  store i32 %318, i32* %316, align 4
  %319 = getelementptr inbounds i32, i32* %316, i64 1
  %320 = load i32, i32* %9, align 4
  %321 = sub nsw i32 %320, 1
  store i32 %321, i32* %319, align 4
  %322 = getelementptr inbounds i32, i32* %319, i64 1
  %323 = load i32, i32* %8, align 4
  %324 = sub nsw i32 %323, 1
  store i32 %324, i32* %322, align 4
  %325 = getelementptr inbounds i32, i32* %322, i64 1
  store i32 0, i32* %325, align 4
  %326 = getelementptr inbounds i32, i32* %325, i64 1
  store i32 0, i32* %326, align 4
  %327 = getelementptr inbounds i32, i32* %326, i64 1
  %328 = load i32, i32* %7, align 4
  %329 = sub nsw i32 %328, 1
  store i32 %329, i32* %327, align 4
  %330 = getelementptr inbounds i32, i32* %327, i64 1
  %331 = load i32, i32* %8, align 4
  %332 = sub nsw i32 %331, 1
  store i32 %332, i32* %330, align 4
  %333 = getelementptr inbounds [7 x i32], [7 x i32]* %40, i64 0, i64 0
  %334 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %335 = call { i64, i64 } @setUpdateData(i32* noundef %333, i32* noundef %334, i32 noundef 7) #5
  %336 = bitcast i128* %43 to { i64, i64 }*
  %337 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %336, i32 0, i32 0
  %338 = extractvalue { i64, i64 } %335, 0
  store i64 %338, i64* %337, align 16
  %339 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %336, i32 0, i32 1
  %340 = extractvalue { i64, i64 } %335, 1
  store i64 %340, i64* %339, align 8
  %341 = load i128, i128* %43, align 16
  store i128 %341, i128* %42, align 16
  %342 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %343 = load i16, i16* %28, align 2
  %344 = load i32, i32* %29, align 4
  %345 = load i128, i128* %38, align 16
  %346 = load i8, i8* %25, align 1
  store i128 %345, i128* %44, align 16
  %347 = bitcast i128* %44 to { i64, i64 }*
  %348 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %347, i32 0, i32 0
  %349 = load i64, i64* %348, align 16
  %350 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %347, i32 0, i32 1
  %351 = load i64, i64* %350, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %342, i16 noundef zeroext %343, i32 noundef %344, i64 noundef %349, i64 noundef %351, i8 noundef zeroext %346, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9) #5
  %352 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %353 = load i16, i16* %28, align 2
  %354 = load i32, i32* %29, align 4
  %355 = add i32 %354, 3
  %356 = load i128, i128* %42, align 16
  %357 = load i8, i8* %25, align 1
  store i128 %356, i128* %45, align 16
  %358 = bitcast i128* %45 to { i64, i64 }*
  %359 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %358, i32 0, i32 0
  %360 = load i64, i64* %359, align 16
  %361 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %358, i32 0, i32 1
  %362 = load i64, i64* %361, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %352, i16 noundef zeroext %353, i32 noundef %355, i64 noundef %360, i64 noundef %362, i8 noundef zeroext %357, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9) #5
  %363 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %364 = load i32, i32* %20, align 4
  %365 = load i32, i32* %21, align 4
  %366 = load i32, i32* %22, align 4
  %367 = load i32, i32* %23, align 4
  %368 = load i32, i32* %24, align 4
  %369 = load i8, i8* %25, align 1
  %370 = load i8, i8* %26, align 1
  %371 = load i8, i8* %27, align 1
  %372 = load i8, i8* %30, align 1
  %373 = load i8, i8* %31, align 1
  %374 = load i8, i8* %32, align 1
  %375 = load i8, i8* %33, align 1
  %376 = load i8, i8* %34, align 1
  %377 = load i8, i8* %35, align 1
  %378 = call i32 @Dre(%struct.DreExecutor_T* noundef %363, i32 noundef %364, i32 noundef %365, i32 noundef %366, i32 noundef %367, i32 noundef %368, i8 noundef zeroext %369, i8 noundef zeroext %370, i8 noundef zeroext %371, i8 noundef zeroext %372, i8 noundef zeroext %373, i8 noundef zeroext %374, i8 noundef zeroext %375, i8 noundef zeroext %376, i8 noundef zeroext %377, i8 noundef zeroext 8) #5
  store i32 0, i32* %95, align 4
  %379 = load i32, i32* %95, align 4
  %380 = icmp eq i32 %379, 0
  br i1 %380, label %381, label %382

381:                                              ; preds = %285
  call void @simd_major_finish(i8 noundef zeroext 0, i8 noundef zeroext 0) #5
  br label %382

382:                                              ; preds = %285, %381
  %383 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %102, align 8
  call void @simd_gemm_executor_release(%struct.CoreExecutor_T* noundef %383)
  %384 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %103, align 8
  call void @simd_dre_executor_release(%struct.DreExecutor_T* noundef %384)
  %385 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %102, align 8
  call void @simd_gemm_executor_destroy(%struct.CoreExecutor_T* noundef %385)
  %386 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %103, align 8
  call void @simd_dre_executor_destroy(%struct.DreExecutor_T* noundef %386)
  ret void
}

declare %struct.CoreExecutor_T* @simd_gemm_executor_create(...) #1

declare %struct.DreExecutor_T* @simd_dre_executor_create(...) #1

declare void @simd_gemm_executor_initialize(%struct.CoreExecutor_T* noundef) #1

declare void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef) #1

declare void @reg2sch_start_set(i8 noundef zeroext) #1

declare void @simd_gemm_executor_release(%struct.CoreExecutor_T* noundef) #1

declare void @simd_dre_executor_release(%struct.DreExecutor_T* noundef) #1

declare void @simd_gemm_executor_destroy(%struct.CoreExecutor_T* noundef) #1

declare void @simd_dre_executor_destroy(%struct.DreExecutor_T* noundef) #1

attributes #0 = { alwaysinline nounwind uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly nofree nounwind willreturn }
attributes #3 = { argmemonly nofree nounwind willreturn writeonly }
attributes #4 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
