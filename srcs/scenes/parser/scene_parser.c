/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:00:35 by mploux            #+#    #+#             */
/*   Updated: 2017/05/04 21:04:18 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		add_correct_object(t_scene *s, char *object)
{
	const t_vec3	base_pos = vec3(1, 1, 1);
	const t_vec3	base_rot = vec3(1, 1, 1);
	const t_vec3	base_scale = vec3(1, 1, 1);
	const int		base_color = 0xff00ff;

	printf("%s\n", object);
	if (ft_strequ(object, "plane"))
		add_object(s, plane(base_color, vec3(0, 0, -1), 1));
	else if (ft_strequ(object, "sphere"))
		add_object(s, sphere(base_color, base_pos, base_rot, base_scale));
	else if (ft_strequ(object, "cylindre"))
		add_object(s, cylindre(base_color, base_pos, base_rot, base_scale));
	else if (ft_strequ(object, "cone"))
		add_object(s, cone(base_color, base_pos, base_rot, base_scale));
	else
		return (P_I_OBJECT_NAME);
	return (P_OK);
}

int		parse_objects(t_scene *scene, char *line)
{
	int ret;

	ret = P_OK;
	if (ft_strequ(line, "light"))
		add_light(scene, light(0xffffff, vec3(0, 0, 0)));
	else
		ret &= add_correct_object(scene, line);
	return (ret);
}

int		parse_object_data(t_scene *scene, char *line)
{
	int		ret;
	// char	**toks;
	// t_scene	*s;
	(void) scene;
	(void) line;

	// s = data->scene;
	ret = P_OK;
	// toks = ft_strsplit(line, " ");
	// // if (ft_strequ(toks[0], "pos"))
	// // 	s->objects->content
	return (ret);
}

int		parse_scene(t_scene *scene, char *name)
{
	int		fd;
	char	*line;
	int		ret;

	ret = P_OK;
	line = NULL;
	fd = open(name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\t')
			ret &= parse_objects(scene, line);
		else
			ret &= parse_object_data(scene, line);
		ft_strdel(&line);
	}
	return (ret);
}
