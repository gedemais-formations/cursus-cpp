#include"main.h"

int	bsq(int argc, char** argv, t_metadata *m_map)
{
	for (int i = 1; i < argc; i++ ){
		if (get_map(argv[i], m_map) != 0){
			printf("map error");
			return(1);
		}
		// obtenir les données stockés dans la metadata
	}
	return (0);
}
