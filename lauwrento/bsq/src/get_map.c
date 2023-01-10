#include "main.h"

int get_map(int fd, Env* env) {
  env->str = read_fd(fd, env);
  if (env->str == NULL) {
    return (ERROR_POINTER);
  }

  if ((env->err_code = get_metadata(env)) != ERROR_NONE) {
    return (env->err_code);
  }

  if ((env->err_code = get_board(env)) != ERROR_NONE) {
    return (env->err_code);
  }

  free(env->str);

  if ((env->err_code = solver(env)) != ERROR_NONE) {
    return (env->err_code);
  }

  print_solution(env);

  return (0);
}