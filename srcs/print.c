/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:07:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/10/14 15:41:45 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Global print error message
*/

int		print_error_msg(void)
{
	ft_putendl_fd("error", 1);
	return (1);
}

/*
**	Print final grid resolution
*/

void	print_grid(char **grid)
{
	size_t	i;

	i = 0;
	while (i < g_size)
		ft_putendl(grid[i++]);
}

/*
**	Print piece for debug purpose
*/

void	print_piece(char **grid)
{
	size_t	i;

	i = 0;
	while (i < 4)
		ft_putendl(grid[i++]);
}
