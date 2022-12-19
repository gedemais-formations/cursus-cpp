


#include <stdbool.h>
#include <stdio.h>
#define CHESS_SIZE 8


bool check_queen(int chessboard[CHESS_SIZE][CHESS_SIZE], int x, int y)
{
    // check lines, column, diags
   
    //check if there is a queen on the left
    for(int i =0;i<y;i++) {
        if(chessboard[CHESS_SIZE][i])
                return (false);
    }
   
    for (int i=x,j=y; i>=0 && j>=0; i--,j--) {
      if (chessboard[i][j]) //check whether there is queen in the left upper diagonal or not
         return (false);
   }
   for (int i=x,j=y; j>=0 && i<CHESS_SIZE; i++,j--) {
      if (chessboard[i][j]) //check whether there is queen in the left lower diagonal or not
         return (false);
   }
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



int solve(int chessboard[CHESS_SIZE][CHESS_SIZE], int y) {
   if (y >= CHESS_SIZE) //when y queense placed successfully
      return true;
   for (int i = 0; i < CHESS_SIZE; i++) { //for each row, check placing of queen is possible or not
      if (check_queen(chessboard, i, y) ) {
         chessboard[i][y] = 1; //if validate, place the queen at place (i, col)
         if ( solve(chessboard, y + 1)) //Go for the other columns recursively
            return true;
         chessboard[i][y] = 0; //When no place is vacant remove that queen
      }
   }
   return false; //when no possible order is found*
   print_chessboard(chessboard);  
}

int main()
{
 int chessboard[CHESS_SIZE][CHESS_SIZE];
        solve(chessboard, 0);
        return 0;
}


    
