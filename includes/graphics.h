/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:57:52 by mploux            #+#    #+#             */
/*   Updated: 2017/04/11 13:29:47 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "rt.h"
# include "maths.h"

typedef struct s_data		t_data;

typedef struct		s_bitmap
{
	t_data			*data;
	SDL_Renderer	*sdl_renderer;
	SDL_Texture		*sdl_texture;
	int				width;
	int				height;
	int				*pixels;
}					t_bitmap;

void			draw_screen(t_data *data);
void			draw_pix(t_data *data, double x, double y, int color);
void			draw_line(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
void			draw_line_x(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
void			draw_line_y(t_data *data, t_vec2 a, t_vec2 b, t_vec2 colors);
t_bitmap		*new_bitmap(t_data *data, int width, int height);
void			bitmap_draw_pix(t_bitmap *b, int x, int y, int color);
void			bitmap_update(t_bitmap *b);
void			clear_bitmap(t_bitmap *b);
int				col_lerp(int a, int b, double n);
int				color(int r, int g, int b);
int				color_angle(int angle, int sat);
int				to_color(t_vec3 v);
t_vec3			color_to_vec3(int color);

#endif
