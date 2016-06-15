/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:24:00 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/15 18:14:26 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*buff;
	int		cmp_line;
	t_list	*map;

	init_null(&map, &buff, &cmp_line);
	ft_putendl(argv[0]);
printf("[%d](argc) [%s](argv)\n", argc, argv[1]);
	if (argc != 1 || !ft_strstr(".fillit", argv[1]))
	{
		ft_putendl_fd("usage : fillit source_file.fillit", 2);
		exit (2);
	}
	else
	{
printf("ici \n");
		while (get_next_line(0, &buff) > 0)
		{
			if (!valide_line(buff, &cmp_line))
				get_line(&map, buff);
			else
				ft_putendl("ici");
			free(buff);
		}
		free(buff);
	}
	return (0);
}
