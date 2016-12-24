/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:00:28 by mploux            #+#    #+#             */
/*   Updated: 2016/12/22 20:17:22 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit		hit(t_object *obj, t_vec3 pos, t_vec3 normal, double dist)
{
	t_hit result;

	result.obj = obj;
	result.pos = pos;
	result.normal = normal;
	result.dist = dist;
	return (result);
}
