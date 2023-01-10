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

int char_charset(char string_char_x,char *charset){
	int charset_size = strlen(charset);
	for (int x = 0; x < charset_size; x++){
		if (string_char_x == charset[x]){
			return(0);
		}
	}
	return(1);
}


// fonction qui va comparer chaque char d'un elt fourni aux éléments de charset
// et qui va calculer la longueur de la longueur de la fraction depuis le debut de elt
// jusqu'à ce char
char *ft_strdup (char *string_char, char *charset){
	
	int string_char_size = strlen(string_char);
	int charset_size = strlen(charset);

	if (string_char_size == 0){
		printf("No char in string_char \n");
		return(NULL);
	}
	else if (charset_size == 0){
		printf("No char in charset \n");
		return(NULL);
	}

	// initialisation d'un compteur qui va définir la l'espace mémoire à allouer
	// pour copier la première fraction de elt jusqu'à un charset
	// doit être au moins de 1
	int elt_length = 1;

	for (int i = 0; i < string_char_size; i++){
		char string_char_x = string_char[i];
		if (char_charset(string_char_x, charset) == 0){
			break;
		}
		else {
			elt_length++;
		}
	}
	
	/*
	 * if (elt_length == string_char_size){
		printf("No char of charset found in string_char \n");
		// return(NULL);	
	}
	*/

		// allocation d'un espace mémoire de taille elt_length avec malloc
	// récupération de l'adresse de cet espace en définissant la variable elt_mem
	
	char * elt_mem = NULL;
	elt_mem = (char *) malloc(sizeof(char) * elt_length);
	
	if(elt_length == 1){
		elt_mem[0] = '\0';
		printf("The first char of string_char is in charset \n");
		return(NULL);
	}	
	
	if (elt_mem == NULL){
		printf("No more memory available");
		return(NULL);
	}

	for (int j = 0; j < elt_length - 1; j++){
		elt_mem[j] = string_char[j];
	}
	elt_mem[elt_length - 1] = '\0';
	
	// printf("%s\n", elt_mem);

	return(elt_mem);
}

/*
 * int main(){
	char *result_elt_mem = ft_strdup("Time_to_test thy code", " y");
	printf("%s \n", result_elt_mem);

	return(0);
}
*/
