/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:10:33 by mploux            #+#    #+#             */
/*   Updated: 2016/12/20 18:43:16 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <stdlib.h>
# include <string.h>
# include "input.h"
# include "mlx.h"
# include "libft.h"
# include "maths.h"
# include "graphics.h"
# include "input.h"

typedef struct s_mesh		t_mesh;
typedef struct s_bitmap		t_bitmap;
typedef struct s_input		t_input;

typedef struct	s_win
{
	void		*ctx;
	int			w;
	int			h;
	char		*name;
}				t_win;

typedef struct	s_data
{
	void		*mlx;
	t_win		*win;
	t_input		*input;
	t_bitmap	*framebuffer;
}				t_data;

int				error(char *error);
int				create_rt(t_data *data, const char *name, int width,
																	int height);
void			loop_rt(t_data *data);
void			exit_rt(t_data *data);

#endif
