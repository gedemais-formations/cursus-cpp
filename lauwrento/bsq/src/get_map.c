#include "main.h"

int get_map(int fd) {
  char **board;
  char *str;
  int err_code;

  str = read_fd(fd, &err_code);
  if (str == NULL) {
    return (ERROR_POINTER);
  }
  board = ft_split(str, "\n");
  if (board == NULL) {
    return (ERROR_POINTER);
  }

  solver(board, &err_code);

  free(str);
  for (int i = 0; board[i] != NULL; i++) free(board[i]);
  free(board);
  return (0);
}