// code_calcu_C.c

// Inclusions des bibliothèques nécessaires au fonctionnement du programme

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

int main(int argc, char * argv[])
{
	// initialisation des variables
	int a = atoi(argv[1]);
	int c = atoi(argv[3]);
	// transforme une chaine de caractère en un entier
	char b = argv[2][0];
	// selectione le 1er caractère de la chaine de caractère du 3eme argument de argv
	int length = strlen(argv[2]); 
	double result;
	
	if (argc != 4)
	{
		printf("invalid number of arguments\n");
	}

	if ( length != 1 ) 
	{
		printf("invalid operator \n");
	}
	else if (b == '+')
	{
		result=a + c;
		printf("Result = %f\n", result);
	}
	else if (b == '-')
	{
		result = a - c;
		printf("Result = %f\n", result);
	}
	else if (b == '*')
	{
		result = a * c;
		printf("Result = %f\n", result);
	}
	else if (b == '/')
	{
		result = a / c;
		printf("Result = %f\n", result);
	}
	else if (b == '%')
	{	result = a % c;
		printf("Result = %f\n", result);
	}
}	
	// voir strcmp
	// quand on compart des charactrère simple utiliser tjs des ' simple pas des double "
	
