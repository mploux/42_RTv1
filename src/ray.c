/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:58:46 by mploux            #+#    #+#             */
/*   Updated: 2016/12/28 23:56:38 by mploux           ###   ########.fr       */
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
	t_object	object;
	double		dist;

	list = data->scene->objects;
	result.dist = 0;
	dist = 10000;
	while (list)
	{
		object = *((t_object *)list->content);
		hit = object.intersect(data, object, ray);
		hit.obj = list->content;
		if (hit.dist > 0 && hit.dist <= dist)
		{
			dist = hit.dist;
			ft_memcpy(&result, &hit, sizeof(t_hit));
		}
		list = list->next;
	}
	return (result);
}
