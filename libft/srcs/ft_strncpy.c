/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:36:35 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:42:34 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*result;

	result = s1;
	if (!n)
		return (result);
	while ((*s1 = *s2))
	{
		n--;
		if (!n)
			return (result);
		s1++;
		s2++;
	}
	while (n--)
	{
		*s1 = '\0';
		s1++;
	}
	return (result);
}
