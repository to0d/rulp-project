;int func1(int x){
;  int y = x == 0? 0b00100: (x == 1? 0b00101: 0b10000);
;  return y;
;}

define dso_local i32 @func1(i32 noundef %0){
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %4 = load i32, i32* %2, align 4
  %5 = icmp eq i32 %4, 0
  br i1 %5, label %6, label %7

6:                                                ; preds = %1
  br label %12

7:                                                ; preds = %1
  %8 = load i32, i32* %2, align 4
  %9 = icmp eq i32 %8, 1
  %10 = zext i1 %9 to i64
  %11 = select i1 %9, i32 5, i32 16
  br label %12

12:                                               ; preds = %7, %6
  %13 = phi i32 [ 4, %6 ], [ %11, %7 ]
  store i32 %13, i32* %3, align 4
  %14 = load i32, i32* %3, align 4
  ret i32 %14
}


