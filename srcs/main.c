/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:24:00 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/24 18:05:01 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	TODO Delete after test
*/

void		print_list(t_map *map)
{
	int	i;

	while (map)
	{
		i = -1;
		while (map->tab[++i])
			ft_putendl(map->tab[i]);
		map = map->next;
		ft_putchar('\n');
	}
}

/*
**	TODO Delete after test
*/

void		printr_list(t_map *map)
{
	int i;

	if (map)
		printr_list(map->next);
	else
		return ;
	i = -1;
	while (map->tab[++i])
		ft_putendl(map->tab[i]);
	ft_putchar('\n');
}

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
	while (get_next_line(var->var, &var->buff) > 0)
	{
		if (!valide_line(var->buff, &var->cmp_line, &var->point, &var->alert))
			get_line(&(*map), var->buff, var->cmp_line);
		else
			break ;
		ft_strdel(&var->buff);
	}
	ft_strdel(&var->buff);
	if (!*map || var->alert || count_piece(*map) || presence_piece(*map)
	   )//|| error_connection(*map))
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
			print_error_msg();
		delete_all(&map);
//		printr_list(map);
		if (close(var.var) < 0)
			return (print_error_msg());
	}
	return (0);
}
