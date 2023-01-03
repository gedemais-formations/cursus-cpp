//
// Created by pad on 12/20/22.
//
#include "bsq.h"
#include <fcntl.h>    //open
#include <unistd.h>   //read write
#include <sys/stat.h> // get file stat
#include <malloc.h>   // dyn memory allocation
#include <stdio.h>    // printf
#include <string.h>   // memcpy
#include <errno.h>    // errno




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

int parse_field_buffer(char *buffer, t_field **field_ptr) {
    static t_field field;

    int iter = 0;
    char length_chr[20] = "";
    while (buffer[iter] <= '9' && buffer[iter] >= '0' ) {
        length_chr[iter] = buffer[iter];
        iter++;
    }

    if(iter==0) {
        free(buffer);
        return print_error(ERROR_INVALID_PATTERN, "");
    }

    int length;
    a_to_i(length_chr, &length);
    field.row_size = length;

    if(buffer[iter] != '\n' && buffer[iter] != '\r') {
        field.empty = buffer[iter];
        iter++;
    } else {
        free(buffer);
        return print_error(ERROR_INVALID_PATTERN, "");
    }

    if(buffer[iter] != '\n' && buffer[iter] != '\r') {
        field.obstacle = buffer[iter];
        iter++;
    } else {
        free(buffer);
        return print_error(ERROR_INVALID_PATTERN, "");
    }

    if(buffer[iter] != '\n' && buffer[iter] != '\r') {
        field.full = buffer[iter];
        iter++;
    } else {
        free(buffer);
        return print_error(ERROR_INVALID_PATTERN, "");
    }

    if(buffer[iter] == '\n' || buffer[iter] == '\r') {
        iter++;
    } else {
        free(buffer);
        return print_error(ERROR_INVALID_PATTERN, "");
    }

    int line_size = 0;
    int tmp_iter = iter;
    while (buffer[tmp_iter] != '\n' && buffer[tmp_iter] != '\0') {
        line_size++;
        tmp_iter++;
    }

    if(line_size == 0) {
        free(buffer);
        return print_error(ERROR_INVALID_PATTERN, "");
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
            print_error(ERROR_CANT_ALLOCATE_MEMORY, "");
            return ERROR_CANT_ALLOCATE_MEMORY;
        }

        while (buffer[iter] != '\n' && buffer[iter] != '\0' && current_size < line_size) {

            char current = buffer[iter];

            if(current_size%8==0)
                field.field[i][current_size/8].val = 254;

            if(current == field.empty) {
                //printf("here %d\n", current_size);
                //fflush(stdout);
                set_case(field.field[i], current_size, false);
            } else if(current == field.obstacle) {
                set_case(field.field[i], current_size, true);
            } else {
                for (int j = 0; j < i; ++j) {
                    free(field.field[j]);
                }
                free(field.field);
                free(buffer);
                return print_error(ERROR_INVALID_PATTERN, "");
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
            return print_error(ERROR_INVALID_PATTERN, "");
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
            if(get_case(field.field[i],j)) {
                printf("%c", field.obstacle);
            }else if(i>=row && i < (row + size) && j >= col && j < (col + size)) {
                printf("%c", field.full);
            } else {
                printf("%c", field.empty);
            }

        }
        printf("\n");
    }
}

int square_size(t_field field,int row, int col, int min_square) {
    int i;

    for (i = min_square; i + row < field.row_size +1 && i + col < field.col_size +1 ; ++i) {
        for (int j = 0; j < i*i; ++j) {
            int byte_col = j%i+col;
            if(get_case(field.field[j/i+row], byte_col) ){
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

int skip_cases(t_field *field, int i, int j, int n_best) {
    int skip = !n_best?0:n_best - 1;
    int last_line = i + n_best;
    if(last_line < (*field).row_size) {
        for (int k = j; k < (j+n_best) && k < (*field).col_size; k++) {
            if(get_case((*field).field[last_line], k)) {
                skip = k - j;
                break;
            }
        }
        j += skip;
    }
    return j;
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
            return print_error(ERROR_INVALID_PATTERN, "");
        }
    }

    *buffer=result;

    return 0;
}

int print_error(int errcode, const char* context) {
    const char* ERRORS_MESSAGES[5] = {
            "SUCCESS\n",
            "Error : Can't open % \n",
            "Error : Can't read % \n",
            "Error : invalid pattern \n",
            "Error : not enough memory \n"
    };
    char result[100];
    const char* err_msg = ERRORS_MESSAGES[errcode];
    int iter_err = 0;
    int iter_context = 0;
    int iter_res = 0;
    for (; iter_res < 99; ++iter_res) {
        if(err_msg[iter_err] != '%' && err_msg[iter_err] != '\0') {
            result[iter_res] = err_msg[iter_err];
            iter_err++;
        } else if (err_msg[iter_err] == '%') {
            if(context[iter_context] != '\0') {
                result[iter_res] = context[iter_context];
                iter_context++;
            } else {
                iter_err++;
                iter_res--;
            }
        } else {
            break;
        }
    }


    result[iter_res] = '\0';

    if(errno != 0)
        perror(result);
    else
        write(2, result, iter_res);

    return errcode;
}