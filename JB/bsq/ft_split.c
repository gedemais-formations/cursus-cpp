// fonction qui va copier tous les "éléments" d'une chaine de caractère 
// séparé par un/des caractère(s) de séparation défini(s) 
// char **ft_split(cahr *s, char *charset) >> *s étant la chaine de caractère *charset, le(s) caractère(s) de séparation

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


char **ft_split (char *string_char, char *charset){
	
	// récupération du nombre d'éléments dans la suite de caractères
	
	int string_char_size = strlen(string_char);
	int nb_elts = 0;

	for (int i = 0; i < string_char_size; i++){
		char string_char_x = string_char[i];
		if (i < (string_shar_size - 1) && (char_charset(string_char[i], charset) == 1) && (char_charset(string_char[i + 1] == 0))){
			nb_elts++;
		}
	}
	
	char **elts_string = (char**) malloc((sizeof(char*) * nb_elts));
	
	int j = 0;
	for (int k = 0, k < string_char_size; k++){
		if (k < (string_shar_size - 1) && (char_charset(string_char[k], charset) == 1) && (char_charset(string_char[k + 1] == 0))){
			if (j < nb_elts){
				*elts_string[j] = ft_strdup(&elt[k], *charset);
				j++;
			}
			else{
				printf("There is more elts found than previously calculated");
				return(1);
			}
		}
	}	
	return(elts_string);
}

	char **elt_word;

}


