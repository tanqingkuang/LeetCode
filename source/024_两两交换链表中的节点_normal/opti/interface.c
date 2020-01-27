#include "../interface.h"

struct ListNode* swapPairs(struct ListNode* head)
{
	struct ListNode rst_last = {0, head};
	struct ListNode *head_last = &rst_last;

	while (head != NULL && head->next != NULL) {
		struct ListNode *p = head->next->next;
		head->next->next = head;
		head_last->next = head->next;
		head->next = p;
		head_last = head;
		head = head->next;
	}
	return rst_last.next;
}