/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 19:13:03 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/29 19:21:55 by aramanan         ###   ########.fr       */
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

void		ft_init_line_x(int i, int j, t_all *all)
{
	all->line.x1 /* * (all->line.end_x % size_map) */= all->coord[i][j]->x;
	all->line.y1 /* * (all->line.end_x % size_map) */= all->coord[i][j]->z;
	all->line.x2 /* * (all->line.end_x % size_map) */= all->coord[i][j + 1]->x;
	all->line.y2 /* * (all->line.end_x % size_map) */= all->coord[i][j + 1]->z;
}
void		ft_init_line_y(int i, int j, t_all *all)
{
	all->line.x1 = all->coord[i][j]->x;
	all->line.y1 = all->coord[i][j]->z;
	all->line.x2 = all->coord[i + 1][j]->x;
	all->line.y2 = all->coord[i + 1][j]->z;
}
