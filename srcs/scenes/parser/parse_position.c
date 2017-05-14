/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:53:19 by mploux            #+#    #+#             */
/*   Updated: 2017/05/14 18:53:19 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_vec3		parse_pos(char **toks, int *ret)
{
	t_vec3 result;

	result = vec3(0, 0, 0);
	if (!toks || !toks[0])
	{
		*ret |= get_error(P_I_OBJECT_POS);
		return (result);
	}
	if (ft_strequ(toks[0], "\tpos:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret |= get_error(P_I_OBJECT_POS);
	}
	return (result);
}
