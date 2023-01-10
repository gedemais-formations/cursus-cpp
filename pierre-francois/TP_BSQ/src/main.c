#include "../include/main.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void function_free(map_t *map)
{
	for(int i=0; map->map_full[i] != NULL; i++)
		{
			free(map->map_full[i]);
		}
	free(map->map_full);
}

int bsq(int argc ,char **argv)
{
	int i = 1 ;
	map_t map;
	memset(&map, 0, sizeof(map_t));
	while(i<argc)
	{
		if(map.map_full)
		{
			function_free(&map);
			memset(&map, 0, sizeof(map_t));
		}
		if(get_map(argv[i],&map)!=0)
		{
			continue;
		}
		i++;
	}
	function_free(&map);
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
