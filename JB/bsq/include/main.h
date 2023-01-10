#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct s_metadata{
         int nb_line;
         int nb_col;
         char empty_char;
         char obstacle_char;
         char full_char;
	 char** map;
	 char** board;
}        t_metadata;

// inclure tous les prototypes des fonctions qui seront utilisés
int char_charset(char string_char_x,char *charset);
char *ft_strdup (char *string_char, char *charset);
char **ft_split (char *string_char, char *charset);
int	bsq(int argc, char** argv, t_metadata *m_map);
int	get_map(char *path, t_metadata *m_map);
void free_array(char** map);
int solve(t_metadata* m_map);
int min_val (int x, int y);

#endif
