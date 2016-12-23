/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:57:52 by mploux            #+#    #+#             */
/*   Updated: 2016/12/23 18:48:16 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "rt.h"
# include "maths.h"

typedef struct s_data		t_data;

typedef struct	s_bitmap
{
	t_data		*data;
	void		*ctx;
	int			width;
	int			height;
	char		*pixels;
	int			bpp;
	int			sl;
	int			endian;
}				t_bitmap;

void			draw_screen(t_data *data);
void			draw_text(t_data *data, t_vec2 pos, int color, char *string);
void			draw_pix(t_data *data, double x, double y, int color);
void			draw_line(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
void			draw_line_x(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
void			draw_line_y(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
t_bitmap		*new_bitmap(t_data *data, int width, int height);
void			bitmap_draw_pix(t_bitmap *b, int x, int y, int color);
void			clear_bitmap(t_bitmap *b);
int				col_lerp(int a, int b, double n);
int				color(int r, int g, int b);
int				color_angle(int angle, int sat);
int				to_color(t_vec3 v);
t_vec3			color_to_vec3(int color);

#endif
