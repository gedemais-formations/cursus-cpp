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

/**
 * Initialise the t_board and populate it
 * @param pBoard Pointer to the pointer holding the new t_board
 * @param number_row Number of board's row
 * @param number_col Number of board's column
 * @param case_size Size of a board case in px
 * @return 0 on success errcode otherwise
 */
int create_board(t_board **pBoard, int number_row, int number_col, int case_size);

/**
 * Initialise a board by populating it with alive cells
 * @param pBoard The board to populate
 * @param saturation Odds of a cell to be alive (0% all dead to 100% all alive)
 * @return 0 on success errcode otherwise
 */
int init_board(t_board *pBoard, unsigned short saturation);

/**
 * Update a board of one life cycle
 * @param board The board to evolve
 * @return 0 on success, errcode otherwise
 */
int evolve(t_board *board);

/**
 * @param board The board to test
 * @param row Cell's row
 * @param col Cell's column
 * @return True if the cell shall be alive at next cycle, false otherwise
 */
bool willBeAlive(t_board board, int row, int col);

/**
 * Print the board on pWindow
 * @param pWindow Pointer to the window
 * @param board The board to print
 * @return 0 on success, errcode otherwise
 */
int print_board(SDL_Window *pWindow, t_board board);

/**
 *
 * @param board
 * @param lineWidth
 * @param row
 * @param col
 * @return
 */
bool get_case(bool *board, int lineWidth, int row, int col);

void set_case(bool *edited_board, int lineWidth, int row, int col, bool value);

#endif //JDLV_JDLV_H
