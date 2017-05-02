/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:04:00 by mploux            #+#    #+#             */
/*   Updated: 2017/05/02 20:04:02 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	quadratic_scale(t_vec3 scale, t_quadratic *quadra)
{
	quadra->a /= powf(scale.x, 2.0);
	quadra->b /= powf(scale.y, 2.0);
	quadra->c /= powf(scale.z, 2.0);
	quadra->d /= scale.y * scale.z;
	quadra->e /= scale.x * scale.z;
	quadra->e /= scale.x * scale.y;
	quadra->f /= scale.x;
	quadra->g /= scale.y;
	quadra->h /= scale.z;
}
