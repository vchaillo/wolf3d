/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchaillo <vchaillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 12:24:51 by vchaillo          #+#    #+#             */
/*   Updated: 2017/03/24 04:00:00 by vchaillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_plane			*new_plane(t_vector normal, float offset, int type,
					t_vector limits[])
{
	t_plane		*plane;

	if (!(plane = (t_plane*)malloc(sizeof(t_plane))))
		print_error(MALLOC_ERROR);
	plane->normal = normalize(normal);
	plane->offset = offset;
	plane->type = type;
	plane->limit_min = limits[0];
	plane->limit_max = limits[1];
	return (plane);
}

void			delete_plane(t_plane *plane)
{
	free(plane);
}
