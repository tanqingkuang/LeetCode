#include "../interface.h"

typedef struct NODE_ST {
	int pos;
	struct NODE_ST *next;
} NODE_ST;

NODE_ST g_head[1000] = {0}; /* ÿ�����ʵ�ƥ��λ��,��ͷ */
int g_map[1000] = {0}; /* ���ڴ洢��ؽڵ㻹ʣ�¶��ٸ�ƥ����� */
int g_len; /* ���ڴ洢���ʵĳ��� */

void insertNode(NODE_ST *head, int pos) /* ������� */
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

/* ��ʼ������ */
int initNodeMap(char *s, char **words, int wordsSize)
{
    int len = strlen(s);
    char *p_pos = NULL;
    int word_idx;
    g_len = strlen(words[0]);
    for (word_idx = 0; word_idx < wordsSize; word_idx++) { /* ����ÿ���ڵ��ƥ����� */
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
        if (g_map[word_idx] == 0) { /* ˵���е���û��ƥ�䵽������ǰ������� */
            return FALSE;
        }
    }
    return TRUE;
}

/* ���ٻ��� */
void destoryNodeMap(int wordsSize)
{
    int word_idx;
    for (word_idx = 0; word_idx < wordsSize; word_idx++) {
        g_map[word_idx] = 0;
        destoryNode(&g_head[word_idx]);
    }
}

/* ���Ĳ��Һ��� */
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
    if (ret == TRUE) { /* FLASE˵���нڵ�û��ƥ�䵽����ôһ��û�д𰸣���˾Ͳ����� */
        findRst(s, words, wordsSize, rst, returnSize);
    }
    destoryNodeMap(wordsSize);
	return rst;
}