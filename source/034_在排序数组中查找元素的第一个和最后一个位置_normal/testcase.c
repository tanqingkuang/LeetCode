#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	int nums[] = {5, 7, 7, 8, 8, 10};
	int returnSize = 0;
	int *rst =  searchRange(nums, ARRAY_SIZE(nums), 8, &returnSize);
	int excp[] = {3, 4};
	if (memcmp(excp, rst, sizeof(excp)) == 0) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase2(void)
{
	int nums[] = {5, 7, 7, 8, 8, 10};
	int returnSize = 0;
	int *rst =  searchRange(nums, ARRAY_SIZE(nums), 6, &returnSize);
	int excp[] = {-1, -1};
	if (memcmp(excp, rst, sizeof(excp)) == 0) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase3(void)
{
	int nums[] = {5};
	int returnSize = 0;
	int *rst =  searchRange(nums, ARRAY_SIZE(nums), 5, &returnSize);
	int excp[] = {0, 0};
	if (memcmp(excp, rst, sizeof(excp)) == 0) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase4(void)
{
	int nums[] = {5};
	int returnSize = 0;
	int *rst =  searchRange(nums, ARRAY_SIZE(nums), 6, &returnSize);
	int excp[] = {-1, -1};
	if (memcmp(excp, rst, sizeof(excp)) == 0) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase(void)
{
	testcase1();
	testcase2();
	testcase3();
	testcase4();
}