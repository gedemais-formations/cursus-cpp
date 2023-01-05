#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
	char *s;
	s=malloc(10);
	printf("%p\n",s);
	
	s = strcpy(s, "Bonjour !");

	printf("%s\n", &s[3]);

	return 0;
}
