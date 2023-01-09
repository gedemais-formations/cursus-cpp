#include "bsq.h"

// Open a file, read it, close it and return the file content
char *open_read(char *file_name, int buffer_size){
  int fd, sz, cl;
  char *buffer = NULL;
  if (!(buffer = malloc(buffer_size+1))){
    printf("Error malloc\n");
    return(buffer);
  }
  
  //Open file
  fd = open(file_name, O_RDONLY);
  //printf("%s\n", file_name);
  if(fd < 0){
    perror(strerror(errno));
    perror("Cannot open file\n");

    return(NULL);
  }
  
  //Read file
  sz = read(fd, buffer, buffer_size);
  if(sz == -1){
    perror(strerror(errno));
    perror("Cannot read file\n");
    return(NULL);
  } else {
    buffer[sz] = '\0';
  }

  //Close file
  cl = close(fd);
  if(cl == -1){
    perror(strerror(errno));
    perror("Cannot close file\n");
  }
  //printf("Contenu du fichier :\n%s \n", buffer);
  return (buffer);
} 

// Count elements on the first line
int count_char_per_line(char *file_content){
  int count = 0;
  while(file_content[count] != '\n'){
    count ++;
  }
  //count++; //Take the '\n'
  return count;
}

int count_lines(char *file_content){
  int count = 0;
  int i = 0;
  while(file_content[i] != '\0'){
    if(file_content[i] == '\n'){
      count ++;
    }
    i++;
  }
  count ++; //The last line doesn't have \n
  return (count);
}

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
  char **tab = NULL;
  int i = 0;
  int j = 0;
  if (! (tab = (char **) malloc(sizeof(char*) * count_line))){
    return(1);
  }
  for(i = 0; i < count_line; i++){
    if(! (tab[i] = (char *) malloc(sizeof(char) * count_char_per_line))){
      return(1);
    }
  }
  
  //Transform into a tab
  i = 0;
  while(file_content[j] != '\0'){
    if(file_content[j] == '\n'){
      j++; //Remove all \n
    }
    tab[i/count_char_per_line][i%count_char_per_line] = file_content[j];
    i++;
    j++;
  }
  
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

// int argc, char const *argv[]
int main() {
  //USE GETCWD to get print
  //Path : home/cedric/cursus-cpp/cedric/
  char *file_content;
  struct stat sb;
  char file_name[] = "foo2.txt";


  if(stat(file_name, &sb) == -1){
    perror("stat");
    return (-1);
  }

  file_content = open_read(file_name, sb.st_size);
  if(!file_content){
    return (-1);
  } else {
    solve(file_content, count_lines(file_content), 
    count_char_per_line(file_content));
    free(file_content);
    return 0;
  }
}

// gcc -Wall -Werror -Wextra -g3 -fsanitize=address bsq.c -o bsq -lm