; ModuleID = 'data_base/llvm_dbg/remove_debug_info_1_src.ll'
source_filename = "data_base/llvm_dbg/remove_debug_info_1_src.ll"
%struct.AA = type { i32 }
define dso_local i32 @foo(%struct.AA* noundef %0) {
  %2 = alloca %struct.AA*, align 8
  store %struct.AA* %0, %struct.AA** %2, align 8
  %3 = load %struct.AA*, %struct.AA** %2, align 8
  %4 = getelementptr inbounds %struct.AA, %struct.AA* %3, i32 0, i32 0
  %5 = load i32, i32* %4, align 4
  ret i32 %5
}
!llvm.module.flags = !{!0, !1, !2, !3, !4}
!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
