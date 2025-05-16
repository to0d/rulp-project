%struct.xxx = type { i32 }

define dso_local void @func1(%struct.xxx* noundef %0) {
  %2 = alloca %struct.xxx*, align 8
  store %struct.xxx* %0, %struct.xxx** %2, align 8
  %3 = load %struct.xxx*, %struct.xxx** %2, align 8
  %4 = getelementptr inbounds %struct.xxx, %struct.xxx* %3, i32 0, i32 0
  %5 = load i32, i32* %4, align 4
  %6 = add nsw i32 %5, 1
  store i32 %6, i32* %4, align 4
  ret void
}
