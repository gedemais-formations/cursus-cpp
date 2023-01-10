#include "main.h"

int get_metadata(map_t *map, char *str)
{
	char *first_line;
	int len;
	if((first_line=ft_strdup(str, "\n"))==NULL)
	{
		perror("strdup :");
		return 1;
	}

	if((len = strlen(first_line))<4)
	{
		perror("strlen :");
		free(first_line);
		return 1;
	}

	map->full_char=first_line[len-1]; 
	map->obstacle_char=first_line[len-2];
	map->empty_char=first_line[len-3];
	first_line[len-3]='\0';

	if(map->full_char==map->obstacle_char || map->obstacle_char==map->empty_char || map->full_char==map->empty_char)
	{
		perror("map error :");
		free(first_line);
		return 1;
	}

	if((map->nb_lines=atoi(first_line))==0)
	{
		perror("atoi :");
		free(first_line);
		return 1;
	}
	free(first_line);	
	return 0;
}

int get_board(map_t *map, char *str)
{
	if((map->map_full=ft_split(str, "\n"))==NULL)
	{
		perror("ftsplit :");
		return 1;
	}
	map->board=&map->map_full[1];
	map->nb_columns=strlen(map->board[0]);

	for(int i=0; map->board[i]!=NULL; i++)
	{
	 if(map->nb_colums != strlen(map->board[i]))
	 {
		perror("nb colonnes inégal :")
		return 1;
	 }
	}
	return 0;
}

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


int get_map(char *path,map_t *map)
{
	char *content;
	content=read_map(path);
	if(!content)
	{ 
		return 1;
	}
	if(get_metadata(map,content)!=0)
	{
		perror("get_metadata :");
		return 1;
	}
	get_board(map, content);
	printf("%d%c%c%c \n", map->nb_lines, map->empty_char, map->obstacle_char, map->full_char);
	for(int i=0; map->board[i]!=NULL;i++)
	{
		printf("%s \n",map->board[i]);
	}
	
	return 0; 

}
