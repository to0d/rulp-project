define dso_local i32 @foo(i32 %0) local_unnamed_addr {
  %2 = icmp sgt i32 %0, 0
  br i1 %2, label %6, label %3

3:                                                ; preds = %1
  %4 = icmp ne i32 %0, 0
  %5 = sext i1 %4 to i32
  ret i32 %5

6:                                                ; preds = %1
  ret i32 1
}
