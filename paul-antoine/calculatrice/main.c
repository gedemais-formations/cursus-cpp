#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {

    if(argc != 4) {
        printf("Nombre d'argument incorrect 3 arguments attendus");
        return 1;
    }
    float arg1 = atof(argv[1]);
    char* operator = argv[2];
    float arg2 = atof(argv[3]);

    if(strcmp("+", operator) == 0) {
        printf("%f + %f = %f", arg1, arg2, arg1 + arg2);
    } else if(strcmp("*", operator) == 0) {
        printf("%f * %f = %f", arg1, arg2, arg1 * arg2);
    } else if(strcmp("/", operator) == 0) {
        printf("%f / %f = %f", arg1, arg2, arg1 / arg2);
    } else if(strcmp("-", operator) == 0) {
        printf("%f - %f = %f", arg1, arg2, arg1 - arg2);
    } else {
        printf("%s n'est pas un opérateur valide", operator);
    }

    return 0;
}
