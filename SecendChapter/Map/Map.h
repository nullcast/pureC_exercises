#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 1000000

int dijkstra(int s, int g, int num, int **array, int *distance, int *path);
void warshallFloyd(int num, int **array);
