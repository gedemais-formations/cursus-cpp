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

    int caseRow, caseCol, caseSize, nbTik, err;

    err = a_to_i(argv[1], &caseRow);
    err += a_to_i(argv[2], &caseCol);
    err += a_to_i(argv[3], &caseSize);
    err += a_to_i(argv[4], &nbTik);
    if(err != 0) return err;
    if(caseRow == 0 || caseSize == 0 || caseCol == 0 ||nbTik == 0)
        return print_error(ERROR_NAN, "0");
    int screen_width = caseCol * caseSize;
    int screen_height = caseRow * caseSize;

    // Interrupt is the number of ms to wait between two call of "evolve"
    int interrupt = 1000 / nbTik;
    SDL_Event event;

    // SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return print_error(ERROR_SDL_INIT);
    }


    // Window creation
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
        if(board != NULL){
            if(board->data != NULL) free(board->data);
            free(board);
        }
        return err;
    }

    bool gameRunning = true;
    while (gameRunning) {

        err = background(pWindow, 0x0000AA00);
        if (err != 0) {
            SDL_Quit();
            free(board->data);
            free(board);
            return err;
        }

        err = print_board(pWindow, *board);
        if (err != 0) {
            SDL_Quit();
            free(board->data);
            free(board);
            return err;
        }

        if(SDL_UpdateWindowSurface(pWindow)) {
            SDL_Quit();
            free(board->data);
            free(board);
            return print_error(ERROR_SDL_WINDOW_UPDATE);
        }

        err = evolve(board);
        if (err != 0) {
            SDL_Quit();
            free(board->data);
            free(board);
            return err;
        }

        SDL_Delay(interrupt);

        handleEvents(&event, &gameRunning);
    }

    free(board->data);
    free(board);

    SDL_DestroyWindow(pWindow);


    SDL_Quit();

    return 0;
}



