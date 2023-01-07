#include "../include/SDL2/SDL.h"

#include <stdio.h>
#include <stdbool.h>

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 600
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT)

void put_pixel(char* buffer, int x, int y, int color);

int main(int argc, char** argv)
{
    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        pWindow = SDL_CreateWindow("Ma première application SDL2", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED,
                                   SCREEN_WIDTH,
                                   SCREEN_HEIGHT,
                                   SDL_WINDOW_SHOWN);

        if( pWindow )
        {
            SDL_Surface* surface = SDL_GetWindowSurface(pWindow);
            char* pixelBuffer = surface->pixels;

            for (int i = 0; i < SCREEN_HEIGHT; ++i) {
                for (int j = 0; j < SCREEN_WIDTH; ++j) {
                    put_pixel(pixelBuffer, i, j, 255 );
                }
            }

            SDL_UpdateWindowSurface(pWindow);

            while (strcmp(scanf("%s"), "quit") != 0) SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

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
        r = ((char *) &color)[0];
        g = ((char *) &color)[1];
        b = ((char *) &color)[2];
        a = ((char *) &color)[3];
    } else {
        r = ((char *) &color)[3];
        g = ((char *) &color)[2];
        b = ((char *) &color)[1];
        a = ((char *) &color)[0];
    }

    int start = (y * SCREEN_WIDTH * 4) + x * 4;

    buffer[start] = r;
    buffer[start+1] = g;
    buffer[start+2] = b;
    buffer[start+3] = a;
}

