; ModuleID = '/mnt/c/data/work_thu/code_thu/lfc/scc/test_scc/TC240412A/main.c.trans.1.tmp.c.2.expand.mark_block.ll'
source_filename = "/mnt/c/data/work_thu/code_thu/lfc/scc/test_scc/TC240412A/main.c.trans.1.tmp.c.1.expand.mark_block.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.CoreExecutor_T = type { i32 }
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
@.str = private unnamed_addr constant [10 x i8] c"HW START\0A\00", align 1

declare void @simd_major_finish(i8 noundef zeroext, i8 noundef zeroext) #0

declare i32 @convertToRelativeAddr(i64 noundef) #0

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #1

declare { i64, i64 } @setUpdateData(i32* noundef, i32* noundef, i32 noundef) #0

declare void @simd_gemm_init(%struct.CoreExecutor_T* noundef, i16 noundef zeroext, i32 noundef, i64 noundef, i64 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #0

declare i32 @Gemm(%struct.CoreExecutor_T* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #0

; Function Attrs: argmemonly nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #2

declare i64 @calculateConvOutputShape(i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) #0

declare void @simd_dre_init(%struct.DreExecutor_T* noundef, i16 noundef zeroext, i32 noundef, i64 noundef, i64 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #0

declare i32 @Dre(%struct.DreExecutor_T* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext, i8 noundef zeroext) #0

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @foo() #3 {
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
  %46 = alloca %struct.DreExecutor_T*, align 8
  %47 = alloca double*, align 8
  %48 = alloca double*, align 8
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
  %61 = alloca i32, align 4
  %62 = alloca i32, align 4
  %63 = alloca i32, align 4
  %64 = alloca i32, align 4
  %65 = alloca i32, align 4
  %66 = alloca i32, align 4
  %67 = alloca i32, align 4
  %68 = alloca i32, align 4
  %69 = alloca i32, align 4
  %70 = alloca i8, align 1
  %71 = alloca i8, align 1
  %72 = alloca i8, align 1
  %73 = alloca i16, align 2
  %74 = alloca i32, align 4
  %75 = alloca i8, align 1
  %76 = alloca i8, align 1
  %77 = alloca i8, align 1
  %78 = alloca i8, align 1
  %79 = alloca i8, align 1
  %80 = alloca i8, align 1
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
  %91 = alloca %struct.CoreExecutor_T*, align 8
  %92 = alloca double*, align 8
  %93 = alloca double*, align 8
  %94 = alloca double*, align 8
  %95 = alloca i32, align 4
  %96 = alloca i32, align 4
  %97 = alloca i32, align 4
  %98 = alloca i32, align 4
  %99 = alloca i32, align 4
  %100 = alloca i32, align 4
  %101 = alloca double, align 8
  %102 = alloca double, align 8
  %103 = alloca i32, align 4
  %104 = alloca i32, align 4
  %105 = alloca i32, align 4
  %106 = alloca i32, align 4
  %107 = alloca i32, align 4
  %108 = alloca i8, align 1
  %109 = alloca i8, align 1
  %110 = alloca i8, align 1
  %111 = alloca i16, align 2
  %112 = alloca i32, align 4
  %113 = alloca i8, align 1
  %114 = alloca i8, align 1
  %115 = alloca i8, align 1
  %116 = alloca i8, align 1
  %117 = alloca i8, align 1
  %118 = alloca i8, align 1
  %119 = alloca [3 x i32], align 4
  %120 = alloca [3 x i32], align 4
  %121 = alloca i128, align 16
  %122 = alloca i128, align 16
  %123 = alloca [2 x i32], align 4
  %124 = alloca [2 x i32], align 4
  %125 = alloca i128, align 16
  %126 = alloca i128, align 16
  %127 = alloca [2 x i32], align 4
  %128 = alloca [2 x i32], align 4
  %129 = alloca i128, align 16
  %130 = alloca i128, align 16
  %131 = alloca [2 x i32], align 4
  %132 = alloca [2 x i32], align 4
  %133 = alloca i128, align 16
  %134 = alloca i128, align 16
  %135 = alloca i128, align 16
  %136 = alloca i128, align 16
  %137 = alloca i128, align 16
  %138 = alloca i128, align 16
  %139 = alloca %struct.CoreExecutor_T*, align 8
  %140 = alloca double*, align 8
  %141 = alloca double*, align 8
  %142 = alloca double*, align 8
  %143 = alloca i32, align 4
  %144 = alloca i32, align 4
  %145 = alloca i32, align 4
  %146 = alloca i32, align 4
  %147 = alloca i32, align 4
  %148 = alloca i32, align 4
  %149 = alloca double, align 8
  %150 = alloca double, align 8
  %151 = alloca i32, align 4
  %152 = alloca i32, align 4
  %153 = alloca i32, align 4
  %154 = alloca i32, align 4
  %155 = alloca i32, align 4
  %156 = alloca i8, align 1
  %157 = alloca i8, align 1
  %158 = alloca i8, align 1
  %159 = alloca i16, align 2
  %160 = alloca i32, align 4
  %161 = alloca i8, align 1
  %162 = alloca i8, align 1
  %163 = alloca i8, align 1
  %164 = alloca i8, align 1
  %165 = alloca i8, align 1
  %166 = alloca i8, align 1
  %167 = alloca [3 x i32], align 4
  %168 = alloca [3 x i32], align 4
  %169 = alloca i128, align 16
  %170 = alloca i128, align 16
  %171 = alloca [2 x i32], align 4
  %172 = alloca [2 x i32], align 4
  %173 = alloca i128, align 16
  %174 = alloca i128, align 16
  %175 = alloca [2 x i32], align 4
  %176 = alloca [2 x i32], align 4
  %177 = alloca i128, align 16
  %178 = alloca i128, align 16
  %179 = alloca [2 x i32], align 4
  %180 = alloca [2 x i32], align 4
  %181 = alloca i128, align 16
  %182 = alloca i128, align 16
  %183 = alloca i128, align 16
  %184 = alloca i128, align 16
  %185 = alloca i128, align 16
  %186 = alloca i128, align 16
  %187 = alloca i32, align 4
  %188 = alloca i32, align 4
  %189 = alloca double*, align 8
  %190 = alloca double*, align 8
  %191 = alloca double*, align 8
  %192 = alloca double*, align 8
  %193 = alloca double*, align 8
  %194 = alloca double*, align 8
  %195 = alloca i32, align 4
  %196 = alloca i32, align 4
  %197 = alloca i32, align 4
  %198 = alloca %struct.CoreExecutor_T*, align 8
  %199 = alloca %struct.DreExecutor_T*, align 8
  store i32 0, i32* %188, align 4
  %200 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([10 x i8], [10 x i8]* @.str, i64 0, i64 0))
  %201 = call %struct.CoreExecutor_T* (...) @simd_gemm_executor_create()
  store %struct.CoreExecutor_T* %201, %struct.CoreExecutor_T** %198, align 8
  %202 = call %struct.DreExecutor_T* (...) @simd_dre_executor_create()
  store %struct.DreExecutor_T* %202, %struct.DreExecutor_T** %199, align 8
  br label %203

203:                                              ; preds = %0
  %204 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %198, align 8
  call void @simd_gemm_executor_initialize(%struct.CoreExecutor_T* noundef %204)
  %205 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %199, align 8
  call void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef %205)
  call void @reg2sch_start_set(i8 noundef zeroext 0)
  %206 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %198, align 8
  %207 = load double*, double** %189, align 8
  %208 = load double*, double** %190, align 8
  %209 = load double*, double** %191, align 8
  %210 = load i32, i32* %195, align 4
  %211 = load i32, i32* %196, align 4
  %212 = load i32, i32* %197, align 4
  store %struct.CoreExecutor_T* %206, %struct.CoreExecutor_T** %91, align 8
  store double* %207, double** %92, align 8
  store double* %208, double** %93, align 8
  store double* %209, double** %94, align 8
  store i32 %210, i32* %95, align 4
  store i32 %211, i32* %96, align 4
  store i32 %212, i32* %97, align 4
  store i32 0, i32* %98, align 4
  store i32 0, i32* %99, align 4
  store i32 0, i32* %100, align 4
  store double 1.000000e+00, double* %101, align 8
  store double 1.000000e+00, double* %102, align 8
  %213 = load double*, double** %92, align 8
  %214 = ptrtoint double* %213 to i64
  %215 = call i32 @convertToRelativeAddr(i64 noundef %214) #4
  store i32 %215, i32* %103, align 4
  %216 = load double*, double** %93, align 8
  %217 = ptrtoint double* %216 to i64
  %218 = call i32 @convertToRelativeAddr(i64 noundef %217) #4
  store i32 %218, i32* %104, align 4
  store i32 0, i32* %105, align 4
  %219 = load double*, double** %94, align 8
  %220 = ptrtoint double* %219 to i64
  %221 = call i32 @convertToRelativeAddr(i64 noundef %220) #4
  store i32 %221, i32* %106, align 4
  store i32 0, i32* %107, align 4
  store i8 0, i8* %108, align 1
  store i8 2, i8* %109, align 1
  store i8 0, i8* %110, align 1
  store i16 4369, i16* %111, align 2
  store i32 1, i32* %112, align 4
  store i8 1, i8* %113, align 1
  store i8 2, i8* %114, align 1
  store i8 0, i8* %115, align 1
  store i8 3, i8* %116, align 1
  store i8 4, i8* %117, align 1
  store i8 0, i8* %118, align 1
  %222 = bitcast [3 x i32]* %119 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %222, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false) #4
  %223 = getelementptr inbounds [3 x i32], [3 x i32]* %120, i64 0, i64 0
  %224 = load i32, i32* %96, align 4
  store i32 %224, i32* %223, align 4
  %225 = getelementptr inbounds i32, i32* %223, i64 1
  %226 = load i32, i32* %95, align 4
  store i32 %226, i32* %225, align 4
  %227 = getelementptr inbounds i32, i32* %225, i64 1
  %228 = load i32, i32* %96, align 4
  %229 = add nsw i32 %228, 16
  %230 = sdiv i32 %229, 16
  %231 = sub nsw i32 %230, 1
  store i32 %231, i32* %227, align 4
  %232 = getelementptr inbounds [3 x i32], [3 x i32]* %119, i64 0, i64 0
  %233 = getelementptr inbounds [3 x i32], [3 x i32]* %120, i64 0, i64 0
  %234 = call { i64, i64 } @setUpdateData(i32* noundef %232, i32* noundef %233, i32 noundef 3) #4
  %235 = bitcast i128* %122 to { i64, i64 }*
  %236 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %235, i32 0, i32 0
  %237 = extractvalue { i64, i64 } %234, 0
  store i64 %237, i64* %236, align 16
  %238 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %235, i32 0, i32 1
  %239 = extractvalue { i64, i64 } %234, 1
  store i64 %239, i64* %238, align 8
  %240 = load i128, i128* %122, align 16
  store i128 %240, i128* %121, align 16
  %241 = bitcast [2 x i32]* %123 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %241, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false) #4
  %242 = getelementptr inbounds [2 x i32], [2 x i32]* %124, i64 0, i64 0
  %243 = load i32, i32* %96, align 4
  store i32 %243, i32* %242, align 4
  %244 = getelementptr inbounds i32, i32* %242, i64 1
  %245 = load i32, i32* %97, align 4
  store i32 %245, i32* %244, align 4
  %246 = getelementptr inbounds [2 x i32], [2 x i32]* %123, i64 0, i64 0
  %247 = getelementptr inbounds [2 x i32], [2 x i32]* %124, i64 0, i64 0
  %248 = call { i64, i64 } @setUpdateData(i32* noundef %246, i32* noundef %247, i32 noundef 2) #4
  %249 = bitcast i128* %126 to { i64, i64 }*
  %250 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %249, i32 0, i32 0
  %251 = extractvalue { i64, i64 } %248, 0
  store i64 %251, i64* %250, align 16
  %252 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %249, i32 0, i32 1
  %253 = extractvalue { i64, i64 } %248, 1
  store i64 %253, i64* %252, align 8
  %254 = load i128, i128* %126, align 16
  store i128 %254, i128* %125, align 16
  %255 = bitcast [2 x i32]* %127 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %255, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false) #4
  %256 = getelementptr inbounds [2 x i32], [2 x i32]* %128, i64 0, i64 0
  %257 = load i32, i32* %95, align 4
  store i32 %257, i32* %256, align 4
  %258 = getelementptr inbounds i32, i32* %256, i64 1
  %259 = load i32, i32* %97, align 4
  store i32 %259, i32* %258, align 4
  %260 = getelementptr inbounds [2 x i32], [2 x i32]* %127, i64 0, i64 0
  %261 = getelementptr inbounds [2 x i32], [2 x i32]* %128, i64 0, i64 0
  %262 = call { i64, i64 } @setUpdateData(i32* noundef %260, i32* noundef %261, i32 noundef 2) #4
  %263 = bitcast i128* %130 to { i64, i64 }*
  %264 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %263, i32 0, i32 0
  %265 = extractvalue { i64, i64 } %262, 0
  store i64 %265, i64* %264, align 16
  %266 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %263, i32 0, i32 1
  %267 = extractvalue { i64, i64 } %262, 1
  store i64 %267, i64* %266, align 8
  %268 = load i128, i128* %130, align 16
  store i128 %268, i128* %129, align 16
  %269 = bitcast [2 x i32]* %131 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %269, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false) #4
  %270 = getelementptr inbounds [2 x i32], [2 x i32]* %132, i64 0, i64 0
  %271 = load i32, i32* %96, align 4
  %272 = load i32, i32* %95, align 4
  %273 = mul nsw i32 %271, %272
  %274 = sdiv i32 %273, 128
  store i32 %274, i32* %270, align 4
  %275 = getelementptr inbounds i32, i32* %270, i64 1
  %276 = load i32, i32* %96, align 4
  %277 = load i32, i32* %97, align 4
  %278 = mul nsw i32 %276, %277
  %279 = sdiv i32 %278, 128
  store i32 %279, i32* %275, align 4
  %280 = getelementptr inbounds [2 x i32], [2 x i32]* %131, i64 0, i64 0
  %281 = getelementptr inbounds [2 x i32], [2 x i32]* %132, i64 0, i64 0
  %282 = call { i64, i64 } @setUpdateData(i32* noundef %280, i32* noundef %281, i32 noundef 2) #4
  %283 = bitcast i128* %134 to { i64, i64 }*
  %284 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %283, i32 0, i32 0
  %285 = extractvalue { i64, i64 } %282, 0
  store i64 %285, i64* %284, align 16
  %286 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %283, i32 0, i32 1
  %287 = extractvalue { i64, i64 } %282, 1
  store i64 %287, i64* %286, align 8
  %288 = load i128, i128* %134, align 16
  store i128 %288, i128* %133, align 16
  %289 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %91, align 8
  %290 = load i16, i16* %111, align 2
  %291 = load i32, i32* %112, align 4
  %292 = load i128, i128* %121, align 16
  %293 = load i8, i8* %108, align 1
  %294 = load i8, i8* %109, align 1
  %295 = load i8, i8* %110, align 1
  store i128 %292, i128* %135, align 16
  %296 = bitcast i128* %135 to { i64, i64 }*
  %297 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %296, i32 0, i32 0
  %298 = load i64, i64* %297, align 16
  %299 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %296, i32 0, i32 1
  %300 = load i64, i64* %299, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %289, i16 noundef zeroext %290, i32 noundef %291, i64 noundef %298, i64 noundef %300, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext %295, i8 noundef zeroext 5) #4
  %301 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %91, align 8
  %302 = load i16, i16* %111, align 2
  %303 = load i32, i32* %112, align 4
  %304 = add i32 %303, 1
  %305 = load i128, i128* %125, align 16
  %306 = load i8, i8* %108, align 1
  %307 = load i8, i8* %109, align 1
  %308 = load i8, i8* %110, align 1
  store i128 %305, i128* %136, align 16
  %309 = bitcast i128* %136 to { i64, i64 }*
  %310 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %309, i32 0, i32 0
  %311 = load i64, i64* %310, align 16
  %312 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %309, i32 0, i32 1
  %313 = load i64, i64* %312, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %301, i16 noundef zeroext %302, i32 noundef %304, i64 noundef %311, i64 noundef %313, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext %308, i8 noundef zeroext 5) #4
  %314 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %91, align 8
  %315 = load i16, i16* %111, align 2
  %316 = load i32, i32* %112, align 4
  %317 = add i32 %316, 2
  %318 = load i128, i128* %129, align 16
  %319 = load i8, i8* %108, align 1
  %320 = load i8, i8* %109, align 1
  %321 = load i8, i8* %110, align 1
  store i128 %318, i128* %137, align 16
  %322 = bitcast i128* %137 to { i64, i64 }*
  %323 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %322, i32 0, i32 0
  %324 = load i64, i64* %323, align 16
  %325 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %322, i32 0, i32 1
  %326 = load i64, i64* %325, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %314, i16 noundef zeroext %315, i32 noundef %317, i64 noundef %324, i64 noundef %326, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext %321, i8 noundef zeroext 5) #4
  %327 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %91, align 8
  %328 = load i16, i16* %111, align 2
  %329 = load i32, i32* %112, align 4
  %330 = add i32 %329, 3
  %331 = load i128, i128* %133, align 16
  %332 = load i8, i8* %108, align 1
  %333 = load i8, i8* %109, align 1
  %334 = load i8, i8* %110, align 1
  store i128 %331, i128* %138, align 16
  %335 = bitcast i128* %138 to { i64, i64 }*
  %336 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %335, i32 0, i32 0
  %337 = load i64, i64* %336, align 16
  %338 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %335, i32 0, i32 1
  %339 = load i64, i64* %338, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %327, i16 noundef zeroext %328, i32 noundef %330, i64 noundef %337, i64 noundef %339, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext %334, i8 noundef zeroext 5) #4
  %340 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %91, align 8
  %341 = load i32, i32* %103, align 4
  %342 = load i32, i32* %104, align 4
  %343 = load i32, i32* %105, align 4
  %344 = load i32, i32* %106, align 4
  %345 = load i32, i32* %107, align 4
  %346 = load i8, i8* %108, align 1
  %347 = load i8, i8* %109, align 1
  %348 = load i8, i8* %110, align 1
  %349 = load i8, i8* %113, align 1
  %350 = load i8, i8* %114, align 1
  %351 = load i8, i8* %115, align 1
  %352 = load i8, i8* %116, align 1
  %353 = load i8, i8* %117, align 1
  %354 = load i8, i8* %118, align 1
  %355 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %340, i32 noundef %341, i32 noundef %342, i32 noundef %343, i32 noundef %344, i32 noundef %345, i8 noundef zeroext %346, i8 noundef zeroext 16, i8 noundef zeroext 0, i8 noundef zeroext %349, i8 noundef zeroext %350, i8 noundef zeroext %351, i8 noundef zeroext %352, i8 noundef zeroext %353, i8 noundef zeroext %354, i8 noundef zeroext 4) #4
  %356 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %199, align 8
  %357 = load double*, double** %191, align 8
  %358 = load double*, double** %190, align 8
  store %struct.DreExecutor_T* %356, %struct.DreExecutor_T** %1, align 8
  store double* %357, double** %2, align 8
  store double* %358, double** %3, align 8
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
  %359 = load double*, double** %2, align 8
  %360 = ptrtoint double* %359 to i64
  %361 = call i32 @convertToRelativeAddr(i64 noundef %360) #4
  store i32 %361, i32* %20, align 4
  store i32 0, i32* %21, align 4
  store i32 0, i32* %22, align 4
  %362 = load double*, double** %3, align 8
  %363 = ptrtoint double* %362 to i64
  %364 = call i32 @convertToRelativeAddr(i64 noundef %363) #4
  store i32 %364, i32* %23, align 4
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
  %365 = load i32, i32* %19, align 4
  %366 = icmp eq i32 %365, 0
  br i1 %366, label %367, label %368

