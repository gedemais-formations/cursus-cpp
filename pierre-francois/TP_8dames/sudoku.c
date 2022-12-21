#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define SUDOKU_SIZE 9

bool check_number(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int number, int ligne, int colonne)
{
	//Check sur la ligne
	for(int i=0; i<SUDOKU_SIZE; i++)
	{
		if(sudoku[ligne][i] == number)
			return false;
	}

	//Check sur la colonne
	for(int i=0; i<SUDOKU_SIZE; i++)
	{
		if(sudoku[i][colonne] == number)
			return false;
	}

	//Check sur le 3*3

	//On commence par regarder dans quel carré se trouve la case
	
	//On converti le double renvoyé par sqrt en int
	int taille_carre = (int) sqrt(SUDOKU_SIZE);

	int ligne_carre = ligne/taille_carre;
	int colonne_carre = colonne/taille_carre;


	//On parcours toutes les cases du carré 
	for(int i=0; i<taille_carre; i++)
	{
		for (int j=0; j<taille_carre; j++)
		{
			// On met une condition pour que pas que la case visée soit prise en compte
				if((sudoku[ligne_carre*taille_carre+i][colonne_carre*taille_carre+j] == number)&&((ligne_carre*taille_carre+i != ligne) && (colonne_carre*taille_carre+j != colonne)))
					return false;
		}
	}

// Si aucune des conditions précédentes n'est remplie, alors nous n'avons pas
// rencontré de dame, on revoie alors false

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

int solve(int sudoku[SUDOKU_SIZE][SUDOKU_SIZE], int num_case)
{
	int nbSolution = 0;

	//Condition d'initialisation, si l'on va jusqu'au bout du chess c'est que l'on a une solution
	if (num_case == SUDOKU_SIZE*SUDOKU_SIZE)
	{	
		if(sudoku[SUDOKU_SIZE-1][SUDOKU_SIZE-1] != 0)
		{
			print_sudoku(sudoku);
			nbSolution = 1;
		}
		
			else
			{
				for(int i=0; i<SUDOKU_SIZE; i++)
				{
					if(check_number(sudoku, i, SUDOKU_SIZE-1, SUDOKU_SIZE-1))
					{
						nbSolution += 1;

					}
				}
			}
	}
	return nbSolution;
}
/*
	for (int i =0; i < SUDOKU_SIZE; i++)
	{

		if (check_number(sudoku, chiffre, i, x) && sudoku[i][x] == 0)
			{
				sudoku[i][x]=chiffre;

				nbSolution+=solve(sudoku, x+1);
			
				sudoku[i][x]=0;
			}
	}
	chiffre++;
}
	print_sudoku(sudoku);
    return (nbSolution);
}*/

int main(void)
{
    int sudoku[SUDOKU_SIZE][SUDOKU_SIZE] =
	{
        {0,0,0,0,0,1,0,7,2},
        {3,2,0,0,7,0,0,0,4},
        {6,0,0,0,0,0,0,0,0},
        {7,4,0,0,1,0,0,0,3},
        {0,0,8,0,0,0,0,0,0},
        {0,0,0,5,0,0,9,0,0},
        {0,0,6,0,2,0,0,0,0},
        {2,8,0,0,0,9,3,0,0},
        {0,0,1,0,0,0,0,0,8}
	};
	print_sudoku(sudoku);
	printf("%d\n", solve(sudoku, 0));
	return (0);
}
