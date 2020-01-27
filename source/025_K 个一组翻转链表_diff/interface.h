
#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "../../project/common.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseKGroup(struct ListNode* head, int k);

#endif