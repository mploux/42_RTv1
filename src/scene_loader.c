/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:21:52 by mploux            #+#    #+#             */
/*   Updated: 2017/01/01 19:56:57 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <fcntl.h>

void		parse_data(t_object *o, char *name, char *data)
{
	char **toks;

	toks = ft_strsplit(data, ' ');
	if (ft_strcmp(name, "pos") && toks[0] && toks[1] && toks[2])
		o->pos = vec3(ft_atoi(toks[0]), ft_atoi(toks[1]), ft_atoi(toks[2]));
	else if (ft_strcmp(name, "rot") && toks[0] && toks[1] && toks[2])
		o->rot = vec3(ft_atoi(toks[0]), ft_atoi(toks[1]), ft_atoi(toks[2]));
	else if (ft_strcmp(name, "color") && toks[0] && toks[1] && toks[2])
		o->color = vec3(ft_atoi(toks[0]), ft_atoi(toks[1]), ft_atoi(toks[2]));
	else if (ft_strcmp(name, "dist") && toks[0])
		o->dist = ft_atoi(toks[0]);

}

void		load_scene(t_scene *s, char *file)
{
	int			fd;
	char		*line;
	void		*object;
	char		**toks;

	fd = open(file, O_RDONLY);
	object = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 0)
			continue;
		toks = ft_strsplit(line, ':');
		if (line[0] == '\t' && toks[1] && object)
		{
			parse_data((t_object *)(s->objects->content), toks[0], toks[1]);
			continue;
		}
		object = ft_mapget(s->names, toks[0]);
		if (object == NULL)
			continue;
		add_object(s, *((t_object *)object));
		ft_strdel(&line);
	}
	close(fd);
}
