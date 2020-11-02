#include "testcase.h"
#include "interface.h"

void StructLink(struct ListNode *arr, uint32 num)
{
    uint32 idx;
    for (idx = 0; idx < (num - 1); idx++) {
        arr[idx].next = &arr[idx + 1];
    }
    arr[num - 1].next = NULL;
}

void testcase1(void)
{
    struct ListNode arr[] = {{1, NULL}, {2, NULL}, {3, NULL}, {4, NULL}, {5, NULL}};
    StructLink(arr, ARRAY_SIZE(arr));
	display_result(getKthFromEnd(arr, 2) == &arr[3], __FUNCTION__);
}

void testcase2(void)
{
    struct ListNode arr[] = {{1, NULL}, {2, NULL}, {3, NULL}, {4, NULL}, {5, NULL}};
    StructLink(arr, ARRAY_SIZE(arr));
	display_result(getKthFromEnd(arr, 1) == &arr[4], __FUNCTION__);
}

void testcase3(void)
{
    struct ListNode arr[] = {{1, NULL}, {2, NULL}, {3, NULL}, {4, NULL}, {5, NULL}};
    StructLink(arr, ARRAY_SIZE(arr));
	display_result(getKthFromEnd(arr, 5) == &arr[0], __FUNCTION__);
}

/* 该用例用于测试性能用例 */
void testcase4(void)
{
    struct ListNode arr[10000] = {{0}};
    StructLink(arr, ARRAY_SIZE(arr));
	display_result(getKthFromEnd(arr, 1000) == &arr[0], __FUNCTION__);
}

void testcase(void)
{
	testcase1();
    //testcase2();
    //testcase3();
    //testcase4();
}