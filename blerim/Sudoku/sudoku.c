#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

//Using backtracking algorithm technique  to resolve problem recursively by removing soloution that doesnt match  condition

//Function to print grid
void print_grid(int arr[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}

//Function which tell us if it is valid to assingn number in actual row, column
int validAssign(int gridSudoku[SIZE][SIZE], int row, int column , int number)
{
    //test if we find the same number in similar row we will return zero
    for (int j = 0; j <=8 ; j++) {
        if(gridSudoku[row][j]==number)
            return 0;
    }

    //If we find the same number in similar column we will return zero
    for (int i = 0; i <=8 ; i++) {
        if(gridSudoku[i][column]==number)
            return 0;
    }

    //If we find the same number in matrix 3x3 we will return zero
    //we devide row and column by module 3 x(3x3)
    int matrixRow = row - row % 3;
    int matrixColumn = column - column % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(gridSudoku[i+matrixRow][j+matrixColumn]==number)
                return 0;
        }
    }
    return 1;
}

int solveSudoku(int gridSudoku[SIZE][SIZE], int row, int column) {

    //if we reach 8th row and 9th column we are returning true to avoid backtracking
    if (row == SIZE - 1 && column == SIZE)
        return 1;

    //If the column reach 9 we move on to the next row and column start from 0
    if (column == SIZE) {
        row++;
        column = 0;
    }

    //if the current position of grid already contain value greater than 0 we iterate for next column
    if (gridSudoku[row][column] > 0)
        return solveSudoku(gridSudoku, row, column + 1);


    for (int number = 1; number <= SIZE; number++) {

        // test if it is valid to put number from  1 to 9  in the  given row ,col  we  move to next column
        if (validAssign(gridSudoku, row, column, number) == 1) {
            // assing number in row column position and assume your prediction
            gridSudoku[row][column] = number;

            //  test for next possibility with next column
            if (solveSudoku(gridSudoku, row, column + 1) == 1)
                return 1;
        }

        //If our assumption it was wrong to assign number we will remove our assigned number after  we can try  for next assupmtion with different values
        gridSudoku[row][column] = 0;

    }

    return 0;
}

int main()
{
    // 0 means unassigned cells
    int gridSudoku[SIZE][SIZE] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                                   { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                                   { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                                   { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                                   { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                                   { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                                   { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                                   { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                                   { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

     if (solveSudoku(gridSudoku, 0, 0)==1)
        print_grid(gridSudoku);
     else
        printf("Your soloution is wrong");

    return 0;
}
