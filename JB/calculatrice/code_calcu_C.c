// code_calcu_C.c

/*
// Inclusions des bibliothèques nécessaires au fonctionnement du programme

// void ne renvoie pas de résultats
void saisie (int a, char ope, int b)
// la fonction invite l'utilisateur à entrer les données requise
{
	printf("Veuillez saisir votre opération simple (sous la forme [a ope b]: ");
	fflush (stdout);		// pas sur que ce soit nécessaire de synchroniser les buffers
	scanf( "%d %c %d" , &a, &ope, &b );
	return; }
*/

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main(int argc, char * argv[])
{
	// initialisation des variables
	int a = atoi(argv[1]);
	int c = atoi(argv[3]);
	// transforme une chaine de caractère en un entier
	char b = argv[2][0];
	// selectione le 1 caractère de la chaine de caractère du 2eme argument de argv
	double result;

	if 'b' != '+' || '-' || '*' || '/' || '%' {
		printf("invalid operator")
	}
	else { 

	// trouve ce que vaut ope et intégrer à result
	// strcmp
	// quand on compart des charactrère simple utiliser tjs des ' simple pas des double "
	result = a 'b' c;
	printf( "Le résultat est : \n", result); }
