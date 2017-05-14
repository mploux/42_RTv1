/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:07:59 by mploux            #+#    #+#             */
/*   Updated: 2017/05/14 18:52:54 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light	light(int color, t_vec3 pos, float intensity)
{
	t_light		light;

	light.pos = pos;
	light.color = vec3_mul_d(color_to_vec3(color), 1.0 / 255.0);
	light.intensity = intensity;
	return (light);
}

int		calc_shadow(t_data *data, t_light light, t_hit *hit)
{
	float	shadow_dist;
	float	light_dist;
	t_vec3	light_dir;
	t_vec3	light_diff;

	light_diff = vec3_sub(light.pos, hit->pos);
	light_dist = vec3_mag(light_diff);
	light_dir = vec3_normalize(light_diff);
	shadow_dist = throw_ray(data, nray(hit->pos, light_dir)).dist;
	if (shadow_dist > 0 && shadow_dist < light_dist)
		return (0);
	return (1);
}

t_vec3	calc_specular(t_data *data, float light_int, t_light light, t_hit *hit)
{
	t_vec3	result;
	float	intensity;
	t_vec3	light_reflection;
	t_vec3	cam_dir;
	t_vec3	light_dir;

	light_dir = vec3_normalize(vec3_sub(light.pos, hit->pos));
	light_reflection = vec3_reflect(vec3_mul_d(light_dir, -1), hit->normal);
	cam_dir = vec3_normalize(vec3_sub(data->scene->camera->pos, hit->pos));
	intensity = pow(clamp(vec3_dot(cam_dir, light_reflection), 0, 1), 10);
	intensity *= light.intensity;
	result = vec3_mul_d(light.color, intensity * 255 * light_int);
	result = vec3_add(hit->specular, result);
	return (result);
}

t_vec3	calc_light(t_data *data, t_light light, t_hit *hit)
{
	t_vec3	light_diff;
	t_vec3	light_dir;
	float	light_intensity;
	float	light_dist;
	t_vec3	light_color;

	light_diff = vec3_sub(light.pos, hit->pos);
	light_dir = vec3_normalize(light_diff);
	light_intensity = clamp(vec3_dot(hit->normal, light_dir), 0, 1);
	light_intensity *= calc_shadow(data, light, hit);
	light_dist = vec3_mag(light_diff);
	hit->specular = calc_specular(data, light_intensity, light, hit);
	light_intensity *= 1.0 / (light_dist * 0.5 + 0.5);
	light_color = vec3_mul_d(light.color, light_intensity * light.intensity);
	return (light_color);
}

t_vec3	calc_lights(t_data *data, t_hit *hit)
{
	t_list	*lights;
	t_vec3	light_color;
	t_light	light;

	lights = data->scene->lights;
	light_color = vec3_mul_d(data->scene->ambiant_light, 1.0 / 255.0);
	while (lights)
	{
		light = *((t_light *)lights->content);
		light_color = vec3_add(light_color, calc_light(data, light, hit));
		lights = lights->next;
	}
	light_color = vec3_clamp(light_color, 0, 1);
	return (light_color);
}
