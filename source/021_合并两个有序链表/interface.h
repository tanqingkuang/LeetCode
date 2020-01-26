#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "../../project/common.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

#endif