#include "../interface.h"

int search(int* nums, int numsSize, int target){
	int middle = (numsSize - 1) >> 1;
	int pos = -1;
	int start;
	int left = 0;

	if (nums == NULL || numsSize == 0) {
		return -1;
	}
	if (nums[middle] == target) {
		return middle;
	}
	if (numsSize == 1) {
		return -1;
	}

	if (nums[0] <= nums[middle]) {
		if (nums[0] <= target && target < nums[middle]) {
			left = 1;
		}
	} else {
		if (nums[0] <= target || target < nums[middle]) {
			left = 1;
		}
	}

	if (left == 1) {
		pos = search(nums, middle, target);
		start = 0;
	} else {
		pos = search(&nums[middle + 1], numsSize - middle - 1, target);
		start = middle + 1;
	}

	if (pos == -1) {
		return pos;
	} else {
		return pos + start;
	}
}