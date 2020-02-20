#include "../interface.h"

typedef struct {
	int hang;
	int lie;
} NODE;

int map_num[10] = {0}; 
NODE map[10][9] = {{0}};

bool checkInSame(int hang1, int lie1, int hang2, int lie2)
{
	if (hang1 == hang2) {
		return 1;
	}
	if (lie1 == lie2) {
		return 1;
	}
	if ((hang1 / 3 == hang2 / 3) && (lie1 / 3 == lie2 / 3)) {
		return 1;
	}
	return 0;
}

void initMap(void)
{
	memset(map, 0, sizeof(map));
	memset(map_num, 0, sizeof(map_num));
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
	int idx_lie;
	int idx_hang;
	int data;
	initMap();
	for (idx_hang = 0; idx_hang < boardSize; idx_hang++) {
		for (idx_lie = 0; idx_lie < boardSize; idx_lie++) {
			int idx_num;
			if (board[idx_hang][idx_lie] == '.') {
				continue;
			}
			data = board[idx_hang][idx_lie] - '0';
			for (idx_num = 0; idx_num < map_num[data]; idx_num++) {
				if (checkInSame(map[data][idx_num].hang, map[data][idx_num].lie, idx_hang, idx_lie) == 1) {
					return 0;
				}
			}
			map[data][map_num[data]].hang = idx_hang;
			map[data][map_num[data]].lie = idx_lie;
			map_num[data]++;
		}
	}
	return 1;
}