#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	int nums1[] = {1, 3};
	int nums2[] = {2};
	double rst = findMedianSortedArrays(nums1, ARRAY_SIZE(nums1), nums2, ARRAY_SIZE(nums2));
	if (fabs(rst - 2.0) <= 0.0001) {
		set_console_color(10);
		printf("test1 : OK\n");
	} else {
		set_console_color(12);
		printf("test1 : Err\r\n");
	}
}

void testcase2(void)
{
	int nums1[] = {1, 2};
	int nums2[] = {3, 4};
	double rst = findMedianSortedArrays(nums1, ARRAY_SIZE(nums1), nums2, ARRAY_SIZE(nums2));
	if (fabs(rst - 2.5) <= 0.0001) {
		set_console_color(10);
		printf("test2 : OK\r\n");
	} else {
		set_console_color(12);
		printf("test2 : Err excp(%lf) != rst(%lf)\r\n", (double)2.5, rst);
	}
}

void testcase(void)
{
	testcase1();
	testcase2();
}