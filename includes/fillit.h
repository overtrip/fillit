/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:28:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/24 17:57:34 by jealonso         ###   ########.fr       */
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

typedef struct		s_var
{
	int				cmp_line;
	int				var;
	int				point;
	int				alert;
	char			*buff;
}					t_var;

int					print_error_msg(void);
int					valide_line(char *str, int *nb_line, int *point, int *alrt);
void				get_line(t_map **map, char *str, int cmp_line);
void				delete_all(t_map **map);
int					error_connection(t_map *map);
int					connection(t_map *map, char c);
int					count_piece(t_map *map);
int					presence_piece(t_map *map);

#endif
