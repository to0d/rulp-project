;void func1();
;
;void foo(){
;  func1();
;}

define dso_local void @foo() {
  call void (...) @func1()
  ret void
}

declare void @func1(...) 

