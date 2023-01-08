//
// Created by pad on 1/5/23.
//

#ifndef JDLV_SCREEN_HANDLING_H
#define JDLV_SCREEN_HANDLING_H

#define QUIT_KEY SDLK_ESCAPE

/**
 * Change background color of a window
 * @param pWindow The window to change
 * @param color The color to change it with in form 0xRRGGBBAA
 * @return 0 on success, errcode otherwise
 */
int background(SDL_Window* pWindow, unsigned int color);

/**
 * Write a color at "x,y" inside buffer
 * @param buffer a Pixel buffer
 * @param x The column where to write
 * @param y The row where to write
 * @param color The color to put in buffer in form 0xRRGGBBAA
 * @param width Width of one buffer row
 */
void put_pixel(char* buffer, int x, int y, unsigned int color, int width);

int print_square(SDL_Window* pWindow, unsigned int color, int x, int y, int w, int h);

void handleEvents(SDL_Event *event, bool *gameRunning);

#endif //JDLV_SCREEN_HANDLING_H
