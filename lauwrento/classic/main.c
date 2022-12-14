#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Main function for calc

int main(int argc, char **argv)
{
	if(argc != 4){
		printf("error : invalid number of arguments\n");
		return (2);
	}

	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[3]);

	if(argv[2][0] == '+'){
		int res = num1 + num2;
		printf("%d\n", res);
	}else if(!strcmp(argv[2], "-")){
		int res = num1 - num2;
		printf("%d\n", res);
	}else if(!strcmp(argv[2], "*")){
		int res = num1 * num2;
		printf("%d\n", res);
	}else if(!strcmp(argv[2], "/")){
		int res = num1 / num2;
		printf("%d\n", res);
	}else {
		printf("error : invalid operator\n");
		return (3);
	}

	return(0);
}
