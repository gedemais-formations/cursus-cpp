#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** dyn_equ;
int dyn_size;
const int MAX_EQU=500;
const int MAX_NUM_CHAR = 20;
const char IGNORE_EQU_CAR = '&';

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

void free_exit(int code) {
    for (int i = 0; i < dyn_size; ++i) {
        free(dyn_equ[i]);
    }
    free(dyn_equ);
    exit(code);
}

int is_digit(char c1, char c2) {
    if(c1 >= '0' && c1 <= '9') {
        return 1;
    } else if(c1 == '-') {
        return is_digit(c2, 'a');
    }

    return 0;
}

/**
 * Get an array of number and operator and return equation result
 * @param equation
 * @param size
 * @return
 */
float resolve_equation(char** equation, int size) {
    int nb_of_parenthesis = 0;
    int parenthesis_start = -1;

    //handle parenthesis
    for (int i = 0; i < size; ++i) {
        if(equation[i][0] == '(') {
            if(nb_of_parenthesis == 0) {
                parenthesis_start = i;
            }
            nb_of_parenthesis++;
        } else if (equation[i][0] == ')') {
            nb_of_parenthesis--;
            if(nb_of_parenthesis == 0 ) {
                sprintf(equation[parenthesis_start],
                          "%.2f", resolve_equation(&equation[parenthesis_start+1],i - parenthesis_start -1) );
                for (int j = parenthesis_start +1; j <= i ; ++j) {
                    equation[j][0] = IGNORE_EQU_CAR;
                    equation[j][1] = '\0';
                }
            } else if(nb_of_parenthesis < 0) {
                printf("Error: Bad pattern\n");
                free_exit(1);
            }
        }
    }

    //remove ignored equation and replace spaces between two numbers by a multiplication
    char n_equation[size][MAX_NUM_CHAR];
    int n_size = 0;
    for (int i = 0; i < size; ++i) {
        if(equation[i][0] != IGNORE_EQU_CAR) {
            if(i>0 && is_digit(equation[i-1][0], equation[i-1][1] ) && is_digit(equation[i][0], equation[i][1])) {
                strcpy(n_equation[n_size],"x");
                n_size++;
            }
            strcpy(n_equation[n_size], equation[i]);
            n_size++;
        }
    }

    //handle division and multiplication
    for (int i = 0; i < n_size; ++i) {
        if(n_equation[i][0] == 'x') {
            int is_negative_number = i < n_size - 2 && n_equation[i+1][0] == '-' && is_digit(n_equation[i+2][0],n_equation[i+2][1]);
            int is_invalid = i == 0 || i == n_size - 1
                    || !is_digit(n_equation[i-1][0],n_equation[i-1][1])
                    || (!is_digit(n_equation[i+1][0],n_equation[i+1][1]) && !is_negative_number);
            if(is_invalid) {
                printf("Error: Bad pattern\n");
                free_exit(1);
            }

            if(is_negative_number){
                float arg1 = atof(n_equation[i-1]);
                float arg2 = -1 * atof(n_equation[i+2]);

                sprintf(n_equation[i+2], "%.2f", arg1 * arg2 );
                n_equation[i-1][0] = IGNORE_EQU_CAR ; n_equation[i-1][1] = '\0';
                n_equation[i][0] = IGNORE_EQU_CAR ; n_equation[i][1] = '\0';
                n_equation[i+1][0] = IGNORE_EQU_CAR ; n_equation[i+1][1] = '\0';
            } else {
                float arg1 = atof(n_equation[i-1]);
                float arg2 = atof(n_equation[i+1]);
                printf("%f * %f = %f \n", arg1, arg2, arg1 * arg2);
                sprintf(n_equation[i+1], "%.2f", arg1 * arg2 );
                n_equation[i-1][0] = IGNORE_EQU_CAR ; n_equation[i-1][1] = '\0';
                n_equation[i][0] = IGNORE_EQU_CAR ; n_equation[i][1] = '\0';
            }
        } else if(n_equation[i][0] == '/') {
            int is_negative_number = i < n_size - 2 && n_equation[i+1][0] == '-' && is_digit(n_equation[i+2][0],n_equation[i+2][1]);
            printf("%i", is_negative_number);
            int is_invalid = i == 0 || i == n_size - 1
                             || !is_digit(n_equation[i-1][0],n_equation[i-1][1])
                             || (!is_digit(n_equation[i+1][0],n_equation[i+1][1]) && !is_negative_number);
            if(is_invalid) {
                printf("Error: Bad pattern\n");
                free_exit(1);
            }

            if(is_negative_number){
                float arg1 = atof(n_equation[i-1]);
                float arg2 = -1 * atof(n_equation[i+2]);
                printf("%f / %f = %f \n", arg1, arg2, arg1 / arg2);
                sprintf(n_equation[i+2], "%.2f", arg1 / arg2 );
                n_equation[i-1][0] = IGNORE_EQU_CAR ; n_equation[i-1][1] = '\0';
                n_equation[i][0] = IGNORE_EQU_CAR ; n_equation[i][1] = '\0';
                n_equation[i+1][0] = IGNORE_EQU_CAR ; n_equation[i+1][1] = '\0';
            } else {
                float arg1 = atof(n_equation[i-1]);
                float arg2 = atof(n_equation[i+1]);
                printf("%f / %f = %f \n", arg1, arg2, arg1 / arg2);
                sprintf(n_equation[i+1], "%.2f", arg1 / arg2 );
                n_equation[i-1][0] = IGNORE_EQU_CAR ; n_equation[i-1][1] = '\0';
                n_equation[i][0] = IGNORE_EQU_CAR ; n_equation[i][1] = '\0';
            }
        }
    }

    //remove ignored equation
    char n2_equation[size][MAX_NUM_CHAR];
    int n2_size = 0;
    for (int i = 0; i < n_size; ++i) {
        if(n_equation[i][0] != IGNORE_EQU_CAR) {
            strcpy(n2_equation[n2_size], n_equation[i]);
            n2_size++;
        }
    }

    //handle addition and subtraction
    for (int i = 0; i < n2_size; ++i) {
        if(n2_equation[i][0] == '-' && n2_equation[i][1] == '\0') {
            if(i==0 && n2_size > 1 && is_digit(n2_equation[1][0],n2_equation[1][1])) {
                float arg1 = -1 * atof(n2_equation[1]);
                sprintf(n2_equation[1], "%.2f", arg1);
                n2_equation[0][0] = IGNORE_EQU_CAR ; n2_equation[0][1] = '\0';
                i++;
            } else {
                if(!is_digit(n2_equation[i-1][0],n2_equation[i-1][1]) || i >= (n2_size - 1) || !is_digit(n2_equation[i+1][0],n2_equation[i+1][1])) {
                    printf("Error: Bad pattern\n");
                    free_exit(1);
                }
                float arg1 = atof(n2_equation[i-1]);
                float arg2 = atof(n2_equation[i+1]);
                sprintf(n2_equation[i+1], "%.2f", arg1 - arg2);
                n2_equation[i-1][0] = IGNORE_EQU_CAR ; n2_equation[i-1][1] = '\0';
                n2_equation[i][0] = IGNORE_EQU_CAR ; n2_equation[i][1] = '\0';
            }
        } else if(n2_equation[i][0] == '+') {
            if(i==0 || !is_digit(n2_equation[i-1][0],n2_equation[i-1][1]) || i >= (n2_size - 1) || !is_digit(n2_equation[i+1][0],n2_equation[i+1][1])) {
                printf("Error: Bad pattern\n");
                free_exit(1);
            }
            float arg1 = atof(n2_equation[i-1]);
            float arg2 = atof(n2_equation[i+1]);
            sprintf(n2_equation[i+1], "%.2f", arg1 + arg2);
            n2_equation[i-1][0] = IGNORE_EQU_CAR ; n2_equation[i-1][1] = '\0';
            n2_equation[i][0] = IGNORE_EQU_CAR ; n2_equation[i][1] = '\0';
        }
    }

    printf("====SOLVING====\n");
    for (int i = 0; i < n2_size; ++i) {
        printf("%s\n", n2_equation[i] );
    }


    return atof(n2_equation[n2_size-1]);
}

