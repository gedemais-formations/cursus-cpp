#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_prio(int, char **, int *, int);

int main(int argc, char ** argv) {
	int array_continue[argc];
	int result = 0, i, j = 0, k, number = 0;
	char invalid_operator = -1;
	for(i = 0; i < argc; i++) array_continue[i] = 0;
	for(i = 1; i < argc; i++) {
		if(strcmp(argv[i], "x") == 0) {
			result += atoi(argv[i - 1]) * atoi(argv[i + 1]);
			number++;
			array_continue[j++] = i - 1;
			array_continue[j++] = i;
			array_continue[j++] = i + 1;
		}
		else if(strcmp(argv[i], "/") == 0) {
			result += atoi(argv[i - 1]) / atoi(argv[i + 1]);
			number++;
			array_continue[j++] = i - 1;
			array_continue[j++] = i;
			array_continue[j++] = i + 1;
		}
		/*else if(!atoi(argv[i])) {
			puts("error : invalid operator");
			invalid_operator = 1;
			break;
		}*/
	}
	for(i = 1; i < argc; i++) {
		//for(k = 0; k < argc; k++) if(array_continue[k] == i && i < argc - 1) i++;
		if(strcmp(argv[i], "+") == 0) {
			result += check_prio(argc, argv, array_continue, i);
			number++;
		}
		else if(strcmp(argv[i], "-") == 0) {
			result += check_prio(argc, argv, array_continue, i);
			number++;
		}
		/*else if(!atoi(argv[i])) {
			puts("error : invalid operator");
			invalid_operator = 1;
			break;
		}*/
	}
	if((number % 2 != 0 || number == 0) && !invalid_operator) puts("error : invalid number of arguments");
	else printf("result %d", result);
}

int check_prio(int argc, char ** argv, int * array_continue, int i) {
	int result = 0, k;
	char ok;
	ok = -1;
	for(k = 0; k < argc; k++) {
		if(array_continue[k] == i - 1) {
			result += atoi(argv[i + 1]);
			ok = 1;
			break;
		}
		else if(array_continue[k] == i + 1) {
			result += atoi(argv[i - 1]);
			ok = 1;
			break;
		}
	}
	if(!ok) result += atoi(argv[i - 1]) + atoi(argv[i + 1]);
	return result;
}
