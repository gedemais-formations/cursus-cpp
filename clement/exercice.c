#include <stdio.h>
#include <string.h>

int main (int argc, char **argv){
	int a = 5;
	int b = 3;
	char *o = "-";
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
				if(strcmp(o, "/") == 0){
					printf("%d", a/b);
					printf("\n");
				}
				else{
					printf("Error: invalid operator.\n");
				}
			}
		}
	}
	return 0;
}
