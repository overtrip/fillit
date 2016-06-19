/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:28:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/19 15:34:20 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

/*
**	TODO Delete this library because use for printf function
*/

# include <stdio.h>
# include <fcntl.h>

typedef struct		s_map
{
	char			**tab;
	struct s_map	*next;
}					t_map;

int					print_error_msg(void);
int					error(char *str);
int					valide_line(char *str, int *cmp_line, int *points);
void				get_line(t_map **map, char *str, int cmp_line);
void				delete_all(t_map **map);

#endif
