//
// Created by pad on 12/20/22.
//
#include "bsq.h"
#include <fcntl.h> //open
#include <unistd.h> //read
#include <sys/stat.h> // get file stat
#include <malloc.h> // dyn memory allocation
#include <stdio.h>
#include <string.h> // memcpy
#include <math.h>

bool get_case(t_case u_case, int i) {
    return (u_case.val & (int) pow(2,i)) / pow(2,i) == true;
}

void set_case(t_case *u_case, int i, bool value){
    if(value && !(get_case(*u_case, i))) {
        u_case->val = u_case->val + (int) pow(2, i);
    } else if(!value && get_case(*u_case, i)) {
        u_case->val = u_case->val - (int) pow(2, i);
    }
}

int get_field(char* file, t_field **field_ptr) {
    int fileDescriptor = open(file, O_RDONLY);

    if (fileDescriptor == -1 ) {
        printf("i'mhere!");
        return ERROR_CANT_OPEN_FILE
    }

    struct stat file_stat;
    int err = stat(file, &file_stat);

    if(err != 0) {
        return ERROR_CANT_READ_FILE
    }

    char* buffer = malloc(file_stat.st_size);

    if(buffer == NULL) {
        return ERROR_CANT_ALLOCATE_MEMORY
    }

    ssize_t byteRead = read(fileDescriptor, buffer, file_stat.st_size);

    if(byteRead == -1 ){
        free(buffer);
        return ERROR_CANT_READ_FILE
    }

    close(fileDescriptor);

    return parse(buffer, field_ptr);

}

int get_field_std(t_field ** field_pointer) {
#define BATCH_SIZE 100
    char *buffer;
    long total=0;
    long batch;
    do {
        char* tmp_buff = malloc(sizeof(char) * BATCH_SIZE);
        batch = read(0, tmp_buff, BATCH_SIZE);

        if(total==0) {
            buffer = tmp_buff;
            total += batch;
        } else if(batch != 0) {
            char* new_buff = malloc(sizeof(char) * (total + batch));
            memcpy(new_buff, buffer, total);
            free(buffer);
            memcpy(&new_buff[total], tmp_buff, batch);
            free(tmp_buff);
            buffer = new_buff;
        }
    } while (batch >= BATCH_SIZE);

    parse(buffer, field_pointer);

    return 0;
}

int parse(char *buffer, t_field **field_ptr) {
    static t_field field;

    int iter = 0;
    char length_chr[20] = "";
    while (buffer[iter] <= '9' && buffer[iter] >= '0' ) {
        length_chr[iter] = buffer[iter];
        iter++;
    }

    if(iter==0) {
        free(buffer);
        return ERROR_INVALID_PATTERN
    }

    int length;
    a_to_i(length_chr, &length);
    field.row_size = length;

    if(buffer[iter] != '\n' && buffer[iter] != '\r') {
        field.empty = buffer[iter];
        iter++;
    } else {
        free(buffer);
        return ERROR_INVALID_PATTERN
    }

    if(buffer[iter] != '\n' && buffer[iter] != '\r') {
        field.obstacle = buffer[iter];
        iter++;
    } else {
        free(buffer);
        return ERROR_INVALID_PATTERN
    }

    if(buffer[iter] != '\n' && buffer[iter] != '\r') {
        field.full = buffer[iter];
        iter++;
    } else {
        free(buffer);
        return ERROR_INVALID_PATTERN
    }

    if(buffer[iter] == '\n' || buffer[iter] == '\r') {
        iter++;
    } else {
        free(buffer);
        return ERROR_INVALID_PATTERN
    }

    int line_size = 0;
    int tmp_iter = iter;
    while (buffer[tmp_iter] != '\n' && buffer[tmp_iter] != '\0') {
        line_size++;
        tmp_iter++;
    }

    if(line_size == 0) {
        free(buffer);
        return ERROR_INVALID_PATTERN
    }

    field.col_size = line_size;
    field.field = malloc(sizeof(void *) * length);

    for (int i = 0; i < length; ++i) {
        int current_size = 0;
        //allocate the smallest multiple of 8 superior to line_size
        field.field[i] = malloc(line_size/8 + (7+line_size%8)/8);

        if (field.field[i] == NULL) {
            for (int j = 0; j < i; ++j) {
                free(field.field[j]);
            }
            free(field.field);
            free(buffer);
            return ERROR_CANT_ALLOCATE_MEMORY
        }

        while (buffer[iter] != '\n' && buffer[iter] != '\0' && current_size < line_size) {

            char current = buffer[iter];

            if(current_size%8==0)
                field.field[i][current_size/8].val = 0;

            if(current == field.empty) {
                //printf("here %d\n", current_size);
                //fflush(stdout);
                set_case(&field.field[i][current_size/8], current_size%8, false);
            } else if(current == field.obstacle) {
                set_case(&field.field[i][current_size/8], current_size%8, true);
            } else {
                for (int j = 0; j < i; ++j) {
                    free(field.field[j]);
                }
                free(field.field);
                free(buffer);
                return ERROR_INVALID_PATTERN
            }

            // buffer[iter];
            current_size++;
            iter++;
        }

        if(current_size != line_size) {
            for (int j = 0; j < i; ++j) {
                free(field.field[j]);
            }
            free(field.field);
            free(buffer);
            return ERROR_INVALID_PATTERN
        }

        if(buffer[iter] != '\0')
            iter++;
    }

    *field_ptr = &field;
    free(buffer);
    return 0;
}

void print_field(t_field field, int size, int row, int col) {

    for (int i = 0; i < field.row_size; ++i) {
        for (int j = 0; j < field.col_size; ++j) {
            if(i>=row && i < (row + size) && j >= col && j < (col + size)) {
                printf("%c", field.full);
            }else if(get_case(field.field[i][j/8],j%8)) {
                printf("%c", field.obstacle);
            } else {
                printf("%c", field.empty);
            }

        }
        printf("\n");
    }
}

int square_size(t_field field,int row, int col) {
    int i;
    for (i = 1; i + row < field.row_size && i + col < field.col_size ; ++i) {
        for (int j = 0; j < i*i; ++j) {
            int byte_col = j%i+col;
            if(get_case(field.field[j/i+row][byte_col/8], byte_col%8) ){
                return i-1;
            }
        }
    }

    return i-1;
}

void find_best(t_field field) {
    int best = 0;
    int best_col=0, best_row=0;

    for (int i = 0; i < field.row_size; ++i) {
        for (int j = 0; j < field.col_size; ++j) {
            int n_best = square_size(field,i,j);
            if(n_best > best) {
                best = n_best;
                best_row = i;
                best_col = j;
            }
        }
    }

    print_field(field, best, best_row, best_col);
}

void destruct(t_field field) {
    for (int i = 0; i < field.row_size; ++i) {
        free(field.field[i]);
    }

    free(field.field);
}

int a_to_i(char const *str, int* buffer) {
    int result=0;

    for (int i = 0 ; str[i] != '\0' ; ++i) {
        if(str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (int) (str[i] - '0');
        } else {
            return ERROR_INVALID_PATTERN
        }
    }

    *buffer=result;

    return 0;
}