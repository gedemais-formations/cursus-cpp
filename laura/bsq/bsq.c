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
	int i, j, size = 0, ** coord, k = 0; // Same, la il faut penser aux dyslexiques etc. Plus une ligne est longue et plus elle est fatiguante a lire.
	for(i = 0; i < max_y; i++) {
		for(j = 0; j < max_x; j++) {
			if(tab[i][j] == 'o') size++;
		}
	}
	coord = (int **)malloc(sizeof(int *) * size); // Malloc non protege
	for(i = 0; i < size; i++) coord[i] = (int *)malloc(sizeof(int) * 2); // Malloc non protege
	for(i = 0; i < max_y; i++) {
		for(j = 0; j < max_x; j++) {
			if(tab[i][j] == 'o') {
				coord[k][0] = i;
				coord[k][1] = j;
				k++;
			}
		}
	}
	write_x(coord, size, tab, max_x, max_y); // Write non protege.
	free(coord);
}

void write_tab(char * buffer) {
	int i, height = 0, j, len, width, k;
	char ** tab;
	len = strlen(buffer); // Segfault si buffer == NULL (malloc non protege)
	k = 0;
	for(i = 0; i < len; i++) {
		if(buffer[i] == '\n') {
			width = i;
			break;
		}
	}
	for(i = 0; i < len; i++) if(buffer[i] == '\n') height++;
	tab = (char **)malloc(sizeof(char *) * height); // Malloc non protege
	for(i = 0, k = 0; i < height; i++) {
		tab[i] = (char *)malloc(sizeof(char) * width); // Malloc non protege
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
	int i, * files = NULL, size, s; // On evite generalement de declarer un type et un pointeur sur ce meme type sur la meme ligne, question de clarte.
	char * buffer = NULL, * filename;  // Buffer n'a pas besoin d'etre set a NULL
	struct stat buf;
	files = malloc(argc * sizeof(int)); // Malloc non protege
	//Si on entre pas de nom de fichier
	//Dans ce cas, on est plutot censes attendre le contenu du fichier sur l'entree standard, et pas son chemin (Good Luck).
	if(argc == 1) {
		int file;
		ask:
		puts("Entrez un nom de fichier :");
		scanf("%s", &filename); // scanf non protege
		file = open(filename, O_RDWR); // open non protege
		if(!file) { // Oulala oulala, RTFM...
			puts("Fichier introuvable");  // C'est pas forcement ca le probleme.
			goto ask; // I swear to God next time I'll find where you live and I'll come to get you (https://stackoverflow.com/questions/3517726/what-is-wrong-with-using-goto)
		}
		s = stat(filename, &buf); // Stat non protegee
		size = buf.st_size;
		buffer = (char *) malloc(size * sizeof(int)); // Malloc non protege
		read(file, buffer, size); // Read non protege
		write_tab(buffer); // Write non protege
		close(file); // Close non protege
	}
	else {
		for(i = 1; i < argc; i++) {
			s = stat(argv[i], &buf);// Stat non protegee
			size = buf.st_size;
			files[i] = open(argv[i], O_RDWR); // Eeeeeeh
			if(!files[i]) { // NOOOO, GOD PLEASE NO
				puts("Fichier inexistant"); // Bruh, c'est meme pas le meme message que la haut XD
				break;
			}
			buffer = (char *)malloc(size * sizeof(int)); // Malloc non protege.
			read(files[i], buffer, size); // Read non protege.
			write_tab(buffer); // Write non protege.
			close(files[i]); // Close non protege.
		}
	}
	// Me refais plus ca stp :') my poor poor eyes
	if(buffer) free(buffer);
	if(files) free(files);
}
