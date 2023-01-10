#include "../include/main.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>


void ft_free(map_t *map){

for (int i = 0 ;map->all_content[i]!= NULL ; i++)
{
	free(map->all_content[i]);

}
free(map->all_content);
}

int bsq(int argc ,char **argv)
{
	int i = 1 ;
	map_t map;
	memset(&map,0,sizeof(map_t));
	while(i<argc)
	{
		if(map.all_content)
		{
			ft_free(&map);
			memset(&map,0,sizeof(map_t));
		}
		if(get_map(argv[i],&map)!=0)
		{
			continue;
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
