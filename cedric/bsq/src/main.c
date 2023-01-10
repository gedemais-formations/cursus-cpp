#include "main.h"

int main(int argc, char const **argv){
	for(int i = 0; i < argc; i ++){
		bsq(argv[i]);
		//TODO : Protect previous line
	}
	return(0);
}