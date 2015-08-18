#include "Sort.h"
#define NUM 13

int data[] = {2,4,5,6,2,3,5,3,8,23,19,4,9};

int main() {
  int i;
  for (i=0; i<NUM; i++) {
    printf("%d ",data[i]);
  }
  puts("");
  puts("");
  
  puts("BubbleSort");
  BubbleSort(NUM, data);
  for (i=0; i<NUM; i++) {
    printf("%d ",data[i]);
  }
}