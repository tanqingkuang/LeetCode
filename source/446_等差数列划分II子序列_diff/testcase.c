#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	int A[] = {2, 4, 6, 8, 10};
	int rst = numberOfArithmeticSlices(A, ARRAYSIZE(A));
	int excp = 7;
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
	int A[] = {4, 2, 4, 6, 8, 10};
	int rst = numberOfArithmeticSlices(A, ARRAYSIZE(A));
	int excp = 10;
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
	int A[] = {7, 7, 7, 7, 7};
	int rst = numberOfArithmeticSlices(A, ARRAYSIZE(A));
	int excp = 7;
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
}