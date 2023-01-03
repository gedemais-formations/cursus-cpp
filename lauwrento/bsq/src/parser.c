#include <main.h>

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
      // printf("%d\nsize=%d\n", i, size);

      if (i > 0) {
        // printf("realloc size = %d\n", BUFFER_SIZE * (i + 1));
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

  str[BUFFER_SIZE * i - size + 1] = '\0';
  return (str);
}

unsigned int str_len(const char *s) {
  unsigned int count = 0;
  while (*s != '\0') {
    count++;
    s++;
  }
  return count;
}

int analyse(char *str, int *boardLength, int *boardHeigth) {
  int i;
  i = 0;
  while (i != 10) {
    if (str[i] == '\n') break;
    i++;
  }
  i++;
  int length = 0;
  int heigth = 0;
  while (str[i] != '\0') {
    if (str[i] == '\n') {
      if (heigth != 0 && *boardLength != length) return (ERROR_BOARD);

      *boardLength = length;
      length = 0;

      heigth++;
      i++;
    }
    length++;
    i++;
  }

  *boardHeigth = heigth;
  // Check if str respect all condition
  return (0);
}

char **parser(char *str, int *code_error) {
  char **board;
  char fileDetails[10];
  int i;
  int boardStart;

  int y = 0;

  // get the fileDetails
  i = 0;
  while (i == 9) {
    if (str[i] == '\n') break;
    fileDetails[i] = str[i];

    i++;
  }
  fileDetails[i + 1] = '\0';

  boardStart = i + 1;

  char tmp[10];
  memcpy(tmp, fileDetails, 10);
  tmp[str_len(tmp) - 3] = '\0';
  // String to int
  for (int i = 0; tmp[i] != '\0'; ++i) y = y * 10 + tmp[i] - '0';

  int row, col;
  row = 0;
  col = 0;

  board = malloc(y);
  if (board == NULL) {
    *code_error = ERROR_MEM;
    return NULL;
  }

  // Get the length of line
  int length = 0;
  i = boardStart;
  while (str[i] != '\n') {
    length++;
    i++;
  }

  i = boardStart;
  while (str[i] != '\0') {
    printf("Row : %d\n", row);
    if (str[i] == '\n') {
      printf("str = %c", str[i]);
      row++;
      col = 0;
    }

    if (col == 0) {
      board[row] = (char *)malloc(length + 1);
      if (board == NULL) {
        *code_error = ERROR_MEM;
        return NULL;
      }
    }

    board[row][col] = str[i];
    i++;
    col++;
  }
  (void)col;
  (void)row;

  return (board);
}
