/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 07:33:27 by mploux            #+#    #+#             */
/*   Updated: 2016/12/30 19:56:20 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_mapclear(t_map **map)
{
	t_map *tmp;

	tmp = *map;
	while (*map)
	{
		tmp = (*map)->next;
		ft_memdel(&((*map)->key));
		ft_memdel(&((*map)->data));
		ft_memdel((void **)map);
		*map = tmp;
	}
}
