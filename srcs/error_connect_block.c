/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_connect_block.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:08:23 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/25 16:23:49 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Search an occurence of '#' in a string and return the position
*/

static int		find_hash_char(t_map *map, int *i, int *j)
{
	int		y;
	char	*found;

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
		++y;
	}
	return (0);
}

/*
**	Change char '#' by a current letter
*/

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

/*
**	Lunch fllod fill and detect error in a block
*/

int				connection(t_map *map, char c)
{
	int		i;
	int		j;

	if (!find_hash_char(map, &i, &j))
		return (1);
	flood_fill(map, i, j, c);
	if (find_hash_char(map, NULL, NULL))
		return (1);
	return (0);
}

/*
**	check if they are a piece in block
*/

int				presence_piece(t_map *map)
{
	int	i;
	int	presence;

	while (map)
	{
		i = 0;
		presence = 0;
		while (map->tab[i])
		{
			if (strchr(map->tab[i], '#'))
				++presence;
			++i;
		}
		if (!presence)
			return (1);
		map = map->next;
	}
	return (0);
}
