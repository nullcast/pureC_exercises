#include "Pointer.h"
#define NUM 10

int main()
{
  int *array = (int *)malloc(sizeof(int)*NUM);
  int i;
  for (i=0; i<NUM; i++) {
    array[i] = i;
  }
  
  puts("push_back");
  array_push_back(10, NUM, array);
  for (i=0; i<NUM+1; i++) {
    printf("%d\n",(int)array[i]);
  }
  puts("");
  
  puts("insert");
  array_insert(5, -1, NUM+1, array);
  for (i=0; i<NUM+2; i++) {
    printf("%d\n",array[i]);
  }
  puts("");
  
  puts("pop_back");
  array_pop_back(NUM+2, array);
  for (i=0; i<NUM+1; i++) {
    printf("%d\n",array[i]);
  }
  puts("");
  
  return 0;
}