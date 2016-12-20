/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 01:21:39 by mploux            #+#    #+#             */
/*   Updated: 2016/12/20 18:45:17 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int			key_hook(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		exit_rt(data);
	data->input->key[key] = 1;
	return (1);
}

int			key_up_hook(int key, t_data *data)
{
	data->input->key[key] = 0;
	return (1);
}
