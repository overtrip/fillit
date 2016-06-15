/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:57:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/15 17:55:40 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_line(t_list **map, char *str)
{
	t_list	*tmp;

	if (!str)
		return ;
	if ((tmp = ft_create_elem(str)))
		ft_list_push_back(map, tmp);
}

void	delete_all(t_list **map)
{
	ft_lstdel(map);
}
