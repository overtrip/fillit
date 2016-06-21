/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:24:00 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/21 16:50:41 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	TODO Delete after test
*/

void	print_list(t_map *map)
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

void	printr_list(t_map *map)
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

static void	init_null(t_map **map, char **buff, int *cmp_line, int *point)
{
	*map = NULL;
	*buff = NULL;
	*cmp_line = 0;
	*point = 0;
}

/*
**	You konw what is that
*/

int			main(int argc, char **argv)
{
	char	*buff;
	int		cmp_line;
	int		var;
	int		point;
	t_map	*map;

	init_null(&map, &buff, &cmp_line, &point);
	if ((argc != 2) || !(ft_strstr(argv[1], ".fillit")))
	{
		ft_putendl_fd("usage : fillit source_file.fillit", 2);
		exit(2);
	}
	else
	{
		if ((var = open(argv[1], O_RDONLY)) < 0)
			return (print_error_msg());
		while (get_next_line(var, &buff) > 0)
		{
			if (!valide_line(buff, &cmp_line, &point))
				get_line(&map, buff, cmp_line);
			else
				break ;
			ft_strdel(&buff);
		}
		ft_strdel(&buff);
		if (!map)
			return (print_error_msg());
//		printr_list(map);
		delete_all(&map);
		if (close(var) < 0)
			return (print_error_msg());
	}
	return (0);
}
