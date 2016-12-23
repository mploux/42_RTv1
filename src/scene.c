/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:35:21 by mploux            #+#    #+#             */
/*   Updated: 2016/12/23 20:20:34 by mploux           ###   ########.fr       */
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

static void	draw_object(t_data *data, t_object object, t_ray ray, t_vec2 pix)
{
	t_hit	hit;
	double	light_intensity;
	t_vec3	final_color;

	hit = object.intersect(data, object, ray);
	if (hit.dist > 0 && hit.dist <= get_depth(data, pix.x, pix.y))
	{
		light_intensity = clamp(vec3_dot(hit.normal, vec3_normalize(vec3_sub(vec3(3, -1, -5), hit.pos))), 0, 1);
		final_color = vec3_mul_d(object.color, light_intensity);
		draw_depth(data, (int)pix.x, (int)pix.y, hit.dist);
		draw_pix(data, (int)pix.x, (int)pix.y, to_color(final_color));
	}
}

void		draw_scene(t_data *data, t_ray ray, t_vec2 pix, int iteration)
{
	t_list		*list;
	t_object	object;

	list = data->scene->objects;
	iteration++;
	while (list)
	{
		object = *((t_object *)list->content);
		draw_object(data, object, ray, pix);
		list = list->next;
	}
}
