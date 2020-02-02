#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	int nums[] = {4,5,6,7,0,1,2};
	int target = 0;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 4;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase2(void)
{
	int nums[] = {4,5,6,7,0,1,2};
	int target = 3;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = -1;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase3(void)
{
	int nums[] = {4,5,6,7,0,1,2};
	int target = 4;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 0;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}
void testcase4(void)
{
	int nums[] = {4,5,6,7,0,1,2};
	int target = 5;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 1;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}
void testcase5(void)
{
	int nums[] = {4,5,6,7,0,1,2};
	int target = 6;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 2;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}
void testcase6(void)
{
	int nums[] = {4,5,6,7,0,1,2};
	int target = 7;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 3;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}
void testcase7(void)
{
	int nums[] = {4,5,6,7,0,1,2};
	int target = 1;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 5;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase8(void)
{
	int nums[] = {4,5,6,7,0,1,2};
	int target = 2;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 6;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase9(void)
{
	int nums[] = {3, 1};
	int target = 3;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 0;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase10(void)
{
	int nums[] = {7,8,1,2,3,4,5,6};
	int target = 2;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 3;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase11(void)
{
	int nums[] = {1, 3};
	int target = 3;
	int rst =  search(nums, ARRAY_SIZE(nums), target);
	int excp = 1;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase(void)
{
	testcase1();
	testcase2();
	testcase3();
	testcase4();
	testcase5();
	testcase6();
	testcase7();
	testcase8();
	testcase9();
	testcase10();
	testcase11();
}