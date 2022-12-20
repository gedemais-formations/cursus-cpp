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
	int r, c;
	for (c=0; c<CHESS_SIZE;c++)			
	{
		for (r=0; r<CHESS_SIZE;r++)
		{
		printf("%d ", chessboard[r][c]);		// va "print" un 1 dans la case r,c
		}
		printf("\n");
	}
	printf("----------\n");				// imprime une ligne de - pour faciliter la lecture
}

// "fonction" qui verifie si une autre queen est sur la même ligne, col ou diag
// en entrée, le chessboard sur lequel une première queen a été positionnée, un entier définissant le numéro de ligne et un entier définissant le numéro de colonne
// en sortie, returns 1 si pas de conflit sinon 0


bool check_queen (int chessboard[CHESS_SIZE][CHESS_SIZE], int r, int c)
{
	for(int i=1;i<CHESS_SIZE;i++)
	{	
		fflush(stdout);
		printf("i : %d\n", i);
		printf("r : %d\n", r);
		printf("c : %d\n", c);
		printf("c-i : %d\n", c-i);
		printf("r-i : %d\n", r-i);

		if ((chessboard[r-i][c-i]==1 && r-i > -1 && c-i > -1) || (chessboard[r+i][c-i]==1 && r+i < (CHESS_SIZE+1) && c-i > -1))			// check diagonales gauche montante ou descendante
		{
		chessboard[r][c]=0;			// conflit
		i=CHESS_SIZE;
		}
	else if (chessboard[r][c-i]==1 && c-i > -1)			//check horizontal gauche
		{
		chessboard[r][c]=0;			// conflit
		i=CHESS_SIZE;
		}
	else
		{
		chessboard[r][c]=1;			// no conflit mettre le 1
		}	
	}
	print_chessboard(chessboard);
	return(0);
}



int solve (int chessboard[CHESS_SIZE][CHESS_SIZE], int c)
{
int count = 0;
	for(int r=0;r<=CHESS_SIZE;r++)
	{
		if (check_queen(chessboard,r,c)==true)
	{
	chessboard[r][c]=1;
	solve(chessboard,c+1);
	chessboard[r][c]=0;
	return(0);
	}
	count++;
	return(count);
	printf("Number of solution for %dCHESS_SIZE -Queen Problem is ", CHESS_SIZE);
	printf("%dcount\n", solve(chessboard,c));
	}
return(0);
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
	solve(chessboard, 0);
}
