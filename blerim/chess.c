#include <stdio.h>
#include <stdbool.h>
#define CHESS_SIZE 8
 
// chessboard

// Function to check if two queens threaten each other or not
bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y)
{
    // return 0 if two queens share the same column
    for (int i = 0; i < x; i++)
    {
        if (chessboard[i][y]) {
            return false;
        }
    }
 
    // return 0 if two queens share the same `\` diagonal
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if (chessboard[i][j]) {
            return false;
        }
    }
 
    // return 0 if two queens share the same `/` diagonal
    for (int i = x, j = y; i >= 0 && j < CHESS_SIZE; i--, j++)
    {
        if (chessboard[i][j]) {
            return false;
        }
    }
 
    return true;
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
    // if `N` queens are placed successfully, print the solution
    if (x == CHESS_SIZE)
    {
        print_chessboard(chessboard);
        return 0;
    }
 
    // place queen at every square in the current row `r`
    // and recur for each valid movement
    for (int i = 0; i < CHESS_SIZE; i++)
    {
        // if no two queens threaten each other
        if (check_queen(chessboard, x, i))
        {
            // place queen on the current square
            chessboard[x][i] = 1;
 
            // recur for the next row
            solve(chessboard, x + 1);
 
            // backtrack and remove the queen from the current square
            chessboard[x][i] = 0;
        }
    }
}
 
int main()
{
    // `chessboard[][]` keeps track of the position of queens in the current configuration
    int chessboard[CHESS_SIZE][CHESS_SIZE];
    
    for(int i = 0; i<CHESS_SIZE; i++) {
         for(int j = 0; j<CHESS_SIZE; j++) {
             chessboard[i][j]= 0;  //set all element to zero
         }
         }
         if ( solve(chessboard, 0) == false ) { //starting from 0th column
      printf( "Solution does not exist");
      return false;
      }
      return true;
      
 
    return 0;
}
