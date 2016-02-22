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
void		ft_first_octant(int x1, int y1, int x2, t_all all)
{
	while (++x1 != x2)
	{
		mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
		if ((all.line.e = all.line.e - all.line.dy) < 0)
		{
			y1 = y1 + 1;
			all.line.e = all.line.e + all.line.dx;
		}
	}
}
void		ft_second_octant(int x1, int y1, int y2, t_all all)
{
	while (++y1 != y2)
	{
		mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
		if ((all.line.e = all.line.e - all.line.dx) < 0)
		{
			x1 = x1 + 1;
			all.line.e = all.line.e + all.line.dy;
		}
	}	
}

void		ft_seventh_octant(int x1, int y1, int y2, t_all all)
{
	while (--y1 != y2)
	{
		mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
		if ((all.line.e = all.line.e + all.line.dx) < 0)
		{
			x1 = x1 + 1;
			all.line.e = all.line.e + all.line.dy;
		}
	}	
}