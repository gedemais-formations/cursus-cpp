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

char *get_line(char *str, int workingLine, int *code_error) {
  char *line;
  int i, j, lineCount;
  i = 0;
  j = 0;
  lineCount = 0;

  line = (char *)malloc(1);
  if (line == NULL) {
    *code_error = ERROR_MEM;
    return (NULL);
  }

  while (str[i] != '\0') {
    if (lineCount == workingLine) {
      line[j] = str[i];
      line = realloc(line, (i + 1) + 1);
      if (line == NULL) {
        *code_error = ERROR_MEM;
        return (NULL);
      }
      j++;
      if (str[i + 1] == '\n') break;
    }
    if (str[i] == '\n') lineCount++;
    i++;
  }

  return (line);
}

int analyse(char **board) {
  (void)board;

  // Check if str respect all condition
  return (0);
}

char **parser(char *str, int *code_error) {
  char **board;
  char *fileDetails;
  // Get the first line
  fileDetails = get_line(str, 0, code_error);
  printf("%s", fileDetails);
  (void)board;

  return (0);
}
