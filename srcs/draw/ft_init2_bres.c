/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2_bres.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:48:46 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/22 20:48:54 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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