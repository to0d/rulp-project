;struct xxx{
;  int x;
;};
;
;int func1(struct xxx* x){
;  if(x == 0)
;    return -1;
;  return x->x + 1;
;}

%struct.xxx = type { i32 }

define dso_local i32 @func1(%struct.xxx* noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca %struct.xxx*, align 8
  store %struct.xxx* %0, %struct.xxx** %3, align 8
  %4 = load %struct.xxx*, %struct.xxx** %3, align 8
  %5 = icmp eq %struct.xxx* %4, null
  br i1 %5, label %6, label %7

6:                                                ; preds = %1
  store i32 -1, i32* %2, align 4
  br label %12

7:                                                ; preds = %1
  %8 = load %struct.xxx*, %struct.xxx** %3, align 8
  %9 = getelementptr inbounds %struct.xxx, %struct.xxx* %8, i32 0, i32 0
  %10 = load i32, i32* %9, align 4
  %11 = add nsw i32 %10, 1
  store i32 %11, i32* %2, align 4
  br label %12

12:                                               ; preds = %7, %6
  %13 = load i32, i32* %2, align 4
  ret i32 %13
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }