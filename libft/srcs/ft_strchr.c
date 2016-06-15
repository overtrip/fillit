/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:04:35 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:41:38 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	to_find;
	int		i;

	to_find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == to_find)
			return ((char *)&s[i]);
		i++;
	}
	if (to_find == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
