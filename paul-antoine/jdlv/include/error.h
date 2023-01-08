//
// Created by pad on 1/5/23.
//

#ifndef JDLV_ERROR_H
#define JDLV_ERROR_H

#define ERROR_ARG_NBR 1, "Error: Program require 4 arguments, number of cell in height, row, size of a cell, and number of tik per second\n", ""
#define ERROR_SDL_INIT 2, "Can't init SDL: (%)\n", SDL_GetError()
#define ERROR_SDL_WINDOW_NULL 3, "Can't create window: %\n", SDL_GetError()
#define ERROR_SDL_NO_SURFACE 4, "Can't get window surface: %\n", SDL_GetError()
#define ERROR_SDL_WINDOW_UPDATE 5, "Can't update window: %\n", SDL_GetError()
#define ERROR_NAN 6, "Error: \"%\" is not a valid number\n"
#define ERROR_CANT_ALLOC_MEMORY 7, "Error: can't allocate memory", ""

int print_error(int errcode, const char* err_msg, const char* context);

#endif //JDLV_ERROR_H
