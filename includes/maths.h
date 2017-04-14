/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:27:50 by mploux            #+#    #+#             */
/*   Updated: 2017/04/11 17:10:53 by mploux           ###   ########.fr       */
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
	float		x;
	float		y;
}				t_vec2;

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

typedef struct	s_mat4
{
	float		m[16];
}				t_mat4;

typedef struct	s_transform
{
	t_vec3		pos;
	t_vec3		rot;
	t_vec3		scale;
}				t_transform;

float			clamp(float a, float min, float max);
int				balance(int min, int max, int v);
t_vec2			vec2(float x, float y);
t_vec3			vec3(float x, float y, float z);
t_vec3			vec3_add(t_vec3 a, t_vec3 b);
t_vec3			vec3_normalize(t_vec3 a);
t_vec3			vec3_sub(t_vec3 a, t_vec3 b);
float			vec3_dot(t_vec3 a, t_vec3 b);
float			vec3_mag(t_vec3 a);
t_vec3			vec3_mul_d(t_vec3 a, float d);
t_vec3			vec3_mul(t_vec3 a, t_vec3 b);
t_vec3			vec3_clamp(t_vec3 v, float min, float max);
t_vec3			vec3_reflect(t_vec3 dir, t_vec3 normal);
t_vec3			mat4_mul_vec3(t_mat4 a, t_vec3 b);
t_vec4			vec4(float x, float y, float z, float w);
t_vec4			vec2_2(t_vec2 a, t_vec2 b);
t_vec4			mat4_mul_vec4(t_mat4 a, t_vec4 b);
t_mat4			mat4(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d);
t_mat4			mat4_identity();
t_mat4			mat4_mul(t_mat4 a, t_mat4 b);
t_mat4			mat4_translate(t_vec3 v);
t_mat4			mat4_rotate_v(t_vec3 rot);
t_mat4			mat4_rotate_vi(t_vec3 rot);
t_mat4			mat4_scale(t_vec3 v);
t_mat4			mat4_ortho(t_vec2 w, t_vec2 h, t_vec2 d);
t_mat4			mat4_persp(float fov, float aspect, float near, float far);
t_mat4			mat4_screen_space(float h_width, float h_height);
t_transform		transform(t_vec3 pos, t_vec3 rot, t_vec3 scale);

#endif
