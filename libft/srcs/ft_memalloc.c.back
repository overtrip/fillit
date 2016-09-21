/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:40:57 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:54:42 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*memory;
	unsigned int	i;

	memory = (char *)malloc(size);
	if (memory)
	{
		i = 0;
		while (i < size)
		{
			memory[i] = 0;
			i++;
		}
	}
	else
		memory = NULL;
	return (memory);
}
