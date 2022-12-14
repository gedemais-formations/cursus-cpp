#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int simple_calc(int argc, char** argv) {
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

int main(int argc, char** argv) {
    // return simple_calc(argc, argv);
    char equation[500][20];
    int curr_equ = 0;
    int curr_char = 0;

    for(int i=1 ; i < argc ; i++) {
        for(int j=0; argv[i][j] != '\0' ; j++) {
            if(argv[i][j] == '/') {
                equation[curr_equ][curr_char] = '\0';
                curr_equ++;
                equation[curr_equ][0] = '/';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == '-') {
                equation[curr_equ][curr_char] = '\0';
                curr_equ++;
                equation[curr_equ][0] = '-';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == '+') {
                equation[curr_equ][curr_char] = '\0';
                curr_equ++;
                equation[curr_equ][0] = '+';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == 'x') {
                equation[curr_equ][curr_char] = '\0';
                curr_equ++;
                equation[curr_equ][0] = 'x';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == '(') {
                equation[curr_equ][curr_char] = '\0';
                curr_equ++;
                equation[curr_equ][0] = '(';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == ')') {
                equation[curr_equ][curr_char] = '\0';
                curr_equ++;
                equation[curr_equ][0] = ')';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] >= '0' &&  argv[i][j] <= '9' || equation[curr_equ][curr_char] == '.') {
                equation[curr_equ][curr_char] = argv[i][j];
                curr_char++;
            } else {
                printf("Error: %c is invalid character", argv[i][j]);
                return 1;
            }
        }
        if(equation[curr_equ][curr_char-1] >= '0' && equation[curr_equ][curr_char-1] <= '9' || equation[curr_equ][curr_char] == '.') {
            equation[curr_equ][curr_char] = '\0';
            curr_char = 0;
            curr_equ++;
        }
    }


    for(int i=0 ; i<500 ; i++) {
        printf("%s \n", equation[i]);
    }

    return 0;
}
