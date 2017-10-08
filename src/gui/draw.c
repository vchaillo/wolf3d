/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:05 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/30 17:42:23 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			if (e->scene->effect == NEGATIVE)
				e->scene->color_array[y][x] = negative_color(
					e->scene->color_array[y][x]);
			fill_pixel(e, e->scene->color_array[y][x], x, y);
		}
	}
}

void			update_image(t_env *e)
{
	clock_t		begin;
	clock_t		end;

	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size), &(e->endian));
	begin = clock();
	draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	end = clock();
	e->frame_time = (float)(end - begin) / CLOCKS_PER_SEC;
	print_gui_output(e);
	print_cli_output(e);
}

void			draw(t_env *e)
{
	multithreading(e);
	super_sampling(e);
	exposure(e->scene->color_array);
	apply_color_to_image(e);
	stereoscopy(e);
}
