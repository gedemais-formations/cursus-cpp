#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<math.h>

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
    //printf("Error, cannot open the file : %s\n", strerror(errno));
    perror(strerror(errno));
    perror("Cannot open file\n");

    return(NULL);
  }
  
  //Read file
  sz = read(fd, buffer, buffer_size);
  //printf("%d\n", sz);
  if(sz == -1){
    //printf("Error, cannot read file : %s\n", strerror(errno));
    perror(strerror(errno));
    perror("Cannot read file\n");
    return(NULL);
  } else {
    buffer[sz] = '\0';
  }

  //Close file
  cl = close(fd);
  if(cl == -1){
    //printf("Error, cannot close file : %s\n", strerror(errno));
    perror(strerror(errno));
    perror("Cannot close file\n");
  }
  printf("Contenu du fichier :\n%s \n", buffer);
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
  //printf("count line : %d\n", count);
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
int print_tab(char **tab){
  int i = 0;
  int x;
  x = sizeof(&tab[0]);
  size_t size = sizeof(tab) / sizeof(*tab[0]);
  printf("x : %d \n", x);
  printf("size : %ld \n", size);
  /*while(i != x*x){
    printf("%c", tab[i/x][i%x]);
    if(i%x==x-1){
      printf("\n");
    }
    i++;
  }*/
  return (i);
}

// Print tab 2
int print_tab2(char **tab, int count_line, int count_char_per_line){
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
  //printf("Paramètres : %d %d %d \n", size_square, count_line, count_char_per_line);
  if((size_square > count_line) || (size_square > count_char_per_line)){
    return(0);
  }

  //printf("xmax et ymax : %d %d\n", size_square, size_square);
  printf("irange et jrange : %d %d\n", count_char_per_line - size_square + 1, count_line - size_square + 1);
  for(int i = 0; i < count_char_per_line - size_square + 1; i++){
    for (int j = 0; j < count_line - size_square + 1; j++){
      printf("i et j : %d %d\n", i, j);
      for(int x = i; x < size_square; x++){
        for(int y = j; y < size_square; y++){
          //printf("x et y : %d %d\n", x, y);
          if(find_an_o(tab, x, y) == 1){
            return(0);
          }
        }
      }
      for(int x = 0; x < size_square; x++){
        for(int y = 0; y < size_square; y++){
          tab[x][y] = 'x';
          //printf("On met un x\n");
        }
      }
      return(1);
    }
  }
  //printf("Unexcepted error\n");
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
    //printf("%d\n", i);
  }
  
  //Transform into a tab
  i = 0;
  while(file_content[j] != '\0'){
    if(file_content[j] == '\n'){
      j++; //Remove all \n
    }
    tab[i/count_char_per_line][i%count_char_per_line] = file_content[j];
    //printf("%c", file_content[j]);
    //printf("[%d][%d]\n", i/count_char_per_line, i%count_char_per_line);
    i++;
    j++;
  }
  
  //Find a solution
  if(count_line < count_char_per_line){
    i = count_line;
  } else {
    i = count_char_per_line;
  }
  printf("find_square value : %d\n", find_square(tab, i, count_line, count_char_per_line));
  while(find_square(tab, i, count_line, count_char_per_line) == 0 && i > 0){
    i--;
  }

  print_tab2(tab, count_line, count_char_per_line);

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
  char file_name[] = "foo.txt";


  if(stat(file_name, &sb) == -1){
    perror("stat");
    return (-1);
  } else {
    printf("File size: %ld bytes\n", sb.st_size);
  }

  file_content = open_read(file_name, sb.st_size);
  if(!file_content){
    return (-1);
  } else {
    //printf("%d\n", count_char_per_line(file_content));
    //printf("Check 1\n");
    //fflush(stdout);
    solve(file_content, count_lines(file_content), 
    count_char_per_line(file_content));
    free(file_content);
    return 0;
  }
}

// gcc -Wall -Werror -Wextra -g3 -fsanitize=address bsq.c -o bsq -lm