/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:27:50 by mploux            #+#    #+#             */
/*   Updated: 2016/12/15 20:13:38 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <math.h>

# define ABS(x) (x < 0 ? -(x) : x)
# define DTR(angle) (angle * M_PI / 180)
# define LERP(a, b, n) (a + (b - a) * n)

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

double			clamp(double a, double min, double max);
int				balance(int min, int max, int v);
t_vec2			vec2(double x, double y);
t_vec3			vec3(double x, double y, double z);
t_vec3			vec3_add(t_vec3 *a, t_vec3 b);
t_vec4			vec4(double x, double y, double z, double w);
t_vec4			vec2_2(t_vec2 a, t_vec2 b);

#endif
