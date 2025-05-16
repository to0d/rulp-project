; ModuleID = '/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC240112B/input.cpp.1.expand.mark_if.cpp'
source_filename = "/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC240112B/input.cpp.1.expand.mark_if.cpp"
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

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @foo(double* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5) #3 {
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
  %158 = load i32, i32* @__SIMD_IF_BLOCK__, align 4
  %159 = icmp ne i32 %158, 0
  br i1 %159, label %160, label %582

160:                                              ; preds = %6
  call void @reg2sch_start_set(i8 noundef zeroext 0)
  %161 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %154, align 8
  call void @simd_gemm_executor_initialize(%struct.CoreExecutor_T* noundef %161)
  %162 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %155, align 8
  call void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef %162)
  %163 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %154, align 8
  %164 = load double*, double** %148, align 8
  %165 = load double*, double** %149, align 8
  %166 = load double*, double** %150, align 8
  %167 = load i32, i32* %151, align 4
  %168 = load i32, i32* %152, align 4
  %169 = load i32, i32* %153, align 4
  store %struct.CoreExecutor_T* %163, %struct.CoreExecutor_T** %52, align 8
  store double* %164, double** %53, align 8
  store double* %165, double** %54, align 8
  store double* %166, double** %55, align 8
  store i32 %167, i32* %56, align 4
  store i32 %168, i32* %57, align 4
  store i32 %169, i32* %58, align 4
  store i32 0, i32* %59, align 4
  store i32 0, i32* %60, align 4
  store i32 0, i32* %61, align 4
  store double 1.000000e+00, double* %62, align 8
  store double 1.000000e+00, double* %63, align 8
  %170 = load double*, double** %53, align 8
  %171 = ptrtoint double* %170 to i64
  %172 = call i32 @convertToRelativeAddr(i64 noundef %171)
  store i32 %172, i32* %64, align 4
  %173 = load double*, double** %54, align 8
  %174 = ptrtoint double* %173 to i64
  %175 = call i32 @convertToRelativeAddr(i64 noundef %174)
  store i32 %175, i32* %65, align 4
  store i32 0, i32* %66, align 4
  %176 = load double*, double** %55, align 8
  %177 = ptrtoint double* %176 to i64
  %178 = call i32 @convertToRelativeAddr(i64 noundef %177)
  store i32 %178, i32* %67, align 4
  store i32 0, i32* %68, align 4
  store i8 0, i8* %69, align 1
  store i8 2, i8* %70, align 1
  store i8 0, i8* %71, align 1
  store i16 4369, i16* %72, align 2
  store i32 1, i32* %73, align 4
  store i8 1, i8* %74, align 1
  store i8 2, i8* %75, align 1
  store i8 0, i8* %76, align 1
  store i8 3, i8* %77, align 1
  store i8 4, i8* %78, align 1
  store i8 0, i8* %79, align 1
  %179 = bitcast [3 x i32]* %80 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %179, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %180 = getelementptr inbounds [3 x i32], [3 x i32]* %81, i64 0, i64 0
  %181 = load i32, i32* %57, align 4
  store i32 %181, i32* %180, align 4
  %182 = getelementptr inbounds i32, i32* %180, i64 1
  %183 = load i32, i32* %56, align 4
  store i32 %183, i32* %182, align 4
  %184 = getelementptr inbounds i32, i32* %182, i64 1
  %185 = load i32, i32* %57, align 4
  %186 = add nsw i32 %185, 16
  %187 = sdiv i32 %186, 16
  %188 = sub nsw i32 %187, 1
  store i32 %188, i32* %184, align 4
  %189 = getelementptr inbounds [3 x i32], [3 x i32]* %80, i64 0, i64 0
  %190 = getelementptr inbounds [3 x i32], [3 x i32]* %81, i64 0, i64 0
  %191 = call { i64, i64 } @setUpdateData(i32* noundef %189, i32* noundef %190, i32 noundef 3)
  %192 = bitcast i128* %83 to { i64, i64 }*
  %193 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %192, i32 0, i32 0
  %194 = extractvalue { i64, i64 } %191, 0
  store i64 %194, i64* %193, align 16
  %195 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %192, i32 0, i32 1
  %196 = extractvalue { i64, i64 } %191, 1
  store i64 %196, i64* %195, align 8
  %197 = load i128, i128* %83, align 16
  store i128 %197, i128* %82, align 16
  %198 = bitcast [2 x i32]* %84 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %198, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %199 = getelementptr inbounds [2 x i32], [2 x i32]* %85, i64 0, i64 0
  %200 = load i32, i32* %57, align 4
  store i32 %200, i32* %199, align 4
  %201 = getelementptr inbounds i32, i32* %199, i64 1
  %202 = load i32, i32* %58, align 4
  store i32 %202, i32* %201, align 4
  %203 = getelementptr inbounds [2 x i32], [2 x i32]* %84, i64 0, i64 0
  %204 = getelementptr inbounds [2 x i32], [2 x i32]* %85, i64 0, i64 0
  %205 = call { i64, i64 } @setUpdateData(i32* noundef %203, i32* noundef %204, i32 noundef 2)
  %206 = bitcast i128* %87 to { i64, i64 }*
  %207 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %206, i32 0, i32 0
  %208 = extractvalue { i64, i64 } %205, 0
  store i64 %208, i64* %207, align 16
  %209 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %206, i32 0, i32 1
  %210 = extractvalue { i64, i64 } %205, 1
  store i64 %210, i64* %209, align 8
  %211 = load i128, i128* %87, align 16
  store i128 %211, i128* %86, align 16
  %212 = bitcast [2 x i32]* %88 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %212, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %213 = getelementptr inbounds [2 x i32], [2 x i32]* %89, i64 0, i64 0
  %214 = load i32, i32* %56, align 4
  store i32 %214, i32* %213, align 4
  %215 = getelementptr inbounds i32, i32* %213, i64 1
  %216 = load i32, i32* %58, align 4
  store i32 %216, i32* %215, align 4
  %217 = getelementptr inbounds [2 x i32], [2 x i32]* %88, i64 0, i64 0
  %218 = getelementptr inbounds [2 x i32], [2 x i32]* %89, i64 0, i64 0
  %219 = call { i64, i64 } @setUpdateData(i32* noundef %217, i32* noundef %218, i32 noundef 2)
  %220 = bitcast i128* %91 to { i64, i64 }*
  %221 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %220, i32 0, i32 0
  %222 = extractvalue { i64, i64 } %219, 0
  store i64 %222, i64* %221, align 16
  %223 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %220, i32 0, i32 1
  %224 = extractvalue { i64, i64 } %219, 1
  store i64 %224, i64* %223, align 8
  %225 = load i128, i128* %91, align 16
  store i128 %225, i128* %90, align 16
  %226 = bitcast [2 x i32]* %92 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %226, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %227 = getelementptr inbounds [2 x i32], [2 x i32]* %93, i64 0, i64 0
  %228 = load i32, i32* %57, align 4
  %229 = load i32, i32* %56, align 4
  %230 = mul nsw i32 %228, %229
  %231 = sdiv i32 %230, 128
  store i32 %231, i32* %227, align 4
  %232 = getelementptr inbounds i32, i32* %227, i64 1
  %233 = load i32, i32* %57, align 4
  %234 = load i32, i32* %58, align 4
  %235 = mul nsw i32 %233, %234
  %236 = sdiv i32 %235, 128
  store i32 %236, i32* %232, align 4
  %237 = getelementptr inbounds [2 x i32], [2 x i32]* %92, i64 0, i64 0
  %238 = getelementptr inbounds [2 x i32], [2 x i32]* %93, i64 0, i64 0
  %239 = call { i64, i64 } @setUpdateData(i32* noundef %237, i32* noundef %238, i32 noundef 2)
  %240 = bitcast i128* %95 to { i64, i64 }*
  %241 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %240, i32 0, i32 0
  %242 = extractvalue { i64, i64 } %239, 0
  store i64 %242, i64* %241, align 16
  %243 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %240, i32 0, i32 1
  %244 = extractvalue { i64, i64 } %239, 1
  store i64 %244, i64* %243, align 8
  %245 = load i128, i128* %95, align 16
  store i128 %245, i128* %94, align 16
  %246 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %247 = load i16, i16* %72, align 2
  %248 = load i32, i32* %73, align 4
  %249 = load i128, i128* %82, align 16
  %250 = load i8, i8* %69, align 1
  %251 = load i8, i8* %70, align 1
  %252 = load i8, i8* %71, align 1
  store i128 %249, i128* %96, align 16
  %253 = bitcast i128* %96 to { i64, i64 }*
  %254 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %253, i32 0, i32 0
  %255 = load i64, i64* %254, align 16
  %256 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %253, i32 0, i32 1
  %257 = load i64, i64* %256, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %246, i16 noundef zeroext %247, i32 noundef %248, i64 noundef %255, i64 noundef %257, i8 noundef zeroext %250, i8 noundef zeroext %251, i8 noundef zeroext %252, i8 noundef zeroext 5)
  %258 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %259 = load i16, i16* %72, align 2
  %260 = load i32, i32* %73, align 4
  %261 = add i32 %260, 1
  %262 = load i128, i128* %86, align 16
  %263 = load i8, i8* %69, align 1
  %264 = load i8, i8* %70, align 1
  %265 = load i8, i8* %71, align 1
  store i128 %262, i128* %97, align 16
  %266 = bitcast i128* %97 to { i64, i64 }*
  %267 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %266, i32 0, i32 0
  %268 = load i64, i64* %267, align 16
  %269 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %266, i32 0, i32 1
  %270 = load i64, i64* %269, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %258, i16 noundef zeroext %259, i32 noundef %261, i64 noundef %268, i64 noundef %270, i8 noundef zeroext %263, i8 noundef zeroext %264, i8 noundef zeroext %265, i8 noundef zeroext 5)
  %271 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %272 = load i16, i16* %72, align 2
  %273 = load i32, i32* %73, align 4
  %274 = add i32 %273, 2
  %275 = load i128, i128* %90, align 16
  %276 = load i8, i8* %69, align 1
  %277 = load i8, i8* %70, align 1
  %278 = load i8, i8* %71, align 1
  store i128 %275, i128* %98, align 16
  %279 = bitcast i128* %98 to { i64, i64 }*
  %280 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %279, i32 0, i32 0
  %281 = load i64, i64* %280, align 16
  %282 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %279, i32 0, i32 1
  %283 = load i64, i64* %282, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %271, i16 noundef zeroext %272, i32 noundef %274, i64 noundef %281, i64 noundef %283, i8 noundef zeroext %276, i8 noundef zeroext %277, i8 noundef zeroext %278, i8 noundef zeroext 5)
  %284 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %285 = load i16, i16* %72, align 2
  %286 = load i32, i32* %73, align 4
  %287 = add i32 %286, 3
  %288 = load i128, i128* %94, align 16
  %289 = load i8, i8* %69, align 1
  %290 = load i8, i8* %70, align 1
  %291 = load i8, i8* %71, align 1
  store i128 %288, i128* %99, align 16
  %292 = bitcast i128* %99 to { i64, i64 }*
  %293 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %292, i32 0, i32 0
  %294 = load i64, i64* %293, align 16
  %295 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %292, i32 0, i32 1
  %296 = load i64, i64* %295, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %284, i16 noundef zeroext %285, i32 noundef %287, i64 noundef %294, i64 noundef %296, i8 noundef zeroext %289, i8 noundef zeroext %290, i8 noundef zeroext %291, i8 noundef zeroext 5)
  %297 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %52, align 8
  %298 = load i32, i32* %64, align 4
  %299 = load i32, i32* %65, align 4
  %300 = load i32, i32* %66, align 4
  %301 = load i32, i32* %67, align 4
  %302 = load i32, i32* %68, align 4
  %303 = load i8, i8* %69, align 1
  %304 = load i8, i8* %70, align 1
  %305 = load i8, i8* %71, align 1
  %306 = load i8, i8* %74, align 1
  %307 = load i8, i8* %75, align 1
  %308 = load i8, i8* %76, align 1
  %309 = load i8, i8* %77, align 1
  %310 = load i8, i8* %78, align 1
  %311 = load i8, i8* %79, align 1
  %312 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %297, i32 noundef %298, i32 noundef %299, i32 noundef %300, i32 noundef %301, i32 noundef %302, i8 noundef zeroext %303, i8 noundef zeroext %304, i8 noundef zeroext %305, i8 noundef zeroext %306, i8 noundef zeroext %307, i8 noundef zeroext %308, i8 noundef zeroext %309, i8 noundef zeroext %310, i8 noundef zeroext %311, i8 noundef zeroext 4)
  %313 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %155, align 8
  %314 = load double*, double** %148, align 8
  %315 = load double*, double** %149, align 8
  store %struct.DreExecutor_T* %313, %struct.DreExecutor_T** %7, align 8
  store double* %314, double** %8, align 8
  store double* %315, double** %9, align 8
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
  %316 = load double*, double** %8, align 8
  %317 = ptrtoint double* %316 to i64
  %318 = call i32 @convertToRelativeAddr(i64 noundef %317)
  store i32 %318, i32* %26, align 4
  store i32 0, i32* %27, align 4
  store i32 0, i32* %28, align 4
  %319 = load double*, double** %9, align 8
  %320 = ptrtoint double* %319 to i64
  %321 = call i32 @convertToRelativeAddr(i64 noundef %320)
  store i32 %321, i32* %29, align 4
  store i32 0, i32* %30, align 4
  store i8 0, i8* %31, align 1
  store i8 2, i8* %32, align 1
  store i8 0, i8* %33, align 1
  store i16 -1, i16* %34, align 2
  store i32 0, i32* %35, align 4
  store i8 0, i8* %36, align 1
  store i8 1, i8* %37, align 1
  store i8 2, i8* %38, align 1
  store i8 3, i8* %39, align 1
  store i8 4, i8* %40, align 1
  %322 = load i32, i32* %25, align 4
  %323 = icmp eq i32 %322, 0
  br i1 %323, label %324, label %325

