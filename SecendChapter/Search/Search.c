#include "Search.h"

//リニアサーチ(線形探索)
//これもSortの時と同じで第二,第三引数の意味は配列の長さと配列の先頭アドレスが格納されたポインタを受け取るということを意識
//第一引数はサーチの対象
//配列としてのarrayを前から見て行ってdataと一致した時点でその位置(添え字)を返す
//最後まで見つからなければNOT_FOUNDを返す
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