#include "../interface.h"

#define MAP_LEN 10000 
int g_map0[MAP_LEN+1];
int g_map1[MAP_LEN+1];

int mycompare(const void *a, const void *b)
{
	int *arr0 = *(int **)a;
	int *arr1 = *(int **)b;
	if (arr0[1] != arr1[1]) {
		return arr0[1] - arr1[1];
	} else {
		return arr0[0] - arr1[0];
	}
}

int scheduleCourse_dp(int** courses, int coursesSize, int maxDeadTime)
{
	int idx_courses;
	int idx_dead;
	int *g_current_map = g_map0;
	int *g_last_map = g_map1;

	/* 第0行 */
	for (idx_courses = 0; idx_courses < coursesSize; idx_courses++) {
		if (courses[idx_courses][0] != 0) {
			break;
		}
	}
	memset(&g_map0[0], 0, courses[idx_courses][0] * sizeof(int));
	for (idx_dead = courses[idx_courses][0]; idx_dead <= maxDeadTime; idx_dead++) {
		g_map0[idx_dead] = 1;
	}

	/* 后续dp */
	for (idx_courses++; idx_courses < coursesSize; idx_courses++) {
		int *map = g_current_map;
		g_current_map = g_last_map;
		g_last_map = map;

		/* cost之前的直接继承 */
		memcpy(&g_current_map[0], &g_last_map[0], courses[idx_courses][0] * sizeof(int));
		
		/* 在二者直接的从上面继承后要+1 */
		for (idx_dead = courses[idx_courses][1]; idx_dead >= courses[idx_courses][0]; idx_dead--) {
			g_current_map[idx_dead] = MAX(g_last_map[idx_dead-courses[idx_courses][0]]+ 1, g_last_map[idx_dead]);
		}

		/* 大于本次节点的deadline直接继承本行的最大数 */
		for (idx_dead = courses[idx_courses][1] + 1; idx_dead <= maxDeadTime; idx_dead++) {
			g_current_map[idx_dead] = g_current_map[courses[idx_courses][1]];
		}
	}

	return g_current_map[maxDeadTime];
}

int checNouse(int** courses, int coursesSize, int* coursesColSize)
{
	int idx = 0;
	int rst = 0;
	for (; idx < coursesSize; idx++) {
		if (courses[idx][0] > courses[idx][1]) {
			courses[idx][0] = 0;
			courses[idx][1] = 0;
			rst++;
		}
	}
	return rst;
}

int scheduleCourse(int** courses, int coursesSize, int* coursesColSize)
{
	int rst;
	int noUseNum;
	int maxDeadTime;
	
	noUseNum = checNouse(courses, coursesSize, coursesColSize);
	courses += noUseNum;
	coursesSize -= noUseNum;
	if (coursesSize <= 0) {
		return 0;
	}
	if (coursesSize == 1) {
		return 1;
	}

	qsort(courses, coursesSize, sizeof(int *), mycompare); /* 首先按照deadTime升序排列 */
	maxDeadTime = courses[coursesSize-1][1];
	rst = scheduleCourse_dp(courses, coursesSize, maxDeadTime);
	return rst;
}