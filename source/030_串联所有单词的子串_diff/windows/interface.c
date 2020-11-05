#include "../interface.h"

typedef struct NODE_ST {
	int pos;
	struct NODE_ST *next;
} NODE_ST;

NODE_ST g_head[1000] = {0}; /* 每个单词的匹配位置,带头 */
int g_map[1000] = {0}; /* 用于存储相关节点还剩下多少个匹配个数 */
int g_len; /* 用于存储单词的长度 */

void insertNode(NODE_ST *head, int pos) /* 降序插入 */
{
    NODE_ST *p = (NODE_ST *)malloc(sizeof(NODE_ST));
    p->pos = pos;
    p->next = head->next;
    head->next = p;
}

void destoryNode(NODE_ST *head)
{
    while(head->next != NULL) {
        NODE_ST *p = head->next;
        head->next = p->next;
        free(p);
    }
}

/* 初始化环境 */
int initNodeMap(char *s, char **words, int wordsSize)
{
    int len = strlen(s);
    char *p_pos = NULL;
    int word_idx;
    g_len = strlen(words[0]);
    for (word_idx = 0; word_idx < wordsSize; word_idx++) { /* 计算每个节点的匹配情况 */
        p_pos = s;
        g_map[word_idx] = 0;
        while (1) {
            p_pos = strstr(p_pos, words[word_idx]);
            if (p_pos == NULL) {
                break;
            }
            g_map[word_idx]++;
            insertNode(&g_head[word_idx], p_pos - s);
            p_pos++;
        }
        if (g_map[word_idx] == 0) { /* 说明有单词没有匹配到，则提前报错结束 */
            return FALSE;
        }
    }
    return TRUE;
}

/* 销毁环境 */
void destoryNodeMap(int wordsSize)
{
    int word_idx;
    for (word_idx = 0; word_idx < wordsSize; word_idx++) {
        g_map[word_idx] = 0;
        destoryNode(&g_head[word_idx]);
    }
}

/* 核心查找函数 */
void findRst(char *s, char **words, int wordsSize, int*rst, int *returnSize)
{

}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    int ret;
	int len = strlen(s);
	int *rst = (int *)malloc(len * sizeof(int));
	*returnSize = 0;
	if (len == 0 || wordsSize == 0) {
        return NULL;
    }
	ret = initNodeMap(s, words, wordsSize);
    if (ret == TRUE) { /* FLASE说明有节点没有匹配到，那么一定没有答案，因此就不用了 */
        findRst(s, words, wordsSize, rst, returnSize);
    }
    destoryNodeMap(wordsSize);
	return rst;
}