;struct xxx{
;  int x;
;};
;
;void func1(struct xxx* x);
;
;int foo(int xx){
;  struct xxx x;
;  func1(&x);
;  return x.x;
;}

%struct.xxx = type { i32 }

define dso_local i32 @foo(i32 noundef %0)  {
  %2 = alloca i32, align 4
  %3 = alloca %struct.xxx, align 4
  store i32 %0, i32* %2, align 4
  call void @func1(%struct.xxx* noundef %3)
  %4 = getelementptr inbounds %struct.xxx, %struct.xxx* %3, i32 0, i32 0
  %5 = load i32, i32* %4, align 4
  ret i32 %5
}

declare void @func1(%struct.xxx* noundef)

