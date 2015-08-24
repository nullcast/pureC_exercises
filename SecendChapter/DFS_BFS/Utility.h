#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool find(int *data, int num, int **array);
int** nextPos(int width, int height, int x, int y, int** map);
void freeArray(int num, int ***array);