/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 16:16:39 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/20 19:11:26 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (str)
	{
		ft_strncpy(str, s1, s1_len);
		str[s1_len] = '\0';
	}
	else
		str = NULL;
	return (str);
}
