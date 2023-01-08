#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../include/error.h"
#include "../include/screen_handling.h"
#include "../include/jdlv.h"
#include "../include/util.h"

int main(int argc, char **argv) {
    if (argc != 5)
        return print_error(ERROR_ARG_NBR);

    int caseRow, caseCol, caseSize, nbTik;
    int err;
    err = a_to_i(argv[1], &caseRow);
    err += a_to_i(argv[2], &caseCol);
    err += a_to_i(argv[3], &caseSize);
    err += a_to_i(argv[4], &nbTik);
    if(err != 0) return err;
    if(caseRow == 0 || caseSize == 0 || caseCol == 0 ||nbTik == 0)
        return print_error(ERROR_NAN, "0");
    int screen_width = caseCol * caseSize;
    int screen_height = caseRow * caseSize;
    int interrupt = 1000 / nbTik;
    SDL_Event event;

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return print_error(ERROR_SDL_INIT);
    }


    /* Création de la fenêtre */
    SDL_Window *pWindow;
    pWindow = SDL_CreateWindow("Jeu de la vie", 0,
                               0,
                               screen_width,
                               screen_height,
                               SDL_WINDOW_SHOWN);
    if (pWindow == NULL) {
        SDL_Quit();
        return print_error(ERROR_SDL_WINDOW_NULL);
    }

    t_board* board = NULL;
    err = create_board(&board, caseRow, caseCol, caseSize);
    if(err != 0) {
        SDL_Quit();
        return err;
    }

    bool gameRunning = true;
    while (gameRunning) {

        err = background(pWindow, 0x0000AA00);
        if (err != 0) {
            return err;
        }

        err = print_board(pWindow, *board);
        if (err != 0) {
            return err;
        }

        if(SDL_UpdateWindowSurface(pWindow)) return print_error(ERROR_SDL_WINDOW_UPDATE);

        evolve(board);

        SDL_Delay(interrupt);

        handleEvents(&event, &gameRunning);
    }

    free(board->board);
    free(board);

    SDL_DestroyWindow(pWindow);


    SDL_Quit();

    return 0;
}



