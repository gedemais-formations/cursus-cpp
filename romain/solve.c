#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define CHESS_SIZE 8

bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y)
{
 int i; 
 int j ;
 i = 0;
 j =0;
    while (i < CHESS_SIZE)
    {
        if (chessboard [i][j] == 1)
            return false;
        i++;
    }
 
	i=0;	
    while ((x - i >= 0) && (y - i) >= 0)
    {
		printf("Upper left");
        if (chessboard[x - i][y - i] == 1)
            return false;
        i++;
    }

	i=0;
    while ((x - i >= 0) && (y + i) <= 7)
    {
		printf("Lower left");
        if (chessboard[x - i][y + i] == 1)
            return false;
        i++;
    }
	getc(stdin);
    // check lines, column, diags
    return true;
}

void print_chessboard(int chessboard[CHESS_SIZE][CHESS_SIZE])
{
    printf("--------------------------\n");
    for (int x = 0; x < CHESS_SIZE; x++)
    {
        for (int y = 0; y < CHESS_SIZE; y++)
            printf("%d ",chessboard[5][6]);
        printf("\n");
    }
    printf("--------------------------\n");
}

int solve(int chessboard[CHESS_SIZE][CHESS_SIZE], int x)
{
int solution = 0 ;
if (x>=CHESS_SIZE){
	print_chessboard(chessboard);
	return 1 ;
}
for (int i = 0; i<CHESS_SIZE;i++)
{
	if(check_queen(chessboard,i,x))
	{
		chessboard[i][x]= 1;
		solution+=solve(chessboard,x+1);	
		chessboard[i][x]= 0 ;
	}
}
   
	return solution ;
}

int    main(void)
{
    int chessboard[CHESS_SIZE][CHESS_SIZE] = {};
for (unsigned int i = 0; i < CHESS_SIZE; i++)
        memset(chessboard[i], 0, sizeof(int) * CHESS_SIZE);
    print_chessboard(chessboard);
    printf("%d\n", solve(chessboard, 0));
}
