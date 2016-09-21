/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:28:21 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/21 13:30:09 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Use only in gestion_grid to win a few lines
*/

void		delete_old_tab(char ***grid, size_t i)
{
	while (i > 0)
		free((*grid)[i-- - 1]);
	free(*grid);
}

/*
**	Delete all elements of map
*/

static void	del_map(t_map **map)
{
	t_map	*current;
	t_map	*save;
	int		i;

	if (map)
	{
		current = *map;
		while (current)
		{
			save = current;
			current = current->next;
			i = -1;
			while (save->tab[++i])
				free(save->tab[i]);
			free(save->tab);
			free(save);
		}
		*map = NULL;
	}
}

/*
**	Free all elemets and tab
*/

void		delete_tab(char **tab)
{
	size_t	i;

	i = 0;
	if (!*tab)
		return ;
	while (i < SIZE)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

/*
**	Free all elements in memory and suppres leaks
*/

void		delete_all(t_map **map)
{
	del_map(map);
}
