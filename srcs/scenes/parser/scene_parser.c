/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:00:35 by mploux            #+#    #+#             */
/*   Updated: 2017/05/05 20:27:38 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		add_correct_object(t_scene *s, char *obj, t_vec3 col, t_transform trs)
{
	int		color;

	color = to_color(col);
	if (ft_strequ(obj, "plane:"))
		add_object(s, plane(color, trs.rot, trs.scale.x));
	else if (ft_strequ(obj, "sphere:"))
		add_object(s, sphere(color, trs.pos, trs.rot, trs.scale));
	else if (ft_strequ(obj, "cylindre:"))
		add_object(s, cylindre(color, trs.pos, trs.rot, trs.scale));
	else if (ft_strequ(obj, "cone:"))
		add_object(s, cone(color, trs.pos, trs.rot, trs.scale));
	else if (ft_strequ(obj, "light:"))
		add_light(s, light(color, trs.pos));
	else if (ft_strequ(obj, "ambiant_light:"))
		s->ambiant_light = col;
	else if (ft_strequ(obj, "camera:"))
		s->camera = new_camera(s->data, trs.pos, trs.rot, trs.scale.x);
	else
		return (P_I_OBJECT_NAME);
	return (P_OK);
}

t_vec3		parse_color(char *line, int *ret)
{
	t_vec3	result;
	char	**toks;

	result = vec3(255, 0, 255);
	toks = ft_strsplit(line, ' ');
	if (!toks || !toks[0])
	{
		*ret &= P_I_OBJECT_COLOR;
		return (result);
	}
	if (ft_strequ(toks[0], "\tcolor:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret &= P_I_OBJECT_COLOR;
	}
	ft_tabclear(&toks);
	return (result);
}

t_vec3		parse_pos(char **toks, int *ret)
{
	t_vec3 result;

	result = vec3(0, 0, 0);
	if (!toks || !toks[0])
	{
		*ret &= P_I_OBJECT_POS;
		return (result);
	}
	if (ft_strequ(toks[0], "\tpos:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret &= P_I_OBJECT_POS;
	}
	return (result);
}

t_vec3		parse_rot(char **toks, int *ret)
{
	t_vec3 result;

	result = vec3(0, 0, 0);
	if (!toks || !toks[0])
	{
		*ret &= P_I_OBJECT_ROT;
		return (result);
	}
	if (ft_strequ(toks[0], "\trot:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret &= P_I_OBJECT_ROT;
	}
	else if (ft_strequ(toks[0], "\tdir:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret &= P_I_OBJECT_DIR;
	}
	return (result);
}

t_vec3		parse_scale(char **toks, int *ret)
{
	t_vec3 result;

	result = vec3(0, 0, 0);
	if (!toks || !toks[0])
	{
		*ret &= P_I_OBJECT_SCALE;
		return (result);
	}
	if (ft_strequ(toks[0], "\tscale:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret &= P_I_OBJECT_SCALE;
	}
	else if (ft_strequ(toks[0], "\tdist:") || ft_strequ(toks[0], "\tfov:"))
	{
		if (toks[1])
			result = vec3(ft_atoi(toks[1]), 0, 0);
		else
			*ret &= P_I_OBJECT_DIST;
	}
	return (result);
}

t_transform parse_transform(char *line, int *ret, t_transform trs)
{
	t_transform	result;
	char		**toks;

	toks = ft_strsplit(line, ' ');
	if (trs.pos.x == 0 && trs.pos.y == 0 && trs.pos.z == 0)
		result.pos = parse_pos(toks, ret);
	else
		result.pos = trs.pos;
	if (trs.rot.x == 0 && trs.rot.y == 0 && trs.rot.z == 0)
		result.rot = parse_rot(toks, ret);
	else
		result.rot = trs.rot;
	if (trs.scale.x == 0 && trs.scale.y == 0 && trs.scale.z == 0)
		result.scale = parse_scale(toks, ret);
	else
		result.scale = trs.scale;
	ft_tabclear(&toks);
	return (result);
}

int		parse_objects(int fd, t_scene *s, char **line)
{
	int			ret;
	char		*obj;
	t_vec3		color;
	t_transform	trs;

	obj = ft_strdup(*line);
	ret = P_OK;
	trs = transform(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0));
	ft_strdel(line);
	get_next_line(fd, line);
	while (*line && (*line)[0] == '\t')
	{
		color = parse_color(*line, &ret);
		trs = parse_transform(*line, &ret, trs);
		ft_strdel(line);
		get_next_line(fd, line);
	}
	add_correct_object(s, obj, color, trs);
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
		if (line[0] != '\t' && line[0] != '\n' && line[0] != 0)
			if (!ft_strchr(line, '#'))
				ret &= parse_objects(fd, scene, &line);
		ft_strdel(&line);
	}
	if (ret != 0)
	{
		printf("Oups ! Scene problem !");
		exit(0);
	}
	return (ret);
}
