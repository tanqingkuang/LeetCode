#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
    int matrix0[] = {9, 9, 4};
    int matrix1[] = {6, 6, 8};
    int matrix2[] = {2, 1, 1};
    int *matrix[] = {matrix0, matrix1, matrix2};
    int matrixColSize = ARRAY_SIZE(matrix0);
    int rst = longestIncreasingPath(matrix, ARRAY_SIZE(matrix), &matrixColSize);
    int excp = 4;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
	
}

void testcase2(void)
{
    int matrix0[] = {1, 2};
    int *matrix[] = {matrix0};
    int matrixColSize = ARRAY_SIZE(matrix0);
    int rst = longestIncreasingPath(matrix, ARRAY_SIZE(matrix), &matrixColSize);
    int excp = 2;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase(void)
{
    testcase1();
    testcase2();
}