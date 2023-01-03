#include <stdio.h>
#include "bsq_solver.h"

int main(int argc, char **argv) {
    t_field *map;
    int err;

    if(argc == 1 ) {
        err = get_field_std(&map);
        if(err != 0) {
            return err;
        }

        find_best(*map);
        destruct(*map);
    } else {
        for (int i = 1; i < argc ; ++i) {
            if(i>1) {
                printf("----------------------------------------------------------\n");
            }
            err = get_field(argv[i], &map);

            if(err != 0) {
                return err;
            }

            find_best(*map);
            destruct(*map);
        }
    }

    return 0;
}
