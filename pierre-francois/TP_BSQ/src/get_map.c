#include "main.h"

char *read_map(char *path)
{  
	ssize_t size;
	struct stat buf_stat ;
	int fd;
	char *resultat;
	fd = open(path,O_RDONLY);
	if(fd==-1 || stat(path,&buf_stat)== -1)
	{
		perror("error :");
		return NULL ;
	}
	
	if(!(resultat=malloc(buf_stat.st_size+1)))
	
	{
		perror("malloc :");
		return NULL ;
	}	
	
	if((size=read(fd,resultat,buf_stat.st_size)) == -1)
	{
		perror("read :");
		return NULL;
    }
	resultat[size]='\0';
	close(fd);
	return resultat ;
	

	
}

map_t *get_map(char *path)
{
	char *content;
	map_t *map ;
	content=read_map(path);
	if(!content)
	{ 
		return NULL;
	}
	printf("%s",content);
	(void) map;
	return NULL; 

}
