#include "main.h"

void print_solution(Env *env) {
  // Calcul the top left corner of the square
  int x = env->maxsq.x - env->maxsq.len;
  int y = env->maxsq.y - env->maxsq.len;

  // printf(GREEN "[%d,%d]\n" RESET, x, y);
  // printf(RED "[%d,%d]\n" RESET, env->maxsq.x, env->maxsq.y);

  for (int i = 0; env->map[i] != NULL; i++) {
    for (int j = 0; env->map[i][j] != '\0'; j++) {
      if (env->map[i][j] == env->metadata.obstacle) {
        printf("%c", env->metadata.obstacle);
        continue;
      }
      if (i > y && i <= env->maxsq.y && j > x && j <= env->maxsq.x) {
        printf(GREEN "%c" RESET, env->metadata.square);
        continue;
      }
      printf("%c", env->metadata.freeSpace);
    }
    printf("\n");
  }
  // char *str;
  // int str_size;

  // str_size = env->cols + 1 * env->rows;

  // str =

  // write(stdout, str, str_size);
}