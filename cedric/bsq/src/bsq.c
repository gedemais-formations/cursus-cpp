#include "bsq.h"

int bsq(char *file_name){
  char *file_content;
  struct stat sb;
  t_file bsq_file;

  if(stat(file_name, &sb) == -1){
    perror("stat");
    return (-1);
  }

  file_content = open_read(file_name, sb.st_size);
  if(!file_content){
    printf("Error, cannot read file \"%s\"\n" file_name);
    return (-1);
  }
  solve(file_content, count_lines(file_content),
    count_char_per_line(file_content));
  free(file_content);
  return (0);
}