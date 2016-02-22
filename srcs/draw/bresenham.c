/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:46:16 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/22 18:47:11 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_first_quadrant(int x1, int y1, int x2, int y2, t_all all)
{
	if (all.line.dx >= all.line.dy)
	{
		ft_init_e_x(all.line);
		ft_first_octant(x1, y1, x2, all);
	}
	else
	{
		ft_init_e_y(all.line);
		ft_second_octant(x1, y1, y2, all);
	}
}
void		ft_fourth_quadrant(int x1, int y1, int x2, int y2, t_all all)
{
	if (all.line.dx >= -all.line.dy)
	{
		ft_init_e_x(all.line);
		while ((x1 = x1 + 1) != x2)
		{
			mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			if ((all.line.e = all.line.e + all.line.dy) < 0)
			{
				y1 = y1 - 1;
				all.line.e = all.line.e + all.line.dx;
			}
		}
	}
	else
	{
		ft_init_e_y(all.line);
		ft_seventh_octant(x1, y1, y2, all);
	}
}

void		ft_second_quadrant(int x1, int y1, int x2, int y2, t_all all)
{
	if (-all.line.dx >= all.line.dy)
	{
		ft_init_e_x(all.line);
		while ((x1 = x1 - 1) != x2)
		{
			mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			if ((all.line.e = all.line.e + all.line.dy) != 0)
			{
				y1 = y1 + 1;
				all.line.e = all.line.e + all.line.dx;
			}
		}
	}
	else
	{
		ft_init_e_y(all.line);
		ft_thirth_octant(x1, y1, y2, all);
	}
}

void		ft_thirth_quadrant(int x1, int y1, int x2, int y2, t_all all)
{
	if (all.line.dx <= all.line.dy)
	{
		ft_init_e_x(all.line);
		while ((x1  = x1 - 1) != x2)
		{
			mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			if ((all.line.e = all.line.e - all.line.dy) >= 0)
			{
				y1 = y1 - 1;
				all.line.e = all.line.e + all.line.dx;
			}
		}
	}
	else
	{
		ft_init_e_y(all.line);
		ft_sixth_octant(x1, y1, y2, all);
	}
}