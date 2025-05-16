target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i32 @foo() {
    %1 = add i32 1, 2
    %2 = add i32 3, 4
    %3 = alloca i32, align 4
    store i32 %1, i32* %3, align 4
    store i32 %2, i32* %3, align 4
    %4 = load i32, i32* %3, align 4
    ret i32 %4
}
