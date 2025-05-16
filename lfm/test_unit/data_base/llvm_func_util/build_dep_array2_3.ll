; ModuleID = '/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC240202A/input.cpp.1.expand.mark_if.cpp'
source_filename = "/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC240202A/input.cpp.1.expand.mark_if.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.CoreExecutor_T = type { i32 }
%struct.DreExecutor_T = type { i32 }

@__SIMD_IF_BLOCK__ = dso_local global i32 0, align 4
@__const.simd_gemm_executor_AB.positions_src0 = private unnamed_addr constant [3 x i32] [i32 0, i32 2, i32 3], align 4
@__const.simd_gemm_executor_AB.positions_src1 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_AB.positions_dst0 = private unnamed_addr constant [2 x i32] [i32 0, i32 2], align 4
@__const.simd_gemm_executor_AB.positions_func = private unnamed_addr constant [2 x i32] [i32 2, i32 3], align 4
@__const.simd_dre_executor_reshape.positions_src0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16
@__const.simd_dre_executor_reshape.positions_dst0 = private unnamed_addr constant [7 x i32] [i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6], align 16

; Function Attrs: alwaysinline mustprogress uwtable
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
define dso_local void @_Z3foov() #3 {
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
  %94 = alloca %struct.CoreExecutor_T*, align 8
  %95 = alloca double*, align 8
  %96 = alloca double*, align 8
  %97 = alloca double*, align 8
  %98 = alloca i32, align 4
  %99 = alloca i32, align 4
  %100 = alloca i32, align 4
  %101 = alloca i32, align 4
  %102 = alloca i32, align 4
  %103 = alloca i32, align 4
  %104 = alloca double, align 8
  %105 = alloca double, align 8
  %106 = alloca i32, align 4
  %107 = alloca i32, align 4
  %108 = alloca i32, align 4
  %109 = alloca i32, align 4
  %110 = alloca i32, align 4
  %111 = alloca i8, align 1
  %112 = alloca i8, align 1
  %113 = alloca i8, align 1
  %114 = alloca i16, align 2
  %115 = alloca i32, align 4
  %116 = alloca i8, align 1
  %117 = alloca i8, align 1
  %118 = alloca i8, align 1
  %119 = alloca i8, align 1
  %120 = alloca i8, align 1
  %121 = alloca i8, align 1
  %122 = alloca [3 x i32], align 4
  %123 = alloca [3 x i32], align 4
  %124 = alloca i128, align 16
  %125 = alloca i128, align 16
  %126 = alloca [2 x i32], align 4
  %127 = alloca [2 x i32], align 4
  %128 = alloca i128, align 16
  %129 = alloca i128, align 16
  %130 = alloca [2 x i32], align 4
  %131 = alloca [2 x i32], align 4
  %132 = alloca i128, align 16
  %133 = alloca i128, align 16
  %134 = alloca [2 x i32], align 4
  %135 = alloca [2 x i32], align 4
  %136 = alloca i128, align 16
  %137 = alloca i128, align 16
  %138 = alloca i128, align 16
  %139 = alloca i128, align 16
  %140 = alloca i128, align 16
  %141 = alloca i128, align 16
  %142 = alloca double*, align 8
  %143 = alloca double*, align 8
  %144 = alloca double*, align 8
  %145 = alloca i32, align 4
  %146 = alloca i32, align 4
  %147 = alloca i32, align 4
  %148 = alloca %struct.CoreExecutor_T*, align 8
  %149 = alloca %struct.DreExecutor_T*, align 8
  %150 = call %struct.CoreExecutor_T* @simd_gemm_executor_create()
  store %struct.CoreExecutor_T* %150, %struct.CoreExecutor_T** %148, align 8
  %151 = call %struct.DreExecutor_T* @simd_dre_executor_create()
  store %struct.DreExecutor_T* %151, %struct.DreExecutor_T** %149, align 8
  %152 = load i32, i32* @__SIMD_IF_BLOCK__, align 4
  %153 = icmp ne i32 %152, 0
  br i1 %153, label %154, label %559

