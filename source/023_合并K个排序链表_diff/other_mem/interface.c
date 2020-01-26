#include "../interface.h"

int g_data[10000] = {0};

void addTailList(struct ListNode* L1, struct ListNode* L2)
{
	while(L1->next != NULL) {
		L1 = L1->next;
	}
	L1->next = L2;
}

struct ListNode* combLists(struct ListNode** lists, int listsSize)
{
	struct ListNode* head = NULL;
	struct ListNode* last = NULL;
	int idx;
	for (idx = 0; idx < listsSize; idx++) {
		if (lists[idx] != NULL) {
			break;
		}
	}
	if (idx == listsSize) {
		return NULL;
	}
	head = lists[idx];
	last = head;

	for (idx += 1; idx < listsSize; idx++) {
		if (lists[idx] != NULL) {
			addTailList(last, lists[idx]);
			last = lists[idx];
		}
	}
	return head;
}

int dataGetLists(struct ListNode* head, int *data)
{
	int idx = 0;
	while(head != NULL) {
		data[idx++] = head->val;
		head = head->next;
	}
	return idx;
}

int my_compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void dataSetList(struct ListNode* head, int *data, int num)
{
	int idx;
	for (idx = 0; idx < num; idx++) {
		head->val = data[idx];
		head = head->next;
	}
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
	struct ListNode* head = combLists(lists, listsSize);
	int num;
	if (head == NULL) {
		return head;
	}
	memset(g_data, 0, sizeof(g_data));
	num = dataGetLists(head, g_data);
	qsort(g_data, num, sizeof(g_data[0]), my_compare);
	dataSetList(head, g_data, num);
	return head;
}