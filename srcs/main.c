/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:24:00 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/16 16:32:03 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
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
//			printf("[ %s ](buff)\n", buff);
			if (!valide_line(buff, &cmp_line, &point))
				get_line(&map, buff);
			else
				break ;
			free(buff);
		}
		free(buff);
		if (close(var) < 0)
			return (1);
	}
	return (0);
}
