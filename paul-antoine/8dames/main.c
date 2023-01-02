#include <stdio.h>
#include <stdbool.h>
#define CHESS_SIZE 8

/**
 * Check if the queen at x,y is in the path of another queen on the left side of the chessboard
 * @param chessboard
 * @param x the column
 * @param y the row
 * @return True if no queen is in path with "x,y" false otherwise
 */
bool check_queen(bool chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y)
{
    bool res = false;
    //Check for row y column from 0 to x for a queen
    for (int i = 0; i < x; ++i) {
        res = res || chessboard[i][y];
    }

    //check up-left diagonal
    int x_c = x;
    int y_c = y;
    while (x_c >= 0 && y_c >= 0) {
        res = res || chessboard[x_c][y_c];
        x_c--;
        y_c--;
    }

    //check down-left diagonal
    x_c = x;
    y_c = y;
    while (x_c >= 0 && y_c < CHESS_SIZE) {
        res = res || chessboard[x_c][y_c];
        x_c--;
        y_c++;
    }

    //Since we add queens sequentially on x the next x should be blank
   /* x_c = x;
    y_c = y;
    while (x_c < CHESS_SIZE && y_c >= 0) {
        res = res || chessboard[x_c][y_c];
        x_c++;
        y_c--;
    }

    x_c = x;
    y_c = y;
    while (x_c < CHESS_SIZE && y_c < CHESS_SIZE) {
        res = res || chessboard[x_c][y_c];
        x_c++;
        y_c++;
    }*/

    //res is true if we have a queen in path, so we return its opposite
    return !res;
}

/**
 * Print the chessboard on stdout
 * @param chessboard
 */
void print_chessboard(bool chessboard[CHESS_SIZE][CHESS_SIZE])
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

/**
 * Solve the n queen dilema using backtracking
 * @param chessboard
 * @param x
 * @return number of solution found
 */
int solve(bool chessboard[CHESS_SIZE][CHESS_SIZE], int x)
{
    int res = 0;

    // if we're at the last column we check if we can add a queen print the board if we can
    // and add one to the solve result
    if(x == CHESS_SIZE -1) {
        for (int i = 0; i < CHESS_SIZE; ++i) {
            if(check_queen(chessboard, x, i)) {
                res +=1;
                chessboard[x][i] = true;
                print_chessboard(chessboard);
                chessboard[x][i] = false;
            }
        }
    // otherwise for each line we check if we can put a queen and if we can we try to solve x+1
    // and add its value to res
    } else {
        for (int i = 0; i < CHESS_SIZE; ++i) {
            if(check_queen(chessboard, x, i)) {
                chessboard[x][i] = true;
                res += solve(chessboard, x+1);
                chessboard[x][i] = false;
            }
        }
    }

    return res;
}

int    main(void)
{
    bool chessboard[CHESS_SIZE][CHESS_SIZE] = {};

    print_chessboard(chessboard);
    printf("%d\n", solve(chessboard, 0));
}