367:                                              ; preds = %203
  br label %379

368:                                              ; preds = %203
  %369 = load i32, i32* %19, align 4
  %370 = icmp eq i32 %369, 1
  br i1 %370, label %371, label %372

371:                                              ; preds = %368
  br label %377

372:                                              ; preds = %368
  %373 = load i32, i32* %19, align 4
  %374 = icmp eq i32 %373, 2
  %375 = zext i1 %374 to i64
  %376 = select i1 %374, i32 6, i32 16
  br label %377

377:                                              ; preds = %372, %371
  %378 = phi i32 [ 5, %371 ], [ %376, %372 ]
  br label %379

379:                                              ; preds = %377, %367
  %380 = phi i32 [ 4, %367 ], [ %378, %377 ]
  %381 = trunc i32 %380 to i8
  store i8 %381, i8* %35, align 1
  %382 = bitcast [7 x i32]* %36 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %382, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false) #4
  %383 = getelementptr inbounds [7 x i32], [7 x i32]* %37, i64 0, i64 0
  %384 = load i32, i32* %4, align 4
  %385 = sub nsw i32 %384, 1
  store i32 %385, i32* %383, align 4
  %386 = getelementptr inbounds i32, i32* %383, i64 1
  %387 = load i32, i32* %6, align 4
  %388 = sub nsw i32 %387, 1
  store i32 %388, i32* %386, align 4
  %389 = getelementptr inbounds i32, i32* %386, i64 1
  %390 = load i32, i32* %5, align 4
  %391 = sub nsw i32 %390, 1
  store i32 %391, i32* %389, align 4
  %392 = getelementptr inbounds i32, i32* %389, i64 1
  store i32 0, i32* %392, align 4
  %393 = getelementptr inbounds i32, i32* %392, i64 1
  store i32 0, i32* %393, align 4
  %394 = getelementptr inbounds i32, i32* %393, i64 1
  %395 = load i32, i32* %4, align 4
  %396 = sub nsw i32 %395, 1
  store i32 %396, i32* %394, align 4
  %397 = getelementptr inbounds i32, i32* %394, i64 1
  %398 = load i32, i32* %5, align 4
  %399 = sub nsw i32 %398, 1
  store i32 %399, i32* %397, align 4
  %400 = getelementptr inbounds [7 x i32], [7 x i32]* %36, i64 0, i64 0
  %401 = getelementptr inbounds [7 x i32], [7 x i32]* %37, i64 0, i64 0
  %402 = call { i64, i64 } @setUpdateData(i32* noundef %400, i32* noundef %401, i32 noundef 7) #4
  %403 = bitcast i128* %39 to { i64, i64 }*
  %404 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %403, i32 0, i32 0
  %405 = extractvalue { i64, i64 } %402, 0
  store i64 %405, i64* %404, align 16
  %406 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %403, i32 0, i32 1
  %407 = extractvalue { i64, i64 } %402, 1
  store i64 %407, i64* %406, align 8
  %408 = load i128, i128* %39, align 16
  store i128 %408, i128* %38, align 16
  %409 = bitcast [7 x i32]* %40 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %409, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false) #4
  %410 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %411 = load i32, i32* %7, align 4
  %412 = sub nsw i32 %411, 1
  store i32 %412, i32* %410, align 4
  %413 = getelementptr inbounds i32, i32* %410, i64 1
  %414 = load i32, i32* %9, align 4
  %415 = sub nsw i32 %414, 1
  store i32 %415, i32* %413, align 4
  %416 = getelementptr inbounds i32, i32* %413, i64 1
  %417 = load i32, i32* %8, align 4
  %418 = sub nsw i32 %417, 1
  store i32 %418, i32* %416, align 4
  %419 = getelementptr inbounds i32, i32* %416, i64 1
  store i32 0, i32* %419, align 4
  %420 = getelementptr inbounds i32, i32* %419, i64 1
  store i32 0, i32* %420, align 4
  %421 = getelementptr inbounds i32, i32* %420, i64 1
  %422 = load i32, i32* %7, align 4
  %423 = sub nsw i32 %422, 1
  store i32 %423, i32* %421, align 4
  %424 = getelementptr inbounds i32, i32* %421, i64 1
  %425 = load i32, i32* %8, align 4
  %426 = sub nsw i32 %425, 1
  store i32 %426, i32* %424, align 4
  %427 = getelementptr inbounds [7 x i32], [7 x i32]* %40, i64 0, i64 0
  %428 = getelementptr inbounds [7 x i32], [7 x i32]* %41, i64 0, i64 0
  %429 = call { i64, i64 } @setUpdateData(i32* noundef %427, i32* noundef %428, i32 noundef 7) #4
  %430 = bitcast i128* %43 to { i64, i64 }*
  %431 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %430, i32 0, i32 0
  %432 = extractvalue { i64, i64 } %429, 0
  store i64 %432, i64* %431, align 16
  %433 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %430, i32 0, i32 1
  %434 = extractvalue { i64, i64 } %429, 1
  store i64 %434, i64* %433, align 8
  %435 = load i128, i128* %43, align 16
  store i128 %435, i128* %42, align 16
  %436 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %437 = load i16, i16* %28, align 2
  %438 = load i32, i32* %29, align 4
  %439 = load i128, i128* %38, align 16
  %440 = load i8, i8* %25, align 1
  store i128 %439, i128* %44, align 16
  %441 = bitcast i128* %44 to { i64, i64 }*
  %442 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %441, i32 0, i32 0
  %443 = load i64, i64* %442, align 16
  %444 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %441, i32 0, i32 1
  %445 = load i64, i64* %444, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %436, i16 noundef zeroext %437, i32 noundef %438, i64 noundef %443, i64 noundef %445, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9) #4
  %446 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %447 = load i16, i16* %28, align 2
  %448 = load i32, i32* %29, align 4
  %449 = add i32 %448, 3
  %450 = load i128, i128* %42, align 16
  %451 = load i8, i8* %25, align 1
  store i128 %450, i128* %45, align 16
  %452 = bitcast i128* %45 to { i64, i64 }*
  %453 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %452, i32 0, i32 0
  %454 = load i64, i64* %453, align 16
  %455 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %452, i32 0, i32 1
  %456 = load i64, i64* %455, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %446, i16 noundef zeroext %447, i32 noundef %449, i64 noundef %454, i64 noundef %456, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9) #4
  %457 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %1, align 8
  %458 = load i32, i32* %20, align 4
  %459 = load i32, i32* %21, align 4
  %460 = load i32, i32* %22, align 4
  %461 = load i32, i32* %23, align 4
  %462 = load i32, i32* %24, align 4
  %463 = load i8, i8* %25, align 1
  %464 = load i8, i8* %26, align 1
  %465 = load i8, i8* %27, align 1
  %466 = load i8, i8* %30, align 1
  %467 = load i8, i8* %31, align 1
  %468 = load i8, i8* %32, align 1
  %469 = load i8, i8* %33, align 1
  %470 = load i8, i8* %34, align 1
  %471 = load i8, i8* %35, align 1
  %472 = call i32 @Dre(%struct.DreExecutor_T* noundef %457, i32 noundef %458, i32 noundef %459, i32 noundef %460, i32 noundef %461, i32 noundef %462, i8 noundef zeroext %463, i8 noundef zeroext 0, i8 noundef zeroext 4, i8 noundef zeroext %466, i8 noundef zeroext %467, i8 noundef zeroext %468, i8 noundef zeroext %469, i8 noundef zeroext %470, i8 noundef zeroext %471, i8 noundef zeroext 8) #4
  %473 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %199, align 8
  %474 = load double*, double** %192, align 8
  %475 = load double*, double** %193, align 8
  store %struct.DreExecutor_T* %473, %struct.DreExecutor_T** %46, align 8
  store double* %474, double** %47, align 8
  store double* %475, double** %48, align 8
  store i32 0, i32* %49, align 4
  store i32 0, i32* %50, align 4
  store i32 0, i32* %51, align 4
  store i32 0, i32* %52, align 4
  store i32 0, i32* %53, align 4
  store i32 0, i32* %54, align 4
  store i32 0, i32* %55, align 4
  store i32 0, i32* %56, align 4
  store i32 0, i32* %57, align 4
  store i32 0, i32* %58, align 4
  store i32 0, i32* %59, align 4
  store i32 0, i32* %60, align 4
  store i32 0, i32* %61, align 4
  store i32 0, i32* %62, align 4
  store i32 0, i32* %63, align 4
  store i32 0, i32* %64, align 4
  %476 = load double*, double** %47, align 8
  %477 = ptrtoint double* %476 to i64
  %478 = call i32 @convertToRelativeAddr(i64 noundef %477) #4
  store i32 %478, i32* %65, align 4
  store i32 0, i32* %66, align 4
  store i32 0, i32* %67, align 4
  %479 = load double*, double** %48, align 8
  %480 = ptrtoint double* %479 to i64
  %481 = call i32 @convertToRelativeAddr(i64 noundef %480) #4
  store i32 %481, i32* %68, align 4
  store i32 0, i32* %69, align 4
  store i8 0, i8* %70, align 1
  store i8 2, i8* %71, align 1
  store i8 0, i8* %72, align 1
  store i16 -1, i16* %73, align 2
  store i32 0, i32* %74, align 4
  store i8 0, i8* %75, align 1
  store i8 1, i8* %76, align 1
  store i8 2, i8* %77, align 1
  store i8 3, i8* %78, align 1
  store i8 4, i8* %79, align 1
  %482 = load i32, i32* %64, align 4
  %483 = icmp eq i32 %482, 0
  br i1 %483, label %484, label %485

