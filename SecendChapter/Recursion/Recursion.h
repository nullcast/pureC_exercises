#include <stdio.h>
#include <stdlib.h>

/*--recurrence relation--*/
/*
  a1(n+1) = a1(n)
  a1(0) = 1
*/
int a1(int n);

/*
 a2(n+1) = a2(n) + 1
 a2(0) = 1
*/
int a2(int n);

/*
 a3(n+1) = 2*a3(n) + 3
 a3(0) = -10
*/
int a3(int n);

/*
 a4(n+2) = a4(n+1) + a4(n)
 a4(0) = 1 a4(1) = 1
 */
int a4(int n);

/*
 Exercises
 a5(n+1) = PI * a5(n) + PI
 a5(0) = 0
 
 a6(n+1) = sin(a6(n) + PI)
 a6(0) = 0
 
 a7(n+2) = pow(sin(a7(n)),2) + pow(cos(a7(n+1)),2)
 a7(0) = 0 a7(1) = 1
*/

/*--quick sort--*/
void QuickSort(int num, int *array);

/*
 Exercises
 quick sort
*/

/*-- euclidean algorithm --*/
int GCD(int a, int b);

/*-- binary search --*/
int BinarySearch(int data, int position, int num, int *array);

