#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
			print_error(ARG_ERROR);
	parser(av[1], &e);
	start_mlx(&e);
	return (0);
}