484:                                              ; preds = %379
  br label %496

485:                                              ; preds = %379
  %486 = load i32, i32* %64, align 4
  %487 = icmp eq i32 %486, 1
  br i1 %487, label %488, label %489

488:                                              ; preds = %485
  br label %494

489:                                              ; preds = %485
  %490 = load i32, i32* %64, align 4
  %491 = icmp eq i32 %490, 2
  %492 = zext i1 %491 to i64
  %493 = select i1 %491, i32 6, i32 16
  br label %494

494:                                              ; preds = %489, %488
  %495 = phi i32 [ 5, %488 ], [ %493, %489 ]
  br label %496

496:                                              ; preds = %494, %484
  %497 = phi i32 [ 4, %484 ], [ %495, %494 ]
  %498 = trunc i32 %497 to i8
  store i8 %498, i8* %80, align 1
  %499 = bitcast [7 x i32]* %81 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %499, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_src0 to i8*), i64 28, i1 false) #4
  %500 = getelementptr inbounds [7 x i32], [7 x i32]* %82, i64 0, i64 0
  %501 = load i32, i32* %49, align 4
  %502 = sub nsw i32 %501, 1
  store i32 %502, i32* %500, align 4
  %503 = getelementptr inbounds i32, i32* %500, i64 1
  %504 = load i32, i32* %51, align 4
  %505 = sub nsw i32 %504, 1
  store i32 %505, i32* %503, align 4
  %506 = getelementptr inbounds i32, i32* %503, i64 1
  %507 = load i32, i32* %50, align 4
  %508 = sub nsw i32 %507, 1
  store i32 %508, i32* %506, align 4
  %509 = getelementptr inbounds i32, i32* %506, i64 1
  store i32 0, i32* %509, align 4
  %510 = getelementptr inbounds i32, i32* %509, i64 1
  store i32 0, i32* %510, align 4
  %511 = getelementptr inbounds i32, i32* %510, i64 1
  %512 = load i32, i32* %49, align 4
  %513 = sub nsw i32 %512, 1
  store i32 %513, i32* %511, align 4
  %514 = getelementptr inbounds i32, i32* %511, i64 1
  %515 = load i32, i32* %50, align 4
  %516 = sub nsw i32 %515, 1
  store i32 %516, i32* %514, align 4
  %517 = getelementptr inbounds [7 x i32], [7 x i32]* %81, i64 0, i64 0
  %518 = getelementptr inbounds [7 x i32], [7 x i32]* %82, i64 0, i64 0
  %519 = call { i64, i64 } @setUpdateData(i32* noundef %517, i32* noundef %518, i32 noundef 7) #4
  %520 = bitcast i128* %84 to { i64, i64 }*
  %521 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %520, i32 0, i32 0
  %522 = extractvalue { i64, i64 } %519, 0
  store i64 %522, i64* %521, align 16
  %523 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %520, i32 0, i32 1
  %524 = extractvalue { i64, i64 } %519, 1
  store i64 %524, i64* %523, align 8
  %525 = load i128, i128* %84, align 16
  store i128 %525, i128* %83, align 16
  %526 = bitcast [7 x i32]* %85 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %526, i8* align 16 bitcast ([7 x i32]* @__const.simd_dre_executor_reshape.positions_dst0 to i8*), i64 28, i1 false) #4
  %527 = getelementptr inbounds [7 x i32], [7 x i32]* %86, i64 0, i64 0
  %528 = load i32, i32* %52, align 4
  %529 = sub nsw i32 %528, 1
  store i32 %529, i32* %527, align 4
  %530 = getelementptr inbounds i32, i32* %527, i64 1
  %531 = load i32, i32* %54, align 4
  %532 = sub nsw i32 %531, 1
  store i32 %532, i32* %530, align 4
  %533 = getelementptr inbounds i32, i32* %530, i64 1
  %534 = load i32, i32* %53, align 4
  %535 = sub nsw i32 %534, 1
  store i32 %535, i32* %533, align 4
  %536 = getelementptr inbounds i32, i32* %533, i64 1
  store i32 0, i32* %536, align 4
  %537 = getelementptr inbounds i32, i32* %536, i64 1
  store i32 0, i32* %537, align 4
  %538 = getelementptr inbounds i32, i32* %537, i64 1
  %539 = load i32, i32* %52, align 4
  %540 = sub nsw i32 %539, 1
  store i32 %540, i32* %538, align 4
  %541 = getelementptr inbounds i32, i32* %538, i64 1
  %542 = load i32, i32* %53, align 4
  %543 = sub nsw i32 %542, 1
  store i32 %543, i32* %541, align 4
  %544 = getelementptr inbounds [7 x i32], [7 x i32]* %85, i64 0, i64 0
  %545 = getelementptr inbounds [7 x i32], [7 x i32]* %86, i64 0, i64 0
  %546 = call { i64, i64 } @setUpdateData(i32* noundef %544, i32* noundef %545, i32 noundef 7) #4
  %547 = bitcast i128* %88 to { i64, i64 }*
  %548 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %547, i32 0, i32 0
  %549 = extractvalue { i64, i64 } %546, 0
  store i64 %549, i64* %548, align 16
  %550 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %547, i32 0, i32 1
  %551 = extractvalue { i64, i64 } %546, 1
  store i64 %551, i64* %550, align 8
  %552 = load i128, i128* %88, align 16
  store i128 %552, i128* %87, align 16
  %553 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %46, align 8
  %554 = load i16, i16* %73, align 2
  %555 = load i32, i32* %74, align 4
  %556 = load i128, i128* %83, align 16
  %557 = load i8, i8* %70, align 1
  store i128 %556, i128* %89, align 16
  %558 = bitcast i128* %89 to { i64, i64 }*
  %559 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %558, i32 0, i32 0
  %560 = load i64, i64* %559, align 16
  %561 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %558, i32 0, i32 1
  %562 = load i64, i64* %561, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %553, i16 noundef zeroext %554, i32 noundef %555, i64 noundef %560, i64 noundef %562, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9) #4
  %563 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %46, align 8
  %564 = load i16, i16* %73, align 2
  %565 = load i32, i32* %74, align 4
  %566 = add i32 %565, 3
  %567 = load i128, i128* %87, align 16
  %568 = load i8, i8* %70, align 1
  store i128 %567, i128* %90, align 16
  %569 = bitcast i128* %90 to { i64, i64 }*
  %570 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %569, i32 0, i32 0
  %571 = load i64, i64* %570, align 16
  %572 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %569, i32 0, i32 1
  %573 = load i64, i64* %572, align 8
  call void @simd_dre_init(%struct.DreExecutor_T* noundef %563, i16 noundef zeroext %564, i32 noundef %566, i64 noundef %571, i64 noundef %573, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext 9) #4
  %574 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %46, align 8
  %575 = load i32, i32* %65, align 4
  %576 = load i32, i32* %66, align 4
  %577 = load i32, i32* %67, align 4
  %578 = load i32, i32* %68, align 4
  %579 = load i32, i32* %69, align 4
  %580 = load i8, i8* %70, align 1
  %581 = load i8, i8* %71, align 1
  %582 = load i8, i8* %72, align 1
  %583 = load i8, i8* %75, align 1
  %584 = load i8, i8* %76, align 1
  %585 = load i8, i8* %77, align 1
  %586 = load i8, i8* %78, align 1
  %587 = load i8, i8* %79, align 1
  %588 = load i8, i8* %80, align 1
  %589 = call i32 @Dre(%struct.DreExecutor_T* noundef %574, i32 noundef %575, i32 noundef %576, i32 noundef %577, i32 noundef %578, i32 noundef %579, i8 noundef zeroext %580, i8 noundef zeroext 6, i8 noundef zeroext 0, i8 noundef zeroext %583, i8 noundef zeroext %584, i8 noundef zeroext %585, i8 noundef zeroext %586, i8 noundef zeroext %587, i8 noundef zeroext %588, i8 noundef zeroext 8) #4
  %590 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %198, align 8
  %591 = load double*, double** %192, align 8
  %592 = load double*, double** %193, align 8
  %593 = load double*, double** %194, align 8
  %594 = load i32, i32* %195, align 4
  %595 = load i32, i32* %196, align 4
  %596 = load i32, i32* %197, align 4
  store %struct.CoreExecutor_T* %590, %struct.CoreExecutor_T** %139, align 8
  store double* %591, double** %140, align 8
  store double* %592, double** %141, align 8
  store double* %593, double** %142, align 8
  store i32 %594, i32* %143, align 4
  store i32 %595, i32* %144, align 4
  store i32 %596, i32* %145, align 4
  store i32 0, i32* %146, align 4
  store i32 0, i32* %147, align 4
  store i32 0, i32* %148, align 4
  store double 1.000000e+00, double* %149, align 8
  store double 1.000000e+00, double* %150, align 8
  %597 = load double*, double** %140, align 8
  %598 = ptrtoint double* %597 to i64
  %599 = call i32 @convertToRelativeAddr(i64 noundef %598) #4
  store i32 %599, i32* %151, align 4
  %600 = load double*, double** %141, align 8
  %601 = ptrtoint double* %600 to i64
  %602 = call i32 @convertToRelativeAddr(i64 noundef %601) #4
  store i32 %602, i32* %152, align 4
  store i32 0, i32* %153, align 4
  %603 = load double*, double** %142, align 8
  %604 = ptrtoint double* %603 to i64
  %605 = call i32 @convertToRelativeAddr(i64 noundef %604) #4
  store i32 %605, i32* %154, align 4
  store i32 0, i32* %155, align 4
  store i8 0, i8* %156, align 1
  store i8 2, i8* %157, align 1
  store i8 0, i8* %158, align 1
  store i16 4369, i16* %159, align 2
  store i32 1, i32* %160, align 4
  store i8 1, i8* %161, align 1
  store i8 2, i8* %162, align 1
  store i8 0, i8* %163, align 1
  store i8 3, i8* %164, align 1
  store i8 4, i8* %165, align 1
  store i8 0, i8* %166, align 1
  %606 = bitcast [3 x i32]* %167 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %606, i8* align 4 bitcast ([3 x i32]* @__const.simd_gemm_executor_AB.positions_src0 to i8*), i64 12, i1 false) #4
  %607 = getelementptr inbounds [3 x i32], [3 x i32]* %168, i64 0, i64 0
  %608 = load i32, i32* %144, align 4
  store i32 %608, i32* %607, align 4
  %609 = getelementptr inbounds i32, i32* %607, i64 1
  %610 = load i32, i32* %143, align 4
  store i32 %610, i32* %609, align 4
  %611 = getelementptr inbounds i32, i32* %609, i64 1
  %612 = load i32, i32* %144, align 4
  %613 = add nsw i32 %612, 16
  %614 = sdiv i32 %613, 16
  %615 = sub nsw i32 %614, 1
  store i32 %615, i32* %611, align 4
  %616 = getelementptr inbounds [3 x i32], [3 x i32]* %167, i64 0, i64 0
  %617 = getelementptr inbounds [3 x i32], [3 x i32]* %168, i64 0, i64 0
  %618 = call { i64, i64 } @setUpdateData(i32* noundef %616, i32* noundef %617, i32 noundef 3) #4
  %619 = bitcast i128* %170 to { i64, i64 }*
  %620 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %619, i32 0, i32 0
  %621 = extractvalue { i64, i64 } %618, 0
  store i64 %621, i64* %620, align 16
  %622 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %619, i32 0, i32 1
  %623 = extractvalue { i64, i64 } %618, 1
  store i64 %623, i64* %622, align 8
  %624 = load i128, i128* %170, align 16
  store i128 %624, i128* %169, align 16
  %625 = bitcast [2 x i32]* %171 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %625, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_src1 to i8*), i64 8, i1 false) #4
  %626 = getelementptr inbounds [2 x i32], [2 x i32]* %172, i64 0, i64 0
  %627 = load i32, i32* %144, align 4
  store i32 %627, i32* %626, align 4
  %628 = getelementptr inbounds i32, i32* %626, i64 1
  %629 = load i32, i32* %145, align 4
  store i32 %629, i32* %628, align 4
  %630 = getelementptr inbounds [2 x i32], [2 x i32]* %171, i64 0, i64 0
  %631 = getelementptr inbounds [2 x i32], [2 x i32]* %172, i64 0, i64 0
  %632 = call { i64, i64 } @setUpdateData(i32* noundef %630, i32* noundef %631, i32 noundef 2) #4
  %633 = bitcast i128* %174 to { i64, i64 }*
  %634 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %633, i32 0, i32 0
  %635 = extractvalue { i64, i64 } %632, 0
  store i64 %635, i64* %634, align 16
  %636 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %633, i32 0, i32 1
  %637 = extractvalue { i64, i64 } %632, 1
  store i64 %637, i64* %636, align 8
  %638 = load i128, i128* %174, align 16
  store i128 %638, i128* %173, align 16
  %639 = bitcast [2 x i32]* %175 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %639, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_dst0 to i8*), i64 8, i1 false) #4
  %640 = getelementptr inbounds [2 x i32], [2 x i32]* %176, i64 0, i64 0
  %641 = load i32, i32* %143, align 4
  store i32 %641, i32* %640, align 4
  %642 = getelementptr inbounds i32, i32* %640, i64 1
  %643 = load i32, i32* %145, align 4
  store i32 %643, i32* %642, align 4
  %644 = getelementptr inbounds [2 x i32], [2 x i32]* %175, i64 0, i64 0
  %645 = getelementptr inbounds [2 x i32], [2 x i32]* %176, i64 0, i64 0
  %646 = call { i64, i64 } @setUpdateData(i32* noundef %644, i32* noundef %645, i32 noundef 2) #4
  %647 = bitcast i128* %178 to { i64, i64 }*
  %648 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %647, i32 0, i32 0
  %649 = extractvalue { i64, i64 } %646, 0
  store i64 %649, i64* %648, align 16
  %650 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %647, i32 0, i32 1
  %651 = extractvalue { i64, i64 } %646, 1
  store i64 %651, i64* %650, align 8
  %652 = load i128, i128* %178, align 16
  store i128 %652, i128* %177, align 16
  %653 = bitcast [2 x i32]* %179 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %653, i8* align 4 bitcast ([2 x i32]* @__const.simd_gemm_executor_AB.positions_func to i8*), i64 8, i1 false) #4
  %654 = getelementptr inbounds [2 x i32], [2 x i32]* %180, i64 0, i64 0
  %655 = load i32, i32* %144, align 4
  %656 = load i32, i32* %143, align 4
  %657 = mul nsw i32 %655, %656
  %658 = sdiv i32 %657, 128
  store i32 %658, i32* %654, align 4
  %659 = getelementptr inbounds i32, i32* %654, i64 1
  %660 = load i32, i32* %144, align 4
  %661 = load i32, i32* %145, align 4
  %662 = mul nsw i32 %660, %661
  %663 = sdiv i32 %662, 128
  store i32 %663, i32* %659, align 4
  %664 = getelementptr inbounds [2 x i32], [2 x i32]* %179, i64 0, i64 0
  %665 = getelementptr inbounds [2 x i32], [2 x i32]* %180, i64 0, i64 0
  %666 = call { i64, i64 } @setUpdateData(i32* noundef %664, i32* noundef %665, i32 noundef 2) #4
  %667 = bitcast i128* %182 to { i64, i64 }*
  %668 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %667, i32 0, i32 0
  %669 = extractvalue { i64, i64 } %666, 0
  store i64 %669, i64* %668, align 16
  %670 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %667, i32 0, i32 1
  %671 = extractvalue { i64, i64 } %666, 1
  store i64 %671, i64* %670, align 8
  %672 = load i128, i128* %182, align 16
  store i128 %672, i128* %181, align 16
  %673 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %139, align 8
  %674 = load i16, i16* %159, align 2
  %675 = load i32, i32* %160, align 4
  %676 = load i128, i128* %169, align 16
  %677 = load i8, i8* %156, align 1
  %678 = load i8, i8* %157, align 1
  %679 = load i8, i8* %158, align 1
  store i128 %676, i128* %183, align 16
  %680 = bitcast i128* %183 to { i64, i64 }*
  %681 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %680, i32 0, i32 0
  %682 = load i64, i64* %681, align 16
  %683 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %680, i32 0, i32 1
  %684 = load i64, i64* %683, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %673, i16 noundef zeroext %674, i32 noundef %675, i64 noundef %682, i64 noundef %684, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext %679, i8 noundef zeroext 5) #4
  %685 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %139, align 8
  %686 = load i16, i16* %159, align 2
  %687 = load i32, i32* %160, align 4
  %688 = add i32 %687, 1
  %689 = load i128, i128* %173, align 16
  %690 = load i8, i8* %156, align 1
  %691 = load i8, i8* %157, align 1
  %692 = load i8, i8* %158, align 1
  store i128 %689, i128* %184, align 16
  %693 = bitcast i128* %184 to { i64, i64 }*
  %694 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %693, i32 0, i32 0
  %695 = load i64, i64* %694, align 16
  %696 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %693, i32 0, i32 1
  %697 = load i64, i64* %696, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %685, i16 noundef zeroext %686, i32 noundef %688, i64 noundef %695, i64 noundef %697, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext %692, i8 noundef zeroext 5) #4
  %698 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %139, align 8
  %699 = load i16, i16* %159, align 2
  %700 = load i32, i32* %160, align 4
  %701 = add i32 %700, 2
  %702 = load i128, i128* %177, align 16
  %703 = load i8, i8* %156, align 1
  %704 = load i8, i8* %157, align 1
  %705 = load i8, i8* %158, align 1
  store i128 %702, i128* %185, align 16
  %706 = bitcast i128* %185 to { i64, i64 }*
  %707 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %706, i32 0, i32 0
  %708 = load i64, i64* %707, align 16
  %709 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %706, i32 0, i32 1
  %710 = load i64, i64* %709, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %698, i16 noundef zeroext %699, i32 noundef %701, i64 noundef %708, i64 noundef %710, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext %705, i8 noundef zeroext 5) #4
  %711 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %139, align 8
  %712 = load i16, i16* %159, align 2
  %713 = load i32, i32* %160, align 4
  %714 = add i32 %713, 3
  %715 = load i128, i128* %181, align 16
  %716 = load i8, i8* %156, align 1
  %717 = load i8, i8* %157, align 1
  %718 = load i8, i8* %158, align 1
  store i128 %715, i128* %186, align 16
  %719 = bitcast i128* %186 to { i64, i64 }*
  %720 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %719, i32 0, i32 0
  %721 = load i64, i64* %720, align 16
  %722 = getelementptr inbounds { i64, i64 }, { i64, i64 }* %719, i32 0, i32 1
  %723 = load i64, i64* %722, align 8
  call void @simd_gemm_init(%struct.CoreExecutor_T* noundef %711, i16 noundef zeroext %712, i32 noundef %714, i64 noundef %721, i64 noundef %723, i8 noundef zeroext 0, i8 noundef zeroext 0, i8 noundef zeroext %718, i8 noundef zeroext 5) #4
  %724 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %139, align 8
  %725 = load i32, i32* %151, align 4
  %726 = load i32, i32* %152, align 4
  %727 = load i32, i32* %153, align 4
  %728 = load i32, i32* %154, align 4
  %729 = load i32, i32* %155, align 4
  %730 = load i8, i8* %156, align 1
  %731 = load i8, i8* %157, align 1
  %732 = load i8, i8* %158, align 1
  %733 = load i8, i8* %161, align 1
  %734 = load i8, i8* %162, align 1
  %735 = load i8, i8* %163, align 1
  %736 = load i8, i8* %164, align 1
  %737 = load i8, i8* %165, align 1
  %738 = load i8, i8* %166, align 1
  %739 = call i32 @Gemm(%struct.CoreExecutor_T* noundef %724, i32 noundef %725, i32 noundef %726, i32 noundef %727, i32 noundef %728, i32 noundef %729, i8 noundef zeroext %730, i8 noundef zeroext 2, i8 noundef zeroext 16, i8 noundef zeroext %733, i8 noundef zeroext %734, i8 noundef zeroext %735, i8 noundef zeroext %736, i8 noundef zeroext %737, i8 noundef zeroext %738, i8 noundef zeroext 4) #4
  store i32 0, i32* %187, align 4
  %740 = load i32, i32* %187, align 4
  %741 = icmp eq i32 %740, 0
  br i1 %741, label %742, label %743

