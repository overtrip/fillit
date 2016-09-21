/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 16:23:53 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:54:27 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*temp;
	t_list	*save;
	t_list	*save_current;

	save = NULL;
	current = lst;
	while (current)
	{
		if (!(temp = ft_lstnew(current->content, current->content_size)))
			return (NULL);
		temp = f(temp);
		if (!save)
		{
			save = temp;
			save_current = save;
		}
		else
		{
			save_current->next = temp;
			save_current = save_current->next;
		}
		current = current->next;
	}
	return (save);
}
