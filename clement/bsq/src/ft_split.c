#include "main.h"

char **ft_split(char *s, char *charset)
{
	int iterateur = 0;
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
	char **sortie = (char **) malloc(nbEntrees * sizeof(char *));
	//tableau contenant l'index de début de chaque chaine valide ainsi que leur longueur. 
	int **coordChaines = (int**) malloc(nbEntrees * sizeof(int *));
	for(int i = 0; i < nbEntrees; i++)
	{
		coordChaines[i] = (int*) malloc(nbEntrees * sizeof(int));
		coordChaines[i][0] = 0;
		coordChaines[i][1] = 0;
	}
	iterateur = 0;
	eligible = true;
	int l = 0;
	//préparation des valeurs de coordChaines pour pouvoir remplir sortie avec memcpy()
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
				l++;
				coordChaines[l][0] = iterateur;
				eligible = false;
			}
			coordChaines[l][1]++;
		}
		else
		{
			eligible = true;
		}
		iterateur++;
	}
	//remplissage de chacune des cases de sortie
	for(int i = 0; i < nbEntrees; i++)
	{
		sortie[i] = (char *) malloc(coordChaines[i][1] * sizeof(char));
		memcpy(sortie[i], &s[coordChaines[i][0]], coordChaines[i][1]);
	}
	//libération de la mémoire prise par coordChaines
	for(int i = 0; i < nbEntrees; i++)
	{
		free(coordChaines[i]);
	}
	free(coordChaines);
	return sortie;
}
