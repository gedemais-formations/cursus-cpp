#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define CHESS_SIZE 8

bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int row, int col)
{
	int i;
    //Check line
	for(i=0;i<col;i++){
		if(chessboard[row][i] == 1){
			return (false);
		}
	}

	i=1;
	//Check diags 
	while(i<=CHESS_SIZE){
		if(row - i >= 0 && col - i >= 0){
			if(chessboard[row-i][col-i] == 1){
				return (false);
			}
		}
		if(row + i < CHESS_SIZE && col - i < CHESS_SIZE){
			if(chessboard[row+i][col-i] == 1){
				return (false);
			}
		}
		i++;
	}

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

int solve(int chessboard[CHESS_SIZE][CHESS_SIZE], int col)
{
	//If all queen are placed so return
	if(col >= CHESS_SIZE){
		print_chessboard(chessboard);
		return 1;
	}
	
	int solution;
	solution = 0;

	//For each row in chessboard
	for(int i = 0; i < CHESS_SIZE; i++){
		if(check_queen(chessboard, i, col)){
			//Save the queen placement
			chessboard[i][col]=1;

			//If next queen is possible 
			solution += solve(chessboard, col + 1);

			//Backtrack
			chessboard[i][col]=0;
		}
	}
	
    return solution;
}

int main(void)
{
    int chessboard[CHESS_SIZE][CHESS_SIZE] = {};

	for (unsigned int i = 0; i < CHESS_SIZE; i++)
        memset(chessboard[i], 0, sizeof(int) * CHESS_SIZE);

    print_chessboard(chessboard);
    printf("%d\n", solve(chessboard, 0));
}
