#include<main.h>

int min(int a, int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

bool check(map_t *map, int x, int y, int side)
{
	int nb_lignes=map->nb_lines;
	int nb_colonnes=map->nb_columns;
	char **board=map->board;
	char obstacle = map->obstacle_char;
	
	if(x+side >= nb_lignes || y+side >= nb_colonnes)
		return false;

	for(int i=x; i<x+side; i++)
	{
		for(int j=y; j<y+side; j++)
		{
			if(board[i][j]==obstacle)
				return false;
		}
	}
	return true;
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
				if(check(map,i,j,side))
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

