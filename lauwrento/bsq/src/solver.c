#include "main.h"

int solver(Env* env) {
  int i, j;
  int* dp;

  if (!(dp = calloc((env->metadata.rows * env->metadata.cols), sizeof(int)))) {
    env->maxsq.len = 0;
    return (ERROR_MEM);
  }

  for (i = 1; env->board[i] != NULL; i++) {
    for (j = 0; env->board[i][j] != '\0'; j++) {
      if (env->board[i][j] == env->metadata.freeSpace)
        dp[(i - 1) * env->metadata.cols + j] = 1;
      if (env->board[i][j] == env->metadata.obstacle)
        dp[(i - 1) * env->metadata.cols + j] = 0;
    }
  }

  env->maxsq.len = 0;

  for (i = 1; i != env->metadata.rows; i++) {
    for (j = 1; j != env->metadata.cols; j++) {
      if (env->board[i + 1][j] == env->metadata.freeSpace) {
        int min_left_up = min(dp[i * env->metadata.cols + (j - 1)],
                              dp[(i - 1) * env->metadata.cols + j]);
        dp[i * env->metadata.cols + j] =
            min(min_left_up, dp[(i - 1) * env->metadata.cols + (j - 1)]) + 1;

        int maxsqlen = max(env->maxsq.len, dp[i * env->metadata.cols + j]);
        if (maxsqlen > env->maxsq.len) {
          env->maxsq.len = maxsqlen;
          env->maxsq.y = i;
          env->maxsq.x = j;
        }
      }
    }
  }
  printf("maxsqlen = %d\n", env->maxsq.len);
  
  free(dp);

  return (0);
}