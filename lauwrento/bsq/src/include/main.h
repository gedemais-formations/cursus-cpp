#ifndef MAIN_LIB
#define MAIN_LIB 

#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 128

void parser(char str);
void error_handler(unsigned char code);

#endif
