/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:07:59 by mploux            #+#    #+#             */
/*   Updated: 2016/12/24 19:52:56 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "graphics.h"
#include <stdlib.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	t_data	*data;

	(void) av;
	(void) ac;
	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		error("malloc error !");
	create_rt(data, "RTv1 !", 1280, 720);
	loop_rt(data);
	return (0);
}
