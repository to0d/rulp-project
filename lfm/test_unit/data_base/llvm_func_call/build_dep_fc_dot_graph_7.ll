; ModuleID = 'HPL_pdmxswp2.c'
source_filename = "HPL_pdmxswp2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.HPL_S_panel = type { %struct.HPL_S_grid*, %struct.HPL_S_palg*, %struct.HPL_S_pmat*, double*, double*, double*, double*, double*, double*, double*, i32*, [2 x i8***], [2 x i32], i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32 }
%struct.HPL_S_grid = type { i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32 }
%struct.HPL_S_palg = type { i32, i32, i32, i32, i32, i32, {}*, {}*, void (%struct.HPL_S_panel*, i32*, %struct.HPL_S_panel*, i32)*, i32, i32, i32, i32 }
%struct.HPL_S_pmat = type { double*, double*, i32, i32, i32, i32, i32, i32 }

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @HPL_pdmxswp(%struct.HPL_S_panel* noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, double* noundef %4) #0 {
  %6 = alloca %struct.HPL_S_panel*, align 8
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca double*, align 8
  %11 = alloca double, align 8
  %12 = alloca double, align 8
  %13 = alloca double*, align 8
  %14 = alloca double*, align 8
  %15 = alloca double*, align 8
  %16 = alloca %struct.HPL_S_grid*, align 8
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
  %31 = alloca i32, align 4
  %32 = alloca i32, align 4
  %33 = alloca i32, align 4
  %34 = alloca i32, align 4
  %35 = alloca i32, align 4
  %36 = alloca i32, align 4
  %37 = alloca i32, align 4
  %38 = alloca i32, align 4
  store %struct.HPL_S_panel* %0, %struct.HPL_S_panel** %6, align 8
  store i32 %1, i32* %7, align 4
  store i32 %2, i32* %8, align 4
  store i32 %3, i32* %9, align 4
  store double* %4, double** %10, align 8
  %39 = load %struct.HPL_S_panel*, %struct.HPL_S_panel** %6, align 8
  %40 = getelementptr inbounds %struct.HPL_S_panel, %struct.HPL_S_panel* %39, i32 0, i32 0
  %41 = load %struct.HPL_S_grid*, %struct.HPL_S_grid** %40, align 8
  store %struct.HPL_S_grid* %41, %struct.HPL_S_grid** %16, align 8
  %42 = load %struct.HPL_S_grid*, %struct.HPL_S_grid** %16, align 8
  %43 = getelementptr inbounds %struct.HPL_S_grid, %struct.HPL_S_grid* %42, i32 0, i32 2
  %44 = load i32, i32* %43, align 4
  store i32 %44, i32* %31, align 4
  %45 = load %struct.HPL_S_grid*, %struct.HPL_S_grid** %16, align 8
  %46 = getelementptr inbounds %struct.HPL_S_grid, %struct.HPL_S_grid* %45, i32 0, i32 4
  %47 = load i32, i32* %46, align 4
  store i32 %47, i32* %33, align 4
  %48 = load %struct.HPL_S_grid*, %struct.HPL_S_grid** %16, align 8
  %49 = getelementptr inbounds %struct.HPL_S_grid, %struct.HPL_S_grid* %48, i32 0, i32 7
  %50 = load i32, i32* %49, align 4
  store i32 %50, i32* %18, align 4
  %51 = load %struct.HPL_S_grid*, %struct.HPL_S_grid** %16, align 8
  %52 = getelementptr inbounds %struct.HPL_S_grid, %struct.HPL_S_grid* %51, i32 0, i32 8
  %53 = load i32, i32* %52, align 4
  store i32 %53, i32* %17, align 4
  %54 = load %struct.HPL_S_panel*, %struct.HPL_S_panel** %6, align 8
  %55 = getelementptr inbounds %struct.HPL_S_panel, %struct.HPL_S_panel* %54, i32 0, i32 14
  %56 = load i32, i32* %55, align 4
  store i32 %56, i32* %32, align 4
  %57 = load %struct.HPL_S_panel*, %struct.HPL_S_panel** %6, align 8
  %58 = getelementptr inbounds %struct.HPL_S_panel, %struct.HPL_S_panel* %57, i32 0, i32 24
  %59 = load i32, i32* %58, align 4
  store i32 %59, i32* %27, align 4
  %60 = load i32, i32* %33, align 4
  %61 = load i32, i32* %18, align 4
  %62 = sub i32 %60, %61
  store i32 %62, i32* %38, align 4
  %63 = icmp ne i32 %62, 0
  %64 = zext i1 %63 to i32
  store i32 %64, i32* %23, align 4
  %65 = load i32, i32* %31, align 4
  %66 = load i32, i32* %27, align 4
  %67 = icmp slt i32 %65, %66
  br i1 %67, label %68, label %74

68:                                               ; preds = %5
  %69 = load i32, i32* %33, align 4
  %70 = load i32, i32* %31, align 4
  %71 = add nsw i32 %69, %70
  %72 = load i32, i32* %27, align 4
  %73 = sub nsw i32 %71, %72
  br label %78

