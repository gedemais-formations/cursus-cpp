#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_char(char c, const char *charset){
	int boolean;
	int length;
	boolean = 0;
	for(length = 0; charset[length]!='\0' && boolean == 0; length ++){
		if(c == charset[length]){
			boolean = 1;
		}
	}
	return (boolean);
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
	int length;
	for(length = index; str[length] != '\0' && check_char(str[length], charset) == 0; length ++){}
	return (length - index + 1);
}

int max_length(const char *str, const char *charset){
	int max_length;
	int length;
	max_length = 0;
	length = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(check_char(str[i], charset) == 0){
			if(max_length < length){
				max_length = length;
				printf("max_length = %d", max_length);
			}
			length = 0;
		}
	}
	return(max_length);
}


char **ft_split(const char *s, const char *charset){
	int k;
	int length;
	int nb_substring;
	int index;
	char **str = NULL;
	nb_substring = count_substring(s, charset);
	printf("nb_substring value : %d\n", nb_substring);
	if(!(str = (char**) malloc(sizeof(char*) * (nb_substring + 1)))){
    	return(NULL);
  	}

  	if(!(str[nb_substring] = (char*) malloc(sizeof(char) * 1))){
  		return(NULL);
  	}
  	str[nb_substring][0] = '\0';

  	index = 0;
  	for(int j = 0; j < nb_substring; j++){
  		printf("j value : %d\n", j);
  		fflush(stdout);
  		length = count_length(str[j], charset, index);
  		index = index + length + 1;
  		if(!(str[j] = (char*) malloc(sizeof(char) * length + 1))){
  			return(NULL);
  		}
  		str[j][length] = '\0';

  		k = 0;
  		for(int i = 0; i < length; i++){
  			str[j][k] = s[i];
  			k++;
  		}
  		//printf("%d\n", j);
  	}
  	return (str);
}

int main(int argc, char const *argv[]){
	char **str = NULL;
	int row;
	if(argc != 3){
		printf("Error, need only 2 args");
		return (-1);
	} else {
		str = ft_split(argv[1], argv[2]);
	}
	for(row = 0; str[row][0] != '\0'; row++){}
	row ++; //Count the last row

	if(str){
		for(int i = 0; i < row; i++){
			if(i != row){
				printf("%s \n", str[i]);
			}
			free(str[i]);
			//printf("Free aray str[%d]\n", i);
		}
		free(str);
	}
	return 0;
}