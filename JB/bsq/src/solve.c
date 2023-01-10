#include"main.h"

int min_val (int x, int y){
	if(x <= y){
		return(x);
	}
	return(y);
}



bool check (t_metadata* m_map, int start_x, int start_y, int sqr_side){
	for (int l = 0; l < sqr_side; l++){
		for(int m = 0; m <sqr_side; m++){
			if (m_map->board[start_x + l][start_y + m] == m_map->obstacle_char){
				return(false);
			}	
		}
	}	
	return (true);		
}

int solve(t_metadata* m_map){
	int sqr1_size = min_val(m_map->nb_line, m_map->nb_col);
		for (int i = 0; i < sqr1_size; i++){
			int sqr_side = sqr1_size - i;
			int end_x = m_map->nb_col - sqr_side;
			int end_y = m_map->nb_line - sqr_side;
			for (int j = 0; j < end_x; j++){
				for(int k = 0; k < end_y; k++){
					if(check(m_map, j, k, sqr_side)){
						printf("IT WORKS \n");
						printf("Square start at %d %d and its side is %d \n", k, j, sqr_side);
						exit(0);
					}
				}
			}
		}
	return(1);
}
