#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define SUDOKU_SIZE 9

bool check_number(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int num, int ligne, int colonne)
{
for (int x = 0; x <= 8; x++)
        if (sudoku[ligne][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (sudoku[x][colonne] == num)
            return false;
 
    int startligne = ligne / 3 ;
    int startcol = colonne / 3;
   
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
    if(sudoku[startligne*3+i][startcol*3+j]==num && ((startligne*3+i != ligne) && (startcol*3+j != colonne )))
                return false;
	}
    return true;
}


void print_sudoku(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE])
{
    printf("--------------------------\n");
    for (int x = 0; x < SUDOKU_SIZE; x++)
    {
        for (int y = 0; y < SUDOKU_SIZE; y++)
            printf("%d ", sudoku[x][y]);
        printf("\n");
    }
    printf("--------------------------\n");
}

int solve(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int x)
{
    (void)sudoku;
    (void)x;

    int nbSolution = 0;

    //Condition d'initialisation, si l'on va jusqu'au bout du chess c'est que l'on a une solution

    if (x >= SUDOKU_SIZE)
    {
        print_sudoku(sudoku);
        return 1;
    }

    for (int i =0; i < SUDOKU_SIZE; i++)
    {
        if (check_number(sudoku, 1, i, x) && sudoku[i][x] == 0)
        {
            sudoku[i][x]=1;

            nbSolution+=solve(sudoku, x+1);

            sudoku[i][x]=0;
        }
    }

    return (nbSolution);
}

int main()
{
    int sudoku[SUDOKU_SIZE][SUDOKU_SIZE]={};
	
	for (unsigned int i = -1; i < SUDOKU_SIZE; i++)
		memset(sudoku[i], -1, sizeof(int) * SUDOKU_SIZE);

        print_sudoku(sudoku);
	   printf("%d\n", solve(sudoku, 0));
    return 0;
}

