#define CHESS_SIZE 8

// appel des librairies
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include <unistd.h>

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

	if ((c-i > -1 && r-i > -1 && chessboard[c-i][r-i]==1) || (c-i > -1 && r+i < CHESS_SIZE && chessboard[c-i][r+i]==1))			// check diagonales gauche montante ou descendante
	{
		// printf("r : %d\n", r);
		// printf("c : %d\n", c);
		// chessboard[c][r]=2;			// conflit
		chessboard[c][r]=0;			// conflit
		return (false);
		return (false);
	}
	else if (c-i > -1 && chessboard[c-i][r]==1)			//check horizontal gauche
		{
		// printf("r : %d\n", r);
		// printf("c : %d\n", c);
		// chessboard[c][r]=3;			// conflit
		chessboard[c][r]=0;			// conflit
		return (false);
		}
//		printf("i : %d\n", i);
//		printf("c-i : %d\n", c-i);
//		printf("r-i : %d\n", r-i);
	}
	// print_chessboard(chessboard);
	return(true);
}



int solve (int chessboard[CHESS_SIZE][CHESS_SIZE], int c)
{
	int count = 0;
	int s_return;
	// print_chessboard(chessboard);
	// usleep(100);
	if (c == CHESS_SIZE)
	{
		// printf("THERE\n");
		print_chessboard(chessboard);
		return(1);
	}
	for(int r=0; r<CHESS_SIZE; r++)
	{
		if (check_queen(chessboard, c, r)==true)
		{
			chessboard[c][r]=1;
			s_return = solve(chessboard,c+1);
			count += s_return;
			chessboard[c][r]=0;
		}
	}
	return(count);
}

int main(void)
{
	int count =0;
	int chessboard[CHESS_SIZE][CHESS_SIZE] = {};
	for (unsigned int i = 0; i < CHESS_SIZE; i++)
	{
		memset(chessboard[i], 0, sizeof(int) * CHESS_SIZE);
	}
	// int game_size ();
	print_chessboard(chessboard);
	count = solve(chessboard,0);
	printf("Number of solution for %d-Queen Problem is : %d\n", CHESS_SIZE, count);
}
