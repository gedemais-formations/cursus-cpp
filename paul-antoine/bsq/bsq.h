//
// Created by pad on 12/20/22.
//

#ifndef BSQ_BSQ_H
#define BSQ_BSQ_H

#endif //BSQ_BSQ_H


#define ERROR_CANT_OPEN_FILE (-1);
#define ERROR_CANT_READ_FILE (-2);
#define ERROR_INVALID_PATTERN (-3);
#define ERROR_CANT_ALLOCATE_MEMORY (-4);






typedef struct {
    unsigned char t_case : 1;
}t_case;


typedef struct {
    int row_size;
    int col_size;
    char empty, obstacle, full;
    t_case** field;
} t_field;

int get_field(char* file, t_field **field_ptr);
int get_field_std(t_field **field_ptr);

int parse(char* buffer, t_field **field_pointer);


void print_field(t_field field);