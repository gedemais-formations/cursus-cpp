#include <stdio.h>
#include <malloc.h>

#define N 9
#define LINE N/3

short ** board;

char is_valid(short number, short index_x, short index_y) {
	short i, j, area_x, area_y;
	//On regarde si le numéro n'est pas déjà présent sur la même ligne
	for(i = 0; i < N; i++) {
		if(board[i][index_y] == number) return 0;
	}
	//On regarde si le numéro n'est pas déjà présent sur la même colonne
	for(i = 0; i < N; i++) {
		if(board[index_x][i] == number) return 0;
	}
	//On regarde la zone (ici 3x3)
	area_x = index_x - index_x % 3;
	area_y = index_y - index_y % 3;
	for(i = 0; i < LINE; i++) {
		for(j = 0; j < LINE; j++) {
			if(board[i + area_x][j + area_y] == number) return 0;
		}
	}
	return 1;
}

char solve(short x, short y) {
	short number;
	if(x == N && y == N - 1) return 1; //Dernière case
	//Si on atteint l'extrêmité, on change de ligne
	if(x == N) {
		x = 0;
		y++;
	}
	if(board[x][y] > 0) return solve(x + 1, y);
	for(number = 1; number <= N; number++) {
		if(is_valid(number, x, y)) {
			board[x][y] = number;
			if(solve(x + 1, y)) return 1;
		}
		board[x][y] = 0; //Cas où c'est faux
	}
	return 0;
}

int main() {
	short i, j;
	board = (short **)malloc(sizeof(short *) * N);
	for(i = 0; i < N; i++) board[i] = (short *)malloc(sizeof(short) * N);
	solve(0, 0);
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}
