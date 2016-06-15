/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 16:28:22 by jealonso          #+#    #+#             */
/*   Updated: 2016/06/15 18:07:11 by jealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
#define FILLIT_H
#include "libft.h"
#include <stdio.h>

void	init_null(t_list **map, char **buff, int *cmp_line);
int		print_error_msg(void);
int		error(char *str);
int		valide_line(char *str, int *cmp_line);
int		call_line(int *cmp_line, char *str);
void	get_line(t_list **map, char *str);

#endif
