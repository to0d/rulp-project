define dso_local signext i32 @main() {
  %1 = alloca ptr, align 8
  %2 = alloca ptr, align 8
  %3 = alloca ptr, align 8
  %4 = alloca ptr, align 8
  %5 = alloca ptr, align 8
  %6 = call ptr @simd_core_executor_create()
  store ptr %6, ptr %5, align 8
  %7 = load ptr, ptr %5, align 8
  %8 = load ptr, ptr %1, align 8
  %9 = load ptr, ptr %2, align 8
  %10 = call zeroext i16 @simd_dre_executor_reshape(ptr noundef %7, ptr noundef %8, ptr noundef %9, i32 noundef signext 6, i32 noundef signext 6, i32 noundef signext 1, i32 noundef signext 6, i32 noundef signext 6, i32 noundef 1, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0)
  %11 = load ptr, ptr %5, align 8
  %12 = load ptr, ptr %2, align 8
  %13 = load ptr, ptr %3, align 8
  %14 = load ptr, ptr %4, align 8
  %15 = call zeroext i16 @simd_dre_executor_Ab(ptr noundef %11, ptr noundef %12, ptr noundef %13, ptr noundef %14, double noundef 6.000000e+00, i32 noundef signext 6, i32 noundef signext 1, i32 noundef signext 0, i32 noundef signext 0, i32 noundef 6, i32 noundef 6, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0, i32 noundef 0)
  ret i32 0
}

declare dso_local ptr @simd_core_executor_create(...)

declare dso_local zeroext i16 @simd_dre_executor_reshape(ptr noundef, ptr noundef, ptr noundef, i32 noundef signext, i32 noundef signext, i32 noundef signext, i32 noundef signext, i32 noundef signext, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef)

declare dso_local zeroext i16 @simd_dre_executor_Ab(ptr noundef, ptr noundef, ptr noundef, ptr noundef, double noundef, i32 noundef signext, i32 noundef signext, i32 noundef signext, i32 noundef signext, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef, i32 noundef) #1

