#include "../interface.h"

typedef struct NODE_ST {
	int pos;
	int len;
	int idx;
	struct NODE_ST *next;
	struct NODE_ST *last;
} NODE_ST;

NODE_ST g_head = {0};
int g_map[1000] = {0};
char g_mask[1000] = {0};

void insertNode(NODE_ST *head, NODE_ST *node) /* 按照升序插入 */
{
	NODE_ST *p = head;
	while (p->next != head && node->pos > p->next->pos) {
		p = p->next;
	}

	/* 此时node要插入p之后 */
	node->next = p->next;
	node->last = p;
	node->last->next = node;
	node->next->last = node;
}

void deleteNode(NODE_ST *node)
{
	node->last->next = node->next;
	node->next->last = node->last;
	g_map[node->idx]--;
	free(node);
}

void freeNode(NODE_ST *head, NODE_ST *node)
{
	NODE_ST *p = node;
	while (p->next != head) {
		p = p->next;
		free(p->last);
	}
	if (p != head) {
		free(p);
	}
	memset(g_map, 0, sizeof(g_map));
}

void setNodemap(NODE_ST *head, int pos, int len, int idx)
{
	NODE_ST *node = (NODE_ST *)malloc(sizeof(NODE_ST));
	node->pos = pos;
	node->len = len;
	node->idx = idx;
	insertNode(head, node);
	g_map[idx]++;
}

void initNodeMap(char * s, char ** words, int wordsSize)
{
	int idx = 0;
	char *pos = NULL;
	int len;
	int len_s = strlen(s);
	memset(&g_head, 0, sizeof(g_head));
	g_head.next = &g_head;
	g_head.last = &g_head;
	memset(g_map, 0, sizeof(g_map));
	for (; idx < wordsSize; idx++) {
		len = strlen(words[idx]);
		pos = s;
		while (1) {
			pos = strstr(pos, words[idx]);
			if (pos == NULL) {
				break;
			}
			setNodemap(&g_head, pos - s, len, idx);
			pos += 1;
		}
	}
}

int mapIsNULL(int wordsSize)
{
	int idx;
	for (idx = 0; idx < wordsSize; idx++) {
		if (g_head.next == &g_head) {
			return TRUE;
		}
	}
	return FALSE;
}

int checkMapbuild(int wordsSize)
{
	int idx;
	for (idx = 0; idx < wordsSize; idx++) {
		if (g_map[idx] == 0) {
			return FALSE;
		}
	}
	return TRUE;
}

uint32 checkAllRight(int wordsSize)
{
	int idx = 0;
	for (idx; idx < wordsSize; idx++) {
		if (g_mask[idx] == 0) {
			return FALSE;
		}
	}
	return TRUE;
}

uint32 checkNodeList(NODE_ST *head, NODE_ST *node, int pos_excp, int wordsSize)
{
	uint32 flag = 0;

	if (checkAllRight(wordsSize) == TRUE) {
		return TRUE;
	}

	while (pos_excp >= node->pos && node != head) {
		if (pos_excp == node->pos && g_mask[node->idx] == 0) {
			g_mask[node->idx] = 1;
			flag = checkNodeList(head, node->next, pos_excp + node->len, wordsSize);
			g_mask[node->idx] = 0;
			if (flag == TRUE) {
				return TRUE;
			}
		}
		node = node->next;
	}
	return FALSE;
}

int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize)
{
	int len = strlen(s);
	int *rst = (int *)malloc(len * sizeof(int));
	*returnSize = 0;
	if (len == 0 || wordsSize == 0) {
        return NULL;
    }
	initNodeMap(s, words, wordsSize);
	while (checkMapbuild(wordsSize) == TRUE) {
		if (checkNodeList(&g_head, g_head.next, g_head.next->pos, wordsSize) == TRUE) {
			rst[*returnSize] = g_head.next->pos;
			*returnSize += 1;
			if (*returnSize > 1) {
				if (rst[(*returnSize) - 2] == g_head.next->pos) {
					*returnSize -= 1;
				}
			}
		}
		deleteNode(g_head.next);
	}
	freeNode(&g_head, g_head.next);
	return rst;
}