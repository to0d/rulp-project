;int f1(int* x);
;int f2();
;void f3(int x);
;
;int foo()
;{
;  int x = 0;
;  f1(&x);
;  x += f2();
;  f3(x);
;  return x; 
;}

define dso_local i32 @foo() {
  %1 = alloca i32, align 4
  store i32 0, i32* %1, align 4
  %2 = call i32 @f1(i32* noundef %1)
  %3 = call i32 (...) @f2()
  %4 = load i32, i32* %1, align 4
  %5 = add nsw i32 %4, %3
  store i32 %5, i32* %1, align 4
  %6 = load i32, i32* %1, align 4
  call void @f3(i32 noundef %6)
  %7 = load i32, i32* %1, align 4
  ret i32 %7
}

declare i32 @f1(i32* noundef)
declare i32 @f2(...)
declare void @f3(i32 noundef)