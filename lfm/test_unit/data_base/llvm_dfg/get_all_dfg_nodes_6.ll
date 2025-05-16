;void f1(int i, int& o);
;void f2(int i1, int i2, int& o);
;void f3(int i1, int i2, int i3, int& o);
;
;int foo(int x) {
;  int y, z, r;
;  f1(x, y);
;  f2(x, y, z);
;  f3(x, y, z, r);
;  return r;
;}

define dso_local noundef i32 @_Z3fooi(i32 noundef %0) {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, i32* %2, align 4
  %6 = load i32, i32* %2, align 4
  call void @_Z2f1iRi(i32 noundef %6, i32* noundef nonnull align 4 dereferenceable(4) %3)
  %7 = load i32, i32* %2, align 4
  %8 = load i32, i32* %3, align 4
  call void @_Z2f2iiRi(i32 noundef %7, i32 noundef %8, i32* noundef nonnull align 4 dereferenceable(4) %4)
  %9 = load i32, i32* %2, align 4
  %10 = load i32, i32* %3, align 4
  %11 = load i32, i32* %4, align 4
  call void @_Z2f3iiiRi(i32 noundef %9, i32 noundef %10, i32 noundef %11, i32* noundef nonnull align 4 dereferenceable(4) %5)
  %12 = load i32, i32* %5, align 4
  ret i32 %12
}

declare void @_Z2f1iRi(i32 noundef, i32* noundef nonnull align 4 dereferenceable(4))
declare void @_Z2f2iiRi(i32 noundef, i32 noundef, i32* noundef nonnull align 4 dereferenceable(4))
declare void @_Z2f3iiiRi(i32 noundef, i32 noundef, i32 noundef, i32* noundef nonnull align 4 dereferenceable(4)) 

