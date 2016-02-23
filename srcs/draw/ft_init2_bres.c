/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2_bres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:48:46 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/23 10:17:20 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void		ft_init_line_y(int i, int j, int a, t_all *all)
{
	all->line.x1 = all->coord[i][j]->x;
	all->line.y1 = all->coord[i][j]->z;
	all->line.x2 = all->coord[a][j]->x;
	all->line.y2 = all->coord[a][j]->z;
}

void		ft_init_line_x(int i, int j, int b, t_all *all)
{
	all->line.x1 = all->coord[i][j]->x;
	all->line.y1 = all->coord[i][j]->z;
	all->line.x2 = all->coord[i][b]->x;
	all->line.y2 = all->coord[i][b]->z;
}

void		ft_thirth_octant(int x1, int y1, int y2, t_all all)
{
	while ((y1 = y1 + 1) != y2)
	{
		mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
		if ((all.line.e = all.line.e + all.line.dx) != 0)
		{
			x1 = x1 - 1;
			all.line.e = all.line.e + all.line.dy;
		}
	}
}

void		ft_sixth_octant(int x1, int y1, int y2, t_all all)
{
	while ((y1  = y1 - 1) != y2)
	{
		mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
		if ((all.line.e = all.line.e - all.line.dx) >= 0)
		{
			x1 = x1 - 1;
			all.line.e = all.line.e + all.line.dy;
		}
	}
}
