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
	struct ListNode arr1[] = {{1, &arr1[1]}, {2, &arr1[2]}, {3, &arr1[3]}, {4, &arr1[4]}, {5, NULL}};
	struct ListNode *rst = reverseKGroup(arr1, 2);
	int excp[] = {2, 1, 4, 3, 5};
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
	struct ListNode *rst = reverseKGroup(arr1, 3);
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
	struct ListNode arr1[] = {{1, &arr1[1]}, {2, &arr1[2]}, {3, &arr1[3]}, {4, &arr1[4]}, {5, NULL}};
	struct ListNode *rst = reverseKGroup(arr1, 3);
	int excp[] = {3, 2, 1, 4, 5};
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
	struct ListNode *rst = reverseKGroup(arr1, 3);
	int excp[] = {3, 2, 1, 6, 5, 4};
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
	struct ListNode arr1[] = {{1, &arr1[1]}, {2, &arr1[2]}, {3, &arr1[3]}, {4, NULL}};
	struct ListNode *rst = reverseKGroup(arr1, 4);
	int excp[] = {4, 3, 2, 1};
	int flag = checkRst(rst, excp, ARRAY_SIZE(excp));
	
	if (flag == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase6(void)
{
	struct ListNode arr1[] = {
		{1, &arr1[1]}, {2, &arr1[2]}, {3, &arr1[3]}, {4, &arr1[4]},
		{5, &arr1[5]}, {6, &arr1[6]}, {7, &arr1[7]}, {8, NULL}
	};
	struct ListNode *rst = reverseKGroup(arr1, 4);
	int excp[] = {4, 3, 2, 1, 8, 7, 6, 5};
	int flag = checkRst(rst, excp, ARRAY_SIZE(excp));
	
	if (flag == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase7(void)
{
	struct ListNode arr1[] = {
		{1, &arr1[1]}, {2, &arr1[2]}, {3, &arr1[3]}, {4, &arr1[4]},
		{5, &arr1[5]}, {6, &arr1[6]}, {7, &arr1[7]}, {8, NULL}
	};
	struct ListNode *rst = reverseKGroup(arr1, 6);
	int excp[] = {6, 5, 4, 3, 2, 1, 7, 8};
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
	testcase6();
	testcase7();
}