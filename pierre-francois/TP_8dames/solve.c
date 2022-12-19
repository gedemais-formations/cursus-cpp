#include <stdbool.h>
#include <stdio.h>
#define CHESS_SIZE 8

bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y)
{
    // check lines, column, diags
    return (true);
}

void print_chessboard(int chessboard[CHESS_SIZE][CHESS_SIZE])
{
    printf("--------------------------\n");
    for (int x = 0; x < CHESS_SIZE; x++)
    {
        for (int y = 0; y < CHESS_SIZE; y++)
            printf("%d ", chessboard[x][y]);
        printf("\n");
    }
    printf("--------------------------\n");
}

int solve(int chessboard[CHESS_SIZE][CHESS_SIZE], int x)
{
    (void)chessboard;
    (void)x;
    return (0);
}

int    main(void)
{
	for (unsigned int i = 0; i < CHESS_SIZE; i++)
        memset(chessboard[i], 0, sizeof(int) * CHESS_SIZE);

    int chessboard[CHESS_SIZE][CHESS_SIZE] = {};

    print_chessboard(chessboard);
    printf("%d\n", solve(chessboard, 0));
}
