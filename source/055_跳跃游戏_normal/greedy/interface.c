#include "../interface.h"

bool canJump(int *nums, int numsSize)
{
    int idx = numsSize - 2;
    int gap = 0;
    for (; idx >= 0; idx--) {
        if (nums[idx] > gap) {
            gap = 0;
        } else {
            gap++;
        }
    }
    
    if (gap > 0) {
        return 0;
    } else {
        return 1;
    }
}