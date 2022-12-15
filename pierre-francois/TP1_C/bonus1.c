#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int nombreArguments = argc;
	float resultat = atof(argv[1]);

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
