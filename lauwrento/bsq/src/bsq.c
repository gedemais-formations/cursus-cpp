#include "main.h"

int start(int argc, char **argv, Env *env) {
  int fd, code;

  // If there is no argument read stdin else read argv
  if (argc == 1) {
    fd = 0;
  } else {
    fd = open(argv[1], O_RDONLY);
  }

  if ((code = get_map(fd, env)) != ERROR_NONE) {
    return (code);
  }

  // if ((code = analyse(str, &boardLength, &boardHeight)) != ERROR_NONE) {
  //   printf("%d", code);
  //   return code;
  // }

  // board = parser(str, &code);

  // for (int i = 0; board[i] != NULL; i++) {
  //   printf("%s\n", board[i]);
  //   free(board[i]);
  // }
  // (void)board;
  // free(board);
  return (0);
}

int main(int argc, char **argv) {
  Env env;
  int code;
  // fflush(stdin);
  memset(&env, 0, sizeof(Env));
  if ((code = start (argc, argv, &env)) != ERROR_NONE) {
    error_handler(code);
    return (code);  // errors defined in error.h
  }

  free_env(&env);
}
