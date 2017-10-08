/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:12:42 by valentin          #+#    #+#             */
/*   Updated: 2017/04/02 16:33:36 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			load_scene5_objects(t_scene *scene)
{
	t_vector	limits[2];

	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 50, 0);
	add_object(scene, new_object(CONE,
		new_cone(new_vector(0, 1, 0), new_vector(40, 20, -25), 20, limits),
		new_color(YELLOW), new_material(TIGER)));
	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 50, 0);
	add_object(scene, new_object(CONE,
		new_cone(new_vector(0, -1, 0), new_vector(40, 20, -25), 20, limits),
		new_color(RED), new_material(BASIC)));
	limits[1] = new_vector(0, 50, 0);
	limits[0] = new_vector(0, -10, 0);
	add_object(scene, new_object(CYLINDER, new_cylinder(new_vector(0, 1, -0.3),
		new_vector(-50, 0, -25), 10, limits), new_color(PASTEL_BLUE),
		new_material(BASIC)));
	limits[0] = new_vector(0, 0, 0);
	limits[1] = new_vector(0, 0, 0);
	add_object(scene, new_object(SPHERE, new_sphere(new_vector(-5, 15, 10), 10,
		new_vector(-10, 1, 2), limits), new_color(BLUE), new_material(BASIC)));
	add_object(scene, new_object(PLANE, new_plane(new_vector(0, 1, 0), 0,
		WAVE, limits), new_color(WHITE), new_material(BIT_REF)));
}

static void			load_scene5_lights(t_scene *scene)
{
	scene->amb_intensity = 0.3;
	scene->amb_color = new_color(BLUE);
	add_light(scene, new_light(LSPOT, 1, new_vector(-100, 75, 50),
		new_color(WHITE)));
	add_light(scene, new_light(LDIR, 0.5, new_vector(0, -1, -1),
		new_color(WHITE)));
}

void				load_scene5(t_env *e)
{
	if (e->scene)
		delete_scene(e->scene);
	e->scene_type = SCENE_5;
	e->scene = new_scene(new_color(BLACK), new_camera(new_vector(0, 20, 100),
		new_vector(0, 20, -1)));
	load_scene5_objects(e->scene);
	load_scene5_lights(e->scene);
}
