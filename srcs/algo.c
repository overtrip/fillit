/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 14:39:58 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/27 18:16:22 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	If is possible to put the piece in the grid o do it
*/

typedef struct	s_pair
{
	int		x;
	int		y;
}				t_pair;

static int	insert_piece(char **grid, char **piece, int pos_grid, int pos_piece)
{
	t_pair	grid_start;
	t_pair	cursor;
	int		error;

	ft_bzero(&cursor, sizeof(t_pair));
	grid_start.x = pos_grid / 10;
	grid_start.y = pos_grid % 10;
	grid_start.x -= pos_piece / 10;
	grid_start.y -= pos_piece % 10;
	error = 0;
	while (cursor.y < 4)
	{
		cursor.x = 0;
		while (cursor.x < 4)
		{
			if (grid[grid_start.y + cursor.y][grid_start.x + cursor.x] != '.' &&
					piece[cursor.y][cursor.x] != '.')
				error++;
			cursor.x++;
		}
		cursor.y++;
	}
	if (!error)
	{
		cursor.y = 0;
		while (cursor.y < 4)
		{
			cursor.x = 0;
			while (cursor.x < 4)
			{
				printf("[ %c ]\n", grid[grid_start.y + cursor.y][grid_start.x + cursor.x]);
				grid[grid_start.y + cursor.y][grid_start.x + cursor.x] =
					piece[cursor.y][cursor.x];
				cursor.x++;
			}
			cursor.y++;
		}
	}
	return (error);
}

/*
**	Test if it's possible to put the piece in the grid
*/

static int	match(char **grid, char **piece)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = -1;
	while (piece[++k])
	{
		l = -1;
		while (piece[k][++l] && piece[k][l] == '.')
			;
		if (piece[k][l] && piece[k][l] != '.')
			break ;
	}
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '.')
				if (insert_piece(grid, piece, (i * 10) + j, k * 10 + l))
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

void		backtrack(char **grid, t_map *map)
{
	if (!map)
		return ;
	while (match(grid, map->tab))
		map = map->next;
	if (map)
	{
		create_grid(grid);
		backtrack(grid, map);
	}
}

/*
**	Prepare and launch backtrack resolution
*/

void		preparation(t_map **map)
{
	char	**grid;

	grid = NULL;
	init_grid(&grid);
	backtrack(grid, *map);
	print_grid(grid);
	delete_tab(grid);
}
