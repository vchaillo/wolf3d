#include "wolf3d.h"

void        print_error(int error)
{
    if (error == MALLOC_ERROR)
        ft_putendl("Memory allocation failed !");
    else if (error == OPEN_ERROR)
        ft_putendl("Failed to open file !");
    else if (error == MLX_ERROR)
        ft_putendl("mlx initialization failed ! !");
    exit(0);
}
