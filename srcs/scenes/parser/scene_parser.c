/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:00:35 by mploux            #+#    #+#             */
/*   Updated: 2017/05/16 14:02:19 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "parser.h"

int		get_error(t_error error)
{
	if (error.error_id == P_OK.error_id)
		return (0);
	return (1 << error.error_id);
}

void	init_errors(t_data *data)
{
	int i;

	i = -1;
	while (++i < P_MAX)
		data->errors[i] = (t_error){0, ""};
	data->errors[P_OK.error_id] = P_OK;
	data->errors[P_I_OBJECT_NAME.error_id] = P_I_OBJECT_NAME;
	data->errors[P_I_OBJECT_COLOR.error_id] = P_I_OBJECT_COLOR;
	data->errors[P_I_OBJECT_POS.error_id] = P_I_OBJECT_POS;
	data->errors[P_I_OBJECT_ROT.error_id] = P_I_OBJECT_ROT;
	data->errors[P_I_OBJECT_SCALE.error_id] = P_I_OBJECT_SCALE;
	data->errors[P_I_OBJECT_DIR.error_id] = P_I_OBJECT_DIR;
	data->errors[P_I_OBJECT_DIST.error_id] = P_I_OBJECT_DIST;
	data->errors[P_I_OBJECT_PARAM.error_id] = P_I_OBJECT_PARAM;
	data->errors[P_I_SCENE_FILE.error_id] = P_I_SCENE_FILE;
}

int		verify_scene(char *line)
{
	int ret;

	ret = 0;
	if (line[0] == '\t')
		ret |= get_error(P_I_OBJECT_PARAM);
	else
	{
		if (!ft_strequ(line, "camera:") && !ft_strequ(line, "ambiant_light:") &&
			!ft_strequ(line, "light:") && !ft_strequ(line, "sphere:") &&
			!ft_strequ(line, "cylindre:") && !ft_strequ(line, "cone:") &&
			!ft_strequ(line, "plane:"))
			ret |= get_error(P_I_OBJECT_NAME);
	}
	return (ret);
}

int		parse_scene_data(t_scene *scene, char *name)
{
	int		fd;
	char	*line;
	int		ret;
	int		res;

	ret = get_error(P_OK);
	line = NULL;
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (get_error(P_I_SCENE_FILE));
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (!ft_strchr(line, '#') && line[0] != '\n' && line[0] != 0)
			if ((ret |= verify_scene(line)) == 0)
				ret |= parse_objects(fd, scene, &line);
		ft_strdel(&line);
		if (ret != 0)
			break ;
	}
	close(fd);
	if (res < 0)
		ret |= get_error(P_I_SCENE_FILE);
	return (ret);
}

int		parse_scene(t_scene *scene, char *name)
{
	int ret;
	int	i;

	i = -1;
	ret = parse_scene_data(scene, name);
	if (ret != 0)
	{
		while (++i < P_MAX)
			if ((ret & (1 << i)) != 0)
			{
				ft_putstr(T_RED"Scene error: ");
				ft_putstr(scene->data->errors[i].error);
				ft_putendl(T_NRM);
			}
		exit(-1);
	}
	return (ret);
}
