/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:35:21 by mploux            #+#    #+#             */
/*   Updated: 2016/12/24 23:40:16 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene		*new_scene()
{
	t_scene *scene;

	if (!(scene = (t_scene *)ft_memalloc(sizeof(t_scene*))))
		error("malloc error !");
	scene->objects = NULL;
	scene->size = 0;
	return (scene);
}

void		manage_scene(t_data *data)
{
	add_object(data->scene, plane(0xffffff, vec3(0, -1, 0), 2));
	add_object(data->scene, plane(0xffffff, vec3(-1, 0, 0), 5));
	add_object(data->scene, plane(0xffffff, vec3(1, 0, 0), 5));
	add_object(data->scene, plane(0xffffff, vec3(0, 1, 0), 2));
	add_object(data->scene, plane(0xffffff, vec3(0, 0, -1), 10));

	add_object(data->scene, sphere(0x0000ff, vec3(2, 0, -7), 1));
	add_object(data->scene, sphere(0x00ff00, vec3(-2, 0, -7), 1));
	add_object(data->scene, sphere(0xff0000, vec3(0, 1, -7), 1));
	add_object(data->scene, sphere(0xffff00, vec3(0, -1, -7), 1));

	add_object(data->scene, cylindre(0xffffff, vec3(-3, 0, -7), vec3(0, 1, 0)));

	data->scene->size = ft_lstsize(data->scene->objects);
}

void		add_object(t_scene *scene, t_object obj)
{
	t_list *new;

	new = ft_lstnew(&obj, sizeof(t_object));
	ft_lstadd(&scene->objects, new);
}

static int	draw_ray(t_data *data, t_ray ray, t_hit hit)
{
	t_object	object;
	double		light_intensity;
	t_vec3		final_color;

	object = *((t_object *)hit.obj);
	light_intensity = clamp(vec3_dot(hit.normal, vec3_normalize(vec3_sub(vec3(3, -1, -5), hit.pos))), 0, 1);
	final_color = vec3_mul_d(object.color, light_intensity);
	return (to_color(final_color));
}

void		draw_scene(t_data *data, t_ray ray, t_vec2 pix, int iteration)
{
	t_hit	hit;

	hit = throw_ray(data, ray);
	if (hit.dist > 0)
		draw_pix(data, pix.x, pix.y, draw_ray(data, ray, hit));
}
