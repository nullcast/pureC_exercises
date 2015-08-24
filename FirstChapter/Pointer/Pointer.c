#include "Pointer.h"

//c言語の配列は値渡しであるため、受け取ったarrayのアドレスは関数の呼び出し元と関数内で異なる
//しかし、配列を実引数に渡すとその配列の先頭アドレスが渡されるため、根元からいじることができる
//c言語 point 配列はポインタで受け取ろう
//しかし多次元配列となるとポインタのポインタで受け取ればいいのかと思うかもしれないがそれはちょっと違う
//そこには気をつけよう
//この関数内ではintのポインタのローカル変数resultにarrayの1つ増やした分reallocし、成功したら
//resultの最後からindex-1までの値を一つずらして、それをarrayの先頭アドレスに入れてindexの値を変更する
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

//insertと原理はほぼ同じ
//dataを最後に突っ込むだけ
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

//intのポインタのローカル変数resultにarrayの1つ減らした分reallocし
//それをresultに入れて返す
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