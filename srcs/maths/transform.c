/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:03:44 by mploux            #+#    #+#             */
/*   Updated: 2017/04/11 17:10:32 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

t_transform	transform(t_vec3 pos, t_vec3 rot, t_vec3 scale)
{
	t_transform result;

	result.pos = pos;
	result.rot = rot;
	result.scale = scale;
	return (result);
}

t_mat4		mat4_translate(t_vec3 v)
{
	t_mat4 result;

	result = mat4_identity();
	result.m[3] = v.x;
	result.m[7] = v.y;
	result.m[11] = v.z;
	return (result);
}

t_mat4		mat4_rotate_v(t_vec3 rot)
{
	t_mat4	x;
	t_mat4	y;
	t_mat4	z;

	x = mat4_identity();
	y = mat4_identity();
	z = mat4_identity();
	x.m[5] = cos(DTR(rot.x));
	x.m[6] = -sin(DTR(rot.x));
	x.m[9] = sin(DTR(rot.x));
	x.m[10] = cos(DTR(rot.x));
	y.m[0] = cos(DTR(rot.y));
	y.m[2] = sin(DTR(rot.y));
	y.m[8] = -sin(DTR(rot.y));
	y.m[10] = cos(DTR(rot.y));
	z.m[0] = cos(DTR(rot.z));
	z.m[1] = -sin(DTR(rot.z));
	z.m[4] = sin(DTR(rot.z));
	z.m[5] = cos(DTR(rot.z));
	return (mat4_mul(z, mat4_mul(y, x)));
}

t_mat4		mat4_rotate_vi(t_vec3 rot)
{
	t_mat4	x;
	t_mat4	y;
	t_mat4	z;

	x = mat4_identity();
	y = mat4_identity();
	z = mat4_identity();
	x.m[5] = cos(DTR(rot.x));
	x.m[6] = -sin(DTR(rot.x));
	x.m[9] = sin(DTR(rot.x));
	x.m[10] = cos(DTR(rot.x));
	y.m[0] = cos(DTR(rot.y));
	y.m[2] = sin(DTR(rot.y));
	y.m[8] = -sin(DTR(rot.y));
	y.m[10] = cos(DTR(rot.y));
	z.m[0] = cos(DTR(rot.z));
	z.m[1] = -sin(DTR(rot.z));
	z.m[4] = sin(DTR(rot.z));
	z.m[5] = cos(DTR(rot.z));
	return (mat4_mul(x, mat4_mul(y, z)));
}

t_mat4		mat4_scale(t_vec3 v)
{
	t_mat4 result;

	result = mat4_identity();
	result.m[0] = v.x;
	result.m[5] = v.y;
	result.m[10] = v.z;
	return (result);
}
