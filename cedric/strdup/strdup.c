#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_strdup(const char *s, char charset){
	int length;
	char *str;

	length = 0;
	while(s[length]!='\0' && s[length]!=charset){
		length ++;
	}

	if (!(str = (char*)malloc(sizeof(*str) * (length + 1)))){
    	return(NULL);
  	}

  	length = 0;
  	while(s[length]!='\0' && s[length]!=charset){
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
		str = ft_strdup(argv[1], argv[2][0]);
		printf("%s \n", str);
	}
	if(str){
		free(str);
	}
	return 0;
}