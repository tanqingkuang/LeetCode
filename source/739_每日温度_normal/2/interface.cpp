#include "../interface.h"

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize)
{
    int *waitDays = (int *)malloc(sizeof(int) * temperaturesSize);
    int lastRst = 0;
    for (int i = 0; i < temperaturesSize; i++) {
        waitDays[i] = 0;
        if (i > 0 && temperatures[i] == temperatures[i -1]) {
            if (lastRst != 0) {
                waitDays[i] = lastRst - 1;
            } 
            lastRst = waitDays[i];
            continue;
        }
        for (int j = i + 1; j < temperaturesSize; j++) {            
            if (temperatures[j] > temperatures[i]) {
                waitDays[i] = j - i;
                break;
            }
        }
        lastRst = waitDays[i];
    }
    *returnSize = temperaturesSize;
    return waitDays;
}