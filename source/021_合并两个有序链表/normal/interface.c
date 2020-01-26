#include "../interface.h"

struct ListNode* exchangByVal(struct ListNode** l1, struct ListNode** l2)
{
	struct ListNode *p;
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	if (*l1 == NULL) {
        *l1 = *l2;
        *l2 = NULL;
		return *l1;
	} else if (*l2 == NULL) {
		return *l1;
	}
	if ((*l1)->val > (*l2)->val) {
		p = *l1;
		*l1 = *l2;
		*l2 = p;
	}
	return *l1;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode *head = exchangByVal(&l1, &l2);
	struct ListNode *p;
	struct ListNode *l1_last;
	if (head == NULL) {
		return NULL;
	}
	l1_last = l1;
	l1 = l1->next;
	while(l1 != NULL && l2 != NULL) {
		if (l1->val <= l2->val) {
			l1 = l1->next;
		} else {
			p = l2->next;
			l2->next = l1;
			l1_last->next = l2;
			l2 = p;
		}
		l1_last = l1_last->next;
	}
	if (l1 == NULL) {
		l1_last->next = l2;
	}
	return head;
}