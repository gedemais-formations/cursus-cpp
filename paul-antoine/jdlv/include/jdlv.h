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
    bool *data;
} t_board;

/**
 * Initialise the t_board and populate it
 * @param pBoard Pointer to the pointer holding the new t_board
 * @param number_row Number of data's row
 * @param number_col Number of data's column
 * @param case_size Size of a data case in px
 * @return 0 on success errcode otherwise
 */
int create_board(t_board **pBoard, int number_row, int number_col, int case_size);

/**
 * Initialise a data by populating it with alive cells
 * @param pBoard The data to populate
 * @param saturation Odds of a cell to be alive (0% all dead to 100% all alive)
 * @return 0 on success errcode otherwise
 */
int init_board(t_board *pBoard, unsigned short saturation);

/**
 * Update a data of one life cycle
 * @param board The data to evolve
 * @return 0 on success, errcode otherwise
 */
int evolve(t_board *board);

/**
 * @param board The data to test
 * @param row Cell's row
 * @param col Cell's column
 * @return True if the cell shall be alive at next cycle, false otherwise
 */
bool willBeAlive(t_board board, int row, int col);

/**
 * Print the data on pWindow
 * @param pWindow Pointer to the window
 * @param board The data to print
 * @return 0 on success, errcode otherwise
 */
int print_board(SDL_Window *pWindow, t_board board);

/**
 * Return boolean value of case at (row, col)
 * @param board The board
 * @param lineWidth Number of column in one row
 * @param row Case's row
 * @param col Case's column
 * @return True if board[row][col] is true false otherwise.
 */
bool get_case(bool *board, int lineWidth, int row, int col);


/**
 * Set case value at (row, col) to new_value
 * @param edited_board The board
 * @param lineWidth Number of column in one row
 * @param row Case's row
 * @param col Case's column
 * @param new_value Value to put inside the case.
 */
void set_case(bool *edited_board, int lineWidth, int row, int col, bool new_value);

#endif //JDLV_JDLV_H
