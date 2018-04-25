#include "wolf3d.h"

void			fill_pixel(t_env *e, t_color color, int x, int y)
{
	int			i;

	i = x * 4 + y * e->size;
	e->data[i] = (color.b);
	e->data[i + 1] = (color.g);
	e->data[i + 2] = (color.r);
}

void    render(t_env *e)
{
	compute(e);

	// int       x;
	// int       y;
	// t_color   color;

  // x = 0;
  // while (x < WIN_W)
  // {
	// 	y = 0;
	// 	color.r = 0;
	// 	color.g = 255;
	// 	color.b = 0;
  //   while (y < WIN_H)
  //   {
  //     fill_pixel(e, color, x, y);
  //     y++;
  //   }
  //   x++;
  // }
}

void			update_image(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size), &(e->endian));
	render(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
