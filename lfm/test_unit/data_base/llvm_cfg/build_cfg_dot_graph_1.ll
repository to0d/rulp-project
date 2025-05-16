;void f1();
;void f2();
;
;int foo() {
;  int i,j,k , t= 0;
;  for(i=0;i<2;i++){
;    for(j=0;j<3;j++)
;      t++;
;    f1();
;  }
;  f2();
;  return t;
;}

target triple = "x86_64-pc-linux-gnu"

define dso_local i32 @foo() {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 0, i32* %4, align 4
  store i32 0, i32* %1, align 4
  br label %5

5:                                                ; preds = %19, %0
  %6 = load i32, i32* %1, align 4
  %7 = icmp slt i32 %6, 2
  br i1 %7, label %8, label %22

8:                                                ; preds = %5
  store i32 0, i32* %2, align 4
  br label %9

9:                                                ; preds = %15, %8
  %10 = load i32, i32* %2, align 4
  %11 = icmp slt i32 %10, 3
  br i1 %11, label %12, label %18

12:                                               ; preds = %9
  %13 = load i32, i32* %4, align 4
  %14 = add nsw i32 %13, 1
  store i32 %14, i32* %4, align 4
  br label %15

15:                                               ; preds = %12
  %16 = load i32, i32* %2, align 4
  %17 = add nsw i32 %16, 1
  store i32 %17, i32* %2, align 4
  br label %9, !llvm.loop !6

18:                                               ; preds = %9
  call void (...) @f1()
  br label %19

19:                                               ; preds = %18
  %20 = load i32, i32* %1, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, i32* %1, align 4
  br label %5, !llvm.loop !8

22:                                               ; preds = %5
  call void (...) @f2()
  %23 = load i32, i32* %4, align 4
  ret i32 %23
}

declare void @f1(...)
declare void @f2(...)

!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}