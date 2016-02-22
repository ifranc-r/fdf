/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifranc-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:23:08 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/02/22 13:58:05 by ifranc-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_line(int x1, int x2, int y1, int y2, t_all all)
{
	int		dy;
	int		dx;
	int		e;

	dy = (y2 - y1) * 2;
	e = x1 - x2;
	dx = e * 2;
	while (x1 <= x2)
	{
		mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFF00FFF);
		x1++;
		if ((e = e - dy) <= 0)
		{
			y1++;
			e = e + dx;
		}
	}
}

void		ft_line2(int x1, int y1, int x2, int y2, t_all all)
{
	all.line.dx = x2 - x1;
	all.line.dy = y2 - y1;
	if (all.line.dx != 0)
	{
		if (all.line.dx > 0)
		{
			if (all.line.dy != 0)
			{
				if (all.line.dy > 0)
				{
					ft_first_quadrant(x1, y1, x2, y2, all);
				}
				else
				{
					ft_fourth_quadrant(x1, y1, x2, y2, all);
				}
			}
			else
			{
				while ((x1 = x1 + 1) != x2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
		}
		else
		{
			if ((all.line.dy = y2 - y1) != 0)
			{
				if (all.line.dy > 0)
				{
					ft_second_quadrant(x1, y1, x2, y2, all);
				}
				else
				{
					ft_thirth_quadrant(x1, y1, x2, y2, all);
				}
			}
			else // dy = 0 and all.line.dx < 0
			{
				while ((x1 = x1 - 1) != x2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);					
			}
		}
	}
	else // all.line.dx = 0
	{
		if ((all.line.dy = y2 - y1) != 0)
		{
			if (all.line.dy > 0)
			{
				while ((y1 = y1 + 1) != y2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
			else // all.line.dy < 0 and all.line.dx = 0
			{
				while ((y1 = y1 - 1) != y2)
					mlx_pixel_put(all.mlx, all.win, x1, y1, 0xFFFFFFF);
			}
		}
	}
}

int		ft_pixel_put(t_all all) // ax + bx
{
	int		i;
	int		j;
	int		a;
	int		b;

	i = -1;
	while (all.coord[++i])
	{
		j = -1;
		while (all.coord[i][++j])
		{
			a = i + 1;
			b = j + 1;
			if (all.coord[a])
			{
				ft_line2(all.coord[i][j]->x, all.coord[i][j]->z, all.coord[a][j]->x, all.coord[a][j]->z, all);
				printf("valeur de x: %d\nvaleur de y: %d\nvaleur de z: %d\n\n ", all.coord[i][j]->x, all.coord[i][j]->y, all.coord[i][j]->z);
				printf("valeur de x1: %d\nvaleur de y1: %d\nvaleur de z1: %d\n\n ", all.coord[i][a]->x, all.coord[i][a]->y, all.coord[i][a]->z);
			}
			if (all.coord[i][b])
				ft_line2(all.coord[i][j]->x, all.coord[i][j]->z, all.coord[i][b]->x, all.coord[i][b]->z, all);
			mlx_pixel_put(all.mlx, all.win, all.coord[i][j]->x, all.coord[i][j]->z, 0x00FF00);
		}
	}
	return (1);
}