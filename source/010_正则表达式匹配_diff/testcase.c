#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	bool rst = isMatch("aa", "a");
    display_result(rst == FALSE, __FUNCTION__);
}

void testcase2(void)
{
	bool rst = isMatch("aa", "a*");
	display_result(rst == TRUE, __FUNCTION__);
}

void testcase3(void)
{
	bool rst = isMatch("ab", ".*");
	display_result(rst == TRUE, __FUNCTION__);
}

void testcase4(void)
{
	bool rst = isMatch("aab", "c*a*b");
	display_result(rst == TRUE, __FUNCTION__);
}

void testcase5(void)
{
	bool rst = isMatch("mississippi", "mis*is*p*.");
	display_result(rst == FALSE, __FUNCTION__);
}

void testcase6(void)
{
	bool rst = isMatch("a", "ab*");
	display_result(rst == TRUE, __FUNCTION__);
}

void testcase7(void)
{
	bool rst = isMatch("ab", ".*c");
	display_result(rst == FALSE, __FUNCTION__);
}

void testcase8(void)
{
	bool rst = isMatch("a", ".*..a*");
	display_result(rst == FALSE, __FUNCTION__);
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
}