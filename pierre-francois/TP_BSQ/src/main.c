#include "../include/main.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int bsq(int argc ,char **argv)
{
	int i = 1 ;
	while(i<argc)
	{
		if(get_map(argv[i]) ==NULL)
		{
			return 1 ;
		}
		i++;
	}
	return 0 ;	
}


int main(int argc, char **argv)
{
	if(bsq(argc,argv)!=0)
	{
		return 1 ;
	}

	return 0;
}
