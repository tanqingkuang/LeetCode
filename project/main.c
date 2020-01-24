#include "common.h"

void set_console_color(unsigned short color_index)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);
}

void testcase(void);
void main(void)
{
	testcase();
	while(1);
}