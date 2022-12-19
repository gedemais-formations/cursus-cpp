#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define CHESS_SIZE 8

bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y)
{
    // check lines, column, diags

	//Check sur la ligne
	for(int i=0; i<CHESS_SIZE; i++)
	{
		if(chessboard[x][i] == 1)
			return true;
	}

	//Check sur la colonne
	for(int i=0; i<CHESS_SIZE; i++)
	{
		if(chessboard[i][y] == 1)
			return true;
	}

	//Check sur les diagonales
	int j = 0;

	while ((x+j<CHESS_SIZE) && (y+j<CHESS_SIZE))
	{
		if(chessboard[x+j][y+j] == 1)
			return true;
	}

	while ((x-j>=0) && (y-j>=0))
	{
		if(chessboard[x-j][y-j] == 1)
			return true;
	}

	while ((x+j<CHESS_SIZE) && (y-j>=0))
	{
		if(chessboard[x+j][y-j] == 1)
			return true;
	}

	while ((x-j>=0) && (y+j<CHESS_SIZE))
	{
		if(chessboard[x-j][y+j] == 1)
			return true;
	}
// Si aucune des conditions précédentes n'est remplie, alors nous n'avons pas
// rencontré de dame, on revoie alors false

	return false;

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
	chessboard[0][0]=1;
    (void)chessboard;
    (void)x;
    return (0);
}

int main(void)
{
    int chessboard[CHESS_SIZE][CHESS_SIZE] = {};

	for (unsigned int i = -1; i < CHESS_SIZE; i++)
        memset(chessboard[i], -1, sizeof(int) * CHESS_SIZE);


    print_chessboard(chessboard);
    printf("%d\n", solve(chessboard, 0));
	return (0);
}
