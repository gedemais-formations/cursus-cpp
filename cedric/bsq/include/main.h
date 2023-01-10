#ifndef BSQ_H
#define BSQ_H

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<math.h>

typedef struct s_metadata{
	int nb_line;
	int nb_col;
	char empty_char;
	char obstacle_char;
	char full_char;
	char** board;	
} t_file;

int bsq(char *filename);
char *read_map(char *file_name, int buffer_size);

#endif