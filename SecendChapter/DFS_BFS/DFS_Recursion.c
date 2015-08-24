#include "DFS_BFS.h"
#include "Utility.h"

#define INF 1000000

/*----------------------------------------------------------
 *                 DFS
 *----------------------------------------------------------
 */

int reached[INF][2];
int reached_pointer = 0;

bool toReachTheGoal_Recursion(int width, int height, int x, int y, int gx, int gy, int** map) {
  int **next;
  int i;
  
  if (x == gx || y == gy)
    return true;
  
  next = nextPos(width, height, x, y, map);
  for (i=0; i<4; i++) {
    if (next[i] != NULL) {
      //find
      int j;
      bool find = false;
      for (j=0; j<reached_pointer; j++)
        if (reached[j][0] == next[i][0] && reached[j][1] == next[i][0]) {
          find = true;
          break;
        }
      
      if (!find) {
        if (map[next[i][0]][next[i][1]] == 1) {
          reached[reached_pointer][0] = next[i][0];
          reached[reached_pointer++][1] = next[i][1];
          return toReachTheGoal(width, height, next[i][0], next[i][1], gx, gy, map);
        }
      }
      free(next[i]);
    }
  }
  free(next);
  
  return false;
}