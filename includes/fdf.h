/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 15:39:41 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/04 15:10:03 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 1024

typedef struct	s_fdf
{
	int		mov_x;
	int		mov_y;

}				t_fdf;
/*
void  t(t_fdf t)
{
 	t->mov_x = 3;
}

int main()
{
	t_fdf t;

	t.mov_x = 7;
	t.mov_y = 7;

	ft_t(&t);
	printf("%d", t.mov_x)
}
3*/
int			get_next_line(int const fd, char **line);
char		***read_map(int const fd, char *line);

#endif
