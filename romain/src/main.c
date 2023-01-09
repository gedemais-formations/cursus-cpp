#include "../include/main.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int bsq(int argc ,char **argv){
int i = 1 ;
	while(i<argc)
{
	get_map(argv[i]);
}

}


int main(int argc, char **argv)
{
	char *s = "Hello World";
	char *charset = "o";

	char **resultat = ft_split(s, charset);
	int i = 0;
	while(resultat[i]!=NULL)
	{
		printf("%s \n",resultat[i]);
		free(resultat[i]);
		i++;
	}
	free(resultat);
	return 0;
}
