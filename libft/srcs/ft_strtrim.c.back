/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:49:26 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:40:07 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_iswhitespace(char c)
{
	if (c == 32 || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t			length;
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	length = ft_strlen(s);
	while (s[i] && ft_iswhitespace(s[i]))
		i++;
	while (length > i && ft_iswhitespace(s[length - 1]))
		length--;
	new = ft_strsub(s, i, length - i);
	return (new);
}
