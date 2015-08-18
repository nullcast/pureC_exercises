#include "Function.h"

void func1() {
  puts("hello world");
}

int func2() {
  int a = 100;
  return a;
}

void func3(int a) {
  puts("Func3");
  printf("recieved number : %d \n", a);
}

double func4(int a, double b) {
  puts("Func4");
  printf("recieved number : %d \n", a);
  printf("recieved number : %lf \n", b);
  return (double)a + b;
}

void func5(int *p) {
  printf("func5 Address : %p \n", &p);
  *p = 300;
}

void func6(char **str) {
  *str = (char*)malloc(sizeof(char)*6);
  *str = "func6";
}

void* func7() {
  int num = 10;
  void *result = (void*)malloc(sizeof(int)*num);
  int i;
  for (i=0; i<num; i++) {
    ((int *)result)[i] = i;
  }
  return result;
}
