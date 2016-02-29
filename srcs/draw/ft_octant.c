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

void		ft_first_octant(int x1, int y1, int x2, t_all *all)
{
	while (++x1 != x2)
	{
		mlx_image(&all, x1, y1, &all->img);
		if ((all->line.e = all->line.e - all->line.dy) < 0)
		{
			y1 = y1 + 1;
			all->line.e = all->line.e + all->line.dx;
		}
	}
}

void		ft_second_octant(int x1, int y1, int y2, t_all *all)
{
	while (++y1 != y2)
	{
		mlx_image(&all, x1, y1, &all->img);
		if ((all->line.e = all->line.e - all->line.dx) < 0)
		{
			x1 = x1 + 1;
			all->line.e = all->line.e + all->line.dy;
		}
	}	
}

void		ft_seventh_octant(int x1, int y1, int y2, t_all *all)
{
	while (--y1 != y2)
	{
		mlx_image(&all, x1, y1, &all->img);
		if ((all->line.e = all->line.e - all->line.dx) < 0)
		{
			x1 = x1 + 1;
			all->line.e = all->line.e - all->line.dy;
		}
	}	
}

void		ft_thirth_octant(int x1, int y1, int y2, t_all *all)
{
	while ((y1 = y1 + 1) != y2)
	{
		mlx_image(&all, x1, y1, &all->img);
		if ((all->line.e = all->line.e + all->line.dx) != 0)
		{
			x1 = x1 - 1;
			all->line.e = all->line.e + all->line.dy;
		}
	}
}

void		ft_sixth_octant(int x1, int y1, int y2, t_all *all)
{
	while ((y1  = y1 - 1) != y2)
	{
		mlx_image(&all, x1, y1, &all->img);
		if ((all->line.e = all->line.e - all->line.dx) >= 0)
		{
			x1 = x1 - 1;
			all->line.e = all->line.e + all->line.dy;
		}
	}
}
