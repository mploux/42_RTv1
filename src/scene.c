/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:35:21 by mploux            #+#    #+#             */
/*   Updated: 2016/12/30 21:18:59 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene		*new_scene()
{
	t_scene		*scene;
	t_object	obj[4];
	size_t		size;

	if (!(scene = (t_scene *)ft_memalloc(sizeof(t_scene*))))
		error("malloc error !");
	scene->objects = NULL;
	scene->lights = NULL;
	obj[0] = plane(0xffffff, vec3(0, -1, 0), 2);
	obj[1] = sphere(0xffffff, vec3(0, 0, -3), 1);
	obj[2] = cylindre(0xffffff, vec3(0, 0, -5), vec3(0, 1, 0), 1);
	obj[3] = plane(0xff0000, vec3(0, 1, 0), 2);
	size = sizeof(t_object);
	ft_mapadd(&scene->names, ft_mapnew("plane", ft_memdup(&obj[0], size)));
	ft_mapadd(&scene->names, ft_mapnew("sphere", ft_memdup(&obj[1], size)));
	ft_mapadd(&scene->names, ft_mapnew("cylindre", ft_memdup(&obj[2], size)));
	ft_mapadd(&scene->names, ft_mapnew("cone", ft_memdup(&obj[3], size)));
	return (scene);
}

void		manage_scene(t_data *data)
{
	t_scene	*s;

	s = data->scene;
	// add_object(s, plane(0xffffff, vec3(0, -1, 0), 2));
	// add_object(s, plane(0xffffff, vec3(-1, 0, 0), 5));
	// add_object(s, plane(0xffffff, vec3(1, 0, 0), 5));
	// add_object(s, plane(0xffffff, vec3(0, 1, 0), 2));
	// add_object(s, plane(0xffffff, vec3(0, 0, -1), 10));
	//
	// add_object(s, sphere(0xffffff, vec3(-2, -2.2, -4), 1));
	// add_object(s, sphere(0xffffff, vec3(-2, -2.2, -8), 1));
	// add_object(s, sphere(0xffffff, vec3(2, -2.2, -4), 1));
	// add_object(s, sphere(0xffffff, vec3(2, -2.2, -8), 1));
	//
	// add_object(s, sphere(0xffffff, vec3(-2, 2.2, -4), 1));
	// add_object(s, sphere(0xffffff, vec3(-2, 2.2, -8), 1));
	// add_object(s, sphere(0xffffff, vec3(2, 2.2, -4), 1));
	// add_object(s, sphere(0xffffff, vec3(2, 2.2, -8), 1));
	//
	// add_object(s, cylindre(0xffffff, vec3(-2, 0, -4), vec3(0, 1, 0), 0.5));
	// add_object(s, cylindre(0xffffff, vec3(-2, 0, -8), vec3(0, 1, 0), 0.5));
	// add_object(s, cylindre(0xffffff, vec3(2, 0, -4), vec3(0, 1, 0), 0.5));
	// add_object(s, cylindre(0xffffff, vec3(2, 0, -8), vec3(0, 1, 0), 0.5));
	//
	// add_light(s, light(0xffff00, vec3(0, -1.5, -6)));
	add_light(s, light(0xffffff, vec3(-4, 0, -1)));
	load_scene(s, "scene.yaml");
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
