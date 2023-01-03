#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

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
	//Le carré est situé entre ces coordonnées
	for(i = minY; i < maxY; i++) for(j = minX; j < maxX; j++) tab[i][j] = 'x';
	for(i = 0; i < max_y; i++) printf("\n%s", tab[i]);
}

//Création d'un tableau de coordonnées de o
void check_o(char ** tab, int max_x, int max_y) {
	int i, j, size, ** coord, k;
	k = 0;
	size = 0;
	//Calcul du nombre de o
	for(i = 0; i < max_y; i++) {
		for(j = 0; j < max_x; j++) {
			if(tab[i][j] == 'o') size++;
		}
	}
	//Création du tableau de coordonnées y,x de o
	coord = (int **)malloc(sizeof(int *) * size);
	if(!coord) {
		puts(strerror(errno));
		return;
	}
	for(i = 0; i < size; i++) {
		coord[i] = (int *)malloc(sizeof(int) * 2);
		if(!coord[i]) {
			puts(strerror(errno));
			return;
		}
	}
	for(i = 0; i < max_y; i++) {
		for(j = 0; j < max_x; j++) {
			if(tab[i][j] == 'o') {
				coord[k][0] = i;
				coord[k][1] = j;
				k++; //On incrémente après chaque coordonnée posée
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
	//Calcul de la largeur du board
	for(i = 0; i < len; i++) {
		if(buffer[i] == '\n') {
			width = i;
			break;
		}
	}
	//Calcul de la hauteur du board
	for(i = 0; i < len; i++) if(buffer[i] == '\n') height++;
	tab = (char **)malloc(sizeof(char *) * height);
	if(!tab) {
		puts(strerror(errno));
		return;
	}
	for(i = 0, k = 0; i < height; i++) {
		tab[i] = (char *)malloc(sizeof(char) * width);
		if(!tab[i]) {
			puts(strerror(errno));
			return;
		}
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

//Cas où aucun argument n'est passé, création d'un nouveau fichier
/*void create_file() {
	int line_size, size_buffer, s, f, w, cl, r;
	char str[100], new_filename[100], * buffer;
	struct stat buf;
	size_buffer = 0;
	puts("Entrez un nom de fichier : ");
	s = scanf("%s", &new_filename);
	if(s == -1) {
		puts(strerror(errno));
		return;
	}
	f = open(new_filename, O_CREAT|O_RDWR|O_TRUNC, 0777);
	if(!f) {
		puts(strerror(errno));
		return;
	}
	while(1) {
		puts("Entrez une ligne : ");
		scanf("%s", &str);
		if(str[0] != '.' && str[0] != 'o') break;
		strcat(str, "\n");
		w = write(f, str, strlen(str));
		if(w == -1) {
			puts(strerror(errno));
			return;
		}
	}
	s = stat(new_filename, &buf);
	if(s == -1) {
		puts(strerror(errno));
		return;
	}
	size_buffer = buf.st_size;
	buffer = (char *)malloc(size_buffer);
	if(!buffer) {
		puts(strerror(errno));
		return;
	}
	r = read(f, buffer, size_buffer);
	if(r == -1) {
		puts(strerror(errno));
		return;
	}
	write_tab(buffer);
	cl = close(f);
	free(buffer);
	if(cl == -1) {
		puts(strerror(errno));
		return;
	}
}*/

//cat example
void command(int argc, char ** argv) {
	FILE * f;
	char * c, ch, * buffer, * str;
	str = (char *)malloc(256);
	if(!str) {
		puts(strerror(errno));
		return;
	}
	buffer = (char *)malloc(256);
	if(!buffer) {
		puts(strerror(errno));
		return;
	}
	puts("Entrez une commande :");
	fgets(buffer, 256, stdin);
	f = popen(buffer, "r");
	if(!f) {
		puts(strerror(errno));
		return;
	}
	while((ch = fgetc(f)) != EOF) strcat(str, &ch);
	write_tab(str);
	if(buffer) free(buffer);
	if(str) free(str);
}

int main(int argc, char ** argv) {
	int i, * files, size, s, r, c;
	char * buffer, * filename;
	struct stat buf;
	buffer = NULL;
	files = malloc(argc * sizeof(int));
	if(!files) {
		puts(strerror(errno));
		return -1;
	}
	//if(argc == 1) create_file();
	if(argc == 1) command(argc, argv);
	else{
		for(i = 1; i < argc; i++) {
			s = stat(argv[i], &buf);
			if(s == -1) {
				puts(strerror(errno));
				return -1;
			}
			size = buf.st_size;
			files[i] = open(argv[i], O_RDWR);
			if(files[i] == -1) {
				puts(strerror(errno));
				return -1;
			}
			buffer = (char *)malloc(size);
			if(!buffer) {
				puts(strerror(errno));
				return -1;
			}
			r = read(files[i], buffer, size);
			if(r == -1) {
				puts(strerror(errno));
				return -1;
			}
			write_tab(buffer);
			c = close(files[i]);
			if(c == -1) {
				puts(strerror(errno));
				return -1;
			}
		}
	}
	if(buffer) free(buffer);
	if(files) free(files);
}
