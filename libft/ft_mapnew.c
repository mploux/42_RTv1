/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:10:22 by mploux            #+#    #+#             */
/*   Updated: 2016/12/30 20:56:04 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_map			*ft_mapnew(char *key, void *data)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->key = key;
	map->data = data;
	map->next = NULL;
	return (map);
}
