#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	int nums[] = {2,3,1,1,4};
	bool rst = canJump(nums, ARRAY_SIZE(nums));
	bool excp = 1;
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
	int nums[] = {3, 2, 1, 0,4};
	bool rst = canJump(nums, ARRAY_SIZE(nums));
	bool excp = 0;
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
}