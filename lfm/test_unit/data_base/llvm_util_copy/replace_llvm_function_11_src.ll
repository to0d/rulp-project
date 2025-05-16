; int func3(int x);
; int func1(int x){
;   return fun3(x)+1;
; }
; int func2(int x){
;   return fun3(x)+2;
; }

define dso_local i32 @func1(i32 %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @func3(i32 %3)
  %5 = add nsw i32 %4, 1
  ret i32 %5
}

declare dso_local i32 @func3(i32) 

define dso_local i32 @func2(i32 %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @func3(i32 %3)
  %5 = add nsw i32 %4, 2
  ret i32 %5
}

