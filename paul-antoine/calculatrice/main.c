#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    if(argc != 4) {
        printf("error : invalid number of arguments");
        return 1;
    }
    float arg1 = atof(argv[1]);
    char* operator = argv[2];
    float arg2 = atof(argv[3]);

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
