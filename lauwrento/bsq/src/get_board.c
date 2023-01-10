#include "main.h"

int get_board(Env* env) {
  int i;
  if (!(env->board = ft_split(env->str, "\n"))) {
    return (ERROR_MEM);
  }
  env->map = &env->board[1];
  env->metadata.cols = (int)str_len(env->map[1]);
  i = 2;
  while (env->map[i] != NULL) {
    if (env->metadata.cols != (int)str_len(env->map[i]))
      return (ERROR_BOARD);
    i++;
  }

  return (0);
}