#include "main.h"

int bsq(char *file_name){
  t_file bsq_file;
  
  memset(&bsq_file, 0, sizeof(bsq_file));

  if(get_map(&bsq_file, file_name)){
    printf("Error in get_map");
    return(-1);
  }

  solve(&bsq_file);

  free_bsq(&bsq_file);
  
  return (0);
}