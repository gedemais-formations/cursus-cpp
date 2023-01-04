#include "main.h"

char *read_fd(int fd, int *code_error) {
  char buf[BUFFER_SIZE];
  int size;
  int i = 0;
  char *str;

  str = (char *)calloc(BUFFER_SIZE, sizeof(char));
  if (str == NULL) {
    *code_error = ERROR_MEM;
    return (NULL);
  }
  // Get the content of the file directory
  do {
    size = read(fd, buf, BUFFER_SIZE);

    if (size > 0) {

      if (i > 0) {
        str = (char *)realloc(str, BUFFER_SIZE * (i + 1) + 1);

        if (str == NULL) {
          *code_error = ERROR_MEM;
          return (NULL);
        }
      }

      memcpy(&str[BUFFER_SIZE * i], buf, size);
    }
    i++;

  } while (size == BUFFER_SIZE);

  str[BUFFER_SIZE * (i-1) + size] = '\0';
  return (str);
}