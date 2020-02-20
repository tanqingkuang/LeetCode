#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	char *heng0 = "53..7....";
	char *heng1 = "6..195...";
	char *heng2 = ".98....6.";
	char *heng3 = "8...6...3";
	char *heng4 = "4..8.3..1";
	char *heng5 = "7...2...6";
	char *heng6 = ".6....28.";
	char *heng7 = "...419..5";
	char *heng8 = "....8..79";
	char *board[] = {heng0,heng1,heng2,heng3,heng4,heng5,heng6,heng7,heng8};
	bool rst = isValidSudoku(board, 9, NULL);
	bool excp = 1;
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
	char *heng0 = "83..7....";
	char *heng1 = "6..195...";
	char *heng2 = ".98....6.";
	char *heng3 = "8...6...3";
	char *heng4 = "4..8.3..1";
	char *heng5 = "7...2...6";
	char *heng6 = ".6....28.";
	char *heng7 = "...419..5";
	char *heng8 = "....8..79";
	char *board[] = {heng0,heng1,heng2,heng3,heng4,heng5,heng6,heng7,heng8};
	bool rst = isValidSudoku(board, 9, NULL);
	bool excp = 0;
	if (rst == excp) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err rst(%u)!=excp(%u)\n", __FUNCTION__, rst, excp);
	}
}

void testcase3(void)
{
	char *heng0 = ".87654321";
	char *heng1 = "2........";
	char *heng2 = "3........";
	char *heng3 = "4........";
	char *heng4 = "5........";
	char *heng5 = "6........";
	char *heng6 = "7........";
	char *heng7 = "8........";
	char *heng8 = "9........";
	char *board[] = {heng0,heng1,heng2,heng3,heng4,heng5,heng6,heng7,heng8};
	bool rst = isValidSudoku(board, 9, NULL);
	bool excp = 1;
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
	testcase3();
}