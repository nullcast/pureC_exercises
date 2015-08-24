#include "DFS_BFS.h"
#define WIDTH 5
#define HEIGHT 5

/*int map[WIDTH][HEIGHT] = {
  {1,0,0,1,1},
  {1,0,0,1,0},
  {1,1,0,1,1},
  {0,1,0,0,1},
  {0,1,1,1,1}
};*/

int map[WIDTH][HEIGHT] = {
  {1,0,0,1,1},
  {1,1,1,1,0},
  {0,1,0,0,0},
  {0,1,0,0,1},
  {0,1,1,1,1}
};

int main() {
  int *map_[HEIGHT];
  int i;
  for (i=0; i<WIDTH; i++)
    map_[i] = map[i];
  
  printf("%d\n", toReachTheGoal(WIDTH, HEIGHT, 0, 0, 0, 4, map_));
  printf("%d\n", shortestPathDistance(WIDTH, HEIGHT, 0, 0, 0, 4, map_));
  printf("%d\n", toReachTheGoal_Recursion(WIDTH, HEIGHT, 0, 0, 0, 4, map_));
  
  return 0;
}