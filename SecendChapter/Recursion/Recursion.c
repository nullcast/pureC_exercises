#include "Recursion.h"
#define NOT_FOUND -1

int a1(int n) {
  if (n==0) {
    return 1;
  }
  return a1(n-1);
}

int a2(int n) {
  if (n==0) {
    return 1;
  }
  return a2(n-1) + 1;
}

int a3(int n) {
  if (n==0) {
    return -10;
  }
  return 2*a3(n-1) + 3;
}

int a4(int n) {
  if (n==0) {
    return 1;
  }
  if (n==1) {
    return 1;
  }
  return a4(n-2) + a4(n-1);
}

void QuickSort(int num, int *array) {
  int p = *array;
  int *leftArray, *rightArray;
  int leftNum = 0, rightNum = 0, i;
  
  if (num <= 1)
    return;
  
  leftArray = (int*)malloc(sizeof(int)*num);
  rightArray = (int*)malloc(sizeof(int)*num);
  
  for (i=0; i<num; i++) {
    if (array[i]<p) {
      leftArray[leftNum] = array[i];
      leftNum++;
    } else {
      rightArray[rightNum] = array[i];
      rightNum++;
    }
  }
  for (i=0; i<leftNum; i++) {
    array[i] = leftArray[i];
  }
  for (i=0; i<rightNum; i++) {
    array[i+leftNum] = rightArray[i];
  }
  free(leftArray);
  free(rightArray);
  
  QuickSort(leftNum, array);
  QuickSort(rightNum-1, array+leftNum+1);
}

int GCD(int a, int b) {
  if (a == 0)
    return b;
  if (b > a)
    return GCD(b%a, a);
  else
    return GCD(a%b, b);
}

int BinarySearch(int data, int position, int num, int *array) {
  if (data == array[num/2])
    return position + num/2;
  else if (num <= 0)
    return NOT_FOUND;
  else if (data < array[num/2])
    return BinarySearch(data, position, num/2-1, array);
  else
    return BinarySearch(data, position+num/2+1, num/2, array+num/2+1);
}











