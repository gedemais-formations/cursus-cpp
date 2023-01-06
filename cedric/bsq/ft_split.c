#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_char(char c, const char *charset){
	int length;
	for(length = 0; charset[length]!='\0'; length ++){
		if(c == charset[length]){
			return(1);
		}
	}
	return (0);
}

int count_substring(const char *str, const char *charset){
	int count;
	for(int i = 0; str[i] != '\0'; i++){
		if(check_char(str[i], charset) == 1){
			count++;
		}
	}
	count ++;
	return (count);
}

int count_length(const char *str, const char *charset, int index){
	int length;	for(length = index; (str[length] != '\0') 
		&& (check_char(str[length], charset) == 0); length ++){}
	return (length - index);
}


char **ft_split(const char *s, const char *charset){
	int k;
	int length;
	int nb_substring;
	int index;
	char **str = NULL;
	nb_substring = count_substring(s, charset);
	if(!(str = (char**) malloc(sizeof(char*) * (nb_substring + 1)))){
    	printf("Error malloc creation\n");
    	return(NULL);
  	}

  	str[nb_substring] = NULL;

  	index = 0;
  	for(int j = 0; j < nb_substring; j++){
  		length = count_length(s, charset, index);

  		if(!(str[j] = (char*) malloc(sizeof(char) * (length + 1)))){
  			printf("Error malloc creation, free previous malloc\n");
  			for(int i = 0; i < j; i++){
  				if(str[i]){
  					free(str[i]);
  				}
  				if(str){
  					free(str);
  				}
  			}
  			return(NULL);
  		}

  		str[j][length] = '\0';

  		k = 0;
  		for(int i = 0; i < length && s[index+k] != '\0'; i++){
  			str[j][k] = s[index+k];
  			k++;
  		}
  		index = index + length + 1;
  	}
  	return (str);
}