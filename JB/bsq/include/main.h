#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>

// inclure tous les prototypes des fonctions qui seront utilisés
int char_charset(char string_char_x,char *charset);
char *ft_strdup (char *string_char, char *charset);
char **ft_split (char *string_char, char *charset);

#endif
