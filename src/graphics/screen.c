/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:47:43 by mploux            #+#    #+#             */
/*   Updated: 2016/12/22 20:15:45 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "graphics.h"

void		draw_screen(t_data *data)
{
	int			x;
	int			y;
	t_ray		ray;
	t_object	sphere_object;
	t_hit		hit;

	sphere_object = sphere(vec3(0, 0, -10), 1);

	y = -1;
	while (++y < data->win->h)
	{
		x = -1;
		while (++x < data->win->w)
		{
			ray = cam_ray(data, (double)x, (double)y);
			hit = intersect_sphere(data, sphere_object, ray);
			if (hit.dist > 0)
			{
				int col = (int)((hit.dist - 9) * 100.0);
				draw_pix(data, x, y, color(col, col, col));
			}
		}
	}
}
