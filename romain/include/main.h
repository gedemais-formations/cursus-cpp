#ifndef MAIN_H
# define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct s_map {
		int nb_lines ;
		int nb_columns ;
		char empty;
		char obstacle;
		char full;
		char *map;
} map_t;


char **ft_split(char *s, char * charset);
t_map *get_map(char *path); 

#endif
