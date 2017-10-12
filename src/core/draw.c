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
	t_color		blue, red, white, color;

	blue.r = 0;
	blue.g = 0;
	blue.b = 255;

	white.r = 255;
	white.g = 255;
	white.b = 255;

	red.r = 255;
	red.g = 0;
	red.b = 0;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		color = blue;
		while (x < WIN_W)
		{
			if (x > WIN_W / 3)
				color = white;
			if (x > (WIN_W / 3) * 2)
				color = red;
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
	compute(e);
	apply_color_to_image(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
