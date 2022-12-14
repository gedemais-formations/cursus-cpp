#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, char **argv)
{
	//int calculatrice (){
int a = atoi(argv[1]) ;
int b = atoi(argv[3]) ;
char * c = argv[2];
int r ;
//printf("écrire un premier numéro : \n");
//scanf("%d",&a);
//printf("écrire votre deuxième numéro : \n");
//scanf("%d",&b);
//printf("type d'opération : \n");
//scanf ("%s",c);

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
printf("%d \n",r);
return 0 ;
}
//}
