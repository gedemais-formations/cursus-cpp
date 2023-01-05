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
 char *test = 0 ; 
   while (recherche(s[longueur],charset)==0)
    {
        longueur++;
    }

   test = malloc(sizeof(char)*(longueur+1));
  while (recherche(s[i],charset)==0)
    {
        test[i] = s[i];
        i++;
    }

    test[i] = '\0';

    return test;
}

int main ()
{
	char *resultat = ft_strdup("Bonjour tout le monde","o");
	printf("%s",resultat);
	free(resultat);
	return 0 ;
}
