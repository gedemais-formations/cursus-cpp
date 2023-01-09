#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

// inclure tous les prototypes des fonctions qui seront utilisés

typedef struct s_map
{
	int nb_lines;
	int nb_columns;
	char empty_char;
	char obstacle_char;
	char full_char;
	char *map;
} t_map;

char **ft_split(char *s, char *charset);
t_map *get_map(char *path);



#endif
