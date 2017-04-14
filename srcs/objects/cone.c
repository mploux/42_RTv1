/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:00:41 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 17:47:45 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "rt.h"

static void		cone_quadratic(t_object *obj)
{
	obj->quadra.a = 1.0;
	obj->quadra.b = -1.0;
	obj->quadra.c = 1.0;
	obj->quadra.d = 0.0;
	obj->quadra.e = 0.0;
	obj->quadra.f = 0.0;
	obj->quadra.g = 0.0;
	obj->quadra.h = 0.0;
	obj->quadra.i = 0.0;
	obj->quadra.j = 0.0;
	quadratic_scale(obj->scale, &obj->quadra);
	quadratic_rotate_z(DTR(obj->rot.z), &obj->quadra);
	quadratic_rotate_y(DTR(obj->rot.y), &obj->quadra);
	quadratic_rotate_x(DTR(obj->rot.x), &obj->quadra);
	quadratic_translate(obj->pos, &obj->quadra);
}

t_object		cone(int color, t_vec3 pos, t_vec3 rot, float angle)
{
	t_object	result;
	t_transform	trs;
	float		y_scale;

	trs = transform(pos, rot, vec3(1, 1, 1));
	result = object(trs, color, &intersect_cone);
	cone_quadratic(&result);
	return (result);
}

t_hit			intersect_cone(t_object obj, t_ray ray)
{
	return (quadratic_object_intersect(&obj, &ray));
}
