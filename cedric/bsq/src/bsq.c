#include "bsq.h"

int bsq(char *file_name){
  t_file bsq_file;
  if(get_map(&bsq_file, *file_name)){
    printf("Error in get_map");
    return(-1);
  }

  solve(&bsq);

  free(&bsq);
  
  free(file_content);
  return (0);
}