#include "testcase.h"
#include "interface.h"

bool checkRst(int *rst, int rstSize, int *excp, int excpSize)
{
	int idx_rst;
	if (rstSize != excpSize) {
		return FALSE;
	}

	for (idx_rst = 0; idx_rst < rstSize; idx_rst++) {
		if (rst[idx_rst] != excp[idx_rst]) {
			return FALSE;
		}
	}

	return TRUE;
}

void testcase1(void)
{
	int rst[] = {1, 2, 3};
	int excp[] = {1, 3, 2};
	int flag;
	nextPermutation(rst, ARRAY_SIZE(rst));
	flag = checkRst(rst, ARRAY_SIZE(rst), excp, ARRAY_SIZE(excp));
	if (flag == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase2(void)
{
	int rst[] = {3, 2, 1};
	int excp[] = {1, 2, 3};
	int flag;
	nextPermutation(rst, ARRAY_SIZE(rst));
	flag = checkRst(rst, ARRAY_SIZE(rst), excp, ARRAY_SIZE(excp));
	if (flag == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase3(void)
{
	int rst[] = {1, 1, 5};
	int excp[] = {1, 5, 1};
	int flag;
	nextPermutation(rst, ARRAY_SIZE(rst));
	flag = checkRst(rst, ARRAY_SIZE(rst), excp, ARRAY_SIZE(excp));
	if (flag == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase4(void)
{
	int rst[] = {1};
	int excp[] = {1};
	int flag;
	nextPermutation(rst, ARRAY_SIZE(rst));
	flag = checkRst(rst, ARRAY_SIZE(rst), excp, ARRAY_SIZE(excp));
	if (flag == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase5(void)
{
	int rst[] = {1, 3, 2, 1, 0};
	int excp[] = {2, 0, 1, 1, 3};
	int flag;
	nextPermutation(rst, ARRAY_SIZE(rst));
	flag = checkRst(rst, ARRAY_SIZE(rst), excp, ARRAY_SIZE(excp));
	if (flag == TRUE) {
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
	testcase5();
}