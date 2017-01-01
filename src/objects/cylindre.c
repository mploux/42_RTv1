/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:00:41 by mploux            #+#    #+#             */
/*   Updated: 2016/12/28 23:55:02 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "rt.h"

t_object		cylindre(int color, t_vec3 pos, t_vec3 rot, double r)
{
	t_object	result;
	t_transform	trs;

	trs = transform(pos, rot, vec3(r, 1, 1));
	result = object(trs, color, &intersect_cylindre);
	return (result);
}

static double	intersect_dist(t_object obj, t_ray ray)
{
	double	abc[3];
	double	delta;
	t_vec3	diff;
	double	p[2];

	diff = vec3_sub(ray.pos, obj.pos);
	abc[0] = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	abc[1] = 2 * diff.x * ray.dir.x + 2 * diff.z * ray.dir.z;
	abc[2] = diff.x * diff.x + diff.z * diff.z - obj.scale.x;
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

t_hit			intersect_cylindre(t_data *data, t_object obj, t_ray ray)
{
	t_hit	result;
	t_vec3	n_diff;

	(void) data;
	result.dist = intersect_dist(obj, ray);
	result.pos = vec3_add(ray.pos, vec3_mul_d(ray.dir, result.dist));
	n_diff = vec3(result.pos.x - obj.pos.x, 0, result.pos.z - obj.pos.z);
	result.normal = vec3_normalize(n_diff);
	return (result);
}
