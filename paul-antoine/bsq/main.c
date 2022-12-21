#include <stdio.h>
#include <malloc.h>
#include "bsq.h"

int main(int argc, char **argv) {
    t_field **map;
    int map_num = argc == 1 ? 1 : argc - 1;
    int err;

    map = malloc(sizeof(t_field*)*map_num);

    if (map == NULL) {
        return ERROR_CANT_ALLOCATE_MEMORY
    }
    printf("%d\n", argc);
    if(argc == 1 ) {
        err = get_field_std(&map[0]);
        if(err != 0) {
            free(map);
            return err;
        }

        find_best(*map[0]);
    } else {
        for (int i = 1; i < argc ; ++i) {
            err = get_field(argv[i], &map[i-1]);

            if(err != 0) {
                free(map);
                return err;
            }

            find_best(*map[i-1]);
            printf("----------------------------------------------------------\n");
            destruct(*map[i-1]);
        }
    }

/*    for (int i = 0; i < map_num; ++i) {
        destruct(*map[i]);
    }*/
    free(map);

    return 0;
}
