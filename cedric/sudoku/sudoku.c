#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define SUDOKU_SIZE 4
int count_solved;
int sqr = SUDOKU_SIZE*SUDOKU_SIZE;

int init_sudoku(int sudoku[sqr][sqr]){
  for(int i=0; i<sqr; i++){
    for(int j = 0; j < sqr; j++){
      if (i == 0){
        sudoku[i][j] = j+1;
      } else {
        sudoku[i][j] = 0;
      }
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

// Solve the problem
int solve(int sudoku[sqr][sqr], int x, int value) {
	int i;
  if(value == sqr+1){
    print_sudoku(sudoku);
		count_solved++; //global variable
  }
  else if(x == sqr) {
		//print_sudoku(sudoku);
    solve(sudoku, 1, value + 1);
	} else {

  }
	for(i = 0; i < sqr; i++) {
		if(check_value(sudoku, x, i, value) && sudoku[x][i]==0) {
			sudoku[x][i] = value;
      //printf("%d ", x+1);
			solve(sudoku, x + 1, value);
		}
	}
	return count_solved;
}

int main(void) {
  //Initialization of sudoku
  int sudoku[sqr][sqr];
  init_sudoku(sudoku);
  print_sudoku(sudoku);
  getc(stdin);
  printf("%d\n", solve(sudoku, 1, 1));
  return 0;
}
