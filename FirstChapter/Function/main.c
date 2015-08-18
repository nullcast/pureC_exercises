#include "Function.h"

int main() {
  int a, b = 10, c = 20, i;
  double d = 3.14, e;
  int *ip;
  char **str;
  void *p;
  
  ip = (int *)malloc(sizeof(int)*1);
  str = (char**)malloc(sizeof(char*)*1);
  func1();
  puts("");
  
  a = func2();
  printf("Func2 recieved number : %d\n", a);
  puts("");
  
  func3(b);
  puts("");
  
  e = func4(c, d);
  printf("Func4 recieved number : %lf\n", e);
  puts("");
  
  func5(ip);
  printf("ip Address : %p \n", &ip);
  printf("Func5 recieved number : %d\n", *ip);
  puts("");
  
  func6(str);
  printf("Func6 recieved str : %s\n", *str);
  puts("");
  
  puts("Func7 foreach");
  p = func7();
  for (i=0; i<10; i++) {
    int j = ((int *)p)[i];
    printf("%d\n", j);
  }
  
  return 0;
}