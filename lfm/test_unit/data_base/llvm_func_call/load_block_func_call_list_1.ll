; ModuleID = 'test_c.c'
source_filename = "test_c.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.CoreExecutor_T = type { i32 }

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @foo(double* noundef %0, double* noundef %1, double* noundef %2, i32 noundef %3, i32 noundef %4, i32 noundef %5) #0 !dbg !10 {
  %7 = alloca double*, align 8
  %8 = alloca double*, align 8
  %9 = alloca double*, align 8
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca %struct.CoreExecutor_T*, align 8
  store double* %0, double** %7, align 8
  call void @llvm.dbg.declare(metadata double** %7, metadata !17, metadata !DIExpression()), !dbg !18
  store double* %1, double** %8, align 8
  call void @llvm.dbg.declare(metadata double** %8, metadata !19, metadata !DIExpression()), !dbg !20
  store double* %2, double** %9, align 8
  call void @llvm.dbg.declare(metadata double** %9, metadata !21, metadata !DIExpression()), !dbg !22
  store i32 %3, i32* %10, align 4
  call void @llvm.dbg.declare(metadata i32* %10, metadata !23, metadata !DIExpression()), !dbg !24
  store i32 %4, i32* %11, align 4
  call void @llvm.dbg.declare(metadata i32* %11, metadata !25, metadata !DIExpression()), !dbg !26
  store i32 %5, i32* %12, align 4
  call void @llvm.dbg.declare(metadata i32* %12, metadata !27, metadata !DIExpression()), !dbg !28
  call void @llvm.dbg.declare(metadata %struct.CoreExecutor_T** %13, metadata !29, metadata !DIExpression()), !dbg !36
  %14 = call %struct.CoreExecutor_T* (...) @simd_gemm_executor_create(), !dbg !37
  store %struct.CoreExecutor_T* %14, %struct.CoreExecutor_T** %13, align 8, !dbg !38
  %15 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8, !dbg !39
  %16 = load double*, double** %7, align 8, !dbg !40
  %17 = load double*, double** %8, align 8, !dbg !41
  %18 = load double*, double** %9, align 8, !dbg !42
  %19 = load i32, i32* %10, align 4, !dbg !43
  %20 = load i32, i32* %11, align 4, !dbg !44
  %21 = load i32, i32* %12, align 4, !dbg !45
  %22 = call i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T* noundef %15, double* noundef %16, double* noundef %17, double* noundef %18, i32 noundef %19, i32 noundef %20, i32 noundef %21, i32 noundef 0, i32 noundef 0, i32 noundef 0, double noundef 1.000000e+00, double noundef 1.000000e+00), !dbg !46
  %23 = load %struct.CoreExecutor_T*, %struct.CoreExecutor_T** %13, align 8, !dbg !47
  %24 = bitcast %struct.CoreExecutor_T* %23 to i8*, !dbg !47
  call void @free(i8* noundef %24) #4, !dbg !48
  ret void, !dbg !49
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare %struct.CoreExecutor_T* @simd_gemm_executor_create(...) #2

declare i32 @simd_gemm_executor_AB(%struct.CoreExecutor_T* noundef, double* noundef, double* noundef, double* noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, double noundef, double noundef) #2

; Function Attrs: nounwind
declare void @free(i8* noundef) #3

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 14.0.6", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "test_c.c", directory: "/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC231225A", checksumkind: CSK_MD5, checksum: "a4dc768ea119d0018e27a29f2b2d8b77")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 2}
!9 = !{!"Ubuntu clang version 14.0.6"}
!10 = distinct !DISubprogram(name: "foo", scope: !1, file: !1, line: 6, type: !11, scopeLine: 6, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !16)
!11 = !DISubroutineType(types: !12)
!12 = !{null, !13, !13, !13, !15, !15, !15}
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !14, size: 64)
!14 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!15 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!16 = !{}
!17 = !DILocalVariable(name: "A", arg: 1, scope: !10, file: !1, line: 6, type: !13)
!18 = !DILocation(line: 6, column: 18, scope: !10)
!19 = !DILocalVariable(name: "B", arg: 2, scope: !10, file: !1, line: 6, type: !13)
!20 = !DILocation(line: 6, column: 29, scope: !10)
!21 = !DILocalVariable(name: "C", arg: 3, scope: !10, file: !1, line: 6, type: !13)
!22 = !DILocation(line: 6, column: 40, scope: !10)
!23 = !DILocalVariable(name: "m", arg: 4, scope: !10, file: !1, line: 6, type: !15)
!24 = !DILocation(line: 6, column: 47, scope: !10)
!25 = !DILocalVariable(name: "k", arg: 5, scope: !10, file: !1, line: 6, type: !15)
!26 = !DILocation(line: 6, column: 54, scope: !10)
!27 = !DILocalVariable(name: "n", arg: 6, scope: !10, file: !1, line: 6, type: !15)
!28 = !DILocation(line: 6, column: 61, scope: !10)
!29 = !DILocalVariable(name: "gemm_executor", scope: !10, file: !1, line: 8, type: !30)
!30 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !31, size: 64)
!31 = !DIDerivedType(tag: DW_TAG_typedef, name: "CoreExecutor", file: !32, line: 10, baseType: !33)
!32 = !DIFile(filename: "../../include_0/simd_gemm.h", directory: "/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC231225A", checksumkind: CSK_MD5, checksum: "c9ae9c209fcfa6dfc5ee9e090567ef5c")
!33 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "CoreExecutor_T", file: !32, line: 10, size: 32, elements: !34)
!34 = !{!35}
!35 = !DIDerivedType(tag: DW_TAG_member, name: "val", scope: !33, file: !32, line: 10, baseType: !15, size: 32)
!36 = !DILocation(line: 8, column: 19, scope: !10)
!37 = !DILocation(line: 9, column: 21, scope: !10)
!38 = !DILocation(line: 9, column: 19, scope: !10)
!39 = !DILocation(line: 12, column: 27, scope: !10)
!40 = !DILocation(line: 12, column: 42, scope: !10)
!41 = !DILocation(line: 12, column: 45, scope: !10)
!42 = !DILocation(line: 12, column: 48, scope: !10)
!43 = !DILocation(line: 12, column: 51, scope: !10)
!44 = !DILocation(line: 12, column: 54, scope: !10)
!45 = !DILocation(line: 12, column: 57, scope: !10)
!46 = !DILocation(line: 12, column: 5, scope: !10)
!47 = !DILocation(line: 15, column: 10, scope: !10)
!48 = !DILocation(line: 15, column: 5, scope: !10)
!49 = !DILocation(line: 16, column: 1, scope: !10)
