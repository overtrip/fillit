/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 15:06:28 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/27 13:44:51 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Search theoretical minimal size of the grid square
*/

int		size_min_square(t_map *map)
{
	int	i;
	int	square_min;

	i = 0;
	square_min = 2;
	while (map && ++i)
		map = map->next;
	i *= 4;
	while ((square_min * square_min) < i)
		++square_min;
	return (square_min);
}

/*
**	Initialise a grid of size 4 * 4
*/

void	init_grid(char ***tab)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = g_size + 1;
	if (!((*tab) = (char **)malloc(sizeof(char *) * g_size)))
		return ;
	while (i < g_size)
	{
		if (!((*tab)[i] = (char *)malloc(sizeof(char) * end)))
			return ;
		ft_memset((*tab)[i], '.', g_size);
		(*tab)[i][g_size] = '\0';
		++i;
	}
}

/*
**	Create a new grid who swell of size + 1 when none pieces can't enter
*/

void	create_grid(char ***grid)
{
	size_t	i;
	size_t	end;

	delete_old_tab(grid);
	++g_size;
	if (!((*grid) = (char **)malloc(sizeof(char *) * (g_size))))
		return ;
	i = 0;
	end = g_size + 1;
	while (i < g_size)
	{
		if (!((*grid)[i] = (char *)malloc(sizeof(char) * end)))
			return ;
		ft_memset((*grid)[i], '.', g_size);
		(*grid)[i][g_size] = '\0';
		++i;
	}
	*grid = (*grid);
}
