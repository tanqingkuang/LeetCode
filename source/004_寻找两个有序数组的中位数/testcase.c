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

void testcase3(void)
{
	int nums2[] = {3, 4};
	double rst = findMedianSortedArrays(NULL, 0, nums2, ARRAY_SIZE(nums2));
	if (fabs(rst - 3.5) <= 0.0001) {
		set_console_color(10);
		printf("test3 : OK\r\n");
	} else {
		set_console_color(12);
		printf("test3 : Err excp(%lf) != rst(%lf)\r\n", (double)3.5, rst);
	}
}

void testcase4(void)
{
	int nums1[] = {2, 3};
	int nums2[] = {1};
	double rst = findMedianSortedArrays(nums1, ARRAY_SIZE(nums1), nums2, ARRAY_SIZE(nums2));
	if (fabs(rst - 2) <= 0.0001) {
		set_console_color(10);
		printf("test4 : OK\r\n");
	} else {
		set_console_color(12);
		printf("test4 : Err excp(%lf) != rst(%lf)\r\n", (double)2, rst);
	}
}

void testcase5(void)
{
	int nums1[] = {2, 3, 4, 5};
	int nums2[] = {1};
	double rst = findMedianSortedArrays(nums1, ARRAY_SIZE(nums1), nums2, ARRAY_SIZE(nums2));
	if (fabs(rst - 3) <= 0.0001) {
		set_console_color(10);
		printf("test5 : OK\r\n");
	} else {
		set_console_color(12);
		printf("test5 : Err excp(%lf) != rst(%lf)\r\n", (double)3, rst);
	}
}

void testcase(void)
{
	testcase1();
	testcase2();
	testcase3();
	testcase4();
	testcase5();
}