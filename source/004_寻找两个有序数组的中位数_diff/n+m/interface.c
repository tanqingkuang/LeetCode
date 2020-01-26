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
	Ϊ�˲�����������ż���ԣ��˴�ʹ������λ�����λ�ҵ�С���ɣ�
	���磺0��1��2��3������λ�����λ�Ҷ�Ϊ1
	���磺0��1��2��3��4������λ�����λ�ҷֱ�Ϊ1��2
	���������������������λ��������λ�����λ�ҵ�ƽ��ֵ
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