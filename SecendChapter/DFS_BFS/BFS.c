#include "DFS_BFS.h"
#include "Utility.h"

/*----------------------------------------------------------
 *                 BFS
 *----------------------------------------------------------
 */

//キューに値を突っ込む
void inQueue(int *data, int *end, int **queue) {
  queue[(*end)++] = data;
}

//キューから値を取り出す
//cの引数はあたい渡しだから、二次元配列を扱う際にそのポインタじゃないと元に影響はしない
int* deQueue(int *end, int ***queue) {
  (*end)--;
  int *result = **queue;
  *queue = *queue + 1;
  return result;
}

//intのポインタで作った配列もどきのサイズ変更
//元がポインタなら関数呼び出し元に影響させるにはポインタのポインタで受け取るのは鉄則
void resize(int **data) {
  int *new_data = (int*)malloc(sizeof(int)*3);
  int i;
  for (i=0; i<2; i++)
    new_data[i] = (*data)[i];
  free(*data);
  *data = new_data;
}

//幅優先探索 BFS
//深さ優先探索のstackの代わりにキューを使うだけ
//たったそれだけでDFSはBFSに変わる
//キューの実現はちょっと面倒
//デキューする際にポインタの先頭をずらしていけば実装できる
//データの末尾を知るためにキューポインタを用いる
//スタートからの最短経路距離を返す関数なのでキューに入れる情報は現在の位置とスタートからの道のり
//キューで実現することで一歩進んだ先を並行してみていくイメージ(複数の道を満遍なくみていく)
//初めてゴールにたどり着いた時、その時のスタートからの道のりが最短経路距離になる。
int shortestPathDistance(int width, int height, int x, int y, int gx, int gy, int** map) {
  int **queue_buffer = (int**)malloc(sizeof(int*)*width*height);
  int **reached = (int**)malloc(sizeof(int*)*width*height);
  int **next;
  int i, queue_pointer = 0, reached_pointer = 0;
  
  //初期化処理
  for (i=0; i<width*height; i++)
    reached[i] = NULL;
  int *firstPos = (int*)malloc(sizeof(int)*3); //座標とスタートからの道のりを保存
  firstPos[0] = x;
  firstPos[1] = y;
  firstPos[2] = 0;
  inQueue(firstPos, &queue_pointer, queue_buffer);
  reached[reached_pointer++] = firstPos;
  
  while (queue_pointer > 0) {
    //int i;
    //puts("queue trace");
    //for (i=0; i<queue_pointer; i++) {
    //  printf("  x = %d : y = %d\n", queue_buffer[i][0], queue_buffer[i][1]);
    //}
    
    int *currentPos = deQueue(&queue_pointer, &queue_buffer);
    
    //ゴールだったらtrueを返す
    if (currentPos[0] == gx && currentPos[1] == gy) {
      int tmp = currentPos[2];
      freeArray(reached_pointer, &reached);
      return tmp;
    }
    
    //考えられる点を全てキューに積んでいく
    next = nextPos(width, height, currentPos[0], currentPos[1], map);
    for (i=0; i<4; i++) {
      if (next[i] != NULL) {
        if (!find(next[i], reached_pointer, reached)) {
          //訪れることが可能であればreachedとstackに積んでいく
          if (map[next[i][0]][next[i][1]] == 1) {
            resize(&next[i]);
            next[i][2] = currentPos[2]+1;
            reached[reached_pointer++] = next[i];
            inQueue(next[i], &queue_pointer, queue_buffer);
          } else
            free(next[i]);
        } else
          free(next[i]);
      }
    }
  }
  
  return -1;
}