#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv){
	int a;
	int b;
	char *o;
	if(sizeof(*argv) < 3 || atoi(argv[1]) == 0 || atoi(argv[3]) == 0){
		printf("error : invalid number of arguments or invalid arguments\n");
	}
	else{
		a = atoi(argv[1]);
		o = argv[2];
		b = atoi(argv[3]);
		if(strcmp(o, "+") == 0){
			printf("%d", a+b);
			printf("\n");
		}
		else{
			if(strcmp(o, "-") == 0){
				printf("%d", a-b);
				printf("\n");
			}
			else{
				if(strcmp(o, "*") == 0){
					printf("%d", a*b);
					printf("\n");
				}
				else{
					printf("%d", a/b);
					printf("\n");
				}
			}
		}
	}
	return 0;
}
