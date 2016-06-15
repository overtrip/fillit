/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:36:01 by jealonso          #+#    #+#             */
/*   Updated: 2015/12/14 17:28:30 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_str(char *a, char *b)
{
	char	*tmp;

	tmp = ft_strdup(a);
	a = ft_strcpy(a, tmp);
	b = ft_strcpy(b, a);
	free(tmp);
}
