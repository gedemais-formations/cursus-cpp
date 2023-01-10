#include <main.h>


bool check(int x , int y , int size, map_t *map)
	
{

	int line ;
	int colomn ;
	line = map->nb_lines ;
	colomn = map->nb_columns ;
	for (int i = x ; i<x+size ;i++)
	{
		for (int j = y  ; j< y+size; j++)
		{
			
               if(i+size >line)
			   {
				   return 1 ;
				}
					if(j+size>colomn)
					{
						return 1 ;
					}
			   if(map->board[i][j] == map->obstacle_char)
			   {
				   printf("pas de carré");
				   return 1 ;
				   
			   }
		}
	}
	printf("il y a un carré");

	return  0 ;
	
}

void pose_x(map_t *map, int x, int y, int side)
{
	char **board=map->board;
	char full = map->full_char;

	for(int i=x; i<x+side; i++)
	{
		for(int j=y; j<y+side; j++)
		{
			board[i][j]=full;	
		}
	}
}

int solve(map_t *map)
{
	int nb_lignes=map->nb_lines;
	int nb_colonnes=map->nb_columns;
	int side=min(nb_lignes,nb_colonnes);

	while(side>0)
	{
		for(int i=0; i<nb_lignes-side; i++)
		{
			for(int j=0; j<nb_colonnes-side; j++)
			{
				if(check(map,i,j,side)== 0 )
				{
					pose_x(map,i,j,side);
					return 0;
				}
			}
		}
		side--;
	}
	return 1;
}


