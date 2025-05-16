
@.str = private unnamed_addr constant [6 x i8] c"x=%d\0A\00", align 1

define dso_local void @foo(i32 %0) {
  %2 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %3 = load i32, i32* %2, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @.str, i64 0, i64 0), i32 %3)
  br label %5

5:                                                ; preds = %1, %5
  br label %5
}

declare dso_local i32 @printf(i8*, ...)