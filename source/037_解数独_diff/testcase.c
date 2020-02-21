#include "testcase.h"
#include "interface.h"

bool isValidSudoku(char** board, char **excp)
{
	int idx;
	for (idx = 0; idx < 9; idx++){
		if (memcmp(board[idx], excp[idx], 9) != 0) {
			return 0;
		}
	}
	return 1;
}
void testcase1(void)
{
	char heng0[] = {'5','3','.','.','7','.','.','.','.'};
	char heng1[] = {'6','.','.','1','9','5','.','.','.'};
	char heng2[] = {'.','9','8','.','.','.','.','6','.'};
	char heng3[] = {'8','.','.','.','6','.','.','.','3'};
	char heng4[] = {'4','.','.','8','.','3','.','.','1'};
	char heng5[] = {'7','.','.','.','2','.','.','.','6'};
	char heng6[] = {'.','6','.','.','.','.','2','8','.'};
	char heng7[] = {'.','.','.','4','1','9','.','.','5'};
	char heng8[] = {'.','.','.','.','8','.','.','7','9'};
	char *board[] = {heng0,heng1,heng2,heng3,heng4,heng5,heng6,heng7,heng8};
	char *excp[] = {"534678912",
					"672195348",
					"198342567",
					"859761423",
					"426853791",
					"713924856",
					"961537284",
					"287419635",
					"345286179"};
	solveSudoku(board, 9, NULL);
	if (isValidSudoku(board, excp) == 1) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}
void testcase(void)
{
	testcase1();
}