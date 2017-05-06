#ifndef PARSER_H
# define PARSER_H

# include "rt.h"

/*
 *	add_correct_object : This is not good.
 *	TODO: Implement a better way than if, else if, else
 */

int			add_correct_object(t_scene *s, char *obj, t_vec3 col,
															t_transform trs);
t_vec3		parse_color(char *line, int *ret, t_vec3 color);
t_vec3		parse_pos(char **toks, int *ret);
t_vec3		parse_rot(char **toks, int *ret);
t_vec3		parse_scale(char **toks, int *ret);
t_transform parse_transform(char *line, int *ret, t_transform trs);
int			parse_objects(int fd, t_scene *s, char **line);
int			parse_scene_data(t_scene *scene, char *name);

#endif
