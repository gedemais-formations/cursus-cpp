#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <string.h>
//#define malloc(x) NULL
#define BUFFER_SIZE 128

void parser(char str);
void error_handler(unsigned char code);

int start(int argc, char **argv){
	(void) argv;

	char buf[BUFFER_SIZE];
	char *ptr;
	int size;

	if(argc == 1){
		ptr = (char *) malloc(BUFFER_SIZE);
			
		if(ptr == NULL){
			return(ERROR_MEM);
		}
		int i = 0;
		// Write the stdin buffed data
		do{
			size = read(0, buf, BUFFER_SIZE);
				
			if(size > 0){
				ptr = (char *) realloc(ptr, BUFFER_SIZE*(i+1));		
				memcpy(&ptr[BUFFER_SIZE*i], buf, size);						
			}
			i++;

		}while(size == BUFFER_SIZE);
		
		write(1, ptr, strlen(ptr));
	}
	
	return (0);
}

int main(int argc, char **argv){
	int code;

	if ((code = start(argc, argv)) != ERROR_NONE)
	{
		error_handler(code);
		return (code); // errors defined in error.h
	}
}
