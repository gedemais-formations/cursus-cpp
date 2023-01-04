// fonction qui va copier le premier "éléments" d'une chaine de caractère jusqu'a un caractère de séparation défini 
// char *ft_strdup(cahr *s, char *charset) >> *s étant le fichier *charset, le(s) caractère(s) de séparation
// exp de *charset: " e!b" >> le caractère de séparation est " " ou "e" ou "!" ou "b"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// pour utiliser READ
#include<unistd.h>
// pour utiliser OPEN
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
// pour utilisert ASSERT
#include<assert.h>

int char_charset(char char_x,char *charset)

	int charset_size = strlen(charset);	
	for (int x = 0; x < charset_size; x++){
		if (char_x == charset[x]){
			return(1);
		}
	}
	return(0);
}

char *ft_strdup (char *elt, char *charset){

	// initialisation d'un compteur qui va définir la taille du premier élément pour définir l'espace mémoire à allouer
	int elt_length = 1;
	// initialisation d'un entier qui permettra de parcourir chaque caractère de la chaine 1 à 1

	for (int i = 0; i < strlen(elt); i++){
		char_x = elt[i];
		if (char_charset(char_x, charset) == 1){
		elt_length++;
		}
		else if (char_charset(char_x, charset) == 0){
			printf("No %c found in elt \n", charset);
			return(false);
		}
		
	return(elt_length);
	}

	// récupération du file descriptor de elt grace à la fct OPEN
	int fd_elt = open(elt, O_RDONLY);
		if (fd_elt == -1){
		printf("No file descriptor for elt \n");
		return(false);
		}

	// allocation d'un espace mémoire de taille elt_length avec malloc
	// récupération de l'adresse de cet espace en définissant la variable elt_mem
	char * elt_mem = (char *) malloc(elt_length);
	if (elt_mem == NULL){
	printf("No more memory available");
	return(false);
	}

	// copie les elt_length-1 premier char dans l'espace alloué avec read
	// et stocké dans rd_elt_mem le nombre d'octet lus
	rd_elt_mem = read(fd_elt, elt_mem, (elt_length - 1));
	
	// ajout de \O en position rd_elt_mem (fin de chaine) soit elt_length
	// normalement
	// > pour signifier la fin de la chaine de caractère (cc)
	// caractère obligatoire sinon continuera à lire après la fin de la cc
	elt_mem[rd_elt_mem] = '\0';

	// vérification que cela à bien ecrit à l'adresse dédié
	printf("%s\n", elt_mem);

	// libération de l'espace mémoire
	free(elt_mem);
}

int main(int argc, char **argv){
	(void)argc;
	(void)argv;
	return(0);
}
