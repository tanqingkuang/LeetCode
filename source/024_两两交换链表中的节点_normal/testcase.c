#include "testcase.h"
#include "interface.h"

bool checkRst(struct ListNode *rst, int *excp, int num)
{
	int idx;
	for(idx = 0; idx < num; idx++) {
		if (rst == NULL) {
			return FALSE;
		}
		if (rst->val != excp[idx]) {
			return FALSE;
		}
		rst = rst->next;
	}
	if (rst != NULL) {
		return FALSE;
	}
	return TRUE;
}

void testcase1(void)
{
	struct ListNode arr1[] = {{1, &arr1[1]}, {2, &arr1[2]}, {3, &arr1[3]}, {4, NULL}};
	struct ListNode *rst = swapPairs(arr1);
	int excp[] = {2, 1, 4, 3};
	int flag = checkRst(rst, excp, ARRAY_SIZE(excp));
	
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
	struct ListNode *arr1 = NULL;
	struct ListNode *rst = swapPairs(arr1);
	int excp[] = {2, 1, 4, 3};
	int flag = checkRst(rst, excp, 0);
	
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
	struct ListNode arr1[] = {{1, &arr1[1]}, {2, &arr1[2]}, {4, NULL}};
	struct ListNode *rst = swapPairs(arr1);
	int excp[] = {2, 1, 4};
	int flag = checkRst(rst, excp, ARRAY_SIZE(excp));
	
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
	struct ListNode arr1[] = {{1, &arr1[1]}, {2, &arr1[2]}, {3, &arr1[3]}, {4, &arr1[4]}, {5, &arr1[5]}, {6, NULL}};
	struct ListNode *rst = swapPairs(arr1);
	int excp[] = {2, 1, 4, 3, 6, 5};
	int flag = checkRst(rst, excp, ARRAY_SIZE(excp));
	
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
	struct ListNode arr1[] = {{1, &arr1[1]}, {2, &arr1[2]}, {3, &arr1[3]}, {4, &arr1[4]}, {6, NULL}};
	struct ListNode *rst = swapPairs(arr1);
	int excp[] = {2, 1, 4, 3, 6};
	int flag = checkRst(rst, excp, ARRAY_SIZE(excp));
	
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