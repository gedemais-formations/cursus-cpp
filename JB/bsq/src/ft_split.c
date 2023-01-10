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

int char_charset(char string_char_x,char *charset);
char *ft_strdup (char *string_char, char *charset);


int recup_nb_elts(char *string_char, char *charset){
	
	// récupération du nombre d'éléments dans la suite de caractères
	
	int string_char_size = strlen(string_char);
	int nb_elts = 1;

	for (int i = 0; i < string_char_size; i++){
		// char string_char_x = string_char[i];
		if (i < (string_char_size - 1) && (char_charset(string_char[i], charset) == 0) && (char_charset(string_char[i + 1], charset) == 1)){
			nb_elts++;
		}
	}
	return(nb_elts);
	
}

char **ft_split (char *string_char, char *charset){
	
	int nb_elts = 1;
	int string_char_size = strlen(string_char);

	for (int i = 0; i < string_char_size - 1; i++){
		if (i < string_char_size && char_charset(string_char[i], charset) == 0 && char_charset(string_char[i + 1], charset) == 1){
		nb_elts++;
		}
	}
	
	char **elts_string = (char**) malloc(sizeof(char*) * (nb_elts + 1));
	if (elts_string == NULL){
		return(NULL);
	}	

	int j = 0;

	elts_string[0] = ft_strdup(string_char,charset);
	if(elts_string[0] ==NULL){
		printf("Memory allocation trouble");
		return(NULL);
	}
	
	
	for (int k = 0; k < string_char_size; k++){
		if ((k < (string_char_size - 1)) && (char_charset(string_char[k], charset) == 0) && (char_charset(string_char[k + 1], charset) == 1)){
			j++;
			if (j < nb_elts){
				elts_string[j] = ft_strdup(&string_char[k + 1], charset);
					if(elts_string[j] == NULL){
						printf("Memory allocation trouble");
						return(NULL);
					}
			}
			else {
				printf("There is more elts found than previously calculated");
				return(NULL);
			}
		}
	}
	elts_string[j+1] = NULL;
	return(elts_string);
}

/*
int main(){
	

	char *string_char = "Time_to_test thy code";
	char *charset = " y";
	char **result_elts_string = ft_split(string_char, charset);

	for (int l = 0; result_elts_string[l] != NULL; l++){ 
		printf("%s \n", result_elts_string[l]);
		free(result_elts_string[l]);
	}
	free(result_elts_string);
	return(0);
}
*/
// pour la compilation il me faudra ajouter ft_strdup.c dans le gcc avec le ft_split.c
