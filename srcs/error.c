/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:23:38 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/15 18:13:16 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_null(t_list **map, char **buff, int *cmp_line)
{
	ft_bzero(map, sizeof(t_list));
	ft_bzero(buff, sizeof(char *));
	cmp_line = 0;
}

int		call_line(int *cmp_line, char *str)
{
	if ((++(*cmp_line)) == 5 && *str != '\n')
		return (1);
	else if ((*cmp_line) == 5)
		(*cmp_line) = 0;
	return (0);
}

int		valide_line(char *str, int *cmp_line)
{
	int	i;

	i = -1;
	if (call_line(cmp_line, str))
		return (print_error_msg());
	while (str[++i])
		if (str[i] != '#' || str[i] != '.' || str[i] != '\n')
			return (print_error_msg());
	if (i > 4 || !(i == 1 && str[i] == '\n') || i < 4)
		return (print_error_msg());
	else
		return (0);
}