742:                                              ; preds = %496
  call void @simd_major_finish(i8 noundef zeroext 0, i8 noundef zeroext 20) #4
  br label %743

743:                                              ; preds = %742, %496
  %744 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %198, align 8
  call void @simd_gemm_executor_release(%struct.CoreExecutor_T* noundef %744)
  %745 = load %struct.DreExecutor_T*, %struct.DreExecutor_T** %199, align 8
  call void @simd_dre_executor_release(%struct.DreExecutor_T* noundef %745)
  br label %746

746:                                              ; preds = %743
  %747 = load i32, i32* %188, align 4
  ret i32 %747
}

declare i32 @printf(i8* noundef, ...) #0

declare %struct.CoreExecutor_T* @simd_gemm_executor_create(...) #0

declare %struct.DreExecutor_T* @simd_dre_executor_create(...) #0

declare void @simd_gemm_executor_initialize(%struct.CoreExecutor_T* noundef) #0

declare void @simd_dre_executor_initialize(%struct.DreExecutor_T* noundef) #0

declare void @reg2sch_start_set(i8 noundef zeroext) #0

declare void @simd_gemm_executor_release(%struct.CoreExecutor_T* noundef) #0

declare void @simd_dre_executor_release(%struct.DreExecutor_T* noundef) #0

attributes #0 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { argmemonly nofree nounwind willreturn }
attributes #2 = { argmemonly nofree nounwind willreturn writeonly }
attributes #3 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
