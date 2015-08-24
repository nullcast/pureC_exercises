#include "Sort.h"

//int型のポインタを二つ受け取る
//int型のポインタということはint型の値は関数の呼び出し元に影響する
//第一引数の値と第二引数の値を取り替える関数である
void Swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

//int型のポインタとint型を受け取る
//ここのint型のポインタは呼び出し元では配列を渡してることに気づくようになろう
//引数の意味は、配列の長さと配列の先頭アドレスを格納したポインタである
//隣と比較して大小関係が異なったら交換するという操作を配列の長さ分行うと
//配列の一番最後(一番大きいもしくは一番小さい)値が定まる
//これを利用してソート(並び替え)を行う
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