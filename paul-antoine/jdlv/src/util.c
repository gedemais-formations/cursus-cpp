//
// Created by pad on 1/5/23.
//

#include "../include/util.h"
#include "../include/error.h"

int a_to_i(char const *str, int* buffer) {
    int result=0;

    for (int i = 0 ; str[i] != '\0' ; ++i) {
        if(str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (int) (str[i] - '0');
        } else {
            return print_error(ERROR_NAN, str);
        }
    }

    *buffer=result;

    return 0;
}