#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	int nums[] = {2,3,1,1,4};
	bool rst = canJump(nums, ARRAY_SIZE(nums));
	bool excp = 1;
    display_result(rst == excp, __FUNCTION__);
}

void testcase2(void)
{
	int nums[] = {3, 2, 1, 0,4};
	bool rst = canJump(nums, ARRAY_SIZE(nums));
	bool excp = 0;
	display_result(rst == excp, __FUNCTION__);
}

void testcase(void)
{
	testcase1();
	testcase2();
}