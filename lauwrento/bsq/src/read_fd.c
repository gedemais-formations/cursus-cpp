#include "main.h"

char* read_fd(int fd, Env* env) {
  char buf[BUFFER_SIZE];
  int size;
  int i = 0;
  char* str;

  str = (char*)calloc(BUFFER_SIZE + 1, sizeof(char));
  if (str == NULL) {
    env->err_code = ERROR_MEM;
    return (NULL);
  }
  // Get the content of the file directory
  do {
    size = read(fd, buf, BUFFER_SIZE);
    fflush(stdin);

    if (size > 0) {
      if (i > 0) {
        if (!(str = (char*)realloc(str, BUFFER_SIZE * (i + 1) + 1))) {
          env->err_code = ERROR_MEM;
          return (NULL);
        }
      }

      memcpy(&str[BUFFER_SIZE * i], buf, size);
    }
    i++;

  } while (size == BUFFER_SIZE);

  str[BUFFER_SIZE * (i - 1) + size] = '\0';
  // close(fd);

  return (str);
}