//
// Created by pad on 12/20/22.
//
#include "bsq.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // memcpy


int get_field(char* file, t_field **field_ptr) {
    int fileDescriptor = open(file, O_RDONLY);

    if (fileDescriptor == -1 ) {
        return ERROR_CANT_OPEN_FILE
    }

    struct stat file_stat;
    int err = stat(file, &file_stat);

    if(err != 0) {
        return ERROR_CANT_READ_FILE
    }

    char* buffer = malloc(file_stat.st_size);

    if(buffer == NULL) {
        return ERROR_CANT_ALLOCATE_MEMORY;
    }

    ssize_t byteRead = read(fileDescriptor, buffer, file_stat.st_size);

    if(byteRead == -1 ){
        free(buffer);
        return ERROR_CANT_READ_FILE
    }

    return parse(buffer, field_ptr);

}

int get_field_std(t_field ** field_pointer) {
#define BATCH_SIZE 1000
    char *buffer;
    int total=0, batch;
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
    char length_chr[20];
    while (buffer[iter] <= '9' && buffer[iter] >= '0' ) {
        length_chr[iter] = buffer[iter];
        iter++;
    }

    if(iter==0) {
        free(buffer);
        return ERROR_INVALID_PATTERN
    }

    int length = atoi(length_chr);
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
    field.field = malloc(sizeof (t_case *) * length);

    for (int i = 0; i < length; ++i) {
        int current_size = 0;
        //allocate the smallest multiple of 8 superior to line_size
        field.field[i] = malloc(line_size/8 + (7 + line_size%8)/8);

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

            if(current == field.empty) {
                field.field[i][current_size].t_case = false;
            } else if(current == field.obstacle) {
                field.field[i][current_size].t_case = true;
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

void print_field(t_field field) {

    for (int i = 0; i < field.row_size; ++i) {
        for (int j = 0; j < field.col_size; ++j) {
            if(field.field[i][j].t_case) {
                printf("%c", field.obstacle);
            } else {
                printf("%c", field.empty);
            }

        }
        printf("\n");
    }
}