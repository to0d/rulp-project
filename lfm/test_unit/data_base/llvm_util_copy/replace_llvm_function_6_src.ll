;void func2();
;
;void func1(){
;  func2();
;}

define dso_local void @func1() {
  call void (...) @func2()
  ret void
}

declare void @func2(...)

