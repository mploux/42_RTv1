#include "parser.h"

t_vec3		parse_rot(char **toks, int *ret)
{
	t_vec3 result;

	result = vec3(0, 0, 0);
	if (!toks || !toks[0])
	{
		*ret |= get_error(P_I_OBJECT_ROT);
		return (result);
	}
	if (ft_strequ(toks[0], "\trot:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret |= get_error(P_I_OBJECT_ROT);
	}
	else if (ft_strequ(toks[0], "\tdir:"))
	{
		if (toks[1] && toks[2] && toks[3])
			result = vec3(ft_atoi(toks[1]), ft_atoi(toks[2]), ft_atoi(toks[3]));
		else
			*ret |= get_error(P_I_OBJECT_DIR);
	}
	return (result);
}
