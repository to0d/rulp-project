int foo(int b, int c, int d, int f){
  
  while(b == 0){
    int a = b + c;
    d -= a;
    int e = d + f;
    if (e > 0)
      f = 2*e;
    else {
      b = d + e;
      e = e - 1;
    }
    b = f + c;
  }

  return b;
}
