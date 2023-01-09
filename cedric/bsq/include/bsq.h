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

char **ft_split(const char *s, const char *charset);
char *ft_strdup(const char *s, const char *charset);

#endif