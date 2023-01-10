#include "main.h"

int main(int argc, char **argv){
	char *file_name;
	for(int i = 1; i < argc; i ++){
		file_name = argv[i];
		bsq(file_name);
		//TODO : Protect previous line
	}
	return(0);
}