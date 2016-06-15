/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 15:23:31 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:55:59 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst)
{
	t_list	*current;
	t_list	*save;

	if (alst)
	{
		current = *alst;
		while (current)
		{
			if (current->data)
				free(current->data);
			if (current->link)
				free(current->link);
			save = current;
			current = current->next;
			free(save);
		}
		*alst = NULL;
	}
}
