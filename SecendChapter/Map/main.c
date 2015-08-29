#include "Map.h"
#define NUM 5

int a[NUM][NUM] = {
  {INF, 8, 15, 2, INF},
  {12, INF, 10, INF, 70},
  {15, 11, INF, 13, 20},
  {1, INF, 20, INF, 7},
  {INF, 10, 11, 5, INF}
};

int main() {
  int *array[NUM], distance[NUM], path[NUM];
  int i,node;
  for (i=0; i<NUM; i++)
    array[i] = a[i];
  node = dijkstra(1,4,NUM,array,distance,path);
  
  printf("dijkstra(2,3) = %d\n", distance[node]);
  puts("path");
  for (i=0; i<NUM; i++)
    printf("%d ", path[i]);
  puts("");
  
  puts("");
  puts("warshallFloyd");
  warshallFloyd(NUM, array);
  printf("2=>3 = %d\n", array[2][3]);
  printf("4=>2 = %d\n", array[4][2]);
  
}