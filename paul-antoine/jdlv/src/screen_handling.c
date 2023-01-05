//
// Created by pad on 1/5/23.
//

#include "../include/error.h"
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include "../include/screen_handling.h"

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

int background(SDL_Window* pWindow, int color) {
    SDL_Surface* surface = SDL_GetWindowSurface(pWindow);
    if(surface == NULL) return print_error(ERROR_SDL_NO_SURFACE);
    char* pixelBuffer = surface->pixels;
    /*int h = surface->h;
    int w = surface->w;*/

    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            put_pixel(pixelBuffer, i, j, color);
        }
    }

    if(SDL_UpdateWindowSurface(pWindow)) return print_error(ERROR_SDL_WINDOW_UPDATE);

    return 0;
}