#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define CHESS_SIZE 8

int compteur = 0;

//Check lines, columns, diag
bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y) {
	int i, j;
	for(i = 0; i < y; i++) if(chessboard[x][i] == 1) return false; //colonne
	for(i = 0; i < x; i++) if(chessboard[i][y] == 1) return false; //ligne
	for(i = x - 1, j = y - 1; j >= 0 && i >= 0; j--, i--) if(chessboard[i][j] == 1) return false; //diagonale gauche
	for(i = x - 1, j = y + 1; i >= 0 && j < CHESS_SIZE; i--, j++) if(chessboard[i][j] == 1) return false; //diagonale droite
	return true;
}

void print_chessboard(int chessboard[CHESS_SIZE][CHESS_SIZE]) {
	printf("--------\n");
	for(int x = 0; x < CHESS_SIZE; x++) {
		for(int y = 0; y < CHESS_SIZE; y++)
			printf("%d ", chessboard[x][y]);
		printf("\n");
	}
	printf("--------\n");
}

int solve(int chessboard[CHESS_SIZE][CHESS_SIZE], int x) {
	int i;
	if(x == CHESS_SIZE) {
		print_chessboard(chessboard);
		compteur++;
		return 0;
	}
	for(i = 0; i < CHESS_SIZE; i++) {
		if(check_queen(chessboard, x, i)) {
			chessboard[x][i] = 1;
			solve(chessboard, x + 1);
		}
		chessboard[x][i] = 0; //Si pas de solution
	}
	return compteur;
}

int main() {
	int chessboard[CHESS_SIZE][CHESS_SIZE] = {};
	print_chessboard(chessboard);
	printf("%d\n", solve(chessboard, 0));
	return 0;
}
