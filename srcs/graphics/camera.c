/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:16:41 by mploux            #+#    #+#             */
/*   Updated: 2017/04/11 15:32:33 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

t_camera	*new_camera(t_data *data, t_transform trs, float fov)
{
	t_camera *cam;

	if (!(cam = (t_camera *)ft_memalloc(sizeof(t_camera))))
		error("malloc error !");
	cam->z_near = 5;
	cam->z_far = 1000;
	cam->fov = fov;
	cam->aspect = (float)data->win->w / (float)data->win->h;
	cam->pos = trs.pos;
	cam->rot = trs.rot;
	cam->scale = trs.scale;
	return (cam);
}

t_ray		cam_ray(t_data *data, float x, float y)
{
	float	fov;
	t_ray	result;
	t_vec3	scr;
	t_vec3	dir;
	t_vec3	rot;

	scr.x = x / data->win->w * 2 - 1;
	scr.y = y / data->win->h * -2 + 1;
	fov = tan(DTR(data->camera->fov) / 2.0);
	dir.x = scr.x * data->camera->aspect * fov;
	dir.y = scr.y * fov;
	dir.z = -1;
	rot = data->camera->rot;
	dir = mat4_mul_vec3(mat4_rotate_v(rot), dir);
	result.pos = data->camera->pos;
	result.dir = vec3_normalize(dir);
	return (result);
}
