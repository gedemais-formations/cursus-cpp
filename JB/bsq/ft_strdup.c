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

int main(int argc, char **argv){
	// vérification qu'il y a uniquement 2 arguments dans la fonction, la chaine de caractère et le(s) charset
	// dans un premier temps il n'y aura qu'un seul char défini dans charset (1)
	if (argc != 3){
		printf("Invalid number of arguments for ft_strdup! \n");
		return(false);
	}

	// initialisation d'un compteur qui va définir la taille du premier élément pour définir l'espace mémoire à allouer
	int elt_length = 1;
	// initialisation d'un entier qui permettra de parcourir chaque caractère de la chaine 1 à 1
	int i = 0;
	char elt_char = argv[1][i];
	
	//(1)
	while (elt_char != *argv[2]){
		if (elt_char == '\0'){
			printf("No charset found \n");
			return(false);	
		}
		else {
		i++;
		elt_length++;
		}
		return(true);
	}
	
	// récupération du file descriptor de argv[1] grace à la fct OPEN
	int fd_argv1 = open(argv[1], O_RDONLY);
		if (fd_argv1 == -1){
		printf("No file descriptor for argv[1] \n");
		return(false);
		}

	// allocation d'un espace mémoire de taille elt_length avec malloc
	// récupération de l'adresse de cet espace en définissant la variable elt_mem
	char * elt_mem = (char *) malloc(elt_length);
	
	// copie les elt_length-1 premier char dans l'espace alloué
	read(fd_argv1, elt_mem, (elt_length - 1));
	
	// vérification que cela à bien ecrit à l'adresse dédié
	printf("%s\n", elt_mem);

	// libération de l'espace mémoire
	free(elt_mem);
}

