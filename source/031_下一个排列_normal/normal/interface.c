#include "../interface.h"

/* 在一个降序数据中找到一个比data大且最接近他的数字，此处可以使用二分优化 */
int findBigger(int *nums, int numsSize, int data)
{
	int idx = 1;
	for (; idx < numsSize; idx++) {
		if (nums[idx] <= data) {
			break;
		}
	}
    return idx - 1;
}

int compare_int(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void nextPermutation(int* nums, int numsSize){
	int idx;

	/* 找到一个idx，使得idx及其之后是降序，idx比idx-1大 */
	for (idx = numsSize - 1; idx >= 1; idx--) {
		if (nums[idx] > nums[idx - 1]) {
			break;
		}
	}
	if (idx >= 1) { /* 在idx及其之后的数据找到一个比idx-1大的最小数据，并进行交换 */
		int pos = findBigger(&nums[idx], numsSize - idx, nums[idx - 1]) + idx;
		int tmp = nums[idx - 1];
		nums[idx - 1] = nums[pos];
		nums[pos] = tmp;
	}

	/* 对idx及其之后的数据进行升序排列 */
	qsort(&nums[idx], numsSize - idx, sizeof(int), compare_int);
}