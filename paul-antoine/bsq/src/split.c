//
// Created by pad on 1/4/23.
//
#include "../include/bsq_parser.h"
#include <stdio.h>

int main(int argc, char** argv) {
    if(argc != 3) return 1;

    char* charset = argv[1];
    char* text = argv[2];

    char** test = ft_split(text, charset);

    int i = 0;
    while (test[i][0] != '\0') {
        printf("%s\n", test[i]);
        i++;
    }
    return 0;
}