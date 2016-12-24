/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_sdl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:12:44 by mploux            #+#    #+#             */
/*   Updated: 2016/12/24 20:08:26 by mploux           ###   ########.fr       */
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
	data->input = new_input();
	data->zbuffer = new_zbuffer(width, height);
	cam = transform(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0));
	data->camera = new_camera(data, cam, 70.0);
	data->scene = new_scene();
	return (1);
}

void	draw_debug(t_data *data)
{
	int y;

	y = data->win->h;
	draw_text(data, vec2(5, y - 25), 0xffffff, "Ecole 42 - rtv1 - mploux");
}

int		loop(t_data *data)
{
	draw_screen(data);
	draw_debug(data);
	bitmap_update(data->framebuffer);
	clear_bitmap(data->framebuffer);
	clear_zbuffer(data, 10000);
	return (1);
}

void	loop_rt(t_data *data)
{
	manage_scene(data);
	sdl_loop(data, &loop);
}

void	exit_rt(t_data *data)
{
	free(data->input);
	free(data);
	exit(0);
}
