//
// Created by pad on 1/5/23.
//

#ifndef JDLV_JDLV_H
#define JDLV_JDLV_H

#include <stdbool.h>


typedef struct {
    unsigned int case_row;
    unsigned int case_col;
    unsigned short case_size;
    bool* board;
} t_board;

int init_board(t_board* board);

int evolve(t_board* board);

#endif //JDLV_JDLV_H
