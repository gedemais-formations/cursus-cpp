#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

void write_x(int ** coord, int size, char ** tab, int max_x, int max_y) {
	int i, j, maxX, maxY, minX, minY;
	maxX = maxY = 0;
	minX = max_x; minY = max_y;
	//On sélectionne l'intervalle
	for(i = 0; i < size; i++) {
		if(maxX < coord[i][1]) maxX = coord[i][1];
		else if(minX > coord[i][1]) minX = coord[i][1];
		if(maxY < coord[i][0]) maxY = coord[i][0];
		else if(minY > coord[i][0]) minY = coord[i][0];
	}
	for(i = minY; i < maxY; i++) for(j = minX; j < maxX; j++) tab[i][j] = 'x';
	for(i = 0; i < max_y; i++) printf("\n%s", tab[i]);
}

//Retourne un tableau de coordonnées de o
void check_o(char ** tab, int max_x, int max_y) {
	int i, j, size = 0, ** coord, k = 0;
	for(i = 0; i < max_y; i++) {
		for(j = 0; j < max_x; j++) {
			if(tab[i][j] == 'o') size++;
		}
	}
	coord = (int **)malloc(sizeof(int *) * size);
	for(i = 0; i < size; i++) coord[i] = (int *)malloc(sizeof(int) * 2);
	for(i = 0; i < max_y; i++) {
		for(j = 0; j < max_x; j++) {
			if(tab[i][j] == 'o') {
				coord[k][0] = i;
				coord[k][1] = j;
				k++;
			}
		}
	}
	write_x(coord, size, tab, max_x, max_y);
	free(coord);
}

void write_tab(char * buffer) {
	int i, height = 0, j, len, width, k;
	char ** tab;
	len = strlen(buffer);
	k = 0;
	for(i = 0; i < len; i++) {
		if(buffer[i] == '\n') {
			width = i;
			break;
		}
	}
	for(i = 0; i < len; i++) if(buffer[i] == '\n') height++;
	tab = (char **)malloc(sizeof(char *) * height);
	for(i = 0, k = 0; i < height; i++) {
		tab[i] = (char *)malloc(sizeof(char) * width);
		for(j = 0; j < width; j++) {
			if(buffer[k] != 'o' && buffer[k] != '.') k++;
			tab[i][j] = buffer[k];
			k++;
		}
	}
		
	printf("\n%s", buffer);
	check_o(tab, width, height);
	free(tab);
}

int main(int argc, char ** argv) {
	int i, * files, size, s;
	char * buffer, * filename;
	struct stat buf;
	files = malloc(argc * sizeof(int));
	//Si on entre pas de nom de fichier
	if(argc == 1) {
		int file;
		ask:
		puts("Entrez un nom de fichier :");
		scanf("%s", &filename);
		file = open(filename, O_RDWR);
		if(!file) {
			puts("Fichier introuvable");
			goto ask;
		}
		s = stat(filename, &buf);
		size = buf.st_size;
		buffer = (char *) malloc(size);
		read(file, buffer, size);
		write_tab(buffer);
		close(file);
	}
	for(i = 1; i < argc; i++) {
		s = stat(argv[i], &buf);
		size = buf.st_size;
		files[i] = open(argv[i], O_RDWR);
		if(!files[i]) {
			puts("Fichier inexistant");
			break;
		}
		buffer = (char *)malloc(size);
		read(files[i], buffer, size);
		write_tab(buffer);
		close(files[i]);
	}
	free(buffer);
	free(files);
}
