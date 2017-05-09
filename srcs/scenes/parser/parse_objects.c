#include "parser.h"

/*
 *	This is not good.
 *	TODO: Implement a better way than if, else if, else
 */

int		add_correct_object(t_scene *s, char *obj, t_vec3 col, t_transform trs)
{
	int		color;

	color = to_color(col);
	if (ft_strequ(obj, "plane:"))
		add_object(s, plane(color, trs.rot, trs.scale.x));
	else if (ft_strequ(obj, "sphere:"))
		add_object(s, sphere(color, trs.pos, trs.rot, trs.scale));
	else if (ft_strequ(obj, "cylindre:"))
		add_object(s, cylindre(color, trs.pos, trs.rot, trs.scale));
	else if (ft_strequ(obj, "cone:"))
		add_object(s, cone(color, trs.pos, trs.rot, trs.scale));
	else if (ft_strequ(obj, "light:"))
		add_light(s, light(color, trs.pos, trs.scale.x / 100.0));
	else if (ft_strequ(obj, "ambiant_light:"))
		s->ambiant_light = col;
	else if (ft_strequ(obj, "camera:"))
		s->camera = new_camera(s->data, trs.pos, trs.rot, trs.scale.x);
	else
		return (get_error(P_I_OBJECT_NAME));
	return (get_error(P_OK));
}

int		parse_objects(int fd, t_scene *s, char **line)
{
	int			ret;
	char		*obj;
	t_vec3		color;
	t_transform	trs;

	color = vec3(255, 0, 255);
	obj = ft_strdup(*line);
	ret = get_error(P_OK);
	trs = transform(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0, 0, 0));
	ft_strdel(line);
	get_next_line(fd, line);
	if ((*line)[0] != '\t')
		return (get_error(P_I_OBJECT_PARAM));
	while (*line && (*line)[0] == '\t')
	{
		color = parse_color(*line, &ret, color);
		trs = parse_transform(*line, &ret, trs);
		ft_strdel(line);
		get_next_line(fd, line);
	}
	ret |= add_correct_object(s, obj, color, trs);
	return (ret);
}
