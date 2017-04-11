/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:00:41 by mploux            #+#    #+#             */
/*   Updated: 2017/04/11 20:33:05 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "rt.h"

t_object		cylindre(int color, t_vec3 pos, t_vec3 rot, double r)
{
	t_object	result;
	t_transform	trs;

	trs = transform(pos, rot, vec3(r, r, r));
	result = object(trs, color, &intersect_cylindre);
	return (result);
}

static double	intersect_dist(t_object obj, t_ray ray)
{
	double	abc[3];
	double	delta;
	double	p[2];

	abc[0] = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	abc[1] = 2 * ray.pos.x * ray.dir.x + 2 * ray.pos.z * ray.dir.z;
	abc[2] = ray.pos.x * ray.pos.x + ray.pos.z * ray.pos.z - obj.scale.x;
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

t_hit			*intersect_cylindre(t_object obj, t_ray ray)
{
	t_hit	*result;

	result = new_hit();
	ray.pos = vec3_sub(ray.pos, obj.pos);
	ray.dir = mat4_mul_vec3(mat4_rotate_v(obj.rot), ray.dir);
	result->dist = intersect_dist(obj, ray);
	if (result->dist == 0)
	{
		hit_free(&result);
		return (NULL);
	}
	ray.pos = vec3_add(ray.pos, obj.pos);
	result->pos = vec3_add(ray.pos, vec3_mul_d(ray.dir, result->dist));
	result->normal = vec3(result->pos.x - obj.pos.x, 0, result->pos.z - obj.pos.z);
	// ray.pos = vec3_sub(ray.pos, obj.pos);
	// result->normal = vec3_normalize(result->normal);
	// printf("%f %f %f\n", result->normal.x, result->normal.y, result->normal.z);
	return (result);
}
