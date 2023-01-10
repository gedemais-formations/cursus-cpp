#include "bsq.h"

// Find an o on a cell
int find_an_o(char **tab, int x, int y){
  if(tab[x][y]=='o'){
    return (1);
  } else {
    return (0);
  }
}

// Print tab
int print_tab(char **tab, int count_line, int count_char_per_line){
  int i = 0;
  while(i != count_char_per_line*count_line){
    printf("%c", tab[i/count_char_per_line][i%count_char_per_line]);
    if(i%count_char_per_line==count_char_per_line-1){
      printf("\n");
    }
    i++;
  }
  return (0);
}

//Try to find a square and if find, return it
int find_square(char **tab, int size_square, int count_line, int count_char_per_line){
  int boolean;
  if((size_square > count_line) || (size_square > count_char_per_line)){
    return(0);
  }

  boolean = 1;
  for(int i = 0; i < count_line - size_square + 1; i++){
    for (int j = 0; j < count_char_per_line - size_square + 1; j++){
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

int solve(char *file_content, int count_line, int count_char_per_line){
  
  
  //Find a solution
  if(count_line < count_char_per_line){
    i = count_line;
  } else {
    i = count_char_per_line;
  }
  while(find_square(tab, i, count_line, count_char_per_line) == 0 && i > 0){
    i--;
  }

  print_tab(tab, count_line, count_char_per_line);

  for(i = 0; i < count_line; i++){
    free(tab[i]);
  }
  free(tab);

  return (0);
}