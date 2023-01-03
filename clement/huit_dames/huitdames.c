#include <stdbool.h>
#include <stdio.h>
#define CHESS_SIZE 8

bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y)
{
    int i = 0;
    
    //droite
    while((y+i)<CHESS_SIZE){
        if(chessboard[x][y+i] == 1){
            return (false);
        }
        i++;
    }
    i = 0;
    //gauche
    while((y-i)>=0){
        if(chessboard[x][y-i] == 1){
            return (false);
        }
        i++;
    }
    i = 0;
    //bas
    while((x+i)<CHESS_SIZE){
        if(chessboard[x+i][y] == 1){
            return (false);
        }
        i++;
    }
    i = 0;
    //haut
    while((x-i)>=0){
        if(chessboard[x-i][y] == 1){
            return (false);
        }
        i++;
    }
    i = 0;
    //bas droite
    while((x+i)<CHESS_SIZE && (y+i)<CHESS_SIZE){
        if(chessboard[x+i][y+i] == 1){
            return (false);
        }
        i++;
    }
    i = 0;
    //bas gauche
    while((x-i)>=0 && (y+i)<CHESS_SIZE){
        if(chessboard[x-i][y+i] == 1){
            return (false);
        }
        i++;
    }
    i = 0;
    //haut droite
    while((x+i)<CHESS_SIZE && (y-i)>=0){
        if(chessboard[x+i][y-i] == 1){
            return (false);
        }
        i++;
    }
    i = 0;
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
    //print_chessboard(chessboard);
    //getc(stdin);
    int possibilites = 0;
    if( x+1 == CHESS_SIZE){
        for(int y = 0; y < CHESS_SIZE; y++){
            if(check_queen(chessboard, x, y)){
                //printf("%d\n", check_queen(chessboard, y, x));
                //printf("%d ", x);
                //print_chessboard(chessboard);
                chessboard[x][y] = 1;
                printf("solution trouvée\n");
                print_chessboard(chessboard);
                possibilites++;
                chessboard[x][y] = 0;
            }
        }
    }
    else{
        for(int y = 0; y < CHESS_SIZE; y++){
            if(check_queen(chessboard, x, y)){
            	chessboard[x][y] = 1;
            	//printf("%d ", chessboard[y][x]);
                //print_chessboard(chessboard);
                possibilites += solve(chessboard, x+1);
                //printf("poss = %d\n", possibilites);
                chessboard[x][y] = 0;
                }
            }
        }
    //todo: ajouter les reines quand elles sont valides et remettre le tableau à son état précédent quand on atteint une impasse.
    return (possibilites);
}

int    main(void)
{
    int chessboard[CHESS_SIZE][CHESS_SIZE] = {};
    /*chessboard[0][0] = 1;
    chessboard[5][1] = 1;
    chessboard[7][2] = 1;
    chessboard[2][3] = 1;
    chessboard[6][4] = 1;
    chessboard[3][5] = 1;
    chessboard[1][6] = 1;*/
    print_chessboard(chessboard);
    printf("%d\n", solve(chessboard, 0));
}
