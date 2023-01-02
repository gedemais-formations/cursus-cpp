#define s_size 9

// appel des librairies

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

// fonction qui construite la grille du sudoku rempli de 0

void print_grille(int grille[s_size][s_size]){
	printf("-----------\n");

	for (int r=0; r<s_size; r++){
		for (int c=0; c<s_size; c++){
			printf("%d", grille[c][r]);
		}
		printf("\n");
	}
	printf("----------\n");
}

// fonction vérifiant que le chiffre n n'est pas sur la colonne, la ligne ou le carre 3x3

bool check_case(int grille[s_size][s_size], int c, int r, int n){
	int c_s = c/3;
	int r_s = r/3;

	fflush(stdout);

	// vérification si la case est vide
	if (grille[c][r] != 0){
	return(false);
	}
	for(int i=0; i<s_size; i++){
		// check horizontal droite et gauche
		// if (r-i > -1 && r+i < s_size && grille[c][r-i]==n && grille[c][r+i]==n){
		//check chaque ligne en commençant à l'indice 0
		if (grille[i][r]==n){
			return(false);
		}
		//check vertical haute et basse
		//else if (c-i > -1 && c+i < s_size && grille[c-i][r]==n && grille[c+i][r]==n){
		//check chaque colonne en commençant à l'indice 0
		else if (grille[c][i]==n){
		return(false);
		}
	}
		// check dans chaque sub_grille 3x3
		// check case par case en commençant par la la case avec l'indice en haut à gaut 
		// prise en compte que les index des lignes et col comme à 0
	for (int j=0; j<(s_size/3); j++){
		for (int k=0; k<(s_size/3); k++){
			if(grille[(c_s*3)+j][(r_s*3)+k]==n){
			return(false);
			}
		}
	
	}
	return(true);
}



int solve (int grille[s_size][s_size], int case_grille){
	int count =0;
	int s_return;

	// Check si on a pus placer un n à la dernière case du sudoku
	if (case_grille == ((s_size*s_size)-1) && grille[s_size -1][s_size-1] != 0){
		print_grille(grille);
		return(1);
	}
	// Sinon on fait la récursvité sur la case suivante en testant les n = s_size numéros possible
	else {
		int c = ((case_grille - 1) % s_size); 
		int r = ((case_grille - 1) / s_size);
	
		if (grille[c][r] != 0) {
		count = solve(grille, case_grille + 1);
		}
		else {
			for (int n = 1; n < s_size + 1; n++){
				if (check_case(grille, c, r, n) == true){
				grille[c][r] = n;
				s_return = solve(grille, n+1);
				count += s_return;
				grille[c][r]=0;
				}	
			}
		}
	}
	return(count);
}

int main(void){
	// initialisation de la grille
	int grille[s_size][s_size] = {};
	for (unsigned int i = 0; i < s_size; i++){
		memset(grille[i], 0, sizeof(int) * s_size);
	}
	print_grille(grille);
	int nb_solution = solve(grille, 0);
	printf("Number of solution for this Sudoku is : %d\n", nb_solution);
	return 0;
}
