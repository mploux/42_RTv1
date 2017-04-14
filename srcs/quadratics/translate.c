/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:33:12 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 12:33:13 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	quadratic_translate(t_vec3 pos, t_quadratic *quadra)
{
	quadra->j += quadra->a * powf(pos.x, 2.0) +
		quadra->b * powf(pos.y, 2.0) +
		quadra->c * powf(pos.z, 2.0) +
		quadra->d * pos.y * pos.z +
		quadra->e * pos.x * pos.z +
		quadra->f * pos.x * pos.y -
		quadra->g * pos.x -
		quadra->h * pos.y -
		quadra->i * pos.z;
	quadra->g +=
		-2.0 * quadra->a * pos.x - quadra->e * pos.z - quadra->f * pos.y;
	quadra->h +=
		-2.0 * quadra->b * pos.y - quadra->d * pos.z - quadra->f * pos.x;
	quadra->i +=
		-2.0 * quadra->c * pos.z - quadra->d * pos.y - quadra->e * pos.x;
}
