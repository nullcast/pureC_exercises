#include "Search.h"

int LinearSearch(int data, int num, int *array) {
  int i;
  int *p;
  for (i=0; i<num; i++) {
    if (data == array[i]) {
      return i;
    }
  }
  return NOT_FOUND;
}