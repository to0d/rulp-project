; ModuleID = 'input.cpp'
source_filename = "input.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@simd_block = external global i32, align 4
@.str = private unnamed_addr constant [7 x i8] c"hello\0A\00", align 1
@x = external global i32, align 4
@.str.1 = private unnamed_addr constant [5 x i8] c"xxx\0A\00", align 1
@y = external global i32, align 4
@.str.2 = private unnamed_addr constant [5 x i8] c"yyy\0A\00", align 1
@.str.3 = private unnamed_addr constant [6 x i8] c"y=%d\0A\00", align 1

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z3foov() #0 !dbg !256 {
  %1 = alloca i32, align 4
  %2 = load i32, i32* @simd_block, align 4, !dbg !258
  %3 = icmp ne i32 %2, 0, !dbg !258
  br i1 %3, label %4, label %28, !dbg !260

4:                                                ; preds = %0
  %5 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([7 x i8], [7 x i8]* @.str, i64 0, i64 0)), !dbg !261
  %6 = load i32, i32* @x, align 4, !dbg !263
  %7 = icmp sgt i32 %6, 0, !dbg !265
  br i1 %7, label %8, label %15, !dbg !266

8:                                                ; preds = %4
  %9 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0)), !dbg !267
  %10 = load i32, i32* @y, align 4, !dbg !269
  %11 = icmp sgt i32 %10, 0, !dbg !271
  br i1 %11, label %12, label %14, !dbg !272

12:                                               ; preds = %8
  %13 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0)), !dbg !273
  br label %14, !dbg !275

14:                                               ; preds = %12, %8
  br label %15, !dbg !276

15:                                               ; preds = %14, %4
  call void @llvm.dbg.declare(metadata i32* %1, metadata !277, metadata !DIExpression()), !dbg !279
  store i32 0, i32* %1, align 4, !dbg !279
  br label %16, !dbg !280

16:                                               ; preds = %22, %15
  %17 = load i32, i32* %1, align 4, !dbg !281
  %18 = icmp slt i32 %17, 10, !dbg !283
  br i1 %18, label %19, label %25, !dbg !284

19:                                               ; preds = %16
  %20 = load i32, i32* @y, align 4, !dbg !285
  %21 = add nsw i32 %20, 10, !dbg !285
  store i32 %21, i32* @y, align 4, !dbg !285
  br label %22, !dbg !286

22:                                               ; preds = %19
  %23 = load i32, i32* %1, align 4, !dbg !287
  %24 = add nsw i32 %23, 1, !dbg !287
  store i32 %24, i32* %1, align 4, !dbg !287
  br label %16, !dbg !288, !llvm.loop !289

25:                                               ; preds = %16
  %26 = load i32, i32* @y, align 4, !dbg !292
  %27 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([6 x i8], [6 x i8]* @.str.3, i64 0, i64 0), i32 noundef %26), !dbg !293
  br label %28, !dbg !294

28:                                               ; preds = %25, %0
  %29 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0)), !dbg !295
  %30 = load i32, i32* @y, align 4, !dbg !296
  %31 = icmp sgt i32 %30, 0, !dbg !298
  br i1 %31, label %32, label %34, !dbg !299

32:                                               ; preds = %28
  %33 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0)), !dbg !300
  br label %34, !dbg !302

34:                                               ; preds = %32, %28
  %35 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0)), !dbg !303
  ret void, !dbg !304
}

declare i32 @printf(i8* noundef, ...) #1

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #2

attributes #0 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!248, !249, !250, !251, !252, !253, !254}
!llvm.ident = !{!255}

