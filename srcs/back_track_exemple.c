/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track_exemple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 16:10:39 by jealonso          #+#    #+#             */
/*   Updated: 2016/07/01 17:31:40 by jealonso         ###   ########.fr       */
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
