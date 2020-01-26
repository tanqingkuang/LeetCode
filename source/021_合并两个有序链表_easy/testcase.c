#include "testcase.h"
#include "interface.h"

bool checkRst(struct ListNode *rst, int *excp, int num)
{
	int idx;
	for(idx = 0; idx < num; idx++) {
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
	struct ListNode l1[] = {{1, &l1[1]}, {2, &l1[2]}, {4, NULL}};
	struct ListNode l2[] = {{1, &l2[1]}, {3, &l2[2]}, {4, NULL}};
	int excp[] = {1, 1, 2, 3, 4, 4};
	struct ListNode *rst = mergeTwoLists(l1, l2);
	bool flag = checkRst(rst, excp, ARRAY_SIZE(excp));
	
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
	int excp[] = {1, 1, 2, 3, 4, 4};
	struct ListNode *rst = mergeTwoLists(NULL, NULL);
	bool flag = checkRst(rst, excp, 0);
	
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
}