//
// Created by pad on 1/5/23.
//

#ifndef JDLV_JDLV_H
#define JDLV_JDLV_H

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct {
    int case_row;
    int case_col;
    unsigned short case_size;
    bool *board;
} t_board;

int create_board(t_board **pBoard, int number_row, int number_col, int case_size);

int init_board(t_board *pBoard, unsigned short saturation);

int evolve(t_board *board);

bool willBeAlive(t_board board, int row, int col);

int print_board(SDL_Window *pWindow, t_board board);

bool get_case(bool *board, int lineWidth, int row, int col);

void set_case(bool *edited_board, int lineWidth, int row, int col, bool value);

#endif //JDLV_JDLV_H
