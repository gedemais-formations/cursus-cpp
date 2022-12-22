#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define SUDOKU_SIZE 3
int count_solved;
int sqr = SUDOKU_SIZE*SUDOKU_SIZE;

int init_sudoku(int sudoku[sqr][sqr]){
  int grille[9][9] =
    {
        {9,0,0,1,0,0,0,0,5},
        {0,0,5,0,9,0,2,0,1},
        {8,0,0,0,4,0,0,0,0},
        {0,0,0,0,8,0,0,0,0},
        {0,0,0,7,0,0,0,0,0},
        {0,0,0,0,2,6,0,0,9},
        {2,0,0,3,0,0,0,0,6},
        {0,0,0,2,0,0,9,0,0},
        {0,0,1,9,0,4,5,7,0}
    };
  for(int i=0; i<sqr; i++){
    for(int j = 0; j < sqr; j++){
      sudoku[i][j] = grille[i][j];
      //sudoku[i][j] = 0;
    }
  }
  return (0);
}

bool check_value(int sudoku[sqr][sqr], int x, int y, int value){
  bool check = true;
  int i = 0;
  int square_x = x/SUDOKU_SIZE;
  int square_y = y/SUDOKU_SIZE;
  int a, b; //For check square
  //Check for rows
  while(i<sqr && check){
    if(sudoku[i][y]==value){
      check = false;
    }
    i++;
  }

  //Check for columns
  i=0;
  while(i<sqr && check){
    if(sudoku[x][i]==value){
      check = false;
    }
    i++;
  }

  //Check for squares
  i=0;
  a=0;
  b=0;
  while(i<sqr && check){
    //printf("%d et %d\n", square_x*SUDOKU_SIZE+a, square_x*SUDOKU_SIZE+b);
    if(sudoku[square_x*SUDOKU_SIZE+a][square_y*SUDOKU_SIZE+b]==value){
      check = false;
    }
    //Need to reset row to increment columns
    a++;
    if(a==SUDOKU_SIZE){
      b++;
      a=0;
    }
    i++;
  }
  //getc(stdin);
  return(check);
}

// Print the sudoku in consol
void print_sudoku(int sudoku[sqr][sqr]){
    printf("\nNEW SUDOKU \n");
    printf("---------------------\n");
    for (int x = 0; x < sqr; x++){
      for (int y = 0; y < sqr; y++){
        printf("%d ", sudoku[x][y]);
        if(y%SUDOKU_SIZE == SUDOKU_SIZE-1 && y != sqr-1){
          printf("| ");
        }
      }
      printf("\n");
      if(x%SUDOKU_SIZE == SUDOKU_SIZE-1){
        printf("-");
        for(int i = 0; i < sqr; i++){
          printf("--");
        }
        printf("-\n");
      }
    }
}

/*// Solve the problem Doesn't Work
int solve(int sudoku[sqr][sqr], int x, int value) {
	int i;
  getc(stdin);
  if(value == sqr+1){
    printf("IF VALUE");
    print_sudoku(sudoku);
		count_solved++; //global variable
  }
  else if(x == sqr) {
    printf("IF VALUE");
		//print_sudoku(sudoku);
    solve(sudoku, 1, value + 1);
	} else {

  }
	for(i = 0; i < sqr; i++) {
		if(check_value(sudoku, x, i, value) && sudoku[x][i]==0) {
			sudoku[x][i] = value;
      printf("%d %d \n", x, i);
      print_sudoku(sudoku);
			solve(sudoku, x + 1, value);
		}
	}
	return count_solved;
}*/

int solve(int sudoku[sqr][sqr], int indice){
  int count = 0;
  //Check if it's end, if end, print solution
  if(indice == sqr*sqr){
    //print_sudoku(sudoku);
    //Check the last cell of sudoku
    if(sudoku[sqr - 1][sqr - 1] != 0) {
        print_sudoku(sudoku);
        count = 1;
    }
  } else {
    int x = indice / sqr; //get x with indice
    int y = indice % sqr; //get y with indice

    //Recursivity call
    if(sudoku[x][y] != 0){
      count = solve(sudoku, indice+1);
    } else {
      for(int i = 1; i < sqr+1; i++){
        if(check_value(sudoku, x, y, i)) {
            sudoku[x][y] = i;
            count += solve(sudoku, indice+1);
            sudoku[x][y] = 0;
        }
      }
    }
  }
  return count;
}


int main(void) {
  //Initialization of sudoku
  int sudoku[sqr][sqr];
  init_sudoku(sudoku);
  print_sudoku(sudoku);
  //getc(stdin);
  //printf("%d\n", solve(sudoku, 1, 1)); //OLD SOLUTION (WORK only for 1 value)
  printf("%d\n", solve(sudoku, 0));
  return 0;
}
