#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *s, char *charset)
{
	char **sortie;
	int iterateur = 0;
	int ligne = 0;
	int colonne = 0;
	int iterSet = 0;
	bool horsDeCharset;
	if(&s == NULL)
	{
		return NULL;
	}
	while(iterateur < strlen(&s))
	{
		horsDeCharset = true;
		while(iterSet < strlen(&charset) && horsDeCharset)
		{
			if(&charset[iterSet] == &s[iterateur])
			{
				horsDeCharset = false;
			}
		}
		if(horsDeCharset)
		{
			if(colonne !=0)
			{
				colonne = 0;
				ligne++;
			}
		}
		else
		{
			&&sortie[ligne][colonne] = &s[iterateur];
		}
		colonne++;
		iterateur++;
	}
	return sortie;
}
