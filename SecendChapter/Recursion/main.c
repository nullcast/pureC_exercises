#include "Recursion.h"
#define NUM 13

int data[] = {2,4,5,6,2,3,5,3,8,23,19,4,9};

int main() {
  int i;
  
  printf("a1(10) = %d\n", a1(10));
  printf("a2(10) = %d\n", a2(10));
  printf("a3(10) = %d\n", a3(10));
  printf("a4(10) = %d\n", a4(10));
  puts("");
  
  for (i=0; i<NUM; i++) {
    printf("%d ",data[i]);
  }
  puts("");
  puts("QuickSort");
  QuickSort(NUM, data);
  for (i=0; i<NUM; i++) {
    printf("%d ",data[i]);
  }
  puts("");
  
  puts("");
  printf("GCD(30, 24) = %d \n", GCD(30, 24));
  puts("");
  
  printf("BinarySearch(10) = %d\n", BinarySearch(10, 0, NUM, data));
  printf("BinarySearch(23) = %d\n", BinarySearch(23, 0, NUM, data));
}