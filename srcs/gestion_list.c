/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:57:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/27 18:07:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Use to reverse map to conforme the subjetc
*/

t_map			*pt_map(t_map *map)
{
	t_map	*map_next;
	t_map	*top_of_stack;

	top_of_stack = NULL;
	while (map)
	{
		map_next = map->next;
		map->next = top_of_stack;
		top_of_stack = map;
		map = map_next;
	}
	return (top_of_stack);
}

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
**	Push front function for t_map *
*/

static void		push_elem(t_map **map, t_map *new)
{
	new->next = *map;
	*map = new;
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
	if (!(str && cmp_line))
		return ;
	if (!*map || cmp_line == 1)
	{
		if (!(new = create_block()))
			return ;
		push_elem(map, new);
	}
	while ((*map)->tab[i])
		++i;
	(*map)->tab[i] = ft_strdup(str);
}
