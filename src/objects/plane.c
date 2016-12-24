/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:00:41 by mploux            #+#    #+#             */
/*   Updated: 2016/12/24 20:56:59 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "rt.h"

t_object		plane(int color, t_vec3 dir, double dist)
{
	t_object	result;
	t_transform	trs;

	trs = transform(vec3_mul_d(dir, dist), dir, vec3(1, 1, 1));
	result = object(trs, color, &intersect_plane);
	return (result);
}

t_hit			intersect_plane(t_data *data, t_object obj, t_ray ray)
{
	t_hit	result;
	double	numer;
	double	denom;
	double	dist;

	(void) data;
	result.dist = 0;
	denom = vec3_dot(ray.dir, obj.rot);
	if (denom > 0.01)
	{
		numer = vec3_dot(vec3_sub(obj.pos, ray.pos), obj.rot);
		dist = numer / denom;
		if (dist >= 0)
		{
			result.normal = vec3_mul_d(vec3_normalize(obj.rot), -1);
			result.dist = dist;
			result.pos = vec3_add(ray.pos, vec3_mul_d(ray.dir, dist));
			result.obj = &obj;
		}
	}
	return (result);
}
