#include "main.h"

struct MaxSq solver(char **board, int *err_code) {
  int rows, cols, i, j;
  char freeSpace, obstacle;
  int *dp;
  struct MaxSq maxsq;

  freeSpace = '.';
  obstacle = 'o';

  rows = 0;
  cols = 0;

  for (i = 1; board[i] != NULL; i++) {
    for (j = 0; board[i][j] != '\0'; j++) {
      cols++;
    }
    rows++;
  }

  dp = calloc((rows * cols), sizeof(int));
  if (dp == NULL) {
    maxsq.len = 0;
    *err_code = ERROR_MEM;
    return (maxsq);
  }

  for (i = 1; board[i] != NULL; i++) {
    for (j = 0; board[i][j] != '\0'; j++) {
      if (board[i][j] == freeSpace) dp[i * cols + j] = 1;
      if (board[i][j] == obstacle) dp[i * cols + j] = 0;
    }
  }

  maxsq.len = 0;

  for (i = 2; board[i] != NULL; i++) {
    for (j = 1; board[i][j] != '\0'; j++) {
      if (board[i - 1][j - 1] == '1') {
        dp[i * cols + j] =
            min(min(dp[i * cols + (j - 1)], dp[(i - 1) * cols + j]),
                dp[(i - 1) * cols + (j - 1)]) +
            1;
        maxsq.len = max(maxsq.len, dp[i * cols + j]);
        if (maxsq.len == dp[i * cols + j]) {
          maxsq.y = i;
          maxsq.x = j;
        }
      }
    }
  }

  free(dp);

  return (maxsq);
}