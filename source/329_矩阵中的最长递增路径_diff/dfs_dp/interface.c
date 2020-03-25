#include "../interface.h"
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int g_map[1000][1000] = {{0}};

int checkNextPos(int** matrix, int matrixSize, int matrixColSize, int x, int y, int dir[2])
{
    int x_next = x + dir[0];
    int y_next = y + dir[1];
    if (x_next >= matrixSize) {
        return 0;
    }
    if (y_next >= matrixColSize) {
        return 0;
    }
    if (x_next < 0) {
        return 0;
    }
    if (y_next < 0) {
        return 0;
    }
    if (matrix[x][y] >= matrix[x_next][y_next]) {
        return 0;
    }
    return 1;
}

int findLongestDfs(int** matrix, int matrixSize, int matrixColSize, int x, int y)
{
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int idx;
    int max = 1;
    if (g_map[x][y] != 0) {
        return g_map[x][y];
    }
    for (idx = 0; idx < 4; idx++) {
        if (checkNextPos(matrix, matrixSize, matrixColSize, x, y, dir[idx]) == 1) {
            max = MAX(max, findLongestDfs(matrix, matrixSize, matrixColSize, x + dir[idx][0] , y + dir[idx][1]) + 1);
        }
    }
    g_map[x][y] = max;
    return g_map[x][y];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize)
{
    int x;
    int y;
    int max = 0;
    memset(g_map, 0, sizeof(g_map));
    for (x = 0; x < matrixSize; x++) {
        for (y = 0; y < matrixColSize[0]; y++) {
            if (g_map[x][y] == 0) {
                findLongestDfs(matrix, matrixSize, *matrixColSize, x, y);
            }
            max = MAX(max, g_map[x][y]);
        }
    }
    return max;
}