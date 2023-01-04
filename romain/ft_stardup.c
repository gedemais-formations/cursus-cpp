#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int arg c, char **argv)
{
char mot[] = "Salut les terriens !";
char *mot2 = NULL;
 
    printf("%s", ft_strdup(mot, &mot2));
 
    free(mot2); //Librer la mémoire ici et non pas dans fonction car sinon pas de renvoie.
 
    mot2 = NULL
}

char *ft_strdup(char *s, char *charset)
{
	longueur_chaine = 0
	if(str==NULL || charset ==NULL){
		return NULL ;
	}
	longueur_chaine = strlen(s);
	*charset = (char *)malloc(sizeof(char)*(longueur_chaine+1));

	int i = 0 ;
	while (s[i]!= '\0')
	{
		(*tab)[i]= s[i];
		i++ ;
	}
	(*charset)[i] = '\0' ;

	return *charset ;
}
