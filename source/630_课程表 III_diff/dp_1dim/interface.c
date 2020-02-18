#include "../interface.h"

#define MAP_LEN 10000 
int g_map[MAP_LEN+1];

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
	int last_max = 0;

	for (idx_courses = 0; idx_courses < coursesSize; idx_courses++) {
		/* 0-1背包做选择 */
		for (idx_dead = courses[idx_courses][1]; idx_dead >= courses[idx_courses][0]; idx_dead--) {
			g_map[idx_dead] = MAX(g_map[idx_dead-courses[idx_courses][0]] + 1, g_map[idx_dead]);
		}

		/* 大于本次节点的deadline直接继承本行的最大数 */
		if (g_map[courses[idx_courses][1]] > last_max) {
			for (idx_dead = courses[idx_courses][1] + 1; idx_dead <= maxDeadTime; idx_dead++) {
				g_map[idx_dead] = g_map[courses[idx_courses][1]];
			}
			last_max = g_map[courses[idx_courses][1]];
		}
	}

	return last_max;
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
	memset(g_map, 0 , (maxDeadTime + 1) * sizeof(int));
	rst = scheduleCourse_dp(courses, coursesSize, maxDeadTime);
	return rst;
}