#include <stdio.h>
#include <malloc.h>
#include "bsq.h"

int main(int argc, char **argv) {
    t_field **map;
    int err = 0;
    if(argc == 1 ) {
        map = malloc(sizeof(t_field*));
        if (map == NULL) {
            return ERROR_CANT_ALLOCATE_MEMORY
        }

        err = get_field_std(&map[0]);

        if(err != 0) {
            free(map);
            return err;
        }

    } else {
        map = malloc(sizeof(t_field*) * (argc-1));

        if (map == NULL) {
            return ERROR_CANT_ALLOCATE_MEMORY
        }
        for (int i = 1; i < argc; ++i) {
            err = get_field(argv[i], &map[i-1]);

            if(err != 0) {
                free(map);
                return err;
            }
        }
    }

    print_field(*map[0]);

    return 0;
}
