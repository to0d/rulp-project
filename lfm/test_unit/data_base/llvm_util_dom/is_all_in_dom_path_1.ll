;int foo(int x){
;  if(x > 0){
;    x++;
;  }
;  else{
;    x--;
;  }
;  return x/2;
;}

define dso_local i32 @foo(i32 noundef %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = icmp sgt i32 %3, 0
  br i1 %4, label %5, label %8

5:                                                ; preds = %1
  %6 = load i32, i32* %2, align 4
  %7 = add nsw i32 %6, 1
  store i32 %7, i32* %2, align 4
  br label %11

8:                                                ; preds = %1
  %9 = load i32, i32* %2, align 4
  %10 = add nsw i32 %9, -1
  store i32 %10, i32* %2, align 4
  br label %11

11:                                               ; preds = %8, %5
  %12 = load i32, i32* %2, align 4
  %13 = sdiv i32 %12, 2
  ret i32 %13
}

