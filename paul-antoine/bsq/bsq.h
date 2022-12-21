//
// Created by pad on 12/20/22.
//

#ifndef BSQ_BSQ_H
#define BSQ_BSQ_H

#endif //BSQ_BSQ_H
#include <stdbool.h>

#define ERROR_CANT_OPEN_FILE (-1);
#define ERROR_CANT_READ_FILE (-2);
#define ERROR_INVALID_PATTERN (-3);
#define ERROR_CANT_ALLOCATE_MEMORY (-4);






typedef struct {
    unsigned char val;
}t_case;


typedef struct {
    int row_size;
    int col_size;
    char empty, obstacle, full;
    t_case** field;
} t_field;

bool get_case(t_case u_case, int i);
void set_case(t_case *u_case, int i, bool value);

int get_field(char* file, t_field **field_ptr);
int get_field_std(t_field **field_ptr);

int parse(char* buffer, t_field **field_pointer);

void print_field(t_field field, int size, int row, int col);

int square_size(t_field field,int row, int col);

void find_best(t_field field);

void destruct(t_field field);

int a_to_i(char const *str, int* buffer);