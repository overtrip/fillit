/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:23:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/16 17:21:30 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		call_line(int *cmp_line, char *str, int *point)
{
	if ((++(*cmp_line) == 5 && *str != 0))
		return (1);
	else if ((*cmp_line) == 5)
	{
		(*cmp_line) = 0;
		*point = 0;
	}
	return (0);
}

static int		nb_points(int *point, int *cmp_line)
{
	if (*point > 4 || (*point < 4 && *cmp_line == 4))
		return (1);
	return (0);
}

int				valide_line(char *str, int *cmp_line, int *point)
{
	int	i;

	i = -1;
	if (nb_points(point, cmp_line) || call_line(cmp_line, str, point))
		return (print_error_msg());
	while (str[++i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != 0)
			return (print_error_msg());
		if (str[i] == '#')
			++(*point);
	}
	if ((i > 4 || i < 4) && !(i == 0 && str[i] == 0))
		return (print_error_msg());
	else
		return (0);
}
