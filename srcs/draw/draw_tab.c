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

void		ft_line(t_all *all)
{

	all->line.dx = all->line.x2 - all->line.x1;
	all->line.dy = all->line.y2 - all->line.y1;
	if (all->line.dx != 0)
	{
		if (all->line.dx > 0)
		{
			ft_first_arc(all);
		}
		else
		{
			ft_second_arc(all);
		}
	}
	else // all->line.dx = 0
	{
		ft_others_cond(all);
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
				ft_init_line_y(i, j, a, &all);
				ft_line(&all);
				//printf("valeur de x: %d\nvaleur de y: %d\nvaleur de z: %d\n\n ", all.coord[i][j]->x, all.coord[i][j]->y, all.coord[i][j]->z);
				//printf("valeur de x1: %d\nvaleur de y1: %d\nvaleur de z1: %d\n\n ", all.coord[i][a]->x, all.coord[i][a]->y, all.coord[i][a]->z);
			}
			if (all.coord[i][b])
				ft_init_line_x(i, j, b, &all);
				ft_line(&all);
			mlx_pixel_put(all.mlx, all.win, all.coord[i][j]->x, all.coord[i][j]->z, all.coord[i][j]->color);
		}
	}
	return (1);
}