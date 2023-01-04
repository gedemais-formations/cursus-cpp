#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

int nb_ligne(char *map)
{
	int fd = open(map, O_RONLY);
	int ligne = read(fd, 
	return 0;
}

int main()
{
	return 0;
}
