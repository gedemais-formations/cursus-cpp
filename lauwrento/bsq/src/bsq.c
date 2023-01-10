#include "main.h"

int start(int argc, char** argv, Env* env) {
  int fd, code;

  // If there is no argument read stdin else read argv
  for (size_t i = 1; i < (size_t)argc; i++) {
    if ((fd = open(argv[i], O_RDONLY)) == -1) {
      return (ERROR_OPEN);
    }

    if (env) {
      free_env(env);
      memset(env, 0, sizeof(Env));
    }

    if ((code = get_map(fd, env)) != ERROR_NONE) {
      error_handler(code, env);
      continue;
    }
  }

  if (argc == 1) {
    fd = STDIN_FILENO;
    if ((code = get_map(fd, env)) != ERROR_NONE) {
      return (code);
    }
  }

  return (0);
}

int main(int argc, char** argv) {
  Env env;
  int code;
  // fflush(stdin);
  memset(&env, 0, sizeof(Env));

  if ((code = start(argc, argv, &env)) != ERROR_NONE) {
    error_handler(code, &env);
    return (code);  // errors defined in error.h
  }

  free_env(&env);
  return (0);
}
