#include "../interface.h"

bool checkLeftNum(struct ListNode* head, int k, struct ListNode **end)
{
	while (k > 0) {
		if (head == NULL) {
			return FALSE;
		}
		k--;
		*end = head;
		head = head->next;
	}
	return TRUE;
}

struct ListNode *getLastNode(struct ListNode *head, struct ListNode *end)
{
	while(head->next != end) {
		head = head->next;
	}
	return head;
}

void exchangeList(struct ListNode *head_last, struct ListNode *head, struct ListNode *end, struct ListNode *end_last, int num)
{
	struct ListNode *head_next = head->next;
	struct ListNode *end_next = end->next;
	if (num > 2) {
		head_last->next = end;
		end->next = head_next;
		end_last->next = head;
		head->next = end_next;
	} else {
		head_last->next = end;
		end->next = head;
		head->next = end_next;
	}
}

struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	struct ListNode rst_last = {0, head};
	struct ListNode *head_last = &rst_last;
	struct ListNode *end = NULL;

	while (checkLeftNum(head, k, &end) == TRUE) {
		struct ListNode *next_head_last = head;
		int num = k;
		while (num > 1) {
			struct ListNode *end_last = getLastNode(head_last, end);
			exchangeList(head_last, head, end, end_last, num);
			head_last = end;
			head = head_last->next;
			end = end_last;
			num -= 2;
		}
		head_last = next_head_last;
		head = head_last->next;
	}
	return rst_last.next;
}
