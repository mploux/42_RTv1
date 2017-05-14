/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:53:10 by mploux            #+#    #+#             */
/*   Updated: 2017/05/14 18:53:51 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vec3		parse_color(char *line, int *ret, t_vec3 color)
{
	t_vec3	result;
	char	**toks;

	result = vec3(255, 0, 255);
	if (color.x != result.x || color.y != result.y || color.z != result.z)
		return (color);
	toks = ft_strsplit(line, ' ');
	if (!toks || !toks[0])
	{
		*ret |= get_error(P_I_OBJECT_COLOR);
		return (result);
	}
	if (ft_strequ(toks[0], "\tcolor:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret |= get_error(P_I_OBJECT_COLOR);
	}
	ft_tabclear(&toks);
	return (result);
}