324:                                              ; preds = %160
  br label %336

325:                                              ; preds = %160
  %326 = load i32, i32* %25, align 4
  %327 = icmp eq i32 %326, 1
  br i1 %327, label %328, label %329

328:                                              ; preds = %325
  br label %334

329:                                              ; preds = %325
  %330 = load i32, i32* %25, align 4
  %331 = icmp eq i32 %330, 2
  %332 = zext i1 %331 to i64
  %333 = select i1 %331, i32 6, i32 16
  br label %334

334:                                              ; preds = %329, %328
  %335 = phi i32 [ 5, %328 ], [ %333, %329 ]
  br label %336

336:                                              ; preds = %324, %334
  %337 = phi i32 [ 4, %324 ], [ %335, %334 ]
  %338 = trunc i32 %337 to i8
  store i8 %338, i8* %41, align 1
  %339 = bitcast [7 x i32]* %42 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %339, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false)
  %340 = getelementptr inbounds [7 x i32], [7 x i32]* %43, i64 0, i64 0
  %341 = load i32, i32* %10, align 4
  %342 = sub nsw i32 %341, 1
  store i32 %342, i32* %340, align 4
  %343 = getelementptr inbounds i32, i32* %340, i64 1
  %344 = load i32, i32* %12, align 4
  %345 = sub nsw i32 %344, 1
  store i32 %345, i32* %343, align 4
  %346 = getelementptr inbounds i32, i32* %343, i64 1
  %347 = load i32, i32* %11, align 4
  %348 = sub nsw i32 %347, 1
  store i32 %348, i32* %346, align 4
  %349 = getelementptr inbounds i32, i32* %346, i64 1
  store i32 0, i32* %349, align 4
  %350 = getelementptr inbounds i32, i32* %349, i64 1
  store i32 0, i32* %350, align 4
  %351 = getelementptr inbounds i32, i32* %350, i64 1
  %352 = load i32, i32* %10, align 4
  %353 = sub nsw i32 %352, 1
  store i32 %353, i32* %351, align 4
  %354 = getelementptr inbounds i32, i32* %351, i64 1
  %355 = load i32, i32* %11, align 4
  %356 = sub nsw i32 %355, 1
  store i32 %356, i32* %354, align 4
  %357 = getelementptr inbounds [7 x i32], [7 x i32]* %42, i64 0, i64 0
  %358 = getelementptr inbounds [7 x i32], [7 x i32]* %43, i64 0, i64 0
  %359 = call { i64, i64 } @setUpdateData(i32* noundef %357, i32* noundef %358, i32 noundef 7)
  %360 = bitcast i128* %45 to { i64, i64 }*
  %361 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %360, i32 0, i32 0
  %362 = extractvalue { i64, i64 } %359, 0
  store i64 %362, i64* %361, align 16
  %363 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %360, i32 0, i32 1
  %364 = extractvalue { i64, i64 } %359, 1
  store i64 %364, i64* %363, align 8
  %365 = load i128, i128* %45, align 16
  store i128 %365, i128* %44, align 16
  %366 = bitcast [7 x i32]* %46 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %366, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false)
  %367 = getelementptr inbounds [7 x i32], [7 x i32]* %47, i64 0, i64 0
  %368 = load i32, i32* %13, align 4
  %369 = sub nsw i32 %368, 1
  store i32 %369, i32* %367, align 4
  %370 = getelementptr inbounds i32, i32* %367, i64 1
  %371 = load i32, i32* %15, align 4
  %372 = sub nsw i32 %371, 1
  store i32 %372, i32* %370, align 4
  %373 = getelementptr inbounds i32, i32* %370, i64 1
  %374 = load i32, i32* %14, align 4
  %375 = sub nsw i32 %374, 1
  store i32 %375, i32* %373, align 4
  %376 = getelementptr inbounds i32, i32* %373, i64 1
  store i32 0, i32* %376, align 4
  %377 = getelementptr inbounds i32, i32* %376, i64 1
  store i32 0, i32* %377, align 4
  %378 = getelementptr inbounds i32, i32* %377, i64 1
  %379 = load i32, i32* %13, align 4
  %380 = sub nsw i32 %379, 1
  store i32 %380, i32* %378, align 4
  %381 = getelementptr inbounds i32, i32* %378, i64 1
  %382 = load i32, i32* %14, align 4
  %383 = sub nsw i32 %382, 1
  store i32 %383, i32* %381, align 4
  %384 = getelementptr inbounds [7 x i32], [7 x i32]* %46, i64 0, i64 0
  %385 = getelementptr inbounds [7 x i32], [7 x i32]* %47, i64 0, i64 0
  %386 = call { i64, i64 } @setUpdateData(i32* noundef %384, i32* noundef %385, i32 noundef 7)
  %387 = bitcast i128* %49 to { i64, i64 }*
  %388 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %387, i32 0, i32 0
  %389 = extractvalue { i64, i64 } %386, 0
  store i64 %389, i64* %388, align 16
  %390 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %387, i32 0, i32 1
  %391 = extractvalue { i64, i64 } %386, 1
  store i64 %391, i64* %390, align 8
  %392 = load i128, i128* %49, align 16
  store i128 %392, i128* %48, align 16
  %393 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %7, align 8
  %394 = load i16, i16* %34, align 2
  %395 = load i32, i32* %35, align 4
  %396 = load i128, i128* %44, align 16
  %397 = load i8, i8* %31, align 1
  store i128 %396, i128* %50, align 16
  %398 = bitcast i128* %50 to { i64, i64 }*
  %399 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %398, i32 0, i32 0
  %400 = load i64, i64* %399, align 16
  %401 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %398, i32 0, i32 1
  %402 = load i64, i64* %401, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %393, i16 noundef zeroext %394, i32 noundef %395, i64 noundef %400, i64 noundef %402, i8 noundef zeroext %397, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9)
  %403 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %7, align 8
  %404 = load i16, i16* %34, align 2
  %405 = load i32, i32* %35, align 4
  %406 = add i32 %405, 3
  %407 = load i128, i128* %48, align 16
  %408 = load i8, i8* %31, align 1
  store i128 %407, i128* %51, align 16
  %409 = bitcast i128* %51 to { i64, i64 }*
  %410 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %409, i32 0, i32 0
  %411 = load i64, i64* %410, align 16
  %412 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %409, i32 0, i32 1
  %413 = load i64, i64* %412, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %403, i16 noundef zeroext %404, i32 noundef %406, i64 noundef %411, i64 noundef %413, i8 noundef zeroext %408, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9)
  %414 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %7, align 8
  %415 = load i32, i32* %26, align 4
  %416 = load i32, i32* %27, align 4
  %417 = load i32, i32* %28, align 4
  %418 = load i32, i32* %29, align 4
  %419 = load i32, i32* %30, align 4
  %420 = load i8, i8* %31, align 1
  %421 = load i8, i8* %32, align 1
  %422 = load i8, i8* %33, align 1
  %423 = load i8, i8* %36, align 1
  %424 = load i8, i8* %37, align 1
  %425 = load i8, i8* %38, align 1
  %426 = load i8, i8* %39, align 1
  %427 = load i8, i8* %40, align 1
  %428 = load i8, i8* %41, align 1
  %429 = call i32 @Dre(%struct.DreExecutor_T* noundef %414, i32 noundef %415, i32 noundef %416, i32 noundef %417, i32 noundef %418, i32 noundef %419, i8 noundef zeroext %420, i8 noundef zeroext %421, i8 noundef zeroext %422, i8 noundef zeroext %423, i8 noundef zeroext %424, i8 noundef zeroext %425, i8 noundef zeroext %426, i8 noundef zeroext %427, i8 noundef zeroext %428, i8 noundef zeroext 8)
  call void @simd_synchronize(i32 noundef 0)
  call void @reg2sch_start_set(i8 noundef zeroext 0)
  %430 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %154, align 8
  %431 = load double*, double** %150, align 8
  %432 = load double*, double** %150, align 8
  %433 = load double*, double** %150, align 8
  %434 = load i32, i32* %151, align 4
  %435 = load i32, i32* %152, align 4
  %436 = load i32, i32* %153, align 4
  store %struct.CoreExecutor_T* %430, %struct.CoreExecutor_T** %100, align 8
  store double* %431, double** %101, align 8
  store double* %432, double** %102, align 8
  store double* %433, double** %103, align 8
  store i32 %434, i32* %104, align 4
  store i32 %435, i32* %105, align 4
  store i32 %436, i32* %106, align 4
  store i32 0, i32* %107, align 4
  store i32 0, i32* %108, align 4
  store i32 0, i32* %109, align 4
  store double 1.000000e+00, double* %110, align 8
  store double 1.000000e+00, double* %111, align 8
  %437 = load double*, double** %101, align 8
  %438 = ptrtoint double* %437 to i64
  %439 = call i32 @convertToRelativeAddr(i64 noundef %438)
  store i32 %439, i32* %112, align 4
  %440 = load double*, double** %102, align 8
  %441 = ptrtoint double* %440 to i64
  %442 = call i32 @convertToRelativeAddr(i64 noundef %441)
  store i32 %442, i32* %113, align 4
  store i32 0, i32* %114, align 4
  %443 = load double*, double** %103, align 8
  %444 = ptrtoint double* %443 to i64
  %445 = call i32 @convertToRelativeAddr(i64 noundef %444)
  store i32 %445, i32* %115, align 4
  store i32 0, i32* %116, align 4
  store i8 0, i8* %117, align 1
  store i8 2, i8* %118, align 1
  store i8 0, i8* %119, align 1
  store i16 4369, i16* %120, align 2
  store i32 1, i32* %121, align 4
  store i8 1, i8* %122, align 1
  store i8 2, i8* %123, align 1
  store i8 0, i8* %124, align 1
  store i8 3, i8* %125, align 1
  store i8 4, i8* %126, align 1
  store i8 0, i8* %127, align 1
  %446 = bitcast [3 x i32]* %128 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %446, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false)
  %447 = getelementptr inbounds [3 x i32], [3 x i32]* %129, i64 0, i64 0
  %448 = load i32, i32* %105, align 4
  store i32 %448, i32* %447, align 4
  %449 = getelementptr inbounds i32, i32* %447, i64 1
  %450 = load i32, i32* %104, align 4
  store i32 %450, i32* %449, align 4
  %451 = getelementptr inbounds i32, i32* %449, i64 1
  %452 = load i32, i32* %105, align 4
  %453 = add nsw i32 %452, 16
  %454 = sdiv i32 %453, 16
  %455 = sub nsw i32 %454, 1
  store i32 %455, i32* %451, align 4
  %456 = getelementptr inbounds [3 x i32], [3 x i32]* %128, i64 0, i64 0
  %457 = getelementptr inbounds [3 x i32], [3 x i32]* %129, i64 0, i64 0
  %458 = call { i64, i64 } @setUpdateData(i32* noundef %456, i32* noundef %457, i32 noundef 3)
  %459 = bitcast i128* %131 to { i64, i64 }*
  %460 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %459, i32 0, i32 0
  %461 = extractvalue { i64, i64 } %458, 0
  store i64 %461, i64* %460, align 16
  %462 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %459, i32 0, i32 1
  %463 = extractvalue { i64, i64 } %458, 1
  store i64 %463, i64* %462, align 8
  %464 = load i128, i128* %131, align 16
  store i128 %464, i128* %130, align 16
  %465 = bitcast [2 x i32]* %132 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %465, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false)
  %466 = getelementptr inbounds [2 x i32], [2 x i32]* %133, i64 0, i64 0
  %467 = load i32, i32* %105, align 4
  store i32 %467, i32* %466, align 4
  %468 = getelementptr inbounds i32, i32* %466, i64 1
  %469 = load i32, i32* %106, align 4
  store i32 %469, i32* %468, align 4
  %470 = getelementptr inbounds [2 x i32], [2 x i32]* %132, i64 0, i64 0
  %471 = getelementptr inbounds [2 x i32], [2 x i32]* %133, i64 0, i64 0
  %472 = call { i64, i64 } @setUpdateData(i32* noundef %470, i32* noundef %471, i32 noundef 2)
  %473 = bitcast i128* %135 to { i64, i64 }*
  %474 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %473, i32 0, i32 0
  %475 = extractvalue { i64, i64 } %472, 0
  store i64 %475, i64* %474, align 16
  %476 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %473, i32 0, i32 1
  %477 = extractvalue { i64, i64 } %472, 1
  store i64 %477, i64* %476, align 8
  %478 = load i128, i128* %135, align 16
  store i128 %478, i128* %134, align 16
  %479 = bitcast [2 x i32]* %136 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %479, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false)
  %480 = getelementptr inbounds [2 x i32], [2 x i32]* %137, i64 0, i64 0
  %481 = load i32, i32* %104, align 4
  store i32 %481, i32* %480, align 4
  %482 = getelementptr inbounds i32, i32* %480, i64 1
  %483 = load i32, i32* %106, align 4
  store i32 %483, i32* %482, align 4
  %484 = getelementptr inbounds [2 x i32], [2 x i32]* %136, i64 0, i64 0
  %485 = getelementptr inbounds [2 x i32], [2 x i32]* %137, i64 0, i64 0
  %486 = call { i64, i64 } @setUpdateData(i32* noundef %484, i32* noundef %485, i32 noundef 2)
  %487 = bitcast i128* %139 to { i64, i64 }*
  %488 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %487, i32 0, i32 0
  %489 = extractvalue { i64, i64 } %486, 0
  store i64 %489, i64* %488, align 16
  %490 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %487, i32 0, i32 1
  %491 = extractvalue { i64, i64 } %486, 1
  store i64 %491, i64* %490, align 8
  %492 = load i128, i128* %139, align 16
  store i128 %492, i128* %138, align 16
  %493 = bitcast [2 x i32]* %140 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %493, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false)
  %494 = getelementptr inbounds [2 x i32], [2 x i32]* %141, i64 0, i64 0
  %495 = load i32, i32* %105, align 4
  %496 = load i32, i32* %104, align 4
  %497 = mul nsw i32 %495, %496
  %498 = sdiv i32 %497, 128
  store i32 %498, i32* %494, align 4
  %499 = getelementptr inbounds i32, i32* %494, i64 1
  %500 = load i32, i32* %105, align 4
  %501 = load i32, i32* %106, align 4
  %502 = mul nsw i32 %500, %501
  %503 = sdiv i32 %502, 128
  store i32 %503, i32* %499, align 4
  %504 = getelementptr inbounds [2 x i32], [2 x i32]* %140, i64 0, i64 0
  %505 = getelementptr inbounds [2 x i32], [2 x i32]* %141, i64 0, i64 0
  %506 = call { i64, i64 } @setUpdateData(i32* noundef %504, i32* noundef %505, i32 noundef 2)
  %507 = bitcast i128* %143 to { i64, i64 }*
  %508 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %507, i32 0, i32 0
  %509 = extractvalue { i64, i64 } %506, 0
  store i64 %509, i64* %508, align 16
  %510 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %507, i32 0, i32 1
  %511 = extractvalue { i64, i64 } %506, 1
  store i64 %511, i64* %510, align 8
  %512 = load i128, i128* %143, align 16
  store i128 %512, i128* %142, align 16
  %513 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %514 = load i16, i16* %120, align 2
  %515 = load i32, i32* %121, align 4
  %516 = load i128, i128* %130, align 16
  %517 = load i8, i8* %117, align 1
  %518 = load i8, i8* %118, align 1
  %519 = load i8, i8* %119, align 1
  store i128 %516, i128* %144, align 16
  %520 = bitcast i128* %144 to { i64, i64 }*
  %521 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %520, i32 0, i32 0
  %522 = load i64, i64* %521, align 16
  %523 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %520, i32 0, i32 1
  %524 = load i64, i64* %523, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %513, i16 noundef zeroext %514, i32 noundef %515, i64 noundef %522, i64 noundef %524, i8 noundef zeroext %517, i8 noundef zeroext %518, i8 noundef zeroext %519, i8 noundef zeroext 5)
  %525 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %526 = load i16, i16* %120, align 2
  %527 = load i32, i32* %121, align 4
  %528 = add i32 %527, 1
  %529 = load i128, i128* %134, align 16
  %530 = load i8, i8* %117, align 1
  %531 = load i8, i8* %118, align 1
  %532 = load i8, i8* %119, align 1
  store i128 %529, i128* %145, align 16
  %533 = bitcast i128* %145 to { i64, i64 }*
  %534 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %533, i32 0, i32 0
  %535 = load i64, i64* %534, align 16
  %536 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %533, i32 0, i32 1
  %537 = load i64, i64* %536, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %525, i16 noundef zeroext %526, i32 noundef %528, i64 noundef %535, i64 noundef %537, i8 noundef zeroext %530, i8 noundef zeroext %531, i8 noundef zeroext %532, i8 noundef zeroext 5)
  %538 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %539 = load i16, i16* %120, align 2
  %540 = load i32, i32* %121, align 4
  %541 = add i32 %540, 2
  %542 = load i128, i128* %138, align 16
  %543 = load i8, i8* %117, align 1
  %544 = load i8, i8* %118, align 1
  %545 = load i8, i8* %119, align 1
  store i128 %542, i128* %146, align 16
  %546 = bitcast i128* %146 to { i64, i64 }*
  %547 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %546, i32 0, i32 0
  %548 = load i64, i64* %547, align 16
  %549 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %546, i32 0, i32 1
  %550 = load i64, i64* %549, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %538, i16 noundef zeroext %539, i32 noundef %541, i64 noundef %548, i64 noundef %550, i8 noundef zeroext %543, i8 noundef zeroext %544, i8 noundef zeroext %545, i8 noundef zeroext 5)
  %551 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %552 = load i16, i16* %120, align 2
  %553 = load i32, i32* %121, align 4
  %554 = add i32 %553, 3
  %555 = load i128, i128* %142, align 16
  %556 = load i8, i8* %117, align 1
  %557 = load i8, i8* %118, align 1
  %558 = load i8, i8* %119, align 1
  store i128 %555, i128* %147, align 16
  %559 = bitcast i128* %147 to { i64, i64 }*
  %560 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %559, i32 0, i32 0
  %561 = load i64, i64* %560, align 16
  %562 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %559, i32 0, i32 1
  %563 = load i64, i64* %562, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %551, i16 noundef zeroext %552, i32 noundef %554, i64 noundef %561, i64 noundef %563, i8 noundef zeroext %556, i8 noundef zeroext %557, i8 noundef zeroext %558, i8 noundef zeroext 5)
  %564 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %100, align 8
  %565 = load i32, i32* %112, align 4
  %566 = load i32, i32* %113, align 4
  %567 = load i32, i32* %114, align 4
  %568 = load i32, i32* %115, align 4
  %569 = load i32, i32* %116, align 4
  %570 = load i8, i8* %117, align 1
  %571 = load i8, i8* %118, align 1
  %572 = load i8, i8* %119, align 1
  %573 = load i8, i8* %122, align 1
  %574 = load i8, i8* %123, align 1
  %575 = load i8, i8* %124, align 1
  %576 = load i8, i8* %125, align 1
  %577 = load i8, i8* %126, align 1
  %578 = load i8, i8* %127, align 1
  %579 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %564, i32 noundef %565, i32 noundef %566, i32 noundef %567, i32 noundef %568, i32 noundef %569, i8 noundef zeroext %570, i8 noundef zeroext %571, i8 noundef zeroext %572, i8 noundef zeroext %573, i8 noundef zeroext %574, i8 noundef zeroext %575, i8 noundef zeroext %576, i8 noundef zeroext %577, i8 noundef zeroext %578, i8 noundef zeroext 4)
  %580 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %154, align 8
  call void @simd_gemm_executor_release(%struct.CoreExecutor_T* noundef %580)
  %581 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %155, align 8
  call void @simd_dre_executor_release(%struct.DreExecutor_T* noundef %581)
  call void @simd_synchronize(i32 noundef 0)
  br label %582

582:                                              ; preds = %336, %6
  %583 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %155, align 8
  %584 = bitcast %struct.DreExecutor_T* %583 to i8*
  call void @free(i8* noundef %584) #5
  %585 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %154, align 8
  %586 = bitcast %struct.CoreExecutor_T* %585 to i8*
  call void @free(i8* noundef %586) #5
  ret void
}

declare %struct.CoreExecutor_T* @simd_gemm_executor_create() #1

declare %struct.DreExecutor_T* @simd_dre_executor_create() #1

declare void @reg2sch_start_set(i8 noundef zeroext) #1

declare void @simd_gemm_executor_initialize(%struct.CoreExecutor_T* noundef) #1

declare void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef) #1

declare void @simd_synchronize(i32 noundef) #1

declare void @simd_gemm_executor_release(%struct.CoreExecutor_T* noundef) #1

declare void @simd_dre_executor_release(%struct.DreExecutor_T* noundef) #1

; Function Attrs: nounwind
declare void @free(i8* noundef) #4

attributes #0 = { alwaysinline mustprogress uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly nofree nounwind willreturn }
attributes #3 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
