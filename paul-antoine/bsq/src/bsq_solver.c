//
// Created by pad on 12/20/22.
//
#include "../include/bsq_solver.h"
#include "../include/bsq_error.h"

#include <unistd.h>   //read write
#include <malloc.h>   // dyn memory allocation


void print_field(t_field field, int found_size, int found_row, int found_col) {
#define PRINT_BUFFER_SIZE 100000
    //int maxSize = field.row_size * (field.col_size + 1) + 1;
    char buffer[PRINT_BUFFER_SIZE] = "";
    int count = 0;

    for (int i = 0; i < field.row_size; ++i) {
        for (int j = 0; j < field.col_size; ++j) {
            count++;
            if(get_case(&field.field[i * field.col_size_byte],j)) {
                buffer[count] = field.obstacle;
            }else if(i >= found_row && i < (found_row + found_size) && j >= found_col && j < (found_col + found_size)) {
                buffer[count] = field.full;
            } else {
                buffer[count] = field.empty;
            }
            if(count >= PRINT_BUFFER_SIZE - 1) {
                buffer[count] = '\0';
                write(1, buffer, count+1 );
                count = 0;
            }
        }
        if(count >= PRINT_BUFFER_SIZE - 2) {
            buffer[count+1] = '\n';
            buffer[count+2] = '\0';
            write(1, buffer, count+2 );
            count = 0;
        } else {
            count++;
            buffer[count] = '\n';
        }
    }

    if(count != 0) {
        buffer[count+1] = '\0';
        write(1, buffer, count+1 );
    }
}

int square_size(t_field field,int row, int col, int min_square) {
    int i;

    for (i = min_square; i + row < field.row_size +1 && i + col < field.col_size +1 ; ++i) {
        for (int j = 0; j < i*i; ++j) {
            int byte_col = j%i+col;
            if(get_case(&field.field[(j/i+row) * field.col_size_byte], byte_col) ){
                return byte_col - col;
            }
        }
    }

    return i-1;
}
//#include <stdlib.h> //system
void find_best(t_field field) {
    int best = 0;
    int best_col=0, best_row=0;

    for (int i = 0; i < field.row_size; i++) {
        for (int j = 0; j < field.col_size; j++) {
            int n_best = square_size(field, i, j, best-1);
            
            //system("clear");
            //print_field(field,n_best, i, j);
            //sleep(1);
            if(n_best > best) {
                best = n_best;
                best_row = i;
                best_col = j;
            }
            j = skip_cases(&field, i, j, n_best);
        }
    }

    print_field(field, best, best_row, best_col);
}

int skip_cases(t_field *field, int seek_row, int seek_col, int seek_size) {
    int skip = !seek_size ? 0 : seek_size - 1;
    int last_line = seek_row + seek_size;
    if(last_line < (*field).row_size) {
        for (int k = seek_col; k < (seek_col + seek_size) && k < (*field).col_size; k++) {
            if(get_case(&(*field).field[last_line * field->col_size_byte], k)) {
                skip = k - seek_col;
                break;
            }
        }
        seek_col += skip;
    }
    return seek_col;
}

void destruct(t_field field) {
    free(field.field);
}

