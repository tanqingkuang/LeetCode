#include "../interface.h"

/*
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣

ʾ����
����һ������: 1->2->3->4->5, �� k = 2.
�������� 4->5.

struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    /*�������нڵ�õ�������;
      �ҵ�������k���ڵ���Ϊͷ�ڵ������������*/
    int cnt, idx;
    struct ListNode* prehead = head;;
    for (cnt = 1; prehead->next != NULL; cnt++) {
        prehead = prehead->next;
    }
    for (idx = 1; idx <= cnt - k; idx++) {
        head = head->next;
    }
    return head;
}
