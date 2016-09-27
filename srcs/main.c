/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:24:00 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/27 17:57:55 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Put all strctures and variable to 0 or NULL
*/

static void	init_null(t_var *var, t_map **map)
{
	*map = NULL;
	ft_bzero(var, sizeof(t_var));
}

/*
**	Get lines and put in structur
*/

static int	aquisition(t_var *var, t_map **map)
{
	t_map	*tmp;

	tmp = NULL;
	while (get_next_line(var->var, &var->buff) > 0)
	{
		if (!valide_line(var->buff, &var->cmp_line, &var->point, &var->alert))
			get_line(&(*map), var->buff, var->cmp_line);
		else
			break ;
		ft_strdel(&var->buff);
	}
	ft_strdel(&var->buff);
	*map = pt_map(*map);
	if (!*map || var->alert || count_piece(*map) || presence_piece(*map)
			|| error_connection(*map))
		return (1);
	return (0);
}

/*
**	You konw what is that
*/

int			main(int argc, char **argv)
{
	t_var	var;
	t_map	*map;

	init_null(&var, &map);
	if ((argc != 2) || !(ft_strstr(argv[1], ".fillit")))
	{
		ft_putendl_fd("usage : fillit source_file.fillit", 2);
		exit(2);
	}
	else
	{
		if ((var.var = open(argv[1], O_RDONLY)) < 0)
			return (print_error_msg());
		if (aquisition(&var, &map))
			return (print_error_msg());
		if (!var.alert)
			preparation(&map);
		delete_all(&map);
		if (close(var.var) < 0)
			return (print_error_msg());
	}
	return (0);
}
