#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_char(char c, const char *str){
	int boolean;
	int length;
	boolean = 0;
	length = 0;
	while(str[length]!='\0' && boolean == 0){
		length ++;
		if(c == str[length]){
			boolean = 1;
		}
	}
	return (boolean);
}

char *ft_strdup(const char *s, const char *charset){
	int length;
	char *str;

	length = 0;
	while(s[length]!='\0' && check_char(s[length], charset) == 0){
		length ++;
	}

	if (!(str = (char*)malloc(sizeof(*str) * (length + 1)))){
    	return(NULL);
  	}

  	length = 0;
  	while(s[length]!='\0' && check_char(s[length], charset) == 0){
		str[length] = s[length];
		length++;
	}
	str[length] = '\0';
	return str;
}

int main(int argc, char const *argv[]){
	char *str = NULL;
	if(argc != 3){
		printf("Error, need only 2 args");
		return (-1);
	} else {
		str = ft_strdup(argv[1], argv[2]);
		printf("%s \n", str);
	}
	if(str){
		free(str);
	}
	return 0;
}