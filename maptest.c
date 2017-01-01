#include "libft/libft.h"
#include <stdio.h>

typedef struct	s_lol
{
	int		id;
	char	*text;
	char	mdr[5];
}				t_lol;

int main(int ac, char **av)
{
	t_map	*map;

	t_lol	a;
	a.id = 42;
	a.text = "42 forever";
	a.mdr[0] = 'a';
	a.mdr[1] = 'b';
	a.mdr[2] = 'c';
	a.mdr[3] = 'd';
	a.mdr[4] = 'e';

	t_lol	b;
	b.id = 21;
	b.text = "21 forever";
	b.mdr[0] = 'x';
	b.mdr[1] = 'y';
	b.mdr[2] = 'z';
	b.mdr[3] = 'w';
	b.mdr[4] = 'v';

	ft_mapadd(&map, ft_mapnew(&b, &a));
	ft_mapadd(&map, ft_mapnew(&a, &b));

	printf("%s\n", ((t_lol *)ft_mapget(map, &b))->mdr);
}
