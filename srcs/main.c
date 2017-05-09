/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:07:59 by mploux            #+#    #+#             */
/*   Updated: 2017/05/09 20:45:05 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "graphics.h"
#include <stdlib.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		error("Usage: rtv1 scene_file");
	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		error("malloc error !");
	create_rt(data, "RTv1 !", 1280, 720);
	data->scene = new_scene(data, av[1]);
	loop_rt(data);
	return (0);
}
