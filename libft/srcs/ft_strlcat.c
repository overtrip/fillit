/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:53:53 by jealonso          #+#    #+#             */
/*   Updated: 2016/05/20 16:43:50 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	char	*dst_end;

	src_len = ft_strlen(src);
	dst_end = ft_memchr(dst, '\0', size);
	if (!dst_end)
		return (size + src_len);
	dst_len = dst_end - dst;
	if (!ft_memccpy(dst_end, src, 0, size - dst_len - 1))
		dst[size - 1] = '\0';
	return (dst_len + src_len);
}
