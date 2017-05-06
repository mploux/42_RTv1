/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:58:46 by mploux            #+#    #+#             */
/*   Updated: 2017/05/06 17:30:56 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "graphics.h"

t_ray			nray(t_vec3 pos, t_vec3 dir)
{
	t_ray	result;

	result.pos = pos;
	result.dir = dir;
	return (result);
}

t_hit			throw_ray(t_data *data, t_ray ray)
{
	t_hit		hit;
	t_hit		result;
	t_list		*list;
	t_object	*object;
	float		dist;

	list = data->scene->objects;
	result.dist = 0;
	dist = 10000;
	while (list)
	{
		object = (t_object *)list->content;
		hit = object->intersect(*object, ray);
		if (hit.dist > 0.0005 && hit.dist < dist)
		{
			hit.obj = object;
			dist = hit.dist;
			result = hit;
		}
		list = list->next;
	}
	return (result);
}
