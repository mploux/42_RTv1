/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:47:43 by mploux            #+#    #+#             */
/*   Updated: 2016/12/22 21:29:30 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "graphics.h"

void		draw_screen(t_data *data)
{
	int			x;
	int			y;
	t_ray		ray;

	y = -1;
	while (++y < data->win->h)
	{
		x = -1;
		while (++x < data->win->w)
		{
			ray = cam_ray(data, (float)x, (float)y);
			draw_scene(data, ray, vec2(x, y));
		}
	}
}
