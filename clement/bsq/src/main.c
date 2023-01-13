#include "main.h"

int main(void)
{
	char **sortie = malloc(20);
	char *s = malloc(20);
	char *charset = malloc(5);
	s = "Je m'apelle Georges";
	charset = "e";
	sortie = ft_split(s, charset);
	if(!(sortie = ft_split(s, charset)))
	{
		return 1;
	}
	for(unsigned int i = 0; sortie[i]; i++)
	{
		printf("%s\n", sortie[i]);
		free(sortie[i]);
	}
	free(sortie);
	return 0;
}
