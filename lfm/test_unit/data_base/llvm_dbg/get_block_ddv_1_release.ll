; ModuleID = 'hello.cpp'
source_filename = "hello.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%struct.XX = type { i32 }

@.str = private unnamed_addr constant [5 x i8] c"x=%d\00", align 1
@.str.1 = private unnamed_addr constant [5 x i8] c"x=%f\00", align 1
@.str.2 = private unnamed_addr constant [5 x i8] c"y=%d\00", align 1

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z3fooP2XXRS_(%struct.XX* noundef %0, %struct.XX* noundef nonnull align 4 dereferenceable(4) %1) #0 {
  %3 = alloca %struct.XX*, align 8
  %4 = alloca %struct.XX*, align 8
  %5 = alloca %struct.XX, align 4
  store %struct.XX* %0, %struct.XX** %3, align 8
  store %struct.XX* %1, %struct.XX** %4, align 8
  %6 = load %struct.XX*, %struct.XX** %3, align 8
  %7 = getelementptr inbounds %struct.XX, %struct.XX* %6, i32 0, i32 0
  %8 = load i32, i32* %7, align 4
  %9 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 noundef %8)
  %10 = load %struct.XX*, %struct.XX** %4, align 8
  %11 = getelementptr inbounds %struct.XX, %struct.XX* %10, i32 0, i32 0
  %12 = load i32, i32* %11, align 4
  %13 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 noundef %12)
  %14 = getelementptr inbounds %struct.XX, %struct.XX* %5, i32 0, i32 0
  %15 = load i32, i32* %14, align 4
  %16 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str, i64 0, i64 0), i32 noundef %15)
  ret void
}

declare i32 @printf(i8* noundef, ...) #1

; Function Attrs: mustprogress noinline optnone uwtable
define dso_local void @_Z4foo2Pdi(double* noundef %0, i32 noundef %1) #0 {
  %3 = alloca double*, align 8
  %4 = alloca i32, align 4
  store double* %0, double** %3, align 8
  store i32 %1, i32* %4, align 4
  %5 = load double*, double** %3, align 8
  %6 = load double, double* %5, align 8
  %7 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), double noundef %6)
  %8 = load i32, i32* %4, align 4
  %9 = call i32 (i8*, ...) @printf(i8* noundef getelementptr inbounds ([5 x i8], [5 x i8]* @.str.2, i64 0, i64 0), i32 noundef %8)
  ret void
}

attributes #0 = { mustprogress noinline optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.6"}
