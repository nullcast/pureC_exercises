#include "Utility.h"

//arrayの中にdataが含まれてるか見る
bool find(int *data, int num, int **array) {
  int i;
  for (i=0; i<num; i++) {
    if (array[i] == NULL)
      break;
    if(data[0] == array[i][0] && data[1] == array[i][1])
      return true;
  }
  return false;
}

//mapからはみ出さない次のポジションを返す
int** nextPos(int width, int height, int x, int y, int** map) {
  int **next = (int**)malloc(sizeof(int*)*4);
  int dx[4] = {0,1,-1,0};
  int dy[4] = {1,0,0,-1};
  int i;
  for (i=0; i<4; i++) {
    next[i] = (int*)malloc(sizeof(int)*2);
    if (x+dx[i]<0 || x+dx[i]>=width || y+dy[i]<0 || y+dy[i]>=height)
      next[i] = NULL;
    else {
      next[i][0] = x+dx[i];
      next[i][1] = y+dy[i];
    }
  }
  return next;
}

void freeArray(int num, int ***array) {
  int i;
  for (i=0; i<num; i++)
    free((*array)[i]);
  free(*array);
}