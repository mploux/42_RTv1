/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:14:30 by mploux            #+#    #+#             */
/*   Updated: 2016/12/16 01:26:46 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_input		*new_input(void)
{
	t_input	*input;
	int		i;

	if (!(input = (t_input *)ft_memalloc(sizeof(t_input))))
		error("malloc error !");
	i = -1;
	while (++i < KEY_SIZE)
		input->key[i] = 0;
	return (input);
}
