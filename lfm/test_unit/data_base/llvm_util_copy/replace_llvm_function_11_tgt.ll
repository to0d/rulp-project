; int func1(int x);
; int func2(int x);
; int foo(int x){
;   return func1(x)+func2(x);
; }

define dso_local i32 @foo(i32 %0){
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @func1(i32 %3)
  %5 = load i32, i32* %2, align 4
  %6 = call i32 @func2(i32 %5)
  %7 = add nsw i32 %4, %6
  ret i32 %7
}

declare dso_local i32 @func1(i32) 
declare dso_local i32 @func2(i32) 

