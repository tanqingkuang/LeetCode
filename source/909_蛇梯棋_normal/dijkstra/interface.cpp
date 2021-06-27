#include "../interface.h"

#define N 20

typedef struct {
    int used;
    int dest; /* ��ΪĿ�ĵأ�����Ϊ������ת */
} NODE;

NODE g_map[N*N];

/* �������boardת��Ϊmap�� */
void initMap(int** board, int boardSize)
{
    int idx_map = 0;
    int flag = 0; /* 0˵����ǰ����1˵���Ӻ���ǰ */
    for (int row = boardSize-1; row >=0; row--) {
        if (flag == 0) {
            for (int line = 0; line < boardSize; line++) {
                g_map[idx_map].used = 0;
                g_map[idx_map++].dest = board[row][line] - 1;
                
            }
        } else {
            for (int line = boardSize - 1; line >= 0; line--) {
                g_map[idx_map].used = 0;
                g_map[idx_map++].dest = board[row][line] - 1;
            }
        }
        flag = !flag;
    }
    g_map[0].used = 1;
}

typedef struct {
    int pos;
    int times;
} DATA;

typedef struct {
    DATA data[N*N];
    int start;
    int end;
} QUEUE;

QUEUE g_queue;

void initQueue(void)
{
    g_queue.start = 0;
    g_queue.end = 0;
}

void pushQueue(int pos, int times)
{ /* ����queue�㹻����˲���Ҫѭ������ */
    g_queue.data[g_queue.end].pos = pos;
    g_queue.data[g_queue.end].times = times;
    g_queue.end += 1;
}

int isEmptyQueue()
{
    if (g_queue.start == g_queue.end) return 1;
    return 0;
}

DATA *popQueue()
{
    return &(g_queue.data[g_queue.start++]);
}

int bfs(int start, int target)
{
    pushQueue(start, 0);
    while (!isEmptyQueue()) {
        DATA *data = popQueue();
        int pos = data->pos;
        int times = data->times;
        for (int step = 1; step <= 6; step++) {
            int dest = pos + step;
            if (dest == target) return times + 1; /* ����Ŀ�ĵأ����� */
            if (g_map[dest].dest >= 0) { /* ��ת�߼� */
                dest = g_map[dest].dest;
                if (dest == target) return times + 1; /* ����Ŀ�ĵأ����� */
                if (g_map[dest].used == 1) continue; /* �Ѿ������ˣ��ü��� */
                g_map[dest].used = 1;
                pushQueue(dest, times + 1);
                continue;
            }
            /* ����ת�߼� */
            if (g_map[dest].used == 1) continue; /* �Ѿ������ˣ��ü��� */
            g_map[dest].used = 1;
            pushQueue(dest, times + 1);
        }
        
    }
    return -1;
}

int snakesAndLadders(int** board, int boardSize, int* boardColSize) {
    initMap(board, boardSize);
    initQueue();
    int rst = bfs(0, boardSize * boardSize - 1);
    return rst;
}