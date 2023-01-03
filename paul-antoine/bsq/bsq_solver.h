//
// Created by pad on 12/20/22.
//
#ifndef BSQ_BSQ_SOLVER_H
#define BSQ_BSQ_SOLVER_H

#include <stdbool.h>

#define ERROR_CANT_OPEN_FILE 1
#define ERROR_CANT_READ_FILE 2
#define ERROR_INVALID_PATTERN 3
#define ERROR_CANT_ALLOCATE_MEMORY 4


/**
 * save case value as a 1bit boolean (see get_case and set_case for data retrieval)
 */
typedef struct {
    unsigned char val;
} t_case;

/**
 * Save all information regarding a field (size, characters, values)
 */
typedef struct {
    int row_size;
    int col_size;
    int col_size_byte;
    char empty, obstacle, full;
    t_case* field;
} t_field;

/**
 * Return the boolean value of a case
 * @param u_case an array of t_case
 * @param global_index index in bit inside the array
 * @return Value of u_case at "global_index"
 */
bool get_case(t_case* u_case, int global_index);

/**
 * Set the boolean value of a case inside an array of cases
 * @param u_case an array of t_case
 * @param global_index index in bit inside the array
 * @param value the new value
 */
void set_case(t_case *u_case, int global_index, bool value);

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
 * Parse a string buffer and put its data inside a new t_field
 * @param buffer The string buffer containing raw data
 * @param field_ptr a pointer to the pointer who'll hold the result
 * @return 0 on success, errcode otherwise
 */
int parse_field_buffer(char* buffer, t_field **field_ptr);
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
 * Destruct a field properly by freeing allocated memory
 * @param field The t_field to destruct
 */
void destruct(t_field field);

/**
 * Simple array to int conversion
 * @param str The array to convert
 * @param buffer The buffer who'll hold the result
 * @return 0 on success, errcode otherwise
 */
int a_to_i(char const *str, int* buffer);

/**
 * Print a message linked to "errcode" and add content of "context" in it
 * @param errcode The error code as defined in bsq.h
 * @param context Some context to add to the error (eg. filename)
 * @return errcode
 */
int print_error(int errcode, const char* context);


int skip_cases(t_field *field, int i, int j, int n_best);

#endif //BSQ_BSQ_SOLVER_H