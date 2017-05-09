/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:35:21 by mploux            #+#    #+#             */
/*   Updated: 2017/05/06 19:42:03 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene		*new_scene(t_data *data, char *scene_path)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)ft_memalloc(sizeof(t_scene))))
		error("malloc error !");
	(void) scene_path;
	scene->objects = NULL;
	scene->lights = NULL;
	scene->camera = NULL;
	scene->ambiant_light = vec3(20, 20, 20);
	scene->data = data;
	parse_scene(scene, scene_path);
	if (!scene->camera)
		scene->camera = new_camera(data, vec3(0, 0, 0), vec3(0, 0, 0), 70.0);
	return (scene);
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
