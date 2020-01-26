#include "../../../project/common.h"

int checkRst(int* nums1, int nums1Size, int* nums2, int nums2Size, int i, int *hit)
{
	int j = (nums1Size + nums2Size) / 2 - i;
	if (j > nums2Size) {
		*hit = -1;
		return j;
	}
	if (j < 0) {
		*hit = 1;
		return j;
	}
	if (j != 0 && i != nums1Size) {
		if (nums2[j-1] > nums1[i]) { /* i过小 */
			*hit = -1;
			return j;
		}
	}
	if (i != 0 && j != nums2Size) {
		if (nums1[i-1] > nums2[j]) { /* i过大 */
			*hit = 1;
			return j;
		}
	}
	*hit = 0;
	return j;
}

void changeArrays(int** nums1, int *nums1Size, int** nums2, int *nums2Size)
{
	int *p;
	int tmp;
	if (*nums1Size <= *nums2Size) {
		return;
	}
	p = *nums1;
	*nums1 = *nums2;
	*nums2 = p;
	tmp = *nums1Size;
	*nums1Size = *nums2Size;
	*nums2Size = tmp;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int left = 0;
	int right;
	int i;
	int j;
	int flag = 0;
	int right_min;
	int left_max;
	changeArrays(&nums1, &nums1Size, &nums2, &nums2Size);
	right = nums1Size;
	if (nums1Size == 0) {
		return (nums2[(nums2Size-1)/2] + nums2[nums2Size/2]) / (double)2.0;
	}

	/* 二分法查找i和j */
	while (1) {
		i = (left + right) / 2;
		j = checkRst(nums1, nums1Size, nums2, nums2Size, i, &flag);
		if (flag == 0) {
			break;
		} else if (flag == 1) { /* i过大则在left和i-1之间 */
			right = i - 1;
		} else { /* i过大则在i+1和right之间 */
			left = i + 1;
		}
	}

	/* 针对i和j讨论各种极限情况 */
	if (i == nums1Size) {
		right_min = nums2[j];
	} else if (j == nums2Size) {
		right_min = nums1[i];
	} else {
		right_min = MIN(nums1[i], nums2[j]);
	}
	if (i == 0) {
		left_max = nums2[j-1];
	} else if (j == 0) {
		left_max = nums1[i-1];
	} else {
		left_max = MAX(nums1[i-1], nums2[j-1]);
	}
	if ((nums1Size + nums2Size) % 2 == 1) { /* 说明是奇数 */
		return right_min;
	} else {
		return (left_max + right_min)/ (double)2.0;
	}
}