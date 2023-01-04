#include <main.h>

int start(int argc, char **argv) {
  int fd, code;
  char **board;
  char *str;
  // If there is no argument read stdin else read argv
  if (argc == 1) {
    fd = 0;
  } else {
    fd = open(argv[1], O_RDONLY);
  }

  str = read_fd(fd, &code);

  // board = ft_split(str, "\n");
  board = ft_split("My little poney", NULL);
  if (board == NULL) {
    return ERROR_POINTER;
  }

  // if ((code = analyse(str, &boardLength, &boardHeight)) != ERROR_NONE) {
  //   printf("%d", code);
  //   return code;
  // }

  // board = parser(str, &code);

  //  if (board == NULL) {
  //  code = ERROR_POINTER;
  //}

  for (int i = 0; board[i] != NULL; i++) {
    printf("%s\n", board[i]);
  }
  free(board);
  free(str);
  return (0);
}

int main(int argc, char **argv) {
  int code;
  // fflush(stdin);

  if ((code = start(argc, argv)) != ERROR_NONE) {
    error_handler(code);
    return (code);  // errors defined in error.h
  }
}
