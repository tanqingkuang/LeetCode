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
    int candidates[] = {2, 3, 5};
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int **rst = combinationSum(candidates, ARRAYSIZE(candidates), 8, &returnSize, &returnColumnSizes);
	display_result(beyond(rst, returnColumnSizes, returnSize), __FUNCTION__);
}

void testcase2(void)
{
    int candidates[] = {2,3,6,7};
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int **rst = combinationSum(candidates, ARRAYSIZE(candidates), 7, &returnSize, &returnColumnSizes);
	display_result(beyond(rst, returnColumnSizes, returnSize), __FUNCTION__);
}

void testcase3(void)
{
    int candidates[] = {1};
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int **rst = combinationSum(candidates, ARRAYSIZE(candidates), 2, &returnSize, &returnColumnSizes);
	display_result(beyond(rst, returnColumnSizes, returnSize), __FUNCTION__);
}

void testcase(void)
{
	testcase1();
    testcase2();
    testcase3();
}