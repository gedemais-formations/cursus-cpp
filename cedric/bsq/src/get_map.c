#include "bsq.h"

// Open a file, read it, close it and return the file content
static char *read_map(char *file_name, int buffer_size){
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

static int get_board(t_file bsq_file, char *file_content){
	char **tab = NULL;
	int j = 0;
	if (! (tab = (char **) malloc(sizeof(char*) * count_line))){
		return(1);
	}
	for(i = 0; i < count_line; i++){
		if(! (tab[i] = (char *) malloc(sizeof(char) * count_char_per_line))){
			return(1);
		}
	}
	//Transform into a tab
	i = 0;
	for(unsigned int i = 0; file_content[j] != '\0'; i++){
		if(file_content[j]='\n'){
			j++; //Remove all \n
		}
		tab[i/bsq_file.nb_char][i%bsq_file.nb_char] = file_content[j];
		j++;
	}
	
	/* Ancien code
	while(file_content[j] != '\0'){
		if(file_content[j] == '\n'){
			j++; //Remove all \n
		}
		tab[i/count_char_per_line][i%count_char_per_line] = file_content[j];
		i++;
		j++;
	}*/
	bsq_file->board = tab;
	return (0);
}

static int get_metadata(t_file bsq_file, char *file_content){
	char *line;
	int size; //Size of the first line
	int nb_char; //Nb char
	int count; //Count char par line
	line = ft_strdup(file_content, '\n');

	if(!line){
		printf("Error to read metadata");
		return(-1);
	}
	size = 0;
	for(int i = 0; line[i] != '\0'; i++){
		size ++;
	}

	if(size < 4){ //Need 4 paramaters
		printf("No enough parameters");
		return(-1);
	}

	bsq_file->full_char = line[size - 1];
	bsq_file->obstacle_char = line[size - 2];
	bsq_file->empty_char = line[size - 3];

	if(bsq_file.full_char == bsq_file.obstacle_char
		|| bsq_file.full_char == bsq_file.empty_char
		|| bsq_file.empty_char == bsq_file.obstacle_char){
		printf("Char in first line aren't unique");
	return(-1);
	}
	count = 0;
	nb_char = 0;
	for(int i = size; file_content[i] = '\0'; i++){
		if(file_content[i] == '\n' && i != size){
			if(nb_char == 0){
				nb_char = count;
			} else if(nb_char != count) {
				printf("Error, lines have different lengths");
				return(-1);
			}
		}			
	}
	bsq_file->nb_char = nb_char;
	bsq_file->nb_line = count_lines(&file_content[size+1]);
	if(get_board(&bsq_file, &file_content[size+1])){
		printf("Error to get_board");
		return(-1);
	}
	return (0);
}

int get_map(t_file bsq_file, char *file_content){
	char *file_content;
	struct stat sb;

	if(stat(file_name, &sb) == -1){
		perror("stat");
		return (-1);
	}

	file_content = read_map(file_name, sb.st_size);
	if(file_content){
		printf("Error, cannot read file \"%s\"\n" file_name);
		return (-1);
	}

	if(get_metadata(&bsq_file, file_content)){
		printf("Error to access to metadata");
		return(-1);
	}
}