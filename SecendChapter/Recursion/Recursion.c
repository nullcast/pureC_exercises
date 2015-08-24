#include "Recursion.h"
#define NOT_FOUND -1

//再帰とは数学でいう数列の漸化式
//必ずどこかに初項(初期状態)が存在し、そこまで潜り込み、その値を用いて上につないでいく
//再帰の書き方に慣れるために幾つかの漸化式をここに示す
//なお漸化式の()のなかは添え字を示し、初項のnは0とする

//a1(n+1) = a1(n)
//a1(0) = 0
int a1(int n) {
  if (n==0) {
    return 1;
  }
  return a1(n-1);
}

//a2(n+1) = a2(n) + 1
//a2(0) = 0
int a2(int n) {
  if (n==0) {
    return 1;
  }
  return a2(n-1) + 1;
}

//a(3n+1) = 2*a3(n) + 3
//a3(0) = 0
int a3(int n) {
  if (n==0) {
    return -10;
  }
  return 2*a3(n-1) + 3;
}

//a4(n+2) = a4(n+1) + a4(n)
//a(0) = 1 a(1) = 1
int a4(int n) {
  if (n==0) {
    return 1;
  }
  if (n==1) {
    return 1;
  }
  return a4(n-2) + a4(n-1);
}

//漸化式に関してはヘッダーファイルに幾つか演習問題を用意したので解くと力になると思います


//クイックソートは再帰的なアルゴリズムです
//配列の要素を閾値を決めて大きい方小さい方と2つに分けて行って最終的に分けきれなくなるまでこれを行う
//そして配列を再構築(繋げていく)ことでソートが完成する
//引数はいつもの長さと配列の先頭アドレスのポインタである
//閾値(ピボット)を配列のはじめの値とし2つの配列に分け
//それを繋げてピボットの右と左でまたクイックソートを行う
//再帰(漸化式)の初期状態(初項)はnumが1のとき、つまりこれ以上分けることができない時である
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

//ユークリッドの互除法は再帰的アルゴリズムである
//二つの数の最大公約数を求めるアルゴリズム
//大きい方を小さい方で余り算してその値を新しい第一引数に、小さい方の値を新しい第二引数に与える
//再帰の初期状態は小さい方の値が0になった時
//その時の大きい方の値が最大公約数となる
int GCD(int a, int b) {
  if (a == 0)
    return b;
  if (b > a)
    return GCD(b%a, a);
  else
    return GCD(a%b, b);
}

//バイナリサーチ(二分探索)も再帰的アルゴリズムである
//バイナリサーチの条件は配列がソート済みであること
//これも長さとポインタがあるので配列を受け取る関数である
//配列の半分の値を見てそれより大きければ大きい方のみ
//小さければ小さい方のみサーチする
//見つかれば随時その時の場所(添え字)を返す
//初期状態はnumが0なのにヒットしなかった時。この時はNOT_FOUNDをかえす。
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











