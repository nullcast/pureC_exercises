#include "Function.h"

//引数なし
//hello worldと表示するだけの関数
void func1() {
  puts("hello world");
}

//引数なし
//関数内のint型のローカル変数を定義し、その値を返す
int func2() {
  int a = 100;
  return a;
}

//int型の引数あり
//引数の値を使って出力
void func3(int a) {
  puts("Func3");
  printf("recieved number : %d \n", a);
}

//int型とdouble型の引数あり
//引数の値を使って出力
//足し合わせた値を返す
//ここで注意 cの引数は値渡しでありローカル変数定義と同じ。
//実引数とはアドレスが違うことに注意
double func4(int a, double b) {
  puts("Func4");
  printf("recieved number : %d \n", a);
  printf("recieved number : %lf \n", b);
  return (double)a + b;
}

//int型のポインタの引数あり
//ポインタのアドレスを表示
//注意 ポインタに格納されてるアドレスを表示してるわけではない
//pの指し示すアドレス先に300を入れる
//関数の呼び出し元に影響
void func5(int *p) {
  printf("func5 Address : %p \n", &p);
  *p = 300;
}

//charのポインタのポインタ型の引数あり
//なぜポインタのポインタか
//文字列を扱うだけならcharのポインタでおk
//しかし、cの引数は値渡しでありcharのポインタ型のアドレスは関数の呼び出し元と関数内では異なる
//ポインタのポインタを受け取ることで変数の根元っから変更することが可能！
//配列の操作でも同じことが言える。cの気をつけるポイント
void func6(char **str) {
  *str = (char*)malloc(sizeof(char)*6);
  *str = "func6";
}

//引数なし
//voidのポインタ型を返す
//voidのポインタ型とは何か
//これは汎用ポインタと言われなんでも入れることができる変数
//この関数ではvoidのポインタ型のローカル変数resultを定義してint型の配列のようなものを入れている。
//その変数を随時キャストしてint型の値を入れて返り値として返している。
void* func7() {
  int num = 10;
  void *result = (void*)malloc(sizeof(int)*num);
  int i;
  for (i=0; i<num; i++) {
    ((int *)result)[i] = i;
  }
  return result;
}
