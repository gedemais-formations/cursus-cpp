#include <stdio.h>

int main (int argc, char **argv){
	int a = 5;
	int b = 3;
	char o='a';
	switch(o){
		case '+':
			printf("%d", a+b);
			printf("\n");
			break;
		case '-':
			printf("%d", a-b);
			printf("\n");
			break;
		case '*':
			printf("%d", a*b);
			printf("\n");
			break;
		case '/':
			printf("%d", a/b);
			printf("\n");
			break;
		default:
			printf("Error: invalid operator.\n");
			break;
	}
	return 0;
}
