#include "main.h"

int solver(Env *env) {
  int rows, cols, i, j;
  int *dp;

  env->freeSpace = '.';
  env->obstacle = 'o';

  rows = 0;
  cols = 0;

  for (i = 1; env->board[i] != NULL; i++) {
    for (j = 0; env->board[i][j] != '\0'; j++) {
      cols++;
    }
    rows++;
  }

  cols = cols / rows;

  dp = calloc((rows * cols), sizeof(int));
  if (dp == NULL) {
    env->maxsq.len = 0;
    env->err_code = ERROR_MEM;
    return (env->err_code);
  }

  for (i = 1; env->board[i] != NULL; i++) {
    for (j = 0; env->board[i][j] != '\0'; j++) {
      if (env->board[i][j] == env->freeSpace) dp[(i - 1) * cols + j] = 1;
      if (env->board[i][j] == env->obstacle) dp[(i - 1) * cols + j] = 0;
    }
  }

  env->maxsq.len = 0;

  for (i = 1; i != rows; i++) {
    for (j = 1; j != cols; j++) {
      if (env->board[i + 1][j] == env->freeSpace) {
        int min_left_up = min(dp[i * cols + (j - 1)], dp[(i - 1) * cols + j]);
        dp[i * cols + j] = min(min_left_up, dp[(i - 1) * cols + (j - 1)]) + 1;

        env->maxsq.len = max(env->maxsq.len, dp[i * cols + j]);
        if (env->maxsq.len == dp[i * cols + j]) {
          env->maxsq.y = i;
          env->maxsq.x = j;
        }
      }
    }
  }
  printf("maxsqlen = %d\n", env->maxsq.len);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d", dp[i * cols + j]);
    }
    printf("\n");
  }

  free(dp);

  return (0);
}