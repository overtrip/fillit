/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:25:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/29 18:24:39 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	If they are no error put the piece on the grid
*/

static void	put_piece(char **grid, char **piece, t_pair g, t_pair p)
{

	p.i = -1;
	printf("*[%d][%d]*\n", g.i, g.j);
	while (piece[++p.i] && p.i < 4)
	{
		p.j = -1;
		while (piece[p.i][++p.j] && p.j < 4)
		{
//			printf("grid[%d][%d] = |%c|\tpiece[%d][%d] = |%c|\n", g.i + (p.i - g.i), g.j + (p.j - g.j), grid[g.i + (p.i - g.i)][g.j + (p.j - g.j)], p.i, p.j, piece[p.i][p.j]);
			if (piece[p.i][p.j] != '.' && grid[g.i + (p.i - g.i)][g.j + (p.j - g.j)])
			{
				grid[g.i + (p.i - g.i)][g.j + (p.j - g.j)] = piece[p.i][p.j];
			printf("grid[%d][%d] = |%c|\tpiece[%d][%d] = |%c|\n", g.i + (p.i - g.i), g.j + (p.j - g.j), grid[g.i + (p.i - g.i)][g.j + (p.j - g.j)],	p.i, p.j, piece[p.i][p.j]);
			}
		}
	}
}


/*
**	Test the piece if it's possible to put
*/

static int	insert_piece(char **grid, char **piece, t_pair pos_g, t_pair pos_p)
{
	t_pair	g;
	t_pair	p;
	int		error;

	ft_bzero(&g, sizeof(t_pair));
	ft_bzero(&p, sizeof(t_pair));
	p = pos_p;
	g = pos_g;
	error = 0;
	while (piece[p.i] && p.i < 4)
	{
		p.j = -1;
		while (piece[p.i][++p.j] && p.j < 4)
		{
			if (grid[g.i + (p.i - g.i)][g.j + (p.j - g.j)] != '.' && piece[p.i][p.j] != '.')
				++error;
			++p.j;
		}
		++p.i;
	}
	if (!error)
		put_piece(grid, piece, g, p);
	return (error);
}

/*
**	Find a '.' on the grid and first block of piece
*/

static int	match(char **grid, char **piece)
{
	t_pair p;
	t_pair g;

	ft_bzero(&g, sizeof(t_pair));
	ft_bzero(&p, sizeof(t_pair));
	g.i = -1;
	p.i = -1;
	while (piece[++p.i])
	{
		p.j = -1;
		while (piece[p.i][++p.j] && piece[p.i][p.j] == '.')
			;
		if (piece[p.i][p.j] && piece[p.i][p.j] != '.')
			break ;
	}
	while (grid[++g.i])
	{
		g.j = -1;
		while (grid[g.i][++g.j])
		{
			if (grid[g.i][g.j] == '.')
				if (!insert_piece(grid, piece, g, p))
					return (1);
		}
	}
	if (!grid[g.i][g.j])
		return (0);
	return (1);
}

/*
**	Try all possibility in backtrack
*/

void		backtrack(char **grid, t_map *map, char **save)
{
	if (!map)
		return ;
	while (map)
	{
		if (!match(grid, map->tab))
		{
			backtrack(grid, map->next, save);
			grid = save;
			map = map->next;
		}
	}
	create_grid(grid);
}

/*
**	Prepare and launch backtrack resolution
*/

void		preparation(t_map **map)
{
	char	**grid;
	char	**begin;

	grid = NULL;
	init_grid(&grid);
	init_grid(&begin);
	backtrack(grid, *map, begin);
	print_grid(grid);
	delete_tab(grid);
}
