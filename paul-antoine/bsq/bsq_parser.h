//
// Created by pad on 1/3/23.
//

#ifndef BSQ_BSQ_PARSER_H
#define BSQ_BSQ_PARSER_H
#include <stdbool.h>
#include "bsq_error.h"

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
 * Parse a string buffer and put its data inside a new t_field
 * @param buffer The string buffer containing raw data
 * @param field_ptr a pointer to the pointer who'll hold the result
 * @return 0 on success, errcode otherwise
 */
int parse_field_buffer(char* buffer, t_field **field_ptr);

int get_row_number(const char *buffer, int *length_ptr, int *iter_ptr);

/**
 * Simple array to int conversion
 * @param str The array to convert
 * @param buffer The buffer who'll hold the result
 * @return 0 on success, errcode otherwise
 */
int a_to_i(char const *str, int* buffer);

int get_symbols(const char *buffer, t_field *field_ptr, int *iter_ptr);

int get_line_size(const char *buffer, int iter, int *line_size_ptr);

#endif //BSQ_BSQ_PARSER_H
