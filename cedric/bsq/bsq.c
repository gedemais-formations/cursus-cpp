#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

const char * open_read(char * file_name, int byte){
    int fd, sz;
    char *c = "";
    fd = open(file_name, O_RDONLY);
    if(fd < 0){
      printf("Erreur, ouverture du fichier impossible\n");
      exit(1);
    }
    //Open file
    sz = read(fd, c, byte);
    if(sz == -1){
      printf("Cannot open file : %s\n", strerror(errno));
    }
    printf("Contenu du fichier c : %s \n", c);

    return (c);
}

// int argc, char const *argv[]
int main() {
  //USE GETCWD to get print
  //Path : home/cedric/cursus-cpp/cedric/
  open_read("foo.txt", 100);
  return 0;
}
