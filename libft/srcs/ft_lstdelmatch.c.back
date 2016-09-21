/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelmatch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 19:15:09 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:55:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstdelmatch(t_list **alst, void *data, int (*cmp)(void*, void*))
{
	t_list	*ret;

	if (!*alst)
		return (NULL);
	ret = ft_lstdelmatch(&((*alst)->next), data, cmp);
	if (cmp((*alst)->content, data))
	{
		free((*alst)->content);
		free(*alst);
		*alst = ret;
		return (ret);
	}
	else
	{
		(*alst)->next = ret;
		return (*alst);
	}
}
