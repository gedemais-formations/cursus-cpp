#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int recherche(char lettre, char *phrase)
{
	int longue = strlen(phrase);
		for (int i = 0 ;i<longue ; i++)
		{
			if(lettre ==phrase[i])
			{ 
			   return 1 ;
			}
		}
return 0 ;
}



char *ft_strdup(char *s, char *charset)
{
 int longueur = 0;
 int i = 0;
 int taille = strlen(s) ;
 char *test = 0 ; 
   while ( recherche(s[longueur], charset) == 0 && longueur < taille )
    {
        longueur++;
    }

   test = malloc(sizeof(char)*(longueur+1));
   if( test == NULL){
	printf("ERROR : OUT OF MEMORY");
}
	else
{

  while (recherche(s[i],charset) == 0 && i < taille )
    {
        test[i] = s[i];
        i++;
    }

    test[i] = '\0';
}
    return test;
}

char **ft_split(char *s,char *charset)
{ 
	int compteur = 1 ;
    char *strdup = ft_strdup(s , charset);
	char **tab = NULL ;
	int i = 0 ;
	int longueur = strlen(s) ;



	while (i+1 < longueur)
		{	
		 if (recherche(s[i], charset) == 1 && recherche(s[i + 1], charset) == 0)
			{
				compteur ++ ;
			//	i ++ ;
	     	}
		 i++ ;
		} 
	tab = malloc(sizeof(char*)*(compteur+1));
	tab[0]=strdup ;
   i = 0 ;
   int j = 0 ;
     	while  (i+1 < longueur)
		{
		 if (recherche(s[i], charset) == 1 && recherche(s[i + 1], charset) == 0)
			{
				j++ ;
				tab[j] = ft_strdup(&s[i + 1], charset);
	     	}
		 i++ ;
		}

	    tab[j+1] = NULL ;
	//	printf("%d",compteur);
		return tab ;
}
  
int main ()
{
	int i = 0 ;
	char **resultat2 = ft_split("Bonjour tout le monde","o");
	while(resultat2[i] !=NULL)
			{
			printf("%s \n", resultat2[i]);
			free(resultat2[i]);
			i++ ;
			}
	free (resultat2);
	return 0 ;
}
