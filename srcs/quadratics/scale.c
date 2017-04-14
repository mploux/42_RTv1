/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiammel <pgiammel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 12:54:45 by pgiammel          #+#    #+#             */
/*   Updated: 2017/02/23 16:54:44 by wescande         ###   ########.fr       */
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