!0 = distinct !DICompileUnit(language: DW_LANG_C_plus_plus_14, file: !1, producer: "Ubuntu clang version 14.0.0-1ubuntu1.1", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, imports: !2, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "input.cpp", directory: "/mnt/c/data/work_thu/code_thu/lfc/scc/test_func/TC231229B", checksumkind: CSK_MD5, checksum: "c5524c127a76b2af3aaf960ef343d832")
!2 = !{!3, !11, !15, !22, !26, !31, !33, !41, !45, !49, !63, !67, !71, !75, !79, !84, !88, !92, !96, !100, !108, !112, !116, !118, !122, !126, !131, !137, !141, !145, !147, !155, !159, !167, !169, !173, !177, !181, !185, !190, !195, !200, !201, !202, !203, !205, !206, !207, !208, !209, !210, !211, !213, !214, !215, !216, !217, !218, !219, !224, !225, !226, !227, !228, !229, !230, !231, !232, !233, !234, !235, !236, !237, !238, !239, !240, !241, !242, !243, !244, !245, !246, !247}
!3 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !5, file: !10, line: 52)
!4 = !DINamespace(name: "std", scope: null)
!5 = !DISubprogram(name: "abs", scope: !6, file: !6, line: 848, type: !7, flags: DIFlagPrototyped, spFlags: 0)
!6 = !DIFile(filename: "/usr/include/stdlib.h", directory: "", checksumkind: CSK_MD5, checksum: "02258fad21adf111bb9df9825e61954a")
!7 = !DISubroutineType(types: !8)
!8 = !{!9, !9}
!9 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!10 = !DIFile(filename: "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/bits/std_abs.h", directory: "")
!11 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !12, file: !14, line: 127)
!12 = !DIDerivedType(tag: DW_TAG_typedef, name: "div_t", file: !6, line: 63, baseType: !13)
!13 = !DICompositeType(tag: DW_TAG_structure_type, file: !6, line: 59, size: 64, flags: DIFlagFwdDecl, identifier: "_ZTS5div_t")
!14 = !DIFile(filename: "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/cstdlib", directory: "")
!15 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !16, file: !14, line: 128)
!16 = !DIDerivedType(tag: DW_TAG_typedef, name: "ldiv_t", file: !6, line: 71, baseType: !17)
!17 = distinct !DICompositeType(tag: DW_TAG_structure_type, file: !6, line: 67, size: 128, flags: DIFlagTypePassByValue, elements: !18, identifier: "_ZTS6ldiv_t")
!18 = !{!19, !21}
!19 = !DIDerivedType(tag: DW_TAG_member, name: "quot", scope: !17, file: !6, line: 69, baseType: !20, size: 64)
!20 = !DIBasicType(name: "long", size: 64, encoding: DW_ATE_signed)
!21 = !DIDerivedType(tag: DW_TAG_member, name: "rem", scope: !17, file: !6, line: 70, baseType: !20, size: 64, offset: 64)
!22 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !23, file: !14, line: 130)
!23 = !DISubprogram(name: "abort", scope: !6, file: !6, line: 598, type: !24, flags: DIFlagPrototyped | DIFlagNoReturn, spFlags: 0)
!24 = !DISubroutineType(types: !25)
!25 = !{null}
!26 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !27, file: !14, line: 134)
!27 = !DISubprogram(name: "atexit", scope: !6, file: !6, line: 602, type: !28, flags: DIFlagPrototyped, spFlags: 0)
!28 = !DISubroutineType(types: !29)
!29 = !{!9, !30}
!30 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !24, size: 64)
!31 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !32, file: !14, line: 137)
!32 = !DISubprogram(name: "at_quick_exit", scope: !6, file: !6, line: 607, type: !28, flags: DIFlagPrototyped, spFlags: 0)
!33 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !34, file: !14, line: 140)
!34 = !DISubprogram(name: "atof", scope: !6, file: !6, line: 102, type: !35, flags: DIFlagPrototyped, spFlags: 0)
!35 = !DISubroutineType(types: !36)
!36 = !{!37, !38}
!37 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!38 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !39, size: 64)
!39 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !40)
!40 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!41 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !42, file: !14, line: 141)
!42 = !DISubprogram(name: "atoi", scope: !6, file: !6, line: 105, type: !43, flags: DIFlagPrototyped, spFlags: 0)
!43 = !DISubroutineType(types: !44)
!44 = !{!9, !38}
!45 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !46, file: !14, line: 142)
!46 = !DISubprogram(name: "atol", scope: !6, file: !6, line: 108, type: !47, flags: DIFlagPrototyped, spFlags: 0)
!47 = !DISubroutineType(types: !48)
!48 = !{!20, !38}
!49 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !50, file: !14, line: 143)
!50 = !DISubprogram(name: "bsearch", scope: !6, file: !6, line: 828, type: !51, flags: DIFlagPrototyped, spFlags: 0)
!51 = !DISubroutineType(types: !52)
!52 = !{!53, !54, !54, !56, !56, !59}
!53 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!54 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !55, size: 64)
!55 = !DIDerivedType(tag: DW_TAG_const_type, baseType: null)
!56 = !DIDerivedType(tag: DW_TAG_typedef, name: "size_t", file: !57, line: 46, baseType: !58)
!57 = !DIFile(filename: "/usr/lib/llvm-14/lib/clang/14.0.0/include/stddef.h", directory: "", checksumkind: CSK_MD5, checksum: "2499dd2361b915724b073282bea3a7bc")
!58 = !DIBasicType(name: "unsigned long", size: 64, encoding: DW_ATE_unsigned)
!59 = !DIDerivedType(tag: DW_TAG_typedef, name: "__compar_fn_t", file: !6, line: 816, baseType: !60)
!60 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !61, size: 64)
!61 = !DISubroutineType(types: !62)
!62 = !{!9, !54, !54}
!63 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !64, file: !14, line: 144)
!64 = !DISubprogram(name: "calloc", scope: !6, file: !6, line: 543, type: !65, flags: DIFlagPrototyped, spFlags: 0)
!65 = !DISubroutineType(types: !66)
!66 = !{!53, !56, !56}
!67 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !68, file: !14, line: 145)
!68 = !DISubprogram(name: "div", scope: !6, file: !6, line: 860, type: !69, flags: DIFlagPrototyped, spFlags: 0)
!69 = !DISubroutineType(types: !70)
!70 = !{!12, !9, !9}
!71 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !72, file: !14, line: 146)
!72 = !DISubprogram(name: "exit", scope: !6, file: !6, line: 624, type: !73, flags: DIFlagPrototyped | DIFlagNoReturn, spFlags: 0)
!73 = !DISubroutineType(types: !74)
!74 = !{null, !9}
!75 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !76, file: !14, line: 147)
!76 = !DISubprogram(name: "free", scope: !6, file: !6, line: 555, type: !77, flags: DIFlagPrototyped, spFlags: 0)
!77 = !DISubroutineType(types: !78)
!78 = !{null, !53}
!79 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !80, file: !14, line: 148)
!80 = !DISubprogram(name: "getenv", scope: !6, file: !6, line: 641, type: !81, flags: DIFlagPrototyped, spFlags: 0)
!81 = !DISubroutineType(types: !82)
!82 = !{!83, !38}
!83 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !40, size: 64)
!84 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !85, file: !14, line: 149)
!85 = !DISubprogram(name: "labs", scope: !6, file: !6, line: 849, type: !86, flags: DIFlagPrototyped, spFlags: 0)
!86 = !DISubroutineType(types: !87)
!87 = !{!20, !20}
!88 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !89, file: !14, line: 150)
!89 = !DISubprogram(name: "ldiv", scope: !6, file: !6, line: 862, type: !90, flags: DIFlagPrototyped, spFlags: 0)
!90 = !DISubroutineType(types: !91)
!91 = !{!16, !20, !20}
!92 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !93, file: !14, line: 151)
!93 = !DISubprogram(name: "malloc", scope: !6, file: !6, line: 540, type: !94, flags: DIFlagPrototyped, spFlags: 0)
!94 = !DISubroutineType(types: !95)
!95 = !{!53, !56}
!96 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !97, file: !14, line: 153)
!97 = !DISubprogram(name: "mblen", scope: !6, file: !6, line: 930, type: !98, flags: DIFlagPrototyped, spFlags: 0)
!98 = !DISubroutineType(types: !99)
!99 = !{!9, !38, !56}
!100 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !101, file: !14, line: 154)
!101 = !DISubprogram(name: "mbstowcs", scope: !6, file: !6, line: 941, type: !102, flags: DIFlagPrototyped, spFlags: 0)
!102 = !DISubroutineType(types: !103)
!103 = !{!56, !104, !107, !56}
!104 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !105)
!105 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !106, size: 64)
!106 = !DIBasicType(name: "wchar_t", size: 32, encoding: DW_ATE_signed)
!107 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !38)
!108 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !109, file: !14, line: 155)
!109 = !DISubprogram(name: "mbtowc", scope: !6, file: !6, line: 933, type: !110, flags: DIFlagPrototyped, spFlags: 0)
!110 = !DISubroutineType(types: !111)
!111 = !{!9, !104, !107, !56}
!112 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !113, file: !14, line: 157)
!113 = !DISubprogram(name: "qsort", scope: !6, file: !6, line: 838, type: !114, flags: DIFlagPrototyped, spFlags: 0)
!114 = !DISubroutineType(types: !115)
!115 = !{null, !53, !56, !56, !59}
!116 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !117, file: !14, line: 160)
!117 = !DISubprogram(name: "quick_exit", scope: !6, file: !6, line: 630, type: !73, flags: DIFlagPrototyped | DIFlagNoReturn, spFlags: 0)
!118 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !119, file: !14, line: 163)
!119 = !DISubprogram(name: "rand", scope: !6, file: !6, line: 454, type: !120, flags: DIFlagPrototyped, spFlags: 0)
!120 = !DISubroutineType(types: !121)
!121 = !{!9}
!122 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !123, file: !14, line: 164)
!123 = !DISubprogram(name: "realloc", scope: !6, file: !6, line: 551, type: !124, flags: DIFlagPrototyped, spFlags: 0)
!124 = !DISubroutineType(types: !125)
!125 = !{!53, !53, !56}
!126 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !127, file: !14, line: 165)
!127 = !DISubprogram(name: "srand", scope: !6, file: !6, line: 456, type: !128, flags: DIFlagPrototyped, spFlags: 0)
!128 = !DISubroutineType(types: !129)
!129 = !{null, !130}
!130 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!131 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !132, file: !14, line: 166)
!132 = !DISubprogram(name: "strtod", scope: !6, file: !6, line: 118, type: !133, flags: DIFlagPrototyped, spFlags: 0)
!133 = !DISubroutineType(types: !134)
!134 = !{!37, !107, !135}
!135 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !136)
!136 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !83, size: 64)
!137 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !138, file: !14, line: 167)
!138 = !DISubprogram(name: "strtol", scope: !6, file: !6, line: 177, type: !139, flags: DIFlagPrototyped, spFlags: 0)
!139 = !DISubroutineType(types: !140)
!140 = !{!20, !107, !135, !9}
!141 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !142, file: !14, line: 168)
!142 = !DISubprogram(name: "strtoul", scope: !6, file: !6, line: 181, type: !143, flags: DIFlagPrototyped, spFlags: 0)
!143 = !DISubroutineType(types: !144)
!144 = !{!58, !107, !135, !9}
!145 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !146, file: !14, line: 169)
!146 = !DISubprogram(name: "system", scope: !6, file: !6, line: 791, type: !43, flags: DIFlagPrototyped, spFlags: 0)
!147 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !148, file: !14, line: 171)
!148 = !DISubprogram(name: "wcstombs", scope: !6, file: !6, line: 945, type: !149, flags: DIFlagPrototyped, spFlags: 0)
!149 = !DISubroutineType(types: !150)
!150 = !{!56, !151, !152, !56}
!151 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !83)
!152 = !DIDerivedType(tag: DW_TAG_restrict_type, baseType: !153)
!153 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !154, size: 64)
!154 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !106)
!155 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !156, file: !14, line: 172)
!156 = !DISubprogram(name: "wctomb", scope: !6, file: !6, line: 937, type: !157, flags: DIFlagPrototyped, spFlags: 0)
!157 = !DISubroutineType(types: !158)
!158 = !{!9, !83, !106}
!159 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !161, file: !14, line: 200)
!160 = !DINamespace(name: "__gnu_cxx", scope: null)
!161 = !DIDerivedType(tag: DW_TAG_typedef, name: "lldiv_t", file: !6, line: 81, baseType: !162)
!162 = distinct !DICompositeType(tag: DW_TAG_structure_type, file: !6, line: 77, size: 128, flags: DIFlagTypePassByValue, elements: !163, identifier: "_ZTS7lldiv_t")
!163 = !{!164, !166}
!164 = !DIDerivedType(tag: DW_TAG_member, name: "quot", scope: !162, file: !6, line: 79, baseType: !165, size: 64)
!165 = !DIBasicType(name: "long long", size: 64, encoding: DW_ATE_signed)
!166 = !DIDerivedType(tag: DW_TAG_member, name: "rem", scope: !162, file: !6, line: 80, baseType: !165, size: 64, offset: 64)
!167 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !168, file: !14, line: 206)
!168 = !DISubprogram(name: "_Exit", scope: !6, file: !6, line: 636, type: !73, flags: DIFlagPrototyped | DIFlagNoReturn, spFlags: 0)
!169 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !170, file: !14, line: 210)
!170 = !DISubprogram(name: "llabs", scope: !6, file: !6, line: 852, type: !171, flags: DIFlagPrototyped, spFlags: 0)
!171 = !DISubroutineType(types: !172)
!172 = !{!165, !165}
!173 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !174, file: !14, line: 216)
!174 = !DISubprogram(name: "lldiv", scope: !6, file: !6, line: 866, type: !175, flags: DIFlagPrototyped, spFlags: 0)
!175 = !DISubroutineType(types: !176)
!176 = !{!161, !165, !165}
!177 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !178, file: !14, line: 227)
!178 = !DISubprogram(name: "atoll", scope: !6, file: !6, line: 113, type: !179, flags: DIFlagPrototyped, spFlags: 0)
!179 = !DISubroutineType(types: !180)
!180 = !{!165, !38}
!181 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !182, file: !14, line: 228)
!182 = !DISubprogram(name: "strtoll", scope: !6, file: !6, line: 201, type: !183, flags: DIFlagPrototyped, spFlags: 0)
!183 = !DISubroutineType(types: !184)
!184 = !{!165, !107, !135, !9}
!185 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !186, file: !14, line: 229)
!186 = !DISubprogram(name: "strtoull", scope: !6, file: !6, line: 206, type: !187, flags: DIFlagPrototyped, spFlags: 0)
!187 = !DISubroutineType(types: !188)
!188 = !{!189, !107, !135, !9}
!189 = !DIBasicType(name: "unsigned long long", size: 64, encoding: DW_ATE_unsigned)
!190 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !191, file: !14, line: 231)
!191 = !DISubprogram(name: "strtof", scope: !6, file: !6, line: 124, type: !192, flags: DIFlagPrototyped, spFlags: 0)
!192 = !DISubroutineType(types: !193)
!193 = !{!194, !107, !135}
!194 = !DIBasicType(name: "float", size: 32, encoding: DW_ATE_float)
!195 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !160, entity: !196, file: !14, line: 232)
!196 = !DISubprogram(name: "strtold", scope: !6, file: !6, line: 127, type: !197, flags: DIFlagPrototyped, spFlags: 0)
!197 = !DISubroutineType(types: !198)
!198 = !{!199, !107, !135}
!199 = !DIBasicType(name: "long double", size: 128, encoding: DW_ATE_float)
!200 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !161, file: !14, line: 240)
!201 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !168, file: !14, line: 242)
!202 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !170, file: !14, line: 244)
!203 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !204, file: !14, line: 245)
!204 = !DISubprogram(name: "div", linkageName: "_ZN9__gnu_cxx3divExx", scope: !160, file: !14, line: 213, type: !175, flags: DIFlagPrototyped, spFlags: 0)
!205 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !174, file: !14, line: 246)
!206 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !178, file: !14, line: 248)
!207 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !191, file: !14, line: 249)
!208 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !182, file: !14, line: 250)
!209 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !186, file: !14, line: 251)
!210 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !4, entity: !196, file: !14, line: 252)
!211 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !23, file: !212, line: 38)
!212 = !DIFile(filename: "/usr/bin/../lib/gcc/x86_64-linux-gnu/11/../../../../include/c++/11/stdlib.h", directory: "", checksumkind: CSK_MD5, checksum: "0f5b773a303c24013fb112082e6d18a5")
!213 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !27, file: !212, line: 39)
!214 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !72, file: !212, line: 40)
!215 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !32, file: !212, line: 43)
!216 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !117, file: !212, line: 46)
!217 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !12, file: !212, line: 51)
!218 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !16, file: !212, line: 52)
!219 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !220, file: !212, line: 54)
!220 = !DISubprogram(name: "abs", linkageName: "_ZSt3absg", scope: !4, file: !10, line: 103, type: !221, flags: DIFlagPrototyped, spFlags: 0)
!221 = !DISubroutineType(types: !222)
!222 = !{!223, !223}
!223 = !DIBasicType(name: "__float128", size: 128, encoding: DW_ATE_float)
!224 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !34, file: !212, line: 55)
!225 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !42, file: !212, line: 56)
!226 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !46, file: !212, line: 57)
!227 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !50, file: !212, line: 58)
!228 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !64, file: !212, line: 59)
!229 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !204, file: !212, line: 60)
!230 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !76, file: !212, line: 61)
!231 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !80, file: !212, line: 62)
!232 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !85, file: !212, line: 63)
!233 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !89, file: !212, line: 64)
!234 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !93, file: !212, line: 65)
!235 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !97, file: !212, line: 67)
!236 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !101, file: !212, line: 68)
!237 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !109, file: !212, line: 69)
!238 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !113, file: !212, line: 71)
!239 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !119, file: !212, line: 72)
!240 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !123, file: !212, line: 73)
!241 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !127, file: !212, line: 74)
!242 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !132, file: !212, line: 75)
!243 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !138, file: !212, line: 76)
!244 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !142, file: !212, line: 77)
!245 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !146, file: !212, line: 78)
!246 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !148, file: !212, line: 80)
!247 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !0, entity: !156, file: !212, line: 81)
!248 = !{i32 7, !"Dwarf Version", i32 5}
!249 = !{i32 2, !"Debug Info Version", i32 3}
!250 = !{i32 1, !"wchar_size", i32 4}
!251 = !{i32 7, !"PIC Level", i32 2}
!252 = !{i32 7, !"PIE Level", i32 2}
!253 = !{i32 7, !"uwtable", i32 1}
!254 = !{i32 7, !"frame-pointer", i32 2}
!255 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!256 = distinct !DISubprogram(name: "foo", linkageName: "_Z3foov", scope: !1, file: !1, line: 8, type: !24, scopeLine: 8, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !257)
!257 = !{}
!258 = !DILocation(line: 10, column: 8, scope: !259)
!259 = distinct !DILexicalBlock(scope: !256, file: !1, line: 10, column: 8)
!260 = !DILocation(line: 10, column: 8, scope: !256)
!261 = !DILocation(line: 12, column: 9, scope: !262)
!262 = distinct !DILexicalBlock(scope: !259, file: !1, line: 11, column: 5)
!263 = !DILocation(line: 13, column: 12, scope: !264)
!264 = distinct !DILexicalBlock(scope: !262, file: !1, line: 13, column: 12)
!265 = !DILocation(line: 13, column: 14, scope: !264)
!266 = !DILocation(line: 13, column: 12, scope: !262)
!267 = !DILocation(line: 14, column: 13, scope: !268)
!268 = distinct !DILexicalBlock(scope: !264, file: !1, line: 14, column: 9)
!269 = !DILocation(line: 15, column: 16, scope: !270)
!270 = distinct !DILexicalBlock(scope: !268, file: !1, line: 15, column: 16)
!271 = !DILocation(line: 15, column: 18, scope: !270)
!272 = !DILocation(line: 15, column: 16, scope: !268)
!273 = !DILocation(line: 16, column: 17, scope: !274)
!274 = distinct !DILexicalBlock(scope: !270, file: !1, line: 16, column: 13)
!275 = !DILocation(line: 17, column: 13, scope: !274)
!276 = !DILocation(line: 18, column: 9, scope: !268)
!277 = !DILocalVariable(name: "i", scope: !278, file: !1, line: 21, type: !9)
!278 = distinct !DILexicalBlock(scope: !262, file: !1, line: 21, column: 9)
!279 = !DILocation(line: 21, column: 17, scope: !278)
!280 = !DILocation(line: 21, column: 13, scope: !278)
!281 = !DILocation(line: 21, column: 22, scope: !282)
!282 = distinct !DILexicalBlock(scope: !278, file: !1, line: 21, column: 9)
!283 = !DILocation(line: 21, column: 24, scope: !282)
!284 = !DILocation(line: 21, column: 9, scope: !278)
!285 = !DILocation(line: 22, column: 14, scope: !282)
!286 = !DILocation(line: 22, column: 13, scope: !282)
!287 = !DILocation(line: 21, column: 30, scope: !282)
!288 = !DILocation(line: 21, column: 9, scope: !282)
!289 = distinct !{!289, !284, !290, !291}
!290 = !DILocation(line: 22, column: 17, scope: !278)
!291 = !{!"llvm.loop.mustprogress"}
!292 = !DILocation(line: 23, column: 26, scope: !262)
!293 = !DILocation(line: 23, column: 9, scope: !262)
!294 = !DILocation(line: 24, column: 5, scope: !262)
!295 = !DILocation(line: 26, column: 5, scope: !256)
!296 = !DILocation(line: 28, column: 8, scope: !297)
!297 = distinct !DILexicalBlock(scope: !256, file: !1, line: 28, column: 8)
!298 = !DILocation(line: 28, column: 10, scope: !297)
!299 = !DILocation(line: 28, column: 8, scope: !256)
!300 = !DILocation(line: 29, column: 9, scope: !301)
!301 = distinct !DILexicalBlock(scope: !297, file: !1, line: 29, column: 5)
!302 = !DILocation(line: 30, column: 5, scope: !301)
!303 = !DILocation(line: 32, column: 5, scope: !256)
!304 = !DILocation(line: 33, column: 1, scope: !256)
