/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:07:59 by mploux            #+#    #+#             */
/*   Updated: 2016/12/24 19:52:56 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light	light(int color, t_vec3 pos)
{
	t_light		light;

	light.pos = pos;
	light.color = vec3_mul_d(color_to_vec3(color), 1.0 / 255.0);
	return (light);
}

int		calc_shadow(t_data *data, t_light light, t_hit hit)
{
	double	shadow_dist;
	double	light_dist;
	t_vec3	light_dir;
	t_vec3	light_diff;

	light_diff = vec3_sub(light.pos, hit.pos);
	light_dist = vec3_mag(light_diff);
	light_dir = vec3_normalize(light_diff);
	shadow_dist = throw_ray(data, nray(hit.pos, light_dir)).dist;
	if (shadow_dist > 0 && shadow_dist <= light_dist)
		return (0);
	return (1);
}

double	calc_specular(t_data *data, t_vec3 light_dir, t_hit hit)
{
	double	result;
	t_vec3	light_reflection;
	t_vec3	cam_dir;

	light_reflection = vec3_reflect(vec3_mul_d(light_dir, -1), hit.normal);
	cam_dir = vec3_normalize(vec3_sub(data->camera->pos, hit.pos));
	result = pow(clamp(vec3_dot(cam_dir, light_reflection), 0, 1), 10);
	return (result);
}

t_vec3	calc_light(t_data *data, t_light light, t_hit hit)
{
	t_vec3	light_diff;
	t_vec3	light_dir;
	double	light_intensity;
	double	light_dist;
	t_vec3	light_color;

	light_diff = vec3_sub(light.pos, hit.pos);
	light_dir = vec3_normalize(light_diff);
	light_intensity = clamp(vec3_dot(hit.normal, light_dir), 0, 1);
	light_intensity *= calc_shadow(data, light, hit);
	light_dist = vec3_mag(light_diff);
	light_intensity *= 1.0 / (light_dist * 0.5 + 0.5);
	light_intensity += calc_specular(data, light_dir, hit);
	light_color = vec3_mul_d(light.color, light_intensity);
	return (light_color);
}

t_vec3	calc_lights(t_data *data, t_hit hit)
{
	t_list	*lights;
	t_vec3	light_color;
	t_light	light;

	lights = data->scene->lights;
	light_color = vec3(0, 0, 0);
	while (lights)
	{
		light = *((t_light *)lights->content);
		light_color = vec3_add(light_color, calc_light(data, light, hit));
		lights = lights->next;
	}
	light_color = vec3_clamp(light_color, 0, 1);
	return (light_color);
}