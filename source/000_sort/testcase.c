#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
    int arr[] = {1,2,3};
    int excp[] = {1,2,3};
    int newNumsSize = 0;
    newNumsSize = removeDuplicates(arr, ARRAYSIZE(arr));
	if (memcmp(arr, excp, newNumsSize) == 0 && newNumsSize ==  ARRAYSIZE(excp)) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
    } else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}
void testcase2(void)
{
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    int excp[] = {0,1,2,3,4};
    int newNumsSize = 0;
    newNumsSize = removeDuplicates(arr, ARRAYSIZE(arr));
	if (memcmp(arr, excp, newNumsSize) == 0 && newNumsSize ==  ARRAYSIZE(excp)) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
    } else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}
void testcase3(void)
{
    int arr[] = {1,1,1};
    int excp[] = {1};
    int newNumsSize = 0;
    newNumsSize = removeDuplicates(arr, ARRAYSIZE(arr));
	if (memcmp(arr, excp, newNumsSize) == 0 && newNumsSize ==  ARRAYSIZE(excp)) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
    } else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}
void testcase4(void)
{
    int arr[] = {1,2,2,3};
    int excp[] = {1,2,3};
    int newNumsSize = 0;
    newNumsSize = removeDuplicates(arr, ARRAYSIZE(arr));
	if (memcmp(arr, excp, newNumsSize) == 0 && newNumsSize ==  ARRAYSIZE(excp)) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
    } else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

#if 0
void testcase1(void)
{
    int arr[] = {3, 2, 5, 1, 7, 6, 4};
    int excp[] = {3, 2, 5, 4, 1, 6, 7};
    nextPermutation(arr, ARRAYSIZE(arr));
	if (memcmp(arr, excp, ARRAYSIZE(arr)) == 0) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase2(void)
{
    int arr[] = {3, 2, 4, 5, 4, 9, 7, 6, 4};
    int excp[] = {3, 2, 4, 5, 6, 4, 4, 7, 9};
    nextPermutation(arr, ARRAYSIZE(arr));
	if (memcmp(arr, excp, ARRAYSIZE(arr)) == 0) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase3(void)
{
    int arr[] = {3, 2, 1};
    int excp[] = {1, 2, 3};
    nextPermutation(arr, ARRAYSIZE(arr));
	if (memcmp(arr, excp, ARRAYSIZE(arr)) == 0) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase4(void)
{
    int arr[] = {2, 1, 3};
    int excp[] = {2, 3, 1};
    nextPermutation(arr, ARRAYSIZE(arr));
	if (memcmp(arr, excp, ARRAYSIZE(arr)) == 0) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}
#endif

void testcase(void)
{
	testcase1();
    testcase2();
    testcase3();
    testcase4();
}
