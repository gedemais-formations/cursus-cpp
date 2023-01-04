#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int size, k;

char ** ft_split(char * s, char * charset) {
	int i, len, len_ch;
	char * next, * str, ** tab;
	len_ch = strlen(charset);
	tab = (char **)malloc(sizeof(char *) * size);
	k = 0;
	if(!tab) {
		puts(strerror(errno));
		return NULL;
	}
	while((next = strpbrk(s, charset)) != NULL) {
		*next = '\0';
		len = next - s; //Longueur de la chaîne coupée
		str = (char *)malloc(len);
		if(!str) {
			puts(strerror(errno));
			return NULL;
		}
		strcpy(str, s);
		tab[k] = (char *)malloc(len);
		if(!tab[k]) {
			puts(strerror(errno));
			return NULL;
		}
		strcpy(tab[k], str);
		k++;
		tab = (char **)realloc(tab, sizeof(char *) * k);
		if(!tab) {
			puts(strerror(errno));
			return NULL;
		}
		//printf("\n%s", str);
		s = next + 1;
		free(str);
	}
	if(next == NULL) {
		strcpy(str, s);
		tab[k] = (char *)malloc(len);
		if(!tab[k]) {
			puts(strerror(errno));
			return NULL;
		}
		strcpy(tab[k], str);
		k++;
		tab = (char **)realloc(tab, sizeof(char *) * k);
		if(!tab) {
			puts(strerror(errno));
			return NULL;
		}
		//printf("%s", str);
	}
	for(i = 0; i < k; i++) printf("\n%s", tab[i]);
	return tab;
}

int main(int argc, char ** argv) {
	int i, j;
	char delim[] = "eo", ** tab;
	size = argc - 1;
	for(i = 1; i < argc; i++) {
		tab = ft_split(argv[i], delim);
		for(j = 0; j < k; j++) free(tab[j]);
		free(tab);
	}
	return 0;
}
