/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:00:00 by mploux            #+#    #+#             */
/*   Updated: 2017/04/11 13:29:34 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "maths.h"

void	draw_pix(t_data *data, float x, float y, int color)
{
	bitmap_draw_pix(data->framebuffer, (int)x, (int)y, color);
}

void	draw_line(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors)
{
	if (ABS(b.x - a.x) > ABS(b.y - a.y))
		draw_line_x(data, a, b, colors);
	else
		draw_line_y(data, a, b, colors);
}
