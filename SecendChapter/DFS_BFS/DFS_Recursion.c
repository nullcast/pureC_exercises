#include "DFS_BFS.h"
#include "Utility.h"

#define INF 1000000

/*----------------------------------------------------------
 *                 DFS
 *----------------------------------------------------------
 */

int reached[INF][2];
int reached_pointer = 0;

//深さ優先探索のみ簡単に書く方法がある
//それが再帰をつかった方法
//スタックがいらなくなる
//FIFO的な情報の受け渡しは再帰で行っていた
//スタックに挿入する部分をで再帰を呼ぶだけ、そうすればwhileループもスタックから取り出す作業もスタックの初期化処理もいらない
//ゴールが見つかり次第returnする。初期状態はもう次のあてがなくなった時である falseが返される。
//しかし、他の道でtrueが帰れば結果的にresultはtrueになる。
//一本でもゴールにたどり着く道があればtrueが帰る
bool toReachTheGoal_Recursion(int width, int height, int x, int y, int gx, int gy, int** map) {
  int **next;
  int i;
  bool result = false;
  
  if (x == gx && y == gy)
    return true;
  
  next = nextPos(width, height, x, y, map);
  for (i=0; i<4; i++) {
    if (next[i] != NULL) {
      //find
      int j;
      bool find = false;
      for (j=0; j<reached_pointer; j++)
        if (reached[j][0] == next[i][0] && reached[j][1] == next[i][1]) {
          find = true;
          break;
        }
      
      if (!find) {
        if (map[next[i][0]][next[i][1]] == 1) {
          reached[reached_pointer][0] = next[i][0];
          reached[reached_pointer++][1] = next[i][1];
          result += toReachTheGoal_Recursion(width, height, next[i][0], next[i][1], gx, gy, map);
          if (result)
            break;
        }
      }
      free(next[i]);
    }
  }
  free(next);
  
  return result;
}