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
    return true;
}

int solve(int grille[9][9], int x)
{
    int soluce = 0;
    if( x == 8)
    {
        for(int y = 0; y < 9; y++)
        {
            if(grille[x][y] != 0)
            {
                if(check_sudoku(grille, x, y, grille[x][y]))
                {
                    printf("solution trouvée\n");
                    print_sudoku(grille);
                    soluce++;
                }
            }
            else{
                for(int z = 1; z <= 9; z++)
                {
                    if(check_sudoku(grille, x, y, z))
                    {
                        grille[x][y] = z;
                        printf("solution trouvée\n");
                        print_sudoku(grille);
                        soluce++;
                        grille[x][y] = 0;
                    }
                }
            }
        }
    }
    else
    {
        for(int y = 0; y < 9; y++)
        {
            if(grille[x][y] !=0)
            {
                if(check_sudoku(grille, x, y, grille[x][y]))
                {
                    soluce += solve(grille, x+1);
                }
            }
            else
            {
                for(int z = 1; z <= 9; z++)
                {
                    if(check_sudoku(grille, x, y, z))
                    {
                        grille[x][y] = z;
                        soluce += solve(grille, x+1);
                        grille[x][y] = 0;
                    }
                }
            }
        }
    }
    return (soluce);
}

int main(void)
{
    int grille[9][9] = {
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0},
        {0,0,0, 0,0,0, 0,0,0}
    };
    
    printf("grille de départ\n");
    print_sudoku(grille);
    
    //printf("Il y a %d solutions possibles.\n", solve(grille[9][9], 0));
}
