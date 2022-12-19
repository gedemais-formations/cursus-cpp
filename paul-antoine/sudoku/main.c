#include <stdio.h>
#include <stdbool.h>

/**
 * Print a sudoku grid on stdout
 * @param sudoku_grid
 */
void print_sudoku(int sudoku_grid[9][9]) {
    printf("\n");
    for (int i = 0; i < 9; ++i) {
        if(i%3 == 0) {
            printf("#---#---#---#\n");
        }
        printf("|%c%c%c|%c%c%c|%c%c%c|\n",
               sudoku_grid[i][0] ? sudoku_grid[i][0] + 48: ' ',
               sudoku_grid[i][1] ? sudoku_grid[i][1] + 48: ' ',
               sudoku_grid[i][2] ? sudoku_grid[i][2] + 48: ' ',
               sudoku_grid[i][3] ? sudoku_grid[i][3] + 48: ' ',
               sudoku_grid[i][4] ? sudoku_grid[i][4] + 48: ' ',
               sudoku_grid[i][5] ? sudoku_grid[i][5] + 48: ' ',
               sudoku_grid[i][6] ? sudoku_grid[i][6] + 48: ' ',
               sudoku_grid[i][7] ? sudoku_grid[i][7] + 48: ' ',
               sudoku_grid[i][8] ? sudoku_grid[i][8] + 48: ' ');
    }

    printf("#---#---#---#\n");
}

/**
 * Check if you can place "number" on "x,y"
 * @param sudoku_grid
 * @param x
 * @param y
 * @param number
 * @return True if number can be placed on "x,y" false otherwise
 */
bool check_number(int sudoku_grid[9][9], int x, int y, int number){
    int groupCol = x / 3;
    int groupRow = y / 3;
    bool res = true;

    // check if number is alone in its column
    for (int i = 0; i < 9; ++i) {
        res = res && sudoku_grid[x][i] != number;
    }

    // check if number is alone in its row
    for (int i = 0; i < 9; ++i) {
        res = res && sudoku_grid[i][y] != number;
    }

    // check if number is alone in its block
    for (int i = 0; i < 9; ++i) {
        res = res && sudoku_grid[i/3+groupCol * 3][i%3+groupRow*3] != number;
    }

    return res;
}

/**
 * Take a sudoku_grid and return number of solution for
 * @param sudoku_grid the grid to solve
 * @param indice the indice to start from (number between 0 and 9*9)
 * @return Number of solution found
 */
int solve(int sudoku_grid[9][9], int indice) {
    int res = 0;

    if(indice == 81) {
        //print_sudoku(sudoku_grid);
        if(sudoku_grid[8][8] != 0) {
            print_sudoku(sudoku_grid);
            res = 1;
        } else {
            for (int i = 0; i < 9; ++i) {
                if(check_number(sudoku_grid, 8, 8, i)) {
                    res += 1;
                    sudoku_grid[8][8] = i;
                    print_sudoku(sudoku_grid);
                    sudoku_grid[8][8] = 0;
                }
            }
        }
    } else {
        int x = indice / 9;
        int y = indice % 9;

        if(sudoku_grid[x][y] != 0 ) {
            res = solve(sudoku_grid, indice+1);
        } else {
            for (int i = 1; i < 10; ++i) {
                if(check_number(sudoku_grid, x, y, i)) {
                    sudoku_grid[x][y] = i;
                    res += solve(sudoku_grid, indice+1);
                    sudoku_grid[x][y] = 0;
                }
            }
        }
    }
    //print_sudoku(sudoku_grid);
    return res;
}

int main() {

    int sudoku_grid[9][9] = {};

    for (int i = 0; i < 9; ++i) {
        printf("Ecrire ligne %d: ", i+1);
        scanf("%d %d %d %d %d %d %d %d %d",
              &sudoku_grid[i][0],
              &sudoku_grid[i][1],
              &sudoku_grid[i][2],
              &sudoku_grid[i][3],
              &sudoku_grid[i][4],
              &sudoku_grid[i][5],
              &sudoku_grid[i][6],
              &sudoku_grid[i][7],
              &sudoku_grid[i][8]);
    }

    print_sudoku(sudoku_grid);

    printf("%d\n", solve(sudoku_grid,0));

    return 0;
}
