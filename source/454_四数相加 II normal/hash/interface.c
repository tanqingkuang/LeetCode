#include "../interface.h"

typedef struct NODE {
    int data;
    int cnt;
    struct NODE *next;
} NODE;

#define MASK_LEN 15 /* 该数据代表了hash的散列度，越大空间消耗越大，碰撞越小 */

NODE g_map0[2][1 << MASK_LEN] = {0}; /* g_map0[0]正数, g_map0[1]负数 */
NODE g_map1[2][1 << MASK_LEN] = {0};

#define memset_s(src, len, dest, cnt) memset(src, dest, cnt)
#define memcpy_s(src, len, dest, cnt) memcpy(src, dest, cnt)
#define memcmp_s(src, len, dest, cnt) memcmp(src, dest, cnt)
#define ARRAY_SIZE(_X_) (sizeof((_X_)) / sizeof((_X_)[0]))

NODE *findList(NODE *head, int data)
{
    NODE *p = head->next;
    while (p != NULL) {
        if (p->data == data) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void insertMap(NODE map[2][1 << MASK_LEN], int data)
{
    int delay = abs(data) & ((1 << MASK_LEN) - 1);
    NODE *head = (data >= 0) ? &map[0][delay] : &map[1][delay];
    NODE *p = findList(head, data);
    if (p == NULL) {
        p = (NODE *)malloc(sizeof(NODE));
        p->data = data;
        p->cnt = 1;
        p->next = head->next;
        head->next = p;
    } else {
        p->cnt += 1;
    }
    head->cnt++;
}

void initMap(NODE map[2][1 << MASK_LEN], int *arr0, int *arr1, int num)
{
    int idx_arr0;
    int idx_arr1;
    memset_s(map, sizeof(g_map0), 0, sizeof(g_map0));
    for (idx_arr0 = 0; idx_arr0 < num; idx_arr0++) {
        for (idx_arr1 = 0; idx_arr1 < num; idx_arr1++) {
            int data = arr0[idx_arr0] + arr1[idx_arr1];
            insertMap(map, data);
        }
    }
}

void deleteList(NODE *head)
{
    NODE *p = head->next;
    while(p != NULL) {
        head->next = p->next;
        free(p);
        p = head->next;
    }
}

void freeMap(NODE map[2][1 << MASK_LEN])
{
    int idx;
    for (idx = 0; idx < (1 << MASK_LEN); idx++) {
        deleteList(&map[0][idx]);
        deleteList(&map[1][idx]);
    }
}

int calucNode(NODE *node, NODE *head)
{
    NODE *p = head->next;
    while (p != NULL) {
        if ((p->data + node->data) == 0) {
            return p->cnt * node->cnt;
        }
        p = p->next;
    }
    return 0;
}

int calucList(NODE *head0, NODE *head1)
{
    NODE *p = head0->next;
    int rst = 0;
    while (p != NULL) {
        rst += calucNode(p, head1);
        p = p->next;
    }
    return rst;
}

int calucList0(NODE *head0, NODE *head1)
{
    NODE *p0 = head0->next;
    NODE *p1 = head1->next;
    int rst = 0;
    while (p0 != NULL) {
        if (p0->data == 0) {
            break;
        }
        p0 = p0->next;
    }
    while (p1 != NULL) {
        if (p1->data == 0) {
            break;
        }
        p1 = p1->next;
    }
    if (p1 != NULL && p0 != NULL) {
        return p1->cnt * p0->cnt;
    }
    return 0;
}

int calucRst(NODE map0[2][1 << MASK_LEN], NODE map1[2][1 << MASK_LEN])
{
    int rst = 0;
    int idx;

    rst += calucList0(&map0[0][0], &map1[0][0]);/* 此处可以优化，也可以不优化，视时间而定 */
    for (idx = 0; idx < (1 << MASK_LEN); idx++) {
        rst += calucList(&map0[0][idx], &map1[1][idx]);
        rst += calucList(&map0[1][idx], &map1[0][idx]);
    }
    return rst;
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
    int rst;
    initMap(g_map0, A, B, ASize);
    initMap(g_map1, C, D, ASize);
    rst = calucRst(g_map0, g_map1);
    freeMap(g_map0);
    freeMap(g_map1);
    return rst;
}