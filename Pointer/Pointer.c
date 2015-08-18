#include "Pointer.h"

void array_insert(int index, int data, int num, int *array) {
  int *result;
  if ((result = (int*)realloc(array,num+1)) == NULL) {
    printf("realloc時にメモリが確保できません\n");
    free(array);
    exit(EXIT_FAILURE);
  }
  else {
    for (int i=num+1; index<i; i--) {
      result[i] = result[i-1];
    }
    array = result;
    array[index] = data;
  }
}

void array_push_back(int data, int num, int *array) {
  int *result;
  if ((result = (int*)realloc(array,num+1)) == NULL) {
    printf("realloc時にメモリが確保できません\n");
    free(array);
    exit(EXIT_FAILURE);
  }
  else {
    array = result;
    array[num] = data;
  }
}

void array_pop_back(int num, int *array) {
  int *result;
  if ((result = (int*)realloc(array,num-1)) == NULL) {
    printf("realloc時にメモリが確保できません\n");
    free(array);
    exit(EXIT_FAILURE);
  }
  else {
    array = result;
  }
}