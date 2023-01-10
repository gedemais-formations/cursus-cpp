//
// Created by pad on 1/5/23.
//

#include "../include/jdlv.h"
#include "../include/error.h"
#include "../include/screen_handling.h"
#include <stdlib.h>
//#include <stdio.h>
#include <time.h>
#include <string.h>


int create_board(t_board **pBoard, int number_row, int number_col, int case_size) {
    *pBoard = malloc(sizeof(t_board));
    if(*pBoard == NULL) return print_error(ERROR_CANT_ALLOC_MEMORY);

    (*pBoard)->case_row = number_row;
    (*pBoard)->case_col = number_col;
    (*pBoard)->case_size = case_size;
    (*pBoard)->data = malloc(sizeof(bool) * number_col * number_row);
    if((*pBoard)->data == NULL) return print_error(ERROR_CANT_ALLOC_MEMORY);

    return init_board(*pBoard, 50);
}

int init_board(t_board *pBoard, unsigned short saturation) {
    srand(time(NULL));

    pBoard->data = malloc(sizeof(char) * pBoard->case_col * pBoard->case_row);
    if(pBoard->data == NULL) return print_error(ERROR_CANT_ALLOC_MEMORY);

    for (int i = 0; i < pBoard->case_row; ++i) {
        for (int j = 0; j < pBoard->case_col; ++j) {
            set_case(pBoard->data, pBoard->case_col, i, j, rand() % 100 < saturation);
            //printf("%d", get_case(pBoard->data, pBoard->case_col, i, j));
        }
        //printf("\n");
    }

    return 0;
}


bool* copy_board(t_board board) {
    unsigned int tab_size = sizeof(bool) * board.case_col * board.case_row;
    bool* copy = malloc(tab_size);
    if(copy == NULL) return NULL;
    copy = memcpy(copy, board.data, tab_size);

    return copy;
}

int evolve(t_board* pBoard) {
    bool* next_board = copy_board(*pBoard);
    if(next_board == NULL) return print_error(ERROR_CANT_ALLOC_MEMORY);

    for (int i = 0; i < pBoard->case_row; ++i) {
        for (int j = 0; j < pBoard->case_col; ++j) {
            set_case(next_board,
                     pBoard->case_col,
                     i, j,
                     willBeAlive(*pBoard, i, j));
        }
    }
    free(pBoard->data);
    pBoard->data = next_board;

    return 0;
}

bool willBeAlive(t_board board, int row, int col) {
    int neighbor_val = 0;
    for (int i = row-1; i <= row+1; ++i) {
        for (int j = col-1; j <= col+1; ++j) {
            bool case_val = false;
            if(i>=0 && i<board.case_row && j>=0 &&  j < board.case_col && (i!=row || j!=col )) {
                case_val = get_case(board.data, board.case_col, i, j);
            }
            if(case_val) neighbor_val++;
        }
    }

    switch (neighbor_val) {
        case 3:
            return true;
        case 2:
            return get_case(board.data, board.case_col, row, col);
        default:
            return false;
    }
}

int print_board(SDL_Window *pWindow, t_board board) {
    unsigned short size = board.case_size;
    int err;
    for (int i = 0; i < board.case_row; ++i) {
        for (int j = 0; j < board.case_col; ++j) {
            if(get_case(board.data, board.case_col, i, j)) {
                err = print_square(pWindow, 0x00FF0000, j*size, i*size, size, size);
                if(err!=0) return err;
            }
        }
    }

    return 0;
}

bool get_case(bool *board, int lineWidth, int row, int col) {
    return board[row * lineWidth + col];
}

void set_case(bool *edited_board, int lineWidth, int row, int col, bool new_value) {
    edited_board[row * lineWidth + col]= new_value;
}