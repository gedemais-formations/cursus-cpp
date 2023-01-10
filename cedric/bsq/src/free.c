#include "main.h"

int free_bsq(t_file *bsq_file){
	for(unsigned int i = 0; i < bsq_file->nb_line; i++){
		free(bsq_file->board[i]);
	}
	free(bsq_file->board);
	return (0);
}