/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 15:28:21 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/19 17:26:39 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
**	Free all elements in memory and suppres leaks
*/

void		delete_all(t_map **map)
{
	del_map(map);
}
