//
// Created by pad on 1/3/23.
//

#include <errno.h>    // errno
#include <malloc.h>   // dyn memory allocation
#include <unistd.h>   //read write
#include "../include/bsq_error.h"

int print_error(int errcode, const char* context) {
    const char* ERRORS_MESSAGES[6] = {
            "",
            "Error : Can't open % \n",
            "Error : Can't read % \n",
            "Error : invalid pattern % \n",
            "Error : not enough memory \n",
            "Error : Invalid error code \n"
    };
    char result[100];
    if(errcode > 4 || errcode < 1) {
        errcode = 5;
    }
    const char* err_msg = ERRORS_MESSAGES[errcode];
    int iter_err = 0;
    int iter_context = 0;
    int iter_res = 0;
    for (; iter_res < 99 ; ++iter_res) {
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