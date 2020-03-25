#include "../interface.h"

typedef struct NODE_ST{
	int start;
    int start_id;
	int gap;
	int num;
    struct NODE_ST *next;
} NODE_ST;

int SearchList(NODE_ST *head, int start_id, int data, int gap)
{
    NODE_ST *p = head->next;
    int exited = 0;
    while (p != NULL) {
        if (gap == p->gap) {

        }
        p = p->next;
    }
    return exited;
}

void InsertList(NODE_ST *head, int start_id, int data, int gap)
{
    NODE_ST *p = (NODE_ST *)malloc(sizeof(NODE_ST));
    p->start = data;
    p->start_id = start_id;
    p->gap = gap;
    p->num = 2;
    p->next = head->next;
    head->next = p;
}

void RefreshList(NODE_ST *head, int start_id, int dataBefore, int dataAfter)
{
    int gap = dataBefore - dataAfter;
    int exited;
    if (((uint32)abs(gap)) >= 0x1fffffff) {
        return;
    }
    exited = SearchList(head, start_id, dataBefore, gap);
    if (exited == 0) {
        InsertList(head, start_id, dataBefore, gap);
    }
}

void CreatList(NODE_ST *head, int* A, int ASize)
{
    int idx;
    int start_id;
    for (idx = 1; idx < ASize; idx++) {
        for (start_id = 0; start_id < idx; start_id++) {
            RefreshList(head, start_id, A[start_id], A[idx]);
        }
    }
}

int CalcList(NODE_ST *head)
{
    int map[1001] = {0};
    int rst = 0;
    head = head->next;
    while (head != NULL) {
        if (head->num > 2) {
            if (map[head->num] == 0) {
                map[head->num] = (int64)(head->num - 1) * (head->num - 2) / 2;
            }
            rst += map[head->num];
        }
        head = head->next;
    }
    return rst;
}

void DestoryList(NODE_ST *head)
{
    NODE_ST *freeNode = head->next;
    while (freeNode != NULL) {
        head->next = freeNode->next;
        free(freeNode);
        freeNode = head->next;
    }
}

int numberOfArithmeticSlices(int* A, int ASize)
{
    int rst;
    NODE_ST head = {0};
    CreatList(&head, A, ASize);
    rst = CalcList(&head);
    DestoryList(&head);
	return rst;
}