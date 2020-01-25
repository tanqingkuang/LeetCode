#include "../../../project/common.h"

char *g_str[] = { NULL, NULL, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void getSizeOfRst(char * digits, int* returnSize)
{
	int len = strlen(digits);
	int idx;
	*returnSize = 1;
	for (idx = 0; idx < len; idx++) {
		*returnSize *= strlen(g_str[digits[idx] - '0']);
	}
}

char **getTableOfRst(int size, int len)
{
	char **table = (char **)malloc(sizeof(char *) * size);
	int idx;
	for (idx = 0; idx < size; idx++) {
		table[idx] = (char *)malloc(sizeof(char) * len);
		memset(table[idx], 0, len);
	}
	return table;
}

void getRst(int data, int idx, int now_size, char **table)
{
	int num_str = strlen(g_str[data]); /* 该数字对应字母的个数，也是需要复制的次数 */
	int idx_size;
	int idx_num_str;
	int size;

	/* 先将已经有的数据进行复制 */
    if (idx != 0) {
        for (idx_size = 0; idx_size < now_size; idx_size++) {
            for (idx_num_str = 1; idx_num_str < num_str; idx_num_str++) {
                strcpy(table[idx_size + idx_num_str * now_size], table[idx_size]);
            }
        }
    }

	/* 添加后缀 */
	size = 0;
	for (idx_num_str = 0; idx_num_str < num_str; idx_num_str++) {
		for (idx_size = 0; idx_size < now_size; idx_size++) {
			table[size][idx] = g_str[data][idx_num_str];
			size++;
		}
		idx_size++;
	}
}

char **letterCombinations(char * digits, int* returnSize){
	int len = strlen(digits) + 1;
	char **table = NULL;
	int idx_dig;
	int now_size = 1;
	if (digits == NULL || digits[0] == 0) {
		*returnSize = 0;
		return NULL;
	}

	getSizeOfRst(digits, returnSize);
	table = getTableOfRst(*returnSize, len);

	for (idx_dig = 0; idx_dig < strlen(digits); idx_dig++) {
		int data = digits[idx_dig] - '0';
		getRst(digits[idx_dig] - '0', idx_dig, now_size, table);
		now_size *= strlen(g_str[data]);
	}
	return table;
}