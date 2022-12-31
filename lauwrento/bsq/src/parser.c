#include <main.h>

int read_fd(int fd, char *str) {
  char buf[BUFFER_SIZE];
  int size;
  int i = 0;
  // Get the content of the file directory
  do {
    size = read(fd, buf, BUFFER_SIZE);

    if (size > 0) {
      str = (char *)realloc(str, BUFFER_SIZE * (i + 1));

      if (str == NULL) return (ERROR_MEM);

      memcpy(&str[BUFFER_SIZE * i], buf, size);
    }
    i++;

  } while (size == BUFFER_SIZE);

  return (0);
}

int analyse(int fd, char *str) {
  read_fd(fd, str);

  // Check if str respect all condition
  return (0);
}

char **parser(int fd, char *str) {
  (void)fd;
  printf("%s", str);

  return (0);
}
