#include "../interface.h"

struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode* rst = NULL;
	struct ListNode *p = NULL;
	if (head == NULL || head->next == NULL) {
		return head;
	}

	rst = head->next;
	p = rst->next;
	rst->next = head;
	head->next = p;

	head = rst->next;
	while (head->next != NULL && head->next->next != NULL) {
		struct ListNode *q = head->next->next->next;
		p = head->next;
		head->next = head->next->next;
		head->next->next = p;
		head = head->next->next;
		head->next = q;
	}
	return rst;
}