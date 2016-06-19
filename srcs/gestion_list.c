/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:57:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/19 18:13:38 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Create a new link with 4 to include blocks
*/

static t_map	*create_block(void)
{
	t_map	*new;
	int		i;

	i = -1;
	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (!(new->tab = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	ft_bzero(new->tab, sizeof(char *) * 5);
	new->next = NULL;
	return (new);
}

/*
**	Push back function for t_map *
*/

static void		push_elem(t_map **map, t_map *new)
{
	t_map	*tmp;

	if (!*map)
		*map = new;
	else
	{
		tmp = *map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

/*
**	Create map links blocks by blocks when size ok link was 4 lines
*/

void			get_line(t_map **map, char *str, int cmp_line)
{
	t_map	*new;
	int		i;

	i = 0;
	new = NULL;
	if (!str)
		return ;
	if (!*map)
		if (!(*map = create_block()))
			return;
	if (cmp_line < 5)
	{
		while ((*map)->tab[i])
			++i;
		if (i == 4)
		{
			if (!(new = create_block()))
				return ;
			push_elem(map, new);
			i = 0;
		}
		(*map)->tab[i] = ft_strdup(str);
	}

/*
**	TODO creer un maillon puis le remplir et enfin le push
*/

/*	if (!(*map) || cmp_line == 0)
	{
		if (!(new = create_block()))
			return ;
		if (!(*map))
			*map = new;
	}
	if (cmp_line < 4)
	{
		while (new->tab[i])
			++i;
		if (i < 4)
			new->tab[i] = ft_strdup(str);
	}
	if (cmp_line == 4)
		push_elem(map, new);*/
}
