#include "bsq.h"

// Open a file, read it, close it and return the file content
char *read_map(char *file_name, int buffer_size){
  int fd, sz, cl;
  char *buffer = NULL;
  if (!(buffer = malloc(buffer_size+1))){
    printf("Error malloc\n");
    return(buffer);
  }
  
  //Open file
  fd = open(file_name, O_RDONLY);
  //printf("%s\n", file_name);
  if(fd < 0){
    perror(strerror(errno));
    perror("Cannot open file\n");

    return(NULL);
  }
  
  //Read file
  sz = read(fd, buffer, buffer_size);
  if(sz == -1){
    perror(strerror(errno));
    perror("Cannot read file\n");
    return(NULL);
  } else {
    buffer[sz] = '\0';
  }

  //Close file
  cl = close(fd);
  if(cl == -1){
    perror(strerror(errno));
    perror("Cannot close file\n");
  }

  return(buffer);
} 

// Count elements on the first line
static int count_char_per_line(char *file_content){
  int count = 0;
  while(file_content[count] != '\n'){
    count ++;
  }
  //count++; //Take the '\n'
  return (count);
}

static int count_lines(char *file_content){
  int count = 0;
  int i = 0;
  while(file_content[i] != '\0'){
    if(file_content[i] == '\n'){
      count ++;
    }
    i++;
  }
  count ++; //The last line doesn't have \n
  return (count);
}

int get_metadata(t_file bsq_file, char *file_content){
	return (0);
}