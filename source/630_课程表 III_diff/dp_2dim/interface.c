#include "../interface.h"

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

int **initMap(int coursesSize, int maxDeadTime)
{
	int **map = (int **)malloc(sizeof(int *) * coursesSize);
	int idx = 0;
	for (;idx < coursesSize; idx++) {
		map[idx] = (int *)malloc(sizeof(int) * (maxDeadTime+1));
	}
	return map;
}

void freeMap(int **map, int coursesSize)
{
	int idx = 0;
	for (;idx < coursesSize; idx++) {
		free(map[idx]);
	}
	free(map);
}

int scheduleCourse_dp(int** courses, int coursesSize, int **map, int maxDeadTime)
{
	int idx_courses;
	int idx_dead;

	/* ��0�� */
	for (idx_courses = 0; idx_courses < coursesSize; idx_courses++) {
		if (courses[idx_courses][0] != 0) {
			break;
		}
	}
	memset(&map[idx_courses][0], 0, courses[idx_courses][0] * sizeof(int));
	for (idx_dead = courses[idx_courses][0]; idx_dead <= maxDeadTime; idx_dead++) {
		map[idx_courses][idx_dead] = 1;
	}

	/* ����dp */
	for (idx_courses++; idx_courses < coursesSize; idx_courses++) {
		/* cost֮ǰ��ֱ�Ӽ̳� */
		memcpy(&map[idx_courses][0], &map[idx_courses-1][0], courses[idx_courses][0] * sizeof(int));
		
		/* �ڶ���ֱ�ӵĴ�����̳к�Ҫ+1 */
		for (idx_dead = courses[idx_courses][1]; idx_dead >= courses[idx_courses][0]; idx_dead--) {
			map[idx_courses][idx_dead] = MAX(map[idx_courses-1][idx_dead-courses[idx_courses][0]]+ 1, map[idx_courses-1][idx_dead]);
		}

		/* ���ڱ��νڵ��deadlineֱ�Ӽ̳б��е������ */
		for (idx_dead = courses[idx_courses][1] + 1; idx_dead <= maxDeadTime; idx_dead++) {
			map[idx_courses][idx_dead] = map[idx_courses][courses[idx_courses][1]];
		}
	}

	return map[coursesSize-1][maxDeadTime];
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
	int **map = NULL;
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

	qsort(courses, coursesSize, sizeof(int *), mycompare); /* ���Ȱ���deadTime�������� */
	maxDeadTime = courses[coursesSize-1][1];
	map = initMap(coursesSize, maxDeadTime);
	rst = scheduleCourse_dp(courses, coursesSize, map, maxDeadTime);
	freeMap(map, coursesSize);
	return rst;
}