; int fun1(double* value);
; 
; void foo(){
;   fun1(0);
; }

define dso_local void @foo() {
  %1 = call i32 @fun1(double* noundef null)
  ret void
}

declare i32 @fun1(double* noundef)

