/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:10:33 by mploux            #+#    #+#             */
/*   Updated: 2017/05/14 19:17:39 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <SDL.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "maths.h"
# include "graphics.h"

typedef struct s_data		t_data;
typedef struct s_mesh		t_mesh;
typedef struct s_bitmap		t_bitmap;
typedef struct s_input		t_input;
typedef struct s_win		t_win;
typedef struct s_light		t_light;
typedef struct s_ray		t_ray;
typedef struct s_hit		t_hit;
typedef struct s_camera		t_camera;
typedef struct s_quadratic	t_quadratic;
typedef struct s_object		t_object;
typedef struct s_scene		t_scene;
typedef struct s_error		t_error;

# define P_MAX				(int)(sizeof(int) * 8)
# define P_OK				(t_error){0, "No error"}
# define P_I_OBJECT_NAME	(t_error){1, "Invalide object name"}
# define P_I_OBJECT_COLOR	(t_error){2, "Invalide object color"}
# define P_I_OBJECT_POS		(t_error){3, "Invalide object position"}
# define P_I_OBJECT_ROT		(t_error){4, "Invalide object rotation"}
# define P_I_OBJECT_SCALE	(t_error){5, "Invalide object scale"}
# define P_I_OBJECT_DIR		(t_error){6, "Invalide object direction"}
# define P_I_OBJECT_DIST	(t_error){7, "Invalide object distance"}
# define P_I_OBJECT_PARAM	(t_error){8, "Invalide object param"}
# define P_I_SCENE_FILE		(t_error){9, "Invalide scene file"}

struct			s_error
{
	int			error_id;
	char		*error;
};

struct			s_win
{
	int			w;
	int			h;
	char		*name;
};

struct			s_light
{
	t_vec3		pos;
	t_vec3		color;
	float		intensity;
};

struct			s_ray
{
	t_vec3		pos;
	t_vec3		dir;
};

struct			s_hit
{
	void		*obj;
	t_vec3		pos;
	t_vec3		normal;
	float		dist;
	t_vec3		specular;
};

struct			s_camera
{
	t_mat4		proj;
	float		fov;
	float		aspect;
	float		z_near;
	float		z_far;
	t_vec3		pos;
	t_vec3		rot;
	float		zoom;
	t_mat4		trs;
	t_vec3		apos;
	t_vec3		arot;
	t_vec3		ascale;
	int			azoom;
};

struct			s_quadratic
{
	float		a;
	float		b;
	float		c;
	float		d;
	float		e;
	float		f;
	float		g;
	float		h;
	float		i;
	float		j;
};

struct			s_object
{
	t_quadratic	quadra;
	t_vec3		pos;
	t_vec3		rot;
	t_vec3		scale;
	t_vec3		color;
	float		dist;
	t_hit		(*intersect)(struct s_object, t_ray);
};

struct			s_scene
{
	t_data		*data;
	t_camera	*camera;
	t_vec3		ambiant_light;
	t_list		*objects;
	t_list		*lights;
};

struct			s_data
{
	SDL_Window	*sdl_win;
	SDL_Surface	*sdl_surface;
	t_win		*win;
	t_bitmap	*framebuffer;
	t_scene		*scene;
	t_error		errors[P_MAX];
};

t_object		sphere(int color, t_vec3 pos, t_vec3 rot, t_vec3 scale);
t_hit			intersect_sphere(t_object obj, t_ray ray);
t_object		plane(int color, t_vec3 dir, float dist);
t_hit			intersect_plane(t_object obj, t_ray ray);
t_object		cylindre(int color, t_vec3 pos, t_vec3 rot, t_vec3 scale);
t_hit			intersect_cylindre(t_object obj, t_ray ray);
t_object		cone(int color, t_vec3 pos, t_vec3 rot, t_vec3 angle);
t_hit			intersect_cone(t_object obj, t_ray ray);

t_light			light(int color, t_vec3 pos, float intensity);
t_vec3			calc_light(t_data *data, t_light light, t_hit *hit);
t_vec3			calc_lights(t_data *data, t_hit *hit);

t_hit			quadratic_object_intersect(t_object *object, t_ray *ray);
float			quadratic_intersect(t_quadratic *quadra, t_vec3 *dir,
																t_vec3 *eye);
void			quadratic_rotate_x(float angle, t_quadratic *quadra);
void			quadratic_rotate_y(float angle, t_quadratic *quadra);
void			quadratic_rotate_z(float angle, t_quadratic *quadra);
void			quadratic_scale(t_vec3 scale, t_quadratic *quadra);
void			quadratic_translate(t_vec3 pos, t_quadratic *quadra);
t_vec3			quadratic_normal(t_quadratic *q, t_vec3 pos, t_vec3 dir);

void			new_sdl_display(t_data *data, const char *name, int width,
																	int height);
void			sdl_loop(t_data *data, int (*loop)(t_data *));
int				error(char *error);
int				create_rt(t_data *data, const char *name, int width,
																	int height);
void			loop_rt(t_data *data);
void			exit_rt(t_data *data);
t_camera		*new_camera(t_data *data, t_vec3 pos, t_vec3 rot, float fov);
t_object		object(t_transform trs, int type, t_hit (*intersect)
													(t_object, t_ray));
t_ray			nray(t_vec3 pos, t_vec3 dir);
t_hit			throw_ray(t_data *data, t_ray ray);
t_ray			cam_ray(t_data *data, float x, float y);
t_scene			*new_scene(t_data *data, char *scene_path);
void			manage_scene(t_scene *s);
int				parse_scene(t_scene *scene, char *name);
void			add_object(t_scene *scene, t_object obj);
void			add_light(t_scene *scene, t_light light);
void			draw_scene(t_data *data, t_ray ray, t_vec2 pix);
void			init_errors(t_data *data);
int				get_error(t_error error);

#endif
