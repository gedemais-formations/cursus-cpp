#include "main.h"

void print_solution(Env *env) {
  printf("[%d,%d]", env->maxsq.x, env->maxsq.y);

  int x = env->maxsq.x - (env->maxsq.len - 1);
  int y = env->maxsq.y - (env->maxsq.len - 1);
  env->square = 'x';

  printf("[%d,%d]\n", x, y);

  for (int i = 1; env->board[i] != NULL; i++) {
    for (int j = 0; env->board[i][j] != '\0'; j++) {
      if (i >= y && i <= env->maxsq.y && j >= x && j <= env->maxsq.x) {
        printf("%c", env->square);
      } else {
        printf("%c", env->board[i][j]);
      }
    }
    printf("\n");
  }
}