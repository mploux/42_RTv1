/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:53:14 by mploux            #+#    #+#             */
/*   Updated: 2017/05/16 14:01:57 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
		add_light(s, light(color, trs.pos, trs.scale.x / 100.0));
	else if (ft_strequ(obj, "ambiant_light:"))
		s->ambiant_light = col;
	else if (ft_strequ(obj, "camera:"))
		s->camera = new_camera(s->data, trs.pos, trs.rot, trs.scale.x);
	else
		return (get_error(P_I_OBJECT_NAME));
	return (get_error(P_OK));
}

int		verify_object(char *line)
{
	int		ret;
	char	**toks;

	ret = 0;
	if (line[0] != '\t')
		return (get_error(P_I_OBJECT_PARAM));
	toks = ft_strsplit(line, ':');
	if (toks[2] || !toks[1])
		error("INVALID SCENE !");
	if (toks[0][0] == '\t')
	{
		if (!ft_strequ(toks[0], "\tpos") && !ft_strequ(toks[0], "\trot") &&
			!ft_strequ(toks[0], "\tscale") && !ft_strequ(toks[0], "\tfov") &&
			!ft_strequ(toks[0], "\tdist") &&
			!ft_strequ(toks[0], "\tintensity") &&
			!ft_strequ(toks[0], "\tdir") && !ft_strequ(toks[0], "\tcolor"))
			ret |= get_error(P_I_OBJECT_PARAM);
	}
	else if (ft_strchr(line, '#') || line[0] == '\n' || line[0] == 0)
		ret |= 0;
	else
		ret |= get_error(P_I_OBJECT_PARAM);
	ft_tabclear(&toks);
	return (ret);
}

int		parse_objects(int fd, t_scene *s, char **line)
{
	int			ret;
	char		*obj;
	t_vec3		color;
	t_transform	trs;

	color = vec3(255, 0, 255);
	obj = ft_strdup(*line);
	ret = get_error(P_OK);
	trs = transform(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0));
	ft_strdel(line);
	get_next_line(fd, line);
	while (*line && (*line)[0] == '\t')
	{
		if ((ret = verify_object(*line)) != 0)
			break ;
		color = parse_color(*line, &ret, color);
		trs = parse_transform(*line, &ret, trs);
		ft_strdel(line);
		get_next_line(fd, line);
	}
	ft_strdel(line);
	ret |= add_correct_object(s, obj, color, trs);
	ft_strdel(&obj);
	return (ret);
}
