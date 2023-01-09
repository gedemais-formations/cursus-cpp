#include"main.h"

int main (void){
        char **tab;
        if(!(tab=ft_split("Bonjour tout le monde", " "))){
                return(1);              
        }       
        for (unsigned int i=0; tab[i]; i++){
                printf("%s\n", tab[i]);
                free(tab[i]);
        }
        free(tab);
        return (0);
}

