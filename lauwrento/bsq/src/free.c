#include "main.h"

void free_board(char** board) {
  if (board) {
    for (int i = 0; board[i] != NULL; i++) {
      free(board[i]);
    }
    free(board);
  }
}

void free_env(Env* env) {
  free_board(env->board);

  // if (env->str)
  // free(env->str);
}