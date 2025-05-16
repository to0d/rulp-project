;struct xxx{
;  int x;
;};
;
;struct xxx* create_xx();
;void des_xx(struct xxx*);
;void func1(struct xxx* x);
;
;int foo(){
; struct xxx* x = create_xx();
; func1(x);
; des_xx(x);
; return x->x;
;}

%struct.xxx = type { i32 }

define dso_local i32 @foo() {
  %1 = alloca %struct.xxx*, align 8
  %2 = call %struct.xxx* (...) @create_xx()
  store %struct.xxx* %2, %struct.xxx** %1, align 8
  %3 = load %struct.xxx*, %struct.xxx** %1, align 8
  call void @func1(%struct.xxx* noundef %3)
  %4 = load %struct.xxx*, %struct.xxx** %1, align 8
  call void @des_xx(%struct.xxx* noundef %4)
  %5 = load %struct.xxx*, %struct.xxx** %1, align 8
  %6 = getelementptr inbounds %struct.xxx, %struct.xxx* %5, i32 0, i32 0
  %7 = load i32, i32* %6, align 4
  ret i32 %7
}

declare %struct.xxx* @create_xx(...)
declare void @func1(%struct.xxx* noundef)
declare void @des_xx(%struct.xxx* noundef)

