/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:21:57 by mploux            #+#    #+#             */
/*   Updated: 2016/12/20 13:04:19 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int			mouse_pos_hook(int x, int y, t_data *data)
{
	data->input->x = x;
	data->input->y = y;
	return (1);
}

int			mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	data->input->button = button;
	return (1);
}
