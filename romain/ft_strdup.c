#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *ft_strdup(char *s, char *charset)
{
 int longueur = 0;
    int i = 0;
char *test = 0 ; 
   longueur = strlen(s);
    test = malloc(sizeof(char)*longueur);

    while (s[i]==*test)
    {
        (charset)[i] = s[i];
        i++;
    }
    (charset)[i] = '\0';
    return charset;
}

int main ()
{
	ft_strdup("Projet BLUE LOCK","o");
	return 0 ;
}
