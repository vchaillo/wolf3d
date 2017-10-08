/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:18 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/15 01:50:09 by mmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	print_gui_output(e);
	print_exposehook(e);
	return (0);
}

void	start_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
	{
		print_error(MLX_ERROR);
		exit(0);
	}
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "rt");
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size), &(e->endian));
	update_image(e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_hook(e->win, 17, (1l << 17), mouse_clic, e);
	mlx_loop(e->mlx);
}
