#include"main.h"

int			main(int argc, char** argv){
	t_metadata	m_map;
	int			errcode;

	memset(&m_map, 0, sizeof(t_metadata));

	if ((errcode = bsq(argc, argv, &m_map)))
		return (errcode);

	return(0);
}
