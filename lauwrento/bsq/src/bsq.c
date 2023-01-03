#include <main.h>

int start(int argc, char **argv) {
  int fd, code;
  char **board;
  char *str;
  int boardLength, boardHeight;

  // If there is no argument read stdin else read argv
  if (argc == 1) {
    fd = 0;
  } else {
    fd = open(argv[1], O_RDONLY);
  }

  str = read_fd(fd, &code);

  if ((code = analyse(str, &boardLength, &boardHeight)) != ERROR_NONE) {
    return code;
  }

  // board = parser(str, &code);

  //  if (board == NULL) {
  //  code = ERROR_POINTER;
  //}

  // for (unsigned int i = 0; i < str_len(*board); i++) {
  // printf("%s\n", board[i]);
  //}
  (void)board;
  (void)boardHeight;
  (void)boardLength;
  // free(board);
  free(str);
  return (0);
}

int main(int argc, char **argv) {
  int code;
  fflush(stdout);

  if ((code = start(argc, argv)) != ERROR_NONE) {
    error_handler(code);
    return (code);  // errors defined in error.h
  }
}
