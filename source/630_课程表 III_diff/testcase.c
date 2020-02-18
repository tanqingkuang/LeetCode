#include "testcase.h"
#include "interface.h"

void testcase1(void)
{
	int courses0[] = {100, 200};
	int courses1[] = {200, 1300};
	int courses2[] = {1000, 1250};
	int courses3[] = {2000, 3200};
	int *courses[] = {courses0, courses1, courses2, courses3}; 
	int coursesColSize[] = {2, 2, 2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 3;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}

void testcase2(void)
{
	int courses0[] = {5, 5};
	int courses1[] = {4, 6};
	int courses2[] = {2, 6};
	int *courses[] = {courses0, courses1, courses2}; 
	int coursesColSize[] = {2, 2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 2;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}

void testcase3(void)
{
	int courses0[] = {1, 2};
	int courses1[] = {2, 3};
	int courses2[] = {2, 6};
	int *courses[] = {courses0, courses1}; 
	int coursesColSize[] = {2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 2;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}

void testcase4(void)
{
	int courses0[] = {9, 14};
	int courses1[] = {7, 12};
	int courses2[] = {1, 11};
	int courses3[] = {4, 7};
	int *courses[] = {courses0, courses1, courses2, courses3}; 
	int coursesColSize[] = {2, 2, 2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 3;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}

void testcase5(void)
{
	int courses0[] = {100, 2};
	int courses1[] = {32, 50};
	int *courses[] = {courses0, courses1}; 
	int coursesColSize[] = {2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 1;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}

void testcase6(void)
{
	int courses0[] = {7,16};
	int courses1[] = {2,3};
	int courses2[] = {3,12};
	int courses3[] = {3,14};
	int courses4[] = {10,19};
	int courses5[] = {10,16};
	int courses6[] = {6,8};
	int courses7[] = {6,11};
	int courses8[] = {3,13};
	int courses9[] = {6,16};
	int *courses[] = {courses0, courses1, courses2, courses3, courses4, courses5, courses6, courses7, courses8, courses9}; 
	int coursesColSize[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 4;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}


void testcase7(void)
{
	int courses0[] = {1, 19};
	int courses1[] = {2, 2};
	int courses2[] = {1, 17};
	int *courses[] = {courses0, courses1, courses2}; 
	int coursesColSize[] = {2, 2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 3;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}

void testcase8(void)
{
	int courses0[] = {10,12};
	int courses1[] = {6,15};
	int courses2[] = {1,12};
	int courses3[] = {3,20};
	int courses4[] = {10,19};
	int *courses[] = {courses0, courses1, courses2, courses3, courses4}; 
	int coursesColSize[] = {2, 2, 2, 2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 4;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}

void testcase9(void)
{
	int courses0[] = {9,10};
	int courses1[] = {8,8};
	int courses2[] = {8,18};
	int courses3[] = {4,16};
	int courses4[] = {10,14};
	int courses5[] = {9,13};
	int courses6[] = {2,7};
	int *courses[] = {courses0, courses1, courses2, courses3, courses4, courses5, courses6}; 
	int coursesColSize[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
	int rst =  scheduleCourse(courses, ARRAY_SIZE(courses), coursesColSize);
	int excp = 3;
	if (excp == rst) {
		set_console_color(10);
		printf("%s: OK\n", __FUNCTION__);
	} else {
		set_console_color(12);
		printf("%s: Err excp(%d) != rst(%d)\n", __FUNCTION__, excp, rst);
	}
}

void testcase(void)
{
	testcase1();
	testcase2();
	testcase3();
	testcase4();
	testcase5();
	testcase6();
	testcase7();
	testcase8();
	testcase9();
}