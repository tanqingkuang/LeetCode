#include "../interface.h"

char g_mem[200000] = {0};
int g_bytes_num = 0;
void *my_malloc(int byte_num)
{
    byte_num = ((byte_num + 7) >> 3) << 3;
    char *p = g_mem + g_bytes_num;
    g_bytes_num += byte_num;
    return p;
}

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
    int min;
    int min_num;
    struct NODE *next;
} NODE;

typedef struct {
    int num; /* 用于记录个数 */
    NODE *rst;
} ARRAY;

ARRAY g_map[501] = {0};

void clearMap(int target)
{
    g_bytes_num = 0;
    memset(g_map, 0, sizeof(g_map));
}

void pushList(ARRAY *dest, NODE *rst, int cand, int min, int min_num)
{
    if (rst == NULL) { /* 特殊处理 */
        NODE *p = (NODE *)my_malloc(sizeof(NODE));
        p->data = (int *)my_malloc(sizeof(int));
        p->data[0] = cand;
        p->word_num = 1;
        p->next = dest->rst;
        p->min = min;
        p->min_num = min_num;
        dest->rst = p;
        dest->num += 1;
        return;
    }

    while (rst != NULL) {
        if (rst->min > min) { 
            if (min_num != 1) {
                rst = rst->next;
                continue;
            }
        } else {
            if (min_num != (rst->min_num+1)) {
                rst = rst->next;
                continue;
            }
        }

        NODE *p = (NODE *)my_malloc(sizeof(NODE));
        p->data = (int *)my_malloc(sizeof(int) * (rst->word_num + 1));
        p->word_num = rst->word_num + 1;
        memcpy(p->data, rst->data, sizeof(int) * rst->word_num);
        p->data[rst->word_num] = cand;
        p->min = min;
        p->min_num = min_num;

        rst = rst->next;
        p->next = dest->rst;
        dest->rst = p;
        dest->num += 1;
    }
}

void dp(int* candidates, int candidatesSize, int target)
{
    int min = 0xfffffff;
    int min_num;
    for (int idxCand = (candidatesSize - 1); idxCand >= 0; idxCand--) { /* 对数组进行遍历 */
        if (candidates[idxCand] < min) {
            min = candidates[idxCand];
            min_num = 1;
        } else {
            min_num++;
        }
        for (int idxMap = target; idxMap >= candidates[idxCand]; idxMap--) { /* 对map进行遍历 */
            if (g_map[idxMap - candidates[idxCand]].num == 0) continue;
            pushList(&g_map[idxMap], g_map[idxMap - candidates[idxCand]].rst, candidates[idxCand], min, min_num);
        }
        if (min_num == 1) /* 只有第一次才搞起 */
            pushList(&g_map[candidates[idxCand]], NULL, candidates[idxCand], min, min_num); /* 0节点比较特殊，不需要判断rst */
    }
}

int **creatRst(int target, int* returnSize, int** returnColumnSizes)
{
    *returnSize = g_map[target].num;
    if (*returnSize == 0) {
        *returnColumnSizes = NULL;
        return NULL;
    }
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

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes)
{
    candidatesSize = candidatesFilter(candidates, candidatesSize, target);
    dp(candidates, candidatesSize, target);
    int **rst = creatRst(target, returnSize, returnColumnSizes);
    clearMap(target);
    return rst;
}