/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:32:45 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 12:32:47 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	quadratic_rotate_y(float angle, t_quadratic *quadra)
{
	const float			cos1 = cosf(angle);
	const float			sin1 = sinf(angle);
	const float			cos2 = (1.0 + cosf(2.0 * angle)) / 2.0;
	const float			sin2 = (1.0 - cosf(2.0 * angle)) / 2.0;
	const t_quadratic	tmp = *quadra;

	quadra->a = quadra->a * cos2 + quadra->c * sin2 - quadra->e * cos1 * sin1;
	quadra->c = tmp.a * sin2 + quadra->c * cos2 + quadra->e * cos1 * sin1;
	quadra->d = quadra->d * cos1 + quadra->f * sin1;
	quadra->e = 2.0 * tmp.a * cos1 * sin1 - 2.0 * tmp.c * cos1 * sin1 +
		quadra->e * cos2 - quadra->e * sin2;
	quadra->f = -tmp.d * sin1 + quadra->f * cos1;
}
