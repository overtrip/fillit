/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:07:15 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/26 16:27:16 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Global print error message
*/

int	print_error_msg(void)
{
	ft_putendl_fd("error", 2);
	return (1);
}

/*
**	Print final grid resolution
*/

void	print_grid(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		ft_putendl(grid[i]);
}
