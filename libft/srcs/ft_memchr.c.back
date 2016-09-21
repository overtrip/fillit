/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:11:57 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:54:01 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*sptr;

	sptr = (const unsigned char *)s;
	while (n--)
	{
		if (*sptr == (unsigned char)c)
			return ((void *)sptr);
		sptr++;
	}
	return (NULL);
}
