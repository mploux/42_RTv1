/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:55:27 by mploux            #+#    #+#             */
/*   Updated: 2017/05/04 19:40:56 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "rt.h"

static void		sphere_quadratic(t_object *obj)
{
	obj->quadra.a = 1.0;
	obj->quadra.b = 1.0;
	obj->quadra.c = 1.0;
	obj->quadra.d = 0.0;
	obj->quadra.e = 0.0;
	obj->quadra.f = 0.0;
	obj->quadra.g = 0.0;
	obj->quadra.h = 0.0;
	obj->quadra.i = 0.0;
	obj->quadra.j = -1.0;
	quadratic_scale(obj->scale, &obj->quadra);
	quadratic_rotate_z(DTR(obj->rot.z), &obj->quadra);
	quadratic_rotate_y(DTR(obj->rot.y), &obj->quadra);
	quadratic_rotate_x(DTR(obj->rot.x), &obj->quadra);
	quadratic_translate(obj->pos, &obj->quadra);
}

t_object		sphere(int color, t_vec3 pos, t_vec3 rot, t_vec3 scale)
{
	t_object	result;
	t_transform	trs;

	trs = transform(pos, rot, scale);
	result = object(trs, color, &intersect_sphere);
	sphere_quadratic(&result);
	return (result);
}

t_hit			intersect_sphere(t_object obj, t_ray ray)
{
	return (quadratic_object_intersect(&obj, &ray));
}
