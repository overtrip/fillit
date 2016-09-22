/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 15:06:28 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/22 14:56:07 by jealonso         ###   ########.fr       */
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
	while(map && ++i)
		map = map->next;
	i *= 4;
	while ((square_min * square_min)  < i)
		++square_min;
	return (square_min);
}


/*
**	Duplicate a grid
*/

void			dup_grid(char ***grid, char ***save)
{
	char	**new;
	size_t	i;

	i = 0;
	delete_tab(grid);
	if (!(new = (char **)malloc(sizeof(char *) * g_size + 1)))
		return ;
	i = 0;
	while (i < g_size)
	{
		new[i] = ft_strdup((*save)[i]);
		++i;
	}
	*grid = new;
}

/*
**	Initialise a grid of size 4 * 4
*/

void			init_grid(char ***tab)
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

void			create_grid(char ***grid)
{
	size_t	i;
	size_t	end;
	char	**new_tab;

	if (!(new_tab = (char **)malloc(sizeof(char *) * (g_size + 1))))
		return ;
	i = 0;
	++g_size;
	end = g_size + 1;
	while (i < g_size)
	{
		if (!(new_tab[i] = (char *)malloc(sizeof(char) * end)))
			return ;
		if (i + 1 != g_size)
			ft_memcpy(new_tab[i], (*grid)[i], g_size - 1);
		else
			ft_memset(new_tab[i], '.', g_size);
		new_tab[i][g_size - 1] = '.';
		new_tab[i][g_size] = '\0';
		++i;
	}
	delete_old_tab(grid);
	*grid = new_tab;
}
