#define s_size 9

// appel des librairies

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

// fonction qui construite la grille du sudoku rempli de 0

void print_grille(int grille[s_size][s_size]){
	float f_s_size = (float)s_size;
	int r_sqr = (int)sqrt(f_s_size);
	printf("-----------\n");

	for (int r=0; r<s_size; r++){
		for (int c=0; c<s_size; c++){
			printf("%d", grille[r][c]);
			if(c%(r_sqr) == r_sqr-1 && c != s_size -1){
          			printf("|");
        		}
      		}
      		printf("\n");
      		if(r%r_sqr == r_sqr-1){
        		printf("-");
        		for(int i = 0; i < s_size; i++){
          			printf("-");
        	}
        		printf("-\n");
      		}
	}
	printf("\n");
	printf("----------\n");
}

// fonction vérifiant que le chiffre n n'est pas sur la colonne, la ligne ou le carre 3x3

 
// pour tester le code avec une grille déjà préremplie
/*
int init_grille(int sudoku[s_size][s_size]){
	int grille[s_size][s_size] =
		{
       		{9,0,0,1,0,0,0,0,5},
       		{0,0,5,0,9,0,2,0,1},
        	{8,0,0,0,4,0,0,0,0},
        	{0,0,0,0,8,0,0,0,0},
        	{0,0,0,7,0,0,0,0,0},
        	{0,0,0,0,2,6,0,0,9},
        	{2,0,0,3,0,0,0,0,6},
        	{0,0,0,2,0,0,9,0,0},
        	{0,0,1,9,0,4,5,7,0}
    		};
  	for(int i=0; i<s_size; i++){
    		for(int j = 0; j < s_size; j++){
      		sudoku[i][j] = grille[i][j];
    		}
  	}
  	return (0);
}
*/

bool check_case(int grille[s_size][s_size], int r, int c, int n){
	float f_s_size = (float)s_size;
	int r_sqr = (int)sqrt(f_s_size);
	int c_s = c/r_sqr;
	int r_s = r/r_sqr;
	// printf("-----------\n");

	fflush(stdout);

	// vérification si la case est vide
	/*
	 * if (grille[r][c] != 0){
		return(false);
	}
	*/
	for(int i=0; i<s_size; i++){
		// check horizontal droite et gauche
		// if (r-i > -1 && r+i < s_size && grille[c][r-i]==n && grille[c][r+i]==n){
		//check chaque ligne en commençant à l'indice 0
		if (grille[i][c]==n){
			return(false);
		}
		//check vertical haute et basse
		//else if (c-i > -1 && c+i < s_size && grille[c-i][r]==n && grille[c+i][r]==n){
		//check chaque colonne en commençant à l'indice 0
		else if (grille[r][i]==n){
		return(false);
		}
	}
		// check dans chaque sub_grille r_sqrxr_sqr
		// check case par case en commençant par la la case avec l'indice en haut à gauche 
		// prise en compte que les index des lignes et col commence à 0
	for (int j=0; j<(r_sqr); j++){
		for (int k=0; k<(r_sqr); k++){
			if(grille[(r_s*r_sqr)+j][(c_s*r_sqr)+k]==n){
			return(false);
			}
		}
	
	}
	return(true);
}



int solve (int grille[s_size][s_size], int case_grille){
	int count =0;
	int s_return;
	int rt = s_size-1;
	int ct = s_size-1;
	
	// Check si on a pus placer un n à la dernière case du sudoku
	if (case_grille == ((s_size*s_size)-1)){
		if (grille[s_size -1][s_size-1] != 0){
		print_grille(grille);
		return(1);
		}
		else {
			for (int n = 1; n < s_size + 1; n++){
				if (check_case(grille, rt, ct, n)==true){
					grille[rt][ct] = n;
					print_grille(grille);
					grille[rt][ct] = 0;
					return(1);
				}
			}
		}

	}
	// Sinon on fait la récursvité sur la case suivante en testant les n = s_size numéros possible
	else {
		int r = (case_grille / s_size); 
		int c = (case_grille % s_size);
		/*
		assert(r>=0);
		printf("r >= 0 le programme peut se poursuivre normalement \n");
		assert(r<s_size);
		printf("r <= s_size le programme peut se poursuivre normalement \n");
		assert(c>=0);
		printf("c >= 0 le programme peut se poursuivre normalement \n");
		assert(c<s_size);
		printf("c <= s_size le programme peut se poursuivre normalement \n");
		*/

		// printf("%d\n", grille[c][r]);
		// !! indice de case_grille commence à 0, donc quand une ligne est complétée, case_grille est à 8 et non pas à 9 > ok
		if (grille[r][c] != 0) {
			s_return = solve(grille, case_grille+1);
			count = s_return;
		}
		else {
			for (int n = 1; n < s_size + 1; n++){
				if (check_case(grille, r, c, n) == true){
					grille[r][c] = n;
					s_return = solve(grille, case_grille+1);
					count += s_return;
					grille[r][c]=0;
				}	
			}
		}
	}
	return(count);
}

int main(void){
	// initialisation de la grille
	int grille[s_size][s_size] = {};
	// pour tester avec une grille déjà pré-remplie
	// init_grille(grille);
	/*
	for (unsigned int i = 0; i < s_size; i++){
		memset(grille[i], 0, sizeof(int) * s_size);
	}
	*/
	print_grille(grille);
	int nb_solution = solve(grille, 0);
	printf("Number of solution for this Sudoku is : %d\n", nb_solution);
	return (0);
}
// il y a toujours une erreur, il y a un 0 en grille[1][0]
