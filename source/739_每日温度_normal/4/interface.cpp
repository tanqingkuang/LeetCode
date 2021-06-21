#include "../interface.h"

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int *rst = (int *)malloc(sizeof(int) * temperaturesSize);
    rst[temperaturesSize - 1] = 0;

    for (int date = temperaturesSize - 2; date >= 0; date--) {
        int after_date = date + 1;
        while (1) {
            if (temperatures[date] < temperatures[after_date]) {
                rst[date] = after_date - date;
                break;
            }
            if (rst[after_date] == 0) {
                rst[date] = 0;
                break;
            }
            if (temperatures[date] == temperatures[after_date]) {
                rst[date] = rst[after_date] + after_date - date;
                break;
            }
            after_date = after_date + rst[after_date];
        }
    }

    *returnSize = temperaturesSize;
    return rst;
}