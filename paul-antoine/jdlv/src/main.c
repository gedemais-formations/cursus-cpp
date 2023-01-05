#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/error.h"
#include "../include/screen_handling.h"

int main(int argc, char **argv) {
    if (argc != 4)
        return print_error(ERROR_ARG_NBR);

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return print_error(ERROR_SDL_INIT);
    }


    /* Création de la fenêtre */
    SDL_Window *pWindow;
    pWindow = SDL_CreateWindow("Jeu de la vie", 0,
                               0,
                               SCREEN_WIDTH,
                               SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);
    if (pWindow == NULL) {
        SDL_Quit();
        return print_error(ERROR_SDL_WINDOW_NULL);
    }
    int err = background(pWindow, 0x45224F00);
    if (err != 0) {
        return err;
    }

    print_square(pWindow, 0x11F11100, 20, 20, 80, 120);

    while (1) SDL_Delay(3000);

    SDL_DestroyWindow(pWindow);


    SDL_Quit();

    return 0;
}



