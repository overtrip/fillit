/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 15:06:28 by jealonso          #+#    #+#             */
/*   Updated: 2016/07/11 18:08:05 by jealonso         ###   ########.fr       */
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
	if (!*tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
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

	i = 0;
	SIZE = 4;
	if (!((*tab) = (char **)malloc(sizeof(char *) * (SIZE + 1))))
		return ;
	while (i < SIZE)
	{
		if (!((*tab)[i] = (char *)malloc(sizeof(char) * SIZE + 1)))
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
	int		save;
	char	**new_tab;

	if (!(new_tab = (char **)malloc(sizeof(char *) * (count_tab(*grid) + 2))))
		return ;
	i = 0;
	++SIZE;
	save = ft_strlen((*grid)[i]);
	while ((*grid)[i])
	{
		if (!(new_tab[i] = (char *)malloc(sizeof(char) * (SIZE))))
			return ;
		ft_memcpy(new_tab[i], (*grid)[i], save);
		new_tab[i][save] = '.';
		new_tab[i][SIZE] = '\0';
		++i;
	}
	if (!(new_tab[i] = (char *)malloc(sizeof(char) * (SIZE))))
		return ;
	ft_memset(new_tab[i], '.', SIZE);
	new_tab[i][SIZE] = '\0';
	new_tab[++i] = NULL;
	while (--i > 0)
		free((*grid)[i - 1]);
	free(*grid);
	*grid = new_tab;
}
