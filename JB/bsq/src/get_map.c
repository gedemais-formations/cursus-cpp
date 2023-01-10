#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
// pour utiliser la fonction malloc
#include<stdlib.h>
//pour utiliser la fonction open et stat
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"main.h"

// Pour chaque argument de la fonction main
// fonction get_map
// une fraction qui récupère les metadata (1ere ligne du fichier d'entrée)
// 1: ouvrir le/les fichier(s) transmis
// utilisation de la fonction open

char* read_map(char* file_map){					// file_map est une variable qui contient l'adresse du fichier
	int fd_open_file = open(file_map, O_RDONLY);		// variable open_file est le fd (file descriptor) de file_map
	// vérification que l'on peut ouvrir et sinon renvoyé une erreur
	if (fd_open_file < 0){
		printf("File failed to open. \n");
		return(NULL);
	}
	

	// obtenir la taille du fichier à malloc
	// déclare une variable structure stat > vide qui sera entré en paramètre de stat
	struct stat buf_stat;
	// on rempli cette variable avec la fonction stat, passage de variable par référence
	// et vérification que stat a bien fonctionné
	if(stat(file_map, &buf_stat) == -1){
		perror(strerror(errno));
		perror("Cannot acces stat file\n");
	}
	
	int file_size = buf_stat.st_size;
	char* map_init = NULL;
	map_init = (char*)malloc(sizeof(char) * (file_size + 1));
	if (!map_init){
		printf("No more memory available\n");
		return(NULL);
	}

	// copie les file_size premier char dans l'espace alloué avec read
	// et stocké dans re_file_map le nombre d'octet lus
        int rd_file_map = read(fd_open_file, map_init, file_size);
        
        // ajout de \O en position rd_elt_mem (fin de chaine) soit elt_length
        // normalement
        // > pour signifier la fin de la chaine de caractère (cc)
        // caractère obligatoire sinon continuera à lire après la fin de la cc
        map_init[rd_file_map] = '\0';

        // vérification que cela à bien ecrit à l'adresse dédié
        printf("%s\n", map_init);
	
        // libération de l'espace mémoire
        return(map_init);
}

int get_metadata(char* map_init, t_metadata* m_map){

	char* first_line = ft_strdup(map_init, "\n");
	if (first_line == NULL){
		printf("Memory allocation trouble\n");
		return(1);
	}
	int length_fl = strlen(first_line);
	if (length_fl < 4){	// nb minimal de caractère à define en tête de fichier
		printf("Not enough arguments in line 1\n");
		return(2);
	}
	m_map->full_char = first_line[length_fl - 1];
	m_map->obstacle_char = first_line[length_fl - 2];
	m_map->empty_char = first_line[length_fl - 3];
	
	if(m_map->full_char == m_map->obstacle_char 
		|| m_map->full_char == m_map->empty_char 
		|| m_map->obstacle_char == m_map->empty_char){
		printf("The three characteres are not unique\n");
		return(3);
	}
	
	first_line[length_fl - 3] = '\0';
	m_map->nb_line = atoi(map_init);
	printf("Numbre of line is : %d \n", m_map->nb_line);
	
	char** lines = ft_split(map_init, "\n");
	if (lines == NULL){
		printf("Memory allocation trouble 2\n");
		return(4);
	}
	m_map->nb_col = strlen(lines[1]);
	return(0);
}	
	
//une seconde fraction pour récupérer le board
// 3: recupérer le board
// !!: verifier la taille du fichier 
// >> allouer un espace mémoire suffisant avec malloc pour la fonction
 
// fonction solve
// 4: trouver le plus grand carré de caractères vides
 
int get_board (char* map_init, t_metadata* m_map){
	m_map->map = ft_split(map_init, "\n");
	m_map->board = &m_map->map[1];
	for (int i = 0; i < m_map->nb_line; i++){
		if ((int)strlen(m_map->board[i]) != m_map->nb_col){
			printf("lines do not have the same size \n");
			return(1);
		}
	}
	return(0);
}




// 5: si plusieurs solutions, définir le carré à remplir
// 
// 6: remplir le carré sélectionné de caractères pleins
//
// fonction free
// 7: libérer la mémoire

// int bsq(argc, argv)
/*
int main(){
	char* ad_map_test = "./map_test";	 
	
	char* map_init;

	t_metadata m_map;
	
	if(!(map_init = read_map(ad_map_test))){
		return(1);
	}
	
	return (get_metadata(map_init, &m_map));
}*/

int	get_map(char *path, t_metadata *m_map)
{
	char	*content;

	content = read_map(path);
	if (content == NULL){
		printf("map error\n");
		return(1);
	}
	
	if (get_metadata(content, m_map)){
		printf("map error\n");
		return(1);
	}
	
	if (get_board(content, m_map)){
		printf("map error\n");
		return(1);
	}

	printf("nb_line = %d, nb_col = %d, empty_char = %c, obstacle_char = %c, full_char = %c\n", 
			m_map->nb_line, m_map->nb_col, m_map->empty_char, m_map->obstacle_char, m_map->full_char);

	return(0);
}

