#include "../interface.h"

int findFirst(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = (left + right) >> 1;
    while (left < right) {
        if (nums[mid] < target) { /* [mid+1, right] */
            left = mid + 1;
        } else if (nums[mid] == target) { /* [left, mid] */
            right = mid;
        } else { /* [left, mid-1] */
            right = mid - 1;
        }
        mid = (left + right) >> 1;
    }
    if (nums[left] == target) return left;
    return -1;
}

int findLast(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = (left + right + 1) >> 1;
    while (left < right) {
        if (nums[mid] < target) { /* [mid+1, right] */
            left = mid + 1;
        } else if (nums[mid] == target) { /* [mid, right] */
            left = mid;
        } else { /* [left, mid-1] */
            right = mid - 1;
        }
        mid = (left + right + 1) >> 1;
    }
    if (nums[mid] == target) return mid;
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *rst = (int *)malloc(2 * sizeof(int));
    rst[0] = rst[1] = -1;
    *returnSize = 2;
    if (numsSize == 0) return rst;

    int left = findFirst(nums, numsSize, target);
    if (left == -1) return rst;
    int right = findLast(nums, numsSize, target);
    rst[0] = left;
    rst[1] = right;
    
    return rst;
}