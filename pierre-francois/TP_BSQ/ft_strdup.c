#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

int est_dans(char lettre, char *phrase)
{
	int taille_phrase=strlen(phrase);

	for(int i=0; i<taille_phrase; i++)
	{
		if(lettre==phrase[i])
		{
			return 1;
		}
	}
	return 0;
}

char *ft_strdup(char *s, char *charset)
{
	int i = 0;
	int taille_s = strlen(s);
	int compteur_place = 0;
	char *copie = NULL;

	while(est_dans(s[i],charset)==0 && i<taille_s)
		{
			compteur_place++;
			i++;
		}
	i=0;
	copie=malloc(sizeof(char)*(compteur_place+1));

	if(copie == NULL)
	{
		return ("MEMORY NOT ALLOCATED");
	}
	while(est_dans(s[i],charset)==0 && i<taille_s)
	{
		copie[i]=s[i];
		i++;
	}
	copie[i]='\0';
	return copie;
}
/*
char **ft_split(char *s, char *charset)
{
	int longueur_s = strlen(s);
	char **resultat = NULL;
}
*/

int main()
{
	char *s = "Hello World";
	char *charset = "p";
	char *resultat = ft_strdup(s, charset);
	printf("%s \n",resultat);
	free(resultat);
	return 0;
}
