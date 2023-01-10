#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

// inclure tous les prototypes des fonctions qui seront utilisés

typedef struct s_map
{
	int nb_lines;
	int nb_columns;
	char empty_char;
	char obstacle_char;
	char full_char;
	char **map_full;
	char **board;
} map_t;

char *ft_strdup(char *s, char *charset);
char **ft_split(char *s, char *charset);
int get_map(char *path, map_t *map);
int solve(map_t *map);


#endif
