/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 01:20:22 by valentin          #+#    #+#             */
/*   Updated: 2017/03/24 03:36:09 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		vector_rot_x(t_vector v, float angle)
{
	t_vector	vector;

	angle = M_PI * angle / 180;
	vector.x = v.x;
	vector.y = v.y * cos(angle) - v.z * sin(angle);
	vector.z = v.y * sin(angle) + v.z * cos(angle);
	return (vector);
}

t_vector		vector_rot_y(t_vector v, float angle)
{
	t_vector	vector;

	angle = M_PI * angle / 180;
	vector.x = v.x * cos(angle) + v.z * sin(angle);
	vector.y = v.y;
	vector.z = -v.x * sin(angle) + v.z * cos(angle);
	return (vector);
}

t_vector		vector_rot_z(t_vector v, float angle)
{
	t_vector	vector;

	angle = M_PI * angle / 180;
	vector.x = v.x * cos(angle) - v.y * sin(angle);
	vector.y = v.x * sin(angle) + v.y * cos(angle);
	vector.z = v.z;
	return (vector);
}

t_vector		vector_rot_axis(t_vector v, t_vector axis, float angle)
{
	t_vector	vector;
	float		c;
	float		s;

	angle = M_PI * angle / 180;
	c = cos(angle);
	s = sin(angle);
	vector.x = ((pow_2(axis.x) * (1 - c) + c) * v.x)
		+ ((axis.x * axis.y * (1 - c) - (axis.z * s)) * v.y)
		+ ((axis.x * axis.z * (1 - c) + (axis.y * s)) * v.z);
	vector.y = ((axis.x * axis.y * (1 - c) + (axis.z * s)) * v.x)
		+ ((pow_2(axis.y) * (1 - c) + c) * v.y)
		+ ((axis.y * axis.z * (1 - c) - (axis.x * s)) * v.z);
	vector.z = ((axis.x * axis.z * (1 - c) - (axis.y * s)) * v.x)
		+ ((axis.y * axis.z * (1 - c) + (axis.x * s)) * v.y)
		+ ((pow_2(axis.z) * (1 - c) + c) * v.z);
	return (normalize(vector));
}

t_vector		convert_to_rotated_coordinates(t_vector pos, t_vector axis)
{
	float		theta[2];
	float		phi[2];
	float		r[2];

	r[0] = sqrt(pow(pos.x, 2) + pow(pos.y, 2) + pow(pos.z, 2));
	r[1] = sqrt(pow(axis.x, 2) + pow(axis.y, 2) + pow(axis.z, 2));
	theta[0] = acos(pos.y / r[0]);
	if (!theta[0])
		phi[0] = 0;
	else
		phi[0] = acos(pos.z / sin(theta[0]) / r[0]);
	theta[1] = acos(axis.y / r[1]);
	if (!theta[1])
		phi[1] = 0;
	else
		phi[1] = acos(axis.z / sin(theta[1]) / r[1]);
	if (asin(pos.x / sin(theta[0]) / r[0]) < 0)
		phi[0] = -phi[0];
	if (asin(axis.x / sin(theta[1]) / r[1]) < 0)
		phi[1] = -phi[1];
	pos.x = r[0] * sin(theta[0] + theta[1]) * sin(phi[0] + phi[1]);
	pos.y = r[0] * cos(theta[0] + theta[1]);
	pos.z = r[0] * sin(theta[0] + theta[1]) * cos(phi[0] + phi[1]);
	return (pos);
}
