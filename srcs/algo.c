/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 14:39:58 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/28 18:16:14 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

typedef struct	s_pair
{
	int		x;
	int		y;
}				t_pair;

/*
**	If they are no error put the piece on the grid
*/

static void	put_piece(char **grid, char **piece, t_pair pos_g, t_pair pos_p)
{
	pos_p.y = 0;
	while (pos_p.y < 4)
	{
		pos_p.x = 0;
		while (pos_p.x < 4)
		{
			grid[pos_g.y + pos_p.y][pos_g.x + pos_p.x] =
				piece[pos_p.y][pos_p.x];
			pos_p.x++;
		}
		pos_p.y++;
	}
}


/*
**	Test the piece if it's possible to put
*/

static int	insert_piece(char **grid, char **piece, int pos_grid, int pos_piece)
{
	t_pair	pos_g;
	t_pair	pos_p;
	int		error;

	ft_bzero(&pos_p, sizeof(t_pair));
	pos_g.x = pos_grid / 10;
	pos_g.y = pos_grid % 10;
	pos_p.x -= pos_piece / 10;
	pos_p.y -= pos_piece % 10;
	error = 0;
	while (pos_p.y < 4 && piece[pos_p.y])
	{
		pos_p.x = 0;
		while (pos_p.x < 4 && piece[pos_p.x][pos_p.y])
		{
//			printf("[%d](pos_g.y)\t[%d](pos_g.x)\t[%d](pos_p.y)\t[%d](pos_p.x)\n", pos_g.y, pos_g.x, pos_p.y, pos_p.x);
//			printf("** %c %c**\n", grid[pos_g.x][pos_g.y], piece[pos_p.x][pos_p.y]);
				if ( grid[pos_g.y + pos_p.y][pos_g.x + pos_p.x] != '.' &&
					piece[pos_p.y][pos_p.x] != '.')
				++error;
			++pos_p.x;
		}
		++pos_p.y;
	}
	if (!error)
	{
			printf("** %c %c**\n", grid[pos_g.x][pos_g.y], piece[pos_p.x][pos_p.y]);
		put_piece(grid, piece, pos_g, pos_p);
	}
	return (error);
}

/*
**	Find a '.' on the grid and first block of piece
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
				if (!insert_piece(grid, piece, (i * 10) + j, k * 10 + l))
					 ;
			++j;
		}
		++i;
	}
	if (!grid[i][j])
		return (1);
	return (0);
}

/*
**	Try all possibility in backtrack
*/

void		backtrack(char **grid, t_map *map)
{
	if (!map)
		return ;
	while (map)
	{
		if (!match(grid, map->tab))
			map = map->next;
		else
		{
			create_grid(grid);
			backtrack(grid, map);
		}
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
