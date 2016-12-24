/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mploux <mploux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:10:33 by mploux            #+#    #+#             */
/*   Updated: 2016/12/24 18:41:42 by mploux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define PLANE 0
# define SPHERE	1
# define CONE 2
# define CYLINDRE 3

typedef	unsigned int 		s_uint;

# include <SDL2/SDL.h>
# include <stdlib.h>
# include <string.h>
# include "input.h"
# include "mlx.h"
# include "libft.h"
# include "maths.h"
# include "graphics.h"
# include "input.h"

# include <stdio.h> //////////

typedef struct s_mesh		t_mesh;
typedef struct s_bitmap		t_bitmap;
typedef struct s_input		t_input;

typedef struct	s_win
{
	// void		*ctx;
	int			w;
	int			h;
	char		*name;
}				t_win;

typedef struct	s_ray
{
	t_vec3		pos;
	t_vec3		dir;
}				t_ray;

typedef struct	s_hit
{
	void		*obj;
	t_vec3		pos;
	t_vec3		normal;
	double		dist;
}				t_hit;

typedef struct	s_object
{
	t_vec3		pos;
	t_vec3		rot;
	t_vec3		scale;
	t_vec3		color;
	t_hit		(*intersect)(t_data*, struct s_object, t_ray);
}				t_object;

typedef struct	s_camera
{
	t_mat4		proj;
	double		fov;
	double		aspect;
	double		z_near;
	double		z_far;
	t_vec3		pos;
	t_vec3		rot;
	t_vec3		scale;
	double		zoom;
	t_mat4		trs;
	t_vec3		apos;
	t_vec3		arot;
	t_vec3		ascale;
	int			azoom;
}				t_camera;

typedef struct	s_scene
{
	t_list		*objects;
	int			size;
}				t_scene;

typedef struct	s_data
{
	SDL_Window	*sdl_win;
	SDL_Surface	*sdl_surface;
	// void		*mlx;
	t_win		*win;
	t_input		*input;
	t_bitmap	*framebuffer;
	double		*zbuffer;
	t_camera	*camera;
	t_scene		*scene;
}				t_data;

t_object		sphere(int color, t_vec3 pos, double radius);
t_hit			intersect_sphere(t_data *data, t_object obj, t_ray ray);
t_object		plane(int color, t_vec3 pos, double radius);
t_hit			intersect_plane(t_data *data, t_object obj, t_ray ray);
t_object		cylindre(int color, t_vec3 pos, t_vec3 rot);
t_hit			intersect_cylindre(t_data *data, t_object obj, t_ray ray);

void			new_sdl_display(t_data *data, const char *name, int width,
																	int height);
void			sdl_loop(t_data *data, int (*loop)(t_data *));
int				error(char *error);
int				create_rt(t_data *data, const char *name, int width,
																	int height);
void			loop_rt(t_data *data);
void			exit_rt(t_data *data);
t_camera		*new_camera(t_data *data, t_transform trs, double fov);
t_object		object(t_transform trs, int type, t_hit (*intersect)
													(t_data*, t_object, t_ray));
t_ray			ray(t_vec3 pos, t_vec3 dir);
t_ray			cam_ray(t_data *data, double x, double y);
t_hit			hit(t_object *obj, t_vec3 pos, t_vec3 normal, double dist);
t_scene			*new_scene();
void			manage_scene(t_data *data);
void			add_object(t_scene *scene, t_object obj);
void			draw_scene(t_data *data, t_ray ray, t_vec2 pix, int iteration);
double			*new_zbuffer(int width, int height);
void			clear_zbuffer(t_data *data, double z_far);
void			draw_depth(t_data *data, int x, int y, double depth);
double			get_depth(t_data *data, int x, int y);

#endif
