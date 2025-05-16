;int fun1(int x);
;int foo(int x){
;  return fun1(x);
;}

define dso_local i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 @fun1(i32 noundef %3)
  ret i32 %4
}

declare i32 @fun1(i32 noundef)

