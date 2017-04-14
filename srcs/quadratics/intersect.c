/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:34:10 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 13:27:23 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	delta(float a, float b, float c)
{
	const float	delta = b * b - 4.0 * a * c;
	const float sqrt_delta = sqrtf(delta);
	const float a2 = 2.0 * a;
	float		inter1;
	float		inter2;

	if (delta < 0.0)
		return (0);
	else
	{
		inter1 = (-b + sqrt_delta) / a2;
		inter2 = (-b - sqrt_delta) / a2;
		if (inter2 > 0.0 && inter1 > inter2)
			inter1 = inter2;
		return (inter1);
	}
}

float			quadratic_intersect(t_quadratic *quad, t_vec3 *dir, t_vec3 *eye)
{
	float a;
	float b;
	float c;

	a = quad->a * powf(dir->x, 2.0) + quad->b * powf(dir->y, 2.0) +
		quad->c * powf(dir->z, 2.0) + quad->d * dir->y * dir->z +
		quad->e * dir->x * dir->z + quad->f * dir->x * dir->y;
	b = 2 * (quad->a * eye->x * dir->x + quad->b * eye->y * dir->y +
		quad->c * eye->z * dir->z) +
		quad->d * (eye->y * dir->z + eye->z * dir->y) +
		quad->e * (eye->x * dir->z + eye->z * dir->x) +
		quad->f * (eye->x * dir->y + eye->y * dir->x) + quad->g * dir->x +
		quad->h * dir->y + quad->i * dir->z;
	c = quad->a * powf(eye->x, 2.0) + quad->b * powf(eye->y, 2.0) +
		quad->c * powf(eye->z, 2.0) +
		quad->d * eye->y * eye->z + quad->e * eye->x * eye->z +
		quad->f * eye->x * eye->y + quad->g * eye->x +
		quad->h * eye->y + quad->i * eye->z + quad->j;
	return (delta(a, b, c));
}

t_hit			quadratic_object_intersect(t_object *object, t_ray *ray)
{
	t_hit	r;

	r.dist = quadratic_intersect(&object->quadra, &ray->dir, &ray->pos);
	if (r.dist > 0.0)
	{
		r.pos = vec3_add(ray->pos, vec3_mul_d(ray->dir, r.dist));
		r.normal = quadratic_normal(&object->quadra, r.pos, ray->dir);
	}
	return (r);
}
