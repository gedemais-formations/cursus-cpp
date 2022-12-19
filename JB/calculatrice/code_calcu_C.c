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
	int length = strlen(char argv[2]); 
	double result;

	if (length != 1) || ('b' != '+') || ('b' != '-') || ('b' != '*') || ('b' != '/') || ('b' != '%') 
	{
		printf("invalid operator");
	}
	else if ('b' == '+')
	{
		result=a + c;
		printf(result);
	}
	else if ('b' == '-')
	{
		result = a - c;
		printf(result)
	}
	else if ('b' == '*')
	{
		result = a * c
		printf(result)
	}
	else if ('b' == '/')
	{
		result = a / c
		printf(result)
	}
	else if ('b' == '%') 
	{
		result = a % c
		printf(result)
	}
	else 
	{
		printf("invalid number of arguments")
	} 
}	
	// voir strcmp
	// quand on compart des charactrère simple utiliser tjs des ' simple pas des double "
	
