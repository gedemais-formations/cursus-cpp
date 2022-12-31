#ifndef MAIN_LIB
#define MAIN_LIB

#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128

char **parser(int fd, char *str);
int analyse(int fd, char *str);
void error_handler(unsigned char code);
void min(int a, int b);
void max(int a, int b);

#endif
