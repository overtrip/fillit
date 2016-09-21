/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 15:06:28 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/21 13:36:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Count size of a table
*/

static int		count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

/*
**	Duplicate a grid
*/

void			dup_grid(char ***grid, char ***save)
{
	char	**new;
	size_t	i;

	i = 0;
	delete_tab(*grid);
	if (!(new = (char **)malloc(sizeof(char *) * SIZE + 1)))
		return ;
	i = 0;
	while (i < SIZE)
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
	SIZE = 4;
	end = SIZE + 1;
	if (!((*tab) = (char **)malloc(sizeof(char *) * end)))
		return ;
	while (i < SIZE)
	{
		if (!((*tab)[i] = (char *)malloc(sizeof(char) * end)))
			return ;
		ft_memset((*tab)[i], '.', SIZE);
		(*tab)[i][SIZE] = '\0';
		++i;
	}
	(*tab)[i] = NULL;
}

/*
**	Create a new grid who swell of size + 1 when none pieces can't enter
*/

void			create_grid(char ***grid)
{
	size_t	i;
	size_t	end;
	char	**new_tab;

	if (!(new_tab = (char **)malloc(sizeof(char *) * (count_tab(*grid) + 2))))
		return ;
	i = 0;
	++SIZE;
	end = SIZE + 1;
	while (i < SIZE - 1)
	{
		if (!(new_tab[i] = (char *)malloc(sizeof(char) * end)))
			return ;
		ft_memcpy(new_tab[i], (*grid)[i], SIZE - 1);
		new_tab[i][SIZE - 1] = '.';
		new_tab[i][SIZE] = '\0';
		++i;
	}
	if (!(new_tab[i] = (char *)malloc(sizeof(char) * end)))
		return ;
	ft_memset(new_tab[i], '.', SIZE);
	new_tab[i][SIZE] = '\0';
	new_tab[SIZE] = NULL;
	delete_old_tab(grid, i);
	*grid = new_tab;
}
