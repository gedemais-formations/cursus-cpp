#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
		float nombre1 = atof(argv[1]);
		float nombre2 = atof(argv[3]);
		char * operateur = argv[2];
		float resultat;

		if (argc != 4)
		{
			printf("error: invalid number of argument \n");
			return (0);
		}
		else
		{
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