154:                                              ; preds = %0
  call void @reg2sch_start_set(i32 noundef 0)
  %155 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %148, align 8
  call void @simd_gemm_executor_initialize(%struct.CoreExecutor_T* noundef %155)
  %156 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %149, align 8
  call void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef %156)
  %157 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %148, align 8
  %158 = load double*, double** %142, align 8
  %159 = load double*, double** %143, align 8
  %160 = load double*, double** %144, align 8
  %161 = load i32, i32* %145, align 4
  %162 = load i32, i32* %146, align 4
  %163 = load i32, i32* %147, align 4
  store %struct.CoreExecutor_T* %157, %struct.CoreExecutor_T** %46, align 8
  store double* %158, double** %47, align 8
  store double* %159, double** %48, align 8
  store double* %160, double** %49, align 8
  store i32 %161, i32* %50, align 4
  store i32 %162, i32* %51, align 4
  store i32 %163, i32* %52, align 4
  store i32 0, i32* %53, align 4
  store i32 0, i32* %54, align 4
  store i32 0, i32* %55, align 4
  store double 1.000000e+00, double* %56, align 8
  store double 1.000000e+00, double* %57, align 8
  %164 = load double*, double** %47, align 8
  %165 = bitcast double* %164 to i8*
  %166 = ptrtoint i8* %165 to i64
  %167 = call i32 @simd_convert_to_relative_addr(i64 noundef %166)
  store i32 %167, i32* %58, align 4
  %168 = load double*, double** %48, align 8
  %169 = bitcast double* %168 to i8*
  %170 = ptrtoint i8* %169 to i64
  %171 = call i32 @simd_convert_to_relative_addr(i64 noundef %170)
  store i32 %171, i32* %59, align 4
  store i32 0, i32* %60, align 4
  %172 = load double*, double** %49, align 8
  %173 = bitcast double* %172 to i8*
  %174 = ptrtoint i8* %173 to i64
  %175 = call i32 @simd_convert_to_relative_addr(i64 noundef %174)
  store i32 %175, i32* %61, align 4
  store i32 0, i32* %62, align 4
  store i8 0, i8* %63, align 1
  store i8 0, i8* %64, align 1
  store i8 0, i8* %65, align 1
  store i16 4369, i16* %66, align 2
  store i32 1, i32* %67, align 4
  store i8 1, i8* %68, align 1
  store i8 2, i8* %69, align 1
  store i8 0, i8* %70, align 1
  store i8 3, i8* %71, align 1
  store i8 4, i8* %72, align 1
  store i8 0, i8* %73, align 1
  %176 = bitcast [3 x i32]* %74 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %176, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %177 = getelementptr inbounds [3 x i32], [3 x i32]* %75, i64 0, i64 0
  %178 = load i32, i32* %51, align 4
  store i32 %178, i32* %177, align 4
  %179 = getelementptr inbounds i32, i32* %177, i64 1
  %180 = load i32, i32* %50, align 4
  store i32 %180, i32* %179, align 4
  %181 = getelementptr inbounds i32, i32* %179, i64 1
  %182 = load i32, i32* %51, align 4
  %183 = add nsw i32 %182, 16
  %184 = sdiv i32 %183, 16
  %185 = sub nsw i32 %184, 1
  store i32 %185, i32* %181, align 4
  %186 = getelementptr inbounds [3 x i32], [3 x i32]* %74, i64 0, i64 0
  %187 = getelementptr inbounds [3 x i32], [3 x i32]* %75, i64 0, i64 0
  %188 = call { i64, i64 } @simd_set_update_data(i32* noundef %186, i32* noundef %187)
  %189 = bitcast i128* %77 to { i64, i64 }*
  %190 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %189, i32 0, i32 0
  %191 = extractvalue { i64, i64 } %188, 0
  store i64 %191, i64* %190, align 16
  %192 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %189, i32 0, i32 1
  %193 = extractvalue { i64, i64 } %188, 1
  store i64 %193, i64* %192, align 8
  %194 = load i128, i128* %77, align 16
  store i128 %194, i128* %76, align 16
  %195 = bitcast [2 x i32]* %78 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %195, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %196 = getelementptr inbounds [2 x i32], [2 x i32]* %79, i64 0, i64 0
  %197 = load i32, i32* %51, align 4
  store i32 %197, i32* %196, align 4
  %198 = getelementptr inbounds i32, i32* %196, i64 1
  %199 = load i32, i32* %52, align 4
  store i32 %199, i32* %198, align 4
  %200 = getelementptr inbounds [2 x i32], [2 x i32]* %78, i64 0, i64 0
  %201 = getelementptr inbounds [2 x i32], [2 x i32]* %79, i64 0, i64 0
  %202 = call { i64, i64 } @simd_set_update_data(i32* noundef %200, i32* noundef %201)
  %203 = bitcast i128* %81 to { i64, i64 }*
  %204 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %203, i32 0, i32 0
  %205 = extractvalue { i64, i64 } %202, 0
  store i64 %205, i64* %204, align 16
  %206 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %203, i32 0, i32 1
  %207 = extractvalue { i64, i64 } %202, 1
  store i64 %207, i64* %206, align 8
  %208 = load i128, i128* %81, align 16
  store i128 %208, i128* %80, align 16
  %209 = bitcast [2 x i32]* %82 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %209, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %210 = getelementptr inbounds [2 x i32], [2 x i32]* %83, i64 0, i64 0
  %211 = load i32, i32* %50, align 4
  store i32 %211, i32* %210, align 4
  %212 = getelementptr inbounds i32, i32* %210, i64 1
  %213 = load i32, i32* %52, align 4
  store i32 %213, i32* %212, align 4
  %214 = getelementptr inbounds [2 x i32], [2 x i32]* %82, i64 0, i64 0
  %215 = getelementptr inbounds [2 x i32], [2 x i32]* %83, i64 0, i64 0
  %216 = call { i64, i64 } @simd_set_update_data(i32* noundef %214, i32* noundef %215)
  %217 = bitcast i128* %85 to { i64, i64 }*
  %218 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %217, i32 0, i32 0
  %219 = extractvalue { i64, i64 } %216, 0
  store i64 %219, i64* %218, align 16
  %220 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %217, i32 0, i32 1
  %221 = extractvalue { i64, i64 } %216, 1
  store i64 %221, i64* %220, align 8
  %222 = load i128, i128* %85, align 16
  store i128 %222, i128* %84, align 16
  %223 = bitcast [2 x i32]* %86 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %223, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %224 = getelementptr inbounds [2 x i32], [2 x i32]* %87, i64 0, i64 0
  %225 = load i32, i32* %51, align 4
  %226 = load i32, i32* %50, align 4
  %227 = mul nsw i32 %225, %226
  %228 = sdiv i32 %227, 128
  store i32 %228, i32* %224, align 4
  %229 = getelementptr inbounds i32, i32* %224, i64 1
  %230 = load i32, i32* %51, align 4
  %231 = load i32, i32* %52, align 4
  %232 = mul nsw i32 %230, %231
  %233 = sdiv i32 %232, 128
  store i32 %233, i32* %229, align 4
  %234 = getelementptr inbounds [2 x i32], [2 x i32]* %86, i64 0, i64 0
  %235 = getelementptr inbounds [2 x i32], [2 x i32]* %87, i64 0, i64 0
  %236 = call { i64, i64 } @simd_set_update_data(i32* noundef %234, i32* noundef %235)
  %237 = bitcast i128* %89 to { i64, i64 }*
  %238 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %237, i32 0, i32 0
  %239 = extractvalue { i64, i64 } %236, 0
  store i64 %239, i64* %238, align 16
  %240 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %237, i32 0, i32 1
  %241 = extractvalue { i64, i64 } %236, 1
  store i64 %241, i64* %240, align 8
  %242 = load i128, i128* %89, align 16
  store i128 %242, i128* %88, align 16
  %243 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %244 = load i16, i16* %66, align 2
  %245 = load i32, i32* %67, align 4
  %246 = load i128, i128* %76, align 16
  %247 = load i8, i8* %63, align 1
  %248 = load i8, i8* %64, align 1
  %249 = load i8, i8* %65, align 1
  store i128 %246, i128* %90, align 16
  %250 = bitcast i128* %90 to { i64, i64 }*
  %251 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %250, i32 0, i32 0
  %252 = load i64, i64* %251, align 16
  %253 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %250, i32 0, i32 1
  %254 = load i64, i64* %253, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %243, i16 noundef zeroext %244, i32 noundef %245, i64 noundef %252, i64 noundef %254, i8 noundef zeroext %247, i8 noundef zeroext %248, i8 noundef zeroext %249, i8 noundef zeroext 5)
  %255 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %256 = load i16, i16* %66, align 2
  %257 = load i32, i32* %67, align 4
  %258 = add i32 %257, 1
  %259 = load i128, i128* %80, align 16
  %260 = load i8, i8* %63, align 1
  %261 = load i8, i8* %64, align 1
  %262 = load i8, i8* %65, align 1
  store i128 %259, i128* %91, align 16
  %263 = bitcast i128* %91 to { i64, i64 }*
  %264 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %263, i32 0, i32 0
  %265 = load i64, i64* %264, align 16
  %266 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %263, i32 0, i32 1
  %267 = load i64, i64* %266, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %255, i16 noundef zeroext %256, i32 noundef %258, i64 noundef %265, i64 noundef %267, i8 noundef zeroext %260, i8 noundef zeroext %261, i8 noundef zeroext %262, i8 noundef zeroext 5)
  %268 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %269 = load i16, i16* %66, align 2
  %270 = load i32, i32* %67, align 4
  %271 = add i32 %270, 2
  %272 = load i128, i128* %84, align 16
  %273 = load i8, i8* %63, align 1
  %274 = load i8, i8* %64, align 1
  %275 = load i8, i8* %65, align 1
  store i128 %272, i128* %92, align 16
  %276 = bitcast i128* %92 to { i64, i64 }*
  %277 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %276, i32 0, i32 0
  %278 = load i64, i64* %277, align 16
  %279 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %276, i32 0, i32 1
  %280 = load i64, i64* %279, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %268, i16 noundef zeroext %269, i32 noundef %271, i64 noundef %278, i64 noundef %280, i8 noundef zeroext %273, i8 noundef zeroext %274, i8 noundef zeroext %275, i8 noundef zeroext 5)
  %281 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %282 = load i16, i16* %66, align 2
  %283 = load i32, i32* %67, align 4
  %284 = add i32 %283, 3
  %285 = load i128, i128* %88, align 16
  %286 = load i8, i8* %63, align 1
  %287 = load i8, i8* %64, align 1
  %288 = load i8, i8* %65, align 1
  store i128 %285, i128* %93, align 16
  %289 = bitcast i128* %93 to { i64, i64 }*
  %290 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %289, i32 0, i32 0
  %291 = load i64, i64* %290, align 16
  %292 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %289, i32 0, i32 1
  %293 = load i64, i64* %292, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %281, i16 noundef zeroext %282, i32 noundef %284, i64 noundef %291, i64 noundef %293, i8 noundef zeroext %286, i8 noundef zeroext %287, i8 noundef zeroext %288, i8 noundef zeroext 5)
  %294 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %46, align 8
  %295 = load i32, i32* %58, align 4
  %296 = load i32, i32* %59, align 4
  %297 = load i32, i32* %60, align 4
  %298 = load i32, i32* %61, align 4
  %299 = load i32, i32* %62, align 4
  %300 = load i8, i8* %63, align 1
  %301 = load i8, i8* %64, align 1
  %302 = load i8, i8* %65, align 1
  %303 = load i8, i8* %68, align 1
  %304 = load i8, i8* %69, align 1
  %305 = load i8, i8* %70, align 1
  %306 = load i8, i8* %71, align 1
  %307 = load i8, i8* %72, align 1
  %308 = load i8, i8* %73, align 1
  %309 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %294, i32 noundef %295, i32 noundef %296, i32 noundef %297, i32 noundef %298, i32 noundef %299, i8 noundef zeroext %300, i8 noundef zeroext %301, i8 noundef zeroext %302, i8 noundef zeroext %303, i8 noundef zeroext %304, i8 noundef zeroext %305, i8 noundef zeroext %306, i8 noundef zeroext %307, i8 noundef zeroext %308, i8 noundef zeroext 4)
  %310 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %149, align 8
  %311 = load double*, double** %142, align 8
  %312 = load double*, double** %143, align 8
  store %struct.DreExecutor_T* %310, %struct.DreExecutor_T** %1, align 8
  store double* %311, double** %2, align 8
  store double* %312, double** %3, align 8
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
  %313 = load double*, double** %2, align 8
  %314 = ptrtoint double* %313 to i64
  %315 = call i32 @simd_convert_to_relative_addr(i64 noundef %314)
  store i32 %315, i32* %20, align 4
  store i32 0, i32* %21, align 4
  store i32 0, i32* %22, align 4
  %316 = load double*, double** %3, align 8
  %317 = ptrtoint double* %316 to i64
  %318 = call i32 @simd_convert_to_relative_addr(i64 noundef %317)
  store i32 %318, i32* %23, align 4
  store i32 0, i32* %24, align 4
  store i8 0, i8* %25, align 1
  store i8 0, i8* %26, align 1
  store i8 0, i8* %27, align 1
  store i16 4369, i16* %28, align 2
  store i32 1, i32* %29, align 4
  store i8 1, i8* %30, align 1
  store i8 2, i8* %31, align 1
  store i8 0, i8* %32, align 1
  store i8 3, i8* %33, align 1
  store i8 4, i8* %34, align 1
  store i8 0, i8* %35, align 1
  %319 = bitcast [7 x i32]* %36 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %319, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false)
  %320 = getelementptr inbounds [7 x i32], [7 x i32]* %37, i64 0, i64 0
  %321 = load i32, i32* %4, align 4
  store i32 %321, i32* %320, align 4
  %322 = getelementptr inbounds i32, i32* %320, i64 1
  %323 = load i32, i32* %6, align 4
  store i32 %323, i32* %322, align 4
  %324 = getelementptr inbounds i32, i32* %322, i64 1
  %325 = load i32, i32* %5, align 4
  store i32 %325, i32* %324, align 4
  %326 = getelementptr inbounds i32, i32* %324, i64 1
  store i32 0, i32* %326, align 4
  %327 = getelementptr inbounds i32, i32* %326, i64 1
  store i32 0, i32* %327, align 4
  %328 = getelementptr inbounds i32, i32* %327, i64 1
  %329 = load i32, i32* %4, align 4
  store i32 %329, i32* %328, align 4
  %330 = getelementptr inbounds i32, i32* %328, i64 1
  %331 = load i32, i32* %8, align 4
  store i32 %331, i32* %330, align 4
  %332 = getelementptr inbounds [7 x i32], [7 x i32]* %36, i64 0, i64 0
  %333 = getelementptr inbounds [7 x i32], [7 x i32]* %37, i64 0, i64 0
  %334 = call { i64, i64 } @simd_set_update_data(i32* noundef %332, i32* noundef %333)
  %335 = bitcast i128* %39 to { i64, i64 }*
  %336 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %335, i32 0, i32 0
  %337 = extractvalue { i64, i64 } %334, 0
  store i64 %337, i64* %336, align 16
  %338 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %335, i32 0, i32 1
  %339 = extractvalue { i64, i64 } %334, 1
  store i64 %339, i64* %338, align 8
  %340 = load i128, i128* %39, align 16
  store i128 %340, i128* %38, align 16
  %341 = bitcast [7 x i32]* %40 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %341, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false)
  %342 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %343 = load i32, i32* %7, align 4
  store i32 %343, i32* %342, align 4
  %344 = getelementptr inbounds i32, i32* %342, i64 1
  %345 = load i32, i32* %9, align 4
  store i32 %345, i32* %344, align 4
  %346 = getelementptr inbounds i32, i32* %344, i64 1
  %347 = load i32, i32* %8, align 4
  store i32 %347, i32* %346, align 4
  %348 = getelementptr inbounds i32, i32* %346, i64 1
  store i32 0, i32* %348, align 4
  %349 = getelementptr inbounds i32, i32* %348, i64 1
  store i32 0, i32* %349, align 4
  %350 = getelementptr inbounds i32, i32* %349, i64 1
  %351 = load i32, i32* %7, align 4
  store i32 %351, i32* %350, align 4
  %352 = getelementptr inbounds i32, i32* %350, i64 1
  %353 = load i32, i32* %8, align 4
  store i32 %353, i32* %352, align 4
  %354 = getelementptr inbounds [7 x i32], [7 x i32]* %40, i64 0, i64 0
  %355 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %356 = call { i64, i64 } @simd_set_update_data(i32* noundef %354, i32* noundef %355)
  %357 = bitcast i128* %43 to { i64, i64 }*
  %358 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %357, i32 0, i32 0
  %359 = extractvalue { i64, i64 } %356, 0
  store i64 %359, i64* %358, align 16
  %360 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %357, i32 0, i32 1
  %361 = extractvalue { i64, i64 } %356, 1
  store i64 %361, i64* %360, align 8
  %362 = load i128, i128* %43, align 16
  store i128 %362, i128* %42, align 16
  %363 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %364 = load i16, i16* %28, align 2
  %365 = load i32, i32* %29, align 4
  %366 = load i128, i128* %38, align 16
  %367 = load i8, i8* %25, align 1
  %368 = load i8, i8* %26, align 1
  %369 = load i8, i8* %27, align 1
  store i128 %366, i128* %44, align 16
  %370 = bitcast i128* %44 to { i64, i64 }*
  %371 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %370, i32 0, i32 0
  %372 = load i64, i64* %371, align 16
  %373 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %370, i32 0, i32 1
  %374 = load i64, i64* %373, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %363, i16 noundef zeroext %364, i32 noundef %365, i64 noundef %372, i64 noundef %374, i8 noundef zeroext %367, i8 noundef zeroext %368, i8 noundef zeroext %369, i8 noundef zeroext 5)
  %375 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %376 = load i16, i16* %28, align 2
  %377 = load i32, i32* %29, align 4
  %378 = add i32 %377, 2
  %379 = load i128, i128* %42, align 16
  %380 = load i8, i8* %25, align 1
  %381 = load i8, i8* %26, align 1
  %382 = load i8, i8* %27, align 1
  store i128 %379, i128* %45, align 16
  %383 = bitcast i128* %45 to { i64, i64 }*
  %384 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %383, i32 0, i32 0
  %385 = load i64, i64* %384, align 16
  %386 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %383, i32 0, i32 1
  %387 = load i64, i64* %386, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %375, i16 noundef zeroext %376, i32 noundef %378, i64 noundef %385, i64 noundef %387, i8 noundef zeroext %380, i8 noundef zeroext %381, i8 noundef zeroext %382, i8 noundef zeroext 5)
  %388 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %389 = load i32, i32* %20, align 4
  %390 = load i32, i32* %21, align 4
  %391 = load i32, i32* %22, align 4
  %392 = load i32, i32* %23, align 4
  %393 = load i32, i32* %24, align 4
  %394 = load i8, i8* %25, align 1
  %395 = load i8, i8* %26, align 1
  %396 = load i8, i8* %27, align 1
  %397 = load i8, i8* %30, align 1
  %398 = load i8, i8* %31, align 1
  %399 = load i8, i8* %32, align 1
  %400 = load i8, i8* %33, align 1
  %401 = load i8, i8* %34, align 1
  %402 = load i8, i8* %35, align 1
  %403 = call i32 @Dre(%struct.DreExecutor_T* noundef %388, i32 noundef %389, i32 noundef %390, i32 noundef %391, i32 noundef %392, i32 noundef %393, i8 noundef zeroext %394, i8 noundef zeroext %395, i8 noundef zeroext %396, i8 noundef zeroext %397, i8 noundef zeroext %398, i8 noundef zeroext %399, i8 noundef zeroext %400, i8 noundef zeroext %401, i8 noundef zeroext %402, i8 noundef zeroext 4)
  %404 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %148, align 8
  %405 = load double*, double** %143, align 8
  %406 = load double*, double** %144, align 8
  %407 = load double*, double** %144, align 8
  %408 = load i32, i32* %145, align 4
  %409 = load i32, i32* %146, align 4
  %410 = load i32, i32* %147, align 4
  store %struct.CoreExecutor_T* %404, %struct.CoreExecutor_T** %94, align 8
  store double* %405, double** %95, align 8
  store double* %406, double** %96, align 8
  store double* %407, double** %97, align 8
  store i32 %408, i32* %98, align 4
  store i32 %409, i32* %99, align 4
  store i32 %410, i32* %100, align 4
  store i32 0, i32* %101, align 4
  store i32 0, i32* %102, align 4
  store i32 0, i32* %103, align 4
  store double 1.000000e+00, double* %104, align 8
  store double 1.000000e+00, double* %105, align 8
  %411 = load double*, double** %95, align 8
  %412 = bitcast double* %411 to i8*
  %413 = ptrtoint i8* %412 to i64
  %414 = call i32 @simd_convert_to_relative_addr(i64 noundef %413)
  store i32 %414, i32* %106, align 4
  %415 = load double*, double** %96, align 8
  %416 = bitcast double* %415 to i8*
  %417 = ptrtoint i8* %416 to i64
  %418 = call i32 @simd_convert_to_relative_addr(i64 noundef %417)
  store i32 %418, i32* %107, align 4
  store i32 0, i32* %108, align 4
  %419 = load double*, double** %97, align 8
  %420 = bitcast double* %419 to i8*
  %421 = ptrtoint i8* %420 to i64
  %422 = call i32 @simd_convert_to_relative_addr(i64 noundef %421)
  store i32 %422, i32* %109, align 4
  store i32 0, i32* %110, align 4
  store i8 0, i8* %111, align 1
  store i8 0, i8* %112, align 1
  store i8 0, i8* %113, align 1
  store i16 4369, i16* %114, align 2
  store i32 1, i32* %115, align 4
  store i8 1, i8* %116, align 1
  store i8 2, i8* %117, align 1
  store i8 0, i8* %118, align 1
  store i8 3, i8* %119, align 1
  store i8 4, i8* %120, align 1
  store i8 0, i8* %121, align 1
  %423 = bitcast [3 x i32]* %122 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %423, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %424 = getelementptr inbounds [3 x i32], [3 x i32]* %123, i64 0, i64 0
  %425 = load i32, i32* %99, align 4
  store i32 %425, i32* %424, align 4
  %426 = getelementptr inbounds i32, i32* %424, i64 1
  %427 = load i32, i32* %98, align 4
  store i32 %427, i32* %426, align 4
  %428 = getelementptr inbounds i32, i32* %426, i64 1
  %429 = load i32, i32* %99, align 4
  %430 = add nsw i32 %429, 16
  %431 = sdiv i32 %430, 16
  %432 = sub nsw i32 %431, 1
  store i32 %432, i32* %428, align 4
  %433 = getelementptr inbounds [3 x i32], [3 x i32]* %122, i64 0, i64 0
  %434 = getelementptr inbounds [3 x i32], [3 x i32]* %123, i64 0, i64 0
  %435 = call { i64, i64 } @simd_set_update_data(i32* noundef %433, i32* noundef %434)
  %436 = bitcast i128* %125 to { i64, i64 }*
  %437 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %436, i32 0, i32 0
  %438 = extractvalue { i64, i64 } %435, 0
  store i64 %438, i64* %437, align 16
  %439 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %436, i32 0, i32 1
  %440 = extractvalue { i64, i64 } %435, 1
  store i64 %440, i64* %439, align 8
  %441 = load i128, i128* %125, align 16
  store i128 %441, i128* %124, align 16
  %442 = bitcast [2 x i32]* %126 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %442, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %443 = getelementptr inbounds [2 x i32], [2 x i32]* %127, i64 0, i64 0
  %444 = load i32, i32* %99, align 4
  store i32 %444, i32* %443, align 4
  %445 = getelementptr inbounds i32, i32* %443, i64 1
  %446 = load i32, i32* %100, align 4
  store i32 %446, i32* %445, align 4
  %447 = getelementptr inbounds [2 x i32], [2 x i32]* %126, i64 0, i64 0
  %448 = getelementptr inbounds [2 x i32], [2 x i32]* %127, i64 0, i64 0
  %449 = call { i64, i64 } @simd_set_update_data(i32* noundef %447, i32* noundef %448)
  %450 = bitcast i128* %129 to { i64, i64 }*
  %451 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %450, i32 0, i32 0
  %452 = extractvalue { i64, i64 } %449, 0
  store i64 %452, i64* %451, align 16
  %453 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %450, i32 0, i32 1
  %454 = extractvalue { i64, i64 } %449, 1
  store i64 %454, i64* %453, align 8
  %455 = load i128, i128* %129, align 16
  store i128 %455, i128* %128, align 16
  %456 = bitcast [2 x i32]* %130 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %456, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %457 = getelementptr inbounds [2 x i32], [2 x i32]* %131, i64 0, i64 0
  %458 = load i32, i32* %98, align 4
  store i32 %458, i32* %457, align 4
  %459 = getelementptr inbounds i32, i32* %457, i64 1
  %460 = load i32, i32* %100, align 4
  store i32 %460, i32* %459, align 4
  %461 = getelementptr inbounds [2 x i32], [2 x i32]* %130, i64 0, i64 0
  %462 = getelementptr inbounds [2 x i32], [2 x i32]* %131, i64 0, i64 0
  %463 = call { i64, i64 } @simd_set_update_data(i32* noundef %461, i32* noundef %462)
  %464 = bitcast i128* %133 to { i64, i64 }*
  %465 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %464, i32 0, i32 0
  %466 = extractvalue { i64, i64 } %463, 0
  store i64 %466, i64* %465, align 16
  %467 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %464, i32 0, i32 1
  %468 = extractvalue { i64, i64 } %463, 1
  store i64 %468, i64* %467, align 8
  %469 = load i128, i128* %133, align 16
  store i128 %469, i128* %132, align 16
  %470 = bitcast [2 x i32]* %134 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %470, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %471 = getelementptr inbounds [2 x i32], [2 x i32]* %135, i64 0, i64 0
  %472 = load i32, i32* %99, align 4
  %473 = load i32, i32* %98, align 4
  %474 = mul nsw i32 %472, %473
  %475 = sdiv i32 %474, 128
  store i32 %475, i32* %471, align 4
  %476 = getelementptr inbounds i32, i32* %471, i64 1
  %477 = load i32, i32* %99, align 4
  %478 = load i32, i32* %100, align 4
  %479 = mul nsw i32 %477, %478
  %480 = sdiv i32 %479, 128
  store i32 %480, i32* %476, align 4
  %481 = getelementptr inbounds [2 x i32], [2 x i32]* %134, i64 0, i64 0
  %482 = getelementptr inbounds [2 x i32], [2 x i32]* %135, i64 0, i64 0
  %483 = call { i64, i64 } @simd_set_update_data(i32* noundef %481, i32* noundef %482)
  %484 = bitcast i128* %137 to { i64, i64 }*
  %485 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %484, i32 0, i32 0
  %486 = extractvalue { i64, i64 } %483, 0
  store i64 %486, i64* %485, align 16
  %487 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %484, i32 0, i32 1
  %488 = extractvalue { i64, i64 } %483, 1
  store i64 %488, i64* %487, align 8
  %489 = load i128, i128* %137, align 16
  store i128 %489, i128* %136, align 16
  %490 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %94, align 8
  %491 = load i16, i16* %114, align 2
  %492 = load i32, i32* %115, align 4
  %493 = load i128, i128* %124, align 16
  %494 = load i8, i8* %111, align 1
  %495 = load i8, i8* %112, align 1
  %496 = load i8, i8* %113, align 1
  store i128 %493, i128* %138, align 16
  %497 = bitcast i128* %138 to { i64, i64 }*
  %498 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %497, i32 0, i32 0
  %499 = load i64, i64* %498, align 16
  %500 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %497, i32 0, i32 1
  %501 = load i64, i64* %500, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %490, i16 noundef zeroext %491, i32 noundef %492, i64 noundef %499, i64 noundef %501, i8 noundef zeroext %494, i8 noundef zeroext %495, i8 noundef zeroext %496, i8 noundef zeroext 5)
  %502 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %94, align 8
  %503 = load i16, i16* %114, align 2
  %504 = load i32, i32* %115, align 4
  %505 = add i32 %504, 1
  %506 = load i128, i128* %128, align 16
  %507 = load i8, i8* %111, align 1
  %508 = load i8, i8* %112, align 1
  %509 = load i8, i8* %113, align 1
  store i128 %506, i128* %139, align 16
  %510 = bitcast i128* %139 to { i64, i64 }*
  %511 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %510, i32 0, i32 0
  %512 = load i64, i64* %511, align 16
  %513 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %510, i32 0, i32 1
  %514 = load i64, i64* %513, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %502, i16 noundef zeroext %503, i32 noundef %505, i64 noundef %512, i64 noundef %514, i8 noundef zeroext %507, i8 noundef zeroext %508, i8 noundef zeroext %509, i8 noundef zeroext 5)
  %515 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %94, align 8
  %516 = load i16, i16* %114, align 2
  %517 = load i32, i32* %115, align 4
  %518 = add i32 %517, 2
  %519 = load i128, i128* %132, align 16
  %520 = load i8, i8* %111, align 1
  %521 = load i8, i8* %112, align 1
  %522 = load i8, i8* %113, align 1
  store i128 %519, i128* %140, align 16
  %523 = bitcast i128* %140 to { i64, i64 }*
  %524 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %523, i32 0, i32 0
  %525 = load i64, i64* %524, align 16
  %526 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %523, i32 0, i32 1
  %527 = load i64, i64* %526, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %515, i16 noundef zeroext %516, i32 noundef %518, i64 noundef %525, i64 noundef %527, i8 noundef zeroext %520, i8 noundef zeroext %521, i8 noundef zeroext %522, i8 noundef zeroext 5)
  %528 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %94, align 8
  %529 = load i16, i16* %114, align 2
  %530 = load i32, i32* %115, align 4
  %531 = add i32 %530, 3
  %532 = load i128, i128* %136, align 16
  %533 = load i8, i8* %111, align 1
  %534 = load i8, i8* %112, align 1
  %535 = load i8, i8* %113, align 1
  store i128 %532, i128* %141, align 16
  %536 = bitcast i128* %141 to { i64, i64 }*
  %537 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %536, i32 0, i32 0
  %538 = load i64, i64* %537, align 16
  %539 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %536, i32 0, i32 1
  %540 = load i64, i64* %539, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %528, i16 noundef zeroext %529, i32 noundef %531, i64 noundef %538, i64 noundef %540, i8 noundef zeroext %533, i8 noundef zeroext %534, i8 noundef zeroext %535, i8 noundef zeroext 5)
  %541 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %94, align 8
  %542 = load i32, i32* %106, align 4
  %543 = load i32, i32* %107, align 4
  %544 = load i32, i32* %108, align 4
  %545 = load i32, i32* %109, align 4
  %546 = load i32, i32* %110, align 4
  %547 = load i8, i8* %111, align 1
  %548 = load i8, i8* %112, align 1
  %549 = load i8, i8* %113, align 1
  %550 = load i8, i8* %116, align 1
  %551 = load i8, i8* %117, align 1
  %552 = load i8, i8* %118, align 1
  %553 = load i8, i8* %119, align 1
  %554 = load i8, i8* %120, align 1
  %555 = load i8, i8* %121, align 1
  %556 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %541, i32 noundef %542, i32 noundef %543, i32 noundef %544, i32 noundef %545, i32 noundef %546, i8 noundef zeroext %547, i8 noundef zeroext %548, i8 noundef zeroext %549, i8 noundef zeroext %550, i8 noundef zeroext %551, i8 noundef zeroext %552, i8 noundef zeroext %553, i8 noundef zeroext %554, i8 noundef zeroext %555, i8 noundef zeroext 4)
  %557 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %148, align 8
  call void @simd_gemm_executor_release(%struct.CoreExecutor_T* noundef %557)
  %558 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %149, align 8
  call void @simd_dre_executor_release(%struct.DreExecutor_T* noundef %558)
  call void @simd_synchronize(i32 noundef 0)
  br label %559

559:                                              ; preds = %154, %0
  ret void
}

declare %struct.CoreExecutor_T* @simd_gemm_executor_create() #1

declare %struct.DreExecutor_T* @simd_dre_executor_create() #1

declare void @reg2sch_start_set(i32 noundef) #1

declare void @simd_gemm_executor_initialize(%struct.CoreExecutor_T* noundef) #1

declare void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef) #1

declare void @simd_gemm_executor_release(%struct.CoreExecutor_T* noundef) #1

declare void @simd_dre_executor_release(%struct.DreExecutor_T* noundef) #1

declare void @simd_synchronize(i32 noundef) #1

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
