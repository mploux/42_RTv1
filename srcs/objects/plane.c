/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:00:41 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 13:27:52 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "rt.h"

t_object		plane(int color, t_vec3 dir, float dist)
{
	t_object	result;
	t_transform	trs;

	trs = transform(vec3_mul_d(dir, dist), dir, vec3(1, 1, 1));
	result = object(trs, color, &intersect_plane);
	result.dist = dist;
	return (result);
}

t_hit			intersect_plane(t_object obj, t_ray ray)
{
	t_hit	result;
	float	numer;
	float	denom;
	float	dist;

	result.dist = 0;
	obj.pos = vec3_mul_d(obj.rot, obj.dist);
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
		}
	}
	return (result);
}
