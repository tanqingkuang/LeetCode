#include "common.h"

uint32 g_prtint_en = 1;

void set_console_color(unsigned short color_index)
{
    if (g_prtint_en == 0) {
        return;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_index);
}

void display_result(bool rst, char *func)
{
    if (g_prtint_en == 0) {
        return;
    }
	if (rst == TRUE) {
		set_console_color(10);
		printf("%s: OK\n", func);
	} else {
		set_console_color(12);
		printf("%s: Err\n", func);
	}
}

void testcase(void);
void time_test(void)
{
    clock_t start, finish;
    uint32 times = 0;
    g_prtint_en = 0; /* 该变量会在性能测试时优化掉打印 */
    start = clock();
    finish = start;
    while((finish - start) < 500) {
	    testcase();
        finish = clock();
        times++;
    }
    printf("time = %fms", (finish - start) * 1.0 / times);
}

void main(void)
{
	testcase();
    //time_test();
	while(1);
}