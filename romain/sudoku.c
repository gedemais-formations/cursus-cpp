#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define SUDOKU_SIZE 9


bool check_number(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int num, int ligne, int colonne)
{
for (int i = 0; i <= 8; i++)
        if (sudoku[ligne][i] == num)
            return false;

    for (int i = 0; i <= 8; i++)
        if (sudoku[i][colonne] == num)
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
    int ligne = x/SUDOKU_SIZE ;
	int colonne = x % SUDOKU_SIZE ;
    int nbSolution = 0;

    //Condition d'initialisation, si l'on va jusqu'au bout du chess c'est que l'on a une solution

    if (x == SUDOKU_SIZE*SUDOKU_SIZE-1)
    {
		if(sudoku[SUDOKU_SIZE-1][SUDOKU_SIZE-1] != 0)
		{
			print_sudoku(sudoku);
			nbSolution = 1;
		}
		else
		{
			for (int i=1 ; i<=SUDOKU_SIZE;i++)
			{
				if (check_number(sudoku,i,SUDOKU_SIZE-1,SUDOKU_SIZE-1))
				{
				nbSolution = nbSolution +1 ;
				 }
			}
		}
	}
	else 
	{
		if(sudoku[ligne][colonne]!= 0)
		{
		 nbSolution = solve(sudoku,x+1);
		}
			else
			{   for (int i = 1;i<=SUDOKU_SIZE;i++)
				{
					 if (check_number(sudoku,i,ligne,colonne))
					 {
					sudoku[ligne][colonne]= i ;
					nbSolution = nbSolution + solve(sudoku,x+1);
					sudoku[ligne][colonne]= 0 ;
		           }
				}
			}
		}	
    return nbSolution;
}

int main()
{
    int sudoku[SUDOKU_SIZE][SUDOKU_SIZE]=
		{
        {9,0,0,1,0,0,0,0,5},
        {0,0,5,0,9,0,2,0,1},
        {8,0,0,0,4,0,0,0,0},
        {0,0,0,0,8,0,0,0,0},
        {0,0,0,7,0,0,0,0,0},
        {0,0,0,0,2,6,0,0,9},
        {2,0,0,3,0,0,0,0,6},
        {0,0,0,2,0,0,9,0,0},
        {0,0,1,9,0,4,5,7,0}
    };
      print_sudoku(sudoku);
	  printf("%d\n", solve(sudoku, 0));
    return 0;
}

