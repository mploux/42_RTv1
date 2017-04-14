/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 18:51:35 by mploux            #+#    #+#             */
/*   Updated: 2017/04/12 13:53:56 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	hit_color(t_data *data, t_hit *hit)
{
	t_object	object;
	t_vec3		final_color;
	t_vec3		light_color;

	object = *((t_object *)hit->obj);
	light_color = calc_lights(data, hit);
	final_color = vec3_mul(object.color, light_color);
	final_color = vec3_add(final_color, hit->specular);
	final_color = vec3_clamp(final_color, 0, 255);
	return (to_color(final_color));
}

void		draw_scene(t_data *data, t_ray ray, t_vec2 pix)
{
	t_hit	hit;

	hit = throw_ray(data, ray);
	hit.specular = vec3(0, 0, 0);
	if (hit.dist > 0)
		draw_pix(data, pix.x, pix.y, hit_color(data, &hit));
}
