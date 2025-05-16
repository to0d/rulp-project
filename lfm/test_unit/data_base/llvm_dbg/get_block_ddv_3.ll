;struct xxx{
;  int x;
;};
;
;void foo(struct xxx* x){
; x->x++;
;}

%struct.xxx = type { i32 }

define dso_local void @foo(ptr noundef %0) !dbg !10 {
  %2 = alloca ptr, align 8
  store ptr %0, ptr %2, align 8
  call void @llvm.dbg.declare(metadata ptr %2, metadata !19, metadata !DIExpression()), !dbg !20
  %3 = load ptr, ptr %2, align 8, !dbg !21
  %4 = getelementptr inbounds %struct.xxx, ptr %3, i32 0, i32 0, !dbg !22
  %5 = load i32, ptr %4, align 4, !dbg !23
  %6 = add nsw i32 %5, 1, !dbg !23
  store i32 %6, ptr %4, align 4, !dbg !23
  ret void, !dbg !24
}

declare void @llvm.dbg.declare(metadata, metadata, metadata)

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 15.0.7", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "test.c", directory: "/mnt/c/data/project/lfc-project/test_unit/data/llvm_util_base", checksumkind: CSK_MD5, checksum: "126d5deab5d50517d845df0decbba448")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 2}
!8 = !{i32 7, !"frame-pointer", i32 2}
!9 = !{!"Ubuntu clang version 15.0.7"}
!10 = distinct !DISubprogram(name: "func1", scope: !1, file: !1, line: 5, type: !11, scopeLine: 5, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !18)
!11 = !DISubroutineType(types: !12)
!12 = !{null, !13}
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !14, size: 64)
!14 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "xxx", file: !1, line: 1, size: 32, elements: !15)
!15 = !{!16}
!16 = !DIDerivedType(tag: DW_TAG_member, name: "x", scope: !14, file: !1, line: 2, baseType: !17, size: 32)
!17 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!18 = !{}
!19 = !DILocalVariable(name: "x", arg: 1, scope: !10, file: !1, line: 5, type: !13)
!20 = !DILocation(line: 5, column: 24, scope: !10)
!21 = !DILocation(line: 6, column: 2, scope: !10)
!22 = !DILocation(line: 6, column: 5, scope: !10)
!23 = !DILocation(line: 6, column: 6, scope: !10)
!24 = !DILocation(line: 7, column: 1, scope: !10)
