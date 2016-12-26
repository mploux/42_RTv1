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
	t_scene	*s;

	s = data->scene;
	add_object(s, plane(0xffffff, vec3(0, -1, 0), 2));
	add_object(s, plane(0xffffff, vec3(-1, 0, 0), 5));
	add_object(s, plane(0xffffff, vec3(1, 0, 0), 5));
	add_object(s, plane(0xffffff, vec3(0, 1, 0), 2));
	add_object(s, plane(0xffffff, vec3(0, 0, -1), 10));

	add_object(s, sphere(0xff0000, vec3(-2, -2.2, -4), 1));
	add_object(s, sphere(0xff0000, vec3(-2, -2.2, -8), 1));
	add_object(s, sphere(0xff0000, vec3(2, -2.2, -4), 1));
	add_object(s, sphere(0xff0000, vec3(2, -2.2, -8), 1));

	add_object(s, sphere(0xff0000, vec3(-2, 2.2, -4), 1));
	add_object(s, sphere(0xff0000, vec3(-2, 2.2, -8), 1));
	add_object(s, sphere(0xff0000, vec3(2, 2.2, -4), 1));
	add_object(s, sphere(0xff0000, vec3(2, 2.2, -8), 1));

	add_object(s, cylindre(0xffffff, vec3(-2, 0, -4), vec3(0, 1, 0), 0.5));
	add_object(s, cylindre(0xffffff, vec3(-2, 0, -8), vec3(0, 1, 0), 0.5));
	add_object(s, cylindre(0xffffff, vec3(2, 0, -4), vec3(0, 1, 0), 0.5));
	add_object(s, cylindre(0xffffff, vec3(2, 0, -8), vec3(0, 1, 0), 0.5));

	add_light(s, light(0xffff00, vec3(0, -1.5, -6)));
	add_light(s, light(0xff0000, vec3(4, 1, -7)));
	add_light(s, light(0x00ffff, vec3(-4, 0, -1)));
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