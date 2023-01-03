//
// Created by pad on 12/20/22.
//
#ifndef BSQ_BSQ_SOLVER_H
#define BSQ_BSQ_SOLVER_H
#include "bsq_parser.h"

/**
 * Get field from a file
 * @param file the file pathname
 * @param field_ptr a pointer to the pointer who'll hold the result
 * @return 0 on success, errcode otherwise
 */
int get_field(char* file, t_field **field_ptr);
/**
 * Get field from stdin
 * @param field_ptr a pointer to the pointer who'll hold the result
 * @return 0 on success, errcode otherwise
 */
int get_field_std(t_field **field_ptr);

/**
 * Print a field on stdout
 * @param field the field to print
 * @param found_size found_size of the "full" square
 * @param found_row starting found_row of "full" square (upper left corner)
 * @param found_col starting column of "full" square (upper left corner)
 */
void print_field(t_field field, int found_size, int found_row, int found_col);
/**
 * Return the maximal square size starting from "row, col" inside of "field"
 * @param field The t_field to test
 * @param row starting row
 * @param col starting column
 * @return Max square size without an obstacle
 */
int square_size(t_field field,int row, int col, int min_square);

/**
 * Find the biggest square possible in a field and print the result on stdout
 * @param field The field to test
 */
void find_best(t_field field);

/**
 * Get the last tested square.
 * if it failed because of right side it will advance of "seek_size" to pass the obstacle.
 * if it failed because of an obstacle at the bottom advance of enough cases to pass the obstacle.
 * @param field The field tested
 * @param seek_row origin row of the square to test
 * @param seek_col origin column of the square to test
 * @param seek_size size of the maximum square at (seek_row, seek_col)
 * @return The seeking index updated to avoid the obstacle.
 */
int skip_cases(t_field *field, int seek_row, int seek_col, int seek_size);

/**
 * Destruct a field properly by freeing allocated memory
 * @param field The t_field to destruct
 */
void destruct(t_field field);


#endif //BSQ_BSQ_SOLVER_H