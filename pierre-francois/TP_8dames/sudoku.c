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

	//Condition de solution : on se trouve sur la dernière case de la grille (case numéro 80 comme on commence à 0)
	if (num_case == SUDOKU_SIZE*SUDOKU_SIZE-1)
	{
		//Si la case est différente de 0 c'est que l'on a placé un chiffre qui fonctionne et donc notre sudoku est terminé
		if(sudoku[SUDOKU_SIZE-1][SUDOKU_SIZE-1] != 0)
		{
			print_sudoku(sudoku);
			nbSolution = 1;
		}
		//Sinon on check tous les chiffres pour trouver celui qui correspond
			else
			{
				for(int i=1; i<=SUDOKU_SIZE; i++)
				{
					if(check_number(sudoku, i, SUDOKU_SIZE-1, SUDOKU_SIZE-1))
					{
						nbSolution += 1;

					}
				}
			}
	} else {
		//A partir du numéro de la case, on identifie sa localisation
		//La division va nous permettre de connaître la ligne (en effet pour chaque "lot" de 9 dépassé on change de ligne)
        int x = num_case / SUDOKU_SIZE;
		//Le modulo quant à lui nous permet de connaître sa colonne (pour chaque "lot" de 9 dépassé, le reste de la division repart donc à 0 et correspond au numéro de sa colonne) 
        int y = num_case % SUDOKU_SIZE;

		//On regarde dans un premier temps si la case ne comporte pas déjà un chiffre, si c'est le cas, on passe à la case suivante
        if(sudoku[x][y] != 0 ) {
            nbSolution = solve(sudoku, num_case+1);
		//Sinon on fait un check sur tous les chiffres et si un correspond on passe à la case suivante en résolvant par backtracking	
        } else {
            for (int i = 1; i <= SUDOKU_SIZE; ++i) {
                if(check_number(sudoku, i, x, y)) {
                    sudoku[x][y] = i;
                    nbSolution += solve(sudoku, num_case+1);
                    sudoku[x][y] = 0;
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
        {0,0,0,7,0,0,4,0,6},
        {0,0,9,0,0,0,0,0,0},
        {6,0,8,0,4,0,0,0,1},
        {3,0,6,2,0,0,0,8,0},
        {0,9,0,0,6,0,0,0,0},
        {0,7,0,0,0,0,0,0,3},
        {0,0,0,0,0,5,0,2,0},
        {0,3,0,0,0,0,0,0,0},
        {1,0,4,0,7,0,0,0,8}
	};
	print_sudoku(sudoku);
	printf("%d\n", solve(sudoku, 0));
	return (0);
}
