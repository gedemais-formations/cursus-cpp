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

  str = (char *)malloc(BUFFER_SIZE);
  if (str == NULL) return (ERROR_MEM);
  read_fd(fd, str);

  board = parser(str, &code);
  if (board == NULL){
    code = ERROR_POINTER;
  }

  if ((code = analyse(board) != ERROR_NONE)) {
    return code;
  }

  (void)board;
  return (0);
}

int main(int argc, char **argv) {
  int code;

  if ((code = start(argc, argv)) != ERROR_NONE) {
    error_handler(code);
    return (code);  // errors defined in error.h
  }
}
