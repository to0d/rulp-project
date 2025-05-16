;void fun1();
;
;void foo(int x) {
;  fun1();
;
;  if(x > 0){
;    fun1();
;  }
;}

define dso_local void @foo(i32 noundef %0){
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  call void (...) @fun1()
  %3 = load i32, i32* %2, align 4
  %4 = icmp sgt i32 %3, 0
  br i1 %4, label %5, label %6

5:                                                ; preds = %1
  call void (...) @fun1()
  br label %6

6:                                                ; preds = %5, %1
  ret void
}

declare void @fun1(...)


