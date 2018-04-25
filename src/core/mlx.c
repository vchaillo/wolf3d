#include "wolf3d.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	start_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		print_error(MLX_ERROR);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "wolf3d");
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size), &(e->endian));
	update_image(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_loop(e->mlx);
}