74:                                               ; preds = %5
  %75 = load i32, i32* %31, align 4
  %76 = load i32, i32* %27, align 4
  %77 = sub nsw i32 %75, %76
  br label %78

78:                                               ; preds = %74, %68
  %79 = phi i32 [ %73, %68 ], [ %77, %74 ]
  store i32 %79, i32* %29, align 4
  %80 = load i32, i32* %32, align 4
  %81 = add nsw i32 %80, 4
  store i32 %81, i32* %24, align 4
  %82 = load i32, i32* %32, align 4
  %83 = add nsw i32 %81, %82
  store i32 %83, i32* %25, align 4
  %84 = load double*, double** %10, align 8
  %85 = getelementptr inbounds double, double* %84, i64 4
  store double* %85, double** %14, align 8
  %86 = load i32, i32* %32, align 4
  %87 = sext i32 %86 to i64
  %88 = getelementptr inbounds double, double* %85, i64 %87
  store double* %88, double** %13, align 8
  %89 = load double*, double** %10, align 8
  %90 = load i32, i32* %25, align 4
  %91 = sext i32 %90 to i64
  %92 = getelementptr inbounds double, double* %89, i64 %91
  store double* %92, double** %15, align 8
  %93 = load i32, i32* %7, align 4
  %94 = icmp sgt i32 %93, 0
  br i1 %94, label %95, label %135

95:                                               ; preds = %78
  %96 = load %struct.HPL_S_panel*, %struct.HPL_S_panel** %6, align 8
  %97 = getelementptr inbounds %struct.HPL_S_panel, %struct.HPL_S_panel* %96, i32 0, i32 23
  %98 = load i32, i32* %97, align 8
  store i32 %98, i32* %28, align 4
  %99 = load i32, i32* %32, align 4
  %100 = load %struct.HPL_S_panel*, %struct.HPL_S_panel** %6, align 8
  %101 = getelementptr inbounds %struct.HPL_S_panel, %struct.HPL_S_panel* %100, i32 0, i32 3
  %102 = load double*, double** %101, align 8
  %103 = load i32, i32* %8, align 4
  %104 = load double*, double** %10, align 8
  %105 = getelementptr inbounds double, double* %104, i64 1
  %106 = load double, double* %105, align 8
  %107 = fptosi double %106 to i32
  %108 = add nsw i32 %103, %107
  %109 = sext i32 %108 to i64
  %110 = getelementptr inbounds double, double* %102, i64 %109
  %111 = load i32, i32* %28, align 4
  %112 = sext i32 %111 to i64
  %113 = mul i64 0, %112
  %114 = getelementptr inbounds double, double* %110, i64 %113
  %115 = load i32, i32* %28, align 4
  %116 = load double*, double** %14, align 8
  call void @HPL_dcopy(i32 noundef %99, double* noundef %114, i32 noundef %115, double* noundef %116, i32 noundef 1)
  %117 = load i32, i32* %31, align 4
  %118 = load i32, i32* %27, align 4
  %119 = icmp eq i32 %117, %118
  br i1 %119, label %120, label %134

120:                                              ; preds = %95
  %121 = load i32, i32* %32, align 4
  %122 = load %struct.HPL_S_panel*, %struct.HPL_S_panel** %6, align 8
  %123 = getelementptr inbounds %struct.HPL_S_panel, %struct.HPL_S_panel* %122, i32 0, i32 3
  %124 = load double*, double** %123, align 8
  %125 = load i32, i32* %8, align 4
  %126 = sext i32 %125 to i64
  %127 = getelementptr inbounds double, double* %124, i64 %126
  %128 = load i32, i32* %28, align 4
  %129 = sext i32 %128 to i64
  %130 = mul i64 0, %129
  %131 = getelementptr inbounds double, double* %127, i64 %130
  %132 = load i32, i32* %28, align 4
  %133 = load double*, double** %13, align 8
  call void @HPL_dcopy(i32 noundef %121, double* noundef %131, i32 noundef %132, double* noundef %133, i32 noundef 1)
  br label %134

134:                                              ; preds = %120, %95
  br label %149

135:                                              ; preds = %78
  store i32 0, i32* %26, align 4
  br label %136

136:                                              ; preds = %145, %135
  %137 = load i32, i32* %26, align 4
  %138 = load i32, i32* %32, align 4
  %139 = icmp slt i32 %137, %138
  br i1 %139, label %140, label %148

140:                                              ; preds = %136
  %141 = load double*, double** %14, align 8
  %142 = load i32, i32* %26, align 4
  %143 = sext i32 %142 to i64
  %144 = getelementptr inbounds double, double* %141, i64 %143
  store double 0.000000e+00, double* %144, align 8
  br label %145

145:                                              ; preds = %140
  %146 = load i32, i32* %26, align 4
  %147 = add nsw i32 %146, 1
  store i32 %147, i32* %26, align 4
  br label %136, !llvm.loop !6

148:                                              ; preds = %136
  br label %149

149:                                              ; preds = %148, %134
  ret void
}

declare void @HPL_dcopy(i32 noundef, double* noundef, i32 noundef, double* noundef, i32 noundef) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
