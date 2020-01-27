#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	int rst = divide(10, 3);
	int excp = 3;
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
	int rst = divide(7, -3);
	int excp = -2;
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
	int rst = divide(-2147483648, -1);
	int excp = 2147483647;
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
	int rst = divide(-2147483648, 1);
	int excp = -2147483648;
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
}