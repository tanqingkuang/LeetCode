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
void findMaxNode(int** courses, int coursesSize, int *max_id)
{
	int max = 0;
	int idx;
	
	for (idx = 0; idx < coursesSize; idx++) {
		if (courses[idx][0] > max) {
			*max_id = idx;
			max = courses[idx][0];
		}
	}
}
int scheduleCourse_greedy(int** courses, int coursesSize)
{
	int idx_courses;
	int rst = 0;
	int deadTime = 0;
	for (idx_courses = 0; idx_courses < coursesSize; idx_courses++) {
		if ((courses[idx_courses][0] + deadTime) <= courses[idx_courses][1]) { /* 如果能放下就尽量放 */
			deadTime += courses[idx_courses][0];
			rst++;
		} else { 
			/* 如果放不下，找一个之前最大的，
					如果当前比之前最大的小，则删除替换掉那个最大的;
					反之则放弃该节点 
			*/
			int last_max_id = 0;
			findMaxNode(courses, idx_courses, &last_max_id);
			if (courses[idx_courses][0] >= courses[last_max_id][0]) {
				courses[idx_courses][0] = 0;
				courses[idx_courses][1] = 0;
				continue;
			} else {
				deadTime = deadTime - courses[last_max_id][0] + courses[idx_courses][0];
				courses[last_max_id][0] = 0;
				courses[last_max_id][1] = 0;
			}
		}
	}
	return rst;
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
	rst = scheduleCourse_greedy(courses, coursesSize);
	return rst;
}