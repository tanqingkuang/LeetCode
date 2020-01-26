#include "../../../project/common.h"

void combinMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int *rst, int numsRst)
{
	int idx_rst;
	int idx_nums1 = 0;
	int idx_nums2 = 0;
	for (idx_rst = 0; idx_rst < numsRst; idx_rst++) {
		if (idx_nums1 == nums1Size || idx_nums2 == nums2Size) {
			break;
		}
		if (nums1[idx_nums1] < nums2[idx_nums2]) {
			rst[idx_rst] = nums1[idx_nums1];
			idx_nums1++;
		} else {
			rst[idx_rst] = nums2[idx_nums2];
			idx_nums2++;
		}
	}

	if (idx_nums1 == nums1Size) {
		memcpy(&rst[idx_rst], &nums2[idx_nums2], MIN(nums2Size - idx_nums2, numsRst - idx_rst) * sizeof(int));
	} else if (idx_nums2 == nums2Size) {
		memcpy(&rst[idx_rst], &nums1[idx_nums1], MIN(nums1Size - idx_nums1, numsRst - idx_rst) * sizeof(int));
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	/* 
	为了不分类讨论奇偶特性，此处使用了中位左和中位右的小技巧：
	例如：0、1、2共3个，中位左和中位右都为1
	例如：0、1、2、3共4个，中位左和中位右分别为1、2
	无论哪种情况，真正的中位数都是中位左和中位右的平均值
	*/
	int idx_middle_left = (nums1Size + nums2Size - 1) / 2;
	int idx_middle_right = (nums1Size + nums2Size) / 2;
	int *p = (int *)malloc((idx_middle_right + 1) * sizeof(int));
	double rst;
	combinMedianSortedArrays(nums1, nums1Size, nums2, nums2Size, p, idx_middle_right + 1);
	rst = (p[idx_middle_left] + p[idx_middle_right]) / (double)2.0;
	free(p);
	return rst;
}