#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_char(char c, const char *charset){
	int boolean;
	int length;
	boolean = 0;
	length = 0;
	while(charset[length]!='\0' && boolean == 0){
		length ++;
		if(c == charset[length]){
			boolean = 1;
		}
	}
	return (boolean);
}

int count_substring(const char *str, const char *charset){
	int i;
	int count;
	i = 0;

	while(str[i] != '\0'){
		if(check_char(str[i], charset) == 1){
			count++;
		}
	}
	return (count);
}

int count_length(const char *str, const char *charset, int index){
	int length;
	length = index;
	while(str[length]!='\0' && check_char(str[length], charset) == 0){
		length ++;
	}
	return (length - index);
}

char **ft_split(const char *s, const char *charset){
	int i;
	int k;
	int length;
	int nb_substring;
	char **str = NULL;
	i=0;
	nb_substring = count_substring(s, charset);
	if (!(str[0] = (char*)malloc(sizeof(*str) * (nb_substring + 1)))){
    	return(NULL);
  	}
  	str[nb_substring] = '\0';
  	for(int j = 0; j < nb_substring; j++){
  		length = count_length(str[j], charset, i);
  		k = 0;
  		while(i < length){
  			str[j][k] = s[i];
  			i++;
  			k++;
  		}
  		printf("%d\n", j);
  	}
  	return (str);
}


int main(int argc, char const *argv[]){
	char **str = NULL;
	if(argc != 3){
		printf("Error, need only 2 args");
		return (-1);
	} else {
		str = ft_split(argv[1], argv[2]);
		//printf("%s \n", str);
	}
	if(str){
		free(str);
	}
	return 0;
}