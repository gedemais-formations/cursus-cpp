#include <stdbool.h>
#include <stdio.h>
#define CHESS_SIZE 8

bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y)
{
    int i = 1;
    //droite
    while((y+i)<=CHESS_SIZE){
        if(chessboard[x][y+i] == 1){
            return (false);
        }
        i++;
    }
    i = 1;
    //gauche
    while((y-i)>=0){
        if(chessboard[x][y-i] == 1){
            return (false);
        }
        i++;
    }
    i = 1;
    //bas
    while((x+i)<=CHESS_SIZE){
        if(chessboard[x+i][y] == 1){
            return (false);
        }
        i++;
    }
    i = 1;
    //haut
    while((x-i)>=0){
        if(chessboard[x-i][y] == 1){
            return (false);
        }
        i++;
    }
    i = 1;
    //bas droite
    while((x+i)<=CHESS_SIZE && (y+i)<=CHESS_SIZE){
        if(chessboard[x+i][y+i] == 1){
            return (false);
        }
        i++;
    }
    i = 1;
    //bas gauche
    while((x-i)>=0 && (y+i)<=CHESS_SIZE){
        if(chessboard[x-i][y+i] == 1){
            return (false);
        }
        i++;
    }
    i = 1;
    //haut droite
    while((x+i)<=CHESS_SIZE && (y-i)>=0){
        if(chessboard[x+i][y-i] == 1){
            return (false);
        }
        i++;
    }
    i = 1;
    //haut gauche
    while((x-i)>=0 && (y-i)>=0){
        if(chessboard[x-i][y-i] == 1){
            return (false);
        }
        i++;
    }
    // check lines, column, diags
    return (true);
}

void print_chessboard(int chessboard[CHESS_SIZE][CHESS_SIZE])
{
    printf("--------------------------\n");
    for (int x = 0; x < CHESS_SIZE; x++)
    {
        for (int y = 0; y < CHESS_SIZE; y++)
            printf("%d ", chessboard[x][y]);
        printf("\n");
    }
    printf("--------------------------\n");
}

int solve(int chessboard[CHESS_SIZE][CHESS_SIZE], int x)
{
    (void)chessboard;
    (void)x;
    return (0);
}

int    main(void)
{
    int chessboard[CHESS_SIZE][CHESS_SIZE] = {};

    print_chessboard(chessboard);
    printf("%d\n", solve(chessboard, 0));
}
