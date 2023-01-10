#include "main.h"

bool check_metadata(char square, char obstacle, char free) {
  if (square == obstacle || square == free || obstacle == free)
    return (false);

  return (true);
}

int get_metadata(Env* env) {
  char* dest;
  size_t len;

  if (!(dest = ft_strdup(env->str, "\n"))) {
    return (ERROR_MEM);
  }

  if ((len = str_len(dest)) < 4) {
    free(dest);
    return (ERROR_BOARD);
  }

  env->metadata.square = dest[len - 1];
  env->metadata.obstacle = dest[len - 2];
  env->metadata.freeSpace = dest[len - 3];

  if (!check_metadata(env->metadata.square, env->metadata.obstacle,
                     env->metadata.freeSpace)) {
    free(dest);
    return (ERROR_BOARD);
  }

  // Get number of rows;
  dest[len - 3] = '\0';
  // Array to int;
  for (int i = 0; dest[i] != '\0'; ++i)
    env->metadata.rows = env->metadata.rows * 10 + dest[i] - '0';

  free(dest);

  return (0);
}