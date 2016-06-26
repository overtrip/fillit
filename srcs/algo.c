/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 14:39:58 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/26 18:20:38 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	If is possible to put the piece in the grid o do it
*/

static int	insert_piece(char **grid, char **piece, int position)
{
	int	i;
	int	j;

	i = position / 10;
	j = position % 10;

	// TODO create a flood fill to complete grid while the piece
	return (1);
}

/*
**	Test if it's possible to put the piece in the grid
*/

static int	match(char **grid, char **piece)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
				if (insert_piece(grid, piece, (i * 10) + j))
					return (1);
			++j;
		}
		++i;
	}
	return (0);
}

/*
**	Try all possibility in backtrack
*/

void	backtrack(char **grid, t_map *map)
{
	while (map)
	{
		if (match(grid, map->tab))
			map = map->next;
		else
			backtrack(grid, map->next);
	}
	if (!map->next)
	{
		create_grid(grid);
		backtrack(grid, map->next);
	}
	else
		return ;
}

/*
**	Prepare and launch backtrack resolution
*/

void	preparation(t_map **map)
{
	char	**grid;

	grid = NULL;
	init_grid(&grid);
	backtrack(grid, *map);
	print_grid(grid);
	delete_tab(grid);
}
