/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:32:39 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 12:32:39 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	quadratic_rotate_x(float angle, t_quadratic *quadra)
{
	const float			cos1 = cosf(angle);
	const float			sin1 = sinf(angle);
	const float			cos2 = (1.0 + cosf(2.0 * angle)) / 2.0;
	const float			sin2 = (1.0 - cosf(2.0 * angle)) / 2.0;
	const t_quadratic	tmp = *quadra;

	quadra->b = quadra->b * cos2 + quadra->c * sin2 + quadra->d * cos1 * sin1;
	quadra->c = tmp.b * sin2 + quadra->c * cos2 - quadra->d * cos1 * sin1;
	quadra->d = -2.0 * tmp.b * cos1 * sin1 + 2.0 * tmp.c * cos1 * sin1 +
		quadra->d * cos2 - quadra->d * sin2;
	quadra->e = quadra->e * cos1 - quadra->f * sin1;
	quadra->f = tmp.e * sin1 + quadra->f * cos1;
	quadra->h = quadra->h * cos1 + quadra->i * sin1;
	quadra->i = -tmp.h * sin1 + quadra->i * cos1;
}
