#include "../interface.h"

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int *waitDays = (int *)malloc(sizeof(int) * temperaturesSize);
    for (int i = 0; i < temperaturesSize; i++) {
        waitDays[i] = 0;
        for (int j = i + 1; j < temperaturesSize; j++) {            
            if (temperatures[j] > temperatures[i]) {
                waitDays[i] = j - i;
                break;
            }
        }
    }
    *returnSize = temperaturesSize;
    return waitDays;
}