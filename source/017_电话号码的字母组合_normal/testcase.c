#include "testcase.h"
#include "interface.h"

int checkRst(char **table, int size, char *excp[], int excp_size)
{
	int idx_rst;
	int idx_excp;
	if (size != excp_size) {
		return FALSE;
	}
	for (idx_rst = 0; idx_rst < size; idx_rst++) {
		for (idx_excp = 0; idx_excp < size; idx_excp++) {
			if (strcmp(table[idx_rst], excp[idx_excp]) == 0) {
				break;
			}
	    }
		if (idx_excp == size) {
			printf("%s not found\r\n", table[idx_rst]);
			return FALSE;
		}
	}

	for (idx_excp = 0; idx_excp < size; idx_excp++) {
		for (idx_rst = 0; idx_rst < size; idx_rst++) {
			if (strcmp(table[idx_rst], excp[idx_excp]) == 0) {
				break;
			}
	    }
		if (idx_rst == size) {
			printf("%s not found\r\n", table[idx_rst]);
			return FALSE;
		}
	}
	return TRUE;
}

void testcase1(void)
{
	char *excp[] = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
	int size = 0;
	char **table = letterCombinations("23", &size);
	bool rst = checkRst(table, size, excp, ARRAY_SIZE(excp));
	
	if (rst == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase2(void)
{
	char *excp[] = {"ap", "aq", "ar", "as", "bp", "bq", "br", "bs", "cp", "cq", "cr", "cs"};
	int size = 0;
	char **table = letterCombinations("27", &size);
	bool rst = checkRst(table, size, excp, ARRAY_SIZE(excp));
	
	if (rst == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase3(void)
{
	char *excp[] = {"adg", "aeg", "afg", "bdg", "beg", "bfg", "cdg", "ceg", "cfg", 
		"adh", "aeh", "afh", "bdh", "beh", "bfh", "cdh", "ceh", "cfh", 
		"adi", "aei", "afi", "bdi", "bei", "bfi", "cdi", "cei", "cfi"};
	int size = 0;
	char **table = letterCombinations("234", &size);
	bool rst = checkRst(table, size, excp, ARRAY_SIZE(excp));
	
	if (rst == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase4(void)
{
	int size = 0;
	char **table = letterCombinations("", &size);
	bool rst = checkRst(table, size, NULL, 0);
	
	if (rst == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err\n", __FUNCTION__);
	}
}

void testcase(void)
{
	//testcase1();
	//testcase2();
	//testcase3();
	testcase4();
}