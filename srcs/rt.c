/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:12:44 by mploux            #+#    #+#             */
/*   Updated: 2017/04/11 14:32:07 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "maths.h"
#include "graphics.h"
#include <stdlib.h>

int		create_rt(t_data *data, const char *name, int width, int height)
{
	t_win		*win;
	t_transform	cam;

	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		error("malloc error !");
	data->win = win;
	new_sdl_display(data, name, width, height);
	data->framebuffer = new_bitmap(data, width, height);
	cam = transform(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0));
	data->camera = new_camera(data, cam, 70.0);
	data->scene = new_scene();
	return (1);
}

int		loop(t_data *data)
{
	bitmap_update(data->framebuffer);
	return (1);
}

void	loop_rt(t_data *data)
{
	manage_scene(data);
	bitmap_update(data->framebuffer);
	draw_screen(data);
	sdl_loop(data, &loop);
}

void	exit_rt(t_data *data)
{
	free(data);
	exit(0);
}
