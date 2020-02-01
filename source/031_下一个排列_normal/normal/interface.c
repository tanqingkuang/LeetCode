#include "../interface.h"

/* ��һ�������������ҵ�һ����data������ӽ��������֣��˴�����ʹ�ö����Ż� */
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

	/* �ҵ�һ��idx��ʹ��idx����֮���ǽ���idx��idx-1�� */
	for (idx = numsSize - 1; idx >= 1; idx--) {
		if (nums[idx] > nums[idx - 1]) {
			break;
		}
	}
	if (idx >= 1) { /* ��idx����֮��������ҵ�һ����idx-1�����С���ݣ������н��� */
		int pos = findBigger(&nums[idx], numsSize - idx, nums[idx - 1]) + idx;
		int tmp = nums[idx - 1];
		nums[idx - 1] = nums[pos];
		nums[pos] = tmp;
	}

	/* ��idx����֮������ݽ����������� */
	qsort(&nums[idx], numsSize - idx, sizeof(int), compare_int);
}