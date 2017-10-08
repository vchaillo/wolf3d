/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 19:53:08 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 08:20:43 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			load_scene(int scene_type, t_env *e)
{
	if (scene_type == SCENE_1)
		load_scene1(e);
	else if (scene_type == SCENE_2)
		load_scene2(e);
	else if (scene_type == SCENE_3)
		load_scene3(e);
	else if (scene_type == SCENE_4)
		load_scene4(e);
	else if (scene_type == SCENE_5)
		load_scene5(e);
	else if (scene_type == SCENE_6)
		load_scene6(e);
	else if (scene_type == SCENE_7)
		load_scene7(e);
	else if (scene_type == SCENE_8)
		load_scene8(e);
	else if (scene_type == SCENE_9)
		load_scene9(e);
}

void			switch_scene(int keycode, t_env *e)
{
	if (keycode == KEY_LEFT)
		e->scene_type--;
	else if (keycode == KEY_RIGHT)
		e->scene_type++;
	if (e->scene_type == 0)
		e->scene_type = NB_SCENES;
	else if (e->scene_type == NB_SCENES + 1)
		e->scene_type = SCENE_1;
	load_scene(e->scene_type, e);
}
