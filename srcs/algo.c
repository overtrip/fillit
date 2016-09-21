/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:25:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/21 17:45:23 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	If they are no error put the piece on the grid
*/

void	put_piece(char **grid, char **piece, const t_pair g, const t_pair p)
{
	t_pair	s;

	s.i = p.i - 1;
	s.j = p.j - 1;
	while (++s.i < 4)
	{
		while (++s.j < 4)
		{
			if (INGRID(g, s, p) && piece[s.i][s.j] != '.')
				grid[g.i + s.i - p.i][g.j + s.j - p.j] = piece[s.i][s.j];
		}
		s.j = -1;
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

	s.i = p.i - 1;
	s.j = p.j - 1;
	error = 0;
	while (++s.i < 4)
	{
		while (++s.j < 4)
		{
			if (piece[s.i][s.j] != '.')
			{
				if (!INGRID(g, s, p) || grid[g.i + s.i - p.i][g.j + s.j - p.j] != '.')
					++error;
			}
		}
		s.j = -1;
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
	while (++p.i < 4 && (p.j = -1))
	{
		while (++p.j < 4 && piece[p.i][p.j] == '.')
			;
		if (piece[p.i][p.j] && piece[p.i][p.j] != '.')
			break ;
	}
	while (++g.i < (int)g_size && (g.j = -1))
	{
		while (++g.j < (int)g_size)
			if (grid[g.i][g.j] == '.')
				if (!insert_piece(grid, piece, g, p))
					return (1);
	}
	if (g.i == (int)g_size)
		return (0);
	return (1);
}

/*
**	Try all possibility in backtrack
*/

void	backtrack(char ***grid, t_map *map)
{
	if (!map)
		return ;
	while (map)
	{
		if (match(*grid, map->tab))
		{
/*	ft_putendl("[+++ PIECE +++]");
	print_piece(map->tab);
	ft_putendl("[+++ END +++]");
	ft_putchar('\n');
*/	ft_putendl("[--- g_size ---]");
	print_grid(*grid);
	ft_putendl("[--- END ---]");
	ft_putchar('\n');
			map = map->next;
		}
		else
			create_grid(grid);
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
	backtrack(&grid, *map);
	print_grid(grid);
	delete_tab(&grid);
}
