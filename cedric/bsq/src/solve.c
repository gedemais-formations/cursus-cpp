#include "bsq.h"

// Find an o on a cell
static int find_an_o(char **tab, int x, int y){
  if(tab[x][y]=='o'){
    return (1);
  } else {
    return (0);
  }
}

// Print tab
static int print_tab(t_file bsq_file){
  /* OLD CODE
  int i = 0;
  while(i != count_char_per_line*count_line){
    printf("%c", tab[i/count_char_per_line][i%count_char_per_line]);
    if(i%count_char_per_line==count_char_per_line-1){
      printf("\n");
    }
    i++;
  }*/
  for(unsigned int i = 0; i < bsq_file.nb_char*bsq_file.nb_line){
    printf("%c", bsq_file.board[i/bsq_file.nb_char][i%bsq_file.nb_char]);
    if(i%bsq_file.nb_char==bsq_file.nb_char-1){
      printf("\n");
    }
  }
  return (0);
}

//Try to find a square and if find, return it
static int find_square(t_file bsq_file, int size_square){
  int boolean;
  if((size_square > bsq_file.nb_line) || (size_square > bsq_file.nb_char)){
    return(0);
  }

  boolean = 1;
  for(int i = 0; i < bsq_file.nb_line - size_square + 1; i++){
    for (int j = 0; j < bsq_file.nb_char - size_square + 1; j++){
      boolean = 1;
      for(int x = i; x < size_square + i && boolean == 1; x++){
        for(int y = j; y < size_square + j && boolean == 1; y++){
          if(find_an_o(tab, x, y) == 1){
            boolean = 0;
          }
        }
      }
      if(boolean == 1){
        for(int x = i; x < size_square + i; x++){
          for(int y = j; y < size_square + j; y++){
            tab[x][y] = 'x';
          }
        }
        return(1);
      }
    }
  }
  return(0);
}

int solve(t_file bsq_file){
  //Find a solution
  if(bsq_file.nb_line < bsq_file.nb_char){
    i = bsq_file.nb_line;
  } else {
    i = bsq_file.nb_char;
  }
  while(find_square(&bsq_file) == 0 && i > 0){
    i--;
  }

  print_tab(&bsq_file);

  return (0);
}