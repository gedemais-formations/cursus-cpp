#ifndef MAIN_LIB
#define MAIN_LIB

#include <error.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128

typedef struct s_maxsq {
  int len;
  int x;
  int y;
} MaxSq;

typedef struct s_env {
  MaxSq maxsq;
  char *str;
  char **board;
  char freeSpace;
  char obstacle;
  char square;
  int err_code;
} Env;

char *read_fd(int fd, int *error_code);
size_t str_len(const char *s);
void error_handler(unsigned char code);
int min(int a, int b);
int max(int a, int b);
char *ft_strdup(char *s, char *charset);
char **ft_split(char *s, char *charset);
bool ft_strchr(char c, char *charset);
int get_map(int fd, Env *env);
int solver(Env *env);
void free_env(Env *env);
void print_solution(Env *env);

#endif
