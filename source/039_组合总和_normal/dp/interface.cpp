#include "../interface.h"

int upperArray(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int lowerNum(int* candidates, int candidatesSize, int target)
{
    int idx = 0;
    for (; idx < candidatesSize; idx++) {
        if (candidates[idx] > target) {
            return idx;
        }
    }
    return candidatesSize;
}

/* 完成candidates升序排序，并且完成裁剪 */
int candidatesFilter(int* candidates, int candidatesSize, int target)
{
    qsort(candidates, candidatesSize, sizeof(int), upperArray);
    return lowerNum(candidates, candidatesSize, target);
}

typedef struct NODE{
    int *data;
    int word_num;
    struct NODE *next;
} NODE;

typedef struct {
    int num; /* 用于记录个数 */
    NODE *rst;
} ARRAY;

ARRAY g_map[501] = {0};

void clearList(NODE *head)
{
    if (head == NULL) return;
    while (head->next != NULL) {
        NODE *node = head->next;
        head->next = head->next->next;
        free(node);
    }
    free(head);
}

void clearMap(int target)
{
    for (int idx = 0; idx <= target; idx++) {
        if (g_map[idx].rst == NULL) continue;
        clearList(g_map[idx].rst);
        g_map[idx].rst = NULL;
        g_map[idx].num = 0;
    }
}

void pushList(ARRAY *dest, NODE *rst, int cand)
{
    if (rst == NULL) { /* 特殊处理 */
        NODE *p = (NODE *)malloc(sizeof(NODE));
        p->data = (int *)malloc(sizeof(int));
        p->data[0] = cand;
        p->word_num = 1;
        p->next = dest->rst;
        dest->rst = p;
        dest->num += 1;
        return;
    }

    while (rst != NULL) {
        NODE *p = (NODE *)malloc(sizeof(NODE));
        p->data = (int *)malloc(sizeof(int) * (rst->word_num + 1));
        p->word_num = rst->word_num + 1;
        memcpy(p->data, rst->data, sizeof(int) * rst->word_num);
        p->data[rst->word_num] = cand;

        rst = rst->next;
        p->next = dest->rst;
        dest->rst = p;
        dest->num += 1;
    }
    
}

void dp(int* candidates, int candidatesSize, int target)
{
    for (int idxCand = 0; idxCand < candidatesSize; idxCand++) { /* 对数组进行遍历 */
        pushList(&g_map[candidates[idxCand]], NULL, candidates[idxCand]); /* 0节点比较特殊，不需要判断rst */
        for (int idxMap = candidates[idxCand] + 1; idxMap <= target; idxMap++) { /* 对map进行遍历 */
            if (g_map[idxMap - candidates[idxCand]].num == 0) continue;
            pushList(&g_map[idxMap], g_map[idxMap - candidates[idxCand]].rst, candidates[idxCand]);
        }
    }
}

int **creatRst(int target, int* returnSize, int** returnColumnSizes)
{
    *returnSize = g_map[target].num;
    if (*returnSize == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    *returnSize = g_map[target].num;
    *returnColumnSizes = (int *)malloc(sizeof(int) * g_map[target].num);
    int **rst = (int **)malloc(sizeof(int *) * g_map[target].num);
    NODE *p = g_map[target].rst;
    int idx = 0;
    while (p != NULL) {
        (*returnColumnSizes)[idx] = p->word_num;
        rst[idx] = (int *)malloc(sizeof(int) * p->word_num);
        memcpy(rst[idx], p->data, sizeof(int)*p->word_num);
        p = p->next;
        idx++;
    }
    return rst;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    candidatesSize = candidatesFilter(candidates, candidatesSize, target);
    dp(candidates, candidatesSize, target);
    int **rst = creatRst(target, returnSize, returnColumnSizes);
    clearMap(target);
    return rst;
}