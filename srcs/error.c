/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:23:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/16 16:36:05 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_null(t_list **map, char **buff, int *cmp_line, int *point)
{
	ft_bzero(map, sizeof(t_list *));
	ft_bzero(buff, sizeof(char *));
	cmp_line = 0;
	point = 0;
}

int		call_line(int *cmp_line, char *str, int *point)
{
	//	printf("[ %d ](cmp_line)\t[ %s](str)\n", *cmp_line, str);
	if ((++(*cmp_line) == 5 && *str != 0))
		return (1);
	else if ((*cmp_line) == 5)
	{
		(*cmp_line) = 0;
		*point = 0;
	}
	return (0);
}

int		nb_points(int *point, int *cmp_line)
{
	if (*point > 4 || (*point < 4 && *cmp_line > 4))
		return (1);
	return (0);
}

int		valide_line(char *str, int *cmp_line, int *point)
{
	int	i;

	i = -1;
	if (nb_points(point, cmp_line) || call_line(cmp_line, str, point))
	{
			printf("[ %d ](point)\t[ %d ](line)\n", *point, *cmp_line);
		return (print_error_msg());
	}
/*	if (call_line(cmp_line, str))
		return (print_error_msg());*/
	while (str[++i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != 0)
		{
			//printf("ici\n");
			return (print_error_msg());
		}
		if (str[i] == '#')
			++(*point);
	}
	if ((i > 4 && i < 4) && !(i == 1 && str[i] == '\n'))
	{
			//printf("ici\n");
		return (print_error_msg());
	}
	else
		return (0);
}
