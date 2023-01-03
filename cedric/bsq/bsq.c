#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include <sys/stat.h>


#define SIZE 100

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

int count_char_per_line(char *file_content){
  int count = 0;
  while(file_content[count] != '\n'){
    count ++;
  }
  return count;
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
    printf("%d", count_char_per_line(file_content));
  }
  
  free(file_content);
  return 0;
}

// gcc -Wall -Werror -Wextra -g3 -fsanitize=address bsq.c -o bsq