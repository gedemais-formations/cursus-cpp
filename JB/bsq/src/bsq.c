#include"main.h"

int	bsq(int argc, char** argv, t_metadata *m_map)
{
	for (int i = 1; i < argc; i++ ){
		memset(m_map, 0, sizeof(t_metadata));
		if (get_map(argv[i], m_map) != 0){
			printf("map error");
			free_array(m_map->map);
			continue;
		}
		else {
			solve(m_map);
			free_array(m_map->map);
		}
		// obtenir les données stockés dans la metadata
	}
	
	return (0);
}
