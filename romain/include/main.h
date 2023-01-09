#ifndef MAIN_H
# define MAIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_metadata (
		int nb_lines ;
		int nb_columns ;
		char empty;
		char obstacle;
		char full;
) metadata_t;

char **ft_split(char *s, char * charset);

#endif
