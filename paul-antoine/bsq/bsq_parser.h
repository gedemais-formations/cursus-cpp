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

/**
 * Get the number of row from the buffer
 * @param buffer The buffer to parse
 * @param length_ptr Ptr to the variable who'll hold the number of row
 * @param iter_ptr Ptr to the buffer iterator
 * @return 0 on success, errcode otherwise
 */
int get_row_number(const char *buffer, int *length_ptr, int *iter_ptr);

/**
 * Simple array to int conversion
 * @param str The array to convert
 * @param buffer The buffer who'll hold the result
 * @return 0 on success, errcode otherwise
 */
int a_to_i(char const *str, int* buffer);

/**
 * Get symbols from the buffer and put them in field_ptr's t_field
 * @param buffer The buffer to parse
 * @param field_ptr Pointer to the updated field
 * @param iter_ptr Buffer iterator !! should point to the first symbol
 * otherwise the function will fail or have unexpected behavior !!
 * @return 0 on success, errcode otherwise
 */
int get_symbols(const char *buffer, t_field *field_ptr, int *iter_ptr);

/**
 * Get from the buffer number of column inside field lines
 * @param buffer The buffer to parse
 * @param iter Buffer iterator !! should point to the first symbol of a line
 * otherwise the function will fail or have unexpected behavior !!
 * @param line_size_ptr Pointer to the variable who'll old line size value
 * @return 0 on success, errcode otherwise
 */
int get_line_size(const char *buffer, int iter, int *line_size_ptr);

/**
 * @param tested_char the character to test
 * @param charset Set of characters to test it with
 * @return Return true if tested_char is in charset
 */
bool isSplit(char tested_char, const char* charset);

/**
 * extract a string from s starting at start index and ending at end index
 * @param s String to cut
 * @param start start index (included)
 * @param end end index (excluded)
 * @return The extracted substring, NULL pointer in case of error
 */
char* ft_substr(const char* s, int start, int end);

/**
 * Split a string into an array of string using charset as a list of separators
 * @param s String to split
 * @param charset List of separators
 * @return An array of strings with an empty string at its last index. NULL pointer in case of error
 */
char** ft_split(const char* s, const char* charset);

#endif //BSQ_BSQ_PARSER_H
