#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
//#define malloc(x) NULL
#define BUFFER_SIZE 128

void parser(char str);
void error_handler(unsigned char code);

int start(int argc, char **argv) {
  (void)argv;

  char buf[BUFFER_SIZE];
  char *ptr;
  int size;
  int fd;

  fd = argc == 1 ? 0 : open(argv[1], O_RDONLY);

  ptr = (char *)malloc(BUFFER_SIZE);
  if (ptr == NULL)
    return (ERROR_MEM);
  int i = 0;
  // Get the content of FD
  do {
    size = read(fd, buf, BUFFER_SIZE);

    if (size > 0) {
      ptr = (char *)realloc(ptr, BUFFER_SIZE * (i + 1));

      if (ptr == NULL)
        return (ERROR_MEM);

      memcpy(&ptr[BUFFER_SIZE * i], buf, size);
    }
    i++;

  } while (size == BUFFER_SIZE);

  write(1, ptr, strlen(ptr));

  return (0);
}

int main(int argc, char **argv) {
  int code;

  if ((code = start(argc, argv)) != ERROR_NONE) {
    error_handler(code);
    return (code); // errors defined in error.h
  }
}
