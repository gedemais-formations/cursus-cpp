#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

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

char **ft_split(char *s, char *charset)
{
	char **resultat = NULL;
	int allocation_place = 1;
	int taille_s = strlen(s);
	for (int i = 0; i<taille_s-1; i++)
	{
		if(est_dans(s[i],charset) && !(est_dans(s[i+1],charset)))
				{
					allocation_place++;
				}
	}
	resultat=malloc(sizeof(char*)*(allocation_place+1));
	if(resultat == NULL)
	{
		return NULL;
	}
	int j=0;
	resultat[0]=ft_strdup(s, charset);
	for(int i = 0; i<taille_s; i++)
	{
		if(est_dans(s[i],charset) && !(est_dans(s[i+1], charset)))
		{
			j++;
			resultat[j]=ft_strdup(&s[i+1],charset);
		}
	}
	resultat[j+1]=NULL;
	return resultat;
}

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
