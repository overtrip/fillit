/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:28:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/09/21 17:43:39 by jealonso         ###   ########.fr       */
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

size_t	g_size;

# define GRIDI(g, s, p) ((size_t)(g.i + s.i - p.i) < g_size)
# define GRIDJ(g, s, p) ((size_t)(g.j + s.j - p.j) < g_size)
# define INGRID(g, s, p) (GRIDI(g, s, p) && GRIDJ(g, s, p))

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

typedef struct		s_pair
{
	int				i;
	int				j;
}					t_pair;

int					print_error_msg(void);
int					valide_line(char *str, int *nb_line, int *point, int *alrt);
void				get_line(t_map **map, char *str, int cmp_line);
void				delete_all(t_map **map);
int					error_connection(t_map *map);
int					connection(t_map *map, char c);
int					count_piece(t_map *map);
void				preparation(t_map **map);
int					presence_piece(t_map *map);
void				init_grid(char ***tab);
void				create_grid(char ***grid);
void				delete_tab(char ***tab);
void				print_grid(char **grid);
void				print_piece(char **grid);
void				dup_grid(char ***grid, char ***save);
void				delete_old_tab(char ***grid);

#endif
