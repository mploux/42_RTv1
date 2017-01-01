/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:55:27 by mploux            #+#    #+#             */
/*   Updated: 2016/12/28 23:54:52 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "rt.h"

t_object		sphere(int color, t_vec3 pos, double radius)
{
	t_object	result;
	t_transform	trs;

	trs = transform(pos, vec3(0, 0, 0), vec3(radius, radius, radius));
	result = object(trs, color, &intersect_sphere);
	return (result);
}

static double	intersect_dist(t_object obj, t_ray ray)
{
	double	abc[3];
	double	delta;
	t_vec3	diff;
	double	p[2];

	diff = vec3_sub(ray.pos, obj.pos);
	abc[0] = 1;
	abc[1] = 2 * vec3_dot(ray.dir, diff);
	abc[2] = vec3_dot(diff, diff) - obj.scale.x * obj.scale.x;
	delta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (delta < 0)
		return (0);
	else if (delta == 0)
		return (-(2 * abc[0]) / abc[1]);
	else
	{
		p[0] = (-abc[1] + sqrt(delta)) / (2.0 * abc[0]);
		p[1] = (-abc[1] - sqrt(delta)) / (2.0 * abc[0]);
		if (p[0] > p[1])
			p[0] = p[1];
		return (p[0]);
	}
	return (0);
}

t_hit			intersect_sphere(t_data *data, t_object obj, t_ray ray)
{
	t_hit	result;

	(void) data;
	result.dist = intersect_dist(obj, ray);
	result.pos = vec3_add(ray.pos, vec3_mul_d(ray.dir, result.dist));
	result.normal = vec3_normalize(vec3_sub(result.pos, obj.pos));
	return (result);
}
