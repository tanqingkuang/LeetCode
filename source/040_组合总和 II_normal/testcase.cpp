#include "testcase.h"
#include "interface.h"

int beyond(int **rst, int* returnColumnSizes, int returnSize)
{
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d\t", rst[i][j]);
        }
        printf("\r\n");
    }
    return 1;
}

void testcase1(void)
{
    int candidates[] = {10,1,2,7,6,1,5};
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int **rst = combinationSum2(candidates, ARRAYSIZE(candidates), 8, &returnSize, &returnColumnSizes);
	display_result(beyond(rst, returnColumnSizes, returnSize), __FUNCTION__);
}

void testcase2(void)
{
    int candidates[] = {2,5,2,1,2};
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int **rst = combinationSum2(candidates, ARRAYSIZE(candidates), 5, &returnSize, &returnColumnSizes);
	display_result(beyond(rst, returnColumnSizes, returnSize), __FUNCTION__);
}

void testcase3(void)
{
    int candidates[] = {14,18,19,30,6,5,14,23,28,18,26,21,12,15,29,18,32,23,6,21,19,30,6,28,17,13,29,28,10,34,26,11,10,32,7,11,32,8,21,18,22,5,34,21,7,20,26,5,9,28,21,23,23,15,8,27,23,32,12,20,31,33,27,28,30,21,34,19};
    int returnSize = 29;
    int* returnColumnSizes = NULL;
    int **rst = combinationSum2(candidates, ARRAYSIZE(candidates), 29, &returnSize, &returnColumnSizes);
	display_result(beyond(rst, returnColumnSizes, returnSize), __FUNCTION__);
}

void testcase(void)
{
	//testcase1();
    //testcase2();
    testcase3();
}