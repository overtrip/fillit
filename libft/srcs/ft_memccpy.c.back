/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:48:07 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:38:52 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*s1ptr;
	const unsigned char	*s2ptr;

	s1ptr = (unsigned char *)s1;
	s2ptr = (const unsigned char *)s2;
	while (n--)
	{
		*s1ptr = *s2ptr;
		s1ptr++;
		if (*s2ptr == (unsigned char)c)
			return (s1ptr);
		s2ptr++;
	}
	return (NULL);
}
