/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:46:16 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/03/04 15:56:55 by aramanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_first_quadrant(t_all *all)
{
	if (all->line.dx >= all->line.dy)
	{
		ft_init_e_x(all->line);
		ft_first_octant(all->line.x1, all->line.y1, all->line.x2, all);
	}
	else
	{
		ft_init_e_y(all->line);
		ft_second_octant(all->line.x1, all->line.y1, all->line.y2, all);
	}
}
void		ft_fourth_quadrant(t_all *all)
{
	if (all->line.dx >= -all->line.dy)
	{
		ft_init_e_x(all->line);
		while ((all->line.x1 = all->line.x1 + 1) != all->line.x2)
		{
			mlx_pixel_put(all->mlx, all->win, all->line.x1, all->line.y1, 0xFFFFFFF);
			if ((all->line.e = all->line.e + all->line.dy) < 0)
			{
				all->line.y1 = all->line.y1 - 1;
				all->line.e = all->line.e + all->line.dx;
			}
		}
	}
	else
	{
		ft_init_e_y(all->line);
		ft_seventh_octant(all->line.x1, all->line.y1, all->line.y2, all);
	}
}

void		ft_second_quadrant(t_all *all)
{
	if (-all->line.dx >= all->line.dy)
	{
		ft_init_e_x(all->line);
		while ((all->line.x1 = all->line.x1 - 1) != all->line.x2)
		{
			mlx_pixel_put(all->mlx, all->win, all->line.x1, all->line.y1, 0xFFFFFFF);
			if ((all->line.e = all->line.e + all->line.dy) != 0)
			{
				all->line.y1 = all->line.y1 + 1;
				all->line.e = all->line.e + all->line.dx;
			}
		}
	}
	else
	{
		ft_init_e_y(all->line);
		ft_thirth_octant(all->line.x1, all->line.y1, all->line.y2, all);
	}
}

void		ft_thirth_quadrant(t_all *all)
{
	if (all->line.dx <= all->line.dy)
	{
		ft_init_e_x(all->line);
		while ((all->line.x1  = all->line.x1 - 1) != all->line.x2)
		{
			mlx_pixel_put(all->mlx, all->win, all->line.x1, all->line.y1, 0xFFFFFFF);
			if ((all->line.e = all->line.e - all->line.dy) >= 0)
			{
				all->line.y1 = all->line.y1 - 1;
				all->line.e = all->line.e + all->line.dx;
			}
		}
	}
	else
	{
		ft_init_e_y(all->line);
		ft_sixth_octant(all->line.x1, all->line.y1, all->line.y2, all);
	}
}
