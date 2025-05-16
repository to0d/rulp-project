; ModuleID = '/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC240202A/input.cpp.2.expand.mark_if.ll'
source_filename = "/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC240202A/input.cpp.1.expand.mark_if.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.CoreExecutor_T = type { i32 }
%struct.DreExecutor_T = type { i32 }

@__const.simd_gemm_executor_AB.positions_src0 = private unnamed_addr constant [3 x i32] [i32 0, i32 2, i32 3], align 4
@__const.simd_gemm_executor_AB.positions_src1 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_AB.positions_dst0 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_AB.positions_func = private unnamed_addr constant [2 x i32] [i32 2, i32 3], align 4
@__const.simd_dre_executor_reshape.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_reshape.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16

; Function Attrs: alwaysinline mustprogress uwtable
define dso_local i32 @simd_gemm_executor_AB_wrap(%struct.CoreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, double* noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, double noundef %10, double noundef %11) #0 {
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
  %62 = bitcast double* %61 to i8*
  %63 = ptrtoint i8* %62 to i64
  %64 = call i32 @simd_convert_to_relative_addr(i64 noundef %63)
  store i32 %64, i32* %25, align 4
  %65 = load double*, double** %15, align 8
  %66 = bitcast double* %65 to i8*
  %67 = ptrtoint i8* %66 to i64
  %68 = call i32 @simd_convert_to_relative_addr(i64 noundef %67)
  store i32 %68, i32* %26, align 4
  store i32 0, i32* %27, align 4
  %69 = load double*, double** %16, align 8
  %70 = bitcast double* %69 to i8*
  %71 = ptrtoint i8* %70 to i64
  %72 = call i32 @simd_convert_to_relative_addr(i64 noundef %71)
  store i32 %72, i32* %28, align 4
  store i32 0, i32* %29, align 4
  store i8 0, i8* %30, align 1
  store i8 0, i8* %31, align 1
  store i8 0, i8* %32, align 1
  store i16 4369, i16* %33, align 2
  store i32 1, i32* %34, align 4
  store i8 1, i8* %35, align 1
  store i8 2, i8* %36, align 1
  store i8 0, i8* %37, align 1
  store i8 3, i8* %38, align 1
  store i8 4, i8* %39, align 1
  store i8 0, i8* %40, align 1
  %73 = bitcast [3 x i32]* %41 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %73, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %74 = getelementptr inbounds [3 x i32], [3 x i32]* %42, i64 0, i64 0
  %75 = load i32, i32* %18, align 4
  store i32 %75, i32* %74, align 4
  %76 = getelementptr inbounds i32, i32* %74, i64 1
  %77 = load i32, i32* %17, align 4
  store i32 %77, i32* %76, align 4
  %78 = getelementptr inbounds i32, i32* %76, i64 1
  %79 = load i32, i32* %18, align 4
  %80 = add nsw i32 %79, 16
  %81 = sdiv i32 %80, 16
  %82 = sub nsw i32 %81, 1
  store i32 %82, i32* %78, align 4
  %83 = getelementptr inbounds [3 x i32], [3 x i32]* %41, i64 0, i64 0
  %84 = getelementptr inbounds [3 x i32], [3 x i32]* %42, i64 0, i64 0
  %85 = call { i64, i64 } @simd_set_update_data(i32* noundef %83, i32* noundef %84)
  %86 = bitcast i128* %44 to { i64, i64 }*
  %87 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %86, i32 0, i32 0
  %88 = extractvalue { i64, i64 } %85, 0
  store i64 %88, i64* %87, align 16
  %89 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %86, i32 0, i32 1
  %90 = extractvalue { i64, i64 } %85, 1
  store i64 %90, i64* %89, align 8
  %91 = load i128, i128* %44, align 16
  store i128 %91, i128* %43, align 16
  %92 = bitcast [2 x i32]* %45 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %92, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %93 = getelementptr inbounds [2 x i32], [2 x i32]* %46, i64 0, i64 0
  %94 = load i32, i32* %18, align 4
  store i32 %94, i32* %93, align 4
  %95 = getelementptr inbounds i32, i32* %93, i64 1
  %96 = load i32, i32* %19, align 4
  store i32 %96, i32* %95, align 4
  %97 = getelementptr inbounds [2 x i32], [2 x i32]* %45, i64 0, i64 0
  %98 = getelementptr inbounds [2 x i32], [2 x i32]* %46, i64 0, i64 0
  %99 = call { i64, i64 } @simd_set_update_data(i32* noundef %97, i32* noundef %98)
  %100 = bitcast i128* %48 to { i64, i64 }*
  %101 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %100, i32 0, i32 0
  %102 = extractvalue { i64, i64 } %99, 0
  store i64 %102, i64* %101, align 16
  %103 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %100, i32 0, i32 1
  %104 = extractvalue { i64, i64 } %99, 1
  store i64 %104, i64* %103, align 8
  %105 = load i128, i128* %48, align 16
  store i128 %105, i128* %47, align 16
  %106 = bitcast [2 x i32]* %49 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %106, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %107 = getelementptr inbounds [2 x i32], [2 x i32]* %50, i64 0, i64 0
  %108 = load i32, i32* %17, align 4
  store i32 %108, i32* %107, align 4
  %109 = getelementptr inbounds i32, i32* %107, i64 1
  %110 = load i32, i32* %19, align 4
  store i32 %110, i32* %109, align 4
  %111 = getelementptr inbounds [2 x i32], [2 x i32]* %49, i64 0, i64 0
  %112 = getelementptr inbounds [2 x i32], [2 x i32]* %50, i64 0, i64 0
  %113 = call { i64, i64 } @simd_set_update_data(i32* noundef %111, i32* noundef %112)
  %114 = bitcast i128* %52 to { i64, i64 }*
  %115 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %114, i32 0, i32 0
  %116 = extractvalue { i64, i64 } %113, 0
  store i64 %116, i64* %115, align 16
  %117 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %114, i32 0, i32 1
  %118 = extractvalue { i64, i64 } %113, 1
  store i64 %118, i64* %117, align 8
  %119 = load i128, i128* %52, align 16
  store i128 %119, i128* %51, align 16
  %120 = bitcast [2 x i32]* %53 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %120, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %121 = getelementptr inbounds [2 x i32], [2 x i32]* %54, i64 0, i64 0
  %122 = load i32, i32* %18, align 4
  %123 = load i32, i32* %17, align 4
  %124 = mul nsw i32 %122, %123
  %125 = sdiv i32 %124, 128
  store i32 %125, i32* %121, align 4
  %126 = getelementptr inbounds i32, i32* %121, i64 1
  %127 = load i32, i32* %18, align 4
  %128 = load i32, i32* %19, align 4
  %129 = mul nsw i32 %127, %128
  %130 = sdiv i32 %129, 128
  store i32 %130, i32* %126, align 4
  %131 = getelementptr inbounds [2 x i32], [2 x i32]* %53, i64 0, i64 0
  %132 = getelementptr inbounds [2 x i32], [2 x i32]* %54, i64 0, i64 0
  %133 = call { i64, i64 } @simd_set_update_data(i32* noundef %131, i32* noundef %132)
  %134 = bitcast i128* %56 to { i64, i64 }*
  %135 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %134, i32 0, i32 0
  %136 = extractvalue { i64, i64 } %133, 0
  store i64 %136, i64* %135, align 16
  %137 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %134, i32 0, i32 1
  %138 = extractvalue { i64, i64 } %133, 1
  store i64 %138, i64* %137, align 8
  %139 = load i128, i128* %56, align 16
  store i128 %139, i128* %55, align 16
  %140 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %141 = load i16, i16* %33, align 2
  %142 = load i32, i32* %34, align 4
  %143 = load i128, i128* %43, align 16
  %144 = load i8, i8* %30, align 1
  %145 = load i8, i8* %31, align 1
  %146 = load i8, i8* %32, align 1
  store i128 %143, i128* %57, align 16
  %147 = bitcast i128* %57 to { i64, i64 }*
  %148 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 0
  %149 = load i64, i64* %148, align 16
  %150 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %147, i32 0, i32 1
  %151 = load i64, i64* %150, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %140, i16 noundef zeroext %141, i32 noundef %142, i64 noundef %149, i64 noundef %151, i8 noundef zeroext %144, i8 noundef zeroext %145, i8 noundef zeroext %146, i8 noundef zeroext 5)
  %152 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %153 = load i16, i16* %33, align 2
  %154 = load i32, i32* %34, align 4
  %155 = add i32 %154, 1
  %156 = load i128, i128* %47, align 16
  %157 = load i8, i8* %30, align 1
  %158 = load i8, i8* %31, align 1
  %159 = load i8, i8* %32, align 1
  store i128 %156, i128* %58, align 16
  %160 = bitcast i128* %58 to { i64, i64 }*
  %161 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %160, i32 0, i32 0
  %162 = load i64, i64* %161, align 16
  %163 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %160, i32 0, i32 1
  %164 = load i64, i64* %163, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %152, i16 noundef zeroext %153, i32 noundef %155, i64 noundef %162, i64 noundef %164, i8 noundef zeroext %157, i8 noundef zeroext %158, i8 noundef zeroext %159, i8 noundef zeroext 5)
  %165 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %166 = load i16, i16* %33, align 2
  %167 = load i32, i32* %34, align 4
  %168 = add i32 %167, 2
  %169 = load i128, i128* %51, align 16
  %170 = load i8, i8* %30, align 1
  %171 = load i8, i8* %31, align 1
  %172 = load i8, i8* %32, align 1
  store i128 %169, i128* %59, align 16
  %173 = bitcast i128* %59 to { i64, i64 }*
  %174 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %173, i32 0, i32 0
  %175 = load i64, i64* %174, align 16
  %176 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %173, i32 0, i32 1
  %177 = load i64, i64* %176, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %165, i16 noundef zeroext %166, i32 noundef %168, i64 noundef %175, i64 noundef %177, i8 noundef zeroext %170, i8 noundef zeroext %171, i8 noundef zeroext %172, i8 noundef zeroext 5)
  %178 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %179 = load i16, i16* %33, align 2
  %180 = load i32, i32* %34, align 4
  %181 = add i32 %180, 3
  %182 = load i128, i128* %55, align 16
  %183 = load i8, i8* %30, align 1
  %184 = load i8, i8* %31, align 1
  %185 = load i8, i8* %32, align 1
  store i128 %182, i128* %60, align 16
  %186 = bitcast i128* %60 to { i64, i64 }*
  %187 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %186, i32 0, i32 0
  %188 = load i64, i64* %187, align 16
  %189 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %186, i32 0, i32 1
  %190 = load i64, i64* %189, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %178, i16 noundef zeroext %179, i32 noundef %181, i64 noundef %188, i64 noundef %190, i8 noundef zeroext %183, i8 noundef zeroext %184, i8 noundef zeroext %185, i8 noundef zeroext 5)
  %191 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8
  %192 = load i32, i32* %25, align 4
  %193 = load i32, i32* %26, align 4
  %194 = load i32, i32* %27, align 4
  %195 = load i32, i32* %28, align 4
  %196 = load i32, i32* %29, align 4
  %197 = load i8, i8* %30, align 1
  %198 = load i8, i8* %31, align 1
  %199 = load i8, i8* %32, align 1
  %200 = load i8, i8* %35, align 1
  %201 = load i8, i8* %36, align 1
  %202 = load i8, i8* %37, align 1
  %203 = load i8, i8* %38, align 1
  %204 = load i8, i8* %39, align 1
  %205 = load i8, i8* %40, align 1
  %206 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %191, i32 noundef %192, i32 noundef %193, i32 noundef %194, i32 noundef %195, i32 noundef %196, i8 noundef zeroext %197, i8 noundef zeroext %198, i8 noundef zeroext %199, i8 noundef zeroext %200, i8 noundef zeroext %201, i8 noundef zeroext %202, i8 noundef zeroext %203, i8 noundef zeroext %204, i8 noundef zeroext %205, i8 noundef zeroext 4)
  ret i32 %206
}

