#include "DFS_BFS.h"
#include "Utility.h"

/*----------------------------------------------------------
 *                 DFS
 *----------------------------------------------------------
 */

bool toReachTheGoal(int width, int height, int x, int y, int gx, int gy, int** map) {
  int **stack_buffer = (int**)malloc(sizeof(int*)*width*height);
  int **reached = (int**)malloc(sizeof(int*)*width*height);
  int **next;
  int i, stack_pointer = 0, reached_pointer = 0;
  
  //初期化処理
  for (i=0; i<width*height; i++)
    reached[i] = NULL;
  int *firstPos = (int*)malloc(sizeof(int)*2);
  firstPos[0] = x;
  firstPos[1] = y;
  stack_buffer[stack_pointer++] = firstPos;
  reached[reached_pointer++] = firstPos;
  
  while (stack_pointer > 0) {
    int *currentPos = stack_buffer[--stack_pointer];
    
    //ゴールだったらtrueを返す
    if (currentPos[0] == gx && currentPos[1] == gy) {
      freeArray(reached_pointer, &reached);
      free(stack_buffer);
      return true;
    }
    
    //考えられる点を全てスタックに積んでいく
    next = nextPos(width, height, currentPos[0], currentPos[1], map);
    for (i=0; i<4; i++) {
      if (next[i] != NULL) {
        if (!find(next[i], reached_pointer, reached)) {
          //訪れることが可能であればreachedとstackに積んでいく
          if (map[next[i][0]][next[i][1]] == 1) {
            reached[reached_pointer++] = next[i];
            stack_buffer[stack_pointer++] = next[i];
          } else
            free(next[i]);
        } else
          free(next[i]);
      }
    }
  }
  
  return false;
}