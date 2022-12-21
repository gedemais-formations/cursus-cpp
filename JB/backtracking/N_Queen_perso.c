#define CHESS_SIZE 8

// appel des librairies
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

/* demander le nb de Queens/taille d'un coté de l'échéquier carré

int game_size(CHESS_SIZE) 				// fonction a un entier en argument et renvoi un entier en sorti
{
printf("\nEnter the wanted Number of Queens:\t");
scanf("%d", &CHESS_SIZE);
return(0);						// il faudra vérifier que CHESS_SIZE est supérieur à 3 dans la fonction principale sinon 
}
*/

// "fonction" qui va "placer" la première queen sur chaque case du chessboard et à partir de laquelle les autres possibilités seront testées

void print_chessboard(int chessboard[CHESS_SIZE][CHESS_SIZE])
{
	printf("----------\n");				// imprime une ligne de - pour faciliter la lecture
	for (int r=0; r<CHESS_SIZE; r++)			
	{
		for (int c=0; c<CHESS_SIZE; c++)
		{
		printf("%d ", chessboard[c][r]);		// va "print" un 1 dans la case r,c
		}
		printf("\n");
	}
	printf("----------\n");				// imprime une ligne de - pour faciliter la lecture
}

// "fonction" qui verifie si une autre queen est sur la même ligne, col ou diag
// en entrée, le chessboard sur lequel une première queen a été positionnée, un entier définissant le numéro de ligne et un entier définissant le numéro de colonne
// en sortie, returns 1 si pas de conflit sinon 0


bool check_queen (int chessboard[CHESS_SIZE][CHESS_SIZE], int c, int r)
{
	for(int i=1; i<CHESS_SIZE; i++)
	{	
		fflush(stdout);

	if ((c-i > -1 && r-i > -1 && chessboard[c-i][r-i]==1) || (c+i < (CHESS_SIZE) && r-i > -1 && chessboard[c+i][r-i]==1))			// check diagonales gauche montante ou descendante
		{
		chessboard[c][r]=2;			// conflit
		i=CHESS_SIZE;
		}
	else if ( c-i > -1 && chessboard[c-1][r]==1)			//check horizontal gauche
		{
		chessboard[c][r]=3;			// conflit
		i=CHESS_SIZE;
		}
	else
		{
		chessboard[c][r]=1;			// no conflit mettre le 1
		i=CHESS_SIZE;
		}
		printf("i : %d\n", i);
		printf("r : %d\n", r);
		printf("c : %d\n", c);
		printf("c-i : %d\n", c-i);
		printf("r-i : %d\n", r-i);
	}
	print_chessboard(chessboard);
	return(0);
}



int solve (int chessboard[CHESS_SIZE][CHESS_SIZE], int r)
{
int count = 0;
	for(int c=0; c<CHESS_SIZE; c++)
	{
		if (check_queen(chessboard,c,r)==true)
	{
	chessboard[c][r]=1;
	solve(chessboard,r+1);
	chessboard[c][r]=0;
	}
	count++;
	printf("Number of solution for %d-Queen Problem is :\n", CHESS_SIZE);
	}
return(count);
}

int main(void)
{
	int chessboard[CHESS_SIZE][CHESS_SIZE] = {};
		for (unsigned int i = 0; i < CHESS_SIZE; i++)
		{
		memset(chessboard[i], 0, sizeof(int) * CHESS_SIZE);
		}
	// int game_size ();
	print_chessboard(chessboard);
	printf("%d\n", solve(chessboard,0));
}
