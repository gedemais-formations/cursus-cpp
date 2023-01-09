#include "main.h"

char *ft_strdup(char *s, char *charset, int n)
{
	char *dest = NULL;
	int iterateur = 0;
	int iterSet;
	int nbrIncorrect = 0;
	
	while(iterateur < strlen(s) && horsDeCharset)
	{
		iterSet = 0
		while(iterSet < strlen(charset))
		{
			if(&charset[iterSet] == &s[iterateur])
			{
				if(iterateur > nbrIncorrect)
				{
					return (dest);
				}
				else
				{
					nbrIncorrect++;
				}
			}
			else
			{
				if(n>0)
				{
					n--;
					nbrIncorrect++;
				}
			}
			
			iterset++;
		}
		dest[iterateur-nbrIncorrect] = s[iterateur];
		iterateur++;
	}
	
	return (dest);
}

char **ft_split(char *s, char *charset)
{
	char **sortie /*= malloc()*/;
	int iterateur = 0;
	int ligne = 0;
	int colonne = 0;
	int iterSet;
	bool horsDeCharset;
	while(iterateur < strlen(s))
	{
		horsDeCharset = true;
		iterset = 0;
		while(iterSet < strlen(charset) && horsDeCharset)
		{
			if(&charset[iterSet] == &s[iterateur])
			{
				horsDeCharset = false;
			}
			iterSet++;
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
			sortie[ligne][colonne] = s[iterateur];
		}
		colonne++;
		iterateur++;
	}
	return sortie;
}
