#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char **argv)
{
	/* 1-Ouvrir le ou les fichiers contenant la /les map(s)
	 * 2- Contenir les informations de la carte
       nombre de ligne
        nombre de caracteres vides
		nombre de caracteres obstacles
		nombre de caracteres pleins
		3- Détecter le nombre d'octets présents sur une ligne
		4- Détecter la fin de la ligne pour passer à la suivante
		5- Calculer la distance entre deux caracteres plein à l'aide de la récursivité ? 
		Déterminer chaque caractere plein à l'aide de la fonction read et calculer une distance
		distance = meme nombre d'octets vide
		On part d'un caracetre plein et on calcule le nombre d'octets jusqu'au caracteres prochain
*/

}

int get_metadata(){
int fd = open(~/cursus-cpp/romain/exemple.txt,O_RDONLY);
if(fd<0)
{
	printf("Problem with file");
}

}
