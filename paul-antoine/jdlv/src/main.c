#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/error.h"

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT)

void put_pixel(char* buffer, int x, int y, int color);

int main( int argc, char** argv)
{
    if(argc != 4)
        return print_error(ERROR_ARG_NBR, "");

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Jeu de la vie", 0,
                                   0,
                                   SCREEN_WIDTH,
                                   SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);

        if( pWindow )
        {
            SDL_Surface* surface = SDL_GetWindowSurface(pWindow);
            char* pixelBuffer = surface->pixels;

            for (int i = 0; i < SCREEN_HEIGHT; ++i) {
                for (int j = 0; j < SCREEN_WIDTH; ++j) {
                    put_pixel(pixelBuffer, i, j, 0x43ff64d9);
                }
            }

            SDL_UpdateWindowSurface(pWindow);

            while (1) SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

            SDL_DestroyWindow(pWindow);
        }
        else
        {
            fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
}



bool isLittleEndian() {
    int n = 1;
    return *(char*)&n == 1; //if the first byte of n is equal to 1 then the system is littleEndian
}

void put_pixel(char* buffer, int x, int y, int color) {
    char r, g, b, a;
    if (isLittleEndian()) {
        r = ((char *) &color)[3];
        g = ((char *) &color)[2];
        b = ((char *) &color)[1];
        a = ((char *) &color)[0];

    } else {
        r = ((char *) &color)[0];
        g = ((char *) &color)[1];
        b = ((char *) &color)[2];
        a = ((char *) &color)[3];
    }

    int start = (y * SCREEN_WIDTH * 4) + x * 4;

    buffer[start] = b;
    buffer[start+1] = g;
    buffer[start+2] = r;
    buffer[start+3] = a;
}
