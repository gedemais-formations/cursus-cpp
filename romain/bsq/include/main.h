#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

typedef struct s_map {
		int nb_lines ;
		int nb_columns ;
		char empty;
		char obstacle;
		char full;
		char *map;
} map_t;

char *ft_strdup(char *s ,char *charset);

char **ft_split(char *s, char * charset);
map_t *get_map(char *path); 

#endif
