#include"main.h"

void free_array(char** map){

	if (map != NULL){
		for (int i = 0; map[i] != NULL ; i++ ){
		free(map[i]);
		}
	free(map);
	}
}
