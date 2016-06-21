/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:23:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/21 18:22:04 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Check how much line between each declaration blocks
*/

static int		call_line(int *cmp_line, char *str, int *point)
{
	if ((++(*cmp_line) == 5 && *str != 0))
		return (1);
	else if ((*cmp_line) == 5)
	{
		(*cmp_line) = 0;
		*point = 0;
	}
	return (0);
}

/*
**	Count how much piece point there are in block
*/

static int		nb_points(int *point, int *cmp_line)
{
	if (*point > 4 || (*point < 4 && *cmp_line == 4))
		return (1);
	return (0);
}

/*
**	Check all errors functions and each patern point of global map
*/

int				valide_line(char *str, int *cmp_line, int *point)
{
	int	i;

	i = -1;
	if (nb_points(point, cmp_line) || call_line(cmp_line, str, point))
		return (print_error_msg());
	while (str[++i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != 0)
			return (print_error_msg());
		if (str[i] == '#')
			++(*point);
	}
	if ((i > 4 || i < 4) && !(i == 0 && str[i] == 0))
		return (print_error_msg());
	else
		return (0);
}

/*
**	TODO IN PROGRESS
*/


static int		find_hash_char(t_map *map, int *i, int *j)
{
	int		y;
	char	*found;
	int		pos;

	y = 0;
	while (map->tab[y])
	{
		if ((found = ft_strchr(map->tab[y], '#')))
		{
			if (j)
				*j = y;
			if (i)
				*i = found - map->tab[y];
			return (1);
		}
		j++;
	}
	return (0);
}

static void		flood_fill(t_map *map, int i, int j, char c)
{
	if (i < 0 || j < 0 || i > 3 || j > 3 || map->tab[j][i] != '#')
		return ;
	if (map->tab[j][i] == '#')
		map->tab[j][i] = c;
	flood_fill(map, i - 1, j, c);
	flood_fill(map, i, j - 1, c);
	flood_fill(map, i + 1, j, c);
	flood_fill(map, i, j + 1, c);
}

int				connection(t_map *map, char c)
{
	int		i;
	int		j;

	if (!find_hash_char(map, &i, &j))
		return (1);
	flood_fill(map, i, j, c);
	if(!find_hash_char(map, NULL, NULL))
		return (1);
	return (0);
}

void			backtracking(int	**tab)
{
	int		i;

	i = 0;
	if (resolu())
		return ;
	if (!verif(tab))
		return ;
	while (i < 10)
	{
		tab[0][0] = i;
		backtracking(tab+1);
		tab[0][0] = 0;
		++i;
	}

}
