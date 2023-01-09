#include "main.h"

char *ft_strdup(char *s, char *charset);
char **ft_split(char *s, char *charset);

int main(void)
{
	char **sortie;
	if(!(sortie = ft_split("Je m'apelle George", "e")))
	{
		return 1;
	}
	for(unsigned int i = 0; sortie[i]; i++)
	{
		printf("%s\n", sortie[i]);
		free(sortie[i]);
	}
	/*char *sortie;
	if(!(sortie = ft_strdup("Bonjour", j, 0)))
	{
		return 1;
	}
	printf("%s\n", sortie);*/
	free(sortie);
	return 0;
}
