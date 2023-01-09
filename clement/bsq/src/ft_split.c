#include "main.h"

/*char *ft_strdup(char *s, char *charset, int n)
{
	char *dest = NULL;
	int iterateur = 0;
	int iterSet;
	int nbrIncorrect = 0;
	
	while(iterateur < strlen(s))
	{
		iterSet = 0;
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
			
			iterSet++;
		}
		dest[iterateur-nbrIncorrect] = s[iterateur];
		iterateur++;
	}
	
	return (dest);
}*/

char **ft_split(char *s, char *charset)
{
	int iterateur = 0;
	//int ligne = 0;
	//int colonne = 0;
	int iterSet=0;
	int nbEntrees = 0;
	bool horsDeCharset;
	bool eligible = true;
	//préparation de la taille de 
	while(iterateur < (int)strlen(s))
	{
		horsDeCharset = true;
		iterSet = 0;
		while(iterSet < (int)strlen(charset) && horsDeCharset)
		{
			if(charset[iterSet] == s[iterateur])
			{
				horsDeCharset = false;
			}
			iterSet++;
		}
		if(horsDeCharset)
		{
			if(eligible)
			{
				nbEntrees++;
				eligible = false;
			}
		}
		else
		{
			eligible = true;
		}
		iterateur++;
	}
	printf("%d\n", nbEntrees);
	char **sortie = (char **) malloc(nbEntrees * sizeof(char *));
	char temp[] = "";
	iterateur = 0;
	eligible = true;
	int i = 0;
	while(iterateur < (int)strlen(s))
	{
		horsDeCharset = true;
		iterSet = 0;
		while(iterSet < (int)strlen(charset) && horsDeCharset)
		{
			if(charset[iterSet] == s[iterateur])
			{
				horsDeCharset = false;
			}
			iterSet++;
		}
		if(horsDeCharset)
		{
			if(eligible)
			{
				i++;
				eligible = false;
			}
			//strcat(temp, s[i]);
		}
		else
		{
			eligible = true;
		}
		/*if(horsDeCharset)
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
		iterateur++;*/
	}
	return sortie;
}
