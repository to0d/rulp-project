;void f1(short* x);
;
;union X
;{
;    int  a;
;    short b[2];
;};
;
;void foo() {
;    union X x;
;    x.a = 1;
;    f1(&x.b[0]);
;    f1(&x.b[1]);
;}

%union.X = type { i32 }

define dso_local void @foo() {
  %1 = alloca %union.X, align 4
  %2 = bitcast %union.X* %1 to i32*
  store i32 1, i32* %2, align 4
  %3 = bitcast %union.X* %1 to [2 x i16]*
  %4 = getelementptr inbounds [2 x i16], [2 x i16]* %3, i64 0, i64 0
  call void @f1(i16* noundef %4)
  %5 = bitcast %union.X* %1 to [2 x i16]*
  %6 = getelementptr inbounds [2 x i16], [2 x i16]* %5, i64 0, i64 1
  call void @f1(i16* noundef %6)
  ret void
}

declare void @f1(i16* noundef)


