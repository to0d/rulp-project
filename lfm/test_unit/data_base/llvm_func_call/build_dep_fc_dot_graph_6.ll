;int f1(int* x);
;int f2();
;void f3(int x);
;
;int foo()
;{
;  int x = 0;
;  f1(&x);
;  if(x > 0){
;    x += f2();
;  }
;  f3(x);
;  return x; 
;}

define dso_local i32 @foo() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 @f1(i32* noundef %1)
  %3 = load i32, i32* %1, align 4
  %4 = icmp sgt i32 %3, 0
  br i1 %4, label %5, label %9

5:                                                ; preds = %0
  %6 = call i32 (...) @f2()
  %7 = load i32, i32* %1, align 4
  %8 = add nsw i32 %7, %6
  store i32 %8, i32* %1, align 4
  br label %9

9:                                                ; preds = %5, %0
  %10 = load i32, i32* %1, align 4
  call void @f3(i32 noundef %10)
  %11 = load i32, i32* %1, align 4
  ret i32 %11
}

declare i32 @f1(i32* noundef)
declare i32 @f2(...)
declare void @f3(i32 noundef)

