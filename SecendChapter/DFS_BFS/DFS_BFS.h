#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//DFS
bool toReachTheGoal(int width, int height, int x, int y, int gx, int gy, int** map);

//BFS
int shortestPathDistance(int width, int height, int x, int y, int gx, int gy, int** map);

//DFS_Recursion
bool toReachTheGoal_Recursion(int width, int height, int x, int y, int gx, int gy, int** map);