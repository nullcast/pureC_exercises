#include "Search.h"
#define NUM 11

int array[] = {2,3,5,0,4,16,45,20,51,1,9};

int main() {
  int i2 = LinearSearch(2, NUM, array);
  int i4 = LinearSearch(4, NUM, array);
  int i10 = LinearSearch(10, NUM, array);
  int i51_0_5 = LinearSearch(51, NUM-6, array);
  
  printf("Search for 2 : %d\n", i2);
  printf("Search for 4 : %d\n", i4);
  printf("Search for 10 : %d\n", i10);
  printf("Search for 51 range of 0 to 5 : %d\n", i10);
}