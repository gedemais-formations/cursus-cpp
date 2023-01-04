#ifndef MAIN_LIB
#define MAIN_LIB

#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128

char **parser(char *str, int *error_code);
int analyse(char *str, int *boardLength, int *boardHeigth);
char *read_fd(int fd, int *error_code);
size_t str_len(const char *s);
void error_handler(unsigned char code);
void min(int a, int b);
void max(int a, int b);
char *ft_strdup(char *s, char *charset);
char **ft_split(char *s, char *charset);
bool ft_strchr(char c, char *charset);

#endif
