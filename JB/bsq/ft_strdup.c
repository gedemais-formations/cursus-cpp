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

int char_charset(char elt_x,char *charset)

	int charset_size = strlen(charset);
	if (charset[0] != '\0'){
		for (int x = 0; x < charset_size; x++){
			if (elt_x == charset[x]){
				return(0);
			}
		}
		return(1);
	}
	else {
		return(2);
	}
}


// fonction qui va comparer chaque char d'un elt fourni aux éléments de charset
// et qui va calculer la longueur de la longueur de la fraction depuis le debut de elt
// jusqu'à ce char
char *ft_strdup (char *elt, char *charset){

	// initialisation d'un compteur qui va définir la l'espace mémoire à allouer
	// pour copier la première fraction de elt jusqu'à un charset
	// doit être au moins de 1
	int cut_elt_length = 1;
	
	int elt_size = strlen(elt);
	for (int i = 0; i < elt_size; i++){
		char_x = elt[i];
		if ((char_charset(elt_x, charset) == 1{
			printf("No char of charset found in elt \n");
			return(NULL);
		}
		else if	(char_charset(char_x, charset) == 2){
			printf("There is no char in charset \n");
			return(NULL);
		}
		else if (char_charset(char_x, charset) == 0){
			cut_elt_length += i;
		}
	}
	if(cut_elt_length == 1){
		printf("The first char of elt is in charset \n");
		return(NULL);
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
		return(NULL);
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
