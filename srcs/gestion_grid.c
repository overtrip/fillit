/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 15:06:28 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/29 16:40:05 by jealonso         ###   ########.fr       */
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
**	Free all elemets and tab
*/

void			delete_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

/*
**	Initialise a grid of size 4 * 4
*/

void			init_grid(char ***tab)
{
	int	i;

	i = 0;
	if (!((*tab) = (char **)malloc(sizeof(char *) * 5)))
		return ;
	ft_bzero((*tab), sizeof(char **));
	while (i < 4)
	{
		if (!((*tab)[i] = (char *)malloc(sizeof(char) * 5)))
			return ;
		ft_memset((*tab)[i], '.', 4);
		++i;
	}
	(*tab)[i] = NULL;
}

/*
**	Create a new grid who swell of size + 1 when none pieces can't enter
*/

void			create_grid(char **grid)
{
	int		i;
	char	**new_tab;
	int		size;

	if (!(new_tab = (char **)malloc(sizeof(char *) * (count_tab(grid) + 2))))
		return ;
	ft_bzero(new_tab, sizeof(char **));
	i = 0;
	size = ft_strlen(grid[i]);
	while (grid[i])
	{
		if (!(new_tab[i] = (char *)malloc(sizeof(char) * (size + 2))))
			return ;
		new_tab[i] = ft_strdup(grid[i]);
		new_tab[i][size + 1] = '.';
		++i;
	}
	ft_memset(new_tab[++i], '.', size + 1);
	new_tab[++i] = NULL;
	while (--i > 0)
		free(grid[i]);
	grid = new_tab;
}
