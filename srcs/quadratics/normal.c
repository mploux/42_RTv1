/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:07:08 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 13:00:49 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec3		quadratic_normal(t_quadratic *q, t_vec3 pos, t_vec3 dir)
{
	t_vec3	result;

	result.x = 2.0 * q->a * pos.x + q->e * pos.z + q->f * pos.y + q->g;
	result.y = 2.0 * q->b * pos.y + q->d * pos.z + q->f * pos.x + q->h;
	result.z = 2.0 * q->c * pos.z + q->d * pos.y + q->e * pos.x + q->i;
	result = vec3_normalize(result);
	if (vec3_dot(result, dir) > 0.0)
		result = vec3_mul_d(result, -1.0);
	return (result);
}
