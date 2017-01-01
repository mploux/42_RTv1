/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 06:54:34 by mploux            #+#    #+#             */
/*   Updated: 2016/12/30 20:56:30 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_mapget(t_map *map, char *key)
{
	t_map *tmp;

	tmp = map;
	while (tmp)
	{
		if (ft_strcmp(key, tmp->key) == 0)
			return (tmp->data);
		tmp = tmp->next;
	}
	return (NULL);
}

void		*ft_mapget_key(t_map *map, void *data)
{
	t_map *tmp;

	tmp = map;
	while (tmp)
	{
		if (tmp->data == data)
			return (tmp->key);
		tmp = tmp->next;
	}
	return (NULL);
}
