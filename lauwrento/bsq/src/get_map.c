#include "main.h"

int get_map(int fd, Env *env) {
  int err_code;

  env->str = read_fd(fd, &err_code);
  if (env->str == NULL) {
    return (ERROR_POINTER);
  }

  env->board = ft_split(env->str, "\n");
  if (env->board == NULL) {
    return (ERROR_POINTER);
  }

  if ((env->err_code = solver(env)) != ERROR_NONE) {
    return (env->err_code);
  }

  print_solution(env);

  return (0);
}