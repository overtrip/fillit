/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:54:27 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:53:16 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1ptr;
	const unsigned char	*s2ptr;

	s1ptr = (const unsigned char *)s1;
	s2ptr = (const unsigned char *)s2;
	while (n--)
	{
		if (*s1ptr != *s2ptr)
			return (*s1ptr - *s2ptr);
		s1ptr++;
		s2ptr++;
	}
	return (0);
}