int main(int argc, char** argv) {
    // return simple_calc(argc, argv);
    char equation[MAX_EQU][MAX_NUM_CHAR];
    int curr_equ = 0;
    int curr_char = 0;

    //Parsing arguments
    for(int i=1 ; i < argc ; i++) {
        for(int j=0; argv[i][j] != '\0' ; j++) {
            if(curr_equ == MAX_EQU) {
                printf("Error: Max equation to compute reached\n");
                return 1;
            }
            if(argv[i][j] == '/') {
                if(curr_char > 0) {
                    equation[curr_equ][curr_char] = '\0';
                    curr_equ++;
                }
                equation[curr_equ][0] = '/';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == '-') {
                if(curr_char > 0) {
                    equation[curr_equ][curr_char] = '\0';
                    curr_equ++;
                }
                equation[curr_equ][0] = '-';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == '+') {
                if(curr_char > 0) {
                    equation[curr_equ][curr_char] = '\0';
                    curr_equ++;
                }
                equation[curr_equ][0] = '+';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == 'x') {
                if(curr_char > 0) {
                    equation[curr_equ][curr_char] = '\0';
                    curr_equ++;
                }
                equation[curr_equ][0] = 'x';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == '(') {
                if(curr_char > 0) {
                    equation[curr_equ][curr_char] = '\0';
                    curr_equ++;
                }
                equation[curr_equ][0] = '(';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] == ')') {
                if(curr_char > 0) {
                    equation[curr_equ][curr_char] = '\0';
                    curr_equ++;
                }
                equation[curr_equ][0] = ')';
                equation[curr_equ][1] = '\0';
                curr_equ++;
                curr_char=0;
            } else if (argv[i][j] >= '0' &&  argv[i][j] <= '9' || equation[curr_equ][curr_char] == '.') {
                if(curr_char > (MAX_NUM_CHAR -2)) { // -1 because start from 0 and -1 for the \0
                    printf("Error: Max number size reached \n");
                    return 1;
                }
                equation[curr_equ][curr_char] = argv[i][j];
                curr_char++;
            } else {
                printf("Error: %c is invalid character \n", argv[i][j]);
                return 1;
            }
        }
        if(equation[curr_equ][curr_char-1] >= '0' && equation[curr_equ][curr_char-1] <= '9' || equation[curr_equ][curr_char] == '.') {
            equation[curr_equ][curr_char] = '\0';
            curr_char = 0;
            curr_equ++;
        }
    }

    dyn_equ = malloc(sizeof(char*) * curr_equ);
    dyn_size = curr_equ;

    for (int i = 0; i < dyn_size; ++i) {
        dyn_equ[i] = malloc(sizeof(char) * MAX_NUM_CHAR);
        strcpy(dyn_equ[i], equation[i]);
    }

    resolve_equation(dyn_equ, dyn_size);

    free_exit(0);
}