declare i32 @simd_convert_to_relative_addr(i64 noundef) #1

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #2

declare { i64, i64 } @simd_set_update_data(i32* noundef, i32* noundef) #1

declare void @simd_gemm_init(%struct.CoreExecutor_T* noundef, i16 noundef zeroext, i32 noundef, i64 noundef, i64 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

declare i32 @Gemm(%struct.CoreExecutor_T* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

; Function Attrs: alwaysinline mustprogress uwtable
define dso_local i32 @simd_dre_executor_reshape_wrap(%struct.DreExecutor_T* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5, i32 noundef %6, i32 noundef %7, i32 noundef %8, i32 noundef %9, i32 noundef %10, i32 noundef %11, i32 noundef %12, i32 noundef %13, i32 noundef %14, i32 noundef %15, i32 noundef %16, i32 noundef %17, i32 noundef %18) #0 {
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
  %67 = call i32 @simd_convert_to_relative_addr(i64 noundef %66)
  store i32 %67, i32* %39, align 4
  store i32 0, i32* %40, align 4
  store i32 0, i32* %41, align 4
  %68 = load double*, double** %22, align 8
  %69 = ptrtoint double* %68 to i64
  %70 = call i32 @simd_convert_to_relative_addr(i64 noundef %69)
  store i32 %70, i32* %42, align 4
  store i32 0, i32* %43, align 4
  store i8 0, i8* %44, align 1
  store i8 0, i8* %45, align 1
  store i8 0, i8* %46, align 1
  store i16 4369, i16* %47, align 2
  store i32 1, i32* %48, align 4
  store i8 1, i8* %49, align 1
  store i8 2, i8* %50, align 1
  store i8 0, i8* %51, align 1
  store i8 3, i8* %52, align 1
  store i8 4, i8* %53, align 1
  store i8 0, i8* %54, align 1
  %71 = bitcast [7 x i32]* %55 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %71, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false)
  %72 = getelementptr inbounds [7 x i32], [7 x i32]* %56, i64 0, i64 0
  %73 = load i32, i32* %23, align 4
  store i32 %73, i32* %72, align 4
  %74 = getelementptr inbounds i32, i32* %72, i64 1
  %75 = load i32, i32* %25, align 4
  store i32 %75, i32* %74, align 4
  %76 = getelementptr inbounds i32, i32* %74, i64 1
  %77 = load i32, i32* %24, align 4
  store i32 %77, i32* %76, align 4
  %78 = getelementptr inbounds i32, i32* %76, i64 1
  store i32 0, i32* %78, align 4
  %79 = getelementptr inbounds i32, i32* %78, i64 1
  store i32 0, i32* %79, align 4
  %80 = getelementptr inbounds i32, i32* %79, i64 1
  %81 = load i32, i32* %23, align 4
  store i32 %81, i32* %80, align 4
  %82 = getelementptr inbounds i32, i32* %80, i64 1
  %83 = load i32, i32* %27, align 4
  store i32 %83, i32* %82, align 4
  %84 = getelementptr inbounds [7 x i32], [7 x i32]* %55, i64 0, i64 0
  %85 = getelementptr inbounds [7 x i32], [7 x i32]* %56, i64 0, i64 0
  %86 = call { i64, i64 } @simd_set_update_data(i32* noundef %84, i32* noundef %85)
  %87 = bitcast i128* %58 to { i64, i64 }*
  %88 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %87, i32 0, i32 0
  %89 = extractvalue { i64, i64 } %86, 0
  store i64 %89, i64* %88, align 16
  %90 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %87, i32 0, i32 1
  %91 = extractvalue { i64, i64 } %86, 1
  store i64 %91, i64* %90, align 8
  %92 = load i128, i128* %58, align 16
  store i128 %92, i128* %57, align 16
  %93 = bitcast [7 x i32]* %59 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %93, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false)
  %94 = getelementptr inbounds [7 x i32], [7 x i32]* %60, i64 0, i64 0
  %95 = load i32, i32* %26, align 4
  store i32 %95, i32* %94, align 4
  %96 = getelementptr inbounds i32, i32* %94, i64 1
  %97 = load i32, i32* %28, align 4
  store i32 %97, i32* %96, align 4
  %98 = getelementptr inbounds i32, i32* %96, i64 1
  %99 = load i32, i32* %27, align 4
  store i32 %99, i32* %98, align 4
  %100 = getelementptr inbounds i32, i32* %98, i64 1
  store i32 0, i32* %100, align 4
  %101 = getelementptr inbounds i32, i32* %100, i64 1
  store i32 0, i32* %101, align 4
  %102 = getelementptr inbounds i32, i32* %101, i64 1
  %103 = load i32, i32* %26, align 4
  store i32 %103, i32* %102, align 4
  %104 = getelementptr inbounds i32, i32* %102, i64 1
  %105 = load i32, i32* %27, align 4
  store i32 %105, i32* %104, align 4
  %106 = getelementptr inbounds [7 x i32], [7 x i32]* %59, i64 0, i64 0
  %107 = getelementptr inbounds [7 x i32], [7 x i32]* %60, i64 0, i64 0
  %108 = call { i64, i64 } @simd_set_update_data(i32* noundef %106, i32* noundef %107)
  %109 = bitcast i128* %62 to { i64, i64 }*
  %110 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %109, i32 0, i32 0
  %111 = extractvalue { i64, i64 } %108, 0
  store i64 %111, i64* %110, align 16
  %112 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %109, i32 0, i32 1
  %113 = extractvalue { i64, i64 } %108, 1
  store i64 %113, i64* %112, align 8
  %114 = load i128, i128* %62, align 16
  store i128 %114, i128* %61, align 16
  %115 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %20, align 8
  %116 = load i16, i16* %47, align 2
  %117 = load i32, i32* %48, align 4
  %118 = load i128, i128* %57, align 16
  %119 = load i8, i8* %44, align 1
  %120 = load i8, i8* %45, align 1
  %121 = load i8, i8* %46, align 1
  store i128 %118, i128* %63, align 16
  %122 = bitcast i128* %63 to { i64, i64 }*
  %123 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %122, i32 0, i32 0
  %124 = load i64, i64* %123, align 16
  %125 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %122, i32 0, i32 1
  %126 = load i64, i64* %125, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %115, i16 noundef zeroext %116, i32 noundef %117, i64 noundef %124, i64 noundef %126, i8 noundef zeroext %119, i8 noundef zeroext %120, i8 noundef zeroext %121, i8 noundef zeroext 5)
  %127 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %20, align 8
  %128 = load i16, i16* %47, align 2
  %129 = load i32, i32* %48, align 4
  %130 = add i32 %129, 2
  %131 = load i128, i128* %61, align 16
  %132 = load i8, i8* %44, align 1
  %133 = load i8, i8* %45, align 1
  %134 = load i8, i8* %46, align 1
  store i128 %131, i128* %64, align 16
  %135 = bitcast i128* %64 to { i64, i64 }*
  %136 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %135, i32 0, i32 0
  %137 = load i64, i64* %136, align 16
  %138 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %135, i32 0, i32 1
  %139 = load i64, i64* %138, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %127, i16 noundef zeroext %128, i32 noundef %130, i64 noundef %137, i64 noundef %139, i8 noundef zeroext %132, i8 noundef zeroext %133, i8 noundef zeroext %134, i8 noundef zeroext 5)
  %140 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %20, align 8
  %141 = load i32, i32* %39, align 4
  %142 = load i32, i32* %40, align 4
  %143 = load i32, i32* %41, align 4
  %144 = load i32, i32* %42, align 4
  %145 = load i32, i32* %43, align 4
  %146 = load i8, i8* %44, align 1
  %147 = load i8, i8* %45, align 1
  %148 = load i8, i8* %46, align 1
  %149 = load i8, i8* %49, align 1
  %150 = load i8, i8* %50, align 1
  %151 = load i8, i8* %51, align 1
  %152 = load i8, i8* %52, align 1
  %153 = load i8, i8* %53, align 1
  %154 = load i8, i8* %54, align 1
  %155 = call i32 @Dre(%struct.DreExecutor_T* noundef %140, i32 noundef %141, i32 noundef %142, i32 noundef %143, i32 noundef %144, i32 noundef %145, i8 noundef zeroext %146, i8 noundef zeroext %147, i8 noundef zeroext %148, i8 noundef zeroext %149, i8 noundef zeroext %150, i8 noundef zeroext %151, i8 noundef zeroext %152, i8 noundef zeroext %153, i8 noundef zeroext %154, i8 noundef zeroext 4)
  ret i32 %155
}

