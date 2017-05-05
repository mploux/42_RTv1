/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:04:17 by mploux            #+#    #+#             */
/*   Updated: 2017/05/05 18:32:03 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabclear(char ***tab)
{
	int i;

	if (!tab || !(*tab))
		return ;
	i = -1;
	while ((*tab)[++i])
		ft_strdel(&((*tab)[i]));
	free(*tab);
	*tab = NULL;
}
