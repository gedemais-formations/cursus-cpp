#include <stdio.h>
#include <malloc.h>
#include "bsq.h"

int main(int argc, char **argv) {
    t_field **map;
    int map_num = argc == 1 ? 1 : argc - 1;
    int err = 0;

    map = malloc(sizeof(t_field*)*map_num);

    if (map == NULL) {
        return ERROR_CANT_ALLOCATE_MEMORY
    }

    if(argc == 1 ) {
        err = get_field_std(&map[0]);
        if(err != 0) {
            free(map);
            return err;
        }
    } else {
        for (int i = 1; i < argc ; ++i) {
            err = get_field(argv[i], &map[i-1]);

            if(err != 0) {
                free(map);
                return err;
            }
        }
    }

    for (int i = 0; i < map_num ; ++i) {
        find_best(*map[i]);
    }

    return 0;
}
