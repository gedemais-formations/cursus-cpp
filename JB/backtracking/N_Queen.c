#define CHESS_SIZE 8

// appel des librairies
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

// demander le nb de Queens/taille d'un coté de l'échéquier carré

/* int game_size(CHESS_SIZE) 				// fonction a un entier en argument et renvoi un entier en sorti
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
		printf("%d", chessboard[r][c]);		// va "print" un 1 dans la case r,c
		printf("\n");
		}
	}
	printf("----------\n");				// imprime une ligne de - pour faciliter la lecture
}

// "fonction" qui verifie si une autre queen est sur la même ligne, col ou diag
// en entrée, le chessboard sur lequel une première queen a été positionnée, un entier définissant le numéro de ligne et un entier définissant le numéro de colonne
// en sortie, returns 1 si pas de conflit sinon 0


bool check_queen (int chessboard[CHESS_SIZE][CHESS_SIZE], int r, int c)
{
	for(i=1;i<=CHESS_SIZE-1;i++)
	{		
	if (chessboard[r-i][c-i]==1 && r-i > -1 && c-i > -1 || chessboard[r+i][c-i] && r+i < CHESS_SIZE )			// check diagonales gauche montante ou descendante
		return (false);							// conflit
	else if (chessboard[r][c-1]==1)						//check horizontal gauche
		return (false);							// conflit
	}	
print_chessboard();
return (true);									// no conflit
}



int solve (int chessboard[CHESS_SIZE][CHESS_SIZE], int c)
{
int count = 0
	for(r=0;r<=CHESS_SIZE;r++)
	{
	if check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int r, int c)==true
	{
	solve(int chessbpard[CHESS_SIZE][CHESS_SIZE], int c+1);
	return(0);
	}
	count++;
	return(count);
	printf("Number of solution for %d\CHESS_SIZE-Queen Problem is ");
	printf("%d\count\n", solve())
	}
}

int main(void)
{
	// int game_size ();
	void print_chessboard();
	int solve ();
}
