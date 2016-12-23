/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:42:10 by mploux            #+#    #+#             */
/*   Updated: 2016/12/23 18:48:35 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_object	object(t_transform trs, int color, t_hit (*intersect)
												(t_data*, t_object obj, t_ray))
{
	t_object object;

	object.pos = trs.pos;
	object.rot = trs.rot;
	object.scale = trs.scale;
	object.color = color_to_vec3(color);
	object.intersect = intersect;
	return (object);
}
