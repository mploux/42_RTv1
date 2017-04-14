/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:32:52 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 12:32:53 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	quadratic_rotate_z(float angle, t_quadratic *quadra)
{
	const float			cos1 = cosf(angle);
	const float			sin1 = sinf(angle);
	const float			cos2 = (1.0 + cosf(2.0 * angle)) / 2.0;
	const float			sin2 = (1.0 - cosf(2.0 * angle)) / 2.0;
	const t_quadratic	tmp = *quadra;

	quadra->a = quadra->a * cos2 + quadra->b * sin2 + quadra->f * sin1 * cos1;
	quadra->b = tmp.a * sin2 + quadra->b * cos2 - quadra->f * sin1 * cos1;
	quadra->f = 2.0 * (tmp.a - tmp.b) * sin1 * cos1 + quadra->f * (cos2 - sin2);
	quadra->d = quadra->d * cos1 - quadra->e * sin1;
	quadra->e = tmp.d * sin1 + quadra->e * cos1;
	quadra->g = quadra->g * cos1 + quadra->h * sin1;
	quadra->h = -tmp.g * sin1 + quadra->h * cos1;
}
