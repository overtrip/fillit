/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:25:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/21 13:36:28 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	If they are no error put the piece on the grid
*/

void	put_piece(char **grid, char **piece, const t_pair g, const t_pair p)
{
	t_pair	s;

	s.i = -1;
	while (piece[++s.i] && s.i + p.i < 4)
	{
		s.j = -1;
		while (piece[s.i][++s.j] && s.j + p.j < 4)
		{
			if (grid[g.i + s.i] && piece[p.i + s.i][p.j + s.j] != '.' &&
					grid[g.i + s.i][g.j + s.j])
				grid[g.i + s.i][g.j + s.j] = piece[p.i + s.i][p.j + s.j];
		}
	}
}

/*
**	Test the piece if it's possible to put
*/

int		insert_piece(char **grid, char **piece, const t_pair g,
				const t_pair p)
{
	t_pair	s;
	int		error;

	s.i = -1;
	error = 0;
	while (piece[++s.i] && s.i + p.i < 4)
	{
		s.j = -1;
		while (piece[s.i][++s.j] && s.j + p.j < 4)
		{
			if (grid[s.i + g.i] && piece[p.i + s.i][p.j + s.j] != '.' &&
					grid[g.i + s.i][g.j + s.j] != '.')
				++error;
		}
	}
	if (!error)
		put_piece(grid, piece, g, p);
	return (error);
}

/*
**	Find a '.' on the grid and first block of piece
*/

int		match(char **grid, char **piece)
{
	t_pair p;
	t_pair g;

	ft_bzero(&g, sizeof(t_pair));
	ft_bzero(&p, sizeof(t_pair));
	g.i = -1;
	p.i = -1;
	while (piece[++p.i] && (p.j = -1))
	{
		while (piece[p.i][++p.j] && piece[p.i][p.j] == '.')
			;
		if (piece[p.i][p.j] && piece[p.i][p.j] != '.')
			break ;
	}
	while (grid[++g.i] && (g.j = -1))
	{
		while (grid[g.i][++g.j])
			if (grid[g.i][g.j] == '.')
				if (!insert_piece(grid, piece, g, p))
					return (1);
	}
	if (!grid[g.i])
		return (0);
	return (1);
}

/*
**	Try all possibility in backtrack
*/

void	backtrack(char **grid, t_map *map)
{
	if (!map)
		return ;
	while (map)
	{
		if (match(grid, map->tab))
			map = map->next;
		else
			create_grid(&grid);
	}
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
