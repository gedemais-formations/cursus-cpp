#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * ft_split(char * s, char * charset) {
	int i, j, len;
	char * next, * str;
	while((next = strchr(s, 'e')) != NULL) {
		*next = '\0';
		len = next - s; //Longueur de la chaîne coupée
		str = (char *)malloc(len);
		strcpy(str, s);
		printf("\n%s", str);
		s = next + 1;
		free(str);
	}
	if(next == NULL) {
		strcpy(str, s);
		printf("%s", str);
	}
	return str;
}

int main(int argc, char ** argv) {
	int i;
	char delim[] = "e ", ** tab, * str;
	tab = (char **)malloc(sizeof(char *) * (argc - 1));
	for(i = 1; i < argc; i++) {
		str = ft_split(argv[i], delim);
		//TODO
	}
	return 0;
}
