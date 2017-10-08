/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <hbock@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:58:39 by hbock             #+#    #+#             */
/*   Updated: 2017/04/02 15:34:59 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		load_scene9_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-4, -3.2, 0),
		2.6, new_vector(0, 1, 0), limits), new_color(BLACK),
		new_material(CHROME)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -2, -2),
		new_vector(0.7, 0, 8), new_vector(0, 0, 0)), new_color(PASTEL_BLUE),
		new_material(GLASS)));
	add_object(scene, new_object(BOX, new_box(new_vector(-2, -2, -2),
		new_vector(2, -4, 1), new_vector(0, 0, 0)), new_color(FLASH_PINK),
		new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 6,
		NORMAL, limits), new_color(GREEN), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, -1, 0), 6,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 0, 1), 14,
		NORMAL, limits), new_color(GREY), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(1, 0, 0), 8,
		NORMAL, limits), new_color(RED), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(-1, 0, 0), 8,
		NORMAL, limits), new_color(BLUE), new_material(BASIC)));
}

static void		load_scene9_lights(t_scene *scene)
{
	scene->amb_intensity = 0.01;
	scene->amb_color = new_color(WHITE);
	add_light(scene, new_light(LSPOT, 0.5, new_vector(-4, 2, 10),
		new_color(FAKE_WHITE)));
}

void			load_scene9(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_9;
	e->scene = new_scene(new_color(FAKE_BLACK), new_camera(new_vector(4, 4, 25),
		new_vector(-7, -2, -1)));
	load_scene9_objects(e->scene);
	load_scene9_lights(e->scene);
}
