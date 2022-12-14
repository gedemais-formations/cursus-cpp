#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv){
	int c;
	int i = 3;
	if(sizeof(*argv) <= 4){
		printf("error : invalid number of arguments\n");
	}
	else{
		c=atoi(argv[i]);
		while(i <= sizeof(*argv));{
			if(strcmp(argv[i-1], "+") == 0){
				c+=atoi(argv[i]);
			}
			else{
				if(strcmp(argv[i-1], "-") == 0){
					c-=atoi(argv[i]);
				}
				else{
					if(strcmp(argv[i-1], "*") == 0){
						c*=atoi(argv[i]);
					}
					else{
						if(strcmp(argv[i-1], "/") == 0){
							c/=atoi(argv[i]);
						}
						else{
							printf("Error: invalid operator.\n");
							return 0;
						}
					}
				}
			}
			i+=2;
		}
		printf("%d", c);
	}
	return 0;
}
