#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
//On récupère la longueur du tableau argv
	int nombreArguments = argc;
//On initialise la valeur du résultat avec le premier nombre rentré
	float resultat = atof(argv[1]);

/*On utilise une boucle for dont le corps est semblable à la fonction de
  base. On initialise la boucle for avec le second nombre présent dans 
  les arguments */

	for (int i = 3; i <= nombreArgument-2; i = i+2)
	{
		float nombre = atof(argv[i]);
		char * operateur = argv[i-1];

			if (strcmp(operateur,"+") == 0)
			{
				resultat = resultat + nombre;	
			}
			else if (strcmp(operateur,"-") == 0)
			{
				resultat = resultat - nombre;
			}
			else if (strcmp(operateur,"*") == 0)
			{
				resultat = resultat * nombre;
			}
			else if (strcmp(operateur,"/") == 0)
			{
				resultat = resultat / nombre;
			}
			else 	
			{
				printf("error: invalid operator \n");
			}
		}
	printf ("%f \n", resultat)
	return (0);
}