declare void @simd_dre_init(%struct.DreExecutor_T* noundef, i16 noundef zeroext, i32 noundef, i64 noundef, i64 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

declare i32 @Dre(%struct.DreExecutor_T* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #1

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z3fooPdS_S_iii(double* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5) #3 {
  %7 = alloca %struct.DreExecutor_T*, align 8
  %8 = alloca double*, align 8
  %9 = alloca double*, align 8
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
  %25 = alloca i32, align 4
  %26 = alloca i32, align 4
  %27 = alloca i32, align 4
  %28 = alloca i32, align 4
  %29 = alloca i32, align 4
  %30 = alloca i32, align 4
  %31 = alloca i8, align 1
  %32 = alloca i8, align 1
  %33 = alloca i8, align 1
  %34 = alloca i16, align 2
  %35 = alloca i32, align 4
  %36 = alloca i8, align 1
  %37 = alloca i8, align 1
  %38 = alloca i8, align 1
  %39 = alloca i8, align 1
  %40 = alloca i8, align 1
  %41 = alloca i8, align 1
  %42 = alloca [7 x i32], align 16
  %43 = alloca [7 x i32], align 16
  %44 = alloca i128, align 16
  %45 = alloca i128, align 16
  %46 = alloca [7 x i32], align 16
  %47 = alloca [7 x i32], align 16
  %48 = alloca i128, align 16
  %49 = alloca i128, align 16
  %50 = alloca i128, align 16
  %51 = alloca i128, align 16
  %52 = alloca %struct.CoreExecutor_T*, align 8
  %53 = alloca double*, align 8
  %54 = alloca double*, align 8
  %55 = alloca double*, align 8
  %56 = alloca i32, align 4
  %57 = alloca i32, align 4
  %58 = alloca i32, align 4
  %59 = alloca i32, align 4
  %60 = alloca i32, align 4
  %61 = alloca i32, align 4
  %62 = alloca double, align 8
  %63 = alloca double, align 8
  %64 = alloca i32, align 4
  %65 = alloca i32, align 4
  %66 = alloca i32, align 4
  %67 = alloca i32, align 4
  %68 = alloca i32, align 4
  %69 = alloca i8, align 1
  %70 = alloca i8, align 1
  %71 = alloca i8, align 1
  %72 = alloca i16, align 2
  %73 = alloca i32, align 4
  %74 = alloca i8, align 1
  %75 = alloca i8, align 1
  %76 = alloca i8, align 1
  %77 = alloca i8, align 1
  %78 = alloca i8, align 1
  %79 = alloca i8, align 1
  %80 = alloca [3 x i32], align 4
  %81 = alloca [3 x i32], align 4
  %82 = alloca i128, align 16
  %83 = alloca i128, align 16
  %84 = alloca [2 x i32], align 4
  %85 = alloca [2 x i32], align 4
  %86 = alloca i128, align 16
  %87 = alloca i128, align 16
  %88 = alloca [2 x i32], align 4
  %89 = alloca [2 x i32], align 4
  %90 = alloca i128, align 16
  %91 = alloca i128, align 16
  %92 = alloca [2 x i32], align 4
  %93 = alloca [2 x i32], align 4
  %94 = alloca i128, align 16
  %95 = alloca i128, align 16
  %96 = alloca i128, align 16
  %97 = alloca i128, align 16
  %98 = alloca i128, align 16
  %99 = alloca i128, align 16
  %100 = alloca %struct.CoreExecutor_T*, align 8
  %101 = alloca double*, align 8
  %102 = alloca double*, align 8
  %103 = alloca double*, align 8
  %104 = alloca i32, align 4
  %105 = alloca i32, align 4
  %106 = alloca i32, align 4
  %107 = alloca i32, align 4
  %108 = alloca i32, align 4
  %109 = alloca i32, align 4
  %110 = alloca double, align 8
  %111 = alloca double, align 8
  %112 = alloca i32, align 4
  %113 = alloca i32, align 4
  %114 = alloca i32, align 4
  %115 = alloca i32, align 4
  %116 = alloca i32, align 4
  %117 = alloca i8, align 1
  %118 = alloca i8, align 1
  %119 = alloca i8, align 1
  %120 = alloca i16, align 2
  %121 = alloca i32, align 4
  %122 = alloca i8, align 1
  %123 = alloca i8, align 1
  %124 = alloca i8, align 1
  %125 = alloca i8, align 1
  %126 = alloca i8, align 1
  %127 = alloca i8, align 1
  %128 = alloca [3 x i32], align 4
  %129 = alloca [3 x i32], align 4
  %130 = alloca i128, align 16
  %131 = alloca i128, align 16
  %132 = alloca [2 x i32], align 4
  %133 = alloca [2 x i32], align 4
  %134 = alloca i128, align 16
  %135 = alloca i128, align 16
  %136 = alloca [2 x i32], align 4
  %137 = alloca [2 x i32], align 4
  %138 = alloca i128, align 16
  %139 = alloca i128, align 16
  %140 = alloca [2 x i32], align 4
  %141 = alloca [2 x i32], align 4
  %142 = alloca i128, align 16
  %143 = alloca i128, align 16
  %144 = alloca i128, align 16
  %145 = alloca i128, align 16
  %146 = alloca i128, align 16
  %147 = alloca i128, align 16
  %148 = alloca double*, align 8
  %149 = alloca double*, align 8
  %150 = alloca double*, align 8
  %151 = alloca i32, align 4
  %152 = alloca i32, align 4
  %153 = alloca i32, align 4
  %154 = alloca %struct.CoreExecutor_T*, align 8
  %155 = alloca %struct.DreExecutor_T*, align 8
  store double* %0, double** %148, align 8
  store double* %1, double** %149, align 8
  store double* %2, double** %150, align 8
  store i32 %3, i32* %151, align 4
  store i32 %4, i32* %152, align 4
  store i32 %5, i32* %153, align 4
  %156 = call %struct.CoreExecutor_T* @simd_gemm_executor_create()
  store %struct.CoreExecutor_T* %156, %struct.CoreExecutor_T** %154, align 8
  %157 = call %struct.DreExecutor_T* @simd_dre_executor_create()
  store %struct.DreExecutor_T* %157, %struct.DreExecutor_T** %155, align 8
  br label %158

158:                                              ; preds = %6
  call void @reg2sch_start_set(i32 noundef 0)
  %159 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %154, align 8
  %160 = load double*, double** %148, align 8
  %161 = load double*, double** %149, align 8
  %162 = load double*, double** %150, align 8
  %163 = load i32, i32* %151, align 4
  %164 = load i32, i32* %152, align 4
  %165 = load i32, i32* %153, align 4
  store %struct.CoreExecutor_T* %159, %struct.CoreExecutor_T** %52, align 8
  store double* %160, double** %53, align 8
  store double* %161, double** %54, align 8
  store double* %162, double** %55, align 8
  store i32 %163, i32* %56, align 4
  store i32 %164, i32* %57, align 4
  store i32 %165, i32* %58, align 4
  store i32 0, i32* %59, align 4
  store i32 0, i32* %60, align 4
  store i32 0, i32* %61, align 4
  store double 1.000000e+00, double* %62, align 8
  store double 1.000000e+00, double* %63, align 8
  %166 = load double*, double** %53, align 8
  %167 = bitcast double* %166 to i8*
  %168 = ptrtoint i8* %167 to i64
  %169 = call i32 @simd_convert_to_relative_addr(i64 noundef %168)
  store i32 %169, i32* %64, align 4
  %170 = load double*, double** %54, align 8
  %171 = bitcast double* %170 to i8*
  %172 = ptrtoint i8* %171 to i64
  %173 = call i32 @simd_convert_to_relative_addr(i64 noundef %172)
  store i32 %173, i32* %65, align 4
  store i32 0, i32* %66, align 4
  %174 = load double*, double** %55, align 8
  %175 = bitcast double* %174 to i8*
  %176 = ptrtoint i8* %175 to i64
  %177 = call i32 @simd_convert_to_relative_addr(i64 noundef %176)
  store i32 %177, i32* %67, align 4
  store i32 0, i32* %68, align 4
  store i8 0, i8* %69, align 1
  store i8 0, i8* %70, align 1
  store i8 0, i8* %71, align 1
  store i16 4369, i16* %72, align 2
  store i32 1, i32* %73, align 4
  store i8 1, i8* %74, align 1
  store i8 2, i8* %75, align 1
  store i8 0, i8* %76, align 1
  store i8 3, i8* %77, align 1
  store i8 4, i8* %78, align 1
  store i8 0, i8* %79, align 1
  %178 = bitcast [3 x i32]* %80 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %178, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %179 = getelementptr inbounds [3 x i32], [3 x i32]* %81, i64 0, i64 0
  %180 = load i32, i32* %57, align 4
  store i32 %180, i32* %179, align 4
  %181 = getelementptr inbounds i32, i32* %179, i64 1
  %182 = load i32, i32* %56, align 4
  store i32 %182, i32* %181, align 4
  %183 = getelementptr inbounds i32, i32* %181, i64 1
  %184 = load i32, i32* %57, align 4
  %185 = add nsw i32 %184, 16
  %186 = sdiv i32 %185, 16
  %187 = sub nsw i32 %186, 1
  store i32 %187, i32* %183, align 4
  %188 = getelementptr inbounds [3 x i32], [3 x i32]* %80, i64 0, i64 0
  %189 = getelementptr inbounds [3 x i32], [3 x i32]* %81, i64 0, i64 0
  %190 = call { i64, i64 } @simd_set_update_data(i32* noundef %188, i32* noundef %189)
  %191 = bitcast i128* %83 to { i64, i64 }*
  %192 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %191, i32 0, i32 0
  %193 = extractvalue { i64, i64 } %190, 0
  store i64 %193, i64* %192, align 16
  %194 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %191, i32 0, i32 1
  %195 = extractvalue { i64, i64 } %190, 1
  store i64 %195, i64* %194, align 8
  %196 = load i128, i128* %83, align 16
  store i128 %196, i128* %82, align 16
  %197 = bitcast [2 x i32]* %84 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %197, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %198 = getelementptr inbounds [2 x i32], [2 x i32]* %85, i64 0, i64 0
  %199 = load i32, i32* %57, align 4
  store i32 %199, i32* %198, align 4
  %200 = getelementptr inbounds i32, i32* %198, i64 1
  %201 = load i32, i32* %58, align 4
  store i32 %201, i32* %200, align 4
  %202 = getelementptr inbounds [2 x i32], [2 x i32]* %84, i64 0, i64 0
  %203 = getelementptr inbounds [2 x i32], [2 x i32]* %85, i64 0, i64 0
  %204 = call { i64, i64 } @simd_set_update_data(i32* noundef %202, i32* noundef %203)
  %205 = bitcast i128* %87 to { i64, i64 }*
  %206 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %205, i32 0, i32 0
  %207 = extractvalue { i64, i64 } %204, 0
  store i64 %207, i64* %206, align 16
  %208 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %205, i32 0, i32 1
  %209 = extractvalue { i64, i64 } %204, 1
  store i64 %209, i64* %208, align 8
  %210 = load i128, i128* %87, align 16
  store i128 %210, i128* %86, align 16
  %211 = bitcast [2 x i32]* %88 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %211, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %212 = getelementptr inbounds [2 x i32], [2 x i32]* %89, i64 0, i64 0
  %213 = load i32, i32* %56, align 4
  store i32 %213, i32* %212, align 4
  %214 = getelementptr inbounds i32, i32* %212, i64 1
  %215 = load i32, i32* %58, align 4
  store i32 %215, i32* %214, align 4
  %216 = getelementptr inbounds [2 x i32], [2 x i32]* %88, i64 0, i64 0
  %217 = getelementptr inbounds [2 x i32], [2 x i32]* %89, i64 0, i64 0
  %218 = call { i64, i64 } @simd_set_update_data(i32* noundef %216, i32* noundef %217)
  %219 = bitcast i128* %91 to { i64, i64 }*
  %220 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %219, i32 0, i32 0
  %221 = extractvalue { i64, i64 } %218, 0
  store i64 %221, i64* %220, align 16
  %222 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %219, i32 0, i32 1
  %223 = extractvalue { i64, i64 } %218, 1
  store i64 %223, i64* %222, align 8
  %224 = load i128, i128* %91, align 16
  store i128 %224, i128* %90, align 16
  %225 = bitcast [2 x i32]* %92 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %225, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %226 = getelementptr inbounds [2 x i32], [2 x i32]* %93, i64 0, i64 0
  %227 = load i32, i32* %57, align 4
  %228 = load i32, i32* %56, align 4
  %229 = mul nsw i32 %227, %228
  %230 = sdiv i32 %229, 128
  store i32 %230, i32* %226, align 4
  %231 = getelementptr inbounds i32, i32* %226, i64 1
  %232 = load i32, i32* %57, align 4
  %233 = load i32, i32* %58, align 4
  %234 = mul nsw i32 %232, %233
  %235 = sdiv i32 %234, 128
  store i32 %235, i32* %231, align 4
  %236 = getelementptr inbounds [2 x i32], [2 x i32]* %92, i64 0, i64 0
  %237 = getelementptr inbounds [2 x i32], [2 x i32]* %93, i64 0, i64 0
  %238 = call { i64, i64 } @simd_set_update_data(i32* noundef %236, i32* noundef %237)
  %239 = bitcast i128* %95 to { i64, i64 }*
  %240 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %239, i32 0, i32 0
  %241 = extractvalue { i64, i64 } %238, 0
  store i64 %241, i64* %240, align 16
  %242 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %239, i32 0, i32 1
  %243 = extractvalue { i64, i64 } %238, 1
  store i64 %243, i64* %242, align 8
  %244 = load i128, i128* %95, align 16
  store i128 %244, i128* %94, align 16
  %245 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %246 = load i16, i16* %72, align 2
  %247 = load i32, i32* %73, align 4
  %248 = load i128, i128* %82, align 16
  %249 = load i8, i8* %69, align 1
  %250 = load i8, i8* %70, align 1
  %251 = load i8, i8* %71, align 1
  store i128 %248, i128* %96, align 16
  %252 = bitcast i128* %96 to { i64, i64 }*
  %253 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %252, i32 0, i32 0
  %254 = load i64, i64* %253, align 16
  %255 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %252, i32 0, i32 1
  %256 = load i64, i64* %255, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %245, i16 noundef zeroext %246, i32 noundef %247, i64 noundef %254, i64 noundef %256, i8 noundef zeroext %249, i8 noundef zeroext %250, i8 noundef zeroext %251, i8 noundef zeroext 5)
  %257 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %258 = load i16, i16* %72, align 2
  %259 = load i32, i32* %73, align 4
  %260 = add i32 %259, 1
  %261 = load i128, i128* %86, align 16
  %262 = load i8, i8* %69, align 1
  %263 = load i8, i8* %70, align 1
  %264 = load i8, i8* %71, align 1
  store i128 %261, i128* %97, align 16
  %265 = bitcast i128* %97 to { i64, i64 }*
  %266 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %265, i32 0, i32 0
  %267 = load i64, i64* %266, align 16
  %268 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %265, i32 0, i32 1
  %269 = load i64, i64* %268, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %257, i16 noundef zeroext %258, i32 noundef %260, i64 noundef %267, i64 noundef %269, i8 noundef zeroext %262, i8 noundef zeroext %263, i8 noundef zeroext %264, i8 noundef zeroext 5)
  %270 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %271 = load i16, i16* %72, align 2
  %272 = load i32, i32* %73, align 4
  %273 = add i32 %272, 2
  %274 = load i128, i128* %90, align 16
  %275 = load i8, i8* %69, align 1
  %276 = load i8, i8* %70, align 1
  %277 = load i8, i8* %71, align 1
  store i128 %274, i128* %98, align 16
  %278 = bitcast i128* %98 to { i64, i64 }*
  %279 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %278, i32 0, i32 0
  %280 = load i64, i64* %279, align 16
  %281 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %278, i32 0, i32 1
  %282 = load i64, i64* %281, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %270, i16 noundef zeroext %271, i32 noundef %273, i64 noundef %280, i64 noundef %282, i8 noundef zeroext %275, i8 noundef zeroext %276, i8 noundef zeroext %277, i8 noundef zeroext 5)
  %283 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %284 = load i16, i16* %72, align 2
  %285 = load i32, i32* %73, align 4
  %286 = add i32 %285, 3
  %287 = load i128, i128* %94, align 16
  %288 = load i8, i8* %69, align 1
  %289 = load i8, i8* %70, align 1
  %290 = load i8, i8* %71, align 1
  store i128 %287, i128* %99, align 16
  %291 = bitcast i128* %99 to { i64, i64 }*
  %292 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %291, i32 0, i32 0
  %293 = load i64, i64* %292, align 16
  %294 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %291, i32 0, i32 1
  %295 = load i64, i64* %294, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %283, i16 noundef zeroext %284, i32 noundef %286, i64 noundef %293, i64 noundef %295, i8 noundef zeroext %288, i8 noundef zeroext %289, i8 noundef zeroext %290, i8 noundef zeroext 5)
  %296 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %297 = load i32, i32* %64, align 4
  %298 = load i32, i32* %65, align 4
  %299 = load i32, i32* %66, align 4
  %300 = load i32, i32* %67, align 4
  %301 = load i32, i32* %68, align 4
  %302 = load i8, i8* %69, align 1
  %303 = load i8, i8* %70, align 1
  %304 = load i8, i8* %71, align 1
  %305 = load i8, i8* %74, align 1
  %306 = load i8, i8* %75, align 1
  %307 = load i8, i8* %76, align 1
  %308 = load i8, i8* %77, align 1
  %309 = load i8, i8* %78, align 1
  %310 = load i8, i8* %79, align 1
  %311 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %296, i32 noundef %297, i32 noundef %298, i32 noundef %299, i32 noundef %300, i32 noundef %301, i8 noundef zeroext %302, i8 noundef zeroext %303, i8 noundef zeroext %304, i8 noundef zeroext %305, i8 noundef zeroext %306, i8 noundef zeroext %307, i8 noundef zeroext %308, i8 noundef zeroext %309, i8 noundef zeroext %310, i8 noundef zeroext 4)
  %312 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %155, align 8
  %313 = load double*, double** %148, align 8
  %314 = load double*, double** %149, align 8
  store %struct.DreExecutor_T* %312, %struct.DreExecutor_T** %7, align 8
  store double* %313, double** %8, align 8
  store double* %314, double** %9, align 8
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
  store i32 0, i32* %20, align 4
  store i32 0, i32* %21, align 4
  store i32 0, i32* %22, align 4
  store i32 0, i32* %23, align 4
  store i32 0, i32* %24, align 4
  store i32 0, i32* %25, align 4
  %315 = load double*, double** %8, align 8
  %316 = ptrtoint double* %315 to i64
  %317 = call i32 @simd_convert_to_relative_addr(i64 noundef %316)
  store i32 %317, i32* %26, align 4
  store i32 0, i32* %27, align 4
  store i32 0, i32* %28, align 4
  %318 = load double*, double** %9, align 8
  %319 = ptrtoint double* %318 to i64
  %320 = call i32 @simd_convert_to_relative_addr(i64 noundef %319)
  store i32 %320, i32* %29, align 4
  store i32 0, i32* %30, align 4
  store i8 0, i8* %31, align 1
  store i8 0, i8* %32, align 1
  store i8 0, i8* %33, align 1
  store i16 4369, i16* %34, align 2
  store i32 1, i32* %35, align 4
  store i8 1, i8* %36, align 1
  store i8 2, i8* %37, align 1
  store i8 0, i8* %38, align 1
  store i8 3, i8* %39, align 1
  store i8 4, i8* %40, align 1
  store i8 0, i8* %41, align 1
  %321 = bitcast [7 x i32]* %42 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %321, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false)
  %322 = getelementptr inbounds [7 x i32], [7 x i32]* %43, i64 0, i64 0
  %323 = load i32, i32* %10, align 4
  store i32 %323, i32* %322, align 4
  %324 = getelementptr inbounds i32, i32* %322, i64 1
  %325 = load i32, i32* %12, align 4
  store i32 %325, i32* %324, align 4
  %326 = getelementptr inbounds i32, i32* %324, i64 1
  %327 = load i32, i32* %11, align 4
  store i32 %327, i32* %326, align 4
  %328 = getelementptr inbounds i32, i32* %326, i64 1
  store i32 0, i32* %328, align 4
  %329 = getelementptr inbounds i32, i32* %328, i64 1
  store i32 0, i32* %329, align 4
  %330 = getelementptr inbounds i32, i32* %329, i64 1
  %331 = load i32, i32* %10, align 4
  store i32 %331, i32* %330, align 4
  %332 = getelementptr inbounds i32, i32* %330, i64 1
  %333 = load i32, i32* %14, align 4
  store i32 %333, i32* %332, align 4
  %334 = getelementptr inbounds [7 x i32], [7 x i32]* %42, i64 0, i64 0
  %335 = getelementptr inbounds [7 x i32], [7 x i32]* %43, i64 0, i64 0
  %336 = call { i64, i64 } @simd_set_update_data(i32* noundef %334, i32* noundef %335)
  %337 = bitcast i128* %45 to { i64, i64 }*
  %338 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %337, i32 0, i32 0
  %339 = extractvalue { i64, i64 } %336, 0
  store i64 %339, i64* %338, align 16
  %340 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %337, i32 0, i32 1
  %341 = extractvalue { i64, i64 } %336, 1
  store i64 %341, i64* %340, align 8
  %342 = load i128, i128* %45, align 16
  store i128 %342, i128* %44, align 16
  %343 = bitcast [7 x i32]* %46 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %343, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false)
  %344 = getelementptr inbounds [7 x i32], [7 x i32]* %47, i64 0, i64 0
  %345 = load i32, i32* %13, align 4
  store i32 %345, i32* %344, align 4
  %346 = getelementptr inbounds i32, i32* %344, i64 1
  %347 = load i32, i32* %15, align 4
  store i32 %347, i32* %346, align 4
  %348 = getelementptr inbounds i32, i32* %346, i64 1
  %349 = load i32, i32* %14, align 4
  store i32 %349, i32* %348, align 4
  %350 = getelementptr inbounds i32, i32* %348, i64 1
  store i32 0, i32* %350, align 4
  %351 = getelementptr inbounds i32, i32* %350, i64 1
  store i32 0, i32* %351, align 4
  %352 = getelementptr inbounds i32, i32* %351, i64 1
  %353 = load i32, i32* %13, align 4
  store i32 %353, i32* %352, align 4
  %354 = getelementptr inbounds i32, i32* %352, i64 1
  %355 = load i32, i32* %14, align 4
  store i32 %355, i32* %354, align 4
  %356 = getelementptr inbounds [7 x i32], [7 x i32]* %46, i64 0, i64 0
  %357 = getelementptr inbounds [7 x i32], [7 x i32]* %47, i64 0, i64 0
  %358 = call { i64, i64 } @simd_set_update_data(i32* noundef %356, i32* noundef %357)
  %359 = bitcast i128* %49 to { i64, i64 }*
  %360 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %359, i32 0, i32 0
  %361 = extractvalue { i64, i64 } %358, 0
  store i64 %361, i64* %360, align 16
  %362 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %359, i32 0, i32 1
  %363 = extractvalue { i64, i64 } %358, 1
  store i64 %363, i64* %362, align 8
  %364 = load i128, i128* %49, align 16
  store i128 %364, i128* %48, align 16
  %365 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %7, align 8
  %366 = load i16, i16* %34, align 2
  %367 = load i32, i32* %35, align 4
  %368 = load i128, i128* %44, align 16
  %369 = load i8, i8* %31, align 1
  %370 = load i8, i8* %32, align 1
  %371 = load i8, i8* %33, align 1
  store i128 %368, i128* %50, align 16
  %372 = bitcast i128* %50 to { i64, i64 }*
  %373 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %372, i32 0, i32 0
  %374 = load i64, i64* %373, align 16
  %375 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %372, i32 0, i32 1
  %376 = load i64, i64* %375, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %365, i16 noundef zeroext %366, i32 noundef %367, i64 noundef %374, i64 noundef %376, i8 noundef zeroext %369, i8 noundef zeroext %370, i8 noundef zeroext %371, i8 noundef zeroext 5)
  %377 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %7, align 8
  %378 = load i16, i16* %34, align 2
  %379 = load i32, i32* %35, align 4
  %380 = add i32 %379, 2
  %381 = load i128, i128* %48, align 16
  %382 = load i8, i8* %31, align 1
  %383 = load i8, i8* %32, align 1
  %384 = load i8, i8* %33, align 1
  store i128 %381, i128* %51, align 16
  %385 = bitcast i128* %51 to { i64, i64 }*
  %386 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %385, i32 0, i32 0
  %387 = load i64, i64* %386, align 16
  %388 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %385, i32 0, i32 1
  %389 = load i64, i64* %388, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %377, i16 noundef zeroext %378, i32 noundef %380, i64 noundef %387, i64 noundef %389, i8 noundef zeroext %382, i8 noundef zeroext %383, i8 noundef zeroext %384, i8 noundef zeroext 5)
  %390 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %7, align 8
  %391 = load i32, i32* %26, align 4
  %392 = load i32, i32* %27, align 4
  %393 = load i32, i32* %28, align 4
  %394 = load i32, i32* %29, align 4
  %395 = load i32, i32* %30, align 4
  %396 = load i8, i8* %31, align 1
  %397 = load i8, i8* %32, align 1
  %398 = load i8, i8* %33, align 1
  %399 = load i8, i8* %36, align 1
  %400 = load i8, i8* %37, align 1
  %401 = load i8, i8* %38, align 1
  %402 = load i8, i8* %39, align 1
  %403 = load i8, i8* %40, align 1
  %404 = load i8, i8* %41, align 1
  %405 = call i32 @Dre(%struct.DreExecutor_T* noundef %390, i32 noundef %391, i32 noundef %392, i32 noundef %393, i32 noundef %394, i32 noundef %395, i8 noundef zeroext %396, i8 noundef zeroext %397, i8 noundef zeroext %398, i8 noundef zeroext %399, i8 noundef zeroext %400, i8 noundef zeroext %401, i8 noundef zeroext %402, i8 noundef zeroext %403, i8 noundef zeroext %404, i8 noundef zeroext 4)
  %406 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %154, align 8
  %407 = load double*, double** %149, align 8
  %408 = load double*, double** %150, align 8
  %409 = load double*, double** %150, align 8
  %410 = load i32, i32* %151, align 4
  %411 = load i32, i32* %152, align 4
  %412 = load i32, i32* %153, align 4
  store %struct.CoreExecutor_T* %406, %struct.CoreExecutor_T** %100, align 8
  store double* %407, double** %101, align 8
  store double* %408, double** %102, align 8
  store double* %409, double** %103, align 8
  store i32 %410, i32* %104, align 4
  store i32 %411, i32* %105, align 4
  store i32 %412, i32* %106, align 4
  store i32 0, i32* %107, align 4
  store i32 0, i32* %108, align 4
  store i32 0, i32* %109, align 4
  store double 1.000000e+00, double* %110, align 8
  store double 1.000000e+00, double* %111, align 8
  %413 = load double*, double** %101, align 8
  %414 = bitcast double* %413 to i8*
  %415 = ptrtoint i8* %414 to i64
  %416 = call i32 @simd_convert_to_relative_addr(i64 noundef %415)
  store i32 %416, i32* %112, align 4
  %417 = load double*, double** %102, align 8
  %418 = bitcast double* %417 to i8*
  %419 = ptrtoint i8* %418 to i64
  %420 = call i32 @simd_convert_to_relative_addr(i64 noundef %419)
  store i32 %420, i32* %113, align 4
  store i32 0, i32* %114, align 4
  %421 = load double*, double** %103, align 8
  %422 = bitcast double* %421 to i8*
  %423 = ptrtoint i8* %422 to i64
  %424 = call i32 @simd_convert_to_relative_addr(i64 noundef %423)
  store i32 %424, i32* %115, align 4
  store i32 0, i32* %116, align 4
  store i8 0, i8* %117, align 1
  store i8 0, i8* %118, align 1
  store i8 0, i8* %119, align 1
  store i16 4369, i16* %120, align 2
  store i32 1, i32* %121, align 4
  store i8 1, i8* %122, align 1
  store i8 2, i8* %123, align 1
  store i8 0, i8* %124, align 1
  store i8 3, i8* %125, align 1
  store i8 4, i8* %126, align 1
  store i8 0, i8* %127, align 1
  %425 = bitcast [3 x i32]* %128 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %425, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %426 = getelementptr inbounds [3 x i32], [3 x i32]* %129, i64 0, i64 0
  %427 = load i32, i32* %105, align 4
  store i32 %427, i32* %426, align 4
  %428 = getelementptr inbounds i32, i32* %426, i64 1
  %429 = load i32, i32* %104, align 4
  store i32 %429, i32* %428, align 4
  %430 = getelementptr inbounds i32, i32* %428, i64 1
  %431 = load i32, i32* %105, align 4
  %432 = add nsw i32 %431, 16
  %433 = sdiv i32 %432, 16
  %434 = sub nsw i32 %433, 1
  store i32 %434, i32* %430, align 4
  %435 = getelementptr inbounds [3 x i32], [3 x i32]* %128, i64 0, i64 0
  %436 = getelementptr inbounds [3 x i32], [3 x i32]* %129, i64 0, i64 0
  %437 = call { i64, i64 } @simd_set_update_data(i32* noundef %435, i32* noundef %436)
  %438 = bitcast i128* %131 to { i64, i64 }*
  %439 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %438, i32 0, i32 0
  %440 = extractvalue { i64, i64 } %437, 0
  store i64 %440, i64* %439, align 16
  %441 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %438, i32 0, i32 1
  %442 = extractvalue { i64, i64 } %437, 1
  store i64 %442, i64* %441, align 8
  %443 = load i128, i128* %131, align 16
  store i128 %443, i128* %130, align 16
  %444 = bitcast [2 x i32]* %132 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %444, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %445 = getelementptr inbounds [2 x i32], [2 x i32]* %133, i64 0, i64 0
  %446 = load i32, i32* %105, align 4
  store i32 %446, i32* %445, align 4
  %447 = getelementptr inbounds i32, i32* %445, i64 1
  %448 = load i32, i32* %106, align 4
  store i32 %448, i32* %447, align 4
  %449 = getelementptr inbounds [2 x i32], [2 x i32]* %132, i64 0, i64 0
  %450 = getelementptr inbounds [2 x i32], [2 x i32]* %133, i64 0, i64 0
  %451 = call { i64, i64 } @simd_set_update_data(i32* noundef %449, i32* noundef %450)
  %452 = bitcast i128* %135 to { i64, i64 }*
  %453 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %452, i32 0, i32 0
  %454 = extractvalue { i64, i64 } %451, 0
  store i64 %454, i64* %453, align 16
  %455 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %452, i32 0, i32 1
  %456 = extractvalue { i64, i64 } %451, 1
  store i64 %456, i64* %455, align 8
  %457 = load i128, i128* %135, align 16
  store i128 %457, i128* %134, align 16
  %458 = bitcast [2 x i32]* %136 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %458, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %459 = getelementptr inbounds [2 x i32], [2 x i32]* %137, i64 0, i64 0
  %460 = load i32, i32* %104, align 4
  store i32 %460, i32* %459, align 4
  %461 = getelementptr inbounds i32, i32* %459, i64 1
  %462 = load i32, i32* %106, align 4
  store i32 %462, i32* %461, align 4
  %463 = getelementptr inbounds [2 x i32], [2 x i32]* %136, i64 0, i64 0
  %464 = getelementptr inbounds [2 x i32], [2 x i32]* %137, i64 0, i64 0
  %465 = call { i64, i64 } @simd_set_update_data(i32* noundef %463, i32* noundef %464)
  %466 = bitcast i128* %139 to { i64, i64 }*
  %467 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %466, i32 0, i32 0
  %468 = extractvalue { i64, i64 } %465, 0
  store i64 %468, i64* %467, align 16
  %469 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %466, i32 0, i32 1
  %470 = extractvalue { i64, i64 } %465, 1
  store i64 %470, i64* %469, align 8
  %471 = load i128, i128* %139, align 16
  store i128 %471, i128* %138, align 16
  %472 = bitcast [2 x i32]* %140 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %472, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %473 = getelementptr inbounds [2 x i32], [2 x i32]* %141, i64 0, i64 0
  %474 = load i32, i32* %105, align 4
  %475 = load i32, i32* %104, align 4
  %476 = mul nsw i32 %474, %475
  %477 = sdiv i32 %476, 128
  store i32 %477, i32* %473, align 4
  %478 = getelementptr inbounds i32, i32* %473, i64 1
  %479 = load i32, i32* %105, align 4
  %480 = load i32, i32* %106, align 4
  %481 = mul nsw i32 %479, %480
  %482 = sdiv i32 %481, 128
  store i32 %482, i32* %478, align 4
  %483 = getelementptr inbounds [2 x i32], [2 x i32]* %140, i64 0, i64 0
  %484 = getelementptr inbounds [2 x i32], [2 x i32]* %141, i64 0, i64 0
  %485 = call { i64, i64 } @simd_set_update_data(i32* noundef %483, i32* noundef %484)
  %486 = bitcast i128* %143 to { i64, i64 }*
  %487 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %486, i32 0, i32 0
  %488 = extractvalue { i64, i64 } %485, 0
  store i64 %488, i64* %487, align 16
  %489 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %486, i32 0, i32 1
  %490 = extractvalue { i64, i64 } %485, 1
  store i64 %490, i64* %489, align 8
  %491 = load i128, i128* %143, align 16
  store i128 %491, i128* %142, align 16
  %492 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %493 = load i16, i16* %120, align 2
  %494 = load i32, i32* %121, align 4
  %495 = load i128, i128* %130, align 16
  %496 = load i8, i8* %117, align 1
  %497 = load i8, i8* %118, align 1
  %498 = load i8, i8* %119, align 1
  store i128 %495, i128* %144, align 16
  %499 = bitcast i128* %144 to { i64, i64 }*
  %500 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %499, i32 0, i32 0
  %501 = load i64, i64* %500, align 16
  %502 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %499, i32 0, i32 1
  %503 = load i64, i64* %502, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %492, i16 noundef zeroext %493, i32 noundef %494, i64 noundef %501, i64 noundef %503, i8 noundef zeroext %496, i8 noundef zeroext %497, i8 noundef zeroext %498, i8 noundef zeroext 5)
  %504 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %505 = load i16, i16* %120, align 2
  %506 = load i32, i32* %121, align 4
  %507 = add i32 %506, 1
  %508 = load i128, i128* %134, align 16
  %509 = load i8, i8* %117, align 1
  %510 = load i8, i8* %118, align 1
  %511 = load i8, i8* %119, align 1
  store i128 %508, i128* %145, align 16
  %512 = bitcast i128* %145 to { i64, i64 }*
  %513 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %512, i32 0, i32 0
  %514 = load i64, i64* %513, align 16
  %515 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %512, i32 0, i32 1
  %516 = load i64, i64* %515, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %504, i16 noundef zeroext %505, i32 noundef %507, i64 noundef %514, i64 noundef %516, i8 noundef zeroext %509, i8 noundef zeroext %510, i8 noundef zeroext %511, i8 noundef zeroext 5)
  %517 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %518 = load i16, i16* %120, align 2
  %519 = load i32, i32* %121, align 4
  %520 = add i32 %519, 2
  %521 = load i128, i128* %138, align 16
  %522 = load i8, i8* %117, align 1
  %523 = load i8, i8* %118, align 1
  %524 = load i8, i8* %119, align 1
  store i128 %521, i128* %146, align 16
  %525 = bitcast i128* %146 to { i64, i64 }*
  %526 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %525, i32 0, i32 0
  %527 = load i64, i64* %526, align 16
  %528 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %525, i32 0, i32 1
  %529 = load i64, i64* %528, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %517, i16 noundef zeroext %518, i32 noundef %520, i64 noundef %527, i64 noundef %529, i8 noundef zeroext %522, i8 noundef zeroext %523, i8 noundef zeroext %524, i8 noundef zeroext 5)
  %530 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %531 = load i16, i16* %120, align 2
  %532 = load i32, i32* %121, align 4
  %533 = add i32 %532, 3
  %534 = load i128, i128* %142, align 16
  %535 = load i8, i8* %117, align 1
  %536 = load i8, i8* %118, align 1
  %537 = load i8, i8* %119, align 1
  store i128 %534, i128* %147, align 16
  %538 = bitcast i128* %147 to { i64, i64 }*
  %539 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %538, i32 0, i32 0
  %540 = load i64, i64* %539, align 16
  %541 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %538, i32 0, i32 1
  %542 = load i64, i64* %541, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %530, i16 noundef zeroext %531, i32 noundef %533, i64 noundef %540, i64 noundef %542, i8 noundef zeroext %535, i8 noundef zeroext %536, i8 noundef zeroext %537, i8 noundef zeroext 5)
  %543 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %544 = load i32, i32* %112, align 4
  %545 = load i32, i32* %113, align 4
  %546 = load i32, i32* %114, align 4
  %547 = load i32, i32* %115, align 4
  %548 = load i32, i32* %116, align 4
  %549 = load i8, i8* %117, align 1
  %550 = load i8, i8* %118, align 1
  %551 = load i8, i8* %119, align 1
  %552 = load i8, i8* %122, align 1
  %553 = load i8, i8* %123, align 1
  %554 = load i8, i8* %124, align 1
  %555 = load i8, i8* %125, align 1
  %556 = load i8, i8* %126, align 1
  %557 = load i8, i8* %127, align 1
  %558 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %543, i32 noundef %544, i32 noundef %545, i32 noundef %546, i32 noundef %547, i32 noundef %548, i8 noundef zeroext %549, i8 noundef zeroext %550, i8 noundef zeroext %551, i8 noundef zeroext %552, i8 noundef zeroext %553, i8 noundef zeroext %554, i8 noundef zeroext %555, i8 noundef zeroext %556, i8 noundef zeroext %557, i8 noundef zeroext 4)
  br label %559

559:                                              ; preds = %158
  ret void
}

declare %struct.CoreExecutor_T* @simd_gemm_executor_create() #1

declare %struct.DreExecutor_T* @simd_dre_executor_create() #1

declare void @reg2sch_start_set(i32 noundef) #1

attributes #0 = { alwaysinline mustprogress uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly nofree nounwind willreturn }
attributes #3 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.6"}
