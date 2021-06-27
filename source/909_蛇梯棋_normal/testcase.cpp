#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
    int board0[] = {-1, -1, -1, -1, -1, -1};
    int board1[] = {-1, -1, -1, -1, -1, -1};
    int board2[] = {-1, -1, -1, -1, -1, -1};
    int board3[] = {-1, 35, -1, -1, 13, -1};
    int board4[] = {-1, -1, -1, -1, -1, -1};
    int board5[] = {-1, 15, -1, -1, -1, -1};
    int *board_cow[] = {board0, board1, board2, board3, board4, board5};
	TEST_EQ(snakesAndLadders(board_cow, ARRAYSIZE(board_cow), NULL), 4);
}

void testcase2(void)
{
    int board0[] = {-1, -1, 27, 13, -1, 25, -1};
    int board1[] = {-1, -1, -1, -1, -1, -1, -1};
    int board2[] = {44, -1,  8, -1, -1,  2, -1};
    int board3[] = {-1, 30, -1, -1, -1, -1, -1};
    int board4[] = { 3, -1, 20, -1, 46,  6, -1};
    int board5[] = {-1, -1, -1, -1, -1, -1, 29};
    int board6[] = {-1, 29, 21, 33, -1, -1, -1};
    int *board_cow[] = {board0, board1, board2, board3, board4, board5, board6};
	TEST_EQ(snakesAndLadders(board_cow, ARRAYSIZE(board_cow), NULL), 4);
}

void testcase3(void)
{
    int board0[]  = {-1,  -1};
    int board1[]  = {-1,  3};
    int *board_cow[] = {board0, board1};
	TEST_EQ(snakesAndLadders(board_cow, ARRAYSIZE(board_cow), NULL), 1);
}

void testcase4(void)
{
    int board0[]  = {-1,  -1,  -1, 30,  -1, 144, 124, 135, -1,  -1, -1,  -1, -1};
    int board1[]  = {-1,  -1,  -1, -1,  -1,  -1, 167,  93, -1,  -1, -1,  -1, -1};
    int board2[]  = {-1,  -1,  -1, -1,  -1,  -1,  -1,  77, -1,  -1, 90,  -1, -1};
    int board3[]  = {-1,  -1,  -1, -1,  -1,  -1,  -1,  -1, -1,  -1, -1,  -1, -1};
    int board4[]  = {-1,  -1,  -1, -1,  -1,  -1,  -1,  -1, -1,  -1, -1, 122, -1};
    int board5[]  = {-1,  -1,  -1, 23,  -1,  -1,  -1,  -1, -1, 155, -1,  -1, -1};
    int board6[]  = {-1,  -1, 140, 29,  -1,  -1,  -1,  -1, -1,  -1, -1,  -1, -1};
    int board7[]  = {-1,  -1,  -1, -1,  -1, 115,  -1,  -1, -1, 109, -1,  -1,  5};
    int board8[]  = {-1,  57,  -1, 99, 121,  -1,  -1, 132, -1,  -1, -1,  -1, -1};
    int board9[]  = {-1,  48,  -1, -1,  -1,  68,  -1,  -1, -1,  -1, 31,  -1, -1};
    int board10[] = {-1, 163, 147, -1,  77,  -1,  -1, 114, -1,  -1, 80,  -1, -1};
    int board11[] = {-1,  -1,  -1, -1,  -1,  57,  28,  -1, -1, 129, -1,  -1, -1};
    int board12[] = {-1,  -1,  -1, -1,  -1,  -1,  -1,  -1, -1,  87, -1,  -1, -1};
    int *board_cow[] = {board0, board1, board2, board3, board4, board5, board6, board7, board8, board9, board10, board11, board12};
	TEST_EQ(snakesAndLadders(board_cow, ARRAYSIZE(board_cow), NULL), 6);
}

void testcase5(void)
{
    int board0[]  = {-1,-1,-1,135,-1,-1,-1,-1,-1,185,-1,-1,-1,-1,105,-1};
    int board1[]  = {-1,-1,92,-1,-1,-1,-1,-1,-1,201,-1,118,-1,-1,183,-1};
    int board2[]  = {-1,-1,-1,-1,-1,-1,-1,-1,-1,179,-1,-1,-1,-1,-1,-1};
    int board3[]  = {-1,248,-1,-1,-1,-1,-1,-1,-1,119,-1,-1,-1,-1,-1,192};
    int board4[]  = {-1,-1,104,-1,-1,-1,-1,-1,-1,-1,165,-1,-1,206,104,-1};
    int board5[]  = {145,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,229,-1};
    int board6[]  = {-1,-1,75,140,-1,-1,-1,-1,-1,-1,-1,-1,43,-1,34,-1};
    int board7[]  = {-1,-1,-1,-1,-1,-1,169,-1,-1,-1,-1,-1,-1,188,-1,-1};
    int board8[]  = {-1,-1,-1,-1,-1,-1,92,-1,171,-1,-1,-1,-1,-1,-1,66};
    int board9[]  = {-1,-1,-1,126,-1,-1,68,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int board10[]  = {-1,109,-1,86,28,228,-1,-1,144,-1,-1,-1,-1,-1,-1,-1};
    int board11[]  = {-1,-1,-1,-1,59,-1,-1,-1,-1,-1,51,-1,-1,-1,62,-1};
    int board12[]  = {-1,71,-1,-1,-1,63,-1,-1,-1,-1,-1,-1,212,-1,-1,-1};
    int board13[]  = {-1,-1,-1,-1,174,-1,59,-1,-1,-1,-1,-1,-1,133,-1,-1};
    int board14[]  = {-1,-1,62,-1,5,-1,16,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int board15[]  = {-1,-1,-1,59,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int *board_cow[] = {board0, board1, board2, board3, board4, board5, board6, board7, board8, board9, board10, board11, board12, board13, board14, board15};
	TEST_EQ(snakesAndLadders(board_cow, ARRAYSIZE(board_cow), NULL), 10);
}

void testcase(void)
{
	testcase1();
    testcase2();
    testcase3();
    testcase4();
    testcase5();
}