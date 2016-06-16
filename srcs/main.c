/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:24:00 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/16 17:48:53 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_null(t_list **map, char **buff, int *cmp_line, int *point)
{
	ft_bzero(map, sizeof(t_list *));
	ft_bzero(buff, sizeof(char *));
	cmp_line = 0;
	point = 0;
}

int			main(int argc, char **argv)
{
	char	*buff;
	int		cmp_line;
	int		var;
	int		point;
	t_list	*map;

	init_null(&map, &buff, &cmp_line, &point);
	if ((argc != 2) || !(ft_strstr(argv[1], ".fillit")))
	{
		ft_putendl_fd("usage : fillit source_file.fillit", 2);
		exit (2);
	}
	else
	{
		if ((var = open(argv[1], O_RDONLY)) < 0)
			return (1);
		while (get_next_line(var, &buff) > 0)
		{
			if (!valide_line(buff, &cmp_line, &point))
				get_line(&map, buff);
			else
				break ;
			free(buff);
		}
		free(buff);
		ft_putlist(map);
		delete_all(&map);
		if (close(var) < 0)
			return (1);
	}
	return (0);
}
