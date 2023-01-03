//
// Created by pad on 1/3/23.
//

#include <string.h>   // memcpy
#include <malloc.h>   // dyn memory allocation
#include "bsq_parser.h"
#include "bsq_error.h"

bool get_case(t_case* u_case, int global_index) {
    //global index is the bit position inside the t_case array
    //therefore we have to divide by 8 to get the byte index, and then modulo 8 to get the position inside the byte
    t_case curr_case = u_case[global_index/8];
    //position is equivalent to the power of 2 corresponding to the case bit.
    int position = 1 << (global_index % 8);
    return (curr_case.val & position) / position == true;
}

void set_case(t_case *u_case, int global_index, bool value){
    //global index is the bit position inside the t_case array
    //therefore we have to divide by 8 to get the byte index, and then modulo 8 to get the position inside the byte
    t_case* curr_case = &u_case[global_index / 8];
    //position is equivalent to the power of 2 corresponding to the case bit.
    int position = 1 << (global_index%8);
    bool old_value = get_case(u_case, global_index);
    if(value && !old_value ) {
        curr_case->val = curr_case->val + position;
    } else if(!value && old_value) {
        curr_case->val = curr_case->val - position;
    }
}

int parse_field_buffer(char *buffer, t_field **field_ptr) {
    static t_field field;

    int iter = 0;
    int length;

    int err = get_row_number(buffer, &length, &iter);
    if(err != 0) {
        free(buffer);
        return err;
    }
    field.row_size = length;

    err = get_symbols(buffer, &field, &iter);
    if(err != 0) {
        free(buffer);
        return err;
    }

    int line_size;
    err = get_line_size(buffer, iter, &line_size);
    if(err != 0) {
        free(buffer);
        return err;
    }

    field.col_size = line_size;
    field.col_size_byte = line_size/8 + (7+line_size%8)/8;
    field.field = (t_case*) malloc(sizeof(t_case) * length * field.col_size_byte);

    if(field.field == NULL) {
        free(buffer);
        return print_error(ERROR_CANT_ALLOCATE_MEMORY, "");
    }

    for (int i = 0; i < length; ++i) {
        int current_size = 0;
        int current_line = i * field.col_size_byte;

        while (buffer[iter] != '\n' && buffer[iter] != '\0' && current_size < line_size) {

            char current = buffer[iter];

            if(current_size%8==0)
                field.field[current_line + current_size/8].val = 254;

            if(current == field.empty) {
                //printf("here %d\n", current_size);
                //fflush(stdout);
                set_case(&field.field[current_line], current_size, false);
            } else if(current == field.obstacle) {
                set_case(&field.field[current_line], current_size, true);
            } else {
                free(field.field);
                free(buffer);
                return print_error(ERROR_INVALID_PATTERN, "Incorrect character in field");
            }

            // buffer[iter];
            current_size++;
            iter++;
        }

        if(current_size != line_size) {
            free(field.field);
            free(buffer);
            return print_error(ERROR_INVALID_PATTERN, "Line size mismatch");
        }

        if(buffer[iter] != '\0')
            iter++;
    }

    *field_ptr = &field;
    free(buffer);
    return 0;
}

int a_to_i(char const *str, int* buffer) {
    int result=0;

    for (int i = 0 ; str[i] != '\0' ; ++i) {
        if(str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (int) (str[i] - '0');
        } else {
            return 1;
        }
    }

    *buffer=result;

    return 0;
}

int get_line_size(const char *buffer, int iter, int *line_size_ptr) {
    *line_size_ptr = 0;
    int tmp_iter = iter;

    while (buffer[tmp_iter] != '\n' && buffer[tmp_iter] != '\0') {
        (*line_size_ptr)++;
        tmp_iter++;
    }

    if(*line_size_ptr == 0) {
        return print_error(ERROR_INVALID_PATTERN, "Line too short (min 1 character)");
    }
    return 0;
}

int get_symbols(const char *buffer, t_field *field_ptr, int *iter_ptr) {
    if(buffer[*iter_ptr] != '\n' && buffer[*iter_ptr] != '\r') {
        field_ptr->empty = buffer[*iter_ptr];
        (*iter_ptr)++;
    } else {
        return print_error(ERROR_INVALID_PATTERN, "Empty character missing");
    }

    if(buffer[*iter_ptr] != '\n' && buffer[*iter_ptr] != '\r') {
        field_ptr->obstacle = buffer[*iter_ptr];
        (*iter_ptr)++;
    } else {
        return print_error(ERROR_INVALID_PATTERN, "Obstacle character missing");
    }

    if(buffer[*iter_ptr] != '\n' && buffer[*iter_ptr] != '\r') {
        field_ptr->full = buffer[*iter_ptr];
        (*iter_ptr)++;
    } else {
        return print_error(ERROR_INVALID_PATTERN, "Full character missing");
    }

    if(buffer[*iter_ptr] == '\n' || buffer[*iter_ptr] == '\r') {
        (*iter_ptr)++;
    } else {
        return print_error(ERROR_INVALID_PATTERN, "First line too long");
    }

    if(field_ptr->obstacle == field_ptr->empty
    || field_ptr->obstacle == field_ptr->full
    || field_ptr->full == field_ptr->empty) {
        return print_error(ERROR_INVALID_PATTERN, "Two symbol are identical");
    }

    return 0;
}

int get_row_number(const char *buffer, int *length_ptr, int *iter_ptr) {
    *iter_ptr=0;
    char *length_chr = malloc(sizeof(char));
    while (buffer[*iter_ptr] <= '9' && buffer[*iter_ptr] >= '0' ) {
        length_chr[*iter_ptr] = buffer[*iter_ptr];
        (*iter_ptr)++;
        length_chr = realloc(length_chr, sizeof(char) * (*iter_ptr + 1));
        if(length_chr == NULL) {
            return print_error(ERROR_CANT_ALLOCATE_MEMORY, "");
        }
    }
    if(buffer[*iter_ptr] != '\n' && buffer[*iter_ptr] != '\r') {
        length_chr[*iter_ptr] = '\0';
    } else if(*iter_ptr >= 4) {
        *iter_ptr -= 3;
        length_chr[*iter_ptr] = '\0';
    } else {
        free(length_chr);
        return print_error(ERROR_INVALID_PATTERN, "1st line is too short");
    }


    if(*iter_ptr==0) {
        free(length_chr);
        return print_error(ERROR_INVALID_PATTERN, "Number of row not found");
    }

    int err = a_to_i(length_chr, length_ptr);

    free(length_chr);
    if(err != 0) {
        return print_error(ERROR_INVALID_PATTERN, "Can't convert number of row");
    }

    return 0;
}
