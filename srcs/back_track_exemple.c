/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track_exemple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:10:39 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/29 18:24:41 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	TODO Delete this file
*/

void			backtracking(int **tab)
{
	int		i;

	i = 0;
	if (resolu())
		return ;
	if (!verif(tab))
		return ;
	while (i < 10)
	{
		tab[0][0] = i;
		backtracking(tab + 1);
		tab[0][0] = 0;
		++i;
	}
}

void		backtrack(char ***grid, t_map *map, char ***save)
{
	if (!map)
		return ;
	while (map)
	{
		if (!match(grid, map->tab))
			create_grid(grid);
		backtrack(grid, map->next, save);
		grid = save;
		map = map->next;
	}
}
