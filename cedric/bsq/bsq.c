#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include <sys/stat.h>
#include <math.h>

// Open a file, read it, close it and return the file content
char *open_read(char *file_name, int buffer_size){
  int fd, sz, cl;
  char *buffer;
  if (!(buffer = malloc(buffer_size+1))){
    return(NULL);
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
  int length = sizeof tab;
  int row = sizeof(tab) / sizeof(&tab[0]);
  while(i < length){
    printf("%c", tab[i/row][i%row]);
    if(i%length==length-1){
      printf("\n");
    }
    i++;
  }
  return (0);
}

// Try to find a square
int find_square(char **tab, char size_square){
  int find = 1;
  int i = 0;
  while(i < size_square && find == 1){
    if(find_an_o(tab, i/size_square, i%size_square)==1){
      find = 0;
      return 0;
    } else {
      tab[i/size_square][i/size_square]='x';
    }
  }
  print_tab(tab);
  return (1);
}

int solve(char *file_content, int count_line, int count_row){
  char **tab = NULL;
  int i = 0;
  tab = (char **) malloc(sizeof(char*) * count_row);
  for(i = 0; i < count_line; i++){
    tab[i] = (char *) malloc(sizeof(char) * count_line);
  }
  
  //Transform into a tab
  while(file_content[i] != '\0'){
    tab[i/count_row][i%count_row] = file_content[i];
    i++;
  }
  
  //Find a solution
  i = count_line;
  while(find_square(&tab[0], i) == 0 && i < 1){
    i--;
  }

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
    printf("Check 1");
    fflush(stdout);
    solve(file_content, count_lines(file_content), 
      count_char_per_line(file_content));
    free(file_content);
    return 0;
  }
}

// gcc -Wall -Werror -Wextra -g3 -fsanitize=address bsq.c -o bsq -lm