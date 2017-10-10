#include "wolf3d.h"

void			fill_pixel(t_env *e, t_color color, int x, int y)
{
	int			i;

	i = x * 4 + y * e->size;
	e->data[i] = (color.b);
	e->data[i + 1] = (color.g);
	e->data[i + 2] = (color.r);
}

void			apply_color_to_image(t_env *e)
{
	int			x;
	int			y;
	t_color		color;

	color.r = 100;
	color.g = 0;
	color.b = 50;
	y = 1;
	while (y < WIN_H)
	{
		x = 1;
		while (x < WIN_W)
		{
			fill_pixel(e, color, x, y);
			x++;
		}
		y++;
	}
}

void			update_image(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size), &(e->endian));
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void			draw(t_env *e)
{
	apply_color_to_image(e);
}
