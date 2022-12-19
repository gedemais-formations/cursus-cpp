#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define CHESS_SIZE 8

// Fonction to check if queen can be here
bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y){
    // check lines, column, diags
	bool check = true;
	int i;


	//Check rows above
	i = 1;
	while(check==true && x+i < CHESS_SIZE){
		//printf("%d et %d \n", x+i, y);
		if(chessboard[x+i][y] == 1){
			check = false;
		}
		i++;
	}

	//Check rows before
	i = 1;
	while(check==true && x-i >= 0){
		//printf("%d et %d \n", x-i, y);
		if(chessboard[x-i][y] == 1){
			check = false;
		}
		i++;
	}

	//Check columns above
	i = 1;
	while(check==true && y+i < CHESS_SIZE){
		//printf("%d et %d \n", x, y+1);
		if(chessboard[x][y+i] == 1){
			check = false;
		}
		i++;
	}

	//Check columns before
	i = 1;
	while(check==true && y-i >= 0){
		if(chessboard[x][y-i] == 1){
			check = false;
		}
		i++;
	}

	//Check diagonal above
	i = 1;
	while(check==true && x+i < CHESS_SIZE && y+i < CHESS_SIZE){
		printf("+ %d et %d \n", x+i, y+i);
		if(chessboard[x+i][y+i] == 1){
			check = false;
			printf("false");
		}
		i++;
	}

	//Check diagonal before
	i = 1;
	while(check==true && x-i >= 0 && y-i >= 0){
		printf("- %d et %d \n", x-i, y-i);
		if(chessboard[x-i][y-i] == 1){
			check = false;
		}
		i++;
	}

	//Check anti-diagonal above
	i = 1;
	while(check==true && x+i < CHESS_SIZE && y-i >= 0){
		if(chessboard[x+i][y-i] == 1){
			check = false;
		}
		i++;
	}

	//Check anti-diagonal before
	i = 1;
	while(check==true && x-i >= 0 && y+i < CHESS_SIZE){
		if(chessboard[x-i][y+i] == 1){
			check = false;
		}
		i++;
	}

	return (check);
}

void print_chessboard(int chessboard[CHESS_SIZE][CHESS_SIZE]){
    printf("--------------------------\n");
    for (int x = 0; x < CHESS_SIZE; x++){
		for (int y = 0; y < CHESS_SIZE; y++){
			printf("%d ", chessboard[x][y]);
		}
		printf("\n");
    }
    printf("--------------------------\n");
}

int solve(int chessboard[CHESS_SIZE][CHESS_SIZE], int x){
    (void)chessboard;
    (void)x;
		int i = 0;
		while(!check_queen(chessboard, x, i) && i < CHESS_SIZE-1){
			i ++;
		}
		if(check_queen(chessboard, x, i)){
			chessboard[x][i] = 1;
			print_chessboard(chessboard);
			if(x < 8){
				solve(chessboard, x+1);
			}
		}
		return (0);
}

int main(void){
	int chessboard[CHESS_SIZE][CHESS_SIZE] = {};
	//int count_solved = 0;
	for (unsigned int i = 0; i < CHESS_SIZE; i++){
		memset(chessboard[i], 0, sizeof(int) * CHESS_SIZE);
	}
	chessboard[0][0]=1;
	print_chessboard(chessboard);
	printf("%d\n", solve(chessboard, 0));
	return (1);
}
