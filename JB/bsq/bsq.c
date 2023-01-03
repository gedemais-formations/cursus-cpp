#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
// pour utiliser la fonction malloc
#include<stdlib.h>
//pour utiliser la fonction open
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

// Pour chaque argument de la fonction main
// fonction get_map
// une fraction qui récupère les metadata (1ere ligne du fichier d'entrée)
// 1: ouvrir le/les fichier(s) transmis
// utilisation de la fonction open

char get_map(char *ad_file_map){			// file_map est une variable qui contient l'adresse du fichier
	int open_file = open(ad_file_map, O_RDONLY);	// variable open_file est le fd (file descriptor) de file_map
	// vérification que l'on peut ouvrir et sinon renvoyé une erreur
	if (open_file < 0){
	printf("File failed to open. \n");
	return(false)
	}
	
// 2: lire la première ligne du/des fichier(s) transmis
// l'adresse du (des) fichier(s) est/sont spécifié(s) dans les arguments de la fonction main
// utilisation de la fonction read
// il faut récupérer la première ligne jusqu'au premier \n >> utiliser ft_split()

}


// 	a: vérifier que les caractères de la grille sont ceux de la première ligne
//	>> renvoyer un message erreur spécifique si non
//
// 	b: vérifier qu'il y a au moins une ligne d'une case
// 	Il doit y avoir au moins 2 lignes dans le fichier ET la seconde ligne doit avoir au moins un caractère
// 	>> renvoyer un message erreur spécifique si non
// 	
// 	c: vérifier que toutes les lignes (sauf la première) ont la même longueur
//	pour toutes les lignes l de l'index 1 à (last = dimension du fichier), size(
//	>> renvoyer un message erreur spécifique si non
// 	
// 	d: vérifier qu'il y a un retour à la ligne à la fin de chaque ligne
// 	>> renvoyer un message erreur spécifique si non
//
//une seconde fraction pour récupérer le board
// 3: recupérer le board
// !!: verifier la taille du fichier 
// >> allouer un espace mémoire suffisant avec malloc pour la fonction
// 
// fonction solve
// 4: trouver le plus grand carré de caractères vides
// 
// 5: si plusieurs solutions, définir le carré à remplir
// 
// 6: remplir le carré sélectionné de caractères pleins
//
// fonction free
// 7: libérer la mémoire

void main (){
return (0)
}
