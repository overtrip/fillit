/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:48:07 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:53:01 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*s1ptr;
	const char	*s2ptr;

	s1ptr = (char *)s1;
	s2ptr = (const char *)s2;
	while (n--)
	{
		*s1ptr = *s2ptr;
		s1ptr++;
		s2ptr++;
	}
	return (s1);
}
