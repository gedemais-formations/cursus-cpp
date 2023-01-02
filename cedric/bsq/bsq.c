#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

const char * open_read(char *file_name, int byte){
    int fd, sz;
    char *c = (char *) calloc(100, sizeof(char));
    fd = open(file_name, O_RDONLY);
    //printf("%s\n", file_name);
    //Open file
    if(fd < 0){
      printf("Error, cannot open the file : %s\n", strerror(errno));
      return("Cannot open file");
    }
    //Read file
    sz = read(fd, c, byte);
    if(sz == -1){
      printf("Error, cannot read file : %s\n", strerror(errno));
      return("File empty");
    }
    //printf("Contenu du fichier c : %s \n", c);

    return (c);
}

// int argc, char const *argv[]
int main() {
  //USE GETCWD to get print
  //Path : home/cedric/cursus-cpp/cedric/
  printf("%s\n", open_read("foo.txt", 100));
  return 0;
}

// gcc -Wall -Werror -Wextra -g3 -fsanitize=address bsq.c -o bsq