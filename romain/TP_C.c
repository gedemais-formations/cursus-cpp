#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void	calculatrice(int a, int b, char *c)
{
	float	r;

	if(strcmp(c,"+")==0)
	{r= a+b ;
	}
	else if (strcmp(c,"-")==0)
	{r =a-b;
	}
	else if (strcmp(c,"/")==0)
	{r  = a/b ;
	}
	else if (strcmp(c,"*")==0)
	{
		r = a*b ;
	}
	else{
		printf("Erreur d'opérateur ");
	}
	printf("%f\n",r);
}

int		get_user_input(int argc, char **argv, int *a, int *b, char **c)
{
	if (argc != 4)
	{
		printf("Nombre de parametres invalide.\n");
		return (1);
	}
	*a = atoi(argv[1]);
	*b = atoi(argv[3]);
	*c = argv[2];

	return (0);
}

int		main (int argc, char **argv)
{
	//int calculatrice (){
	int a, b;
	char * c;

	get_user_input(argc, argv, &a, &b, &c);
	calculatrice(a, b, c);
//printf("écrire un premier numéro : \n");
//scanf("%d",&a);
//printf("écrire votre deuxième numéro : \n");
//scanf("%d",&b);
//printf("type d'opération : \n");
//scanf ("%s",c);


	return (0);
}
