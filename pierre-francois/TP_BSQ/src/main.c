#include "../include/main.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	char *s = "Hello World";
	char *charset = "H";
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
