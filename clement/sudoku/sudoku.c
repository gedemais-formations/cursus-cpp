#include <stdbool.h>
#include <stdio.h>

//énoncé : avec une grille donnée, trouver toutes les solutions possibles

void print_sudoku(int grille[9][9])
{
    printf("--------------------------\n");
    for (int x = 0; x < 9; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            if (y==0){
                printf("| ");
            }
            printf("%d ", grille[x][y]);
            if (( y + 1 ) % 3 == 0){
                printf("| ");
            }
        }
        printf("\n");
        if (( x + 1 ) % 3 == 0){
            printf("--------------------------\n");
        }
    }
}

bool check_sudoku(int grille[9][9], int x, int y, int z)
{
    //vérification sur la ligne
    for(int i = 0; i < 9; i++)
    {
        if((grille[x][i] == z) && (i != y))
        {
            return false;
        }
    }
    //vérification sur la colonne
    for(int i = 0; i < 9; i++)
    {
        if((grille[i][y] == z) && (i != x))
        {
            return false;
        }
    }
    //vérification sur le bloc 3x3 qui contient la case
    for(int i = (x/3)*3; i/3 <= x/3; i++)
    {
        for(int j = (y/3)*3; j/3 <= y/3; j++)
        {
            if(grille[i][j] == z && !(i == x && j == y))
            {
                return false;
            }
        }
    }
    return true;
}

//cette fonction valide l'état de la grille rentrée comme paramètre. Si elle ne respecte pas les règles du Sudoku, elle renvoie un message d'erreur
bool grille_correcte(int grille[9][9])
{
    int i = 0;
    int j = 0;
    bool sortie = true;
    while(i < 9 && sortie)
    {
        while(j < 9 && sortie)
        {
            //vérification que la case est déjà préremplie 
            if(grille[i][j] != 0)
            {
                //vérification que la case est remplie de façon appropriée
                if(!check_sudoku(grille, i, j, grille[i][j]) || grille[i][j] < 0 || grille[i][j] > 9)
                {
                    printf("La grille n'est pas remplie correctement!!!");
                    sortie = false;
                }
            }
            j++;
        }
        i++;
    }
    return sortie;
}

int solve(int grille[9][9], int x, int y)
{
    int soluce = 0;
    //boucle récursive sur y en premier pour optimiser
    if(y < 8)
    {
        //vérification que la case [x][y] est vide
        if(grille[x][y] == 0)
        {
            //vérification sur chaque chiffre possible
            for(int z = 1; z <= 9; z++)
            {
                if(check_sudoku(grille, x, y, z))
                {
                    //remplissage de la case pour pouvoir continuer
                    grille[x][y] = z;
                    soluce += solve(grille, x, y+1);
                    //réinitialisation de la case
                    grille[x][y] = 0;
                }
            }
        }
        //passage immédiat à la case suivante si la case [x][y] est une case préremplie
        else
        {
            soluce += solve(grille, x, y+1);
        }
    }
    else
    {
        //boucle récursive sur x
        if(x < 8)
        {
            //vérification que la case est vide
            if(grille[x][y] == 0)
            {
                //vérification sur chaque chiffre possible
                for(int z = 1; z <= 9; z++)
                {
                    if(check_sudoku(grille, x, y, z))
                    {
                        //remplissage de la case pour pouvoir continuer
                        grille[x][y] = z;
                        soluce += solve(grille, x+1, 0);
                        //réinitialisation de la case
                        grille[x][y] = 0;
                    }
                }
            }
            //passage immédiat à la case suivante si las case [x][y] est une case préremplie
            else
            {
                soluce += solve(grille, x+1, 0);
            }
        }
        else
        {
            //vérification que la case est vide
            if(grille[x][y] == 0)
            {
                //vérification sur chaque chiffre possible
                for(int z = 1; z <= 9; z++)
                {
                    if(check_sudoku(grille, x, y, z))
                    {
                        //remplissage de la case pour l'affichage
                        grille[x][y] = z;
                        soluce++;
                        //affichage de la solution
                        print_sudoku(grille);
                        //réinitialisation de la case
                        grille[x][y] = 0;
                    }
                }
            }
            //affichage immédiat de la solution si la case [x][y] est préremplie
            else
            {
                soluce++;
                print_sudoku(grille);
            }
        }
    }
    return soluce;
}

int main(void)
{
    //initialisez ce tableau avec les valeurs que vous voulez tester
    int grille[9][9] = {
        {1,0,0, 0,4,7, 3,0,8},
        {0,9,0, 0,8,0, 0,2,0},
        {6,0,0, 0,0,0, 0,0,0},
        
        {9,0,0, 8,0,2, 0,0,0},
        {2,6,0, 0,0,0, 0,8,4},
        {0,0,0, 4,0,5, 0,0,3},
        
        {0,0,0, 0,0,0, 0,0,9},
        {0,0,0, 0,5,0, 0,0,0},
        {8,0,3, 6,1,0, 0,0,0}
    };
    
    printf("grille de départ\n");
    print_sudoku(grille);
    
    if (grille_correcte(grille))
    {
        printf("Il y a %d solutions possibles.\n", solve(grille, 0, 0));
    }
}
