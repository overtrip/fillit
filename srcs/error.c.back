/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:23:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/24 18:03:41 by jealonso         ###   ########.fr       */
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

int				valide_line(char *str, int *cmp_line, int *point, int *alert)
{
	int	i;

	i = -1;
	if (nb_points(point, cmp_line) || call_line(cmp_line, str, point))
		return (++*alert);
	while (str[++i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != 0)
			return (++*alert);
		if (str[i] == '#')
			++(*point);
	}
	if ((i > 4 || i < 4) && !(i == 0 && str[i] == 0))
		return (++*alert);
	else
		return (0);
}

/*
**	Count if they are more 27 pieces
*/

int				count_piece(t_map *map)
{
	int	nb;

	nb = 0;
	while (map)
	{
		++nb;
		map = map->next;
	}
	if (nb >= 27)
		return (1);
	return (0);
}

/*
**	Lunch a loop to test all pieces blocks are connect
*/

int				error_connection(t_map *map)
{
	char	letter;

	letter = 'A';
	while (map)
	{
		if (connection(map, letter))
			return (1);
		++letter;
		map = map->next;
	}
	return (0);
}
