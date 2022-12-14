#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int nombreArguments = argc;

	for (int i = 1; i <= nombreArgument-2; i = i+2)
	{
		float nombre1 = atof(argv[i]);
		float nombre2 = atof(argv[i+2]);
		char * operateur = argv[i+1];
		float resultat;

			if (strcmp(operateur,"+") == 0)
			{
				resultat = nombre1 + nombre2;
				printf("%f \n", resultat);	
			}
			else if (strcmp(operateur,"-") == 0)
			{
				resultat = nombre1 - nombre2;
				printf("%f \n", resultat);
			}
			else if (strcmp(operateur,"*") == 0)
			{
				resultat = nombre1 * nombre2;
				printf ("%f \n", resultat);
			}
			else if (strcmp(operateur,"/") == 0)
			{
				resultat = nombre1 / nombre2;
				printf ("%f \n", resultat);
			}
			else 	
			{
				printf("error: invalid operator \n");
			}
		}
	return (0);
}

