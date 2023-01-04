//
// Created by pad on 12/20/22.
//
#include "bsq_solver.h"
#include "bsq_error.h"
#include <fcntl.h>    //open
#include <unistd.h>   //read write
#include <stdio.h>    // fflush
#include <sys/stat.h> // get file stat
#include <malloc.h>   // dyn memory allocation
#include <string.h>   // memcpy



int get_field(char* file, t_field **field_ptr) {
    int fileDescriptor = open(file, O_RDONLY);

    if (fileDescriptor == -1 ) {
        return print_error(ERROR_CANT_OPEN_FILE, file);
    }

    struct stat file_stat;
    int err = stat(file, &file_stat);

    if(err != 0) {
        close(fileDescriptor);
        return print_error(ERROR_CANT_READ_FILE, file);
    }

    char* buffer = malloc(file_stat.st_size);

    if(buffer == NULL) {
        close(fileDescriptor);
        return print_error(ERROR_CANT_ALLOCATE_MEMORY, "");
    }

    ssize_t byteRead = read(fileDescriptor, buffer, file_stat.st_size);

    if(byteRead == -1 ){
        free(buffer);
        close(fileDescriptor);
        return print_error(ERROR_CANT_READ_FILE, file);
    }

    close(fileDescriptor);

    return parse_field_buffer(buffer, field_ptr);

}

int get_field_std(t_field ** field_pointer) {
    //max batch size on vm tty is 8192, higher value might still only read 8192Bytes
#define BATCH_SIZE 8192
    char *buffer = "";
    long total=0;
    long batch;
    int count = 0;
    do {
        count++;
        char* tmp_buff = malloc(sizeof(char) * BATCH_SIZE);
        if(tmp_buff == NULL) {
            if(count > 1) free(buffer);
            return print_error(ERROR_CANT_ALLOCATE_MEMORY, "");
        }
        fflush(stdin);
        batch = read(0, tmp_buff, BATCH_SIZE);
        /*if(batch < BATCH_SIZE ) {
            printf("%ld %d\n", batch, count);
        }*/
        if(batch == -1 ) {
            if(count > 1) free(buffer);
            return print_error(ERROR_CANT_READ_FILE, "stdin");
        }

        if(total==0) {
            buffer = tmp_buff;
            total += batch;
        } else if(batch != 0) {
            char* new_buff = malloc(sizeof(char) * (total + batch));
            if(new_buff == NULL) {
                free(buffer);
                free(tmp_buff);
                return print_error(ERROR_CANT_ALLOCATE_MEMORY, "");
            }
            memcpy(new_buff, buffer, total);
            free(buffer);
            memcpy(&new_buff[total], tmp_buff, batch);
            free(tmp_buff);
            buffer = new_buff;
            total += batch;
        }
    } while (batch >= BATCH_SIZE);

    //printf(buffer);
    return parse_field_buffer(buffer, field_pointer);
}

void print_field(t_field field, int found_size, int found_row, int found_col) {
    int buffer_size = field.row_size * (field.col_size + 1) + 1;
    char* buffer = malloc(sizeof(char) * buffer_size);

    for (int i = 0; i < field.row_size; ++i) {
        for (int j = 0; j < field.col_size; ++j) {
            if(get_case(&field.field[i * field.col_size_byte],j)) {
                buffer[i * (field.col_size + 1) + j ] = field.obstacle;
            }else if(i >= found_row && i < (found_row + found_size) && j >= found_col && j < (found_col + found_size)) {
                buffer[i * (field.col_size + 1) + j ] = field.full;
            } else {
                buffer[i * (field.col_size + 1) + j ] = field.empty;
            }
        }
        buffer[(i+1) * (field.col_size + 1) -1 ] = '\n';
    }
    buffer[buffer_size - 1]= '\0';

    write(1,buffer, buffer_size );

    free(buffer);
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

