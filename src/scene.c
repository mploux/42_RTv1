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
	scene->lights = NULL;
	return (scene);
}

void		manage_scene(t_data *data)
{
	add_object(data->scene, plane(0xffffff, vec3(0, -1, 0), 2));
	add_object(data->scene, plane(0xffffff, vec3(-1, 0, 0), 5));
	add_object(data->scene, plane(0xffffff, vec3(1, 0, 0), 5));
	add_object(data->scene, plane(0xffffff, vec3(0, 1, 0), 2));
	add_object(data->scene, plane(0xffffff, vec3(0, 0, -1), 10));

	add_object(data->scene, sphere(0xff0000, vec3(2, -1, -5), 1));
	add_object(data->scene, sphere(0xffff00, vec3(-1, 0, -7), 1));
//	add_object(data->scene, sphere(0xffff00, vec3(-2, 1, -5), 1));

	add_object(data->scene, cylindre(0xffffff, vec3(-3, 0, -7), vec3(0, 1, 0)));

	add_light(data->scene, light(0xffff00, vec3(-4, -1.5, -5)));
	add_light(data->scene, light(0x00ffff, vec3(4, 0, 0)));
}

void		add_object(t_scene *scene, t_object obj)
{
	t_list *new;

	new = ft_lstnew(&obj, sizeof(t_object));
	ft_lstadd(&scene->objects, new);
}

void		add_light(t_scene *scene, t_light light)
{
	t_list *new;

	new = ft_lstnew(&light, sizeof(t_light));
	ft_lstadd(&scene->lights, new);
}

static int	hit_color(t_data *data, t_hit hit)
{
	t_object	object;
	t_vec3		final_color;
	t_vec3		light_color;

	object = *((t_object *)hit.obj);
	light_color = calc_lights(data, hit);
	final_color = vec3_mul(object.color, light_color);
	return (to_color(final_color));
}

void		draw_scene(t_data *data, t_ray ray, t_vec2 pix)
{
	t_hit	hit;

	hit = throw_ray(data, ray);
	if (hit.dist > 0)
		draw_pix(data, pix.x, pix.y, hit_color(data, hit));
}
