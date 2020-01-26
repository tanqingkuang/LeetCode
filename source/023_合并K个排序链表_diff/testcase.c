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
	struct ListNode arr1[] = {{1, &arr1[1]}, {4, &arr1[2]}, {5, NULL}};
	struct ListNode arr2[] = {{1, &arr2[1]}, {3, &arr2[2]}, {4, NULL}};
	struct ListNode arr3[] = {{2, &arr3[1]}, {6, NULL}};
	struct ListNode *map[] = {arr1, arr2, arr3};
	struct ListNode *rst = mergeKLists(map, ARRAY_SIZE(map));
	int excp[] = {1, 1, 2, 3, 4, 4, 5, 6};
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
	struct ListNode arr1[] = {{1, &arr1[1]}, {4, &arr1[2]}, {5, NULL}};
	struct ListNode *arr2 = NULL;
	struct ListNode arr3[] = {{2, &arr3[1]}, {6, NULL}};
	struct ListNode *map[] = {arr1, arr2, arr3};
	struct ListNode *rst = mergeKLists(map, ARRAY_SIZE(map));
	int excp[] = {1, 2, 4, 5, 6};
	int flag = checkRst(rst, excp, ARRAY_SIZE(excp));
	
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
	struct ListNode *arr1 = NULL;
	struct ListNode *arr2 = NULL;
	struct ListNode *arr3 = NULL;
	struct ListNode *map[] = {arr1, arr2, arr3};
	struct ListNode *rst = mergeKLists(map, ARRAY_SIZE(map));
	int excp[] = {1, 2, 4, 5, 6};
	int flag = checkRst(rst, excp, 0);
	
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
}