#include <stdio.h>
#include "bsq.h"

int main(int argc, char **argv) {
    t_field *map;

    if(argc == 1 ) {

    }

    int test = get_field(argv[1], &map);

    if(test != 0) {
        return test;
    }

    print_field(*map);

    return 0;
}
