/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:00:28 by mploux            #+#    #+#             */
/*   Updated: 2017/05/14 18:51:51 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit		*new_hit(void)
{
	t_hit *result;

	if (!(result = (t_hit *)ft_memalloc(sizeof(t_hit))))
		return (NULL);
	result->obj = NULL;
	result->pos = vec3(0, 0, 0);
	result->normal = vec3(0, 0, 0);
	result->dist = 0;
	return (result);
}

int			hit_free(t_hit **hit)
{
	if (!hit || !*hit)
		return (0);
	free(*hit);
	*hit = NULL;
	return (1);
}
