/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:54:27 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:48:40 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s1ptr;
	unsigned char *s2ptr;

	s1ptr = (unsigned char *)s1;
	s2ptr = (unsigned char *)s2;
	while (*s1ptr && (*s1ptr == *s2ptr))
	{
		s1ptr++;
		s2ptr++;
	}
	return (*s1ptr - *s2ptr);
}
