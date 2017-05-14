/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 18:53:25 by mploux            #+#    #+#             */
/*   Updated: 2017/05/14 18:54:19 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_transform		parse_transform(char *line, int *ret, t_transform trs)
{
	t_transform	result;
	char		**toks;

	toks = ft_strsplit(line, ' ');
	if (trs.pos.x == 0 && trs.pos.y == 0 && trs.pos.z == 0)
		result.pos = parse_pos(toks, ret);
	else
		result.pos = trs.pos;
	if (trs.rot.x == 0 && trs.rot.y == 0 && trs.rot.z == 0)
		result.rot = parse_rot(toks, ret);
	else
		result.rot = trs.rot;
	if (trs.scale.x == 0 && trs.scale.y == 0 && trs.scale.z == 0)
		result.scale = parse_scale(toks, ret);
	else
		result.scale = trs.scale;
	ft_tabclear(&toks);
	return (result);
}
