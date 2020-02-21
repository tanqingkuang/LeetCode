#include "../interface.h"

typedef struct {
	int inused;
	int data;
} NODE;

typedef struct {
	int hang;
	int lie;
} POS;

#define CLEAR_BIT(data, offset) ((data) &= ~(1 << (offset)))

void SetMapNode(NODE map[9][9], int boardSize, int hang, int lie)
{
	int data = 0x3fe;
	int idx_lie;
	int idx_hang;
	for (idx_hang = 0; idx_hang < boardSize; idx_hang++) {
		if (map[idx_hang][lie].inused == 1) {
			CLEAR_BIT(data, map[idx_hang][lie].data);
		}
	}
	for (idx_lie = 0; idx_lie < boardSize; idx_lie++) {
		if (map[hang][idx_lie].inused == 1) {
			CLEAR_BIT(data, map[hang][idx_lie].data);
		}
	}
	for (idx_hang = hang/3*3; idx_hang <= (hang/3*3 + 2); idx_hang++) {
		for (idx_lie = lie/3*3; idx_lie <= (lie/3*3 + 2); idx_lie++) {
			if (map[idx_hang][idx_lie].inused == 1) {
				CLEAR_BIT(data, map[idx_hang][idx_lie].data);
			}
		}
	}
	map[hang][lie].data = data;
}

void Reset_map(NODE map[9][9], int boardSize)
{
	int idx_lie;
	int idx_hang;
	for (idx_hang = 0; idx_hang < boardSize; idx_hang++) {
		for (idx_lie = 0; idx_lie < boardSize; idx_lie++) {
			if (map[idx_hang][idx_lie].inused == 0) {
				SetMapNode(map, boardSize, idx_hang, idx_lie);
			}
		}
	}
}

void InitMap(char** board, int boardSize, NODE map[9][9])
{
	int idx_lie;
	int idx_hang;
	for (idx_hang = 0; idx_hang < boardSize; idx_hang++) {
		for (idx_lie = 0; idx_lie < boardSize; idx_lie++) {
			if (board[idx_hang][idx_lie] == '.') {
				map[idx_hang][idx_lie].inused = 0;
				continue;
			}
			map[idx_hang][idx_lie].inused = 1;
			map[idx_hang][idx_lie].data = board[idx_hang][idx_lie] - '0';
		}
	}
}

int GetBitNum(int data)
{
	int rst = 0;
	while(data > 0) {
		rst++;
		data &= data - 1;
	}
	return rst;
}

int GetMinBit(int data)
{
	int rst = 1;
	while((data & (1 << rst)) ==  0) {
		rst++;
	}
	return rst;
}

int Sudoku_cure(NODE map[9][9], int boardSize, POS *pos_array, int *pos_num, POS *pos)
{
	int idx_lie;
	int idx_hang;
	int min_num = 9;
	for (idx_hang = 0; idx_hang < boardSize; idx_hang++) {
		for (idx_lie = 0; idx_lie < boardSize; idx_lie++) {
			if (map[idx_hang][idx_lie].inused == 0) {
				int num = GetBitNum(map[idx_hang][idx_lie].data);
				if (num == 1) {
					map[idx_hang][idx_lie].inused = 1;
					map[idx_hang][idx_lie].data = GetMinBit(map[idx_hang][idx_lie].data);
					pos_array[*pos_num].hang = idx_hang;
					pos_array[*pos_num].lie = idx_lie;
					Reset_map(map, boardSize);
					return 0;
				} else if (num < min_num){
					pos->hang = idx_hang;
					pos->lie = idx_lie;
					min_num = num;
				}
			}
		}
	}
	return min_num;
	
}

int Sudoku_dg(NODE map[9][9], int boardSize, POS *pos_array, int *pos_num)
{
	int num;
	POS pos = {0};
	do {
		num = Sudoku_cure(map, boardSize, pos_array, pos_num, &pos);
	} while(num == 0);

	return 0;
}
void SetBoard(char** board, int boardSize, NODE map[9][9])
{
	int idx_lie;
	int idx_hang;
	for (idx_hang = 0; idx_hang < boardSize; idx_hang++) {
		for (idx_lie = 0; idx_lie < boardSize; idx_lie++) {
			if (map[idx_hang][idx_lie].inused == 1 && board[idx_hang][idx_lie] == '.') {
				board[idx_hang][idx_lie] = (char)(map[idx_hang][idx_lie].data + '0');
			}
		}
	}
}

NODE g_map[9][9];
void solveSudoku(char** board, int boardSize, int* boardColSize)
{	
	POS pos_array[81] = {0};
	int pos_num = 0;
	InitMap(board, boardSize, g_map);
	Reset_map(g_map, boardSize);
	Sudoku_dg(g_map, boardSize, pos_array, &pos_num);
	SetBoard(board, boardSize, g_map);
}