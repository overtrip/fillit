/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:25:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/27 13:50:25 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	If they are no error put the piece on the grid
*/

static void	put_slab(char ***grid, char **piece, const t_pair g, const t_pair p)
{
	t_pair	s;

	s.i = p.i - 1;
	s.j = p.j - 1;
	while (++s.i < 4)
	{
		while (++s.j < 4)
		{
			if (INGRID(g, s, p) && piece[s.i][s.j] != '.')
				(*grid)[g.i + s.i - p.i][g.j + s.j - p.j] = piece[s.i][s.j];
		}
		s.j = -1;
	}
}

/*
**	Test the piece if it's possible to put
*/

static int	insert_piece(char ***grid, char **piece, const t_pair g,
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
				if (!INGRID(g, s, p) ||
						(*grid)[g.i + s.i - p.i][g.j + s.j - p.j] != '.')
					++error;
			}
		}
		s.j = -1;
	}
	if (!error)
		put_slab(grid, piece, g, p);
	return (error);
}

/*
**	Find the beginning of the piece
*/

static void	find_beginning_piece(char **piece, t_pair *p)
{
	while (++(*p).i < 4 && ((*p).j = -1))
	{
		while (++(*p).j < 4 && piece[(*p).i][(*p).j] == '.')
			;
		if (piece[(*p).i][(*p).j] && piece[(*p).i][(*p).j] != '.')
			break ;
	}
}

/*
**	Try all possibility in backtrack
*/

static int	backtrack(char **grid, t_map *map)
{
	t_pair p;
	t_pair g;

	if (!map)
		return (0);
	ft_bzero(&g, sizeof(t_pair));
	ft_bzero(&p, sizeof(t_pair));
	g.i = -1;
	p.i = -1;
	find_beginning_piece(map->tab, &p);
	while (++g.i < (int)g_size && (g.j = -1))
	{
		while (++g.j < (int)g_size)
		{
			if (!insert_piece(&grid, map->tab, g, p))
			{
				if (!backtrack(grid, map->next))
					return (0);
				erase_try(&grid, map->tab, g, p);
			}
		}
	}
	return (1);
}

/*
**	Prepare and launch backtrack resolution
*/

void		preparation(t_map **map)
{
	char	**grid;

	grid = NULL;
	g_size = size_min_square(*map);
	init_grid(&grid);
	while (backtrack(grid, *map) != 0)
		create_grid(&grid);
	print_grid(grid);
	delete_tab(&grid);
}
