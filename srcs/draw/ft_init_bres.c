/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:13:03 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/22 19:13:08 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_e_x(t_line line)
{
	line.e = line.dx;
	line.dx = line.e * 2;
	line.dy = line.dy * 2;
}

void		ft_init_e_y(t_line line)
{
	line.e = line.dy;
	line.dy = line.e * 2;
	line.dx = line.dx * 2;
}

void		ft_init_line_x(int i, int j, int b, t_all *all)
{
	all->line.x1 /* * (all->line.end_x % size_map) */= all->coord[i][j]->x;
	all->line.y1 /* * (all->line.end_x % size_map) */= all->coord[i][j]->z;
	all->line.x2 /* * (all->line.end_x % size_map) */= all->coord[i][b]->x;
	all->line.y2 /* * (all->line.end_x % size_map) */= all->coord[i][b]->z;
}
void		ft_init_line_y(int i, int j, int a, t_all *all)
{
	all->line.x1 = all->coord[i][j]->x;
	all->line.y1 = all->coord[i][j]->z;
	all->line.x2 = all->coord[a][j]->x;
	all->line.y2 = all->coord[a][j]->z;
}