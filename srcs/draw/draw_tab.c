/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramanan <aramanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:23:08 by ifranc-r          #+#    #+#             */
/*   Updated: 2016/03/04 19:27:26 by aramanan         ###   ########.fr       */
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
			ft_first_arc(all);
		else
			ft_second_arc(all);
	}
	else // all->line.dx = 0
		ft_others_cond(all);
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
				ft_init_line_y(i, j, &all);
				ft_line(&all);
			}
			if (all.coord[i])
			{
				if (all.coord[i][b])
				{
					ft_init_line_x(i, j, &all);
					ft_line(&all);
				}
			}
			mlx_pixel_put_image(all.img, all.coord[i][j]->x, all.coord[i][j]->z, all.coord[i][j]->color);
		}
	}
	return (1);
}
