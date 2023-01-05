#include "main.h"

void print_solution(Env *env) {
  char *red = "\033[0;35m";
  char *green = "\033[0;32m";
  char *reset = "\033[0m";

  int x = env->maxsq.x - env->maxsq.len;
  int y = env->maxsq.y - env->maxsq.len;
  env->square = 'x';

  printf("%s[%d,%d]%s\n", green, x, y, reset);
  printf("%s[%d,%d]%s", red, env->maxsq.x, env->maxsq.y, reset);

  for (int i = 1; env->board[i] != NULL; i++) {
    for (int j = 0; env->board[i][j] != '\0'; j++) {
      if (env->board[i][j] == env->obstacle) {
        printf("%c", env->obstacle);
        continue;
      }
      if (i > y && i <= env->maxsq.y && j > x && j <= env->maxsq.x) {
        if (i == env->maxsq.y && j == env->maxsq.x) {
          printf("%s%c%s", red, env->square, reset);
          continue;
        }
        if (i == y + 1 && j == x + 1) {
          printf("%s%c%s", green, env->square, reset);
          continue;
        }
        printf("%c", env->square);
        continue;
      }
      printf("%c", env->board[i][j]);
    }
    printf("\n");
  }
}