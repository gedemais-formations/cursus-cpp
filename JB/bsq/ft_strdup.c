// fonction qui va copier le premier "éléments" d'une chaine de caractère jusqu'a un caractère de séparation défini 
// char *ft_strdup(cahr *s, char *charset) >> *s étant le fichier *charset, le(s) caractère(s) de séparation
// exp de *charset: " e!b" >> le caractère de séparation est " " ou "e" ou "!" ou "b"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
// pour utiliser READ
#include<unistd.h>


int main(int argc, char **argv){
	// vérification qu'il y a uniquement 2 arguments dans la fonction, la chaine de caractère et le(s) charset
	// dans un premier temps il n'y aura qu'un seul char défini dans charset (1)
	if (argc != 3){
		print("Invalid number of arguments for ft_strdup! \n");
		return (false);
	}

	// initialisation d'un compteur qui va définir la taille du premier élément pour définir l'espace mémoire à allouer
	int elt_length = 1;
	// initialisation d'un entier qui permettra de parcourir chaque caractère de la chaine 1 à 1
	int i = 0;
	char elt_char = argv[1][i];
	
	//(1)
	while (elt_char != arg[2]){
		if (elt_char == "\0"){
			print("No charset found");
			return (false);	
		}
		else {
		i++;
		elt_length++;
		}
		return (true);
	}
	
	// allocation d'un espace mémoire de taille elt_length avec malloc
	// récupération de l'adresse de cet espace en définissant la variable elt_mem
	void elt_mem = void *malloc(size_t elt_length);
	
	// copie les elt_length-1 premier char dans l'espace alloué
	ssize_t read(argv[1], *elt_mem, (elt_length - 1));
	
	// vérification que cela à bien ecrit à l'adresse dédié
	printf("%c\n", *elt_mem);
}

