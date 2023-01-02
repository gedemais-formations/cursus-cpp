#include <stdio.h>
#include "bsq.h"

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
            err = get_field(argv[i], &map);

            if(err != 0) {
                return err;
            }

            find_best(*map);
            printf("----------------------------------------------------------\n");
            destruct(*map);
        }
    }

    return 0;
}
