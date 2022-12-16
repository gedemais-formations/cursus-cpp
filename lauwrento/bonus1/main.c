#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int i = 1;
	char *concat;

	while(i < argc){
        //printf("%s\n", argv[i]);
		strcat(concat, argv[i]);
		i++;
	}

	printf("%s\n", concat);

	return 0;
}
