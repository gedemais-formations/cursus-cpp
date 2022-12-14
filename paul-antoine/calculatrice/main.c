#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    if(argc != 4) {
        printf("error : invalid number of arguments \n");
        return 1;
    }
    char* test = NULL;
    float arg1 = strtof(argv[1], &test);
    if(!test || *test) {
        printf("error : %s is not a valid number \n", argv[1]);
        return 1;
    }

    char* operator = argv[2];

    test = NULL;
    float arg2 = strtof(argv[3], &test);
    if(!test || *test) {
        printf("error : %s is not a valid number \n", argv[3]);
        return 1;
    }

    if(strcmp("+", operator) == 0) {
        printf("%.2f + %.2f = %.2f \n", arg1, arg2, arg1 + arg2);
    } else if(strcmp("*", operator) == 0) {
        printf("%.2f * %.2f = %.2f \n", arg1, arg2, arg1 * arg2);
    } else if(strcmp("/", operator) == 0) {
        printf("%.2f / %.2f = %.2f \n", arg1, arg2, arg1 / arg2);
    } else if(strcmp("-", operator) == 0) {
        printf("%.2f - %.2f = %.2f \n", arg1, arg2, arg1 - arg2);
    } else {
        printf("error : invalid operator %s \n", operator);
        return 1;
    }

    return 0;
}
