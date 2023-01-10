#ifndef MAIN_LIB
#define MAIN_LIB

#include <error.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 65536

// Colors
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

typedef struct s_maxsq {
  int len;
  int x;
  int y;
} MaxSq;

typedef struct s_metadata {
  int rows;
  int cols;
  char freeSpace;
  char obstacle;
  char square;
} metadata_t;

typedef struct s_env {
  MaxSq maxsq;
  metadata_t metadata;
  char* str;
  char** board;
  char** map;
  int err_code;
} Env;

char* read_fd(int fd, Env *env);
size_t str_len(const char* s);
void error_handler(unsigned char code, Env* env);
int min(int a, int b);
int max(int a, int b);
char* ft_strdup(char* s, char* charset);
char** ft_split(char* s, char* charset);
bool ft_strchr(char c, char* charset);
int get_map(int fd, Env* env);
int solver(Env* env);
void free_env(Env* env);
void print_solution(Env* env);
int get_metadata(Env* env);
int get_board(Env* env);

#endif
