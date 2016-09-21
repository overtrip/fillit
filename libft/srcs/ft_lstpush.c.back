/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 17:01:20 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:56:40 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list	*cursor;

	cursor = *alst;
	if (alst)
	{
		if (*alst && new)
		{
			while (cursor->next)
				cursor = cursor->next;
			cursor->next = new;
		}
		else
			*alst = new;
	}
}
