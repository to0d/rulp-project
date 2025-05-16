%struct.AA = type { i32 }

define dso_local i32 @foo(%struct.AA* noundef %0) !dbg !10 {
  %2 = alloca %struct.AA*, align 8
  store %struct.AA* %0, %struct.AA** %2, align 8
  call void @llvm.dbg.declare(metadata %struct.AA** %2, metadata !19, metadata !DIExpression()), !dbg !20
  %3 = load %struct.AA*, %struct.AA** %2, align 8, !dbg !21
  %4 = getelementptr inbounds %struct.AA, %struct.AA* %3, i32 0, i32 0, !dbg !22
  %5 = load i32, i32* %4, align 4, !dbg !22
  ret i32 %5, !dbg !23
}

declare void @llvm.dbg.declare(metadata, metadata, metadata)

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "Ubuntu clang version 14.0.0-1ubuntu1.1", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "test.c", directory: "/mnt/c/data/project/lfc-dev/scc/test_opt/TC240717A", checksumkind: CSK_MD5, checksum: "ced282935c02872e2635100acd14d001")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 7, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 1}
!8 = !{i32 7, !"frame-pointer", i32 2}
!10 = distinct !DISubprogram(name: "foo", scope: !1, file: !1, line: 5, type: !11, scopeLine: 5, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !18)
!11 = !DISubroutineType(types: !12)
!12 = !{!13, !14}
!13 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!14 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !15, size: 64)
!15 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "AA", file: !1, line: 1, size: 32, elements: !16)
!16 = !{!17}
!17 = !DIDerivedType(tag: DW_TAG_member, name: "a", scope: !15, file: !1, line: 2, baseType: !13, size: 32)
!18 = !{}
!19 = !DILocalVariable(name: "a", arg: 1, scope: !10, file: !1, line: 5, type: !14)
!20 = !DILocation(line: 5, column: 20, scope: !10)
!21 = !DILocation(line: 6, column: 10, scope: !10)
!22 = !DILocation(line: 6, column: 13, scope: !10)
!23 = !DILocation(line: 6, column: 3, scope: !10)
