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
	unsigned int nb_line;
	unsigned int nb_char; //Nb of char per line
	char empty_char;
	char obstacle_char;
	char full_char;
	char** board;	
} t_file;

int bsq(char *file_name);
int get_map(t_file *bsq_file, char *file_content);
int solve(t_file *bsq_file);
int free_bsq(t_file *bsq_file);

char *ft_strdup(const char *s, const char *charset);

#endif