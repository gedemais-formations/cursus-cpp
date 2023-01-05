//
// Created by pad on 1/5/23.
//

#include "../include/error.h"

#include <errno.h>    // errno
#include <malloc.h>   // dyn memory allocation
#include <unistd.h>   //read write

int print_error(int errcode, const char* err_msg, const char* context) {
#define MAX_BUFF 250
    char result[MAX_BUFF];
    int iter_err = 0;
    int iter_context = 0;
    int iter_res = 0;
    for (; iter_res < MAX_BUFF-1 ; ++iter_res) {
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