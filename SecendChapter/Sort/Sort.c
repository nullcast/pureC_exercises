#include "Sort.h"

void Swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void BubbleSort(int num, int *data) {
  int i,j;
  for (i=0; i<num; i++) {
    for (j=0; j<num-i-1; j++) {
      if (data[j+1]<data[j]) {
        Swap(data+j+1, data+j);
      }
    }
  }
}